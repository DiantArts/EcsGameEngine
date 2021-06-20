#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Graphic/OpenGL/Shader.hpp>
#include <Engine/Graphic/OpenGL/Vao.hpp>
#include <Engine/Graphic/OpenGL/Vbo.hpp>
#include <Engine/Graphic/OpenGL/Texture.hpp>
#include <Engine/Core/Ecs/Component/Position.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Transformable.hpp>



namespace engine::graphic::opengl::ecs::component {



class Drawable
    : public ::engine::core::ecs::AComponent<engine::graphic::opengl::ecs::component::Drawable>
{

public:

    // ------------------------------------------------------------------ *structors

    Drawable();

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

    [[ nodiscard ]] auto getShader()
        -> ::engine::graphic::opengl::Shader&;

    void operator()(
        const ::engine::graphic::opengl::ecs::component::Transformable& transformation
    ) const;



private:

    ::engine::graphic::opengl::Vao m_vao;
    ::engine::graphic::opengl::Vbo m_vbo;
    ::engine::graphic::opengl::Shader m_shader{ "cube" };

    ::std::size_t m_numberOfArrayToDraw;

};



} // namespace engine::graphic::opengl::ecs::component
