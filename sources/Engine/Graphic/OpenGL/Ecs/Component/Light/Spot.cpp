#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Light/Spot.hpp>
#include <nbLights.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::ecs::component::light::Spot::Spot()
    : m_parameters{ .direction = ::glm::vec3{ 0.0F } }
{}

::engine::graphic::opengl::ecs::component::light::Spot::Spot(
    ::glm::vec3 direction
)
    : m_parameters{
        .direction = ::std::move(direction)
    }
{}

::engine::graphic::opengl::ecs::component::light::Spot::Spot(
    float cutOff,
    float outerCutOff
)
    : m_parameters{
        .direction = ::glm::vec3{ 0.0F },
        .cutOff = cutOff,
        .outerCutOff = outerCutOff
    }
{}

::engine::graphic::opengl::ecs::component::light::Spot::Spot(
    ::glm::vec3 direction,
    float cutOff,
    float outerCutOff
)
    : m_parameters{
        .direction = ::std::move(direction),
        .cutOff = cutOff,
        .outerCutOff = outerCutOff
    }
{}

::engine::graphic::opengl::ecs::component::light::Spot::Spot(
    const Spot::Parameters& parameters
)
    : m_parameters{ parameters }
{}

::engine::graphic::opengl::ecs::component::light::Spot::Spot(
    Spot::Parameters&& parameters
)
    : m_parameters{ ::std::move(parameters) }
{}

::engine::graphic::opengl::ecs::component::light::Spot::~Spot() = default;



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::ecs::component::light::Spot::Spot(
    Spot&&
) noexcept = default;

auto ::engine::graphic::opengl::ecs::component::light::Spot::operator=(
    Spot&&
) noexcept
    -> Spot& = default;



// ------------------------------------------------------------------ Ubo

void ::engine::graphic::opengl::ecs::component::light::Spot::setIntoUbo(
    ::std::size_t& offset
) const
{}
