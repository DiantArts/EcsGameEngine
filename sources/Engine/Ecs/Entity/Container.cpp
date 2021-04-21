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
            return &entity == &static_cast<const engine::ecs::Entity&>(reference);
        }
    ));
}



// ------------------------------------------------------------------ Get

[[ nodiscard ]] auto ::engine::ecs::entity::Container::operator[](
    ::engine::ID entityID
) const
    -> const ::engine::ecs::Entity&
{
    return m_entities[entityID];
}

[[ nodiscard ]] auto ::engine::ecs::entity::Container::operator[](
    ::engine::ID entityID
)
    -> ::engine::ecs::entity::Reference
{
    return ::engine::ecs::entity::Reference{m_components, m_entities[entityID] };
}

[[ nodiscard ]] auto ::engine::ecs::entity::Container::get(
    ::engine::ID entityID
) const
    -> const ::engine::ecs::Entity&
{
    return m_entities[entityID];
}
