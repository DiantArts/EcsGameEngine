#pragma once

#include <Engine/Ecs/Signature.hpp>
#include <Engine/Ecs/AComponent.hpp>
#include <Engine/Detail/Meta/Function.hpp>
#include <Engine/Ecs/System/ASystem.hpp>



namespace engine::ecs::system {



template <
    auto function
> class System
    : public ::engine::ecs::system::ASystem
{

public:

    // ------------------------------------------------------------------ *structors

    System();

    ~System();



    // ------------------------------------------------------------------ Run

    virtual void run(
        ::engine::ecs::entity::Container& entities,
        ::engine::ecs::component::Container& components
    ) override final;

    void run(
        ::engine::ecs::component::Container& components,
        ::engine::ecs::entity::Container& entities
    );



    // ------------------------------------------------------------------ Signature

    static constexpr auto getSignature()
        -> const ::engine::ecs::Signature&;



private:

};

// template <
    // auto func
// > class System
    // : public ::engine::ecs::system::ASystem
// {



} // namespace engine::ecs::system

#include <Engine/Ecs/System/System.impl.hpp>
