#pragma once

#include <Engine/Core/Ecs/Signature.hpp>
#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Core/Detail/Meta/Function.hpp>
#include <Engine/Core/Ecs/System/ASystem.hpp>



namespace engine::core::ecs::system {



template <
    auto function
> class System
    : public ::engine::core::ecs::system::ASystem
{

public:

    // ------------------------------------------------------------------ *structors

    System();

    ~System();



    // ------------------------------------------------------------------ Run

    virtual void operator()(
        ::engine::core::ecs::entity::Container& entities,
        ::engine::core::ecs::component::Container& components
    ) override final;

    void operator()(
        ::engine::core::ecs::component::Container& components,
        ::engine::core::ecs::entity::Container& entities
    );

    virtual void operator()(
        const ::engine::core::ecs::entity::Container& entities,
        const ::engine::core::ecs::component::Container& components
    ) const override final;

    void operator()(
        const ::engine::core::ecs::component::Container& components,
        const ::engine::core::ecs::entity::Container& entities
    ) const;



    // ------------------------------------------------------------------ Signature

    static constexpr auto getSignature()
        -> const ::engine::core::ecs::Signature&;



private:

};

// template <
    // auto func
// > class System
    // : public ::engine::core::ecs::system::ASystem
// {



} // namespace engine::core::ecs::system

#include <Engine/Core/Ecs/System/System.impl.hpp>
