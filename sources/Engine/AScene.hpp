#pragma once

#include <Engine/Ecs/Entity/Container.hpp>
#include <Engine/Ecs/Component/Container.hpp>
#include <Engine/Ecs/System/Container.hpp>

namespace engine {



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

    ::engine::ecs::component::Container m_components;
    // ::engine::ecs::entity::Container m_actors { m_components };
    // ::engine::ecs::system::Container m_systems;



private:

    bool m_isOver { false };

};



} // namespace engine::engine
