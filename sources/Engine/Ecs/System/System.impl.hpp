#pragma once

#include <Engine/Ecs/AComponent.hpp>
#include <Engine/Ecs/System/Detail/System.hpp>



// ------------------------------------------------------------------ Run

template <
    auto func
> void ::engine::ecs::system::System<func>::run(
    ::engine::ecs::entity::Container& entities,
    ::engine::ecs::component::Container& components
)
{
    auto isMatching{ [](const ::engine::ecs::Entity& entity){
        return entity.getSignature() == ::engine::ecs::system::System<func>::getSignature();
    }};
    auto getID{ [](const ::engine::ecs::Entity& entity){ return entity.getID(); }};

    for (auto entityID : entities | std::views::filter(isMatching) | ::std::views::transform(getID)) {
        // get every args into a tupple
        using TupleType = ::engine::detail::meta::Function<decltype(func)>::Arguments::Type;
        auto args{ ::engine::ecs::system::detail::TupleHelper<func, TupleType>::fill(components, entityID) };

        // exec the func
        ::std::apply(func, args);
    }
}



// ------------------------------------------------------------------ Signature

template <
    auto func
> constexpr auto ::engine::ecs::system::System<func>::getSignature()
    -> const ::engine::ecs::Signature&
{
    return ::engine::detail::meta::Function<decltype(func)>::Arguments::signature;
}
