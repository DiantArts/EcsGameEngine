#pragma once

#include <Engine/Graphic/OpenGL/Ubo.hpp>
#include <Engine/Core/AWindow.hpp>
#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Core/Ecs/Component/Position.hpp>



namespace engine::graphic::opengl::ecs::component {



class Camera
    : public ::engine::core::ecs::AComponent<engine::graphic::opengl::ecs::component::Camera>
{

public:

    // ------------------------------------------------------------------ *structors

    Camera(
        ::engine::core::AWindow& window
    );

    ~Camera();



    // ------------------------------------------------------------------ Copy sementic

    Camera(
        const Camera&
    ) noexcept = delete;

    auto operator=(
        const Camera&
    ) noexcept
        -> Camera& = delete;



    // ------------------------------------------------------------------ Move sementic

    Camera(
        Camera&&
    ) noexcept;

    auto operator=(
        Camera&&
    ) noexcept
        -> Camera&;



    // ------------------------------------------------------------------ Orientation

    auto getOrientation() const
        -> const ::glm::vec3&;

    void oriente(
        float xOffset,
        float yOffset
    );

    void oriente(
        const ::glm::vec2& offset
    );

    void setOrientation(
        float xOffset,
        float yOffset
    );

    void setOrientation(
        const ::glm::vec2& offset
    );



    // ------------------------------------------------------------------ Use

    void configureUbo(
        const ::glm::vec3& position,
        const ::glm::vec3& up
    ) const;



private:

    void adjustDirection();



private:

    ::engine::graphic::opengl::Ubo m_informationsUbo;
    ::engine::graphic::opengl::Ubo m_positionUbo;

    ::glm::vec2 m_orientation{ -90.00f, 0.00f }; // .x = yaw, .y = pitch
    ::glm::vec3 m_direction{ 0.5f, 0.5f, 0.5f };
    float m_distance { 5.0f };

    float m_zoom { 45.0F };

    static constexpr int m_informationsUboIndex{ 0 };
    static constexpr int m_positionUboIndex{ 1 };

    static constexpr float minZoom { 1.0f };
    static constexpr float maxZoom { 45.0f };

    static constexpr float far { 0.1f };
    static constexpr float near { 100.0f };

    static inline constexpr float minPitch{ -89.999f };
    static inline constexpr float maxPitch{ 89.999f };

    static inline constexpr ::glm::vec3 m_sensitivity{ 0.1f, 0.1f, 1.0f };

};



} // namespace engine::graphic::opengl::ecs::component
