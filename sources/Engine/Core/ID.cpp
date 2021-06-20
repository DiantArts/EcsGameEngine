#include <pch.hpp>
#include <Engine/Core/ID.hpp>


// ------------------------------------------------------------------ Get

::engine::core::ID::operator ::std::string() const
{
    return ::std::to_string(m_value);
}



// ------------------------------------------------------------------ Set

void ::engine::core::ID::operator=(ID::Type value)
{
    m_value = value;
}



// ------------------------------------------------------------------ Incrementation

auto ::engine::core::ID::operator++()
    -> ID::Type
{
    ++m_value;
    return m_value;
}

auto ::engine::core::ID::operator++(int)
    -> ID::Type
{
    auto value { m_value };
    ++m_value;
    return value;
}

void ::engine::core::ID::increment()
{
    ++m_value;
}



// ------------------------------------------------------------------ Others

auto ::engine::core::ID::operator<=>(const ID& other)
    -> ::std::weak_ordering
{
    return m_value <=> other.m_value;
}
