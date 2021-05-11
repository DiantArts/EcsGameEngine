#pragma once

#include <Engine/Core/AWindow.hpp>


struct GLFWwindow;



namespace engine::graphic::opengl {



class Window final
    : public ::engine::core::AWindow
{

public:

    // ------------------------------------------------------------------ *structors

    explicit Window();

    ~Window();



    // ------------------------------------------------------------------ Loop

    virtual bool shouldClose() const override;

    virtual void clear() const override;

    virtual void draw() const override;



    // ------------------------------------------------------------------ Event

    virtual void handleEvents(
        ::engine::core::AScene& scene
    ) override;



private:

    struct Deleter {
        void operator()(
            GLFWwindow* window
        );
    };
    std::unique_ptr<GLFWwindow, Window::Deleter> m_window;

};



} // namespace engine::core
