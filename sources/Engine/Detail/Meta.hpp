#pragma once



namespace engine::meta {



template <
    typename... ComponentTypes
> struct ForEach
{
    template <
        auto function
    > static constexpr void run(auto&&... args)
    {
        (function.template operator()<ComponentTypes>(std::forward<decltype(args)>(args)...), ...);
    }
};




} // namespace engine::meta {
