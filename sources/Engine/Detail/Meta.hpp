#pragma once



namespace engine::detail::meta {



// ------------------------------------------------------------------ ForEach

template <
    typename... Types
> struct ForEach
{
    template <
        auto function
    > static constexpr void run(auto&&... args)
    {
        (function.template operator()<Types>(std::forward<decltype(args)>(args)...), ...);
    }
};



// ------------------------------------------------------------------ UniqueTypes

template <
    typename... Types
> struct UniqueTypes;

template <
    typename Type1,
    typename Type2,
    typename... Types
> struct UniqueTypes<
    Type1,
    Type2,
    Types...
>{
    static constexpr bool value{
        !::std::is_same<Type1, Type2>::value &&
        engine::detail::meta::UniqueTypes<Type1, Types...>::value &&
        engine::detail::meta::UniqueTypes<Type2, Types...>::value
    };
};

template <
    typename Type1
> struct UniqueTypes<
    Type1
>{
    static constexpr bool value{ true };
};




} // namespace engine::meta {
