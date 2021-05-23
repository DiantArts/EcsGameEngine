#include <pch.hpp>
#include <Engine/Core/Ecs/System/Container.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::ecs::system::Container::Container() = default;

::engine::core::ecs::system::Container::~Container() = default;



// ------------------------------------------------------------------ Run

void ::engine::core::ecs::system::Container::run(
    ::engine::core::Time t,
    ::engine::core::ecs::entity::Container& entities,
    ::engine::core::ecs::component::Container& components
)
{
    for (auto& system : m_systems) {
        system->operator()(t, entities, components);
    }
}

void ::engine::core::ecs::system::Container::run(
    ::engine::core::Time t,
    const ::engine::core::ecs::entity::Container& entities,
    const ::engine::core::ecs::component::Container& components
) const
{
    for (auto& system : m_systems) {
        system->operator()(t, entities, components);
    }
}
