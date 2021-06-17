#include <pch.hpp>
#include <Engine/Core/Textures.hpp>
#include <Engine/Graphic/OpenGL/Vertices.hpp>
#include <Engine/Graphic/OpenGL/Shader.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::Textures::Textures() = default;

::engine::core::Textures::Textures(
    ::std::initializer_list<::std::pair<::std::string, ::std::string>>&& textureinformations,
    ::engine::graphic::opengl::Shader& shader
)
{
    shader.use();
    for (int i{ 0 }; const auto& textureFilename : textureinformations) {
        m_textures.emplace_back(textureFilename.second);
        shader.set(textureFilename.first, i++);
    }
}

::engine::core::Textures::~Textures() = default;



// ------------------------------------------------------------------ Move sementic

::engine::core::Textures::Textures(
    Textures&&
) noexcept = default;

auto ::engine::core::Textures::operator=(
    Textures&&
) noexcept
    -> Textures& = default;



// ------------------------------------------------------------------ use

void ::engine::core::Textures::bind() const
{
    for (::std::size_t i{ 0 }; const auto& texture : m_textures) {
        texture.bind(i);
        ++i;
    }
}
