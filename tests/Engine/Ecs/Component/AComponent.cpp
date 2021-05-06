#include <pch.hpp>
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
BOOST_AUTO_TEST_SUITE(Component)



BOOST_AUTO_TEST_CASE(Constructor)
{
    ::engine::ecs::component::Movable movable();
    ::engine::ecs::component::Movable();
}



// ------------------------------------------------------------------ ID
BOOST_AUTO_TEST_SUITE(ID)



BOOST_AUTO_TEST_CASE(getStaticVsMember)
{
    BOOST_TEST(::engine::ecs::component::Movable::getID() ==
        ::engine::ecs::component::Movable().getID());
}

BOOST_AUTO_TEST_CASE(different)
{
    BOOST_TEST(::engine::ecs::component::Movable::getID() !=
        ::engine::ecs::component::Transformable::getID());
}

BOOST_AUTO_TEST_CASE(constexprness)
{
    // bitset needs a constexpr to compile
    ::std::bitset<::engine::ecs::component::Movable::getID() + 1>();
}



BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
