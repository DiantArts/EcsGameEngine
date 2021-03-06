#pragma once

namespace engine::core::detail::meta {



template <
    template <typename...> class Base,
    typename Derived
> struct IsBaseOfTemplate {

    // A function which can only be called by something convertible to a Base<Ts...>*
    // We return a::std::variant here as a way of "returning" a parameter pack
    template<
        typename... Ts
    > static constexpr auto is_callable( Base<Ts...>* )
        -> ::std::variant<Ts...>;

    // Detector, will return type of calling is_callable, or it won't compile if that can't be done
    template <
        typename T
    > using is_callable_t = decltype(is_callable(::std::declval<T*>()));

    // Is it possible to call is_callable which the Derived type
    static inline constexpr bool value = ::std::experimental::is_detected<is_callable_t, Derived>::value;

    // If it is possible to call is_callable with the Derived type what would it return, if not type is void
    using type = ::std::experimental::detected_or_t<void, is_callable_t, Derived>;

};



} // namespace engine::core::detail::meta
