#pragma once

#include <Engine/Ecs/Entity/Entity.hpp>
#include <Engine/Ecs/Entity/Reference.hpp>
#include <Engine/Ecs/Entity/ConstReference.hpp>
#include <Engine/Ecs/Component/Container.hpp>



namespace engine::ecs::entity {



class Container {

public:

    using Type = ::std::vector<::engine::ecs::Entity>;




public:

    // ------------------------------------------------------------------ *structors

    explicit Container(
        ::engine::ecs::component::Container& componentContainer
    );

    ~Container();



    // ------------------------------------------------------------------ Emplace

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > auto emplace()
        -> ::engine::ecs::entity::Reference;



    // ------------------------------------------------------------------ Remove

    void remove(
        ::engine::ID entityID
    );

    void remove(
        ::engine::ecs::entity::Reference&& reference
    );



    // ------------------------------------------------------------------ Get

    [[ nodiscard ]] auto operator[](
        ::engine::ID entityID
    ) const
        -> ::engine::ecs::entity::ConstReference;

    [[ nodiscard ]] auto operator[](
        ::engine::ID entityID
    )
        -> ::engine::ecs::entity::Reference;

    [[ nodiscard ]] auto get(
        ::engine::ID entityID
    ) const
        -> ::engine::ecs::entity::ConstReference;

    [[ nodiscard ]] auto unsafeGet(
        ::engine::ID entityID
    )
        -> ::engine::ecs::entity::Reference;

    [[ nodiscard ]] auto unsafeGet(
        ::engine::ID entityID
    ) const
        -> ::engine::ecs::entity::ConstReference;



    // ------------------------------------------------------------------ Contains

    [[ nodiscard ]] auto contains(
        ::engine::ID entityID
    ) const
        -> bool;




private:

    Container::Type m_entities;

    ::engine::ecs::component::Container& m_components;

};



} // namespace engine::ecs::entity

#include <Engine/Ecs/Entity/Container.impl.hpp>
