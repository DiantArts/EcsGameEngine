#pragma once

#include <Engine/Ecs/AComponent.hpp>



#include <Engine/Detail/Meta.hpp>
namespace engine::ecs {



class Signature {




public:

    // ------------------------------------------------------------------ *structors

    explicit Signature();

    constexpr ~Signature();



    // ------------------------------------------------------------------ Genetate

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] static constexpr auto generate()
        -> ::engine::ecs::Signature;



    // ------------------------------------------------------------------ BitManipulation

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void set();

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void reset();



    // ------------------------------------------------------------------ Contains

    [[ nodiscard ]] constexpr auto contains(
        const ::engine::ecs::Signature& that
    ) const
        -> bool;

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] constexpr auto contains() const
        -> bool;

    [[ nodiscard ]] constexpr auto contains(
        const ::engine::ecs::component::ConceptType auto&... component
    ) const
        -> bool;



    // ------------------------------------------------------------------ Comparisons

    [[ nodiscard ]] constexpr auto operator==(
        const ::engine::ecs::Signature& that
    ) const
        -> bool;

    [[ nodiscard ]] constexpr auto operator!=(
        const ::engine::ecs::Signature& that
    ) const
        -> bool;



    // ------------------------------------------------------------------ Others

    friend auto operator<<(
        ::std::ostream& os,
        const engine::ecs::Signature& signature
    )
        -> ::std::ostream&
    {
        for (::std::size_t i{ 0 }; i < ::engine::ecs::component::maxID; i++) {
            os << signature.m_bitset[i];
        }
        return os;
    }



private:

    // ------------------------------------------------------------------ *structors

    explicit constexpr Signature(
        const ::cbitset::Cbitset<::engine::ecs::component::maxID>& bitset
    );



private:

    ::cbitset::Cbitset<::engine::ecs::component::maxID> m_bitset;

};



} // namespace engine::ecs

#include <Engine/Ecs/Signature.impl.hpp>
