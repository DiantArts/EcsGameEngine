#pragma once

// ------------------------------------------------------------------ *structors

// default value is 0
constexpr ::engine::ID::ID()
    : m_value{ 0 }
{}

constexpr ::engine::ID::ID(
    ::std::integral auto baseValue
)
    : m_value{ static_cast<ID::Type>(baseValue) }
{}

constexpr ::engine::ID::~ID() = default;



// ------------------------------------------------------------------ Copy

constexpr ::engine::ID::ID(
    const ID& idGiver
) noexcept
{
    m_value = idGiver;
}



// ------------------------------------------------------------------ Get

constexpr auto ::engine::ID::get() const
    -> ::engine::ID::Type
{
    return m_value;
}

constexpr ::engine::ID::operator ::engine::ID::Type() const
{
    return m_value;
}



// ------------------------------------------------------------------ Hasher

namespace engine {



struct ID::Hasher {

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



} // engine
