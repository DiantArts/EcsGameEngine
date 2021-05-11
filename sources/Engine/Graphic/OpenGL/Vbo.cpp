//
// Akanya, Engine
// sources/Engine/Graphic/OpenGL/Vbo
// Vertex Buffer Object : stores a large number of vertices
//

#include "pch.hpp"

#include "Vbo.hpp"



namespace engine::graphic::opengl {



// ---------------------------------- *structors

Vbo::Vbo()
{
    glGenBuffers(1, &m_vbo);
}

Vbo::~Vbo()
{
    glDeleteBuffers(1, &m_vbo);
}



// ---------------------------------- get

GLuint Vbo::get() const
{
    return m_vbo;
}



// ---------------------------------- bind

void Vbo::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
}

void Vbo::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}



} // namespace engine::graphic::opengl
