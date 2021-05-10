#pragma once

#include <Engine/Core/AEvent.hpp>



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



public:
protected:
protected:
private:
private:

    glm::vec2 m_offset;

};



} // namespace engine::core::event
