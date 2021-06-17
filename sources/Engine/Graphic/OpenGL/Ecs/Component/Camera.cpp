#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Camera.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::ecs::component::Camera::Camera(
    ::engine::core::AWindow& window
)
    : m_informationsUbo{ 2 * sizeof(::glm::mat4), m_informationsUboIndex }
    , m_positionUbo{ 1 * sizeof(::glm::vec4), m_positionUboIndex }
    , m_configurationUbo{ 8, m_configurationUboIndex }
{
    this->adjustDirection();
    m_informationsUbo.setOneSubData(0, ::glm::perspective(
            ::glm::radians(m_zoom),
            window.getSize().width / window.getSize().height,
            Camera::far,
            Camera::near
        ));
    m_configurationUbo.setOneSubData(0, this->gamma);
    m_configurationUbo.setOneSubData(4, this->blinn);
}

::engine::graphic::opengl::ecs::component::Camera::Camera(
    ::engine::core::AWindow& window,
    ::glm::vec3 position
)
    : m_informationsUbo{ 2 * sizeof(::glm::mat4), m_informationsUboIndex }
    , m_positionUbo{ 1 * sizeof(::glm::vec4), m_positionUboIndex }
    , m_configurationUbo{ 8, m_configurationUboIndex }
    , m_position{ ::std::move(position) }
{
    this->adjustDirection();
    m_informationsUbo.setOneSubData(0, ::glm::perspective(
            ::glm::radians(m_zoom),
            window.getSize().width / window.getSize().height,
            Camera::far,
            Camera::near
        ));
    m_configurationUbo.setOneSubData(0, this->gamma);
    m_configurationUbo.setOneSubData(4, this->blinn);
}

::engine::graphic::opengl::ecs::component::Camera::~Camera() = default;



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::ecs::component::Camera::Camera(
    Camera&&
) noexcept = default;

auto ::engine::graphic::opengl::ecs::component::Camera::operator=(
    Camera&&
) noexcept
    -> Camera& = default;



// ------------------------------------------------------------------ Rotation

void ::engine::graphic::opengl::ecs::component::Camera::rotate(
    const ::glm::vec2& offset
)
{
    m_rotation.x += offset.x * m_sensitivity.x;
    m_rotation.y += offset.y * m_sensitivity.y;

    if (m_rotation.x >= 360) {
        m_rotation.x -= 360;
    }
    if (m_rotation.y > this->maxPitch) {
        m_rotation.y = this->maxPitch;
    } else if (m_rotation.y < this->minPitch) {
        m_rotation.y = this->minPitch;
    }
    this->adjustDirection();
}

void ::engine::graphic::opengl::ecs::component::Camera::rotate(
    const float yawOffset,
    const float pitchOffset
)
{
    m_rotation.x += yawOffset * m_sensitivity.x;
    m_rotation.y += pitchOffset * m_sensitivity.y;

    if (m_rotation.x >= 360) {
        m_rotation.x -= 360;
    }
    if (m_rotation.y > this->maxPitch) {
        m_rotation.y = this->maxPitch;
    } else if (m_rotation.y < this->minPitch) {
        m_rotation.y = this->minPitch;
    }
    this->adjustDirection();
}

void ::engine::graphic::opengl::ecs::component::Camera::rotateYaw(
    const float offset
)
{
    m_rotation.x += offset * m_sensitivity.x;

    if (m_rotation.x >= 360) {
        m_rotation.x -= 360;
    }
    this->adjustDirection();
}

void ::engine::graphic::opengl::ecs::component::Camera::rotatePitch(
    const float offset
)
{
    m_rotation.y += offset * m_sensitivity.y;

    if (m_rotation.y > this->maxPitch) {
        m_rotation.y = this->maxPitch;
    } else if (m_rotation.y < this->minPitch) {
        m_rotation.y = this->minPitch;
    }
    this->adjustDirection();
}



void ::engine::graphic::opengl::ecs::component::Camera::setRotation(
    const ::glm::vec2& rotation
)
{
    if (rotation.x >= 360 || rotation.y > this->maxPitch || rotation.y < this->minPitch) {
        throw::std::logic_error("invalid orientation");
    }
    m_rotation = rotation;
    this->adjustDirection();
}

void ::engine::graphic::opengl::ecs::component::Camera::setRotation(
    ::glm::vec2&& rotation
)
{
    if (rotation.x >= 360 || rotation.y > this->maxPitch || rotation.y < this->minPitch) {
        throw::std::logic_error("invalid orientation");
    }
    m_rotation = ::std::move(rotation);
    this->adjustDirection();
}


void ::engine::graphic::opengl::ecs::component::Camera::setRotation(
    const float yaw,
    const float pitch
)
{
    if (yaw >= 360 || pitch > this->maxPitch || pitch < this->minPitch) {
        throw::std::logic_error("invalid orientation");
    }
    m_rotation.x = yaw;
    m_rotation.y = pitch;
    this->adjustDirection();
}

void ::engine::graphic::opengl::ecs::component::Camera::setYaw(
    const float yaw
)
{
    if (yaw >= 360) {
        throw::std::logic_error("invalid yaw");
    }
    m_rotation.x = yaw;
    this->adjustDirection();
}

void ::engine::graphic::opengl::ecs::component::Camera::setPitch(
    const float pitch
)
{
    if (pitch > this->maxPitch || pitch < this->minPitch) {
        throw::std::logic_error("invalid orientation");
    }
    m_rotation.y = pitch;
    this->adjustDirection();
}




[[ nodiscard ]] auto ::engine::graphic::opengl::ecs::component::Camera::getRotation() const
    -> const ::glm::vec2&
{
    return m_rotation;
}

[[ nodiscard ]] auto ::engine::graphic::opengl::ecs::component::Camera::getDirection() const
    -> const ::glm::vec3&
{
    return m_direction;
}



// ------------------------------------------------------------------ configureUbo

void ::engine::graphic::opengl::ecs::component::Camera::configureUbo(
    const ::engine::graphic::opengl::ecs::component::Transformable& transformable
) const
{
    auto cameraPos{
        transformable.getPosition() +
        ::glm::vec3{ transformable.getDirection().x, m_direction.y, transformable.getDirection().z } *
        -m_distance +
        m_position
    };

    m_informationsUbo.setOneSubData(sizeof(::glm::mat4),
        ::glm::lookAt(cameraPos, transformable.getPosition(), ::glm::vec3{ 0.0F, 1.0F, 0.0F })
    );
    m_positionUbo.setOneSubData(0, cameraPos);
}



// ------------------------------------------------------------------ Detail

void ::engine::graphic::opengl::ecs::component::Camera::adjustDirection()
{
    m_direction = ::glm::normalize(::glm::vec3(
        cos(::glm::radians(m_rotation.x)) * cos(::glm::radians(m_rotation.y)),
        sin(::glm::radians(m_rotation.y)),
        sin(::glm::radians(m_rotation.x)) * cos(::glm::radians(m_rotation.y))
    ));
}
