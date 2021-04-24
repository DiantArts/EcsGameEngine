#pragma once

#include <Engine/Ecs/Entity.hpp>


namespace engine::ecs::component { class Container; }

namespace engine::ecs::entity {



class ConstReference {

public:

    // ------------------------------------------------------------------ *structors

    explicit ConstReference(
        const ::engine::ecs::Entity& entity
    );

    ~ConstReference();



    // ------------------------------------------------------------------ HasComponent

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto hasComponent() const
        -> bool;

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] auto hasComponents() const
        -> bool;



    // ------------------------------------------------------------------ Signature

    [[ nodiscard ]] auto getSignature() const
        -> const ::engine::ecs::Signature&;



    // ------------------------------------------------------------------ ID

    [[ nodiscard ]] auto getID() const
        -> ::engine::ID;



    // ------------------------------------------------------------------ Conversion

    [[ nodiscard ]] auto get() const
        -> const ::engine::ecs::Entity&;

    [[ nodiscard ]] operator const ::engine::ecs::Entity&() const;




private:

    const ::engine::ecs::Entity& m_entity;

};



} // namespace engine::ecs::entity

#include <Engine/Ecs/Entity/ConstReference.impl.hpp>
