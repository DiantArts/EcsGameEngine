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
    case GLFW_KEY_W:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            stopMovingForward();
        break;
    case GLFW_KEY_S:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            stopMovingBackward();
        break;
    case GLFW_KEY_D:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            stopMovingRight();
        break;
    case GLFW_KEY_A:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            stopMovingLeft();
        break;
    case GLFW_KEY_SPACE:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            stopMovingUp();
        break;
    case GLFW_KEY_X:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            stopMovingDown();
        break;
    }
}
