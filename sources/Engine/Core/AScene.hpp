#pragma once

#include <Engine/Core/Ecs/Entity/Container.hpp>
#include <Engine/Core/Ecs/Component/Container.hpp>
#include <Engine/Core/Ecs/System/Container.hpp>
#include <Engine/Core/AWindow.hpp>



namespace engine::core {



class AScene {

public:

    // ------------------------------------------------------------------ *structors

    AScene();

    virtual ~AScene() = 0;



    // ------------------------------------------------------------------ Loop

    auto isOver() const
        -> bool;



    // ------------------------------------------------------------------ Update

    void update();

    virtual void onUpdate();



    // ------------------------------------------------------------------ Draw

    void draw() const;

    virtual void onDraw() const;



protected:

    // ::engine::core::ecs::component::Container m_components;
    // ::engine::core::ecs::entity::Container m_actors { m_components };
    // ::engine::core::ecs::system::Container m_systems;



private:

    bool m_isOver { false };

};



} // namespace engine::core
