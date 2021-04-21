#include <pch.hpp>
#include <Engine/ID.hpp>


// ------------------------------------------------------------------ Get

::engine::ID::operator ::std::string() const
{
    return ::std::to_string(m_value);
}



// ------------------------------------------------------------------ Set

void ::engine::ID::operator=(ID::Type value)
{
    m_value = value;
}



// ------------------------------------------------------------------ Incrementation

auto ::engine::ID::operator++()
    -> ID::Type
{
    m_value++;
    return m_value;
}

auto ::engine::ID::operator++(int)
    -> ID::Type
{
    auto value { m_value };
    m_value++;
    return value;
}

void ::engine::ID::increment()
{
    m_value++;
}



// ------------------------------------------------------------------ Others

auto ::engine::ID::operator<=>(const ID& other)
    -> ::std::weak_ordering
{
    return m_value <=> other.m_value;
}
