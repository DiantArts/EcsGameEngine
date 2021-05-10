#pragma once

#include <Engine/Core/Ecs/Entity.hpp>


namespace engine::core::ecs::component { class Container; }



class engine::core::ecs::Entity::Reference {

public:

    // ------------------------------------------------------------------ *structors

    explicit Reference(
        ::engine::core::ecs::component::Container& components,
        ::engine::core::ecs::Entity& entity
    );

    explicit Reference(
        ::engine::core::ecs::Entity& entity,
        ::engine::core::ecs::component::Container& components
    );

    ~Reference();



    // ------------------------------------------------------------------ AddComponent

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > auto addComponent() const
        -> ComponentType&;

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > void addComponents();




    // ------------------------------------------------------------------ HasComponent

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto hasComponent() const
        -> bool;

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] auto hasComponents() const
        -> bool;



    // ------------------------------------------------------------------ RemoveComponent

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > void removeComponent();

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > void removeComponents();



    // ------------------------------------------------------------------ Signature

    [[ nodiscard ]] auto getSignature() const
        -> const ::engine::core::ecs::Signature&;



    // ------------------------------------------------------------------ ID

    [[ nodiscard ]] auto getID() const
        -> ::engine::core::ID;



    // ------------------------------------------------------------------ Conversion

    [[ nodiscard ]] auto get() const
        -> const ::engine::core::ecs::Entity&;

    [[ nodiscard ]] operator ::engine::core::ecs::Entity&();

    [[ nodiscard ]] operator const ::engine::core::ecs::Entity&() const;




private:

    ::engine::core::ecs::component::Container& m_components;
    ::engine::core::ecs::Entity& m_entity;

};

#include <Engine/Core/Ecs/Entity/Reference.impl.hpp>
