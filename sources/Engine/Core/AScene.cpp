#include <pch.hpp>
#include <Engine/Core/AScene.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::AScene::AScene(
    ::engine::core::AWindow& window
)
    : m_window{ window }
{
    m_components.get<::engine::core::ecs::component::Position>(m_controlledID).setZ(5);

    m_systems.emplace<[](
        ::engine::core::Time deltaTime,
        ::engine::core::ecs::component::Position& position,
        const ::engine::core::ecs::component::Controllable& controllable
    ){
        controllable.updatePosition(deltaTime, position);
    }>();

    m_drawSystems.emplace<[](
        const ::engine::graphic::opengl::ecs::component::Drawable& draw,
        const ::engine::core::ecs::component::Position& position
    ){
        draw(position);
    }>();

    for (auto& position : ::std::vector<::glm::vec3>{
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    }) {
        m_entities.emplace(
            ::engine::graphic::opengl::ecs::component::Drawable{},
            ::engine::core::ecs::component::Position{ position }
        );
    }
}

::engine::core::AScene::~AScene() = default;



// ------------------------------------------------------------------ Loop

auto ::engine::core::AScene::isOver() const
    -> bool
{
    return m_isOver || m_window.shouldClose();
}

void ::engine::core::AScene::ends()
{
    m_isOver = true;
}



// ------------------------------------------------------------------ Update

void ::engine::core::AScene::update()
{
    m_window.handleEvents(*this);
    this->onUpdate();
    m_systems.run(m_systemsClock.getRestart(), m_entities, m_components);
}

void ::engine::core::AScene::onUpdate()
{}



// ------------------------------------------------------------------ Draw

void ::engine::core::AScene::draw() const
{
    m_window.clear();
    m_components.get<::engine::graphic::opengl::ecs::component::Camera>(m_controlledID).configureUbo(
        m_components.get<::engine::core::ecs::component::Position>(m_controlledID),
        m_components.get<::engine::core::ecs::component::Controllable>(m_controlledID).getUp()
    );
    m_drawSystems.run(m_drawSystemsClock.getRestart(), m_entities, m_components);
    this->onDraw();
    m_window.draw();
}

void ::engine::core::AScene::onDraw() const
{}



// ------------------------------------------------------------------ MainControllable

auto ::engine::core::AScene::getMainEntityControllable() const
    -> const ::engine::core::ecs::component::Controllable&
{
    return m_components.get<::engine::core::ecs::component::Controllable>(m_controlledID);
}

auto ::engine::core::AScene::getMainEntityControllable()
    -> ::engine::core::ecs::component::Controllable&
{
    return m_components.get<::engine::core::ecs::component::Controllable>(m_controlledID);
}

auto ::engine::core::AScene::getMainEntityCamera() const
    -> const ::engine::graphic::opengl::ecs::component::Camera&
{
    return m_components.get<::engine::graphic::opengl::ecs::component::Camera>(m_controlledID);
}

auto ::engine::core::AScene::getMainEntityCamera()
    -> ::engine::graphic::opengl::ecs::component::Camera&
{
    return m_components.get<::engine::graphic::opengl::ecs::component::Camera>(m_controlledID);
}
