#include <pch.hpp>
#include <Engine/Ecs/Entity.hpp>
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
BOOST_AUTO_TEST_SUITE(Entity)



// ------------------------------------------------------------------ Component
BOOST_AUTO_TEST_SUITE(Component)



BOOST_AUTO_TEST_CASE(addNhas1)
{
    auto components{ ::engine::ecs::component::Container::generate<::engine::ecs::component::Movable>() };
    ::engine::ecs::Entity entity;
    const auto& component{ entity.addComponent<::engine::ecs::component::Movable>(components) };

    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Transformable>());
    BOOST_TEST(&component == &components.get<::engine::ecs::component::Movable>(entity.getID()));
}

BOOST_AUTO_TEST_CASE(addNhas2)
{
    auto components{
        ::engine::ecs::component::Container::generate<::engine::ecs::component::Transformable>()
    };
    ::engine::ecs::Entity entity;
    const auto& component{ entity.addComponent<::engine::ecs::component::Transformable>(components) };

    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Transformable>());
    BOOST_TEST(&component == &components.get<::engine::ecs::component::Transformable>(entity.getID()));
}

BOOST_AUTO_TEST_CASE(removeNhas)
{
    ::engine::ecs::component::Container components;
    components.constructSubContainer<::engine::ecs::component::Movable>();
    ::engine::ecs::Entity entity;
    entity.addComponent<::engine::ecs::component::Movable>(components);

    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(components.exists<::engine::ecs::component::Movable>(entity.getID()));

    entity.removeComponent<::engine::ecs::component::Movable>(components);
    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(!components.exists<::engine::ecs::component::Movable>(entity.getID()));
}

BOOST_AUTO_TEST_CASE(addNhasMulti1)
{
    ::engine::ecs::component::Container components;
    components.constructSubContainer<::engine::ecs::component::Movable>();
    components.constructSubContainer<::engine::ecs::component::Transformable>();
    ::engine::ecs::Entity entity;
    const auto& comp1{ entity.addComponent<::engine::ecs::component::Movable>(components) };
    const auto& comp2{ entity.addComponent<::engine::ecs::component::Transformable>(components) };

    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Transformable>());

    BOOST_TEST(&comp1 == &components.get<::engine::ecs::component::Movable>(entity.getID()));
    BOOST_TEST(&comp2 == &components.get<::engine::ecs::component::Transformable>(entity.getID()));
}

BOOST_AUTO_TEST_CASE(addNhasMulti2)
{
    ::engine::ecs::component::Container components;
    components.constructSubContainer<::engine::ecs::component::Movable>();
    components.constructSubContainer<::engine::ecs::component::Transformable>();
    ::engine::ecs::Entity entity;
    entity.addComponents<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >(components);

    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Transformable>());
    BOOST_TEST((entity.hasComponents<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >()));
}

BOOST_AUTO_TEST_CASE(addNhasMulti3)
{
    ::engine::ecs::component::Container components;
    components.constructSubContainer<::engine::ecs::component::Movable>();
    components.constructSubContainer<::engine::ecs::component::Transformable>();
    ::engine::ecs::Entity entity;
    entity.addComponents<
        ::engine::ecs::component::Transformable
    >(components);

    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Transformable>());
    BOOST_TEST(!(entity.hasComponents<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >()));
}

BOOST_AUTO_TEST_CASE(generate)
{
    ::engine::ecs::component::Container components;
    components.constructSubContainer<::engine::ecs::component::Movable>();
    components.constructSubContainer<::engine::ecs::component::Transformable>();
    auto entity{ ::engine::ecs::Entity::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >(components) };

    BOOST_TEST((entity.hasComponents<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >()));
}

BOOST_AUTO_TEST_CASE(removeNhasMulti1)
{
    ::engine::ecs::component::Container components;
    components.constructSubContainer<::engine::ecs::component::Movable>();
    components.constructSubContainer<::engine::ecs::component::Transformable>();
    ::engine::ecs::Entity entity;
    entity.addComponents<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >(components);

    BOOST_TEST((entity.hasComponents<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >()));
    entity.removeComponent<::engine::ecs::component::Movable>(components);
    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Transformable>());
    entity.removeComponent<::engine::ecs::component::Transformable>(components);
    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Transformable>());
}

BOOST_AUTO_TEST_CASE(removeNhasMulti2)
{
    ::engine::ecs::component::Container components;
    components.constructSubContainer<::engine::ecs::component::Movable>();
    components.constructSubContainer<::engine::ecs::component::Transformable>();
    ::engine::ecs::Entity entity;
    entity.addComponents<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >(components);

    BOOST_TEST((entity.hasComponents<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >()));
    entity.removeComponents<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >(components);
    BOOST_TEST(!(entity.hasComponents<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >()));
    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Transformable>());
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Signature
BOOST_AUTO_TEST_SUITE(Signature)



BOOST_AUTO_TEST_CASE(single)
{
    ::engine::ecs::component::Container components;
    components.constructSubContainer<::engine::ecs::component::Movable>();
    components.constructSubContainer<::engine::ecs::component::Transformable>();
    auto entity{ ::engine::ecs::Entity::generate<::engine::ecs::component::Movable>(components) };
    auto signature{ ::engine::ecs::Signature::generate<::engine::ecs::component::Movable>() };

    BOOST_TEST((entity.getSignature() == signature));
}

BOOST_AUTO_TEST_CASE(multi)
{
    ::engine::ecs::component::Container components;
    components.constructSubContainer<::engine::ecs::component::Movable>();
    components.constructSubContainer<::engine::ecs::component::Transformable>();
    auto entity{ ::engine::ecs::Entity::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >(components) };
    auto signature{ ::engine::ecs::Signature::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };

    BOOST_TEST((entity.getSignature() == signature));
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Signature
BOOST_AUTO_TEST_SUITE(ID)



BOOST_AUTO_TEST_CASE(incrementation)
{
    ::engine::ecs::Entity entity1, entity2, entity3;

    BOOST_TEST(entity1.getID() == entity2.getID() - 1);
    BOOST_TEST(entity1.getID() == entity3.getID() - 2);
    BOOST_TEST(entity2.getID() == entity3.getID() - 1);
}



BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
