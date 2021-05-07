#pragma once

// ------------------------------------------------------------------ *structors

// default value is 0
constexpr ::engine::core::ID::ID()
    : m_value{ 0 }
{}

constexpr ::engine::core::ID::ID(
    ::std::integral auto baseValue
)
    : m_value{ static_cast<ID::Type>(baseValue) }
{}

constexpr ::engine::core::ID::~ID() = default;



// ------------------------------------------------------------------ Get

constexpr auto ::engine::core::ID::get() const
    -> ::engine::core::ID::Type
{
    return m_value;
}

constexpr ::engine::core::ID::operator ::engine::core::ID::Type() const
{
    return m_value;
}



// ------------------------------------------------------------------ Hasher

namespace engine::core {



struct ID::Hasher {

    auto operator () (
        const ::engine::core::ID& id
    ) const
        -> ::std::size_t
    {
        ::std::size_t seed = 0;
        boost::hash_combine(seed, id.get());
        return seed;
    }

};



} // engine::core
