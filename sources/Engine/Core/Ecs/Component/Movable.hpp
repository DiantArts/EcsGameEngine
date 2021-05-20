#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>



namespace engine::core::ecs::component {



class Movable
    : public ::engine::core::ecs::AComponent<engine::core::ecs::component::Movable>
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Movable();

    ~Movable();



    // ------------------------------------------------------------------ Position

    operator ::glm::vec3&();

    operator const ::glm::vec3&() const;

    auto getPostion() const
        -> const ::glm::vec3&;



private:

    ::glm::vec3 m_position;

};



} // namespace engine::core::ecs::component

