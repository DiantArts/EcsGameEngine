#include <pch.hpp>
#include <Engine/Ecs/Entity/Reference.hpp>
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
BOOST_AUTO_TEST_SUITE(Referenre)



// ------------------------------------------------------------------ Component
BOOST_AUTO_TEST_SUITE(Component)



BOOST_AUTO_TEST_CASE(addNhas)
{
    auto components{ ::engine::ecs::component::Container::generate<::engine::ecs::component::Movable>() };
    ::engine::ecs::Entity entity;
    ::engine::ecs::entity::Reference ref{ components, entity };

    const auto& component{ ref.addComponent<::engine::ecs::component::Movable>() };

    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(ref.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Transformable>());
    BOOST_TEST(!ref.hasComponent<::engine::ecs::component::Transformable>());
    BOOST_TEST(&component == &components.get<::engine::ecs::component::Movable>(entity.getID()));
    BOOST_TEST(&component == &components.get<::engine::ecs::component::Movable>(ref.getID()));
}

BOOST_AUTO_TEST_CASE(removeNhas)
{
    auto components{ ::engine::ecs::component::Container::generate<::engine::ecs::component::Movable>() };
    ::engine::ecs::Entity entity;
    ::engine::ecs::entity::Reference ref{ components, entity };


    ref.addComponent<::engine::ecs::component::Movable>();

    BOOST_TEST(entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(ref.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(components.exists<::engine::ecs::component::Movable>(entity.getID()));
    BOOST_TEST(components.exists<::engine::ecs::component::Movable>(ref.getID()));

    ref.removeComponent<::engine::ecs::component::Movable>();
    BOOST_TEST(!entity.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(!ref.hasComponent<::engine::ecs::component::Movable>());
    BOOST_TEST(!components.exists<::engine::ecs::component::Movable>(entity.getID()));
    BOOST_TEST(!components.exists<::engine::ecs::component::Movable>(ref.getID()));
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Signature
BOOST_AUTO_TEST_SUITE(Signature)



BOOST_AUTO_TEST_CASE(single)
{
    auto components{ ::engine::ecs::component::Container::generate<
        ::engine::ecs::component::Movable,
        ::engine::ecs::component::Transformable
    >() };
    ::engine::ecs::Entity entity;
    ::engine::ecs::entity::Reference ref{ components, entity };

    ref.addComponent<::engine::ecs::component::Movable>();
    auto signature{ ::engine::ecs::Signature::generate<::engine::ecs::component::Movable>() };

    BOOST_TEST((entity.getSignature() == signature));
    BOOST_TEST((ref.getSignature() == signature));
    BOOST_TEST((ref.getSignature() == entity.getSignature()));
    BOOST_TEST((&ref.getSignature() == &entity.getSignature()));
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Signature
BOOST_AUTO_TEST_SUITE(ID)



BOOST_AUTO_TEST_CASE(incrementation)
{
    ::engine::ecs::component::Container components;
    ::engine::ecs::Entity entity;
    ::engine::ecs::entity::Reference ref{components, entity};

    BOOST_TEST(entity.getID() == ref.getID());
}



BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
