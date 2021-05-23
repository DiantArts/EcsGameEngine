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
    switch (m_keyCode) {
    case GLFW_KEY_W:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            startMovingForward();
        break;
    case GLFW_KEY_S:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            startMovingBackward();
        break;
    case GLFW_KEY_D:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            startMovingRight();
        break;
    case GLFW_KEY_A:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            startMovingLeft();
        break;
    case GLFW_KEY_SPACE:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            startMovingUp();
        break;
    case GLFW_KEY_X:
        scene.m_components.get<::engine::core::ecs::component::Controllable>(scene.m_cameraID).
            startMovingDown();
        break;
    case GLFW_KEY_ESCAPE: scene.ends(); break;
    }
}
