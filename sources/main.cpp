#include <pch.hpp>
#include <Engine/AScene.hpp>
#include <Engine/Ecs/System.hpp>



namespace engine::ecs::component {



    class Movable
        : public ::engine::ecs::AComponent<::engine::ecs::component::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

    };

    class Transformable
        : public ::engine::ecs::AComponent<::engine::ecs::component::Transformable>
    {
    public:
        Transformable() = default;
        ~Transformable() = default;

    };



} // namespace engine::ecs::component




int func(int i)
{
    ::std::cout << "hey1 " << i << ::std::endl;
    return 0;
}



int main()
{
    // ::AScene scene;

    // while (!scene.isOver()) {
        // scene.update();
        // scene.draw();
    // }

    return 0;
}
