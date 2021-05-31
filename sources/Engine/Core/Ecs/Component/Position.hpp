#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>



namespace engine::core::ecs::component {



class Position
    : public ::engine::core::ecs::AComponent<engine::core::ecs::component::Position>
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Position();

    explicit Position(
        float x,
        float y,
        float z
    );

    explicit Position(
        ::glm::vec3 position
    );

    ~Position();



    // ------------------------------------------------------------------ Position

    [[ nodiscard ]] operator ::glm::vec3&();

    [[ nodiscard ]] operator const ::glm::vec3&() const;

    [[ nodiscard ]] auto get() const
        -> const ::glm::vec3&;



    // ------------------------------------------------------------------ Set

    void set(
        ::glm::vec3 position
    );

    void setX(
        float x
    );

    void setY(
        float y
    );

    void setZ(
        float z
    );



private:

    ::glm::vec3 m_position;

};



} // namespace engine::core::ecs::component

