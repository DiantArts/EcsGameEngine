#include <pch.hpp>
#include <Engine/Core/AScene.hpp>
#include <Engine/Core/Ecs/System.hpp>
#include <Engine/Core/Ecs/System/Container.hpp>



namespace engine::core::ecs::component {



    class Movable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

        int value{ 0 };
    };

    class Transformable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::Transformable>
    {
    public:
        Transformable() = default;
        ~Transformable() = default;

        int value{ 0 };
    };



} // namespace engine::core::ecs::component



void func1(::engine::core::ecs::component::Movable& m)
{
    m.value++;
}

void func2(::engine::core::ecs::component::Movable& m, ::engine::core::ecs::component::Transformable& t)
{
    m.value++;
    m.value++;
    t.value++;
}



int main()
{
    {
        auto components{ ::engine::core::ecs::component::Container::generate<
            ::engine::core::ecs::component::Movable,
            ::engine::core::ecs::component::Transformable
        >() };
        ::engine::core::ecs::entity::Container entities{ components };
        auto e1{ entities.emplace<::engine::core::ecs::component::Movable>() };
        auto e2{ entities.emplace<::engine::core::ecs::component::Movable, ::engine::core::ecs::component::Transformable>() };
        auto& e1m{ components.get<::engine::core::ecs::component::Movable>(e1.getID()) };
        auto& e2m{ components.get<::engine::core::ecs::component::Movable>(e2.getID()) };
        auto& e2t{ components.get<::engine::core::ecs::component::Transformable>(e2.getID()) };
        ::engine::core::ecs::System<func1>{}.run(entities, components);
        ::engine::core::ecs::System<func2>{}.run(entities, components);
        ::std::cout << e1m.value << ", " << e2m.value << ", " << e2t.value << ::std::endl;
    }
    {
        auto components{ ::engine::core::ecs::component::Container::generate<
            ::engine::core::ecs::component::Movable,
            ::engine::core::ecs::component::Transformable
        >() };
        ::engine::core::ecs::entity::Container entities{ components };
        auto e1{ entities.emplace<::engine::core::ecs::component::Movable>() };
        auto e2{ entities.emplace<::engine::core::ecs::component::Movable, ::engine::core::ecs::component::Transformable>() };
        auto& e1m{ components.get<::engine::core::ecs::component::Movable>(e1.getID()) };
        auto& e2m{ components.get<::engine::core::ecs::component::Movable>(e2.getID()) };
        auto& e2t{ components.get<::engine::core::ecs::component::Transformable>(e2.getID()) };
        ::engine::core::ecs::system::Container systems;
        systems.emplace<func1>();
        systems.emplace<func2>();
        systems.run(entities, components);
        ::std::cout << e1m.value << ", " << e2m.value << ", " << e2t.value << ::std::endl;
    }
    // ::engine::core::ecs::System<[](::engine::core::ecs::component::Movable){}>::run(entities, components);

    // while (!scene.isOver()) {
        // scene.update();
        // scene.draw();
    // }

    return 0;
}
