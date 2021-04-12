#pragma once

#include <boost/container_hash/hash.hpp>



namespace engine {


class ID {

public:

    using Type = ::std::size_t;

    struct Hasher;

public:

    // ------------------------------------------------------------------ *structors

    // default value is 0
    constexpr ID()
        : m_value{ 0 }
    {}

    constexpr ID(
        ID::Type baseValue
    )
        : m_value{ baseValue }
    {}

    constexpr ~ID() = default;



    // ------------------------------------------------------------------ Copy

    constexpr ID(
        const ID& idGiver
    ) noexcept
    {
        m_value = idGiver;
    }

    void operator=(
        ID idGiver
    ) noexcept
    {
        m_value = idGiver;
    }



    // ------------------------------------------------------------------ Get

    constexpr auto get() const
        -> ID::Type
    {
        return m_value;
    }

    constexpr operator ID::Type() const
    {
        return m_value;
    }

    operator ::std::string() const
    {
        return ::std::to_string(m_value);
    }



    // ------------------------------------------------------------------ Set

    void operator=(ID::Type value);



    // ------------------------------------------------------------------ Incrementation

    auto operator++()
        -> ID::Type;

    auto operator++(int)
        -> ID::Type;

    void increment();



    // ------------------------------------------------------------------ Others

    auto operator<=>(const ID& other)
        -> ::std::weak_ordering;



private:

    ID::Type m_value;

};



struct ID::Hasher {

public:

    auto operator () (
        const ::engine::ID& id
    ) const
        -> ::std::size_t
    {
        ::std::size_t seed = 0;
        boost::hash_combine(seed, id.get());
        return seed;
    }

};



} // namespace engine
