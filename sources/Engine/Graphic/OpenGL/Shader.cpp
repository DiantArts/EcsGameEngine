#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Shader.hpp>
#include <Engine/Graphic/OpenGL/Detail/Shader.hpp>
#include <Engine/Core/Config/Filepaths.hpp>



// ------------------------------------------------------------------ *structors


::engine::graphic::opengl::Shader::Shader(
    const ::std::string_view filepaths
)
    : m_id(glCreateProgram())
{
    ::std::string vertexFilepath;
    vertexFilepath.reserve(::engine::core::config::filepath::shader::vertexes.size() + filepaths.size() + 5);
    vertexFilepath += ::engine::core::config::filepath::shader::vertexes;
    vertexFilepath += filepaths;
    vertexFilepath += ".glsl";

    ::std::string fragmentFilepath;
    fragmentFilepath.reserve(::engine::core::config::filepath::shader::fragments.size() + filepaths.size() + 5);
    fragmentFilepath += ::engine::core::config::filepath::shader::fragments;
    fragmentFilepath += filepaths;
    fragmentFilepath += ".glsl";

    ::std::string geometryFilepath;
    geometryFilepath.reserve(::engine::core::config::filepath::shader::geometries.size() + filepaths.size() + 5);
    geometryFilepath += ::engine::core::config::filepath::shader::geometries;
    geometryFilepath += filepaths;
    geometryFilepath += ".glsl";


    if (tool::file::exists(geometryFilepath)) {
        ::engine::graphic::opengl::detail::createShader(m_id, ::std::move(vertexFilepath), ::std::move(fragmentFilepath), ::std::move(geometryFilepath));
    } else {
        ::engine::graphic::opengl::detail::createShader(m_id, ::std::move(vertexFilepath), ::std::move(fragmentFilepath));
    }
}

::engine::graphic::opengl::Shader::Shader(
    const ::std::string_view vertexFilename,
    const ::std::string_view fragmentFilename
)
    : m_id(glCreateProgram())
{
    ::std::string vertexFilepath;
    vertexFilepath.reserve(::engine::core::config::filepath::shader::vertexes.size() + vertexFilename.size() + 5);
    vertexFilepath += ::engine::core::config::filepath::shader::vertexes;
    vertexFilepath += vertexFilename;
    vertexFilepath += ".glsl";

    ::std::string fragmentFilepath;
    fragmentFilepath.reserve(::engine::core::config::filepath::shader::fragments.size() + fragmentFilename.size() + 5);
    fragmentFilepath += ::engine::core::config::filepath::shader::fragments;
    fragmentFilepath += fragmentFilename;
    fragmentFilepath += ".glsl";

    ::engine::graphic::opengl::detail::createShader(m_id, ::std::move(vertexFilepath), ::std::move(fragmentFilepath));
}


::engine::graphic::opengl::Shader::Shader(
    const ::std::string_view vertexFilename,
   const ::std::string_view fragmentFilename,
   const ::std::string_view geometryFilename
)
    : m_id(glCreateProgram())
{
    ::std::string vertexFilepath;
    vertexFilepath.reserve(::engine::core::config::filepath::shader::vertexes.size() + vertexFilename.size() + 5);
    vertexFilepath += ::engine::core::config::filepath::shader::vertexes;
    vertexFilepath += vertexFilename;
    vertexFilepath += ".glsl";

    ::std::string fragmentFilepath;
    fragmentFilepath.reserve(::engine::core::config::filepath::shader::fragments.size() + fragmentFilename.size() + 5);
    fragmentFilepath += ::engine::core::config::filepath::shader::fragments;
    fragmentFilepath += fragmentFilename;
    fragmentFilepath += ".glsl";

    ::std::string geometryFilepath;
    geometryFilepath.reserve(::engine::core::config::filepath::shader::geometries.size() + geometryFilename.size() + 5);
    geometryFilepath += ::engine::core::config::filepath::shader::geometries;
    geometryFilepath += geometryFilename;
    geometryFilepath += ".glsl";

    ::engine::graphic::opengl::detail::createShader(m_id, ::std::move(vertexFilepath), ::std::move(fragmentFilepath), ::std::move(geometryFilepath));
}

::engine::graphic::opengl::Shader::~Shader()
{
    if (m_id) {
        glDeleteProgram(m_id);
    }
}



// -------------------------------------------------------------------------------- Move sementic

::engine::graphic::opengl::Shader::Shader(
    Shader&& other
) noexcept
    : m_id{ other.m_id }
{
    other.m_id = 0;
}

