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
            ::engine::core::ecs::system::detail::TupleHelper<func, TupleType>::fill(components, entity)
        };

        // exec the func
        ::std::apply(func, args);
    }
}

template <
    auto func
> void ::engine::core::ecs::system::System<func>::operator()(
    ::engine::core::ecs::component::Container& components,
    ::engine::core::ecs::entity::Container& entities
)
{
    this->operator()(entities, components);
}

template <
    auto func
> void ::engine::core::ecs::system::System<func>::operator()(
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
                ::engine::core::ecs::system::detail::TupleHelper<func, TupleType>::fill(components, entity)
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
    const ::engine::core::ecs::component::Container& components,
    const ::engine::core::ecs::entity::Container& entities
) const
{
    this->operator()(entities, components);
}



// ------------------------------------------------------------------ Signature

template <
    auto func
> constexpr auto ::engine::core::ecs::system::System<func>::getSignature()
    -> const ::engine::core::ecs::Signature&
{
    return ::engine::core::detail::meta::Function<decltype(func)>::Arguments::signature;
}
