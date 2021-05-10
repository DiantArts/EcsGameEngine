#pragma once

#include <Engine/Core/ID.hpp>
#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Core/Detail/Meta/UniqueTypes.hpp>



namespace engine::core::ecs::component {



class Container {

public:

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > using SubContainerType = ::std::vector<std::remove_cvref_t<ComponentType>>;

    // map[ComponentID].first == vector<EntityID>
    // map[ComponentID].second  == vector<ComponentType>
    using SubPairContainerType = ::std::pair<::std::vector<::engine::core::ID>, void*>;

    using Type = ::std::unordered_map<
        ::engine::core::ID, Container::SubPairContainerType, ::engine::core::ID::Hasher
    >;



public:

    // ------------------------------------------------------------------ *structors

    explicit Container();

    ~Container();



    // ------------------------------------------------------------------ ID

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] constexpr auto getID() const
        -> ::engine::core::ID;

    [[ nodiscard ]] static constexpr auto getMaxID()
        -> ::engine::core::ID;



    // ------------------------------------------------------------------ Emplace/Remove

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > auto emplace(
        ::engine::core::ID entityID,
        auto&&... args
    )
        -> ComponentType&;

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > void emplaceMany(
        ::engine::core::ID entityID
    );

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > void remove(
        ::engine::core::ID entityID
    );

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > void removeMany(
        ::engine::core::ID entityID
    );



    // ------------------------------------------------------------------ Get

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto get(
        ::engine::core::ID entityID
    ) const
        -> const ComponentType&;

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto get(
        ::engine::core::ID entityID
    )
        -> ComponentType&;

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto getIndex(
        ::engine::core::ID entityID
    ) const
        -> ::std::size_t;

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto exists(
        ::engine::core::ID entityID
    ) const
        -> bool;



private:

    // ------------------------------------------------------------------ Private

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto getPairSubContainer()
        -> SubPairContainerType&;

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto getPairSubContainer() const
        -> const SubPairContainerType&;



private:

    Container::Type m_container;


};



} // namespace engine::core::ecs::component::

#include <Engine/Core/Ecs/Component/Container.impl.hpp>
