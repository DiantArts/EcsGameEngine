#include <pch.hpp>
#include <Engine/Core/Event/MouseMoved.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::event::MouseMoved::MouseMoved(
    float xPos,
    float yPos
)
    : m_offset{ xPos - m_oldPosition.x, -yPos + m_oldPosition.y }
{
    m_oldPosition = ::glm::vec2{ xPos, yPos };
}

::engine::core::event::MouseMoved::~MouseMoved() = default;



// ------------------------------------------------------------------ Resolver

void ::engine::core::event::MouseMoved::resolve(
    ::engine::core::AScene& scene
)
{
    scene.getMainEntityControllable().oriente(::std::move(m_offset));
}
