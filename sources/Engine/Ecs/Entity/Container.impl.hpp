#pragma once



// ------------------------------------------------------------------ Emplace

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> auto ::engine::ecs::entity::Container::emplace()
    -> ::engine::ecs::entity::Reference
{
    auto entity{ m_entities.emplace_back() };
    if constexpr (sizeof(ComponentTypes) != 0) {
        entity.addComponent<ComponentTypes...>(m_components);
    }
    return ::engine::ecs::entity::Reference{ m_components, entity };
}
