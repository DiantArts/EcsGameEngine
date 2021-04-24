#include <pch.hpp>
#include <Engine/Ecs/Entity/Reference.hpp>



// ------------------------------------------------------------------ *structors

::engine::ecs::entity::Reference::Reference(
    ::engine::ecs::component::Container& components,
    ::engine::ecs::Entity& entity
)
    : m_components{ components }, m_entity{ entity }
{}

::engine::ecs::entity::Reference::Reference(
    ::engine::ecs::Entity& entity,
    ::engine::ecs::component::Container& components
)
    : m_components{ components }, m_entity{ entity }
{}

::engine::ecs::entity::Reference::~Reference() = default;



// ------------------------------------------------------------------ Signature

auto ::engine::ecs::entity::Reference::getSignature() const
    -> const ::engine::ecs::Signature&
{
    return m_entity.getSignature();
}



// ------------------------------------------------------------------ ID

auto ::engine::ecs::entity::Reference::getID() const
    -> ::engine::ID
{
    return m_entity.getID();
}


// ------------------------------------------------------------------ Conversion

[[ nodiscard ]] auto ::engine::ecs::entity::Reference::get() const
    -> const ::engine::ecs::Entity&
{
    return m_entity;
}

[[ nodiscard ]] ::engine::ecs::entity::Reference::operator ::engine::ecs::Entity&()
{
    return m_entity;
}

[[ nodiscard ]] ::engine::ecs::entity::Reference::operator const ::engine::ecs::Entity&() const
{
    return m_entity;
}
