#pragma once

namespace engine::core::ecs::entity { class Entity; }
namespace engine::core { class Time; }



namespace engine::core::ecs::detail::signature {



template <
    typename... ComponentTypes
> struct Generate;



template <
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> struct Generate <
    ComponentTypes...
> {
    static constexpr auto get()
        -> ::engine::core::ecs::Signature
    {
        ::cbitset::Cbitset<::engine::core::ecs::component::maxID> signature;

        for (::std::size_t i{ 0 }; i < ::engine::core::ecs::component::maxID; i++) {
            ::engine::core::detail::meta::ForEach<ComponentTypes...>::template run<
                []<
                    ::engine::core::ecs::component::ConceptType RawComponentType
                >(
                    ::cbitset::Cbitset<::engine::core::ecs::component::maxID>& signature,
                    int i
                ){
                    using ComponentType =::std::remove_reference_t<RawComponentType>;
                    if (ComponentType::getID() == i) {
                        signature.set(i);
                    }
                }
            >(signature, i);
        }

        return Signature{ signature };
    }

    static constexpr auto value{ Generate<ComponentTypes...>::get() };
};



template <
    typename Type
> concept EntityConceptType =
    ::std::is_same<
        ::engine::core::ecs::entity::Entity,
        ::std::remove_cvref_t<Type>
    >::value;

template <
    ::engine::core::ecs::detail::signature::EntityConceptType EntityType,
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> struct Generate <
    EntityType,
    ComponentTypes...
> {
    static constexpr auto get()
        -> ::engine::core::ecs::Signature
    {
        return ::engine::core::ecs::detail::signature::Generate<ComponentTypes...>::get();
    }

    static constexpr auto value{ Generate<ComponentTypes...>::get() };
};



template <
    typename Type
> concept TimeConceptType =
    ::std::is_same<
        ::engine::core::Time,
        ::std::remove_cvref_t<Type>
    >::value;

template <
    ::engine::core::ecs::detail::signature::TimeConceptType TimeType,
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> struct Generate <
    TimeType,
    ComponentTypes...
> {
    static constexpr auto get()
        -> ::engine::core::ecs::Signature
    {
        return ::engine::core::ecs::detail::signature::Generate<ComponentTypes...>::get();
    }

    static constexpr auto value{
        ::engine::core::ecs::detail::signature::Generate<ComponentTypes...>::get()
    };
};

template <
    ::engine::core::ecs::detail::signature::TimeConceptType TimeType,
    ::engine::core::ecs::detail::signature::EntityConceptType EntityType,
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> struct Generate <
    TimeType,
    EntityType,
    ComponentTypes...
> {
    static constexpr auto get()
        -> ::engine::core::ecs::Signature
    {
        return ::engine::core::ecs::detail::signature::Generate<ComponentTypes...>::get();
    }

    static constexpr auto value{
        ::engine::core::ecs::detail::signature::Generate<ComponentTypes...>::get()
    };
};

template <
    ::engine::core::ecs::detail::signature::EntityConceptType EntityType,
    ::engine::core::ecs::detail::signature::TimeConceptType TimeType,
    ::engine::core::ecs::component::ConceptType... ComponentTypes
> struct Generate <
    EntityType,
    TimeType,
    ComponentTypes...
> {
    static constexpr auto get()
        -> ::engine::core::ecs::Signature
    {
        return ::engine::core::ecs::detail::signature::Generate<ComponentTypes...>::get();
    }

    static constexpr auto value{
        ::engine::core::ecs::detail::signature::Generate<ComponentTypes...>::get()
    };
};



} // namespace engine::core::ecs::system
