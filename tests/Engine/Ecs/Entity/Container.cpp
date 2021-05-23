#include <pch.hpp>
#include <Engine/Core/Ecs/Entity/Container.hpp>
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
BOOST_AUTO_TEST_SUITE(Entity)
BOOST_AUTO_TEST_SUITE(Container)



BOOST_AUTO_TEST_CASE(get)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto entity1{ entities.emplace<::engine::core::ecs::component::test::Movable>() };
    auto entity2{ entities.get(entity1.getID()) };
    auto entity3{ entities[entity1.getID()] };

    BOOST_TEST(entities.contains(entity1.getID()));
    BOOST_TEST(&entities.unsafeGet(entity1.getID()).get() == &entity1.get());
    BOOST_TEST(&entity1.get() == &entity2.get());
    BOOST_TEST(&entity1.get() == &entity3.get());
}


// ------------------------------------------------------------------ emplace
BOOST_AUTO_TEST_SUITE(emplace)



BOOST_AUTO_TEST_CASE(singleComponent)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto entity{ entities.emplace<::engine::core::ecs::component::test::Movable>() };

    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::test::Movable>());
    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::test::Transformable>());
}

BOOST_AUTO_TEST_CASE(multipleComponent)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto entity{ entities.emplace<
        ::engine::core::ecs::component::test::Movable,
        ::engine::core::ecs::component::test::Transformable
    >() };

    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::test::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::test::Transformable>());
}




BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ remove
BOOST_AUTO_TEST_SUITE(remove)



BOOST_AUTO_TEST_CASE(remove)
{
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::entity::Container entities{ components };
    auto entityID{ entities.emplace<::engine::core::ecs::component::test::Movable>().getID() };
    BOOST_TEST(entities.contains(entityID));
    entities.remove(entityID);
    BOOST_TEST(!entities.contains(entityID));
}



BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
