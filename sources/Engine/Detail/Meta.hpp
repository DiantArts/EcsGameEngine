#pragma once



namespace engine::meta {



template <
    typename... ComponentTypes
> struct ForEach
{
    template <
        auto Function
    > static constexpr void run(auto&&... args)
    {
        (Function.template operator()<ComponentTypes>(std::forward<decltype(args)>(args)...), ...);
    }
};




} // namespace engine::meta {
