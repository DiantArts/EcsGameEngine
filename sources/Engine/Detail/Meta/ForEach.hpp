#pragma once

namespace engine::detail::meta {



template <
    typename... Rest
> struct ForEach
{
    template <
        auto function
    > static inline constexpr void run(auto&... args)
    {
        (function.template operator()<Rest>(std::forward<decltype(args)>(args)...), ...);
    }

    template <
        auto function
    > static inline constexpr auto compare(auto&... args)
        -> bool
    {
        return (function.template operator()<Rest>(std::forward<decltype(args)>(args)...) && ...);
    }
};



} // namespace engine::detail::meta
