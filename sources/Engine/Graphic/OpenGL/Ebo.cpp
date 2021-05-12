#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ebo.hpp>



// ---------------------------------- *structors

::engine::graphic::opengl::Ebo::Ebo()
{
    glGenBuffers(1, &m_ebo);
}

::engine::graphic::opengl::Ebo::~Ebo()
{
    glDeleteBuffers(1, &m_ebo);
}



// ---------------------------------- get

GLuint ::engine::graphic::opengl::Ebo::get() const
{
    return m_ebo;
}



// ---------------------------------- bind

void ::engine::graphic::opengl::Ebo::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
}

void ::engine::graphic::opengl::Ebo::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
