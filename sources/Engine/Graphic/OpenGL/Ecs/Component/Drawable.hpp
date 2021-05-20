#pragma once

#include <Engine/Graphic/OpenGL/Shader.hpp>



namespace engine::graphic::opengl::ecs::component {



class Drawable
    : public ::engine::core::ecs::AComponent<engine::graphic::opengl::ecs::component::Drawable>
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Drawable(
        const std::string& shaderFilepath,
        const std::string& filename,
        bool gamma = false
    );

    ~Drawable();



    // ------------------------------------------------------------------ Use

    void operator()();



private:

    ::engine::graphic::opengl::Shader m_shader;

    ::engine::graphic::opengl::Vao m_vao;
    ::engine::graphic::opengl::Vbo m_vbo;
    ::engine::graphic::opengl::Ebo m_ebo;

    std::vector<GLuint> m_indices;
    std::vector<Drawable::Vertex> m_vertices;
    std::vector<Drawable::Texture> m_textures;


};



} // namespace engine::graphic::opengl::ecs::component
