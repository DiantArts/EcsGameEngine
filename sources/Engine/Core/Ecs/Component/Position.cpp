#include <pch.hpp>
#include <Engine/Core/Ecs/Component/Position.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::ecs::component::Position::Position() = default;

::engine::core::ecs::component::Position::Position(
    float x,
    float y,
    float z
)
    : m_position{ x, y, z }
{}

::engine::core::ecs::component::Position::Position(
    ::glm::vec3 position
)
    : m_position{ ::std::move(position) }
{}

::engine::core::ecs::component::Position::~Position() = default;



// ------------------------------------------------------------------ Position

::engine::core::ecs::component::Position::operator ::glm::vec3&()
{
    return m_position;
}

::engine::core::ecs::component::Position::operator const ::glm::vec3&() const
{
    return m_position;
}

auto ::engine::core::ecs::component::Position::get() const
    -> const ::glm::vec3&
{
    return m_position;
}



// ------------------------------------------------------------------ Set

void ::engine::core::ecs::component::Position::set(
    ::glm::vec3 position
)
{
    m_position = ::std::move(position);
}

void ::engine::core::ecs::component::Position::setX(
    float x
)
{
    m_position.x = x;
}

void ::engine::core::ecs::component::Position::setY(
    float y
)
{
    m_position.y = y;
}

void ::engine::core::ecs::component::Position::setZ(
    float z
)
{
    m_position.z = z;
}
