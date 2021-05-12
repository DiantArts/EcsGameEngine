#pragma once

#include <Engine/Core/Detail/Meta/ForEach.hpp>
#include <Engine/Core/Ecs/Detail/Signature.hpp>



// ------------------------------------------------------------------ *structors

constexpr ::engine::core::ecs::Signature::Signature(
    const ::cbitset::Cbitset<::engine::core::ecs::component::maxID>& bitset
)
    : m_bitset{ bitset }
{}

constexpr ::engine::core::ecs::Signature::~Signature() = default;



// ------------------------------------------------------------------ Genetate

template <
    typename... Types
> [[ nodiscard ]] constexpr auto ::engine::core::ecs::Signature::generate()
    -> ::engine::core::ecs::Signature
{
    return engine::core::ecs::detail::signature::Generate<Types...>::value;
}



// ------------------------------------------------------------------ BitManipulation

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> void ::engine::core::ecs::Signature::set()
{
    ::engine::core::detail::meta::ForEach<ComponentTypes...>::template run<
        []<
            ::engine::core::ecs::component::ConceptType RawComponentType
        >(
            ::cbitset::Cbitset<::engine::core::ecs::component::maxID>& signature
        ){
            using ComponentType = std::remove_reference_t<RawComponentType>;
            signature.set(ComponentType::getID());
        }
    >(m_bitset);
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> void ::engine::core::ecs::Signature::reset()
{
    ::engine::core::detail::meta::ForEach<ComponentTypes...>::template run<
        []<
            ::engine::core::ecs::component::ConceptType RawComponentType
        >(
            ::cbitset::Cbitset<::engine::core::ecs::component::maxID>& signature
        ){
            using ComponentType = std::remove_reference_t<RawComponentType>;
            signature.reset(ComponentType::getID());
        }
    >(m_bitset);
}



// ------------------------------------------------------------------ Contains

[[ nodiscard ]] constexpr auto ::engine::core::ecs::Signature::contains(
    const ::engine::core::ecs::Signature& that
) const
    -> bool
{
    return (m_bitset & that.m_bitset) == that.m_bitset;
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> [[ nodiscard ]] constexpr auto ::engine::core::ecs::Signature::contains() const
    -> bool
{
    return ::engine::core::detail::meta::ForEach<ComponentTypes...>::template compare<
        []<
            ::engine::core::ecs::component::ConceptType RawComponentType
        >(
            const ::cbitset::Cbitset<::engine::core::ecs::component::maxID>& bitset
        ){
            using ComponentType = std::remove_reference_t<RawComponentType>;
            return bitset[ComponentType::getID()];
        }
    >(m_bitset);
}

[[ nodiscard ]] constexpr auto ::engine::core::ecs::Signature::contains(
    const ::engine::core::ecs::component::ConceptType auto&... component
) const
    -> bool
{
    return (m_bitset[component.getID()] || ...);
}



// ------------------------------------------------------------------ Comparisons

[[ nodiscard ]] constexpr auto ::engine::core::ecs::Signature::operator==(
    const ::engine::core::ecs::Signature& that
) const
    -> bool
{
    return m_bitset == that.m_bitset;
}

[[ nodiscard ]] constexpr auto ::engine::core::ecs::Signature::operator!=(
    const ::engine::core::ecs::Signature& that
) const
    -> bool
{
    return m_bitset != that.m_bitset;
}
