#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Drawable.hpp>
#include <Engine/Graphic/OpenGL/Vertices.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::ecs::component::Drawable::Drawable()
{
    m_vao.bind();
    m_vbo.bind();
    ::engine::graphic::opengl::Vertices("cube", m_numberOfArrayToDraw).createBuffer();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

::engine::graphic::opengl::ecs::component::Drawable::~Drawable() = default;



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::ecs::component::Drawable::Drawable(
    Drawable&&
) noexcept = default;

auto ::engine::graphic::opengl::ecs::component::Drawable::operator=(
    Drawable&&
) noexcept
    -> Drawable& = default;



// ------------------------------------------------------------------ use

auto ::engine::graphic::opengl::ecs::component::Drawable::getShader()
    -> ::engine::graphic::opengl::Shader&
{
    return m_shader;
}

void ::engine::graphic::opengl::ecs::component::Drawable::operator()(
    const ::engine::graphic::opengl::ecs::component::Transformable& transformation
) const
{
    m_shader.use();
    m_vao.bind();
    m_shader.set("model", transformation.getModel());
    glDrawArrays(GL_TRIANGLES, 0, m_numberOfArrayToDraw);
}
