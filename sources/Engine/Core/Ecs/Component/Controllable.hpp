#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Transformable.hpp>



namespace engine::core::ecs::component {



class Controllable
    : public ::engine::core::ecs::AComponent<engine::core::ecs::component::Controllable>
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Controllable(
        bool ableToFly = false
    );

    ~Controllable();



    // ------------------------------------------------------------------ Speed

    auto getSpeed() const
        -> float;

    void setSpeed(
        float speed
    );



    // ------------------------------------------------------------------ Movement State

    void updatePosition(
        float deltaTime,
        ::engine::graphic::opengl::ecs::component::Transformable& transformable
    );

    void updateFly(
        float deltaTime,
        ::engine::graphic::opengl::ecs::component::Transformable& transformable
    );

    void updateRun(
        float deltaTime,
        ::engine::graphic::opengl::ecs::component::Transformable& transformable
    );



    void startMovingForward();

    void startMovingBackward();

    void startMovingRight();

    void startMovingLeft();

    void startMovingUp();

    void startMovingDown();



    void stopMovingForward();

    void stopMovingBackward();

    void stopMovingRight();

    void stopMovingLeft();

    void stopMovingUp();

    void stopMovingDown();



    void stopMoving();

    void immobilize();



    auto isMovingForward() const
        -> bool;

    auto isMovingBackward() const
        -> bool;

    auto isMovingRight() const
        -> bool;

    auto isMovingLeft() const
        -> bool;

    auto isMovingUp() const
        -> bool;

    auto isMovingDown() const
        -> bool;



    // ------------------------------------------------------------------ Rotation

    void updateRotation(
        ::engine::graphic::opengl::ecs::component::Transformable& transformable
    );


    void rotate(
        const ::glm::vec2& offset
    );

    void rotate(
        const float yawOffset,
        const float pitchOffset
    );

    void rotateYaw(
        const float offset
    );

    void rotatePitch(
        const float offset
    );



    [[ nodiscard ]] auto getRotation() const
        -> const ::glm::vec3&;


private:

    enum MovementState {
        Forward = 0,
        Backward = 1,
        Left = 2,
        Right = 3,
        Up = 4,
        Down = 5,
    };
    ::std::bitset<6> m_movementState;

    bool m_ableToFly{ false };

    float m_speed{ 5.0f };

    ::glm::vec3 m_rotation{ 0.0f, 0.0f, 0.0f };

    static inline constexpr float minPitch{ -89.999f };
    static inline constexpr float maxPitch{ 89.999f };

    static inline constexpr ::glm::vec3 m_sensitivity{ 0.1f, 0.1f, 1.0f };

};



} // namespace engine::core::ecs::component
