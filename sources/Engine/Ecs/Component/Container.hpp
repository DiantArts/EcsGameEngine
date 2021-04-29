#pragma once

#include <Engine/ID.hpp>
#include <Engine/Ecs/AComponent.hpp>
#include <Engine/Detail/Meta/UniqueTypes.hpp>



namespace engine::ecs::component {



class Container {

public:

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > using SubContainerType = ::std::vector<ComponentType>;

    // map[ComponentID].first == vector<EntityID>
    // map[ComponentID].second  == vector<ComponentType>
    using SubPairContainerType = ::std::pair<::std::vector<::engine::ID>, void*>;

    using Type = ::std::unordered_map<
        ::engine::ID, Container::SubPairContainerType, ::engine::ID::Hasher
    >;



public:

    // ------------------------------------------------------------------ *structors

    explicit Container();

    ~Container();



    // ------------------------------------------------------------------ Genetate

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] static constexpr auto generate()
        -> ::engine::ecs::component::Container;



    // ------------------------------------------------------------------ SubContainer
    // Each sub container for each Component

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > requires
        ::engine::detail::meta::UniqueTypes<ComponentTypes...>::value
    void constructSubContainer();

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto getSubContainer() const
        -> const Container::SubContainerType<ComponentType>&;



    // ------------------------------------------------------------------ ID

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] constexpr auto getID() const
        -> ::engine::ID;

    [[ nodiscard ]] static constexpr auto getMaxID()
        -> ::engine::ID;



    // ------------------------------------------------------------------ Emplace/Remove

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto emplace(
        ::engine::ID entityID,
        auto&&... args
    )
        -> ComponentType&;

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void emplaceMany(
        ::engine::ID entityID
    );

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > void remove(
        ::engine::ID entityID
    );

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void removeMany(
        ::engine::ID entityID
    );



    // ------------------------------------------------------------------ Get

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto get(
        ::engine::ID entityID
    ) const
        -> const ComponentType&;

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto getIndex(
        ::engine::ID entityID
    ) const
        -> ::std::size_t;

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto exists(
        ::engine::ID entityID
    ) const
        -> bool;



private:

    // ------------------------------------------------------------------ Private

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto getPairSubContainer()
        -> SubPairContainerType&;

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto getPairSubContainer() const
        -> const SubPairContainerType&;



private:

    Container::Type m_container;


};



} // namespace engine::ecs::component

#include <Engine/Ecs/Component/Container.impl.hpp>
