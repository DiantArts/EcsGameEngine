#pragma once

#include <Engine/Detail/Meta/ForEach.hpp>



// ------------------------------------------------------------------ *structors


constexpr ::engine::ecs::Signature::~Signature() = default;



// ------------------------------------------------------------------ Genetate

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> [[ nodiscard ]] constexpr auto ::engine::ecs::Signature::generate()
    -> ::engine::ecs::Signature
{
    ::cbitset::Cbitset<::engine::ecs::component::maxID> signature;

    for (::std::size_t i{ 0 }; i < ::engine::ecs::component::maxID; i++) {
        ::engine::detail::meta::ForEach<ComponentTypes...>::template run<
            []<
                ::engine::ecs::component::ConceptType ComponentType
            >(
                ::cbitset::Cbitset<::engine::ecs::component::maxID>& signature,
                int i
            ){
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
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::Signature::set()
{
    ::engine::detail::meta::ForEach<ComponentTypes...>::template run<
        []<
            ::engine::ecs::component::ConceptType ComponentType
        >(
            ::cbitset::Cbitset<::engine::ecs::component::maxID>& signature
        ){
            signature.set(ComponentType::getID());
        }
    >(m_bitset);
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::Signature::reset()
{
    ::engine::detail::meta::ForEach<ComponentTypes...>::template run<
        []<
            ::engine::ecs::component::ConceptType ComponentType
        >(
            ::cbitset::Cbitset<::engine::ecs::component::maxID>& signature
        ){
            signature.reset(ComponentType::getID());
        }
    >(m_bitset);
}



// ------------------------------------------------------------------ Contains

[[ nodiscard ]] constexpr auto ::engine::ecs::Signature::contains(
    const ::engine::ecs::Signature& that
) const
    -> bool
{
    return (m_bitset & that.m_bitset) == that.m_bitset;
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> [[ nodiscard ]] constexpr auto ::engine::ecs::Signature::contains() const
    -> bool
{
    return ::engine::detail::meta::ForEach<ComponentTypes...>::template compare<
        []<
            ::engine::ecs::component::ConceptType ComponentType
        >(
            const ::cbitset::Cbitset<::engine::ecs::component::maxID>& bitset
        ){
            return bitset[ComponentType::getID()];
        }
    >(m_bitset);
}

[[ nodiscard ]] constexpr auto ::engine::ecs::Signature::contains(
    const ::engine::ecs::component::ConceptType auto&... component
) const
    -> bool
{
    return (m_bitset[component.getID()] || ...);
}



// ------------------------------------------------------------------ Comparisons

[[ nodiscard ]] constexpr auto ::engine::ecs::Signature::operator==(
    const ::engine::ecs::Signature& that
) const
    -> bool
{
    return m_bitset == that.m_bitset;
}

[[ nodiscard ]] constexpr auto ::engine::ecs::Signature::operator!=(
    const ::engine::ecs::Signature& that
) const
    -> bool
{
    return m_bitset != that.m_bitset;
}



// ------------------------------------------------------------------ *structors

constexpr ::engine::ecs::Signature::Signature(
    const ::cbitset::Cbitset<::engine::ecs::component::maxID>& bitset
)
    : m_bitset{ bitset }
{}
