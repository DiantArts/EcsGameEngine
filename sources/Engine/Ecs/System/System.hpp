#pragma once

#include <Engine/Ecs/AComponent.hpp>
#include <Engine/Ecs/Component/Container.hpp>
#include <Engine/Ecs/Signature.hpp>
#include <Engine/Detail/Meta/Function.hpp>



namespace engine::ecs::system {



template <
    auto function
> class System {

public:

    // ------------------------------------------------------------------ *structors

    System();

    ~System();



    // ------------------------------------------------------------------ Run

    auto operator()(
        ::engine::ecs::component::ConceptType auto&... args
    );

    auto run(
        ::engine::ecs::component::ConceptType auto&... args
    );



    // ------------------------------------------------------------------ Signature

    static constexpr auto getSignature()
        -> const ::engine::ecs::Signature&;



private:

    static inline constexpr auto m_signature{
        ::engine::detail::meta::Function<decltype(function)>::Arguments::signature
    };

};



} // namespace engine::ecs::system

#include <Engine/Ecs/System/System.impl.hpp>
