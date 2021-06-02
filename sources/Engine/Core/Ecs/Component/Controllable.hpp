#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>



namespace engine::core::ecs::component {



class Controllable
    : public ::engine::core::ecs::AComponent<engine::core::ecs::component::Controllable>
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Controllable();

    ~Controllable();



    // ------------------------------------------------------------------ Speed

    auto getSpeed() const
        -> float;

    void setSpeed(
        float speed
    );



    // ------------------------------------------------------------------ Movement State

    virtual void updatePosition(
        float deltaTime,
        ::glm::vec3& position
    ) const;



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



    // ------------------------------------------------------------------ Orientation

    auto getDirection() const
        -> const ::glm::vec3&;

    auto getOrientation() const
        -> const ::glm::vec2&;

    auto getFront() const
        -> const ::glm::vec3&;

    auto getUp() const
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



    // ------------------------------------------------------------------ View

    auto getView(
        const ::glm::vec3& position
    ) const
        -> glm::mat4;



private:

    void adjustDirection();



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

    float m_speed{ 2.5f };

    ::glm::vec2 m_orientation{ -90.00f, 0.00f }; // .x = yaw, .y = pitch
    ::glm::vec3 m_direction{ 0.5f, 0.5f, 0.5f };
    ::glm::vec3 m_front{ 0.0f, 0.0f, -1.0f };
    ::glm::vec3 m_up{ 0.0f, 1.0f, 0.0f };

    static inline constexpr float minPitch{ -89.999f };
    static inline constexpr float maxPitch{ 89.999f };

    static inline constexpr ::glm::vec3 m_sensitivity{ 0.1f, 0.1f, 1.0f };

};



} // namespace engine::core::ecs::component
