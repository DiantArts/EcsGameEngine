#pragma once

#include <Engine/Core/AEvent.hpp>



namespace engine::core::event {



class KeyPressed
    : public ::engine::core::AEvent
{

public:

    // ------------------------------------------------------------------ *structors

    explicit KeyPressed(
        int keyCode
    );

    ~KeyPressed();



    // ------------------------------------------------------------------ Resolver

    virtual void resolve(
        ::engine::core::AScene& scene
    ) override final;



public:
protected:
protected:
private:
private:

    int m_keyCode;

};



} // namespace engine::core::event
