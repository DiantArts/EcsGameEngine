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


int main()
{
    // ::std::cout << ::engine::core::ecs::entity::ConceptType<::engine::core::ecs::Entity&> << ::std::endl;
    ::engine::graphic::opengl::Window window;
    ::game::Scene scene{ window };

    while (!scene.isOver()) {
        scene.update();
        scene.draw();
    }

    return 0;
}
