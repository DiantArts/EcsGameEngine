#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Fbo.hpp>



// ---------------------------------- *structors

::engine::graphic::opengl::Fbo::Fbo()
{
    glGenFramebuffers(1, &m_fbo);
}

::engine::graphic::opengl::Fbo::~Fbo()
{
    glDeleteFramebuffers(1, &m_fbo);
}



// ---------------------------------- get

GLuint ::engine::graphic::opengl::Fbo::get() const
{
    return m_fbo;
}



// ---------------------------------- bind

void ::engine::graphic::opengl::Fbo::bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
}

void ::engine::graphic::opengl::Fbo::unbind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
