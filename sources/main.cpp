#include <pch.hpp>
#include <Engine/AScene.hpp>
#include <Engine/Ecs/Signature.hpp>



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

int main()
{
    // auto signature1{ ::engine::ecs::Signature::generate<::engine::ecs::component::Movable>() };
    // auto signature2{ ::engine::ecs::Signature::generate<::engine::ecs::component::Transformable>() };
    // ::std::cout << signature1 << ::std::endl;


    // ::AScene scene;

    // while (!scene.isOver()) {
        // scene.update();
        // scene.draw();
    // }

    return 0;
}
