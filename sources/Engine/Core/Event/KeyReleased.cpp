#include <pch.hpp>
#include <Engine/Core/Event/KeyReleased.hpp>
#include <Engine/Core/AScene.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::event::KeyReleased::KeyReleased(
    int keyCode
)
    : m_keyCode(keyCode)
{}

::engine::core::event::KeyReleased::~KeyReleased() = default;



// ------------------------------------------------------------------ Resolver

void ::engine::core::event::KeyReleased::resolve(
    ::engine::core::AScene& scene
)
{
    switch (m_keyCode) {
    case GLFW_KEY_W: scene.getMainEntityControllable().stopMovingForward(); break;
    case GLFW_KEY_S: scene.getMainEntityControllable().stopMovingBackward(); break;
    case GLFW_KEY_D: scene.getMainEntityControllable().stopMovingRight(); break;
    case GLFW_KEY_A: scene.getMainEntityControllable().stopMovingLeft(); break;
    case GLFW_KEY_SPACE: scene.getMainEntityControllable().stopMovingUp(); break;
    case GLFW_KEY_X: scene.getMainEntityControllable().stopMovingDown(); break;
    }
}
