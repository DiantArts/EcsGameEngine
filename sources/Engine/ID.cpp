#include <pch.hpp>
#include <Engine/ID.hpp>



// ------------------------------------------------------------------ *structors

::engine::ID::ID(ID& idGiver)
    : m_id{ idGiver.get() }
{
    idGiver++;
}



// ------------------------------------------------------------------ Incrementation

void ::engine::ID::operator++()
{
    m_id++;
}

auto ::engine::ID::operator++(int)
    -> int
{
    auto id { m_id };
    m_id++;
    return id;
}

void ::engine::ID::increment()
{
    m_id++;
}
