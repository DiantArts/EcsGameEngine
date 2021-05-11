//
// Akanya, Engine
// sources/Engine/Graphic/OpenGL/Ebo
// Element Buffer Object : help to determine which vertex to draw
//

#include "pch.hpp"

#include "Ebo.hpp"



namespace engine::graphic::opengl {



// ---------------------------------- *structors

Ebo::Ebo()
{
    glGenBuffers(1, &m_ebo);
}

Ebo::~Ebo()
{
    glDeleteBuffers(1, &m_ebo);
}



// ---------------------------------- get

GLuint Ebo::get() const
{
    return m_ebo;
}



// ---------------------------------- bind

void Ebo::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
}

void Ebo::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}



} // namespace engine::graphic::opengl
