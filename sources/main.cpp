#include <pch.hpp>
// #include <Game/Scene.hpp>
// #include <Engine/Graphic/OpenGL/Window.hpp>

#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Core/Ecs/Component/Container.hpp>

namespace engine::core::ecs::component {



    class Movable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

        // Movable(const Movable&) = delete;
        // Movable& operator=(const Movable&) = delete;
        // Movable(Movable&&) = delete;
        // Movable& operator=(Movable&&) = delete;

        bool operator==(const ::engine::core::ecs::component::Movable& that) const {
            return this == &that;
        }

        int value{ 0 };
    };

    class Transformable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::Transformable>
    {
    public:
        Transformable() = default;
        ~Transformable() = default;

    };



} // namespace engine::core::ecs::component



int main()
{
    ::engine::core::ecs::component::Container container;

    ::engine::core::ecs::component::Movable& movableComponent{ container.emplace<::engine::core::ecs::component::Movable>(1) };
    ::std::cout << &container.get<::engine::core::ecs::component::Movable>(1) << " == " << container.get<::engine::core::ecs::component::Movable>(1).value << ::std::endl;
    ::std::cout << &movableComponent.value << " == " << movableComponent.value << "\n" << ::std::endl;

    movableComponent.value++;
    ::std::cout << &container.get<::engine::core::ecs::component::Movable>(1) << " == " << container.get<::engine::core::ecs::component::Movable>(1).value << ::std::endl;
    ::std::cout << &movableComponent.value << " == " << movableComponent.value << "\n" << ::std::endl;

    // const auto& movableComponent2{ container.emplace<::engine::core::ecs::component::Movable>(2) };
    // ::std::cout << &container.get<::engine::core::ecs::component::Movable>(1).value << " == " << container.get<::engine::core::ecs::component::Movable>(1).value << ::std::endl;
    // ::std::cout << &container.get<::engine::core::ecs::component::Movable>(2).value << " == " << container.get<::engine::core::ecs::component::Movable>(2).value << ::std::endl;
    // ::std::cout << &movableComponent2.value << " == " << movableComponent2.value << "\n" << ::std::endl;

    // ::std::cout << &container.get<::engine::core::ecs::component::Movable>(2).value << ::std::endl;
    // ::std::cout << &movableComponent2.value << ::std::endl;

    // const auto& movableComponent3{ container.emplace<::engine::core::ecs::component::Movable>(2) };

    // ::std::cout << &container.get<::engine::core::ecs::component::Movable>(2).value << ::std::endl;
    // ::std::cout << &movableComponent2.value << ::std::endl;
    return 0;

    // try {
        // ::engine::graphic::opengl::Window window;
        // ::game::Scene scene{ window };

        // while (!scene.isOver()) {
            // scene.update();
            // scene.draw();
        // }

        // return EXIT_SUCCESS;

    // } catch (const std::exception& e) {
        // std::cerr << "ERROR: " << e.what() << std::endl;
        // return EXIT_FAILURE;

    // } catch (...) {
        // std::cerr << "ERROR: unknown" << std::endl;
        // return EXIT_FAILURE;

    // }

}
