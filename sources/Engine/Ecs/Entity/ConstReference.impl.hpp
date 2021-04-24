#pragma once



// ------------------------------------------------------------------ HasComponent

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::entity::ConstReference::hasComponent() const
    -> bool
{
    return m_entity.hasComponent<ComponentType>();
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> auto ::engine::ecs::entity::ConstReference::hasComponents() const
    -> bool
{
    return m_entity.hasComponents<ComponentTypes...>();
}
