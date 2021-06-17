#pragma once

#include <Engine/Graphic/OpenGL/Ecs/Component/Drawable.hpp>



namespace engine::shape {



class Cube
    : public engine::graphic::opengl::ecs::component::Drawable
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Cube(
        const ::std::string& shaderFilename = "cube",
        const ::std::string& verticesFilename = "cube"
    );

    explicit Cube(
        ::std::initializer_list<::std::pair<::std::string, ::std::string>>&& textureinformations,
        const ::std::string& shaderFilename = "cube",
        const ::std::string& verticesFilename = "cube"
    );

    ~Cube();



    // ------------------------------------------------------------------ Copy sementic

    Cube(
        const Cube&
    ) noexcept = delete;

    auto operator=(
        const Cube&
    ) noexcept
        -> Cube& = delete;



    // ------------------------------------------------------------------ Move sementic

    Cube(
        Cube&&
    ) noexcept;

    auto operator=(
        Cube&&
    ) noexcept
        -> Cube&;

};



} // namespace engine::shape
