#include <pch.hpp>
#include <Engine/Core/Ecs/Component/Controllable.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::ecs::component::Controllable::Controllable() = default;

::engine::core::ecs::component::Controllable::~Controllable() = default;



// ------------------------------------------------------------------ Speed

auto ::engine::core::ecs::component::Controllable::getSpeed() const
    -> float
{
    return m_speed;
}

void ::engine::core::ecs::component::Controllable::setSpeed(
    float speed
)
{
    m_speed = speed;
}



// ------------------------------------------------------------------ Movement State

void ::engine::core::ecs::component::Controllable::updatePosition(
    float deltaTime,
    ::glm::vec3& position
)
{
    auto velocity = this->getSpeed() * deltaTime;

    if (this->isMovingForward()) {
        if (!this->isMovingBackward()) {
            position += velocity * m_front;
        }
    } else {
        if (this->isMovingBackward()) {
            position -= velocity * m_front;
        }
    }

    if (this->isMovingRight()) {
        if (!this->isMovingLeft()) {
            position += ::glm::normalize(::glm::cross(m_front, m_up)) * velocity;
        }
    } else {
        if (this->isMovingLeft()) {
            position -= ::glm::normalize(::glm::cross(m_front, m_up)) * velocity;
        }
    }

    if (this->isMovingUp()) {
        if (!this->isMovingDown()) {
            position.y += velocity;
        }
    } else {
        if (this->isMovingDown()) {
            position.y -= velocity;
        }
    }
}



void ::engine::core::ecs::component::Controllable::startMovingForward()
{
    m_movementState[Controllable::MovementState::Forward] = true;
}

void ::engine::core::ecs::component::Controllable::startMovingBackward()
{
    m_movementState[Controllable::MovementState::Backward] = true;
}

void ::engine::core::ecs::component::Controllable::startMovingRight()
{
    m_movementState[Controllable::MovementState::Right] = true;
}

void ::engine::core::ecs::component::Controllable::startMovingLeft()
{
    m_movementState[Controllable::MovementState::Left] = true;
}

void ::engine::core::ecs::component::Controllable::startMovingUp()
{
    m_movementState[Controllable::MovementState::Up] = true;
}

void ::engine::core::ecs::component::Controllable::startMovingDown()
{
    m_movementState[Controllable::MovementState::Down] = true;
}



void ::engine::core::ecs::component::Controllable::stopMovingForward()
{
    m_movementState[Controllable::MovementState::Forward] = false;
}

void ::engine::core::ecs::component::Controllable::stopMovingBackward()
{
    m_movementState[Controllable::MovementState::Backward] = false;
}

void ::engine::core::ecs::component::Controllable::stopMovingRight()
{
    m_movementState[Controllable::MovementState::Right] = false;
}

void ::engine::core::ecs::component::Controllable::stopMovingLeft()
{
    m_movementState[Controllable::MovementState::Left] = false;
}

void ::engine::core::ecs::component::Controllable::stopMovingUp()
{
    m_movementState[Controllable::MovementState::Up] = false;
}

void ::engine::core::ecs::component::Controllable::stopMovingDown()
{
    m_movementState[Controllable::MovementState::Down] = false;
}



void ::engine::core::ecs::component::Controllable::stopMoving()
{
    m_movementState.reset();
}

void ::engine::core::ecs::component::Controllable::immobilize()
{
    m_movementState.reset();
}



auto ::engine::core::ecs::component::Controllable::isMovingForward()
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Forward);
}

auto ::engine::core::ecs::component::Controllable::isMovingBackward()
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Backward);
}

auto ::engine::core::ecs::component::Controllable::isMovingRight()
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Right);
}

auto ::engine::core::ecs::component::Controllable::isMovingLeft()
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Left);
}

auto ::engine::core::ecs::component::Controllable::isMovingUp()
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Up);
}

auto ::engine::core::ecs::component::Controllable::isMovingDown()
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Down);
}



// ------------------------------------------------------------------ Orientation

auto ::engine::core::ecs::component::Controllable::getOrientation() const
    -> const ::glm::vec3&
{
    return m_orientation;
}

auto ::engine::core::ecs::component::Controllable::getFront() const
    -> const ::glm::vec3&
{
    return m_front;
}



void ::engine::core::ecs::component::Controllable::oriente(
    const float xOffset,
    const float yOffset
)
{
    m_yaw += xOffset * m_sensitivity.x;
    m_pitch += yOffset * m_sensitivity.y;

    if (m_yaw >= 360) {
        m_yaw -= 360;
    }
    if (m_pitch > this->maxPitch) {
        m_pitch = this->maxPitch;
    } else if (m_pitch < this->minPitch) {
        m_pitch = this->minPitch;
    }
    this->adjustOrientation();
}

void ::engine::core::ecs::component::Controllable::oriente(
    const ::glm::vec2& offset
)
{
    m_yaw += offset.x * m_sensitivity.x;
    m_pitch += offset.y * m_sensitivity.y;

    if (m_yaw >= 360) {
        m_yaw -= 360;
    }
    if (m_pitch > this->maxPitch) {
        m_pitch = this->maxPitch;
    } else if (m_pitch < this->minPitch) {
        m_pitch = this->minPitch;
    }
    this->adjustOrientation();
}



void ::engine::core::ecs::component::Controllable::setOrientation(
    const float xOffset,
    const float yOffset
)
{
    if (xOffset >= 360 || yOffset > this->maxPitch || yOffset < this->minPitch) {
        throw std::logic_error("invalid orientation");
    }
    m_yaw = xOffset;
    m_pitch = yOffset;
    this->adjustOrientation();
}

void ::engine::core::ecs::component::Controllable::setOrientation(
    const ::glm::vec2& offset
)
{
    if (offset.x >= 360 || offset.y > this->maxPitch || offset.y < this->minPitch) {
        throw std::logic_error("invalid orientation");
    }
    m_yaw = offset.x;
    m_pitch = offset.y;
    this->adjustOrientation();
}



// ------------------------------------------------------------------ View

auto ::engine::core::ecs::component::Controllable::getView(
    const ::glm::vec3& position
) const
    -> ::glm::mat4
{
    return ::glm::lookAt(position, position + m_front, m_up);
}



// ------------------------------------------------------------------ Detail

void ::engine::core::ecs::component::Controllable::adjustOrientation()
{
    m_orientation.x = cos(::glm::radians(m_yaw)) * cos(::glm::radians(m_pitch));
    m_orientation.y = sin(::glm::radians(m_pitch));
    m_orientation.z = sin(::glm::radians(m_yaw)) * cos(::glm::radians(m_pitch));
    m_front = ::glm::normalize(m_orientation);
}
