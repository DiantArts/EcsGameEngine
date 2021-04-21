#pragma once

#include <Engine/Ecs/Entity/Entity.hpp>
#include <Engine/Ecs/Entity/Reference.hpp>
#include <Engine/Ecs/Component/Container.hpp>



namespace engine::ecs::entity {



class Container {

public:

    using Type = ::std::vector<::engine::ecs::Entity>;

    class iterator;
    class const_iterator;



public:

    // ------------------------------------------------------------------ *structors

    Container(::engine::ecs::component::Container& componentContainer);

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

    auto operator[](
        ::engine::ID entityID
    ) const
        -> const ::engine::ecs::Entity&;

    auto operator[](
        ::engine::ID entityID
    )
        -> ::engine::ecs::entity::Reference;

    auto get(
        ::engine::ID entityID
    ) const
        -> const ::engine::ecs::Entity&;



    // ------------------------------------------------------------------ Iterator

    auto begin()
        -> Container::iterator;

    auto begin() const
        -> Container::const_iterator;

    auto cbegin() const
        -> Container::const_iterator;



    auto end()
        -> Container::iterator;

    auto end() const
        -> Container::const_iterator;

    auto cend() const
        -> Container::const_iterator;




private:

    Container::Type m_entityContainer;

    ::engine::ecs::component::Container& componentContainer;

};



} // namespace engine::ecs::entity
