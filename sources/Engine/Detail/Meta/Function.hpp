#pragma once

#include <Engine/Ecs/Signature.hpp>



namespace engine::detail::meta {


template <
    typename func
> struct Function
    : public Function<decltype(&func::operator())>
{};

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

template <
    typename RetType,
    typename... ArgsType
> struct Function<RetType(*)(ArgsType...)>
    : public ::engine::detail::meta::Function<RetType(ArgsType...)>
{};

template <
    typename RetType,
    typename... ArgsType
> struct Function<::std::function<RetType(ArgsType...)>>
    : public ::engine::detail::meta::Function<RetType(ArgsType...)>
{};

template <
    typename ClassType,
    typename RetType,
    typename... ArgsType
>struct Function<RetType(ClassType::*)(ArgsType...) const> {

    struct Return {
        using Type = RetType;
    };

    struct Arguments {
        using Type = ::std::tuple<ArgsType...>;
        static inline constexpr auto signature{ ::engine::ecs::Signature::generate<ArgsType...>() };
    };
};



} // namespace engine::detail::meta
