#pragma once

namespace engine::core::ecs::system::detail {



template <
    auto func,
    typename
> struct TupleHelper;

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> requires
    ::engine::core::detail::meta::UniqueTypes<ComponentTypes...>::value
struct TupleHelper<func, ::std::tuple<ComponentTypes...>> {
    static inline constexpr auto fill(
        ::engine::core::ecs::component::Container& components,
        ::engine::core::ID entityID
    )
        -> ::std::tuple<ComponentTypes...>
    {
        return { components.get<ComponentTypes>(entityID) ... };
    }
};



} // namespace engine::core::ecs::system
