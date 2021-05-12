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
struct TupleHelper<
    func,
    ::std::tuple<ComponentTypes...>
> {
    static inline constexpr auto fill(
        ::engine::core::ecs::component::Container& components,
        ::engine::core::ecs::Entity& entity
    )
        -> ::std::tuple<ComponentTypes...>
    {
        return { components.get<ComponentTypes>(entity.getID()) ... };
    }

    static inline constexpr auto fill(
        const ::engine::core::ecs::component::Container& components,
        const ::engine::core::ecs::Entity& entity
    )
        -> ::std::tuple<ComponentTypes...>
    {
        return { components.get<ComponentTypes>(entity.getID()) ... };
    }
};

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> requires
    ::engine::core::detail::meta::UniqueTypes<ComponentTypes...>::value
struct TupleHelper<
    func,
    ::std::tuple<const ::engine::core::ecs::Entity&, ComponentTypes...>
> {
    static inline constexpr auto fill(
        ::engine::core::ecs::component::Container& components,
        const ::engine::core::ecs::Entity& entity
    )
        -> ::std::tuple<const ::engine::core::ecs::Entity&, ComponentTypes...>
    {
        return { entity, components.get<ComponentTypes>(entity.getID()) ... };
    }

    static inline constexpr auto fill(
        const ::engine::core::ecs::component::Container& components,
        const ::engine::core::ecs::Entity& entity
    )
        -> ::std::tuple<const ::engine::core::ecs::Entity&, ComponentTypes...>
    {
        return { entity, components.get<ComponentTypes>(entity.getID()) ... };
    }
};

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> requires
    ::engine::core::detail::meta::UniqueTypes<ComponentTypes...>::value
struct TupleHelper<
    func,
    ::std::tuple<::engine::core::ecs::Entity&, ComponentTypes...>
> {
    static inline constexpr auto fill(
        ::engine::core::ecs::component::Container& components,
        ::engine::core::ecs::Entity& entity
    )
        -> ::std::tuple<::engine::core::ecs::Entity&, ComponentTypes...>
    {
        return { entity, components.get<ComponentTypes>(entity.getID()) ... };
    }

    static inline constexpr auto fill(
        const ::engine::core::ecs::component::Container& components,
        ::engine::core::ecs::Entity& entity
    )
        -> ::std::tuple<::engine::core::ecs::Entity&, ComponentTypes...>
    {
        return { entity, components.get<ComponentTypes>(entity.getID()) ... };
    }
};



} // namespace engine::core::ecs::system
