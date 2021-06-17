#include <pch.hpp>
#include <Engine/Shape/Cube.hpp>



// ------------------------------------------------------------------ *structors

::engine::shape::Cube::Cube(
    const ::std::string& shaderFilename,
    const ::std::string& verticesFilename
)
    : ::engine::graphic::opengl::ecs::component::Drawable{ verticesFilename, shaderFilename }
{}

::engine::shape::Cube::Cube(
    ::std::initializer_list<::std::pair<::std::string, ::std::string>>&& textureinformations,
    const ::std::string& shaderFilename,
    const ::std::string& verticesFilename
)
    : ::engine::graphic::opengl::ecs::component::Drawable{
        ::std::move(textureinformations),
        verticesFilename,
        shaderFilename
    }
{}

::engine::shape::Cube::~Cube() = default;



// ------------------------------------------------------------------ Move sementic

::engine::shape::Cube::Cube(
    Cube&&
) noexcept = default;

auto ::engine::shape::Cube::operator=(
    Cube&&
) noexcept
    -> Cube& = default;
