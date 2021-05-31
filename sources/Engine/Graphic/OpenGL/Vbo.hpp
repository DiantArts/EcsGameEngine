#pragma once

namespace engine::graphic::opengl {



class Vbo {

public:

    // ------------------------------------------------------------------ *structors

    Vbo();

    ~Vbo();



    // ------------------------------------------------------------------ Copy sementic

    Vbo(
        const Vbo&
    ) noexcept = delete;

    auto operator=(
        const Vbo&
    ) noexcept
        -> Vbo& = delete;



    // ------------------------------------------------------------------ Move sementic

    Vbo(
        Vbo&&
    ) noexcept;

    auto operator=(
        Vbo&&
    ) noexcept
        -> Vbo&;



    // ------------------------------------------------------------------ get

    GLuint get() const;



    // ------------------------------------------------------------------ bind

    void bind() const;

    void unbind() const;



private:

    GLuint m_vbo;

};



} // namespace engine::graphic::opengl
