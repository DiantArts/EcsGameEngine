#include <pch.hpp>
#include <Engine/Core/AScene.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::AScene::AScene(
    ::engine::core::AWindow& window
)
    : m_window{ window }
{
    // m_systems.emplace<[](
        // ::engine::core::ecs::component::Movable& m,
        // const ::engine::core::ecs::component::Controllable& c
    // ){
        // c.updatePosition(m);
    // }>();
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
    m_systems.run(m_entities, m_components);
}

void ::engine::core::AScene::onUpdate()
{}



// ------------------------------------------------------------------ Draw

void ::engine::core::AScene::draw() const
{
    m_window.clear();
    m_drawSystems.run(m_entities, m_components);
    this->onDraw();
    m_window.draw();
}

void ::engine::core::AScene::onDraw() const
{}
