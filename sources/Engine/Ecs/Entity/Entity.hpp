#pragma once

#include <Engine/ID.hpp>
#include <Engine/Ecs/AComponent.hpp>



namespace engine::ecs::entity {



class Entity {

public:

    using SignatureType = ::std::bitset<::engine::ecs::component::maxID>;

    using IDType = ::engine::ID;




public:

    // ------------------------------------------------------------------ *structors

    Entity();

    ~Entity();



    // ------------------------------------------------------------------ AddComponent

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto addComponent() const
        -> bool;

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > auto addComponents()
        -> bool;




    // ------------------------------------------------------------------ HasComponent

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto hasComponent() const
        -> bool;

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > auto hasComponents() const
        -> bool;



    // ------------------------------------------------------------------ RemoveComponent

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > void removeComponent();

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void removeComponents();



    // ------------------------------------------------------------------ Signature

    auto getSignature() const
        -> Entity::SignatureType;



    // ------------------------------------------------------------------ ID

    auto getID() const
        -> Entity::IDType;




private:

    static inline Entity::IDType m_IDGiver;
    const Entity::IDType m_id { m_IDGiver };

    Entity::SignatureType m_signature;

};



} // namespace engine::ecs::entity

namespace engine::ecs { using Entity = ::engine::ecs::entity::Entity; }
