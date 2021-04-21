#include <pch.hpp>
#include <Engine/Ecs/Entity/Reference.hpp>



// ------------------------------------------------------------------ *structors

::engine::ecs::entity::Reference::Reference(
    ::engine::ecs::entity::Container& entityContainer,
    ::engine::ecs::Entity& entityReference
)
    : m_entityContainer{ entityContainer }, m_entityReference{ entityReference }
{}

::engine::ecs::entity::Reference::Reference(
    ::engine::ecs::Entity& entityReference,
    ::engine::ecs::entity::Container& entityContainer
)
    : m_entityContainer{ entityContainer }, m_entityReference{ entityReference }
{}

::engine::ecs::entity::Reference::~Reference() = default;



// ------------------------------------------------------------------ Signature

auto ::engine::ecs::entity::Reference::getSignature() const
    -> const ::engine::ecs::Signature&
{
    return m_entityReference.getSignature();
}



// ------------------------------------------------------------------ ID

auto ::engine::ecs::entity::Reference::getID() const
    -> ::engine::ID
{
    return m_entityReference.getID();
}
