#pragma once

namespace engine::core::event { class Container; }



namespace engine::graphic::opengl::detail {



void framebufferSizeCallback(
    GLFWwindow*,
    int width,
    int height
);

void applyDefaultConfiguration(
    GLFWwindow* window,
    ::engine::core::event::Container& events
);



} // namespace engine::graphic::opengl::detail
