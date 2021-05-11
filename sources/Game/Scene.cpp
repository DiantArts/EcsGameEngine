#include <pch.hpp>
#include <Game/Scene.hpp>



// ------------------------------------------------------------------ *structors

::game::Scene::Scene(
    ::engine::core::AWindow& window
)
    : ::engine::core::AScene{ window }
{}

::game::Scene::~Scene() = default;



// ------------------------------------------------------------------ Update

void ::game::Scene::onUpdate()
{}



// ------------------------------------------------------------------ Draw

void ::game::Scene::onDraw() const
{}
