#pragma once



// ------------------------------------------------------------------ AddComponent

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::entity::Entity::addComponent(
    ::engine::ecs::component::Container& componentContainer
)
    -> ComponentType&
{
    m_signature.set<ComponentType>();
    return componentContainer.emplace<ComponentType>(m_id);
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::entity::Entity::addComponents(
    ::engine::ecs::component::Container& componentContainer
)
{
    m_signature.set<ComponentTypes...>();
    componentContainer.emplace<ComponentTypes...>(m_id);
}




// ------------------------------------------------------------------ HasComponent

template <
    ::engine::ecs::component::ConceptType ComponentType
> [[ nodiscard ]] auto ::engine::ecs::entity::Entity::hasComponent() const
    -> bool
{
    return m_signature.contains<ComponentType>();
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> [[ nodiscard ]] auto ::engine::ecs::entity::Entity::hasComponents() const
    -> bool
{
    return m_signature.contains<ComponentTypes...>();
}



// ------------------------------------------------------------------ RemoveComponent

template <
    ::engine::ecs::component::ConceptType ComponentType
> void ::engine::ecs::entity::Entity::removeComponent(
    ::engine::ecs::component::Container& componentContainer
)
{
    m_signature.reset<ComponentType>();
    componentContainer.remove<ComponentType>(m_id);
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::entity::Entity::removeComponents(
    ::engine::ecs::component::Container& componentContainer
)
{
    m_signature.reset<ComponentTypes...>();
    componentContainer.remove<ComponentTypes...>(m_id);
}
