#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Camera.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::ecs::component::Camera::Camera(
    ::engine::core::AWindow& window
)
    : m_informationsUbo{ 2 * sizeof(::glm::mat4), m_informationsUboIndex }
    , m_positionUbo{ 1 * sizeof(::glm::vec4), m_positionUboIndex }
{
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



// ------------------------------------------------------------------ configureUbo

void ::engine::graphic::opengl::ecs::component::Camera::configureUbo(
    const ::glm::vec3& position,
    const ::glm::vec3& front,
    const ::glm::vec3& up
) const
{
    m_informationsUbo.setOneSubData(sizeof(glm::mat4), ::glm::lookAt(position, position + front, up));
    m_positionUbo.setOneSubData(0, m_position);
}
