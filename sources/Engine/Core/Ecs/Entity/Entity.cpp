#include <pch.hpp>
#include <Engine/Core/Ecs/Entity/Entity.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::ecs::entity::Entity::Entity() = default;

::engine::core::ecs::entity::Entity::~Entity() = default;



// ------------------------------------------------------------------ Signature

auto ::engine::core::ecs::entity::Entity::getSignature() const
    -> const ::engine::core::ecs::Signature&
{
    return m_signature;
}



// ------------------------------------------------------------------ ID

auto ::engine::core::ecs::entity::Entity::getID() const
    -> ::engine::core::ID
{
    return m_id;
}
