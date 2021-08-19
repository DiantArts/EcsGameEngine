#pragma once

#include <Engine/Core/Ecs/Entity/Container.hpp>
#include <Engine/Core/Ecs/Component/Container.hpp>
#include <Engine/Core/Ecs/System/Container.hpp>
#include <Engine/Core/Ecs/Component/Controllable.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Drawable.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Transformable.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Camera.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Light/Directional.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Light/Point.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Light/Spot.hpp>
#include <Engine/Core/AWindow.hpp>

namespace engine::core::event { class KeyPressed; }
namespace engine::core::event { class KeyReleased; }
namespace engine::core::event { class MouseMoved; }



namespace engine::core {



class AScene {

public:

    // ------------------------------------------------------------------ *structors

    explicit AScene(
        ::engine::core::AWindow& window,
        ::engine::graphic::opengl::ecs::component::Drawable mainCharacter
    );

    virtual ~AScene() = 0;



    // ------------------------------------------------------------------ Loop

    auto isOver() const
        -> bool;

    void ends();



    // ------------------------------------------------------------------ Update

    void update();



    // ------------------------------------------------------------------ Draw

    void draw() const;



    // ------------------------------------------------------------------ MainControllable

    auto getMainEntityControllable() const
        -> const ::engine::core::ecs::component::Controllable&;

    auto getMainEntityControllable()
        -> ::engine::core::ecs::component::Controllable&;

    auto getCamera() const
        -> const ::engine::graphic::opengl::ecs::component::Camera&;

    auto getCamera()
        -> ::engine::graphic::opengl::ecs::component::Camera&;



protected:

    // ------------------------------------------------------------------ Update

    virtual void onUpdate();



    // ------------------------------------------------------------------ Draw

    virtual void onDraw() const;



protected:

    ::engine::core::ecs::component::Container m_components;
    ::engine::core::ecs::entity::Container m_entities{ m_components };
    ::engine::core::ecs::system::Container m_drawSystems;
    ::engine::core::ecs::system::Container m_updateSystems;


    // ::engine::core::ID m_lightID{
        // m_entities.emplace(
            // ::engine::graphic::opengl::ecs::component::Drawable{ "cube", "light" },
            // ::engine::graphic::opengl::ecs::component::Transformable{ 0.0F, 1.0F, 0.0F },
            // ::engine::graphic::opengl::ecs::component::light::Point{}
        // ).getID()
    // };



private:

    // ------------------------------------------------------------------ Systems

    void runInitSystems();

    void emplaceDrawSystems();

    void emplaceUpdateSystems();


    // ------------------------------------------------------------------ Detail

    void configureUbo() const;



private:

    ::engine::core::AWindow& m_window;

    bool m_isOver { false };

    ::engine::core::Clock m_systemsClock;
    mutable ::engine::core::Clock m_drawSystemsClock;

    ::engine::graphic::opengl::Ubo m_lightsUbo;
    static constexpr int m_lightsUboIndex{ 3 };

    ::engine::core::ecs::system::Container m_uboSystems;



protected:

    ::engine::core::ID m_controlledID;

};



} // namespace engine::core
