#include <pch.hpp>
#include <Engine/Ecs/Entity/ConstReference.hpp>



// ------------------------------------------------------------------ *structors

::engine::ecs::entity::ConstReference::ConstReference(
    const ::engine::ecs::Entity& entity
)
    : m_entity{ entity }
{}

::engine::ecs::entity::ConstReference::~ConstReference() = default;



// ------------------------------------------------------------------ Signature

auto ::engine::ecs::entity::ConstReference::getSignature() const
    -> const ::engine::ecs::Signature&
{
    return m_entity.getSignature();
}



// ------------------------------------------------------------------ ID

auto ::engine::ecs::entity::ConstReference::getID() const
    -> ::engine::ID
{
    return m_entity.getID();
}


// ------------------------------------------------------------------ Conversion

[[ nodiscard ]] auto ::engine::ecs::entity::ConstReference::get() const
    -> const ::engine::ecs::Entity&
{
    return m_entity;
}

[[ nodiscard ]] ::engine::ecs::entity::ConstReference::operator const ::engine::ecs::Entity&() const
{
    return m_entity;
}
