#include <pch.hpp>
#include <Engine/Core/Ecs/Component/Movable.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::ecs::component::Movable::Movable() = default;

::engine::core::ecs::component::Movable::~Movable() = default;



// ------------------------------------------------------------------ Position

::engine::core::ecs::component::Movable::operator ::glm::vec3&()
{
    return m_position;
}

::engine::core::ecs::component::Movable::operator const ::glm::vec3&() const
{
    return m_position;
}

auto ::engine::core::ecs::component::Movable::getPostion() const
    -> const ::glm::vec3&
{
    return m_position;
}
