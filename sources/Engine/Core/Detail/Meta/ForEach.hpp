#pragma once

namespace engine::core::detail::meta {



template <
    typename... Rest
> struct ForEach
{
    template <
        auto function
    > static inline constexpr void run(auto&&... args)
    {
        (function.template operator()<Rest>(::std::forward<decltype(args)>(args)...), ...);
    }

    // returns true when the function return true every times
    template <
        auto function
    > static inline constexpr auto compare(auto&&... args)
        -> bool
    {
        return (function.template operator()<Rest>(::std::forward<decltype(args)>(args)...) && ...);
    }

    // returns true when the function return true once
    template <
        auto function
    > static inline constexpr auto exist(auto&&... args)
        -> bool
    {
        return (function.template operator()<Rest>(::std::forward<decltype(args)>(args)...) || ...);
    }
};



} // namespace engine::core::detail::meta
