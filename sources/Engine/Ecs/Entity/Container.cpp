#include <pch.hpp>
#include <Engine/Ecs/Entity/Container.hpp>


// ------------------------------------------------------------------ *structors

::engine::ecs::entity::Container::Container(
    ::engine::ecs::component::Container& components
)
    : m_components{ components }
{}

::engine::ecs::entity::Container::~Container() = default;



// ------------------------------------------------------------------ Remove

void ::engine::ecs::entity::Container::remove(
    ::engine::ID entityID
)
{
    m_entities.erase(::std::ranges::find_if(m_entities,
        [
            entityID{ ::std::move(entityID) }
        ](
            const ::engine::ecs::Entity& entity
        ){
            return entity.getID() == entityID;
        }
    ));
}

void ::engine::ecs::entity::Container::remove(
    ::engine::ecs::entity::Reference&& reference
)
{
    m_entities.erase(::std::ranges::find_if(m_entities,
        [
            reference{ ::std::move(reference) }
        ](
            const ::engine::ecs::Entity& entity
        ){
            return &entity == &reference.get();
        }
    ));
}



// ------------------------------------------------------------------ Get

[[ nodiscard ]] auto ::engine::ecs::entity::Container::operator[](
    ::engine::ID entityID
) const
    -> ::engine::ecs::entity::ConstReference
{
    auto it{ ::std::ranges::find_if(m_entities,
        [entityID](const ::engine::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) };
    if (it == m_entities.end()) {
        throw ::std::runtime_error("Entity '"s + static_cast<::std::string>(entityID) +
                "' inst't present in the EntityContainer");
    }
    return ::engine::ecs::entity::ConstReference{ *it };
}

[[ nodiscard ]] auto ::engine::ecs::entity::Container::operator[](
    ::engine::ID entityID
)
    -> ::engine::ecs::entity::Reference
{
    auto it{ ::std::ranges::find_if(m_entities,
        [entityID](const ::engine::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) };
    if (it == m_entities.end()) {
        throw ::std::runtime_error("Entity '"s + static_cast<::std::string>(entityID) +
                "' inst't present in the EntityContainer");
    }
    return ::engine::ecs::entity::Reference{m_components, *it };
}

[[ nodiscard ]] auto ::engine::ecs::entity::Container::get(
    ::engine::ID entityID
) const
    -> ::engine::ecs::entity::ConstReference
{
    auto it{ ::std::ranges::find_if(m_entities,
        [entityID](const ::engine::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) };
    if (it == m_entities.end()) {
        throw ::std::runtime_error("Entity '"s + static_cast<::std::string>(entityID) +
                "' inst't present in the EntityContainer");
    }
    return ::engine::ecs::entity::ConstReference{ *it };
}

[[ nodiscard ]] auto ::engine::ecs::entity::Container::unsafeGet(
    ::engine::ID entityID
)
    -> ::engine::ecs::entity::Reference
{
    return ::engine::ecs::entity::Reference{ m_components, *::std::ranges::find_if(m_entities,
        [entityID](const ::engine::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) };
}

[[ nodiscard ]] auto ::engine::ecs::entity::Container::unsafeGet(
    ::engine::ID entityID
) const
    -> ::engine::ecs::entity::ConstReference
{
    return ::engine::ecs::entity::ConstReference{ *::std::ranges::find_if(m_entities,
        [entityID](const ::engine::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) };
}



// ------------------------------------------------------------------ Contains

[[ nodiscard ]] auto ::engine::ecs::entity::Container::contains(
    ::engine::ID entityID
) const
    -> bool
{
    return ::std::ranges::find_if(m_entities,
        [entityID](const ::engine::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) != m_entities.end();
}
