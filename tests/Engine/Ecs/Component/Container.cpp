#include <pch.hpp>
#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Core/Ecs/Component/Container.hpp>



// ------------------------------------------------------------------ Class test

namespace engine::core::ecs::component::test {



    class Movable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::test::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

        bool operator==(const ::engine::core::ecs::component::test::Movable& that) const {
            return this == &that;
        }

        int value{ 0 };
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
BOOST_AUTO_TEST_SUITE(Container)



BOOST_AUTO_TEST_CASE(emplaceTwiceTheSameOnSameID)
{
    ::engine::core::ecs::component::Container container;
    container.emplace<::engine::core::ecs::component::test::Movable>(1);
    BOOST_CHECK_THROW(container.emplace<::engine::core::ecs::component::test::Movable>(1), ::std::exception);
}

BOOST_AUTO_TEST_CASE(compareEmplaceRetValAndGetRetVal)
{
    ::engine::core::ecs::component::Container container;
    const auto& movableComponent{ container.emplace<::engine::core::ecs::component::test::Movable>(1) };
    BOOST_TEST((movableComponent == container.get<::engine::core::ecs::component::test::Movable>(1)));
    BOOST_TEST((movableComponent.value == 0));
}

BOOST_AUTO_TEST_CASE(exists)
{
    ::engine::core::ecs::component::Container container;
    container.emplace<::engine::core::ecs::component::test::Movable>(1);
    BOOST_TEST((container.exists<::engine::core::ecs::component::test::Movable>(1)));
}

BOOST_AUTO_TEST_CASE(doenstExists)
{
    ::engine::core::ecs::component::Container container;
    BOOST_TEST((!container.exists<::engine::core::ecs::component::test::Movable>(1)));
}

BOOST_AUTO_TEST_CASE(getIndex)
{
    ::engine::core::ecs::component::Container container;
    container.emplace<::engine::core::ecs::component::test::Movable>(1);
    BOOST_TEST((container.getIndex<::engine::core::ecs::component::test::Movable>(1) == 0));
}

BOOST_AUTO_TEST_CASE(multipleComponentValue)
{
    ::engine::core::ecs::component::Container container;
    const auto& movableComponent{ container.emplace<::engine::core::ecs::component::test::Movable>(1) };
    BOOST_TEST(container.get<::engine::core::ecs::component::test::Movable>(1).value == 0);
    BOOST_TEST(movableComponent.value == 0);
    const auto& movableComponent2{ container.emplace<::engine::core::ecs::component::test::Movable>(2) };
    BOOST_TEST(container.get<::engine::core::ecs::component::test::Movable>(1).value == 0);
    BOOST_TEST(container.get<::engine::core::ecs::component::test::Movable>(2).value == 0);
    BOOST_TEST(movableComponent2.value == 0);
}



BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
