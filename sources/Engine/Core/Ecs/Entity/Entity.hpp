#pragma once

#include <Engine/Core/ID.hpp>
#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Core/Ecs/Component/Container.hpp>
#include <Engine/Core/Ecs/Signature.hpp>



namespace engine::core::ecs::entity {



class Entity {

public:

    class ConstReference;
    class Reference;



public:

    // ------------------------------------------------------------------ *structors

    explicit Entity();

    ~Entity();



    // ------------------------------------------------------------------ Genetate

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] static constexpr auto generate(
        ::engine::core::ecs::component::Container& components
    )
        -> ::engine::core::ecs::entity::Entity;



    // ------------------------------------------------------------------ AddComponent

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > auto addComponent(
        ::engine::core::ecs::component::Container& container
    )
        -> ComponentType&;

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > void addComponents(
        ::engine::core::ecs::component::Container& container
    );




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
    > void removeComponent(
        ::engine::core::ecs::component::Container& container
    );

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > void removeComponents(
        ::engine::core::ecs::component::Container& container
    );



    // ------------------------------------------------------------------ Signature

    [[ nodiscard ]] auto getSignature() const
        -> const ::engine::core::ecs::Signature&;



    // ------------------------------------------------------------------ ID

    [[ nodiscard ]] auto getID() const
        -> ::engine::core::ID;




private:

    static inline ::engine::core::ID m_IDGiver;
    ::engine::core::ID m_id { ++m_IDGiver };

    ::engine::core::ecs::Signature m_signature;

};



template <
    typename Type
> concept ConceptType =
    ::std::is_same<
        ::engine::core::ecs::entity::Entity,
        ::std::remove_cvref_t<Type>
    >::value;



} // namespace engine::core::ecs::Entity

#include <Engine/Core/Ecs/Entity/Entity.impl.hpp>
