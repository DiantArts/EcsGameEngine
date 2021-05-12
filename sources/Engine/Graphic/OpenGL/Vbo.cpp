#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Vbo.hpp>



// ---------------------------------- *structors

::engine::graphic::opengl::Vbo::Vbo()
{
    glGenBuffers(1, &m_vbo);
}

::engine::graphic::opengl::Vbo::~Vbo()
{
    glDeleteBuffers(1, &m_vbo);
}



// ---------------------------------- get

GLuint ::engine::graphic::opengl::Vbo::get() const
{
    return m_vbo;
}



// ---------------------------------- bind

void ::engine::graphic::opengl::Vbo::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
}

void ::engine::graphic::opengl::Vbo::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
