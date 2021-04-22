#pragma once

#include <Engine/ID.hpp>
#include <Engine/Ecs/AComponent.hpp>
#include <Engine/Ecs/Component/Container.hpp>
#include <Engine/Ecs/Signature.hpp>



namespace engine::ecs::entity {



class Entity {

public:

    // ------------------------------------------------------------------ *structors

    explicit Entity();

    ~Entity();



    // ------------------------------------------------------------------ Copy

    Entity(
        const Entity& that
    ) = delete;

    auto operator=(
        const Entity& that
    )
        -> Entity& = delete;



    // ------------------------------------------------------------------ Move

    Entity(
        Entity&& that
    ) noexcept;

    auto operator=(
        Entity&& that
    ) noexcept
        -> Entity&;



    // ------------------------------------------------------------------ Genetate

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] static constexpr auto generate(
        ::engine::ecs::component::Container& componentContainer
    )
        -> ::engine::ecs::entity::Entity;



    // ------------------------------------------------------------------ AddComponent

    template <
        ::engine::ecs::component::ConceptType ComponentType
    > auto addComponent(
        ::engine::ecs::component::Container& container
    )
        -> ComponentType&;

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void addComponents(
        ::engine::ecs::component::Container& container
    );




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
    > void removeComponent(
        ::engine::ecs::component::Container& container
    );

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void removeComponents(
        ::engine::ecs::component::Container& container
    );



    // ------------------------------------------------------------------ Signature

    [[ nodiscard ]] auto getSignature() const
        -> const ::engine::ecs::Signature&;



    // ------------------------------------------------------------------ ID

    [[ nodiscard ]] auto getID() const
        -> ::engine::ID;




private:

    static inline ::engine::ID m_IDGiver;
    ::engine::ID m_id { ++m_IDGiver };

    ::engine::ecs::Signature m_signature;

};



} // namespace engine::ecs::entity

#include <Engine/Ecs/Entity/Entity.impl.hpp>
