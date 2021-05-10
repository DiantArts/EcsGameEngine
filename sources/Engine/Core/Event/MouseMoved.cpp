#include <pch.hpp>
#include <Engine/Core/Event/MouseMoved.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::event::MouseMoved::MouseMoved(
    float xPos,
    float yPos
)
    : m_offset(xPos, yPos)
{}

::engine::core::event::MouseMoved::~MouseMoved() = default;



// ------------------------------------------------------------------ Resolver

void ::engine::core::event::MouseMoved::resolve(
    ::engine::core::AScene& scene
)
{
    // scene.m_camera.orienteFromCursorPosition(std::move(m_offset));
}
