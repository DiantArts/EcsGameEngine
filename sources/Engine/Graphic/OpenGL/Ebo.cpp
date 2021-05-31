#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ebo.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::Ebo::Ebo()
{
    glGenBuffers(1, &m_ebo);
}

::engine::graphic::opengl::Ebo::~Ebo()
{
    if (m_ebo) {
        glDeleteBuffers(1, &m_ebo);
    }
}



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::Ebo::Ebo(
    Ebo&& other
) noexcept
    : m_ebo{ other.m_ebo }
{
    other.m_ebo = 0;
}

auto ::engine::graphic::opengl::Ebo::operator=(
    Ebo&& other
) noexcept
    -> Ebo&
{
    m_ebo = other.m_ebo;
    other.m_ebo = 0;
    return *this;
}



// ------------------------------------------------------------------ get

GLuint ::engine::graphic::opengl::Ebo::get() const
{
    return m_ebo;
}



// ------------------------------------------------------------------ bind

void ::engine::graphic::opengl::Ebo::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
}

void ::engine::graphic::opengl::Ebo::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
