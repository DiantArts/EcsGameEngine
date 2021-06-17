#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Light/Directional.hpp>
#include <nbLights.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::ecs::component::light::Directional::Directional()
    : m_parameters{
        .direction = ::glm::vec3{ 0.0F }
    }
{}

::engine::graphic::opengl::ecs::component::light::Directional::Directional(
    ::glm::vec3 direction
)
    : m_parameters{
        .direction = ::std::move(direction)
    }
{}

::engine::graphic::opengl::ecs::component::light::Directional::Directional(
    Directional::Parameters parameters
)
    : m_parameters{ ::std::move(parameters) }
{}

::engine::graphic::opengl::ecs::component::light::Directional::~Directional() = default;



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::ecs::component::light::Directional::Directional(
    Directional&&
) noexcept = default;

auto ::engine::graphic::opengl::ecs::component::light::Directional::operator=(
    Directional&&
) noexcept
    -> Directional& = default;



// ------------------------------------------------------------------ Ubo

void ::engine::graphic::opengl::ecs::component::light::Directional::setIntoUbo(
    ::std::size_t& offset
) const
{}
