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
> void ::engine::core::ecs::system::System<func>::run(
    ::engine::core::ecs::entity::Container& entities,
    ::engine::core::ecs::component::Container& components
)
{
    auto isMatching{ [](const ::engine::core::ecs::Entity& entity) {
        return entity.getSignature().contains(::engine::core::ecs::system::System<func>::getSignature());
    } };
    auto getID{ [](const ::engine::core::ecs::Entity& entity) { return entity.getID(); } };

    for (auto entityID : entities | std::views::filter(isMatching) | ::std::views::transform(getID)) {
        // get every args into a tupple
        using TupleType = ::engine::core::detail::meta::Function<decltype(func)>::Arguments::Type;
        auto args{
            ::engine::core::ecs::system::detail::TupleHelper<func, TupleType>::fill(components, entityID)
        };

        // exec the func
        ::std::apply(func, args);
    }
}

template <
    auto func
> void ::engine::core::ecs::system::System<func>::run(
    ::engine::core::ecs::component::Container& components,
    ::engine::core::ecs::entity::Container& entities
)
{
    this->run(entities, components);
}

template <
    auto func
> void ::engine::core::ecs::system::System<func>::run(
    const ::engine::core::ecs::entity::Container& entities,
    const ::engine::core::ecs::component::Container& components
) const
{
    auto isMatching{ [](const ::engine::core::ecs::Entity& entity) {
        return entity.getSignature().contains(::engine::core::ecs::system::System<func>::getSignature());
    } };
    auto getID{ [](const ::engine::core::ecs::Entity& entity) { return entity.getID(); } };

    for (auto entityID : entities | std::views::filter(isMatching) | ::std::views::transform(getID)) {
        // get every args into a tupple
        using TupleType = ::engine::core::detail::meta::Function<decltype(func)>::Arguments::Type;
        auto args{
            ::engine::core::ecs::system::detail::TupleHelper<func, TupleType>::fill(components, entityID)
        };

        // exec the func
        ::std::apply(func, args);
    }
}

template <
    auto func
> void ::engine::core::ecs::system::System<func>::run(
    const ::engine::core::ecs::component::Container& components,
    const ::engine::core::ecs::entity::Container& entities
) const
{
    this->run(entities, components);
}



// ------------------------------------------------------------------ Signature

template <
    auto func
> constexpr auto ::engine::core::ecs::system::System<func>::getSignature()
    -> const ::engine::core::ecs::Signature&
{
    return ::engine::core::detail::meta::Function<decltype(func)>::Arguments::signature;
}
