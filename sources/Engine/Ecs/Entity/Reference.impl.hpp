#pragma once



// ------------------------------------------------------------------ AddComponent

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::entity::Reference::addComponent() const
    -> ComponentType&
{
    return m_entity.addComponent<ComponentType>(m_components);
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::entity::Reference::addComponents()
{
    m_entity.addComponents<ComponentTypes...>(m_components);
}




// ------------------------------------------------------------------ HasComponent

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::entity::Reference::hasComponent() const
    -> bool
{
    return m_entity.hasComponent<ComponentType>();
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> auto ::engine::ecs::entity::Reference::hasComponents() const
    -> bool
{
    return m_entity.hasComponents<ComponentTypes...>();
}



// ------------------------------------------------------------------ RemoveComponent

template <
    ::engine::ecs::component::ConceptType ComponentType
> void ::engine::ecs::entity::Reference::removeComponent()
{
    m_entity.removeComponent<ComponentType>(m_components);
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::entity::Reference::removeComponents()
{
    m_entity.removeComponents<ComponentTypes...>(m_components);
}
