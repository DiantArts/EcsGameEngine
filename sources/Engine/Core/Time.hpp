#pragma once

namespace engine::core {



class Time {

public:

    using Type = float;



public:

    // ------------------------------------------------------------------ *structors

    Time(
        Time::Type t
    );

    ~Time();



    // ------------------------------------------------------------------ Get

    [[ nodiscard ]] operator Time::Type();

    [[ nodiscard ]] operator const Time::Type&() const;

    [[ nodiscard ]] auto get() const
        -> Time::Type;



private:

    Time::Type m_time;

};



} // namespace engine::core
