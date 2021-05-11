//
// Akanya, Engine
// sources/Engine/Graphic/OpenGL/Vao
// Vertex Array Object : Contains vertex attributes pointers to get a simple use of VBOs
//

#include "pch.hpp"

#include "Vao.hpp"



namespace engine::graphic::opengl {



// ---------------------------------- *structors

Vao::Vao()
{
    glGenVertexArrays(1, &m_vao);
}

Vao::~Vao()
{
    glDeleteVertexArrays(1, &m_vao);
}



// ---------------------------------- get

GLuint Vao::get() const
{
    return m_vao;
}



// ---------------------------------- bind

void Vao::bind() const
{
    glBindVertexArray(m_vao);
}

void Vao::unbind() const
{
    glBindVertexArray(0);
}



} // namespace engine::graphic::opengl
