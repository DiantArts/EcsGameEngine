#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Texture.hpp>
#include <Engine/Core/Config/Filepaths.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::Texture::Texture(
    const ::std::string& filename,
    bool gammaCorrection
)
{
    glGenTextures(1, &m_id);

    int width, height, nrComponents;

    ::std::string filepath;
    filepath.reserve(filename.size() + engine::core::config::filepath::textures.size());
    filepath += engine::core::config::filepath::textures;
    filepath += filename;
    const auto data { stbi_load(filepath.c_str(), &width, &height, &nrComponents, 0) };

    if (!data) {
        throw ::std::runtime_error("ERROR: Failed to load '"s + filepath + "' texture");
    }

    ::GLenum dataFormat;
    ::GLenum internalFormat;
    switch (nrComponents) {
    case 1: internalFormat = dataFormat = GL_RED; break;
    case 3: internalFormat = gammaCorrection ? GL_SRGB : GL_RGB; dataFormat = GL_RGB; break;
    case 4: internalFormat = gammaCorrection ? GL_SRGB_ALPHA : GL_RGBA; dataFormat = GL_RGBA; break;
    default:
        stbi_image_free(const_cast<unsigned char*>(data));
        throw ::std::runtime_error("unsupported texture format found");
    }

    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(const_cast<unsigned char*>(data));
}

::engine::graphic::opengl::Texture::~Texture()
{
    if (m_id) {
        glDeleteTextures(1, &m_id);
    }
}



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::Texture::Texture(
    Texture&& other
) noexcept
    : m_id{ other.m_id }
{
    other.m_id = 0;
}

auto ::engine::graphic::opengl::Texture::operator=(
    Texture&& other
) noexcept
    -> Texture&
{
    m_id = other.m_id;
    other.m_id = 0;
    return *this;
}



// ------------------------------------------------------------------ get

auto ::engine::graphic::opengl::Texture::get() const
    -> ::GLuint
{
    return m_id;
}



// ------------------------------------------------------------------ bind

void ::engine::graphic::opengl::Texture::bind(
    const ::std::size_t num
) const
{
    glActiveTexture(GL_TEXTURE0 + num);
    glBindTexture(GL_TEXTURE_2D, m_id);
}
