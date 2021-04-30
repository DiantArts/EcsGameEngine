#pragma once



// ------------------------------------------------------------------ *structors

template <
    auto function
> ::engine::ecs::system::System<function>::System() = default;

template <
    auto function
> ::engine::ecs::system::System<function>::~System() = default;



// ------------------------------------------------------------------ Run

template <
    auto function
> auto ::engine::ecs::system::System<function>::operator()(
    ::engine::ecs::component::ConceptType auto&... args
)
{
    return function(args...);
}

template <
    auto function
> auto ::engine::ecs::system::System<function>::run(
    ::engine::ecs::component::ConceptType auto&... args
)
{
    return function(args...);
}



// ------------------------------------------------------------------ Signature

template <
    auto function
> constexpr auto ::engine::ecs::system::System<function>::getSignature()
    -> const ::engine::ecs::Signature&
{
    return m_signature;
}
