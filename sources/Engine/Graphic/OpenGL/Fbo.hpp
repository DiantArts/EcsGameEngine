#pragma once

namespace engine::graphic::opengl {



class Fbo {

public:

    // ------------------------------------------------------------------ *structors

    explicit Fbo();

    ~Fbo();



    // ------------------------------------------------------------------ Copy sementic

    Fbo(
        const Fbo&
    ) noexcept = delete;

    auto operator=(
        const Fbo&
    ) noexcept
        -> Fbo& = delete;



    // ------------------------------------------------------------------ Move sementic

    Fbo(
        Fbo&&
    ) noexcept;

    auto operator=(
        Fbo&&
    ) noexcept
        -> Fbo&;



    // ------------------------------------------------------------------ get

    [[ nodiscard ]] auto get() const
        -> ::GLuint;



    // ------------------------------------------------------------------ bind

    void bind() const;

    void unbind() const;



private:

    ::GLuint m_fbo;

};



} // namespace engine::graphic::opengl
