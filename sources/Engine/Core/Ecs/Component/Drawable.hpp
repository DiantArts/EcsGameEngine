#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>



namespace engine::core::ecs::component {



class Drawable
    : public ::engine::core::ecs::AComponent<Movable>
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Drawable();

    ~Drawable();



private:

};



} // namespace engine::core::ecs::component
