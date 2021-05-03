#pragma once



// ------------------------------------------------------------------ Genetate

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> [[ nodiscard ]] constexpr auto ::engine::ecs::entity::Entity::generate(
    ::engine::ecs::component::Container& componentContainer
)
    -> ::engine::ecs::entity::Entity
{
    ::engine::ecs::entity::Entity entity;

    ::engine::detail::meta::ForEach<ComponentTypes...>::template run<
        []<
            ::engine::ecs::component::ConceptType ComponentType
        >(
            ::engine::ecs::entity::Entity& entity,
            ::engine::ecs::component::Container& componentContainer
        ){
            entity.addComponent<ComponentType>(componentContainer);
        }
    >(entity, componentContainer);

    return entity;
}



// ------------------------------------------------------------------ AddComponent

template <
    ::engine::ecs::component::ConceptType RawComponentType
> auto ::engine::ecs::entity::Entity::addComponent(
    ::engine::ecs::component::Container& componentContainer
)
    -> RawComponentType&
{
    using ComponentType = std::remove_reference_t<RawComponentType>;
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
    componentContainer.emplaceMany<ComponentTypes...>(m_id);
}




// ------------------------------------------------------------------ HasComponent

template <
    ::engine::ecs::component::ConceptType RawComponentType
> [[ nodiscard ]] auto ::engine::ecs::entity::Entity::hasComponent() const
    -> bool
{
    using ComponentType = std::remove_reference_t<RawComponentType>;
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
    ::engine::ecs::component::ConceptType RawComponentType
> void ::engine::ecs::entity::Entity::removeComponent(
    ::engine::ecs::component::Container& componentContainer
)
{
    using ComponentType = std::remove_reference_t<RawComponentType>;
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
    componentContainer.removeMany<ComponentTypes...>(m_id);
}
