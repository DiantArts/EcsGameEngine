#pragma once

#include <Engine/Core/Detail/Meta/ForEach.hpp>



// ------------------------------------------------------------------ ID

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> constexpr auto ::engine::core::ecs::component::Container::getID() const
    -> ::engine::core::ID
{
    using ComponentType = ::std::remove_cvref_t<RawComponentType>;
    return ComponentType::getID();
}

constexpr auto ::engine::core::ecs::component::Container::getMaxID()
    -> ::engine::core::ID
{
    return ::engine::core::ecs::component::maxID;
}



// ------------------------------------------------------------------ Emplace/Remove

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> auto ::engine::core::ecs::component::Container::emplace(
    ::engine::core::ID entityID,
    auto&&... args
)
    -> RawComponentType&
{
    using ComponentType = ::std::remove_cvref_t<RawComponentType>;
    auto& pairComponentContainer{ this->getPairSubContainer<ComponentType>() };
    auto it{ ::std::ranges::find(pairComponentContainer.first, entityID) };
    if (it != pairComponentContainer.first.end()) {
        throw ::std::runtime_error(
            "Entity '"s + static_cast<::std::string>(entityID) + "' already contain an '"s +
                boost::typeindex::type_id<ComponentType>().pretty_name() + "' component"
        );
    }
    pairComponentContainer.first.push_back(::std::move(entityID));
    return (*static_cast<Container::SubContainerType<ComponentType>*>(pairComponentContainer.second)).
        emplace_back(std::forward<decltype(args)>(args)...);
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> void ::engine::core::ecs::component::Container::emplaceMany(
    ::engine::core::ID entityID
)
{
    (this->emplace<ComponentTypes>(entityID), ...);
}


template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> void ::engine::core::ecs::component::Container::remove(
    ::engine::core::ID entityID
)
{
    using ComponentType = ::std::remove_cvref_t<RawComponentType>;
    auto& pairComponentContainer{ this->getPairSubContainer<ComponentType>() };
    auto it{ ::std::ranges::find(pairComponentContainer.first, entityID) };
    if (it == pairComponentContainer.first.end()) {
        throw ::std::runtime_error(
            "Entity '"s + static_cast<::std::string>(entityID) + "' doesn't contain an '"s +
                boost::typeindex::type_id<ComponentType>().pretty_name() + "' component"
        );
    }
    pairComponentContainer.first.erase(it);
}

template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> void ::engine::core::ecs::component::Container::removeMany(
    ::engine::core::ID entityID
)
{
    (this->remove<ComponentTypes>(entityID), ...);
}



// ------------------------------------------------------------------ Get

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> auto ::engine::core::ecs::component::Container::get(
    ::engine::core::ID entityID
) const
    -> const RawComponentType&
{
    using ComponentType = ::std::remove_cvref_t<RawComponentType>;
    auto& pairComponentContainer{ this->getPairSubContainer<ComponentType>() };
    auto it{ ::std::ranges::find(pairComponentContainer.first, entityID) };
    if (it == pairComponentContainer.first.end()) {
        throw ::std::runtime_error(
            "Entity '"s + static_cast<::std::string>(entityID) + "' doesn't contain an '"s +
                boost::typeindex::type_id<ComponentType>().pretty_name() + "' component"
        );
    }
    return (*static_cast<Container::SubContainerType<ComponentType>*>(pairComponentContainer.second)).at(
        it - pairComponentContainer.first.begin()
    );
}

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> auto ::engine::core::ecs::component::Container::get(
    ::engine::core::ID entityID
)
    -> RawComponentType&
{
    using ComponentType = ::std::remove_cvref_t<RawComponentType>;
    auto& pairComponentContainer{ this->getPairSubContainer<ComponentType>() };
    auto it{ ::std::ranges::find(pairComponentContainer.first, entityID) };
    if (it == pairComponentContainer.first.end()) {
        throw ::std::runtime_error(
            "Entity '"s + static_cast<::std::string>(entityID) + "' doesn't contain an '"s +
                boost::typeindex::type_id<ComponentType>().pretty_name() + "' component"
        );
    }
    return (*static_cast<Container::SubContainerType<ComponentType>*>(pairComponentContainer.second)).at(
        it - pairComponentContainer.first.begin()
    );
}

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> auto ::engine::core::ecs::component::Container::getIndex(
    ::engine::core::ID entityID
) const
    -> ::std::size_t
{
    using ComponentType = ::std::remove_cvref_t<RawComponentType>;
    auto& IDContainer{ this->getPairSubContainer<ComponentType>().first };
    auto it{ ::std::ranges::find(IDContainer, entityID) };
    if (it == IDContainer.end()) {
        throw ::std::runtime_error(
            "Entity '"s + static_cast<::std::string>(entityID) + "' doesn't contain an '"s +
                boost::typeindex::type_id<ComponentType>().pretty_name() + "' component"
        );
    }
    return it - IDContainer.begin();
}

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> auto ::engine::core::ecs::component::Container::exists(
    ::engine::core::ID entityID
) const
    -> bool
{
    using ComponentType = ::std::remove_cvref_t<RawComponentType>;
    auto it{ m_container.find(ComponentType::getID()) };
    if (it == m_container.end()) {
        return false;
    }
    return ::std::ranges::find(it->second.first, entityID) != it->second.first.end();
}



// ------------------------------------------------------------------ Private

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> auto ::engine::core::ecs::component::Container::getPairSubContainer()
    -> SubPairContainerType&
{
    using ComponentType = ::std::remove_cvref_t<RawComponentType>;

    return m_container.try_emplace(
        ComponentType::getID(),
        ::std::make_pair<::std::vector<::engine::core::ID>, void*>(
            ::std::vector<::engine::core::ID>{},
            new ::std::vector<ComponentType>{}
        )
    ).first->second;
}

template <
    ::engine::core::ecs::component::ConceptType RawComponentType
> auto ::engine::core::ecs::component::Container::getPairSubContainer() const
    -> const SubPairContainerType&
{
    using ComponentType = ::std::remove_cvref_t<RawComponentType>;
    return m_container.at(ComponentType::getID());
}
