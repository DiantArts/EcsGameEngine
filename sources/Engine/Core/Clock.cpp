#include <pch.hpp>
#include <Engine/Core/Clock.hpp>


// ------------------------------------------------------------------ *structors

::engine::core::Clock::Clock() = default;

::engine::core::Clock::~Clock() = default;



// ------------------------------------------------------------------ Get

auto ::engine::core::Clock::getElapsed()
    -> Clock::Type
{
    return static_cast<Clock::Type>(glfwGetTime()) - m_lastFrameTime;
}

auto ::engine::core::Clock::restart()
    -> Clock::Type
{
    auto currentFrameTime { static_cast<Clock::Type>(glfwGetTime()) };
    auto deltaTime { currentFrameTime - m_lastFrameTime };
    m_lastFrameTime  = currentFrameTime;
    return deltaTime;
}
