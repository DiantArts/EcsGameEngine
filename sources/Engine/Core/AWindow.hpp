#pragma once

#include <Engine/Core/Event/Container.hpp>



namespace engine::core { class AScene; }



namespace engine::core {



class AWindow {

public:

    struct Size {
        float width;
        float height;
    };



public:

    // ------------------------------------------------------------------ *structors

    explicit AWindow();

    virtual ~AWindow() = 0;



    // ------------------------------------------------------------------ Copy sementic

    AWindow(
        const AWindow&
    ) noexcept = delete;

    auto operator=(
        const AWindow&
    ) noexcept
        -> AWindow& = delete;



    // ------------------------------------------------------------------ Move sementic

    AWindow(
        AWindow&&
    ) noexcept;

    auto operator=(
        AWindow&&
    ) noexcept
        -> AWindow&;



    // ------------------------------------------------------------------ Loop

    virtual bool shouldClose() const = 0;

    virtual void clear() const = 0;

    virtual void draw() const = 0;



    // ------------------------------------------------------------------ Event

    virtual void handleEvents(
        ::engine::core::AScene& scene
    ) = 0;



    // ------------------------------------------------------------------ Propreties

    auto getSize() const
        -> const AWindow::Size&;



protected:

    ::engine::core::event::Container m_events;

    AWindow::Size m_size;

    bool m_shouldClose{ false };

};



} // namespace engine::core
