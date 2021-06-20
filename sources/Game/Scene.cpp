#include <pch.hpp>
#include <Game/Scene.hpp>
#include <Engine/Graphic/OpenGL/Vertices.hpp>



// ------------------------------------------------------------------ *structors

::game::Scene::Scene(
    ::engine::core::AWindow& window
)
    : ::engine::core::AScene{ window }
{
    for (auto&& position : ::std::vector<::glm::vec3>{
        ::glm::vec3( 0.0f,  0.0f,  0.0f),
        ::glm::vec3( 2.0f,  5.0f, -15.0f),
        ::glm::vec3(-1.5f, -2.2f, -2.5f),
        ::glm::vec3(-3.8f, -2.0f, -12.3f),
        ::glm::vec3( 2.4f, -0.4f, -3.5f),
        ::glm::vec3(-1.7f,  3.0f, -7.5f),
        ::glm::vec3( 1.3f, -2.0f, -2.5f),
        ::glm::vec3( 1.5f,  2.0f, -2.5f),
        ::glm::vec3( 1.5f,  0.2f, -1.5f),
        ::glm::vec3(-1.3f,  1.0f, -1.5f)
    }) {
        m_entities.emplace(
            ::engine::graphic::opengl::ecs::component::Drawable{},
            ::engine::graphic::opengl::ecs::component::Transformable{ ::std::move(position) },
            ::engine::graphic::opengl::ecs::component::Textures{
                "container.png", "containerBorders.png"
            }
        );
    }
}

::game::Scene::~Scene() = default;



// ------------------------------------------------------------------ Update

void ::game::Scene::onUpdate()
{}



// ------------------------------------------------------------------ Draw

void ::game::Scene::onDraw() const
{}
