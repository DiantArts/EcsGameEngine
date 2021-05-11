//
// Akanya, Engine
// sources/Engine/Graphic/OpenGL/Fbo
// FrameBuffer Object
//

#include "pch.hpp"

#include "Fbo.hpp"



namespace engine::graphic::opengl {



// ---------------------------------- *structors

Fbo::Fbo()
{
    glGenFramebuffers(1, &m_fbo);
}

Fbo::~Fbo()
{
    glDeleteFramebuffers(1, &m_fbo);
}



// ---------------------------------- get

GLuint Fbo::get() const
{
    return m_fbo;
}



// ---------------------------------- bind

void Fbo::bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
}

void Fbo::unbind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}



} // namespace engine::graphic::opengl
