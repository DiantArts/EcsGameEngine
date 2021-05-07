#include <pch.hpp>
#include <Engine/Core/Ecs/Entity/Reference.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::ecs::entity::Reference::Reference(
    ::engine::core::ecs::component::Container& components,
    ::engine::core::ecs::Entity& entity
)
    : m_components{ components }, m_entity{ entity }
{}

::engine::core::ecs::entity::Reference::Reference(
    ::engine::core::ecs::Entity& entity,
    ::engine::core::ecs::component::Container& components
)
    : m_components{ components }, m_entity{ entity }
{}

::engine::core::ecs::entity::Reference::~Reference() = default;



// ------------------------------------------------------------------ Signature

auto ::engine::core::ecs::entity::Reference::getSignature() const
    -> const ::engine::core::ecs::Signature&
{
    return m_entity.getSignature();
}



// ------------------------------------------------------------------ ID

auto ::engine::core::ecs::entity::Reference::getID() const
    -> ::engine::core::ID
{
    return m_entity.getID();
}


// ------------------------------------------------------------------ Conversion

[[ nodiscard ]] auto ::engine::core::ecs::entity::Reference::get() const
    -> const ::engine::core::ecs::Entity&
{
    return m_entity;
}

[[ nodiscard ]] ::engine::core::ecs::entity::Reference::operator ::engine::core::ecs::Entity&()
{
    return m_entity;
}

[[ nodiscard ]] ::engine::core::ecs::entity::Reference::operator const ::engine::core::ecs::Entity&() const
{
    return m_entity;
}
