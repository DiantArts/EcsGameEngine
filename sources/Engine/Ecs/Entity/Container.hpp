#pragma once

#include <Engine/Ecs/Entity/Entity.hpp>
#include <Engine/Ecs/Entity/Reference.hpp>
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
        -> const ::engine::ecs::Entity&;

    [[ nodiscard ]] auto operator[](
        ::engine::ID entityID
    )
        -> ::engine::ecs::entity::Reference;

    [[ nodiscard ]] auto get(
        ::engine::ID entityID
    ) const
        -> const ::engine::ecs::Entity&;




private:

    Container::Type m_entities;

    ::engine::ecs::component::Container& m_components;

};



} // namespace engine::ecs::entity
