#include <pch.hpp>
#include <Engine/Core/Ecs/Entity/ConstReference.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::ecs::entity::ConstReference::ConstReference(
    const ::engine::core::ecs::Entity& entity
)
    : m_entity{ entity }
{}

::engine::core::ecs::entity::ConstReference::~ConstReference() = default;



// ------------------------------------------------------------------ Signature

auto ::engine::core::ecs::entity::ConstReference::getSignature() const
    -> const ::engine::core::ecs::Signature&
{
    return m_entity.getSignature();
}



// ------------------------------------------------------------------ ID

auto ::engine::core::ecs::entity::ConstReference::getID() const
    -> ::engine::core::ID
{
    return m_entity.getID();
}


// ------------------------------------------------------------------ Conversion

[[ nodiscard ]] auto ::engine::core::ecs::entity::ConstReference::get() const
    -> const ::engine::core::ecs::Entity&
{
    return m_entity;
}

[[ nodiscard ]] ::engine::core::ecs::entity::ConstReference::operator
    const ::engine::core::ecs::Entity&() const
{
    return m_entity;
}
