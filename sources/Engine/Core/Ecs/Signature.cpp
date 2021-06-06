#include <pch.hpp>
#include <Engine/Core/Ecs/Signature.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::ecs::Signature::Signature() = default;





auto ::engine::core::ecs::Signature::get(
    ::engine::core::ecs::component::ConceptType auto& component
)
    -> bool
{
    return m_bitset[component.getID()];
}

auto ::engine::core::ecs::Signature::get(
    ::engine::core::ID id
)
    -> bool
{
    return m_bitset[id];
}



// ------------------------------------------------------------------ Get

auto ::engine::core::ecs::Signature::operator[](
    ::engine::core::ecs::component::ConceptType auto& component
)
    -> bool
{
    return m_bitset[component.getID()];
}

auto ::engine::core::ecs::Signature::operator[](
    ::engine::core::ID id
)
    -> bool
{
    return m_bitset[id];
}
