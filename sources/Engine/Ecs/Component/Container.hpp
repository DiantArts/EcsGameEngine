#pragma once

#include <Engine/ID.hpp>
#include <Engine/Ecs/Entity.hpp>
#include <Engine/Ecs/AComponent.hpp>



namespace engine::ecs::component {



class Container {

public:

    using ContainerPointerType = void*;

    using ComponentID = ::engine::ID;
    using EntityID = ::engine::ecs::Entity::IDType;

    // map[ComponentID][EntityID] == Component
    using Type = ::std::map<Container::ComponentID, Container::ContainerPointerType>;



public:

    // ------------------------------------------------------------------ *structors

    Container();

    ~Container();



    // ------------------------------------------------------------------ Construct

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void construct();



    // ------------------------------------------------------------------ Get

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto getComponentMap()
        -> ::std::map<Container::EntityID, ComponentType>&;



    template <
        ::engine::ecs::component::ConceptType ComponentType
    > constexpr auto getComponentID() const
        -> Container::ComponentID;

    static constexpr auto getMaxComponentID()
        -> Container::ComponentID;



    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto getComponent(Container::EntityID)
        -> ComponentType&;


    auto getSize() const
        -> ::std::size_t;



private:

    Container::Type m_container;


};



} // namespace engine::ecs::component

#include <Engine/Ecs/Component/Container.impl.hpp>
