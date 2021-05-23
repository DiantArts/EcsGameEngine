#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Window.hpp>
#include <Engine/Graphic/OpenGL/Detail/Window.hpp>
#include <Engine/Core/Event/MouseMoved.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::Window::Window()
    : m_window{ glfwCreateWindow(
        this->getSize().width,
        this->getSize().height,
        "MainWindow",
        glfwGetPrimaryMonitor(), // allows a fullscreen rendering
        nullptr
    )}
{
    if (!m_window) {
        glfwTerminate();
        throw std::runtime_error("Window creation failed");
    }

    glfwMakeContextCurrent(&*m_window);
    glfwSetFramebufferSizeCallback(&*m_window, ::engine::graphic::opengl::detail::framebufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        throw std::runtime_error("glad initialization failed");
    }

    ::engine::graphic::opengl::detail::applyDefaultConfiguration(&*m_window);
    glfwSetWindowUserPointer(m_window.get(), reinterpret_cast<void*>(&m_events));


    double x, y;
    glfwGetCursorPos(&*m_window, &x, &y);
    ::engine::core::event::MouseMoved::m_oldPosition.x = x;
    ::engine::core::event::MouseMoved::m_oldPosition.y = y;
}

::engine::graphic::opengl::Window::~Window() = default;



// ------------------------------------------------------------------ Loop

bool ::engine::graphic::opengl::Window::shouldClose() const
{
    return glfwWindowShouldClose(m_window.get()) || m_shouldClose;
}

void ::engine::graphic::opengl::Window::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void ::engine::graphic::opengl::Window::draw() const
{
    glfwSwapBuffers(m_window.get());
}



// ------------------------------------------------------------------ Event

void ::engine::graphic::opengl::Window::handleEvents(
    ::engine::core::AScene& scene
)
{
    glfwPollEvents();
    m_events.resolve(scene);
}



// ------------------------------------------------------------------ Window::Deleter

void ::engine::graphic::opengl::Window::Deleter::operator()(
    GLFWwindow* window
)
{
    glfwDestroyWindow(window);
}
