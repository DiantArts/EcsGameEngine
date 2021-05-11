#include <pch.hpp>
#include <Engine/Core/Event/KeyPressed.hpp>
#include <Engine/Core/AScene.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::event::KeyPressed::KeyPressed(
    int keyCode
)
    : m_keyCode(keyCode)
{}

::engine::core::event::KeyPressed::~KeyPressed() = default;



// ------------------------------------------------------------------ Resolver

void ::engine::core::event::KeyPressed::resolve(
    ::engine::core::AScene& scene
)
{
    // if (scene.m_camera.isAttached()) {
        // switch (m_keyCode) {
        // case GLFW_KEY_W: scene.m_camera.startMovingForward(); break;
        // case GLFW_KEY_S: scene.m_camera.startMovingBackward(); break;
        // case GLFW_KEY_D: scene.m_camera.startMovingRight(); break;
        // case GLFW_KEY_A: scene.m_camera.startMovingLeft(); break;
        // case GLFW_KEY_SPACE: scene.m_camera.startMovingUp(); break;
        // case GLFW_KEY_X: scene.m_camera.startMovingDown(); break;
        // case GLFW_KEY_ESCAPE: scene.setToOver(); break;
        // }
    // } else {
        switch (m_keyCode) {
        // case GLFW_KEY_W: scene.m_player->startMovingForward(); break;
        // case GLFW_KEY_S: scene.m_player->startMovingBackward(); break;
        // case GLFW_KEY_D: scene.m_player->startMovingRight(); break;
        // case GLFW_KEY_A: scene.m_player->startMovingLeft(); break;
        // case GLFW_KEY_SPACE: scene.m_player->startMovingUp(); break;
        // case GLFW_KEY_X: scene.m_player->startMovingDown(); break;
        case GLFW_KEY_ESCAPE: scene.ends(); break;
        }
    // }
}
