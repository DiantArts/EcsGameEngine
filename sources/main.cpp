#include <pch.hpp>
#include <Game/Scene.hpp>
#include <Engine/Graphic/OpenGL/Window.hpp>

namespace engine::core::ecs::component {



    class Movable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

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

void func(const int&){}

int main()
{
    ::std::cout << ::engine::core::detail::meta::isModifiable<int> << ::std::endl;
    ::std::cout << ::engine::core::detail::meta::isModifiable<int&> << ::std::endl;
    ::std::cout << ::engine::core::detail::meta::isModifiable<const int&> << ::std::endl;
    ::std::cout << ::engine::core::detail::meta::isModifiable<const int> << ::std::endl;
    ::std::cout << ::engine::core::detail::meta::Function<decltype(func)>::Arguments::areConst << ::std::endl;
    ::engine::graphic::opengl::Window window;
    ::game::Scene scene{ window };

    while (!scene.isOver()) {
        scene.update();
        scene.draw();
    }

    return 0;
}
