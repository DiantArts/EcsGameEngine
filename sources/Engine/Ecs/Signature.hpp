#pragma once

#include <Engine/Ecs/AComponent.hpp>
#include <Engine/Detail/Meta.hpp>



namespace engine::ecs {



class Signature {

public:

    using Type = ::cbitset::Cbitset<::engine::ecs::component::maxID>;



public:

    // ------------------------------------------------------------------ *structors

    constexpr ~Signature() = default;



    // ------------------------------------------------------------------ Genetate

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > [[ nodiscard ]] static constexpr engine::ecs::Signature generate()
    {
        Signature::Type signature;

        for (::std::size_t i{ 0 }; i < ::engine::ecs::component::maxID; i++) {
            ::engine::detail::meta::ForEach<ComponentTypes...>::template run<
                []<
                    ::engine::ecs::component::ConceptType ComponentType
                >(
                    Signature::Type& signature,
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
    > void set()
    {
        ::engine::detail::meta::ForEach<ComponentTypes...>::template run<
            []<
                ::engine::ecs::component::ConceptType ComponentType
            >(
                Signature::Type& signature
            ){
                signature.set(ComponentType::getID());
            }
        >(m_signature);
    }

    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > void reset()
    {
        ::engine::detail::meta::ForEach<ComponentTypes...>::template run<
            []<
                ::engine::ecs::component::ConceptType ComponentType
            >(
                Signature::Type& signature
            ){
                signature.reset(ComponentType::getID());
            }
        >(m_signature);
    }



    // ------------------------------------------------------------------ Contains

    constexpr auto contains(
        const ::engine::ecs::Signature& that
    ) const
        -> bool
    {
        return (m_signature & that.m_signature) == that.m_signature;
    }

    constexpr auto operator&(
        const ::engine::ecs::Signature& that
    ) const
        -> bool
    {
        return (m_signature & that.m_signature) == that.m_signature;
    }



    // ------------------------------------------------------------------ Comparisons

    constexpr auto operator==(
        const ::engine::ecs::Signature& that
    ) const
        -> bool
    {
        return m_signature == that.m_signature;
    }

    constexpr auto operator!=(
        const ::engine::ecs::Signature& that
    ) const
        -> bool
    {
        return m_signature != that.m_signature;
    }

    constexpr auto operator==(
        const Signature::Type& that
    ) const
        -> bool
    {
        return m_signature == that;
    }

    constexpr auto operator!=(
        const Signature::Type& that
    ) const
        -> bool
    {
        return m_signature != that;
    }



    // ------------------------------------------------------------------ Others

    friend auto operator<<(
        ::std::ostream& os,
        const engine::ecs::Signature& signature
    )
        -> ::std::ostream&
    {
        for (::std::size_t i{ 0 }; i < ::engine::ecs::component::maxID; i++) {
            os << signature.m_signature[i];
        }
        return os;
    }



private:

    // ------------------------------------------------------------------ *structors

    explicit constexpr Signature(
        const Signature::Type& bitset
    )
        : m_signature{ bitset }
    {}



private:

    Signature::Type m_signature;

};



} // namespace engine::ecs
