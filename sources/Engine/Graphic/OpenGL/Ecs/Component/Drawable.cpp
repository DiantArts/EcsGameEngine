#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Drawable.hpp>
#include <Engine/Graphic/OpenGL/Vertices.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::ecs::component::Drawable::Drawable(
    const ::std::string& verticeFilename,
    const ::std::string& shaderFilename

)
    : m_shader{ shaderFilename }
{
    m_vao.bind();
    m_vbo.bind();
    ::engine::graphic::opengl::Vertices(verticeFilename, m_numberOfArrayToDraw).createBuffer();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    m_shader.use();

}

::engine::graphic::opengl::ecs::component::Drawable::Drawable(
    ::std::initializer_list<::std::pair<::std::string, ::std::string>>&& textureinformations,
    const ::std::string& verticeFilename,
    const ::std::string& shaderFilename

)
    : m_shader{ shaderFilename }
    , m_textures{ ::std::move(textureinformations), m_shader }
{
    m_vao.bind();
    m_vbo.bind();
    ::engine::graphic::opengl::Vertices(verticeFilename, m_numberOfArrayToDraw).createBuffer();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    m_shader.use();
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

auto ::engine::graphic::opengl::ecs::component::Drawable::getShader() const
    -> ::engine::graphic::opengl::Shader&
{
    return m_shader;
}

void ::engine::graphic::opengl::ecs::component::Drawable::operator()(
    const ::engine::graphic::opengl::ecs::component::Transformable& transformation
) const
{
    m_textures.bind();
    m_shader.use();
    m_vao.bind();
    m_shader.set("model", transformation.getModel());
    glDrawArrays(GL_TRIANGLES, 0, m_numberOfArrayToDraw);
}
