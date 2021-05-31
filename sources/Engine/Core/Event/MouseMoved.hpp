#pragma once

#include <Engine/Core/AEvent.hpp>
#include <Engine/Core/AScene.hpp>

namespace engine::graphic::opengl{ class Window; }



namespace engine::core::event {



class MouseMoved
    : public ::engine::core::AEvent
{

public:

    // ------------------------------------------------------------------ *structors

    explicit MouseMoved(
        float xPos,
        float yPos
    );

    ~MouseMoved();



    // ------------------------------------------------------------------ Resolver

    void resolve(
        ::engine::core::AScene& scene
    ) override final;



public:

    static inline ::glm::vec2 m_oldPosition;



private:

    ::glm::vec2 m_offset;

};



} // namespace engine::core::event
