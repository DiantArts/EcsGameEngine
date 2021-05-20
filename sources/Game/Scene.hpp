#pragma once

#include <Engine/Core/AScene.hpp>
#include <Engine/Graphic/OpenGL/Shader.hpp>
#include <Engine/Graphic/OpenGL/Vao.hpp>
#include <Engine/Graphic/OpenGL/Vbo.hpp>
#include <Engine/Graphic/OpenGL/Texture.hpp>



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

    ::std::size_t m_numberOfArrayToDraw;

    ::engine::graphic::opengl::Texture m_texture1{ "container.png" };
    ::engine::graphic::opengl::Texture m_texture2{ "containerBorders.png" };

    ::engine::graphic::opengl::Vao m_vao;
    ::engine::graphic::opengl::Vbo m_vbo;
    ::engine::graphic::opengl::Shader m_shader{ "cube" };

    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
    float yaw   = -90.0f;
    float pitch =  0.0f;
    float lastX =  800.0f / 2.0;
    float lastY =  600.0 / 2.0;
    float fov   =  45.0f;

};



} // namespace engine

