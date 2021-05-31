#include <pch.hpp>
#include <Engine/Core/Event/KeyPressed.hpp>
#include <Engine/Core/AScene.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::event::KeyPressed::KeyPressed(
    int keyCode
)
    : m_keyCode{ keyCode }
{}

::engine::core::event::KeyPressed::~KeyPressed() = default;



// ------------------------------------------------------------------ Resolver

void ::engine::core::event::KeyPressed::resolve(
    ::engine::core::AScene& scene
)
{
    switch (m_keyCode) {
    case GLFW_KEY_W: scene.getMainEntityControllable().startMovingForward(); break;
    case GLFW_KEY_S: scene.getMainEntityControllable().startMovingBackward(); break;
    case GLFW_KEY_D: scene.getMainEntityControllable().startMovingRight(); break;
    case GLFW_KEY_A: scene.getMainEntityControllable().startMovingLeft(); break;
    case GLFW_KEY_SPACE: scene.getMainEntityControllable().startMovingUp(); break;
    case GLFW_KEY_X: scene.getMainEntityControllable().startMovingDown(); break;
    case GLFW_KEY_ESCAPE: scene.ends(); break;
    }
}
