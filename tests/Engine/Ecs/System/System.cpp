#include <pch.hpp>
#include <Engine/Core/Ecs/System.hpp>



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
        ::engine::core::ecs::Entity& e,
        ::engine::core::ecs::component::Movable& m
    ) {
        m.value++;
    }
    static auto lambda1{
        [](
            ::engine::core::ecs::Entity& e,
            ::engine::core::ecs::component::Movable& m
        ) {
            m.value++;
        }
    };

    static int function2(
        ::engine::core::ecs::Entity& e,
        ::engine::core::ecs::component::Transformable& t
    )
    {
        t.value++;
        return 0;
    }
    static auto lambda2{
        [](
            ::engine::core::ecs::Entity& e,
            ::engine::core::ecs::component::Transformable& t
        )
            -> int
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

    ::engine::core::ecs::System<detail::function1> system1;
    system1.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    system1.run(components, entities);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    ::engine::core::ecs::System<detail::function2> system2;
    system2.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 1);

    ::engine::core::ecs::System<detail::function3> system3;
    system3.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 2);
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

    ::engine::core::ecs::System<detail::lambda1> system1;
    system1.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    system1.run(components, entities);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    ::engine::core::ecs::System<detail::lambda2> system2;
    system2.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 1);

    ::engine::core::ecs::System<detail::lambda3> system3;
    system3.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 2);
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

    ::engine::core::ecs::System<[](::engine::core::ecs::component::Movable& m) { m.value++;}> system1;
    system1.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    system1.run(components, entities);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 0);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 0);

    ::engine::core::ecs::System<[](::engine::core::ecs::component::Transformable& t) -> int
        { t.value++; return 0; }> system2;
    system2.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 1);

    ::engine::core::ecs::System<[](
            ::engine::core::ecs::component::Movable& m,
            ::engine::core::ecs::component::Transformable& t
        ) {
            m.value++;
            t.value++;
        }
    > system3;
    system3.run(entities, components);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e1ID).value == 2);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e2ID).value == 1);
    BOOST_TEST(components.get<::engine::core::ecs::component::Movable>(e3ID).value == 3);
    BOOST_TEST(components.get<::engine::core::ecs::component::Transformable>(e3ID).value == 2);
}

BOOST_AUTO_TEST_CASE(signature)
{
    auto value{ ::engine::core::ecs::System<detail::function1>::getSignature() ==
        ::engine::core::ecs::Signature::generate<::engine::core::ecs::component::Movable>()
    };
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::lambda1>::getSignature() ==
        ::engine::core::ecs::Signature::generate<::engine::core::ecs::component::Movable>();
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::function3>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::Movable,
            ::engine::core::ecs::component::Transformable
        >();
    BOOST_TEST(value);

    value = ::engine::core::ecs::System<detail::lambda3>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::Movable,
            ::engine::core::ecs::component::Transformable
        >();
    BOOST_TEST(value);

    constexpr auto value2{ ::engine::core::ecs::System<detail::function3>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::Movable,
            ::engine::core::ecs::component::Transformable
        >()
    };
    BOOST_TEST(value2);

    constexpr auto value3{ ::engine::core::ecs::System<detail::lambda3>::getSignature() ==
        ::engine::core::ecs::Signature::generate<
            ::engine::core::ecs::component::Movable,
            ::engine::core::ecs::component::Transformable
        >()
    };
    BOOST_TEST(value3);
}


BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
