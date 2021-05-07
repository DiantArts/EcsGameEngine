#pragma once



// ------------------------------------------------------------------ AddComponent

template <
    ::engine::core::ecs::component::ConceptType ComponentType
> auto ::engine::core::ecs::entity::Reference::addComponent() const
    -> ComponentType&
{
    return m_entity.addComponent<ComponentType>(m_components);
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> void ::engine::core::ecs::entity::Reference::addComponents()
{
    m_entity.addComponents<ComponentTypes...>(m_components);
}




// ------------------------------------------------------------------ HasComponent

template <
    ::engine::core::ecs::component::ConceptType ComponentType
> auto ::engine::core::ecs::entity::Reference::hasComponent() const
    -> bool
{
    return m_entity.hasComponent<ComponentType>();
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> auto ::engine::core::ecs::entity::Reference::hasComponents() const
    -> bool
{
    return m_entity.hasComponents<ComponentTypes...>();
}



// ------------------------------------------------------------------ RemoveComponent

template <
    ::engine::core::ecs::component::ConceptType ComponentType
> void ::engine::core::ecs::entity::Reference::removeComponent()
{
    m_entity.removeComponent<ComponentType>(m_components);
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> void ::engine::core::ecs::entity::Reference::removeComponents()
{
    m_entity.removeComponents<ComponentTypes...>(m_components);
}
