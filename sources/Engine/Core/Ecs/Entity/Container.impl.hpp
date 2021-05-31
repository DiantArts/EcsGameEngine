#pragma once



// ------------------------------------------------------------------ Emplace

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> auto ::engine::core::ecs::entity::Container::emplace()
    -> ::engine::core::ecs::Entity::Reference
{
    auto& entity{ m_entities.emplace_back() };
    if constexpr (sizeof...(ComponentTypes) != 0) {
        entity.addComponents<ComponentTypes...>(m_components);
    }
    return ::engine::core::ecs::Entity::Reference{ m_components, entity };
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> auto ::engine::core::ecs::entity::Container::emplace(
    ComponentTypes&&... components
)
    -> ::engine::core::ecs::Entity::Reference
{
    auto& entity{ m_entities.emplace_back() };
    if constexpr (sizeof...(ComponentTypes) != 0) {
        entity.addComponents<ComponentTypes...>(
            m_components,
            ::std::forward<ComponentTypes>(components)...
        );
    }
    return ::engine::core::ecs::Entity::Reference{ m_components, entity };
}
