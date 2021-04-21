#pragma once

#include <Engine/Ecs/Entity.hpp>



namespace engine::ecs::entity {

class Container;



class Reference {

public:

    // ------------------------------------------------------------------ *structors

    explicit Reference(
        ::engine::ecs::entity::Container& entityContainer,
        ::engine::ecs::Entity& entityReference
    );

    explicit Reference(
        ::engine::ecs::Entity& entityReference,
        ::engine::ecs::entity::Container& entityContainer
    );

    ~Reference();



    // ------------------------------------------------------------------ AddComponent

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto addComponent() const
        -> ComponentType&;

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void addComponents();




    // ------------------------------------------------------------------ HasComponent

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto hasComponent() const
        -> bool;

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] auto hasComponents() const
        -> bool;



    // ------------------------------------------------------------------ RemoveComponent

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > void removeComponent();

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void removeComponents();



    // ------------------------------------------------------------------ Signature

    [[ nodiscard ]] auto getSignature() const
        -> const ::engine::ecs::Signature&;



    // ------------------------------------------------------------------ ID

    [[ nodiscard ]] auto getID() const
        -> ::engine::ID;




private:

    ::engine::ecs::entity::Container& m_entityContainer;
    ::engine::ecs::Entity& m_entityReference;

};



} // namespace engine::ecs::entity

#include <Engine/Ecs/Entity/Reference.impl.hpp>
