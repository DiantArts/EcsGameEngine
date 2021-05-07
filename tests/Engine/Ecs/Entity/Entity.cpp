#include <pch.hpp>
#include <Engine/Core/Ecs/Entity.hpp>
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
BOOST_AUTO_TEST_SUITE(Entity)



// ------------------------------------------------------------------ Component
BOOST_AUTO_TEST_SUITE(Component)



BOOST_AUTO_TEST_CASE(addNhas1)
{
    auto components{ ::engine::core::ecs::component::Container::generate<::engine::core::ecs::component::Movable>() };
    ::engine::core::ecs::Entity entity;
    const auto& component{ entity.addComponent<::engine::core::ecs::component::Movable>(components) };

    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Transformable>());
    BOOST_TEST(&component == &components.get<::engine::core::ecs::component::Movable>(entity.getID()));
}

BOOST_AUTO_TEST_CASE(addNhas2)
{
    auto components{
        ::engine::core::ecs::component::Container::generate<::engine::core::ecs::component::Transformable>()
    };
    ::engine::core::ecs::Entity entity;
    const auto& component{ entity.addComponent<::engine::core::ecs::component::Transformable>(components) };

    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Transformable>());
    BOOST_TEST(&component == &components.get<::engine::core::ecs::component::Transformable>(entity.getID()));
}

BOOST_AUTO_TEST_CASE(removeNhas)
{
    ::engine::core::ecs::component::Container components;
    components.constructSubContainer<::engine::core::ecs::component::Movable>();
    ::engine::core::ecs::Entity entity;
    entity.addComponent<::engine::core::ecs::component::Movable>(components);

    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(components.exists<::engine::core::ecs::component::Movable>(entity.getID()));

    entity.removeComponent<::engine::core::ecs::component::Movable>(components);
    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(!components.exists<::engine::core::ecs::component::Movable>(entity.getID()));
}

BOOST_AUTO_TEST_CASE(addNhasMulti1)
{
    ::engine::core::ecs::component::Container components;
    components.constructSubContainer<::engine::core::ecs::component::Movable>();
    components.constructSubContainer<::engine::core::ecs::component::Transformable>();
    ::engine::core::ecs::Entity entity;
    const auto& comp1{ entity.addComponent<::engine::core::ecs::component::Movable>(components) };
    const auto& comp2{ entity.addComponent<::engine::core::ecs::component::Transformable>(components) };

    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Transformable>());

    BOOST_TEST(&comp1 == &components.get<::engine::core::ecs::component::Movable>(entity.getID()));
    BOOST_TEST(&comp2 == &components.get<::engine::core::ecs::component::Transformable>(entity.getID()));
}

BOOST_AUTO_TEST_CASE(addNhasMulti2)
{
    ::engine::core::ecs::component::Container components;
    components.constructSubContainer<::engine::core::ecs::component::Movable>();
    components.constructSubContainer<::engine::core::ecs::component::Transformable>();
    ::engine::core::ecs::Entity entity;
    entity.addComponents<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >(components);

    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Transformable>());
    BOOST_TEST((entity.hasComponents<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >()));
}

BOOST_AUTO_TEST_CASE(addNhasMulti3)
{
    ::engine::core::ecs::component::Container components;
    components.constructSubContainer<::engine::core::ecs::component::Movable>();
    components.constructSubContainer<::engine::core::ecs::component::Transformable>();
    ::engine::core::ecs::Entity entity;
    entity.addComponents<
        ::engine::core::ecs::component::Transformable
    >(components);

    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Transformable>());
    BOOST_TEST(!(entity.hasComponents<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >()));
}

BOOST_AUTO_TEST_CASE(generate)
{
    ::engine::core::ecs::component::Container components;
    components.constructSubContainer<::engine::core::ecs::component::Movable>();
    components.constructSubContainer<::engine::core::ecs::component::Transformable>();
    auto entity{ ::engine::core::ecs::Entity::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >(components) };

    BOOST_TEST((entity.hasComponents<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >()));
}

BOOST_AUTO_TEST_CASE(removeNhasMulti1)
{
    ::engine::core::ecs::component::Container components;
    components.constructSubContainer<::engine::core::ecs::component::Movable>();
    components.constructSubContainer<::engine::core::ecs::component::Transformable>();
    ::engine::core::ecs::Entity entity;
    entity.addComponents<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >(components);

    BOOST_TEST((entity.hasComponents<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >()));
    entity.removeComponent<::engine::core::ecs::component::Movable>(components);
    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Transformable>());
    entity.removeComponent<::engine::core::ecs::component::Transformable>(components);
    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Transformable>());
}

BOOST_AUTO_TEST_CASE(removeNhasMulti2)
{
    ::engine::core::ecs::component::Container components;
    components.constructSubContainer<::engine::core::ecs::component::Movable>();
    components.constructSubContainer<::engine::core::ecs::component::Transformable>();
    ::engine::core::ecs::Entity entity;
    entity.addComponents<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >(components);

    BOOST_TEST((entity.hasComponents<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >()));
    entity.removeComponents<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >(components);
    BOOST_TEST(!(entity.hasComponents<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >()));
    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Transformable>());
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Signature
BOOST_AUTO_TEST_SUITE(Signature)



BOOST_AUTO_TEST_CASE(single)
{
    ::engine::core::ecs::component::Container components;
    components.constructSubContainer<::engine::core::ecs::component::Movable>();
    components.constructSubContainer<::engine::core::ecs::component::Transformable>();
    auto entity{ ::engine::core::ecs::Entity::generate<::engine::core::ecs::component::Movable>(components) };
    auto signature{ ::engine::core::ecs::Signature::generate<::engine::core::ecs::component::Movable>() };

    BOOST_TEST((entity.getSignature() == signature));
}

BOOST_AUTO_TEST_CASE(multi)
{
    ::engine::core::ecs::component::Container components;
    components.constructSubContainer<::engine::core::ecs::component::Movable>();
    components.constructSubContainer<::engine::core::ecs::component::Transformable>();
    auto entity{ ::engine::core::ecs::Entity::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >(components) };
    auto signature{ ::engine::core::ecs::Signature::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };

    BOOST_TEST((entity.getSignature() == signature));
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Signature
BOOST_AUTO_TEST_SUITE(ID)



BOOST_AUTO_TEST_CASE(incrementation)
{
    ::engine::core::ecs::Entity entity1, entity2, entity3;

    BOOST_TEST(entity1.getID() == entity2.getID() - 1);
    BOOST_TEST(entity1.getID() == entity3.getID() - 2);
    BOOST_TEST(entity2.getID() == entity3.getID() - 1);
}



BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
