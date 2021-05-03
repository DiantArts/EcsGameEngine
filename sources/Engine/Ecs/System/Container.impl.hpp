#pragma once

template <
    auto func
> void ::engine::ecs::system::Container::emplace()
{
    m_systems.push_back(::std::make_unique<::engine::ecs::System<func>>());
}
