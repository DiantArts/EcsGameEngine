#pragma once

namespace engine::core::ecs::component::detail {



template <
    ::engine::core::ecs::component::ConceptType... RestComponentTypes
> class PushMany;



template <
    ::engine::core::ecs::component::ConceptType ComponentType,
    ::engine::core::ecs::component::ConceptType... RestComponentTypes
> class PushMany<ComponentType, RestComponentTypes...>{

public:

    static void use(
        ::engine::core::ecs::component::Container& components,
        ::engine::core::ID entityID,
        ComponentType&& componentsArgs,
        RestComponentTypes&&... restComponentsArgs
    )
    {
        components.push<ComponentType>(entityID, ::std::move(componentsArgs));
        ::engine::core::ecs::component::detail::PushMany<RestComponentTypes...>::use(
            components,
            entityID,
            ::std::forward<RestComponentTypes>(restComponentsArgs)...
        );
    }
};



template <
    ::engine::core::ecs::component::ConceptType ComponentType
> class PushMany<ComponentType>{

public:

    static void use(
        ::engine::core::ecs::component::Container& components,
        ::engine::core::ID entityID,
        ComponentType&& componentsArgs
    )
    {
        components.push<ComponentType>(entityID, ::std::move(componentsArgs));
    }
};



} // namespace engine::core::ecs::component::detail
