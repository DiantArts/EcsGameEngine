#pragma once

#include <Engine/Core/AScene.hpp>



namespace game {



class Scene : public ::engine::core::AScene {

public:

    // ------------------------------------------------------------------ *structors

    Scene(
        ::engine::core::AWindow& window
    );

    ~Scene();



    // ------------------------------------------------------------------ Update

    void onUpdate() override final;



    // ------------------------------------------------------------------ Draw

    void onDraw() const override final;



private:

    // ::engine::graphic::opengl::Vao m_vao;
    // ::engine::graphic::opengl::Vbo m_vbo;
    // ::engine::graphic::opengl::Shader m_shader{ "cube" };

    // ::std::size_t m_numberOfArrayToDraw;

    // ::engine::graphic::opengl::Texture m_texture1{ "container.png" };
    // ::engine::graphic::opengl::Texture m_texture2{ "containerBorders.png" };

};



} // namespace engine

