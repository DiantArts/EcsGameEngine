#pragma once



// ------------------------------------------------------------------ Genetate

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> [[ nodiscard ]] constexpr auto ::engine::core::ecs::entity::Entity::generate(
    ::engine::core::ecs::component::Container& componentContainer
)
    -> ::engine::core::ecs::entity::Entity
{
    ::engine::core::ecs::entity::Entity entity;

    ::engine::core::detail::meta::ForEach<ComponentTypes...>::template run<
        []<
            ::engine::core::ecs::component::ConceptType ComponentType
        >(
            ::engine::core::ecs::entity::Entity& entity,
            ::engine::core::ecs::component::Container& componentContainer
        ){
            entity.addComponent<ComponentType>(componentContainer);
        }
    >(entity, componentContainer);

    return entity;
}



// ------------------------------------------------------------------ AddComponent

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> auto ::engine::core::ecs::entity::Entity::addComponent(
    ::engine::core::ecs::component::Container& componentContainer
)
    -> RawComponentType&
{
    using ComponentType = std::remove_reference_t<RawComponentType>;
    m_signature.set<ComponentType>();
    return componentContainer.emplace<ComponentType>(m_id);
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> void ::engine::core::ecs::entity::Entity::addComponents(
    ::engine::core::ecs::component::Container& componentContainer
)
{
    m_signature.set<ComponentTypes...>();
    componentContainer.emplaceMany<ComponentTypes...>(m_id);
}




// ------------------------------------------------------------------ HasComponent

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> [[ nodiscard ]] auto ::engine::core::ecs::entity::Entity::hasComponent() const
    -> bool
{
    using ComponentType = std::remove_reference_t<RawComponentType>;
    return m_signature.contains<ComponentType>();
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> [[ nodiscard ]] auto ::engine::core::ecs::entity::Entity::hasComponents() const
    -> bool
{
    return m_signature.contains<ComponentTypes...>();
}



// ------------------------------------------------------------------ RemoveComponent

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> void ::engine::core::ecs::entity::Entity::removeComponent(
    ::engine::core::ecs::component::Container& componentContainer
)
{
    using ComponentType = std::remove_reference_t<RawComponentType>;
    m_signature.reset<ComponentType>();
    componentContainer.remove<ComponentType>(m_id);
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> void ::engine::core::ecs::entity::Entity::removeComponents(
    ::engine::core::ecs::component::Container& componentContainer
)
{
    m_signature.reset<ComponentTypes...>();
    componentContainer.removeMany<ComponentTypes...>(m_id);
}
