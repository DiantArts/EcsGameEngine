#include <pch.hpp>
#include <Engine/AScene.hpp>



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


template<
    typename T
> void func()
{
    ::std::cout << typeid(T).name() << ::std::endl;
}


int main()
{
    // func<::engine::ecs::component::Movable>();
    ::engine::ecs::component::Container container;
    container.constructSubContainer<::engine::ecs::component::Movable>();
    // container.construct<::engine::ecs::component::Movable, ::engine::ecs::component::Transformable>();


    // ::AScene scene;

    // while (!scene.isOver()) {
        // scene.update();
        // scene.draw();
    // }

    return 0;
}
