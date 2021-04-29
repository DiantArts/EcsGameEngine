#pragma once

#include <Engine/Ecs/Signature.hpp>



namespace engine::detail::meta {



template <
    typename func
> struct Function;

template <
    typename RetType,
    typename... ArgsType
> struct Function<RetType(ArgsType...)> {

    struct Return {
        using Type = RetType;
    };

    struct Arguments {
        using Type = ::std::tuple<ArgsType...>;
        static inline constexpr auto signature{ ::engine::ecs::Signature::generate<ArgsType...>() };
    };

};



} // namespace engine::detail::meta
