#include <pch.hpp>
#include <Engine/Core/AScene.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::AScene::AScene() = default;

::engine::core::AScene::~AScene() = default;



// ------------------------------------------------------------------ Loop

auto ::engine::core::AScene::isOver() const
    -> bool
{
    return m_isOver;
}



// ------------------------------------------------------------------ Update

void ::engine::core::AScene::update()
{
    this->onUpdate();
    // m_systems.run();
}

void ::engine::core::AScene::onUpdate()
{}



// ------------------------------------------------------------------ Draw

void ::engine::core::AScene::draw() const
{
    this->onDraw();
}

void ::engine::core::AScene::onDraw() const
{}
