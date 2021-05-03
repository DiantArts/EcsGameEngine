#include <pch.hpp>
#include <Engine/AScene.hpp>
#include <Engine/Ecs/System.hpp>
#include <Engine/Ecs/System/Container.hpp>



namespace engine::ecs::component {



    class Movable
        : public ::engine::ecs::AComponent<::engine::ecs::component::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

        int value{ 0 };
    };

    class Transformable
        : public ::engine::ecs::AComponent<::engine::ecs::component::Transformable>
    {
    public:
        Transformable() = default;
        ~Transformable() = default;

        int value{ 0 };
    };



} // namespace engine::ecs::component



void func1(::engine::ecs::component::Movable& m)
{
    m.value++;
}

void func2(::engine::ecs::component::Movable& m, ::engine::ecs::component::Transformable& t)
{
    m.value++;
    m.value++;
    t.value++;
}



int main()
{
    {
        auto components{ ::engine::ecs::component::Container::generate<
            ::engine::ecs::component::Movable,
            ::engine::ecs::component::Transformable
        >() };
        ::engine::ecs::entity::Container entities{ components };
        auto e1{ entities.emplace<::engine::ecs::component::Movable>() };
        auto e2{ entities.emplace<::engine::ecs::component::Movable, ::engine::ecs::component::Transformable>() };
        auto& e1m{ components.get<::engine::ecs::component::Movable>(e1.getID()) };
        auto& e2m{ components.get<::engine::ecs::component::Movable>(e2.getID()) };
        auto& e2t{ components.get<::engine::ecs::component::Transformable>(e2.getID()) };
        ::engine::ecs::System<func1>{}.run(entities, components);
        ::engine::ecs::System<func2>{}.run(entities, components);
        ::std::cout << e1m.value << ", " << e2m.value << ", " << e2t.value << ::std::endl;
    }
    {
        auto components{ ::engine::ecs::component::Container::generate<
            ::engine::ecs::component::Movable,
            ::engine::ecs::component::Transformable
        >() };
        ::engine::ecs::entity::Container entities{ components };
        auto e1{ entities.emplace<::engine::ecs::component::Movable>() };
        auto e2{ entities.emplace<::engine::ecs::component::Movable, ::engine::ecs::component::Transformable>() };
        auto& e1m{ components.get<::engine::ecs::component::Movable>(e1.getID()) };
        auto& e2m{ components.get<::engine::ecs::component::Movable>(e2.getID()) };
        auto& e2t{ components.get<::engine::ecs::component::Transformable>(e2.getID()) };
        ::engine::ecs::system::Container systems;
        systems.emplace<func1>();
        systems.emplace<func2>();
        systems.run(entities, components);
        ::std::cout << e1m.value << ", " << e2m.value << ", " << e2t.value << ::std::endl;
    }
    // ::engine::ecs::System<[](::engine::ecs::component::Movable){}>::run(entities, components);

    // while (!scene.isOver()) {
        // scene.update();
        // scene.draw();
    // }

    return 0;
}
