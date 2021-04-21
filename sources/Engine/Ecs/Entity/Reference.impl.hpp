#pragma once

#include <Engine/Ecs/Entity/Container.hpp>



// ------------------------------------------------------------------ AddComponent

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::entity::Reference::addComponent() const
    -> ComponentType&
{
    return m_entityReference.addComponent<ComponentType>();
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::entity::Reference::addComponents()
{
    m_entityReference.addComponents<ComponentTypes...>();
}




// ------------------------------------------------------------------ HasComponent

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::entity::Reference::hasComponent() const
    -> bool
{
    return m_entityReference.hasComponent<ComponentType>();
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> auto ::engine::ecs::entity::Reference::hasComponents() const
    -> bool
{
    return m_entityReference.hasComponents<ComponentTypes...>();
}



// ------------------------------------------------------------------ RemoveComponent

template <
    ::engine::ecs::component::ConceptType ComponentType
> void ::engine::ecs::entity::Reference::removeComponent()
{
    m_entityReference.removeComponent<ComponentType>();
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::entity::Reference::removeComponents()
{
    m_entityReference.removeComponents<ComponentTypes...>();
}
