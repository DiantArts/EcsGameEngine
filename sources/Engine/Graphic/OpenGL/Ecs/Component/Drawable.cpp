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

    m_shader.use();
    m_shader.set("texture1", 0);
    m_shader.set("texture2", 1);
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

void ::engine::graphic::opengl::ecs::component::Drawable::operator()(
    const ::glm::vec3& position
) const
{
    m_texture1.bind(0);
    m_texture2.bind(1);

    m_shader.use();
    m_vao.bind();
    m_shader.set("model", glm::translate(glm::mat4(1.0f), position));
    glDrawArrays(GL_TRIANGLES, 0, m_numberOfArrayToDraw);
}
