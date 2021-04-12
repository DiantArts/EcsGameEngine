#pragma once

#include <boost/type_index.hpp>



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
                ::std::make_pair<Container::SubIDContainerType, Container::SubContainerPointerType>(
                        Container::SubIDContainerType{},
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
> constexpr auto ::engine::ecs::component::Container::getComponentID() const
    -> Container::ComponentID
{
    return ComponentType::getID();
}

constexpr auto ::engine::ecs::component::Container::getMaxComponentID()
    -> Container::ComponentID
{
    return ::engine::ecs::component::maxID;
}



// ------------------------------------------------------------------ Component

template <
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::emplaceComponent(
    Container::EntityID entityID,
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
    ::engine::ecs::component::ConceptType ComponentType
> auto ::engine::ecs::component::Container::getComponent(
    Container::EntityID entityID
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
> auto ::engine::ecs::component::Container::getComponentIndex(
    Container::EntityID entityID
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
> auto ::engine::ecs::component::Container::componentExists(
    Container::EntityID entityID
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
