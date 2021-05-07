#include <pch.hpp>
#include <Engine/Core/Ecs/AComponent.hpp>
#include <Engine/Core/Ecs/Component/Container.hpp>



// ------------------------------------------------------------------ Class test

namespace engine::core::ecs::component {



    class Movable
        : public ::engine::core::ecs::AComponent<::engine::core::ecs::component::Movable>
    {
    public:
        Movable() = default;
        ~Movable() = default;

        bool operator==(const ::engine::core::ecs::component::Movable& that) const {
            return this == &that;
        }

        int value{ 0 };
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
BOOST_AUTO_TEST_SUITE(Component)
BOOST_AUTO_TEST_SUITE(Container)



// ------------------------------------------------------------------ Component
BOOST_AUTO_TEST_SUITE(SubContainer)



BOOST_AUTO_TEST_CASE(singleTypeConstruct)
{
    ::engine::core::ecs::component::Container().constructSubContainer<::engine::core::ecs::component::Movable>();
}

BOOST_AUTO_TEST_CASE(multipleTypeConstruct)
{
    ::engine::core::ecs::component::Container().constructSubContainer<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >();
}

BOOST_AUTO_TEST_CASE(constructTwiceTheSame1)
{
    ::engine::core::ecs::component::Container container{};
    container.constructSubContainer<::engine::core::ecs::component::Movable>();
    BOOST_CHECK_THROW(
        container.constructSubContainer<::engine::core::ecs::component::Movable>(),
        ::std::exception
    );
}

BOOST_AUTO_TEST_CASE(constructTwiceTheSame2)
{
    ::engine::core::ecs::component::Container container{};
    container.constructSubContainer<::engine::core::ecs::component::Movable>();
    BOOST_CHECK_THROW((container.constructSubContainer<
            ::engine::core::ecs::component::Transformable,
            ::engine::core::ecs::component::Movable
        >()), ::std::exception);
}

BOOST_AUTO_TEST_CASE(get)
{
    ::engine::core::ecs::component::Container container{};
    container.constructSubContainer<::engine::core::ecs::component::Movable>();
    const ::std::vector<::engine::core::ecs::component::Movable>& vector{
        container.getSubContainer<::engine::core::ecs::component::Movable>()
    };
    BOOST_TEST(vector.size() == 0);
    container.emplace<::engine::core::ecs::component::Movable>(1);
    BOOST_TEST(vector.size() == 1);
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Component
BOOST_AUTO_TEST_SUITE(Component)



BOOST_AUTO_TEST_CASE(emplace)
{
    ::engine::core::ecs::component::Container container;
    container.constructSubContainer<::engine::core::ecs::component::Movable>();
    const auto& vector{ container.getSubContainer<::engine::core::ecs::component::Movable>() };
    container.emplace<::engine::core::ecs::component::Movable>(1);
    BOOST_TEST(vector.size() == 1);
}

BOOST_AUTO_TEST_CASE(emplaceTwiceTheSameOnSameID)
{
    ::engine::core::ecs::component::Container container;
    container.constructSubContainer<::engine::core::ecs::component::Movable>();
    container.emplace<::engine::core::ecs::component::Movable>(1);
    BOOST_CHECK_THROW(container.emplace<::engine::core::ecs::component::Movable>(1), ::std::exception);
}

BOOST_AUTO_TEST_CASE(compareEmplaceRetValAndGetRetVal)
{
    ::engine::core::ecs::component::Container container;
    container.constructSubContainer<::engine::core::ecs::component::Movable>();
    const auto& vector{ container.getSubContainer<::engine::core::ecs::component::Movable>() };
    const auto& movableComponent{ container.emplace<::engine::core::ecs::component::Movable>(1) };
    BOOST_TEST((movableComponent == container.get<::engine::core::ecs::component::Movable>(1)));
    BOOST_TEST((movableComponent.value == 0));
}

BOOST_AUTO_TEST_CASE(exists)
{
    ::engine::core::ecs::component::Container container;
    container.constructSubContainer<::engine::core::ecs::component::Movable>();
    container.emplace<::engine::core::ecs::component::Movable>(1);
    BOOST_TEST((container.exists<::engine::core::ecs::component::Movable>(1)));
}

BOOST_AUTO_TEST_CASE(doenstExists)
{
    ::engine::core::ecs::component::Container container;
    container.constructSubContainer<::engine::core::ecs::component::Movable>();
    BOOST_TEST((!container.exists<::engine::core::ecs::component::Movable>(1)));
}

BOOST_AUTO_TEST_CASE(getIndex)
{
    ::engine::core::ecs::component::Container container;
    container.constructSubContainer<::engine::core::ecs::component::Movable>();
    container.emplace<::engine::core::ecs::component::Movable>(1);
    BOOST_TEST((container.getIndex<::engine::core::ecs::component::Movable>(1) == 0));
}

BOOST_AUTO_TEST_CASE(generate)
{
    auto container{ ::engine::core::ecs::component::Container::generate<::engine::core::ecs::component::Movable>() };
    const auto& vector{ container.getSubContainer<::engine::core::ecs::component::Movable>() };
    container.emplace<::engine::core::ecs::component::Movable>(1);
    BOOST_TEST(vector.size() == 1);
}

BOOST_AUTO_TEST_CASE(multipleComponentValue)
{
    ::engine::core::ecs::component::Container container;
    container.constructSubContainer<::engine::core::ecs::component::Movable>();
    const auto& movableComponent{ container.emplace<::engine::core::ecs::component::Movable>(1) };
    BOOST_TEST(container.get<::engine::core::ecs::component::Movable>(1).value == 0);
    BOOST_TEST(movableComponent.value == 0);
    const auto& movableComponent2{ container.emplace<::engine::core::ecs::component::Movable>(2) };
    BOOST_TEST(container.get<::engine::core::ecs::component::Movable>(1).value == 0);
    BOOST_TEST(container.get<::engine::core::ecs::component::Movable>(2).value == 0);
    BOOST_TEST(movableComponent2.value == 0);
}



BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
