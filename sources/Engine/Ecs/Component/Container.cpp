#include <pch.hpp>
#include <Engine/Ecs/Component/Container.hpp>



// ------------------------------------------------------------------ *structors

::engine::ecs::component::Container::Container() = default;

::engine::ecs::component::Container::~Container() = default;



// ------------------------------------------------------------------ Get

auto ::engine::ecs::component::Container::getSize() const
    -> ::std::size_t
{
    return m_container.size();
}
