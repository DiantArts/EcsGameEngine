#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Camera.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::ecs::component::Camera::Camera(
    ::engine::core::AWindow& window
)
    : m_informationsUbo{ 2 * sizeof(::glm::mat4), m_informationsUboIndex }
    , m_positionUbo{ 1 * sizeof(::glm::vec4), m_positionUboIndex }
{
    this->adjustDirection();
    m_informationsUbo.setOneSubData(0, ::glm::perspective(
            ::glm::radians(m_zoom),
            window.getSize().width / window.getSize().height,
            Camera::far,
            Camera::near
        ));
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



// ------------------------------------------------------------------ Orientation

void ::engine::graphic::opengl::ecs::component::Camera::oriente(
    const float xOffset,
    const float yOffset
)
{
    m_orientation.x += xOffset * m_sensitivity.x;
    m_orientation.y += yOffset * m_sensitivity.y;

    if (m_orientation.x >= 360) {
        m_orientation.x -= 360;
    }
    if (m_orientation.y > this->maxPitch) {
        m_orientation.y = this->maxPitch;
    } else if (m_orientation.y < this->minPitch) {
        m_orientation.y = this->minPitch;
    }
    this->adjustDirection();
}

void ::engine::graphic::opengl::ecs::component::Camera::oriente(
    const ::glm::vec2& offset
)
{
    m_orientation.x += offset.x * m_sensitivity.x;
    m_orientation.y += offset.y * m_sensitivity.y;

    if (m_orientation.x >= 360) {
        m_orientation.x -= 360;
    }
    if (m_orientation.y > this->maxPitch) {
        m_orientation.y = this->maxPitch;
    } else if (m_orientation.y < this->minPitch) {
        m_orientation.y = this->minPitch;
    }
    this->adjustDirection();
}



void ::engine::graphic::opengl::ecs::component::Camera::setOrientation(
    const float xOffset,
    const float yOffset
)
{
    if (xOffset >= 360 || yOffset > this->maxPitch || yOffset < this->minPitch) {
        throw std::logic_error("invalid orientation");
    }
    m_orientation.x = xOffset;
    m_orientation.y = yOffset;
    this->adjustDirection();
}

void ::engine::graphic::opengl::ecs::component::Camera::setOrientation(
    const ::glm::vec2& offset
)
{
    if (offset.x >= 360 || offset.y > this->maxPitch || offset.y < this->minPitch) {
        throw std::logic_error("invalid orientation");
    }
    m_orientation.x = offset.x;
    m_orientation.y = offset.y;
    this->adjustDirection();
}



// ------------------------------------------------------------------ configureUbo

void ::engine::graphic::opengl::ecs::component::Camera::configureUbo(
    const ::glm::vec3& position,
    const ::glm::vec3& up
) const
{
    auto cameraPos{ position + m_direction * -m_distance + m_position };

    m_informationsUbo.setOneSubData(sizeof(glm::mat4),
        ::glm::lookAt(cameraPos, position, up)
    );
    m_positionUbo.setOneSubData(0, cameraPos);
}



// ------------------------------------------------------------------ Detail

void ::engine::graphic::opengl::ecs::component::Camera::adjustDirection()
{
    m_direction.x = cos(::glm::radians(m_orientation.x)) * cos(::glm::radians(m_orientation.y));
    m_direction.y = sin(::glm::radians(m_orientation.y));
    m_direction.z = sin(::glm::radians(m_orientation.x)) * cos(::glm::radians(m_orientation.y));
}
