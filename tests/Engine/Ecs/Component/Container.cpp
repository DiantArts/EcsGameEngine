#include <pch.hpp>
#include <Engine/Ecs/AComponent.hpp>
#include <Engine/Ecs/Component/Container.hpp>



// ------------------------------------------------------------------ Class test

namespace engine::ecs::component {



    class Movable
        : public ::engine::ecs::AComponent<::engine::ecs::component::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

        bool operator==(const ::engine::ecs::component::Movable& that) const {
            return this == &that;
        }

        int value{ 0 };
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
BOOST_AUTO_TEST_SUITE(Container)



// ------------------------------------------------------------------ Component
BOOST_AUTO_TEST_SUITE(SubContainer)



BOOST_AUTO_TEST_CASE(singleTypeConstruct)
{
    ::engine::ecs::component::Container().constructSubContainer<::engine::ecs::component::Movable>();
}

BOOST_AUTO_TEST_CASE(multipleTypeConstruct)
{
    ::engine::ecs::component::Container().constructSubContainer<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >();
}

BOOST_AUTO_TEST_CASE(constructTwiceTheSame1)
{
    ::engine::ecs::component::Container container{};
    container.constructSubContainer<::engine::ecs::component::Movable>();
    BOOST_CHECK_THROW(
        container.constructSubContainer<::engine::ecs::component::Movable>(),
        ::std::exception
    );
}

BOOST_AUTO_TEST_CASE(constructTwiceTheSame2)
{
    ::engine::ecs::component::Container container{};
    container.constructSubContainer<::engine::ecs::component::Movable>();
    BOOST_CHECK_THROW((container.constructSubContainer<
            ::engine::ecs::component::Transformable,
            ::engine::ecs::component::Movable
        >()), ::std::exception);
}

BOOST_AUTO_TEST_CASE(get)
{
    ::engine::ecs::component::Container container{};
    container.constructSubContainer<::engine::ecs::component::Movable>();
    const ::std::vector<::engine::ecs::component::Movable>& vector{
        container.getSubContainer<::engine::ecs::component::Movable>()
    };
    BOOST_TEST(vector.size() == 0);
    container.emplace<::engine::ecs::component::Movable>(1);
    BOOST_TEST(vector.size() == 1);
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Component
BOOST_AUTO_TEST_SUITE(Component)



BOOST_AUTO_TEST_CASE(emplace)
{
    ::engine::ecs::component::Container container;
    container.constructSubContainer<::engine::ecs::component::Movable>();
    const auto& vector{ container.getSubContainer<::engine::ecs::component::Movable>() };
    container.emplace<::engine::ecs::component::Movable>(1);
    BOOST_TEST(vector.size() == 1);
}

BOOST_AUTO_TEST_CASE(emplaceTwiceTheSameOnSameID)
{
    ::engine::ecs::component::Container container;
    container.constructSubContainer<::engine::ecs::component::Movable>();
    container.emplace<::engine::ecs::component::Movable>(1);
    BOOST_CHECK_THROW(container.emplace<::engine::ecs::component::Movable>(1), ::std::exception);
}

BOOST_AUTO_TEST_CASE(compareEmplaceRetValAndGetRetVal)
{
    ::engine::ecs::component::Container container;
    container.constructSubContainer<::engine::ecs::component::Movable>();
    const auto& vector{ container.getSubContainer<::engine::ecs::component::Movable>() };
    const auto& movableComponent{ container.emplace<::engine::ecs::component::Movable>(1) };
    BOOST_TEST((movableComponent == container.get<::engine::ecs::component::Movable>(1)));
    BOOST_TEST((movableComponent.value == 0));
}

BOOST_AUTO_TEST_CASE(exists)
{
    ::engine::ecs::component::Container container;
    container.constructSubContainer<::engine::ecs::component::Movable>();
    container.emplace<::engine::ecs::component::Movable>(1);
    BOOST_TEST((container.exists<::engine::ecs::component::Movable>(1)));
}

BOOST_AUTO_TEST_CASE(doenstExists)
{
    ::engine::ecs::component::Container container;
    container.constructSubContainer<::engine::ecs::component::Movable>();
    BOOST_TEST((!container.exists<::engine::ecs::component::Movable>(1)));
}

BOOST_AUTO_TEST_CASE(getIndex)
{
    ::engine::ecs::component::Container container;
    container.constructSubContainer<::engine::ecs::component::Movable>();
    container.emplace<::engine::ecs::component::Movable>(1);
    BOOST_TEST((container.getIndex<::engine::ecs::component::Movable>(1) == 0));
}

BOOST_AUTO_TEST_CASE(generate)
{
    auto container{ ::engine::ecs::component::Container::generate<::engine::ecs::component::Movable>() };
    const auto& vector{ container.getSubContainer<::engine::ecs::component::Movable>() };
    container.emplace<::engine::ecs::component::Movable>(1);
    BOOST_TEST(vector.size() == 1);
}

BOOST_AUTO_TEST_CASE(multipleComponentValue)
{
    ::engine::ecs::component::Container container;
    container.constructSubContainer<::engine::ecs::component::Movable>();
    const auto& movableComponent{ container.emplace<::engine::ecs::component::Movable>(1) };
    BOOST_TEST(container.get<::engine::ecs::component::Movable>(1).value == 0);
    BOOST_TEST(movableComponent.value == 0);
    const auto& movableComponent2{ container.emplace<::engine::ecs::component::Movable>(2) };
    BOOST_TEST(container.get<::engine::ecs::component::Movable>(1).value == 0);
    BOOST_TEST(container.get<::engine::ecs::component::Movable>(2).value == 0);
    BOOST_TEST(movableComponent2.value == 0);
}



BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
