#pragma once

#include <boost/type_index.hpp>



// ------------------------------------------------------------------ Genetate

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> [[ nodiscard ]] constexpr auto ::engine::ecs::component::Container::generate()
    -> ::engine::ecs::component::Container
{
    ::engine::ecs::component::Container components;
    components.constructSubContainer<ComponentTypes...>();
    return components;
}



// ------------------------------------------------------------------ Construct

// TODO: Unique Types
template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> requires
    ::engine::detail::meta::UniqueTypes<ComponentTypes...>::value
void ::engine::ecs::component::Container::constructSubContainer()
{
    ::engine::detail::meta::ForEach<ComponentTypes...>::template run<
        []<
            ::engine::ecs::component::ConceptType ComponentType
        >(
            ::engine::ecs::component::Container::Type& container
        ){
            if (container.find(ComponentType::getID()) != container.end()) {
                throw ::std::runtime_error(
                    "Container already contain an '"s +
                        boost::typeindex::type_id<ComponentType>().pretty_name() + "' sub container"
                );
            }
            container.emplace(
                ComponentType::getID(),
                ::std::make_pair<::std::vector<::engine::ID>, void*>(
                    ::std::vector<::engine::ID>{},
                    new ::std::vector<ComponentType>{}
                )
            );
        }
    >(m_container);
}

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::getSubContainer() const
    -> const Container::SubContainerType<ComponentType>&
{
    return *static_cast<Container::SubContainerType<ComponentType>*>(
        m_container.at(ComponentType::getID()).second
    );
}



// ------------------------------------------------------------------ ID

template <
    ::engine::ecs::component::ConceptType ComponentType
> constexpr auto ::engine::ecs::component::Container::getID() const
    -> ::engine::ID
{
    return ComponentType::getID();
}

constexpr auto ::engine::ecs::component::Container::getMaxID()
    -> ::engine::ID
{
    return ::engine::ecs::component::maxID;
}



// ------------------------------------------------------------------ Emplace/Remove

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::emplace(
    ::engine::ID entityID,
    auto&&... args
)
    -> ComponentType&
{
    auto& pairComponentContainer{ this->getPairSubContainer<ComponentType>() };
    auto it { ::std::ranges::find(pairComponentContainer.first, entityID) };
    if (it != pairComponentContainer.first.end()) {
        throw ::std::runtime_error(
            "Entity '"s + static_cast<::std::string>(entityID) + "' already contain an '"s +
                boost::typeindex::type_id<ComponentType>().pretty_name() + "' component"
        );
    }
    pairComponentContainer.first.push_back(entityID);
    return (*static_cast<Container::SubContainerType<ComponentType>*>(pairComponentContainer.second)).
        emplace_back(std::forward<decltype(args)>(args)...);
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::component::Container::emplaceMany(
    ::engine::ID entityID
)
{
    (this->emplace<ComponentTypes>(entityID), ...);
}


template <
    ::engine::ecs::component::ConceptType ComponentType
> void ::engine::ecs::component::Container::remove(
    ::engine::ID entityID
)
{
    auto& pairComponentContainer{ this->getPairSubContainer<ComponentType>() };
    auto it { ::std::ranges::find(pairComponentContainer.first, entityID) };
    if (it == pairComponentContainer.first.end()) {
        throw ::std::runtime_error(
            "Entity '"s + static_cast<::std::string>(entityID) + "' doesn't contain an '"s +
                boost::typeindex::type_id<ComponentType>().pretty_name() + "' component"
        );
    }
    pairComponentContainer.first.erase(it);
}

template <
    ::engine::ecs::component::ConceptType... ComponentTypes
> void ::engine::ecs::component::Container::removeMany(
    ::engine::ID entityID
)
{
    (this->remove<ComponentTypes>(entityID), ...);
}



// ------------------------------------------------------------------ Get

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::get(
    ::engine::ID entityID
) const
    -> const ComponentType&
{
    auto& pairComponentContainer{ this->getPairSubContainer<ComponentType>() };
    auto it { ::std::ranges::find(pairComponentContainer.first, entityID) };
    if (it == pairComponentContainer.first.end()) {
        throw ::std::runtime_error(
            "Entity '"s + static_cast<::std::string>(entityID) + "' doesn't contain an '"s +
                boost::typeindex::type_id<ComponentType>().pretty_name() + "' component"
        );
    }
    return (*static_cast<Container::SubContainerType<ComponentType>*>(pairComponentContainer.second))[
        it - pairComponentContainer.first.begin()
    ];
}

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::getIndex(
    ::engine::ID entityID
) const
    -> ::std::size_t
{
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
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::exists(
    ::engine::ID entityID
) const
    -> bool
{
    auto& IDContainer{ this->getPairSubContainer<ComponentType>().first };
    return ::std::ranges::find(IDContainer, entityID) != IDContainer.end();
}



// ------------------------------------------------------------------ Private

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::getPairSubContainer()
    -> SubPairContainerType&
{
    return m_container.at(ComponentType::getID());
}

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::getPairSubContainer() const
    -> const SubPairContainerType&
{
    return m_container.at(ComponentType::getID());
}
