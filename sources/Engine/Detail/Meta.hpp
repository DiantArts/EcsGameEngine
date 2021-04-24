#pragma once



namespace engine::detail::meta {



// ------------------------------------------------------------------ ForEach

template <
    typename... Rest
> struct ForEach
{
    template <
        auto function
    > static constexpr void run(auto&... args)
    {
        (function.template operator()<Rest>(std::forward<decltype(args)>(args)...), ...);
    }

    template <
        auto function
    > static constexpr auto compare(auto&... args)
        -> bool
    {
        return (function.template operator()<Rest>(std::forward<decltype(args)>(args)...) && ...);
    }
};



// ------------------------------------------------------------------ UniqueTypes

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
        engine::detail::meta::UniqueTypes<Type1, Rest...>::value &&
        engine::detail::meta::UniqueTypes<Type2, Rest...>::value
    };
};

template <
    typename Type1
> struct UniqueTypes<
    Type1
>{
    static constexpr bool value{ true };
};



// ------------------------------------------------------------------ Contains

template <
    typename... Rest
> struct TypeList {

    template <
        typename Type
    > static constexpr bool contains()
    {
        return (std::is_same_v<Type, Rest> || ...);
    }

};



// ------------------------------------------------------------------ IsBaseOfTemplate

template <
    template <typename...> class Base,
    typename Derived
> struct IsBaseOfTemplate {

    // A function which can only be called by something convertible to a Base<Ts...>*
    // We return a std::variant here as a way of "returning" a parameter pack
    template<
        typename... Ts
    > static constexpr auto is_callable( Base<Ts...>* )
        -> ::std::variant<Ts...>;

    // Detector, will return type of calling is_callable, or it won't compile if that can't be done
    template <
        typename T
    > using is_callable_t = decltype(is_callable(std::declval<T*>()));

    // Is it possible to call is_callable which the Derived type
    static inline constexpr bool value = ::std::experimental::is_detected<is_callable_t, Derived>::value;

    // If it is possible to call is_callable with the Derived type what would it return, if not type is void
    using type = ::std::experimental::detected_or_t<void, is_callable_t, Derived>;

};



} // namespace engine::detail::meta {
