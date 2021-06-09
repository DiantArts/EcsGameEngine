#include <pch.hpp>
#include <Game/Scene.hpp>
#include <Engine/Graphic/OpenGL/Window.hpp>



int main()
{
    try {
        ::engine::graphic::opengl::Window window;
        ::game::Scene scene{ window };

        while (!scene.isOver()) {
            scene.update();
            scene.draw();
        }

        return EXIT_SUCCESS;

    } catch (const::std::exception& e) {
       ::std::cerr << "ERROR: " << e.what() <<::std::endl;
        return EXIT_FAILURE;

    } catch (...) {
       ::std::cerr << "ERROR: unknown" <<::std::endl;
        return EXIT_FAILURE;

    }
}
