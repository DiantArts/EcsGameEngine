#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Fbo.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::Fbo::Fbo()
{
    glGenFramebuffers(1, &m_fbo);
}

::engine::graphic::opengl::Fbo::~Fbo()
{
    if (m_fbo) {
        glDeleteFramebuffers(1, &m_fbo);
    }
}



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::Fbo::Fbo(
    Fbo&& other
) noexcept
    : m_fbo{ other.m_fbo }
{
    other.m_fbo = 0;
}

auto ::engine::graphic::opengl::Fbo::operator=(
    Fbo&& other
) noexcept
    -> Fbo&
{
    m_fbo = other.m_fbo;
    other.m_fbo = 0;
    return *this;
}



// ------------------------------------------------------------------ get

auto ::engine::graphic::opengl::Fbo::get() const
    -> ::GLuint
{
    return m_fbo;
}



// ------------------------------------------------------------------ bind

void ::engine::graphic::opengl::Fbo::bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
}

void ::engine::graphic::opengl::Fbo::unbind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
