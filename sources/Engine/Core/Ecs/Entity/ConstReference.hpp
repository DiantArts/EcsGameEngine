#pragma once

#include <Engine/Core/Ecs/Entity.hpp>


namespace engine::core::ecs::component { class Container; }

namespace engine::core::ecs::entity {



class ConstReference {

public:

    // ------------------------------------------------------------------ *structors

    explicit ConstReference(
        const ::engine::core::ecs::Entity& entity
    );

    ~ConstReference();



    // ------------------------------------------------------------------ HasComponent

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > [[ nodiscard ]] auto hasComponent() const
        -> bool;

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] auto hasComponents() const
        -> bool;



    // ------------------------------------------------------------------ Signature

    [[ nodiscard ]] auto getSignature() const
        -> const ::engine::core::ecs::Signature&;



    // ------------------------------------------------------------------ ID

    [[ nodiscard ]] auto getID() const
        -> ::engine::core::ID;



    // ------------------------------------------------------------------ Conversion

    [[ nodiscard ]] auto get() const
        -> const ::engine::core::ecs::Entity&;

    [[ nodiscard ]] operator const ::engine::core::ecs::Entity&() const;




private:

    const ::engine::core::ecs::Entity& m_entity;

};



} // namespace engine::core::ecs::entity

#include <Engine/Core/Ecs/Entity/ConstReference.impl.hpp>
