#include <pch.hpp>
#include <Engine/Core/Ecs/System/Container.hpp>



// ------------------------------------------------------------------ Class test

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



namespace detail {

    static void function1(
        ::engine::core::ecs::component::Movable& m
    ) {
        m.value++;
    }
    static auto lambda1{
        [](
            ::engine::core::ecs::component::Movable& m
        ) {
            m.value++;
        }
    };

    static int function2(
        ::engine::core::ecs::component::Transformable& t
    )
    {
        t.value++;
        return 0;
    }
    static auto lambda2{
        [](
            ::engine::core::ecs::component::Transformable& t
        ) -> int
        {
            t.value++;
            return 0;
        }
    };

    static void function3(
        ::engine::core::ecs::component::Movable& m,
        ::engine::core::ecs::component::Transformable& t
    )
    {
        m.value++;
        t.value++;
    }
    static auto lambda3{
        [](
            ::engine::core::ecs::component::Movable& m,
            ::engine::core::ecs::component::Transformable& t
        ) {
            m.value++;
            t.value++;
        }
    };

}



#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Engine)
BOOST_AUTO_TEST_SUITE(Core)
BOOST_AUTO_TEST_SUITE(Ecs)
BOOST_AUTO_TEST_SUITE(System)
BOOST_AUTO_TEST_SUITE(Container)



BOOST_AUTO_TEST_CASE(mulpiteComponentMulipleEntityMulipleSystem)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto e1ID{ entities.emplace<::engine::core::ecs::component::Movable>().getID() };
    auto e2ID{ entities.emplace<::engine::core::ecs::component::Transformable>().getID() };
    auto e3ID{ entities.emplace<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >().getID() };
    ::engine::core::ecs::system::Container systems;

    systems.emplace<detail::function1>();
    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    systems.emplace<detail::function2>();
    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 1);

    systems.emplace<detail::function3>();
    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 4);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 5);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 3);
}

BOOST_AUTO_TEST_CASE(lambdaMulpiteComponentMulipleEntityMulipleSystem)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto e1ID{ entities.emplace<::engine::core::ecs::component::Movable>().getID() };
    auto e2ID{ entities.emplace<::engine::core::ecs::component::Transformable>().getID() };
    auto e3ID{ entities.emplace<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >().getID() };
    ::engine::core::ecs::system::Container systems;

    systems.emplace<detail::lambda1>();
    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    systems.emplace<detail::lambda2>();
    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 1);

    systems.emplace<detail::lambda3>();
    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 4);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 5);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 3);
}

BOOST_AUTO_TEST_CASE(inlineLambdaMulpiteComponentMulipleEntityMulipleSystem)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto e1ID{ entities.emplace<::engine::core::ecs::component::Movable>().getID() };
    auto e2ID{ entities.emplace<::engine::core::ecs::component::Transformable>().getID() };
    auto e3ID{ entities.emplace<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >().getID() };
    ::engine::core::ecs::system::Container systems;

    systems.emplace<[](::engine::core::ecs::component::Movable& m) { m.value++;}>();
    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    systems.emplace<[](::engine::core::ecs::component::Transformable& t) -> int
        { t.value++; return 0; }>();
    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 1);

    systems.emplace<[](
            ::engine::core::ecs::component::Movable& m,
            ::engine::core::ecs::component::Transformable& t
        ) {
            m.value++;
            t.value++;
        }>();
    systems.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 4);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 5);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 3);
}



BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
