#pragma once

template <
    auto func,
    ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
> void ::engine::core::ecs::system::Container::emplace()
{
    m_systems.push_back(::std::make_unique<::engine::core::ecs::System<func, BanishedComponentTypes...>>());
}
