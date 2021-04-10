#pragma once



namespace engine {


class ID {

public:

    using Type = ::std::size_t;

public:

    // ------------------------------------------------------------------ *structors

    // default value is 0
    constexpr ID()
        : m_id{ 0 }
    {}

    constexpr ID(ID::Type baseValue)
        : m_id{ baseValue }
    {}

    ID(ID& idGiver);

    constexpr ~ID() = default;



    // ------------------------------------------------------------------ Get

    constexpr auto get() const
        -> ID::Type
    {
        return m_id;
    }

    constexpr operator ID::Type() const
    {
        return m_id;
    }


    // ------------------------------------------------------------------ Incrementation

    void operator++();

    auto operator++(int)
        -> int;

    void increment();



private:

    ID::Type m_id;

};



} // namespace engine
