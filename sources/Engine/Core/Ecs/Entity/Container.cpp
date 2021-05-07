#include <pch.hpp>
#include <Engine/Core/Ecs/Entity/Container.hpp>


// ------------------------------------------------------------------ *structors

::engine::core::ecs::entity::Container::Container(
    ::engine::core::ecs::component::Container& components
)
    : m_components{ components }
{}

::engine::core::ecs::entity::Container::~Container() = default;



// ------------------------------------------------------------------ Remove

void ::engine::core::ecs::entity::Container::remove(
    ::engine::core::ID entityID
)
{
    m_entities.erase(::std::ranges::find_if(m_entities,
        [
            entityID{ ::std::move(entityID) }
        ](
            const ::engine::core::ecs::Entity& entity
        ){
            return entity.getID() == entityID;
        }
    ));
}

void ::engine::core::ecs::entity::Container::remove(
    ::engine::core::ecs::entity::Reference&& reference
)
{
    m_entities.erase(::std::ranges::find_if(m_entities,
        [
            reference{ ::std::move(reference) }
        ](
            const ::engine::core::ecs::Entity& entity
        ){
            return &entity == &reference.get();
        }
    ));
}



// ------------------------------------------------------------------ Get

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::operator[](
    ::engine::core::ID entityID
) const
    -> ::engine::core::ecs::entity::ConstReference
{
    auto it{ ::std::ranges::find_if(m_entities,
        [entityID](const ::engine::core::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) };
    if (it == m_entities.end()) {
        throw ::std::runtime_error("Entity '"s + static_cast<::std::string>(entityID) +
                "' inst't present in the EntityContainer");
    }
    return ::engine::core::ecs::entity::ConstReference{ *it };
}

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::operator[](
    ::engine::core::ID entityID
)
    -> ::engine::core::ecs::entity::Reference
{
    auto it{ ::std::ranges::find_if(m_entities,
        [entityID](const ::engine::core::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) };
    if (it == m_entities.end()) {
        throw ::std::runtime_error("Entity '"s + static_cast<::std::string>(entityID) +
                "' inst't present in the EntityContainer");
    }
    return ::engine::core::ecs::entity::Reference{m_components, *it };
}

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::get(
    ::engine::core::ID entityID
) const
    -> ::engine::core::ecs::entity::ConstReference
{
    auto it{ ::std::ranges::find_if(m_entities,
        [entityID](const ::engine::core::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) };
    if (it == m_entities.end()) {
        throw ::std::runtime_error("Entity '"s + static_cast<::std::string>(entityID) +
                "' inst't present in the EntityContainer");
    }
    return ::engine::core::ecs::entity::ConstReference{ *it };
}

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::unsafeGet(
    ::engine::core::ID entityID
)
    -> ::engine::core::ecs::entity::Reference
{
    return ::engine::core::ecs::entity::Reference{ m_components, *::std::ranges::find_if(m_entities,
        [entityID](const ::engine::core::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) };
}

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::unsafeGet(
    ::engine::core::ID entityID
) const
    -> ::engine::core::ecs::entity::ConstReference
{
    return ::engine::core::ecs::entity::ConstReference{ *::std::ranges::find_if(m_entities,
        [entityID](const ::engine::core::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) };
}



// ------------------------------------------------------------------ Contains

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::contains(
    ::engine::core::ID entityID
) const
    -> bool
{
    return ::std::ranges::find_if(m_entities,
        [entityID](const ::engine::core::ecs::Entity& entity){
            return entity.getID() == entityID;
        }
    ) != m_entities.end();
}



// ------------------------------------------------------------------ Iterator

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::begin()
    -> Container::Type::iterator
{
    return m_entities.begin();
}

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::begin() const
    -> Container::Type::const_iterator
{
    return m_entities.begin();
}

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::cbegin() const
    -> Container::Type::const_iterator
{
    return m_entities.cbegin();
}

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::end()
    -> Container::Type::iterator
{
    return m_entities.end();
}

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::end() const
    -> Container::Type::const_iterator
{
    return m_entities.end();
}

[[ nodiscard ]] auto ::engine::core::ecs::entity::Container::cend() const
    -> Container::Type::const_iterator
{
    return m_entities.cend();
}
