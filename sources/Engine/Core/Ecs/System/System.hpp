#pragma once

#include <Engine/Core/Ecs/Signature.hpp>
#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Core/Detail/Meta/Function.hpp>
#include <Engine/Core/Ecs/System/ASystem.hpp>



namespace engine::core::ecs::system {



template <
    auto function,
    typename... BanishedComponentTypes
> class System;



template <
    auto function
> class System<function>
    : public ::engine::core::ecs::system::ASystem
{

public:

    // ------------------------------------------------------------------ *structors

    System();

    ~System();



    // ------------------------------------------------------------------ Run

    void operator()(
        ::engine::core::Time t,
        ::engine::core::ecs::entity::Container& entities,
        ::engine::core::ecs::component::Container& components
    ) override;

    void operator()(
        ::engine::core::Time t,
        ::engine::core::ecs::component::Container& components,
        ::engine::core::ecs::entity::Container& entities
    );

    void operator()(
        ::engine::core::Time t,
        const ::engine::core::ecs::entity::Container& entities,
        const ::engine::core::ecs::component::Container& components
    ) const override;

    void operator()(
        ::engine::core::Time t,
        const ::engine::core::ecs::component::Container& components,
        const ::engine::core::ecs::entity::Container& entities
    ) const;



    // ------------------------------------------------------------------ Signature

    [[ nodiscard ]] static constexpr auto getSignature()
        -> const ::engine::core::ecs::Signature&;

};



template <
    auto function,
    ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
> class System<function, BanishedComponentTypes...>
    : public ::engine::core::ecs::system::ASystem
{

public:

    // ------------------------------------------------------------------ *structors

    System();

    ~System();



    // ------------------------------------------------------------------ Run

    void operator()(
        ::engine::core::Time t,
        ::engine::core::ecs::entity::Container& entities,
        ::engine::core::ecs::component::Container& components
    ) override;

    void operator()(
        ::engine::core::Time t,
        ::engine::core::ecs::component::Container& components,
        ::engine::core::ecs::entity::Container& entities
    );

    void operator()(
        ::engine::core::Time t,
        const ::engine::core::ecs::entity::Container& entities,
        const ::engine::core::ecs::component::Container& components
    ) const override;

    void operator()(
        ::engine::core::Time t,
        const ::engine::core::ecs::component::Container& components,
        const ::engine::core::ecs::entity::Container& entities
    ) const;



    // ------------------------------------------------------------------ Signature

    [[ nodiscard ]] static constexpr auto getSignature()
        -> const ::engine::core::ecs::Signature&;

    [[ nodiscard ]] static constexpr auto getBanishedSignature()
        -> const ::engine::core::ecs::Signature&;



private:

    static constexpr auto m_banishedSignature{
        ::engine::core::ecs::Signature::generate<BanishedComponentTypes...>()
    };

};



} // namespace engine::core::ecs::system

#include <Engine/Core/Ecs/System/System.impl.hpp>
