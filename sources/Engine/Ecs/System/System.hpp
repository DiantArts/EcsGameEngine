#pragma once

#include <Engine/Ecs/Signature.hpp>
#include <Engine/Ecs/AComponent.hpp>
#include <Engine/Ecs/Component/Container.hpp>
#include <Engine/Ecs/Entity/Container.hpp>
#include <Engine/Detail/Meta/Function.hpp>



namespace engine::ecs::system {



template <
    auto func
> class System {

public:

    static constexpr auto function{ func };



public:

    // ------------------------------------------------------------------ *structors

    System() = delete;

    ~System() = delete;



    // ------------------------------------------------------------------ Run

    static void run(
        ::engine::ecs::entity::Container& entities,
        ::engine::ecs::component::Container& components
    );



    // ------------------------------------------------------------------ Signature

    static constexpr auto getSignature()
        -> const ::engine::ecs::Signature&;



private:

};



} // namespace engine::ecs::system

#include <Engine/Ecs/System/System.impl.hpp>
