#pragma once

#include <Engine/Core/AEvent.hpp>



namespace engine::core::event {



class KeyReleased
    : public ::engine::core::AEvent
{

public:

    // ------------------------------------------------------------------ *structors

    explicit KeyReleased(
        int keyCode
    );

    ~KeyReleased();



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