auto ::engine::graphic::opengl::Shader::operator=(
    Shader&& other
) noexcept
    -> Shader&
{
    m_id = other.m_id;
    other.m_id = 0;
    return *this;
}




// ------------------------------------------------------------------ Use

void ::engine::graphic::opengl::Shader::use() const
{
    glUseProgram(m_id);
}



// ------------------------------------------------------------------ Set

void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const bool value
) const
{
    glUniform1i(this->getOrCacheUniformLocation(name), static_cast<int>(value));
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const bool value
) const
{
    glUniform1i(this->getOrCacheUniformLocation(std::move(name)), static_cast<int>(value));
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const int value
) const
{
    glUniform1i(this->getOrCacheUniformLocation(name), value);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const int value
) const
{
    glUniform1i(this->getOrCacheUniformLocation(std::move(name)), value);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const size_t value
) const
{
    glUniform1ui(this->getOrCacheUniformLocation(name), value);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const size_t value
) const
{
    glUniform1ui(this->getOrCacheUniformLocation(std::move(name)), value);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const float value
) const
{
    glUniform1f(this->getOrCacheUniformLocation(name), value);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const float value
) const
{
    glUniform1f(this->getOrCacheUniformLocation(std::move(name)), value);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const glm::vec2& value
) const
{
    glUniform2f(this->getOrCacheUniformLocation(name), value.x, value.y);
}

void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    glm::vec2&& value
) const
{
    glUniform2f(this->getOrCacheUniformLocation(name), value.x, value.y);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const glm::vec2& value
) const
{
    glUniform2f(getOrCacheUniformLocation(std::move(name)), value.x, value.y);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    glm::vec2&& value
) const
{
    glUniform2f(getOrCacheUniformLocation(std::move(name)), value.x, value.y);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const float x,
    const float y
) const
{
    glUniform2f(this->getOrCacheUniformLocation(name), x, y);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const float x,
    const float y
) const
{
    glUniform2f(this->getOrCacheUniformLocation(std::move(name)), x, y);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const glm::vec3& value
) const
{
    glUniform3f(this->getOrCacheUniformLocation(name), value.x, value.y, value.z);
}

void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    glm::vec3&& value
) const
{
    glUniform3f(this->getOrCacheUniformLocation(name), value.x, value.y, value.z);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const glm::vec3& value
) const
{
    glUniform3f(this->getOrCacheUniformLocation(std::move(name)), value.x, value.y, value.z);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    glm::vec3&& value
) const
{
    glUniform3f(this->getOrCacheUniformLocation(std::move(name)), value.x, value.y, value.z);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const float x,
    const float y,
    const float z
) const
{
    glUniform3f(this->getOrCacheUniformLocation(name), x, y, z);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const float x,
    const float y,
    const float z
) const
{
    glUniform3f(this->getOrCacheUniformLocation(std::move(name)), x, y, z);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const glm::vec4& value
) const
{
    glUniform4f(this->getOrCacheUniformLocation(name), value.x, value.y, value.z, value.w);
}

