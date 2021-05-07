#pragma once

template <
    auto func
> void ::engine::core::ecs::system::Container::emplace()
{
    m_systems.push_back(::std::make_unique<::engine::core::ecs::System<func>>());
}
