#include <pch.hpp>
#include <Engine/Ecs/Entity/Reference.hpp>



// ------------------------------------------------------------------ *structors

::engine::ecs::entity::Entity::Entity() = default;

::engine::ecs::entity::Entity::~Entity() = default;



// ------------------------------------------------------------------ Signature

auto ::engine::ecs::entity::Entity::getSignature() const
    -> const ::engine::ecs::Signature&
{
    return m_signature;
}



// ------------------------------------------------------------------ ID

auto ::engine::ecs::entity::Entity::getID() const
    -> ::engine::ID
{
    return m_id;
}
