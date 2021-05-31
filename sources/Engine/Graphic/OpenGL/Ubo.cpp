#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ubo.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::Ubo::Ubo(
    size_t size,
    int index
)
{
    glGenBuffers(1, &m_ubo);

    this->bind();
    glBufferData(GL_UNIFORM_BUFFER, size, nullptr, GL_STREAM_DRAW);
    glBindBufferRange(GL_UNIFORM_BUFFER, index, m_ubo, 0, size);
    this->unbind();
}

::engine::graphic::opengl::Ubo::~Ubo()
{
    if (m_ubo) {
        glDeleteBuffers(1, &m_ubo);
    }
}



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::Ubo::Ubo(
    Ubo&& other
) noexcept
    : m_ubo{ other.m_ubo }
{
    other.m_ubo = 0;
}

auto ::engine::graphic::opengl::Ubo::operator=(
    Ubo&& other
) noexcept
    -> Ubo&
{
    m_ubo = other.m_ubo;
    other.m_ubo = 0;
    return *this;
}



// ------------------------------------------------------------------ get

GLuint ::engine::graphic::opengl::Ubo::get() const
{
    return m_ubo;
}



// ------------------------------------------------------------------ bind

void ::engine::graphic::opengl::Ubo::bind() const
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
}

void ::engine::graphic::opengl::Ubo::unbind() const
{
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
