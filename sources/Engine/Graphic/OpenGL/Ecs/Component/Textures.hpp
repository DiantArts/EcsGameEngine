#pragma once

#include <Engine/Graphic/OpenGL/Texture.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Drawable.hpp>



namespace engine::graphic::opengl::ecs::component {



class Textures
    : public ::engine::core::ecs::AComponent<engine::graphic::opengl::ecs::component::Textures>
{

public:

    // ------------------------------------------------------------------ *structors

    Textures(
        ::std::initializer_list<::std::string> textureFilenames
    );

    ~Textures();



    // ------------------------------------------------------------------ Copy sementic

    Textures(
        const Textures&
    ) noexcept = delete;

    auto operator=(
        const Textures&
    ) noexcept
        -> Textures& = delete;



    // ------------------------------------------------------------------ Move sementic

    Textures(
        Textures&&
    ) noexcept;

    auto operator=(
        Textures&&
    ) noexcept
        -> Textures&;



    // ------------------------------------------------------------------ Use

    void init(
        ::engine::graphic::opengl::ecs::component::Drawable& drawable
    );

    void bind() const;



private:

    ::std::vector<::engine::graphic::opengl::Texture> m_textures;

};



} // namespace engine::graphic::opengl::ecs::component
