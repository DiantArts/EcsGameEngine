#pragma once

#include <Engine/Core/Time.hpp>



namespace engine::core {



class Clock {

public:

    using Type = ::engine::core::Time;



public:

    // ------------------------------------------------------------------ *structors

    Clock();

    ~Clock();



    // ------------------------------------------------------------------ Get

    [[ nodiscard ]] auto getElapsed()
        -> Clock::Type;

    [[ nodiscard ]] auto getRestart()
        -> Clock::Type;

    void restart();



private:

    Clock::Type m_lastFrameTime{ 0.0f };

};



} // namespace engine::core
