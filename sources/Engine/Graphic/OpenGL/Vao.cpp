#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Vao.hpp>



// ---------------------------------- *structors

::engine::graphic::opengl::Vao::Vao()
{
    glGenVertexArrays(1, &m_vao);
}

::engine::graphic::opengl::Vao::~Vao()
{
    glDeleteVertexArrays(1, &m_vao);
}



// ---------------------------------- get

GLuint ::engine::graphic::opengl::Vao::get() const
{
    return m_vao;
}



// ---------------------------------- bind

void ::engine::graphic::opengl::Vao::bind() const
{
    glBindVertexArray(m_vao);
}

void ::engine::graphic::opengl::Vao::unbind() const
{
    glBindVertexArray(0);
}
