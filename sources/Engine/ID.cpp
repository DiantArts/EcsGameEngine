#include <pch.hpp>
#include <Engine/ID.hpp>



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
