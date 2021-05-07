#include <pch.hpp>
#include <Engine/Core/Ecs/Entity/Reference.hpp>
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
BOOST_AUTO_TEST_SUITE(Referenre)



// ------------------------------------------------------------------ Component
BOOST_AUTO_TEST_SUITE(Component)



BOOST_AUTO_TEST_CASE(addNhas)
{
    auto components{ ::engine::core::ecs::component::Container::generate<::engine::core::ecs::component::Movable>() };
    ::engine::core::ecs::Entity entity;
    ::engine::core::ecs::entity::Reference ref{ components, entity };

    const auto& component{ ref.addComponent<::engine::core::ecs::component::Movable>() };

    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(ref.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Transformable>());
    BOOST_TEST(!ref.hasComponent<::engine::core::ecs::component::Transformable>());
    BOOST_TEST(&component == &components.get<::engine::core::ecs::component::Movable>(entity.getID()));
    BOOST_TEST(&component == &components.get<::engine::core::ecs::component::Movable>(ref.getID()));
}

BOOST_AUTO_TEST_CASE(removeNhas)
{
    auto components{ ::engine::core::ecs::component::Container::generate<::engine::core::ecs::component::Movable>() };
    ::engine::core::ecs::Entity entity;
    ::engine::core::ecs::entity::Reference ref{ components, entity };


    ref.addComponent<::engine::core::ecs::component::Movable>();

    BOOST_TEST(entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(ref.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(components.exists<::engine::core::ecs::component::Movable>(entity.getID()));
    BOOST_TEST(components.exists<::engine::core::ecs::component::Movable>(ref.getID()));

    ref.removeComponent<::engine::core::ecs::component::Movable>();
    BOOST_TEST(!entity.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(!ref.hasComponent<::engine::core::ecs::component::Movable>());
    BOOST_TEST(!components.exists<::engine::core::ecs::component::Movable>(entity.getID()));
    BOOST_TEST(!components.exists<::engine::core::ecs::component::Movable>(ref.getID()));
}



BOOST_AUTO_TEST_SUITE_END()
// ------------------------------------------------------------------ Signature
BOOST_AUTO_TEST_SUITE(Signature)



BOOST_AUTO_TEST_CASE(single)
{
    auto components{ ::engine::core::ecs::component::Container::generate<
        ::engine::core::ecs::component::Movable,
        ::engine::core::ecs::component::Transformable
    >() };
    ::engine::core::ecs::Entity entity;
    ::engine::core::ecs::entity::Reference ref{ components, entity };

    ref.addComponent<::engine::core::ecs::component::Movable>();
    auto signature{ ::engine::core::ecs::Signature::generate<::engine::core::ecs::component::Movable>() };

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
    ::engine::core::ecs::component::Container components;
    ::engine::core::ecs::Entity entity;
    ::engine::core::ecs::entity::Reference ref{components, entity};

    BOOST_TEST(entity.getID() == ref.getID());
}



BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
