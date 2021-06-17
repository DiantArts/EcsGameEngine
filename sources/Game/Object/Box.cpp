#include <pch.hpp>
#include <Game/Object/Box.hpp>



// ------------------------------------------------------------------ *structors

::game::object::Box::Box()
    : ::engine::shape::Cube(
        {{ "material.texture", "woodFloor.jpg" }},
        "testingCube",
        "testingCube"
    )
{
    m_shader.set("material.shininess", 32.0F);
}

::game::object::Box::~Box() = default;



// ------------------------------------------------------------------ Move sementic

::game::object::Box::Box(
    Box&&
) noexcept = default;

auto ::game::object::Box::operator=(
    Box&&
) noexcept
    -> Box& = default;
