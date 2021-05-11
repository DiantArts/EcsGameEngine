#pragma once



namespace engine::graphic::opengl::detail {



void framebufferSizeCallback(
    GLFWwindow*,
    int width,
    int height
);

void applyDefaultConfiguration(
    GLFWwindow* window
);



} // namespace engine::graphic::opengl::detail
