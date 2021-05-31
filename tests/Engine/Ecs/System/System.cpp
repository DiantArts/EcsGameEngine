#include <pch.hpp>
#include <Engine/Core/Ecs/System.hpp>
#include <Engine/Core/Clock.hpp>



// ------------------------------------------------------------------ Class test

namespace engine::core::ecs::component::test {



    class Movable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::test::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

        int value{ 0 };
    };

    class Transformable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::test::Transformable>
    {
    public:
        Transformable() = default;
        ~Transformable() = default;

        int value{ 0 };
    };



} // namespace engine::core::ecs::component::test



namespace detail {

    static void function1(
        ::engine::core::ecs::Entity& e,
        ::engine::core::ecs::component::test::Movable& m
    ) {
        m.value++;
    }
    static auto lambda1{
        [](
            ::engine::core::ecs::Entity& e,
            ::engine::core::ecs::component::test::Movable& m
        ) {
            m.value++;
        }
    };

    static int function2(
        ::engine::core::ecs::Entity& e,
        ::engine::core::ecs::component::test::Transformable& t
    )
    {
        t.value++;
        return 0;
    }
    static auto lambda2{
        [](
            ::engine::core::ecs::Entity& e,
            ::engine::core::ecs::component::test::Transformable& t
        )
            -> int
        {
            t.value++;
            return 0;
        }
    };

    static void function3(
        ::engine::core::ecs::component::test::Movable& m,
        ::engine::core::ecs::component::test::Transformable& t
    )
    {
        m.value++;
        t.value++;
    }
    static auto lambda3{
        [](
            ::engine::core::ecs::component::test::Movable& m,
            ::engine::core::ecs::component::test::Transformable& t
        ) {
            m.value++;
            t.value++;
        }
    };

    static void function4(
        const ::engine::core::ecs::Entity& e,
        const ::engine::core::ecs::component::test::Movable& m,
        const ::engine::core::ecs::component::test::Transformable& t
    )
    {}

    static void function5(
        ::engine::core::Time deltaTime,
        ::engine::core::ecs::component::test::Movable& m
    ) {
        m.value++;
    }

    static void function6(
        ::engine::core::Time deltaTime,
        ::engine::core::ecs::Entity& e,
        ::engine::core::ecs::component::test::Movable& m
    ) {
        m.value++;
    }

    static void function7(
        ::engine::core::ecs::Entity& e,
        ::engine::core::Time deltaTime,
        ::engine::core::ecs::component::test::Movable& m
    ) {
        m.value++;
    }

    static void function8(
        ::engine::core::Time deltaTime,
        const ::engine::core::ecs::Entity& e,
        ::engine::core::ecs::component::test::Movable& m,
        ::engine::core::ecs::component::test::Transformable& t
    ) {
        m.value++;
        t.value++;
    }

    static void function9(
        const ::engine::core::ecs::Entity& e,
        const ::engine::core::Time deltaTime,
        const ::engine::core::ecs::component::test::Movable& m
    ) {}

    static void function10(
        const ::engine::core::ecs::Entity& e,
        const ::engine::core::Time deltaTime,
        const::engine::core::ecs::component::test::Movable& m
    ) {}


}



#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Engine)
BOOST_AUTO_TEST_SUITE(Core)
BOOST_AUTO_TEST_SUITE(Ecs)
BOOST_AUTO_TEST_SUITE(System)



BOOST_AUTO_TEST_CASE(mulpiteComponentMulipleEntityMulipleSystem)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto e1ID{ entities.emplace<::engine::core::ecs::component::test::Movable>().getID() };
    auto e2ID{ entities.emplace<::engine::core::ecs::component::test::Transformable>().getID() };
    auto e3ID{ entities.emplace<
        ::engine::core::ecs::component::test::Movable,
        ::engine::core::ecs::component::test::Transformable
    >().getID() };

    ::engine::core::ecs::System<detail::function1> system1;
    ::engine::core::Clock c;
    system1(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 0);

    system1(c.getElapsed(), components, entities);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 0);

    ::engine::core::ecs::System<detail::function2> system2;
    system2(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 1);

    ::engine::core::ecs::System<detail::function3> system3;
    system3(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 2);

    const ::engine::core::ecs::System<detail::function4> system4;
    system4(c.getElapsed(), entities, components);
}