void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    glm::vec4&& value
) const
{
    glUniform4f(this->getOrCacheUniformLocation(name), value.x, value.y, value.z, value.w);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const glm::vec4& value
) const
{
    glUniform4f(this->getOrCacheUniformLocation(std::move(name)), value.x, value.y, value.z, value.w);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    glm::vec4&& value
) const
{
    glUniform4f(this->getOrCacheUniformLocation(std::move(name)), value.x, value.y, value.z, value.w);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const float x,
    const float y,
    const float z,
    const float w
) const
{
    glUniform4f(this->getOrCacheUniformLocation(name), x, y, z, w);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const float x,
    const float y,
    const float z,
    const float w
) const
{
    glUniform4f(this->getOrCacheUniformLocation(std::move(name)), x, y, z, w);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const glm::mat2& mat
) const
{
    glUniformMatrix2fv(this->getOrCacheUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    glm::mat2&& mat
) const
{
    glUniformMatrix2fv(this->getOrCacheUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const glm::mat2& mat
) const
{
    glUniformMatrix2fv(this->getOrCacheUniformLocation(std::move(name)), 1, GL_FALSE, &mat[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    glm::mat2&& mat
) const
{
    glUniformMatrix2fv(this->getOrCacheUniformLocation(std::move(name)), 1, GL_FALSE, &mat[0][0]);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const glm::mat3& mat
) const
{
    glUniformMatrix3fv(this->getOrCacheUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    glm::mat3&& mat
) const
{
    glUniformMatrix3fv(this->getOrCacheUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const glm::mat3& mat
) const
{
    glUniformMatrix3fv(getOrCacheUniformLocation(std::move(name)), 1, GL_FALSE, &mat[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    glm::mat3&& mat
) const
{
    glUniformMatrix3fv(getOrCacheUniformLocation(std::move(name)), 1, GL_FALSE, &mat[0][0]);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const glm::mat4& mat
) const
{
    glUniformMatrix4fv(this->getOrCacheUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    glm::mat4&& mat
) const
{
    glUniformMatrix4fv(this->getOrCacheUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const glm::mat4& mat
) const
{
    glUniformMatrix4fv(this->getOrCacheUniformLocation(std::move(name)), 1, GL_FALSE, &mat[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    glm::mat4&& mat
) const
{
    glUniformMatrix4fv(this->getOrCacheUniformLocation(std::move(name)), 1, GL_FALSE, &mat[0][0]);
}




void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const ::std::span<int> array
) const
{
    glUniform1iv(this->getOrCacheUniformLocation(name), array.size(), &array.front());
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const ::std::span<int> array
) const
{
    glUniform1iv(this->getOrCacheUniformLocation(std::move(name)), array.size(), &array.front());
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const ::std::span<float> array
) const
{
    glUniform1fv(this->getOrCacheUniformLocation(name), array.size(), &array.front());
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const ::std::span<float> array
) const
{
    glUniform1fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), &array.front());
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const ::std::span<glm::vec2> array
) const
{
    glUniform2fv(this->getOrCacheUniformLocation(name), array.size(), &array.front()[0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const ::std::span<glm::vec2> array
) const
{
    glUniform2fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), &array.front()[0]);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const ::std::span<glm::vec3> array
) const
{
    glUniform3fv(this->getOrCacheUniformLocation(name), array.size(), &array.front()[0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const ::std::span<glm::vec3> array
) const
{
    glUniform3fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), &array.front()[0]);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const ::std::span<glm::vec4> array
) const
{
    glUniform4fv(this->getOrCacheUniformLocation(name), array.size(), &array.front()[0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const ::std::span<glm::vec4> array
) const
{
    glUniform4fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), &array.front()[0]);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const ::std::span<glm::mat2> array
) const
{
    glUniformMatrix2fv(this->getOrCacheUniformLocation(name), array.size(), GL_FALSE, &array.front()[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const ::std::span<glm::mat2> array
) const
{
    glUniformMatrix2fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), GL_FALSE,
                       &array.front()[0][0]);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const ::std::span<glm::mat3> array
) const
{
    glUniformMatrix3fv(this->getOrCacheUniformLocation(name), array.size(), GL_FALSE, &array.front()[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const ::std::span<glm::mat3> array
) const
{
    glUniformMatrix3fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), GL_FALSE,
                       &array.front()[0][0]);
}



void ::engine::graphic::opengl::Shader::set(
    const ::std::string& name,
    const ::std::span<glm::mat4> array
) const
{
    glUniformMatrix4fv(this->getOrCacheUniformLocation(name), array.size(), GL_FALSE, &array.front()[0][0]);
}

void ::engine::graphic::opengl::Shader::set(
    ::std::string&& name,
    const ::std::span<glm::mat4> array
) const
{
    glUniformMatrix4fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), GL_FALSE,
                       &array.front()[0][0]);
}



// ------------------------------------------------------------------ Set

void ::engine::graphic::opengl::Shader::setBlockBinding(
    const ::std::string& name,
    const size_t index
) const
{
    auto blockIndex { glGetUniformBlockIndex(this->m_id, name.c_str()) };
    if (blockIndex == GL_INVALID_INDEX) {
        throw ::std::runtime_error("invalid uniform block index ("s + name + ":" + ::std::to_string(index) + ')');
    }
    glUniformBlockBinding(this->m_id, blockIndex, index);
}



// ------------------------------------------------------------------ Optimization

auto ::engine::graphic::opengl::Shader::getOrCacheUniformLocation(
    const ::std::string& uniformId
) const -> ::GLint
{
    try {
        // return it if already cached
        return m_uniformsLocationCache.at(uniformId);

    } catch (const ::std::exception&) {
        // cache it
        return m_uniformsLocationCache.emplace(uniformId, glGetUniformLocation(m_id, uniformId.c_str()))
            .first->second;
    }
}

auto ::engine::graphic::opengl::Shader::getOrCacheUniformLocation(
    ::std::string&& uniformId
) const -> ::GLint
{
    try {
        // return it if already cached
        return m_uniformsLocationCache.at(uniformId);

    } catch (const ::std::exception&) {
        // cache it
        return m_uniformsLocationCache
            .emplace(std::move(uniformId), glGetUniformLocation(m_id, uniformId.c_str()))
            .first->second;
    }
}
