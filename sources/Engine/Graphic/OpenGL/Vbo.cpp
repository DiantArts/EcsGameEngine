#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Vbo.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::Vbo::Vbo()
{
    glGenBuffers(1, &m_vbo);
}

::engine::graphic::opengl::Vbo::~Vbo()
{
    if (m_vbo) {
        glDeleteBuffers(1, &m_vbo);
    }
}



// ------------------------------------------------------------------ Copy sementic

::engine::graphic::opengl::Vbo::Vbo(
    Vbo&& other
) noexcept
    : m_vbo{ other.m_vbo }
{
    other.m_vbo = 0;
}

auto ::engine::graphic::opengl::Vbo::operator=(
    Vbo&& other
) noexcept
    -> Vbo&
{
    m_vbo = other.m_vbo;
    other.m_vbo = 0;
    return *this;
}



// ------------------------------------------------------------------ get

GLuint ::engine::graphic::opengl::Vbo::get() const
{
    return m_vbo;
}



// ------------------------------------------------------------------ bind

void ::engine::graphic::opengl::Vbo::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
}

void ::engine::graphic::opengl::Vbo::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
