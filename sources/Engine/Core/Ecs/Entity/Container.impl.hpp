#pragma once



// ------------------------------------------------------------------ Emplace

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> auto ::engine::core::ecs::entity::Container::emplace()
    -> ::engine::core::ecs::entity::Reference
{
    auto& entity{ m_entities.emplace_back() };
    if constexpr (sizeof...(ComponentTypes) != 0) {
        entity.addComponents<ComponentTypes...>(m_components);
    }
    return ::engine::core::ecs::entity::Reference{ m_components, entity };
}
