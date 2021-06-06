#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>



namespace engine::core::ecs {



class Signature {

public:

    // ------------------------------------------------------------------ *structors

    explicit Signature();

    explicit constexpr Signature(
        const ::cbitset::Cbitset<::engine::core::ecs::component::maxID>& bitset
    );

    constexpr ~Signature();



    // ------------------------------------------------------------------ Genetate

    template <
        typename... Types
    > [[ nodiscard ]] static constexpr auto generate()
        -> ::engine::core::ecs::Signature;



    // ------------------------------------------------------------------ BitManipulation

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > void set();

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > void reset();



    // ------------------------------------------------------------------ Get

    template <
        ::engine::core::ecs::component::ConceptType ComponentType
    > auto get()
        -> bool;

    auto get(::engine::core::ecs::component::ConceptType auto& component)
        -> bool;

    auto get(::engine::core::ID id)
        -> bool;


    auto operator[](::engine::core::ecs::component::ConceptType auto& component)
        -> bool;

    auto operator[](::engine::core::ID id)
        -> bool;



    // ------------------------------------------------------------------ Contains

    [[ nodiscard ]] constexpr auto contains(
        const ::engine::core::ecs::Signature& that
    ) const
        -> bool;

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] constexpr auto contains() const
        -> bool;

    [[ nodiscard ]] constexpr auto contains(
        const ::engine::core::ecs::component::ConceptType auto&... component
    ) const
        -> bool;



    // ------------------------------------------------------------------ ContainsOne

    [[ nodiscard ]] constexpr auto containsAtLeastOne(
        const ::engine::core::ecs::Signature& that
    ) const
        -> bool;

    template <
        ::engine::core::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] constexpr auto containsAtLeastOne() const
        -> bool;

    [[ nodiscard ]] constexpr auto containsAtLeastOne(
        const ::engine::core::ecs::component::ConceptType auto&... component
    ) const
        -> bool;



    // ------------------------------------------------------------------ Comparisons

    [[ nodiscard ]] constexpr auto operator==(
        const ::engine::core::ecs::Signature& that
    ) const
        -> bool;

    [[ nodiscard ]] constexpr auto operator!=(
        const ::engine::core::ecs::Signature& that
    ) const
        -> bool;



    // ------------------------------------------------------------------ Others

    friend auto operator<<(
        ::std::ostream& os,
        const engine::core::ecs::Signature& signature
    )
        -> ::std::ostream&
    {
        for (::std::size_t i{ 0 }; i < ::engine::core::ecs::component::maxID; i++) {
            os << signature.m_bitset[i];
        }
        return os;
    }



// private:

    ::cbitset::Cbitset<::engine::core::ecs::component::maxID> m_bitset;

};



} // namespace engine::core::ecs

#include <Engine/Core/Ecs/Signature.impl.hpp>
