#pragma once

namespace engine::graphic::opengl {



class Shader {

public:

    // ------------------------------------------------------------------ *structors

    Shader(
        std::string_view filepathes
    );

    Shader(
        std::string_view vertexFilename,
        std::string_view fragmentFilename
    );

    Shader(
        std::string_view vertexFilename,
        std::string_view fragmentFilename,
        std::string_view geometryFilename
    );

    ~Shader();



    // ------------------------------------------------------------------ Copy sementic

    Shader(
        const Shader&
    ) noexcept = delete;

    auto operator=(
        const Shader&
    ) noexcept
        -> Shader& = delete;



    // ------------------------------------------------------------------ Move sementic

    Shader(
        Shader&&
    ) noexcept;

    auto operator=(
        Shader&&
    ) noexcept
        -> Shader&;



    // ------------------------------------------------------------------ Use

    void use() const;



    // ------------------------------------------------------------------ Set (must be used before)

    void set(
        const std::string& name,
        bool value
    ) const;

    void set(
        std::string&& name,
        bool value
    ) const;

    void set(
        const std::string& name,
        int value
    ) const;

    void set(
        std::string&& name,
        int value
    ) const;

    void set(
        const std::string& name,
        size_t value
    ) const;

    void set(
        std::string&& name,
        size_t value
    ) const;

    void set(
        const std::string& name,
        float value
    ) const;

    void set(
        std::string&& name,
        float value
    ) const;



    void set(
        const std::string& name,
        const glm::vec2& value
    ) const;

    void set(
        const std::string& name,
        glm::vec2&& value
    ) const;

    void set(
        std::string&& name,
        const glm::vec2& value
    ) const;

    void set(
        std::string&& name,
        glm::vec2&& value
    ) const;

    void set(
        const std::string& name,
        float x,
        float y
    ) const;

    void set(
        std::string&& name,
        float x,
        float y
    ) const;

    void set(
        const std::string& name,
        const glm::vec3& value
    ) const;

    void set(
        const std::string& name,
        glm::vec3&& value
    ) const;

    void set(
        std::string&& name,
        const glm::vec3& value
    ) const;

    void set(
        std::string&& name,
        glm::vec3&& value
    ) const;

    void set(
        const std::string& name,
        float x,
        float y,
        float z
    ) const;

    void set(
        std::string&& name,
        float x,
        float y,
        float z
    ) const;

    void set(
        const std::string& name,
        const glm::vec4& value
    ) const;

    void set(
        const std::string& name,
        glm::vec4&& value
    ) const;

    void set(
        std::string&& name,
        const glm::vec4& value
    ) const;

    void set(
        std::string&& name,
        glm::vec4&& value
    ) const;

    void set(
        const std::string& name,
        float x,
        float y,
        float z,
        float w
    ) const;

    void set(
        std::string&& name,
        float x,
        float y,
        float z,
        float w
    ) const;



    void set(
        const std::string& name,
        const glm::mat2& mat
    ) const;

    void set(
        const std::string& name,
        glm::mat2&& mat
    ) const;

    void set(
        std::string&& name,
        const glm::mat2& mat
    ) const;

    void set(
        std::string&& name,
        glm::mat2&& mat
    ) const;

    void set(
        const std::string& name,
        const glm::mat3& mat
    ) const;

    void set(
        const std::string& name,
        glm::mat3&& mat
    ) const;

    void set(
        std::string&& name,
        const glm::mat3& mat
    ) const;

    void set(
        std::string&& name,
        glm::mat3&& mat
    ) const;

    void set(
        const std::string& name,
        const glm::mat4& mat
    ) const;

    void set(
        const std::string& name,
        glm::mat4&& mat
    ) const;

    void set(
        std::string&& name,
        const glm::mat4& mat
    ) const;

    void set(
        std::string&& name,
        glm::mat4&& mat
    ) const;



    void set(
        const std::string& name,
        std::span<int> array
    ) const;

    void set(
        std::string&& name,
        std::span<int> array
    ) const;

    void set(
        const std::string& name,
        std::span<float> array
    ) const;

    void set(
        std::string&& name,
        std::span<float> array
    ) const;



    void set(
        const std::string& name,
        std::span<glm::vec2> array
    ) const;

    void set(
        std::string&& name,
        std::span<glm::vec2> array
    ) const;

    void set(
        const std::string& name,
        std::span<glm::vec3> array
    ) const;

    void set(
        std::string&& name,
        std::span<glm::vec3> array
    ) const;

    void set(
        const std::string& name,
        std::span<glm::vec4> array
    ) const;

    void set(
        std::string&& name,
        std::span<glm::vec4> array
    ) const;



    void set(
        const std::string& name,
        std::span<glm::mat2> array
    ) const;

    void set(
        std::string&& name,
        std::span<glm::mat2> array
    ) const;

    void set(
        const std::string& name,
        std::span<glm::mat3> array
    ) const;

    void set(
        std::string&& name,
        std::span<glm::mat3> array
    ) const;

    void set(
        const std::string& name,
        std::span<glm::mat4> array
    ) const;

    void set(
        std::string&& name,
        std::span<glm::mat4> array
    ) const;



    // ------------------------------------------------------------------ SetBlockBinding (must be used before)

    void setBlockBinding(
        const std::string& name,
        size_t index
    ) const;




private:

    // ------------------------------------------------------------------ Optimization

    auto getOrCacheUniformLocation(
        const std::string& uniformId
    ) const
        -> GLint;

    auto getOrCacheUniformLocation(
        std::string&& uniformId
    ) const
        -> GLint;



private:

    GLint m_id;

    mutable std::unordered_map<std::string, GLuint> m_uniformsLocationCache;

};



} // namespace engine::graphic::opengl
