#pragma once

#include <Engine/Graphic/OpenGL/Ubo.hpp>
#include <Engine/Core/AWindow.hpp>
#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Transformable.hpp>



namespace engine::graphic::opengl::ecs::component {



class Camera
    : public ::engine::core::ecs::AComponent<engine::graphic::opengl::ecs::component::Camera>
{

public:

    // ------------------------------------------------------------------ *structors

    Camera(
        ::engine::core::AWindow& window
    );

    Camera(
        ::engine::core::AWindow& window,
        ::glm::vec3 position
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



    // ------------------------------------------------------------------ Rotation

    void rotate(
        const ::glm::vec2& offset
    );

    void rotate(
        float yawOffset,
        float pitchOffset
    );

    void rotateYaw(
        float offset
    );

    void rotatePitch(
        float offset
    );



    void setRotation(
        const ::glm::vec2& rotation
    );

    void setRotation(
        ::glm::vec2&& rotation
    );

    void setRotation(
        float yaw,
        float pitch
    );

    void setYaw(
        float yaw
    );

    void setPitch(
        float pitch
    );



    [[ nodiscard ]] auto getRotation() const
        -> const ::glm::vec2&;

    [[ nodiscard ]] auto getDirection() const
        -> const ::glm::vec3&;



    // ------------------------------------------------------------------ Use

    void configureUbo(
        const ::engine::graphic::opengl::ecs::component::Transformable& transformable
    ) const;




private:

    void adjustDirection();



private:

    ::engine::graphic::opengl::Ubo m_informationsUbo;
    ::engine::graphic::opengl::Ubo m_positionUbo;
    ::engine::graphic::opengl::Ubo m_configurationUbo;
    static constexpr int m_informationsUboIndex{ 0 };
    static constexpr int m_positionUboIndex{ 1 };
    static constexpr int m_configurationUboIndex{ 2 };

    ::glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
    float m_distance{ 5.0f };

    ::glm::vec2 m_rotation{ -90.00f, 0.0F }; // .x = yaw, .y = pitch
    ::glm::vec3 m_direction;
    static inline constexpr float minPitch{ -89.999f };
    static inline constexpr float maxPitch{ 89.999f };
    static inline constexpr ::glm::vec3 m_sensitivity{ 0.1f, 0.1f, 1.0f };

    float m_zoom{ 45.0f };
    static constexpr float minZoom{ 1.0f };
    static constexpr float maxZoom{ 45.0f };

    static constexpr float far{ 0.1f };
    static constexpr float near{ 100.0f };

    static inline bool gamma{ true };
    static inline bool blinn{ false };


};



} // namespace engine::graphic::opengl::ecs::component
