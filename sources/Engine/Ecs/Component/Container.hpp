#pragma once

#include <Engine/ID.hpp>
#include <Engine/Ecs/Entity.hpp>
#include <Engine/Ecs/AComponent.hpp>



namespace engine::ecs::component {



class Container {

public:

    using ComponentID = ::engine::ID;
    using EntityID = ::engine::ecs::Entity::IDType;

    // SubContainer
    using SubContainerPointerType = void*;
    template <
        ::engine::ecs::component::ConceptType ComponentType
    > using SubContainerType = ::std::vector<ComponentType>;

    // SubIDContainer
    using SubIDContainerType = ::std::vector<EntityID>;

    // SubPairContainer
    using SubPairContainerType =
        ::std::pair<Container::SubIDContainerType, Container::SubContainerPointerType>;

    // map[ComponentID].first  == vector<ComponentType>
    // map[ComponentID].second == vector<ID>
    using Type = ::std::unordered_map<
        Container::ComponentID, Container::SubPairContainerType, Container::ComponentID::Hasher
    >;



public:

    // ------------------------------------------------------------------ *structors

    Container();

    ~Container();



    // ------------------------------------------------------------------ SubContainer

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void constructSubContainer();

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto getSubContainer() const
        -> const Container::SubContainerType<ComponentType>&;



    // ------------------------------------------------------------------ ID

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > constexpr auto getComponentID() const
        -> Container::ComponentID;

    static constexpr auto getMaxComponentID()
        -> Container::ComponentID;



    // ------------------------------------------------------------------ Component

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto emplaceComponent(
        Container::EntityID entityID,
        auto&&... args
    )
        -> ComponentType&;

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto getComponent(
        Container::EntityID entityID
    ) const
        -> const ComponentType&;

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto getComponentIndex(
        Container::EntityID entityID
    ) const
        -> ::std::size_t;

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto componentExists(
        Container::EntityID entityID
    ) const
        -> bool;



    // ------------------------------------------------------------------ Others

    auto getSize() const
        -> ::std::size_t;



private:

    // ------------------------------------------------------------------ Private

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto getPairSubContainer()
        -> SubPairContainerType&;

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto getPairSubContainer() const
        -> const SubPairContainerType&;



private:

    Container::SubIDContainerType m_IDContainer;
    Container::Type m_container;


};



} // namespace engine::ecs::component

#include <Engine/Ecs/Component/Container.impl.hpp>
