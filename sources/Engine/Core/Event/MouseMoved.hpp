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

    virtual void resolve(
        ::engine::core::AScene& scene
    ) override final;



private:

    ::glm::vec2 m_offset;

    static inline ::glm::vec2 m_oldPosition;



private:

    friend ::engine::graphic::opengl::Window;

};



} // namespace engine::core::event
