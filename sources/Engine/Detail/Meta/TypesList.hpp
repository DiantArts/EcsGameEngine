#pragma once

namespace engine::detail::meta {



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



} // namespace engine::detail::meta
