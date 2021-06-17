#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Core/Textures.hpp>
#include <Engine/Graphic/OpenGL/Shader.hpp>
#include <Engine/Graphic/OpenGL/Vao.hpp>
#include <Engine/Graphic/OpenGL/Vbo.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Transformable.hpp>



namespace engine::graphic::opengl::ecs::component {



class Drawable
    : public ::engine::core::ecs::AComponent<engine::graphic::opengl::ecs::component::Drawable>
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Drawable(
        const ::std::string& verticesFilename,
        const ::std::string& shaderFilename
    );

    explicit Drawable(
        ::std::initializer_list<::std::pair<::std::string, ::std::string>>&& textureinformations,
        const ::std::string& verticesFilename,
        const ::std::string& shaderFilename
    );

    ~Drawable();



    // ------------------------------------------------------------------ Copy sementic

    Drawable(
        const Drawable&
    ) noexcept = delete;

    auto operator=(
        const Drawable&
    ) noexcept
        -> Drawable& = delete;



    // ------------------------------------------------------------------ Move sementic

    Drawable(
        Drawable&&
    ) noexcept;

    auto operator=(
        Drawable&&
    ) noexcept
        -> Drawable&;



    // ------------------------------------------------------------------ Use

    [[ nodiscard ]] auto getShader() const
        -> ::engine::graphic::opengl::Shader&;

    void operator()(
        const ::engine::graphic::opengl::ecs::component::Transformable& transformation
    ) const;



protected:

    mutable ::engine::graphic::opengl::Shader m_shader;



private:

    ::engine::graphic::opengl::Vao m_vao;
    ::engine::graphic::opengl::Vbo m_vbo;

    ::std::size_t m_numberOfArrayToDraw;

    ::engine::core::Textures m_textures;

};



} // namespace engine::graphic::opengl::ecs::component
