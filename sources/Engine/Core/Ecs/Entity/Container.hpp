#pragma once

#include <Engine/Core/Ecs/Entity/Entity.hpp>
#include <Engine/Core/Ecs/Entity/Reference.hpp>
#include <Engine/Core/Ecs/Entity/ConstReference.hpp>
#include <Engine/Core/Ecs/Component/Container.hpp>



namespace engine::core::ecs::entity {



class Container {

public:

    using Type = ::std::vector<::engine::core::ecs::Entity>;




public:

    // ------------------------------------------------------------------ *structors

    explicit Container(
        ::engine::core::ecs::component::Container& componentContainer
    );

    ~Container();



    // ------------------------------------------------------------------ Emplace

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > auto emplace()
        -> ::engine::core::ecs::Entity::Reference;

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > auto emplace(
        ComponentTypes&&... componentsArgs
    )
        -> ::engine::core::ecs::Entity::Reference;



    // ------------------------------------------------------------------ Remove

    void remove(
        ::engine::core::ID entityID
    );

    void remove(
        ::engine::core::ecs::Entity::Reference&& reference
    );



    // ------------------------------------------------------------------ Get

    [[ nodiscard ]] auto operator[](
        ::engine::core::ID entityID
    ) const
        -> ::engine::core::ecs::Entity::ConstReference;

    [[ nodiscard ]] auto operator[](
        ::engine::core::ID entityID
    )
        -> ::engine::core::ecs::Entity::Reference;

    [[ nodiscard ]] auto get(
        ::engine::core::ID entityID
    ) const
        -> ::engine::core::ecs::Entity::ConstReference;

    [[ nodiscard ]] auto unsafeGet(
        ::engine::core::ID entityID
    )
        -> ::engine::core::ecs::Entity::Reference;

    [[ nodiscard ]] auto unsafeGet(
        ::engine::core::ID entityID
    ) const
        -> ::engine::core::ecs::Entity::ConstReference;



    // ------------------------------------------------------------------ Contains

    [[ nodiscard ]] auto contains(
        ::engine::core::ID entityID
    ) const
        -> bool;



    // ------------------------------------------------------------------ Iterator

    [[ nodiscard ]] auto begin()
        -> Container::Type::iterator;

    [[ nodiscard ]] auto begin() const
        -> Container::Type::const_iterator;

    [[ nodiscard ]] auto cbegin() const
        -> Container::Type::const_iterator;

    [[ nodiscard ]] auto end()
        -> Container::Type::iterator;

    [[ nodiscard ]] auto end() const
        -> Container::Type::const_iterator;

    [[ nodiscard ]] auto cend() const
        -> Container::Type::const_iterator;




private:

    Container::Type m_entities;

    ::engine::core::ecs::component::Container& m_components;

};



} // namespace engine::core::ecs::entity

#include <Engine/Core/Ecs/Entity/Container.impl.hpp>
