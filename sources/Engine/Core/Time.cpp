#include <pch.hpp>
#include <Engine/Core/Time.hpp>


// ------------------------------------------------------------------ *structors

::engine::core::Time::Time(
    Time::Type time
)
    : m_time{ time }
{}

::engine::core::Time::~Time() = default;



// ------------------------------------------------------------------ Get

::engine::core::Time::operator Time::Type()
{
    return m_time;
}

::engine::core::Time::operator const Time::Type&() const
{
    return m_time;
}

auto ::engine::core::Time::get() const
    -> Time::Type
{
    return m_time;
}
