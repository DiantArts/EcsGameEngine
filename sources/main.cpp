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
    ::engine::ecs::system::System<func> system1;
    ::engine::ecs::system::System<[](int i){ ::std::cout << "hey2 " << i << ::std::endl; }> system2;
    ::engine::ecs::system::System<[](int i, int y, int z){
        ::std::cout << "[" << i << ", " << y << ", " << z << "]" << ::std::endl;
    }> system3;
    system1(1);
    system2(3);
    system1(6);
    system2(9);
    system3(9, 5, 1);

    // ::std::function<> function{ func };


    // ::engine::ecs::system::print_name(func);

    // ::engine::ecs::system::System<void, int> system1{ func };
    // ::engine::ecs::system::System system2{ [](int){ ::std::cout << "hey2" << ::std::endl; }};

    // system1();
    // system2();

    // ::AScene scene;

    // while (!scene.isOver()) {
        // scene.update();
        // scene.draw();
    // }

    return 0;
}
