#pragma once

namespace engine::graphic::opengl {



class Ubo {

public:

    // ------------------------------------------------------------------ *structors

    explicit Ubo(
        size_t size,
        int index
    );

    ~Ubo();



    // ------------------------------------------------------------------ Copy sementic

    Ubo(
        const Ubo&
    ) noexcept = delete;

    auto operator=(
        const Ubo&
    ) noexcept
        -> Ubo& = delete;



    // ------------------------------------------------------------------ Move sementic

    Ubo(
        Ubo&&
    ) noexcept;

    auto operator=(
        Ubo&&
    ) noexcept
        -> Ubo&;



    // ------------------------------------------------------------------ get

    [[ nodiscard ]] auto get() const
        -> ::GLuint;



    // ------------------------------------------------------------------ bind

    void bind() const;

    void unbind() const;



    // ------------------------------------------------------------------ SubData

    template <
        typename DataType
    > void setOneSubData(
        ::std::size_t offset,
        const DataType& data
    ) const;

    template <
        typename DataType
    > static void setSubData(
        ::std::size_t offset,
        const DataType& data
    );



private:

    ::GLuint m_ubo;

};



} // namespace engine::graphic::opengl

#include <Engine/Graphic/OpenGL/Ubo.impl.hpp>
