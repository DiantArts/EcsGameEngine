#pragma once

#include <Engine/Graphic/OpenGL/Texture.hpp>

namespace engine::graphic::opengl { class Shader; }



namespace engine::core {



class Textures
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Textures();

    // texture: name in shader, filename
    explicit Textures(
        ::std::initializer_list<::std::pair<::std::string, ::std::string>>&& textureinformations,
        ::engine::graphic::opengl::Shader& shader
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

    void bind() const;



private:

    ::std::vector<::engine::graphic::opengl::Texture> m_textures;

};



} // namespace engine::core
