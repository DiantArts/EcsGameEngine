#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Textures.hpp>
#include <Engine/Graphic/OpenGL/Vertices.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::ecs::component::Textures::Textures(
    ::std::initializer_list<::std::string> textureFilenames
)
{
    for (const auto& textureFilename : textureFilenames) {
        m_textures.emplace_back(textureFilename);
    }
}

::engine::graphic::opengl::ecs::component::Textures::~Textures() = default;



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::ecs::component::Textures::Textures(
    Textures&&
) noexcept = default;

auto ::engine::graphic::opengl::ecs::component::Textures::operator=(
    Textures&&
) noexcept
    -> Textures& = default;



// ------------------------------------------------------------------ use

void ::engine::graphic::opengl::ecs::component::Textures::init(
        ::engine::graphic::opengl::ecs::component::Drawable& drawable
)
{
    drawable.getShader().use();

    ::std::string textureName{ "texture" };
    constexpr ::std::size_t textureNameSize{ 7 };

    for (int i{ 0 }; const auto& texture : m_textures) {
        textureName.replace(textureNameSize, ::std::string::npos, ::std::to_string(++i));
        drawable.getShader().set(textureName, i - 1);
    }
}

void ::engine::graphic::opengl::ecs::component::Textures::bind() const
{
    for (::std::size_t i{ 0 }; const auto& texture : m_textures) {
        texture.bind(i);
        ++i;
    }
}
