#pragma once

namespace engine::graphic::opengl {



class Fbo {

public:

    // ---------------------------------- *structors

    Fbo();

    ~Fbo();



    // ---------------------------------- Copy sementic

    Fbo(
        const Fbo&
    ) noexcept = delete;

    auto operator=(
        const Fbo&
    ) noexcept
        -> Fbo& = delete;



    // ---------------------------------- Move sementic

    Fbo(
        Fbo&&
    ) noexcept;

    auto operator=(
        Fbo&&
    ) noexcept
        -> Fbo&;



    // ---------------------------------- get

    GLuint get() const;



    // ---------------------------------- bind

    void bind() const;

    void unbind() const;



public:
protected:
protected:
private:
private:

    GLuint m_fbo;

};



} // namespace engine::graphic::opengl
