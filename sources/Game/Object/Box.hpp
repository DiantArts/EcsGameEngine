#pragma once

#include <Engine/Shape/Cube.hpp>



namespace game::object {



class Box
    : public engine::shape::Cube
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Box();

    ~Box();



    // ------------------------------------------------------------------ Copy sementic

    Box(
        const Box&
    ) noexcept = delete;

    auto operator=(
        const Box&
    ) noexcept
        -> Box& = delete;



    // ------------------------------------------------------------------ Move sementic

    Box(
        Box&&
    ) noexcept;

    auto operator=(
        Box&&
    ) noexcept
        -> Box&;

};



} // namespace game::object
