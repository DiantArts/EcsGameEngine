#pragma once

namespace engine::core {



class ID {

public:

    using Type = ::std::size_t;

    struct Hasher;

public:

    // ------------------------------------------------------------------ *structors

    // default value is 0
    constexpr ID();

    constexpr ID(
        ::std::integral auto baseValue
    );

    constexpr ~ID();



    // ------------------------------------------------------------------ Get

    [[ nodiscard ]] constexpr auto get() const
        -> ID::Type;

    [[ nodiscard ]] constexpr operator ID::Type() const;

    [[ nodiscard ]] operator ::std::string() const;



    // ------------------------------------------------------------------ Set

    void operator=(ID::Type value);



    // ------------------------------------------------------------------ Incrementation

    auto operator++()
        -> ID::Type;

    [[ nodiscard ]] auto operator++(int)
        -> ID::Type;

    void increment();



    // ------------------------------------------------------------------ Others

    [[ nodiscard ]] auto operator<=>(const ID& other)
        -> ::std::weak_ordering;



private:

    ID::Type m_value;

};



} // namespace engine::core

#include <Engine/Core/ID.impl.hpp>
