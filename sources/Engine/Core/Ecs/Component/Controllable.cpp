#include <pch.hpp>
#include <Engine/Core/Ecs/Component/Controllable.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::ecs::component::Controllable::Controllable(
    bool ableToFly
)
    : m_ableToFly{ ableToFly }
{}

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
    ::engine::graphic::opengl::ecs::component::Transformable& transformable
)
{
    if (m_ableToFly) {
        this->updateFly(deltaTime, transformable);
    } else {
        this->updateRun(deltaTime, transformable);
    }
}

void ::engine::core::ecs::component::Controllable::updateFly(
    float deltaTime,
    ::engine::graphic::opengl::ecs::component::Transformable& transformable
)
{
    if (this->isMovingUp()) {
        auto velocity = this->getSpeed() * deltaTime;
        if (!this->isMovingDown()) {
            if (this->isMovingForward()) {
                if (!this->isMovingBackward()) {
                    if (this->isMovingRight() || this->isMovingLeft()) { // if moving up-forward-side
                        velocity /= 3;
                    } else { // if moving up-forward
                        velocity /= 2;
                    }
                    transformable.moveForward(velocity);
                }
            } else if (this->isMovingBackward()) {
                if (this->isMovingRight() || this->isMovingLeft()) { // if moving up-backward-side
                    velocity /= 4;
                } else { // if moving up-backward
                    velocity /= 3;
                }
                transformable.moveBackward(velocity);
            } else {
                if (this->isMovingRight() || this->isMovingLeft()) {
                    velocity /= 2;
                }
            }
            transformable.moveUp(velocity);
            if (this->isMovingRight()) {
                if (!this->isMovingLeft()) {
                    transformable.moveRight(velocity);
                }
            } else if (this->isMovingLeft()) {
                transformable.moveLeft(velocity);
            }
        }
    } else if (this->isMovingDown()) { // if moving down
        auto velocity = this->getSpeed() * deltaTime;
        if (this->isMovingForward()) {
            if (!this->isMovingBackward()) {
                if (this->isMovingRight() || this->isMovingLeft()) { // if moving down-forward-side
                    velocity /= 3;
                } else {  // if moving down-forward
                    velocity /= 2;
                }
                transformable.moveForward(velocity);
            }
        } else if (this->isMovingBackward()) {
            if (this->isMovingRight() || this->isMovingLeft()) { // if moving down-backward-side
                velocity /= 4;
            } else { // if moving down-backward
                velocity /= 3;
            }
            transformable.moveBackward(velocity);
        } else {
            if (this->isMovingRight() || this->isMovingLeft()) {
                velocity /= 2;
            }
        }
        transformable.moveDown(velocity);
        if (this->isMovingRight()) {
            if (!this->isMovingLeft()) {
                transformable.moveRight(velocity);
            }
        } else if (this->isMovingLeft()) {
            transformable.moveLeft(velocity);
        }
    } else {
        this->updateRun(deltaTime, transformable);
        return;
    }
}

void ::engine::core::ecs::component::Controllable::updateRun(
    float deltaTime,
    ::engine::graphic::opengl::ecs::component::Transformable& transformable
)
{
    auto velocity = this->getSpeed() * deltaTime;

    if (this->isMovingForward()) {
        if (!this->isMovingBackward()) {
            if (this->isMovingRight() || this->isMovingLeft()) {
                velocity /= 2;
            }
            transformable.moveForward(velocity);
        }
    } else if (this->isMovingBackward()) {
        if (this->isMovingRight() || this->isMovingLeft()) {
            velocity /= 3;
        } else {
            velocity /= 2;
        }
        transformable.moveBackward(velocity);
    } else {
        if (this->isMovingRight() || this->isMovingLeft()) {
            velocity /= 1.5;
        }
    }

    if (this->isMovingRight()) {
        if (!this->isMovingLeft()) {
            transformable.moveRight(velocity);
        }
    } else if (this->isMovingLeft()) {
        transformable.moveLeft(velocity);
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



auto ::engine::core::ecs::component::Controllable::isMovingForward() const
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Forward);
}

auto ::engine::core::ecs::component::Controllable::isMovingBackward() const
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Backward);
}

auto ::engine::core::ecs::component::Controllable::isMovingRight() const
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Right);
}

auto ::engine::core::ecs::component::Controllable::isMovingLeft() const
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Left);
}

auto ::engine::core::ecs::component::Controllable::isMovingUp() const
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Up);
}

auto ::engine::core::ecs::component::Controllable::isMovingDown() const
    -> bool
{
    return m_movementState.test(Controllable::MovementState::Down);
}



// ------------------------------------------------------------------ Rotation

void ::engine::core::ecs::component::Controllable::updateRotation(
    ::engine::graphic::opengl::ecs::component::Transformable& transformable
)
{
    while (m_rotation.x >= 360) {
        m_rotation.x -= 360;
    }
    transformable.rotate(::std::move(m_rotation));
    m_rotation = ::glm::vec3{ 0.0F, 0.0F, 0.0F };
}


void ::engine::core::ecs::component::Controllable::rotate(
    const ::glm::vec2& offset
)
{
    m_rotation.x += offset.x * m_sensitivity.x;
    m_rotation.y += offset.y * m_sensitivity.y;

    if (m_rotation.y > this->maxPitch) {
        m_rotation.y = this->maxPitch;
    } else if (m_rotation.y < this->minPitch) {
        m_rotation.y = this->minPitch;
    }
}

void ::engine::core::ecs::component::Controllable::rotate(
    const float yawOffset,
    const float pitchOffset
)
{
    m_rotation.x += yawOffset * m_sensitivity.x;
    m_rotation.y += pitchOffset * m_sensitivity.y;

    if (m_rotation.y > this->maxPitch) {
        m_rotation.y = this->maxPitch;
    } else if (m_rotation.y < this->minPitch) {
        m_rotation.y = this->minPitch;
    }
}

void ::engine::core::ecs::component::Controllable::rotateYaw(
    const float offset
)
{
    m_rotation.x += offset * m_sensitivity.x;
}

void ::engine::core::ecs::component::Controllable::rotatePitch(
    const float offset
)
{
    m_rotation.y += offset * m_sensitivity.y;

    if (m_rotation.y > this->maxPitch) {
        m_rotation.y = this->maxPitch;
    } else if (m_rotation.y < this->minPitch) {
        m_rotation.y = this->minPitch;
    }
}



[[ nodiscard ]] auto ::engine::core::ecs::component::Controllable::getRotation() const
    -> const ::glm::vec3&
{
    return m_rotation;
}
