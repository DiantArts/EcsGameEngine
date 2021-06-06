#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Core/Ecs/System/Detail/System.hpp>



// ------------------------------------------------------------------ *structors

template <
    auto func
> ::engine::core::ecs::system::System<func>::System() = default;

template <
    auto func
> ::engine::core::ecs::system::System<func>::~System() = default;



// ------------------------------------------------------------------ Run

template <
    auto func
> void ::engine::core::ecs::system::System<func>::operator()(
    ::engine::core::Time t,
    ::engine::core::ecs::entity::Container& entities,
    ::engine::core::ecs::component::Container& components
)
{
    auto isMatching{ [](const ::engine::core::ecs::Entity& entity) {
        return entity.getSignature().contains(::engine::core::ecs::system::System<func>::getSignature());
    } };

    for (auto& entity : entities | std::views::filter(isMatching)) {
        // get every args into a tupple
        using TupleType = ::engine::core::detail::meta::Function<decltype(func)>::Arguments::Type;
        auto args{
            ::engine::core::ecs::system::detail::TupleHelper<func, TupleType>::fill(t, components, entity)
        };

        // exec the func
        ::std::apply(func, args);
    }
}

template <
    auto func
> void ::engine::core::ecs::system::System<func>::operator()(
    ::engine::core::Time t,
    ::engine::core::ecs::component::Container& components,
    ::engine::core::ecs::entity::Container& entities
)
{
    this->operator()(t, entities, components);
}



template <
    auto func
> void ::engine::core::ecs::system::System<func>::operator()(
    ::engine::core::Time t,
    const ::engine::core::ecs::entity::Container& entities,
    const ::engine::core::ecs::component::Container& components
) const
{
    auto isMatching{ [](const ::engine::core::ecs::Entity& entity) {
        return entity.getSignature().contains(::engine::core::ecs::system::System<func>::getSignature());
    } };

    if constexpr (::engine::core::detail::meta::Function<decltype(func)>::Arguments::areConst) {
        for (auto& entity : entities | std::views::filter(isMatching)) {
            // get every args into a tupple
            using TupleType = ::engine::core::detail::meta::Function<decltype(func)>::Arguments::Type;
            auto args{
                ::engine::core::ecs::system::detail::TupleHelper<func, TupleType>::fill(t, components, entity)
            };

            // exec the func
            ::std::apply(func, args);
        }
    } else {
        throw ::std::runtime_error{ "System called as const but doesn't contain const argments" };
    }
}

template <
    auto func
> void ::engine::core::ecs::system::System<func>::operator()(
    ::engine::core::Time t,
    const ::engine::core::ecs::component::Container& components,
    const ::engine::core::ecs::entity::Container& entities
) const
{
    this->operator()(t, entities, components);
}



// ------------------------------------------------------------------ Signature

template <
    auto func
> constexpr auto ::engine::core::ecs::system::System<func>::getSignature()
    -> const ::engine::core::ecs::Signature&
{
    return ::engine::core::detail::meta::Function<decltype(func)>::Arguments::signature;
}



// -------------------------------------------------------------------------------------- Banished

// ------------------------------------------------------------------ *structors

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
> ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::System()
{
    // static_assert(
        // !::engine::core::ecs::system::System<
            // func,
            // BanishedComponentTypes...
        // >::getSignature().containsAtLeastOne(::engine::core::ecs::system::System<
            // func,
            // BanishedComponentTypes...
        // >::getBanishedSignature()),
        // "System signature contains a banished component"
    // );
};

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
> ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::~System() = default;



// ------------------------------------------------------------------ Run

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
> void ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::operator()(
    ::engine::core::Time t,
    ::engine::core::ecs::entity::Container& entities,
    ::engine::core::ecs::component::Container& components
)
{
    auto isMatching{ [](const ::engine::core::ecs::Entity& entity) {
        auto& signature{ entity.getSignature() };
        return signature.contains(
                ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::getSignature()
            ) &&
            !signature.containsAtLeastOne(
                ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::getBanishedSignature()
            );
    } };

    for (auto& entity : entities | std::views::filter(isMatching)) {
        // get every args into a tupple
        using TupleType = ::engine::core::detail::meta::Function<decltype(func)>::Arguments::Type;
        auto args{
            ::engine::core::ecs::system::detail::TupleHelper<func, TupleType>::fill(t, components, entity)
        };

        // exec the func
        ::std::apply(func, args);
    }
}

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
> void ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::operator()(
    ::engine::core::Time t,
    ::engine::core::ecs::component::Container& components,
    ::engine::core::ecs::entity::Container& entities
)
{
    this->operator()(t, entities, components);
}



template <
    auto func,
    ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
> void ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::operator()(
    ::engine::core::Time t,
    const ::engine::core::ecs::entity::Container& entities,
    const ::engine::core::ecs::component::Container& components
) const
{
    auto isMatching{ [](const ::engine::core::ecs::Entity& entity) {
        auto& signature{ entity.getSignature() };
        return signature.contains(
                ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::getSignature()
            ) &&
            !signature.containsAtLeastOne(
                ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::getBanishedSignature()
            );
    } };

    if constexpr (::engine::core::detail::meta::Function<decltype(func)>::Arguments::areConst) {
        for (auto& entity : entities | std::views::filter(isMatching)) {
            // get every args into a tupple
            using TupleType = ::engine::core::detail::meta::Function<decltype(func)>::Arguments::Type;
            auto args{
                ::engine::core::ecs::system::detail::TupleHelper<func, TupleType>::fill(t, components, entity)
            };

            // exec the func
            ::std::apply(func, args);
        }
    } else {
        throw ::std::runtime_error{ "System called as const but doesn't contain const argments" };
    }
}

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
> void ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::operator()(
    ::engine::core::Time t,
    const ::engine::core::ecs::component::Container& components,
    const ::engine::core::ecs::entity::Container& entities
) const
{
    this->operator()(t, entities, components);
}



// ------------------------------------------------------------------ Signature

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
> constexpr auto ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::getSignature()
    -> const ::engine::core::ecs::Signature&
{
    return ::engine::core::detail::meta::Function<decltype(func)>::Arguments::signature;
}

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
> constexpr auto ::engine::core::ecs::system::System<func, BanishedComponentTypes...>::getBanishedSignature()
    -> const ::engine::core::ecs::Signature&
{
    return m_banishedSignature;
}
