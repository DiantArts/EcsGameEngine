#pragma once



namespace engine::core::detail::meta {

template <
    typename... Rest
> struct UniqueTypes;

template <
    typename Type1,
    typename Type2,
    typename... Rest
> struct UniqueTypes<
    Type1,
    Type2,
    Rest...
>{
    static constexpr bool value{
        !::std::is_same<Type1, Type2>::value &&
        engine::core::detail::meta::UniqueTypes<Type1, Rest...>::value &&
        engine::core::detail::meta::UniqueTypes<Type2, Rest...>::value
    };
};

template <
    typename Type1
> struct UniqueTypes<
    Type1
>{
    static constexpr bool value{ true };
};



} // namespace engine::core::detail::meta
