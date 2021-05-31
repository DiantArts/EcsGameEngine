#pragma once

namespace engine::graphic::opengl {



class Ebo {

public:

    // ------------------------------------------------------------------ *structors

    explicit Ebo();

    ~Ebo();



    // ------------------------------------------------------------------ Copy sementic

    Ebo(
        const Ebo&
    ) noexcept = delete;

    auto operator=(
        const Ebo&
    ) noexcept
        -> Ebo& = delete;



    // ------------------------------------------------------------------ Move sementic

    Ebo(
        Ebo&&
    ) noexcept;

    auto operator=(
        Ebo&&
    ) noexcept
        -> Ebo&;



    // ------------------------------------------------------------------ get

    [[ nodiscard ]] auto get() const
        -> ::GLuint;



    // ------------------------------------------------------------------ bind

    void bind() const;

    void unbind() const;



private:

    ::GLuint m_ebo;

};



} // namespace engine::graphic::opengl
