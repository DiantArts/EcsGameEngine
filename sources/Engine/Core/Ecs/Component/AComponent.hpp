#pragma once

#include <Engine/Core/ID.hpp>
#include <Engine/Core/Ecs/Component/Declaration.hpp>
#include <Engine/Core/Detail/Meta/IsBaseOfTemplate.hpp>



namespace engine::core::ecs::component {




template <
    typename ComponentType
> class AComponent
    : public engine::core::ecs::component::declaration::detail::WithID<::std::remove_cvref_t<ComponentType>>
{

public:

    // ------------------------------------------------------------------ *structors

    explicit AComponent();

    virtual ~AComponent() = 0;



private:

};



template <
    typename Type
> concept ConceptType =
    ::engine::core::detail::meta::IsBaseOfTemplate<
        ::engine::core::ecs::component::AComponent,
        ::std::remove_cvref_t<Type>
    >::value;



static constexpr ::engine::core::ID maxID { ::engine::core::ecs::component::declaration::detail::numberOfIDs };



} // namespace engine::core::ecs::component

#include <Engine/Core/Ecs/Component/AComponent.impl.hpp>