BOOST_AUTO_TEST_CASE(lambdaMulpiteComponentMulipleEntityMulipleSystem)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto e1ID{ entities.emplace<::engine::core::ecs::component::test::Movable>().getID() };
    auto e2ID{ entities.emplace<::engine::core::ecs::component::test::Transformable>().getID() };
    auto e3ID{ entities.emplace<
        ::engine::core::ecs::component::test::Movable,
        ::engine::core::ecs::component::test::Transformable
    >().getID() };

    ::engine::core::ecs::System<detail::lambda1> system1;
    ::engine::core::Clock c;
    system1(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 0);

    system1(c.getElapsed(), components, entities);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 0);

    ::engine::core::ecs::System<detail::lambda2> system2;
    system2(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 1);

    ::engine::core::ecs::System<detail::lambda3> system3;
    system3(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 2);
}

BOOST_AUTO_TEST_CASE(inlineLambdaMulpiteComponentMulipleEntityMulipleSystem)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto e1ID{ entities.emplace<::engine::core::ecs::component::test::Movable>().getID() };
    auto e2ID{ entities.emplace<::engine::core::ecs::component::test::Transformable>().getID() };
    auto e3ID{ entities.emplace<
        ::engine::core::ecs::component::test::Movable,
        ::engine::core::ecs::component::test::Transformable
    >().getID() };

    ::engine::core::ecs::System<[](::engine::core::ecs::component::test::Movable& m) { m.value++;}> system1;
    ::engine::core::Clock c;
    system1(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 0);

    system1(c.getElapsed(), components, entities);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 0);

    ::engine::core::ecs::System<[](::engine::core::ecs::component::test::Transformable& t) -> int
        { t.value++; return 0; }> system2;
    system2(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 1);

    ::engine::core::ecs::System<[](
            ::engine::core::ecs::component::test::Movable& m,
            ::engine::core::ecs::component::test::Transformable& t
        ) {
            m.value++;
            t.value++;
        }
    > system3;
    system3(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 2);
}

BOOST_AUTO_TEST_CASE(systemTime)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto e1ID{ entities.emplace<::engine::core::ecs::component::test::Movable>().getID() };
    auto e2ID{ entities.emplace<::engine::core::ecs::component::test::Transformable>().getID() };
    auto e3ID{ entities.emplace<
        ::engine::core::ecs::component::test::Movable,
        ::engine::core::ecs::component::test::Transformable
    >().getID() };

    ::engine::core::ecs::System<detail::function5> system1;
    ::engine::core::Clock c;
    system1(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 0);

    ::engine::core::ecs::System<detail::function6> system2;
    system2(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 0);

    ::engine::core::ecs::System<detail::function7> system3;
    system3(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 0);

    ::engine::core::ecs::System<detail::function8> system4;
    system4(c.getElapsed(), entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e1ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Movable>(e3ID).value == 4);
    BOOST_TEST(components.get<::engine::core::ecs::component::test::Transformable>(e3ID).value == 1);

    ::engine::core::ecs::System<detail::function9> system5;
    system5(c.getElapsed(), entities, components);

    ::engine::core::ecs::System<detail::function10> system6;
    system6(c.getElapsed(), entities, components);
}

BOOST_AUTO_TEST_CASE(signature)
{
    auto value{ ::engine::core::ecs::System<detail::function1>::getSignature() ==
        ::engine::core::ecs::Signature::generate<::engine::core::ecs::component::test::Movable>()
    };
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::lambda1>::getSignature() ==
        ::engine::core::ecs::Signature::generate<::engine::core::ecs::component::test::Movable>();
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::function3>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::test::Movable,
            ::engine::core::ecs::component::test::Transformable
        >();
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::lambda3>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::test::Movable,
            ::engine::core::ecs::component::test::Transformable
        >();
    BOOST_TEST(value);

    constexpr auto value2{ ::engine::core::ecs::System<detail::function3>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::test::Movable,
            ::engine::core::ecs::component::test::Transformable
        >()
    };
    BOOST_TEST(value2);

    constexpr auto value3{ ::engine::core::ecs::System<detail::lambda3>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::test::Movable,
            ::engine::core::ecs::component::test::Transformable
        >()
    };
    BOOST_TEST(value3);

    value = ::engine::core::ecs::System<detail::function5>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::test::Movable
        >();
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::function6>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::test::Movable
        >();
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::function7>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::test::Movable
        >();
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::function8>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::test::Movable,
            ::engine::core::ecs::component::test::Transformable
        >();
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::function9>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::test::Movable
        >();
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::function10>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::test::Movable
        >();
    BOOST_TEST(value);
}


BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
