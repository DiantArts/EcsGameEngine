#include <pch.hpp>
#include <Engine/Ecs/Signature.hpp>
#include <Engine/Ecs/AComponent.hpp>



// ------------------------------------------------------------------ Class test

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



#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Engine)
BOOST_AUTO_TEST_SUITE(Ecs)
BOOST_AUTO_TEST_SUITE(Signature)



BOOST_AUTO_TEST_CASE(constexprness)
{
    auto signature1{ ::engine::ecs::Signature::generate<::engine::ecs::component::Movable>() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<::engine::ecs::component::Movable>() };
    constexpr auto signature3{ ::engine::ecs::Signature::generate<::engine::ecs::component::Movable>() };
    if constexpr (signature2 == signature3) {}
}



// ------------------------------------------------------------------ ContainsSignature
BOOST_AUTO_TEST_SUITE(ContainsSignature)



BOOST_AUTO_TEST_CASE(true1)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    constexpr auto signature2{
        ::engine::ecs::Signature::generate<::engine::ecs::component::Movable>()
    };
    BOOST_TEST(signature1.contains(signature2));
}

BOOST_AUTO_TEST_CASE(true2)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1.contains(signature2));
}

BOOST_AUTO_TEST_CASE(true3)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1.contains(signature2));
}

BOOST_AUTO_TEST_CASE(true4)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    BOOST_TEST(signature1.contains(signature2));
}

BOOST_AUTO_TEST_CASE(false1)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(!signature1.contains(signature2));
}

BOOST_AUTO_TEST_CASE(false2)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(!signature1.contains(signature2));
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ ContainsComponent
BOOST_AUTO_TEST_SUITE(ContainsComponent)



BOOST_AUTO_TEST_CASE(true1)
{
    constexpr auto signature{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(signature.contains<::engine::ecs::component::Movable>());
    ::engine::ecs::component::Movable movable;
    BOOST_TEST(signature.contains(movable));
}

BOOST_AUTO_TEST_CASE(true2)
{
    constexpr auto signature{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(signature.contains<::engine::ecs::component::Transformable>());
    ::engine::ecs::component::Transformable transformable;
    BOOST_TEST(signature.contains(transformable));
}

BOOST_AUTO_TEST_CASE(true3)
{
    constexpr auto signature{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST((signature.contains<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >()));
    ::engine::ecs::component::Movable movable;
    ::engine::ecs::component::Transformable transformable;
    BOOST_TEST(signature.contains(movable, transformable));
}

BOOST_AUTO_TEST_CASE(true4)
{
    constexpr auto signature{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    BOOST_TEST(signature.contains<::engine::ecs::component::Movable>());
    ::engine::ecs::component::Movable movable;
    BOOST_TEST(signature.contains(movable));
}

BOOST_AUTO_TEST_CASE(false1)
{
    constexpr auto signature{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    BOOST_TEST(!signature.contains<::engine::ecs::component::Transformable>());
    ::engine::ecs::component::Transformable transformable;
    BOOST_TEST(!signature.contains(transformable));
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Comparison
BOOST_AUTO_TEST_SUITE(Comparison)



BOOST_AUTO_TEST_CASE(true1Arg)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(true2Arg)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(false1Arg)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 != signature2);
}

BOOST_AUTO_TEST_CASE(false2Arg1)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 != signature2);
}

BOOST_AUTO_TEST_CASE(false2Arg2)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    BOOST_TEST(signature1 != signature2);
}

BOOST_AUTO_TEST_CASE(false2Arg3)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 != signature2);
}

BOOST_AUTO_TEST_CASE(false2Arg4)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 != signature2);
}

BOOST_AUTO_TEST_CASE(trueConstexprNonConstexpr)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(falseConstexprNonConstexpr)
{
    constexpr auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 != signature2);
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ BitManipulation
BOOST_AUTO_TEST_SUITE(BitManipulation)



BOOST_AUTO_TEST_CASE(set1Arg)
{
    auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    signature1.set<::engine::ecs::component::Transformable>();
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(set2Arg)
{
    auto signature1{ ::engine::ecs::Signature::generate() };
    auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    signature1.set<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >();
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(reset1Arg)
{
    auto signature1{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable
    >() };
    auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    signature2.reset<::engine::ecs::component::Transformable>();
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(reset2Arg)
{
    auto signature1{ ::engine::ecs::Signature::generate() };
    auto signature2{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    signature2.reset<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >();
    BOOST_TEST(signature1 == signature2);
}



BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
