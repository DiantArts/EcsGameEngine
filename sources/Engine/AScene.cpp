#include <pch.hpp>
#include <Engine/AScene.hpp>



// ------------------------------------------------------------------ *structors

::engine::AScene::AScene() = default;

::engine::AScene::~AScene() = default;



// ------------------------------------------------------------------ Loop

auto ::engine::AScene::isOver() const
    -> bool
{
    return m_isOver;
}



// ------------------------------------------------------------------ Update

void ::engine::AScene::update()
{
    this->onUpdate();
    // m_systems.run();
}

void ::engine::AScene::onUpdate()
{}



// ------------------------------------------------------------------ Draw

void ::engine::AScene::draw() const
{
    this->onDraw();
}

void ::engine::AScene::onDraw() const
{}
