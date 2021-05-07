#include <pch.hpp>
#include <Engine/Core/Ecs/Signature.hpp>
#include <Engine/Core/Ecs/AComponent.hpp>



// ------------------------------------------------------------------ Class test

namespace engine::core::ecs::component {



    class Movable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

    };

    class Transformable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::Transformable>
    {
    public:
        Transformable() = default;
        ~Transformable() = default;

    };



} // namespace engine::core::ecs::component



#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Engine)
BOOST_AUTO_TEST_SUITE(Core)
BOOST_AUTO_TEST_SUITE(Ecs)
BOOST_AUTO_TEST_SUITE(Signature)



BOOST_AUTO_TEST_CASE(constexprness)
{
    auto signature1{ ::engine::core::ecs::Signature::generate<::engine::core::ecs::component::Movable>() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<::engine::core::ecs::component::Movable>() };
    constexpr auto signature3{ ::engine::core::ecs::Signature::generate<::engine::core::ecs::component::Movable>() };
    if constexpr (signature2 == signature3) {}
}



// ------------------------------------------------------------------ ContainsSignature
BOOST_AUTO_TEST_SUITE(ContainsSignature)



BOOST_AUTO_TEST_CASE(true1)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    constexpr auto signature2{
        ::engine::core::ecs::Signature::generate<::engine::core::ecs::component::Movable>()
    };
    BOOST_TEST(signature1.contains(signature2));
}

BOOST_AUTO_TEST_CASE(true2)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1.contains(signature2));
}

BOOST_AUTO_TEST_CASE(true3)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1.contains(signature2));
}

BOOST_AUTO_TEST_CASE(true4)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    BOOST_TEST(signature1.contains(signature2));
}

BOOST_AUTO_TEST_CASE(false1)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(!signature1.contains(signature2));
}

BOOST_AUTO_TEST_CASE(false2)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(!signature1.contains(signature2));
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ ContainsComponent
BOOST_AUTO_TEST_SUITE(ContainsComponent)



BOOST_AUTO_TEST_CASE(true1)
{
    constexpr auto signature{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(signature.contains<::engine::core::ecs::component::Movable>());
    ::engine::core::ecs::component::Movable movable;
    BOOST_TEST(signature.contains(movable));
}

BOOST_AUTO_TEST_CASE(true2)
{
    constexpr auto signature{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(signature.contains<::engine::core::ecs::component::Transformable>());
    ::engine::core::ecs::component::Transformable transformable;
    BOOST_TEST(signature.contains(transformable));
}

BOOST_AUTO_TEST_CASE(true3)
{
    constexpr auto signature{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST((signature.contains<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >()));
    ::engine::core::ecs::component::Movable movable;
    ::engine::core::ecs::component::Transformable transformable;
    BOOST_TEST(signature.contains(movable, transformable));
}

BOOST_AUTO_TEST_CASE(true4)
{
    constexpr auto signature{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    BOOST_TEST(signature.contains<::engine::core::ecs::component::Movable>());
    ::engine::core::ecs::component::Movable movable;
    BOOST_TEST(signature.contains(movable));
}

BOOST_AUTO_TEST_CASE(false1)
{
    constexpr auto signature{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    BOOST_TEST(!signature.contains<::engine::core::ecs::component::Transformable>());
    ::engine::core::ecs::component::Transformable transformable;
    BOOST_TEST(!signature.contains(transformable));
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Comparison
BOOST_AUTO_TEST_SUITE(Comparison)



BOOST_AUTO_TEST_CASE(true1Arg)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(true2Arg)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(false1Arg)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 != signature2);
}

BOOST_AUTO_TEST_CASE(false2Arg1)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 != signature2);
}

BOOST_AUTO_TEST_CASE(false2Arg2)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    BOOST_TEST(signature1 != signature2);
}

BOOST_AUTO_TEST_CASE(false2Arg3)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 != signature2);
}

BOOST_AUTO_TEST_CASE(false2Arg4)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    constexpr auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 != signature2);
}

BOOST_AUTO_TEST_CASE(trueConstexprNonConstexpr)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(falseConstexprNonConstexpr)
{
    constexpr auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Transformable
    >() };
    BOOST_TEST(signature1 != signature2);
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ BitManipulation
BOOST_AUTO_TEST_SUITE(BitManipulation)



BOOST_AUTO_TEST_CASE(set1Arg)
{
    auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    signature1.set<::engine::core::ecs::component::Transformable>();
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(set2Arg)
{
    auto signature1{ ::engine::core::ecs::Signature::generate() };
    auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    signature1.set<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >();
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(reset1Arg)
{
    auto signature1{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable
    >() };
    auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    signature2.reset<::engine::core::ecs::component::Transformable>();
    BOOST_TEST(signature1 == signature2);
}

BOOST_AUTO_TEST_CASE(reset2Arg)
{
    auto signature1{ ::engine::core::ecs::Signature::generate() };
    auto signature2{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    signature2.reset<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >();
    BOOST_TEST(signature1 == signature2);
}



BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
