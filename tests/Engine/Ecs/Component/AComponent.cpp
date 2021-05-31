#include <pch.hpp>
#include <Engine/Core/Ecs/AComponent.hpp>



// ------------------------------------------------------------------ Class test

namespace engine::core::ecs::component::test {



    class Movable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::test::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

    };

    class Transformable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::test::Transformable>
    {
    public:
        Transformable() = default;
        ~Transformable() = default;

    };



} // namespace engine::core::ecs::component::test




#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(Engine)
BOOST_AUTO_TEST_SUITE(Core)
BOOST_AUTO_TEST_SUITE(Ecs)
BOOST_AUTO_TEST_SUITE(Component)



BOOST_AUTO_TEST_CASE(Constructor)
{
    ::engine::core::ecs::component::test::Movable movable;
    ::engine::core::ecs::component::test::Movable{};
}



// ------------------------------------------------------------------ ID
BOOST_AUTO_TEST_SUITE(ID)



BOOST_AUTO_TEST_CASE(getStaticVsMember)
{
    BOOST_TEST(::engine::core::ecs::component::test::Movable::getID() ==
        ::engine::core::ecs::component::test::Movable().getID());
}

BOOST_AUTO_TEST_CASE(different)
{
    BOOST_TEST(::engine::core::ecs::component::test::Movable::getID() !=
        ::engine::core::ecs::component::test::Transformable::getID());
}

BOOST_AUTO_TEST_CASE(constexprness)
{
    // bitset needs a constexpr to compile
    ::std::bitset<::engine::core::ecs::component::test::Movable::getID() + 1>();
}



BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
