#include <pch.hpp>
#include <Engine/Core/Event/KeyReleased.hpp>



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
    // if (scene.m_camera.isAttached()) {
        // switch (m_keyCode) {
        // case GLFW_KEY_W: scene.m_camera.stopMovingForward(); break;
        // case GLFW_KEY_S: scene.m_camera.stopMovingBackward(); break;
        // case GLFW_KEY_D: scene.m_camera.stopMovingRight(); break;
        // case GLFW_KEY_A: scene.m_camera.stopMovingLeft(); break;
        // case GLFW_KEY_SPACE: scene.m_camera.stopMovingUp(); break;
        // case GLFW_KEY_X: scene.m_camera.stopMovingDown(); break;
        // }
    // } else {
        // switch (m_keyCode) {
        // case GLFW_KEY_W: scene.m_player->stopMovingForward(); break;
        // case GLFW_KEY_S: scene.m_player->stopMovingBackward(); break;
        // case GLFW_KEY_D: scene.m_player->stopMovingRight(); break;
        // case GLFW_KEY_A: scene.m_player->stopMovingLeft(); break;
        // case GLFW_KEY_SPACE: scene.m_player->stopMovingUp(); break;
        // case GLFW_KEY_X: scene.m_player->stopMovingDown(); break;
        // }
    // }
}
