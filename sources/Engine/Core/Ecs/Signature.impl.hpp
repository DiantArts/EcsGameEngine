#pragma once

#include <Engine/Core/Detail/Meta/ForEach.hpp>



// ------------------------------------------------------------------ *structors

constexpr ::engine::core::ecs::Signature::~Signature() = default;



// ------------------------------------------------------------------ Genetate

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> [[ nodiscard ]] constexpr auto ::engine::core::ecs::Signature::generate()
    -> ::engine::core::ecs::Signature
{
    ::cbitset::Cbitset<::engine::core::ecs::component::maxID> signature;

    for (::std::size_t i{ 0 }; i < ::engine::core::ecs::component::maxID; i++) {
        ::engine::core::detail::meta::ForEach<ComponentTypes...>::template run<
            []<
                ::engine::core::ecs::component::ConceptType RawComponentType
            >(
                ::cbitset::Cbitset<::engine::core::ecs::component::maxID>& signature,
                int i
            ){
                using ComponentType = std::remove_reference_t<RawComponentType>;
                if (ComponentType::getID() == i) {
                    signature.set(i);
                }
            }
        >(signature, i);
    }

    return Signature{ signature };
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



// ------------------------------------------------------------------ *structors

constexpr ::engine::core::ecs::Signature::Signature(
    const ::cbitset::Cbitset<::engine::core::ecs::component::maxID>& bitset
)
    : m_bitset{ bitset }
{}
