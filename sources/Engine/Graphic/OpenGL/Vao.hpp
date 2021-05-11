#pragma once

namespace engine::graphic::opengl {



class Vao {

public:

    // ---------------------------------- *structors

    Vao();

    ~Vao();



    // ---------------------------------- Copy sementic

    Vao(
        const Vao&
    ) noexcept = delete;

    auto operator=(
        const Vao&
    ) noexcept
        -> Vao& = delete;



    // ---------------------------------- Move sementic

    Vao(
        Vao&&
    ) noexcept;

    auto operator=(
        Vao&&
    ) noexcept
        -> Vao&;



    // ---------------------------------- get

    GLuint get() const;



    // ---------------------------------- bind

    void bind() const;

    void unbind() const;



private:

    GLuint m_vao;

};



} // namespace engine::graphic::opengl
