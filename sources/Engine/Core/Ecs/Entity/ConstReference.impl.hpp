#pragma once



// ------------------------------------------------------------------ HasComponent

template <
    ::engine::core::ecs::component::ConceptType ComponentType
> auto ::engine::core::ecs::entity::ConstReference::hasComponent() const
    -> bool
{
    return m_entity.hasComponent<ComponentType>();
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> auto ::engine::core::ecs::entity::ConstReference::hasComponents() const
    -> bool
{
    return m_entity.hasComponents<ComponentTypes...>();
}
