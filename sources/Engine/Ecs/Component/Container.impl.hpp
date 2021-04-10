#pragma once

#include <Engine/Detail/Meta.hpp>



// ------------------------------------------------------------------ Construct

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::component::Container::construct()
{
    // ::engine::meta::ForEach<int>::run<constructFunc>();
    // ::engine::meta::ForEach<ComponentTypes...>::run<constructFunc>();
    // ::engine::meta::ForEach<ComponentTypes...>::run<::engine::ecs::component::detail::construct>();
    // ::engine::meta::ForEach<ComponentTypes...>::run<::engine::ecs::component::detail::construct>(
        // []<
            // ::engine::ecs::component::ConceptType ComponentType
        // >(
            // ::engine::ecs::component::Container::Type& container
        // ){
            // container.emplace(ComponentType::getID(), static_cast<void*>(new ::std::unordered_map<
                // ::engine::ecs::component::Container::EntityID,
                // ::engine::ecs::AComponent<ComponentType>
            // >));
        // }
    // );
}



// ------------------------------------------------------------------ Get

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::getComponentMap()
    -> ::std::map<Container::EntityID, ComponentType>&
{
    return m_container[ComponentType::getID()];
}



template <
    ::engine::ecs::component::ConceptType ComponentType
> constexpr auto ::engine::ecs::component::Container::getComponentID() const
    -> Container::ComponentID
{
    return ComponentType::getID();
}

constexpr auto ::engine::ecs::component::Container::getMaxComponentID()
    -> Container::ComponentID
{
    return ::engine::ecs::component::maxID;
}



template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::getComponent(Container::EntityID id)
    -> ComponentType&
{
    return m_container[ComponentType::getID()][id];
}
