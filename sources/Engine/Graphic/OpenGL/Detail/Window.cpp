#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Detail/Window.hpp>
#include <Engine/Core/Event/Container.hpp>
#include <Engine/Core/Event/KeyPressed.hpp>
#include <Engine/Core/Event/KeyReleased.hpp>
#include <Engine/Core/Event/MouseMoved.hpp>



// ------------------------------------------------------------------ Functions

static void keyCallback(
    GLFWwindow* window,
    int keyCode,
    int,
    int action,
    int mods
)
{
    auto& events = *reinterpret_cast<::engine::core::event::Container*>(glfwGetWindowUserPointer(window));
    if (action == GLFW_PRESS) {
        events.emplace<::engine::core::event::KeyPressed>(std::move(keyCode));
    } else if (action == GLFW_RELEASE) {
        events.emplace<::engine::core::event::KeyReleased>(std::move(keyCode));
    }
}

static void mouseMovedCallback(
    GLFWwindow* window,
    double xPos,
    double yPos
)
{
    auto& events = *reinterpret_cast<::engine::core::event::Container*>(glfwGetWindowUserPointer(window));
    events.emplace<::engine::core::event::MouseMoved>(std::move(xPos), std::move(yPos));
}

void mouseScrollcallback(
    GLFWwindow*,
    double,
    double yOffset
)
{}

static void GLAPIENTRY messageCallback(
    GLenum source,
    GLenum type,
    GLuint,
    GLenum severity,
    GLsizei,
    const GLchar* message,
    const void*
)
{
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH: std::clog << "ERROR"; break;
    case GL_DEBUG_SEVERITY_MEDIUM: std::clog << "ERROR"; break;
    case GL_DEBUG_SEVERITY_LOW: std::clog << "Warning"; break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: std::clog << "notification"; break;
    }
    std::clog << " (GL): " << message;
    std::clog << " (src: " << source << ", type: " << type;
    std::clog << ")" << std::endl;
}

void ::engine::graphic::opengl::detail::framebufferSizeCallback(
    GLFWwindow*,
    int width,
    int height
)
{
    glViewport(0, 0, width, height);
}

void ::engine::graphic::opengl::detail::applyDefaultConfiguration(
    GLFWwindow* window
)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, mouseMovedCallback);
    // glfwSetScrollCallback(window, mouseScrollcallback);

#ifdef __APPLE__ // even if apple will soon not support OpenGL anymore
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // __APPLE__

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_FRAMEBUFFER_SRGB);

    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_CCW);

    // glEnable(GL_STENCIL_TEST);

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(messageCallback, 0);

    // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearColor(0.0f, 1.0f, 0.9f, 1.0f);

#ifdef DEBUG
    glfwSwapInterval(0); // disable vsync
#endif
}



// ------------------------------------------------------------------ OpenGLMemoryManager

class OpenGLMemoryManager {
    OpenGLMemoryManager()
    {
        if (!glfwInit()) {
            throw std::runtime_error("glwfInit failed");
        }

        stbi_set_flip_vertically_on_load(true);
    }

    ~OpenGLMemoryManager()
    {
        glfwTerminate();
    }

    static constinit const OpenGLMemoryManager _;
};
const OpenGLMemoryManager OpenGLMemoryManager::_;
