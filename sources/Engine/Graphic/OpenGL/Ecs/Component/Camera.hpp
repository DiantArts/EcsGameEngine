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



    // ------------------------------------------------------------------ *structors

    void configureUbo(
        const ::glm::vec3& position,
        const ::glm::vec3& front,
        const ::glm::vec3& up
    ) const;



private:

    ::engine::graphic::opengl::Ubo m_informationsUbo;
    ::engine::graphic::opengl::Ubo m_positionUbo;

    ::glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
    float m_zoom { 45.0F };

    static constexpr int m_informationsUboIndex{ 0 };
    static constexpr int m_positionUboIndex{ 1 };

    static constexpr float minZoom { 1.0f };
    static constexpr float maxZoom { 45.0f };

    static constexpr float far { 0.1f };
    static constexpr float near { 100.0f };

};



} // namespace engine::graphic::opengl::ecs::component
