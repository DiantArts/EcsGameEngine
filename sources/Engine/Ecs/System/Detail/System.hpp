#pragma once



namespace engine::ecs::system::detail {

template <
    auto func,
    typename
> struct TupleHelper;

template <
    auto func,
    ::engine::ecs::component::ConceptType... ComponentTypes
> requires
    ::engine::detail::meta::UniqueTypes<ComponentTypes...>::value
struct TupleHelper<func, ::std::tuple<ComponentTypes...>> {
    static inline constexpr auto fill(
        ::engine::ecs::component::Container& components,
        ::engine::ID entityID
    )
        -> ::std::tuple<ComponentTypes...>
    {
        return { components.get<ComponentTypes>(entityID) ... };
    }
};

} // namespace engine::ecs::system
