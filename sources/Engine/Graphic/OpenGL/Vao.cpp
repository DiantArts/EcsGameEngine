#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Vao.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::Vao::Vao()
{
    glGenVertexArrays(1, &m_vao);
}

::engine::graphic::opengl::Vao::~Vao()
{
    if (m_vao) {
        glDeleteVertexArrays(1, &m_vao);
    }
}



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::Vao::Vao(
    Vao&& other
) noexcept
    : m_vao{ other.m_vao }
{
    other.m_vao = 0;
}

auto ::engine::graphic::opengl::Vao::operator=(
    Vao&& other
) noexcept
    -> Vao&
{
    m_vao = other.m_vao;
    other.m_vao = 0;
    return *this;
}



// ------------------------------------------------------------------ get

GLuint ::engine::graphic::opengl::Vao::get() const
{
    return m_vao;
}



// ------------------------------------------------------------------ bind

void ::engine::graphic::opengl::Vao::bind() const
{
    glBindVertexArray(m_vao);
}

void ::engine::graphic::opengl::Vao::unbind() const
{
    glBindVertexArray(0);
}
