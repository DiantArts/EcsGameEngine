#pragma once

#include <Engine/Ecs/Entity.hpp>


namespace engine::ecs::component { class Container; }

namespace engine::ecs::entity {



class Reference {

public:

    // ------------------------------------------------------------------ *structors

    explicit Reference(
        ::engine::ecs::component::Container& components,
        ::engine::ecs::Entity& entity
    );

    explicit Reference(
        ::engine::ecs::Entity& entity,
        ::engine::ecs::component::Container& components
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



    // ------------------------------------------------------------------ Conversion

    [[ nodiscard ]] auto get() const
        -> const ::engine::ecs::Entity&;

    [[ nodiscard ]] operator ::engine::ecs::Entity&();

    [[ nodiscard ]] operator const ::engine::ecs::Entity&() const;




private:

    ::engine::ecs::component::Container& m_components;
    ::engine::ecs::Entity& m_entity;

};



} // namespace engine::ecs::entity

#include <Engine/Ecs/Entity/Reference.impl.hpp>
