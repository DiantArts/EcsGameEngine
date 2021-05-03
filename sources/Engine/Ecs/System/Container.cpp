#include <pch.hpp>
#include <Engine/Ecs/System/Container.hpp>



// ------------------------------------------------------------------ *structors

::engine::ecs::system::Container::Container() = default;

::engine::ecs::system::Container::~Container() = default;



// ------------------------------------------------------------------ Run

void ::engine::ecs::system::Container::run(
    ::engine::ecs::entity::Container& entities,
    ::engine::ecs::component::Container& components
)
{
    for (auto& system : m_systems) {
        system->run(entities, components);
    }
}
