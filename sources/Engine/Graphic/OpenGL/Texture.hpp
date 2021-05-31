#pragma once

namespace engine::graphic::opengl {



class Texture {

public:

    // ------------------------------------------------------------------ *structors

    Texture(
        const ::std::string& filename,
        bool gammaCorrection = false
    );

    ~Texture();



    // ------------------------------------------------------------------ Copy sementic

    Texture(
        const Texture&
    ) noexcept = delete;

    auto operator=(
        const Texture&
    ) noexcept
        -> Texture& = delete;



    // ------------------------------------------------------------------ Move sementic

    Texture(
        Texture&&
    ) noexcept;

    auto operator=(
        Texture&&
    ) noexcept
        -> Texture&;



    // ------------------------------------------------------------------ get

    [[ nodiscard ]] auto get() const
        -> ::GLuint;



    // ------------------------------------------------------------------ bind

    void bind(
        ::std::size_t num
    ) const;



private:

    ::GLuint m_id;

};



} // namespace engine::graphic::opengl

