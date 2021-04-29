#pragma once

#include <Engine/ID.hpp>
#include <Engine/Ecs/Component/Declaration.hpp>
#include <Engine/Detail/Meta/IsBaseOfTemplate.hpp>



namespace engine::ecs::component {




template <
    typename ComponentType
> class AComponent
    : public engine::ecs::component::declaration::detail::WithID<ComponentType>
{

public:

    // ------------------------------------------------------------------ *structors

    explicit AComponent();

    virtual ~AComponent() = 0;



private:

};



template <
    typename ComponentType
> concept ConceptType =
    ::engine::detail::meta::IsBaseOfTemplate<
        ::engine::ecs::component::AComponent,
        ComponentType
    >::value;



static constexpr ::engine::ID maxID { ::engine::ecs::component::declaration::detail::numberOfIDs };



} // namespace engine::ecs::component

#include <Engine/Ecs/Component/AComponent.impl.hpp>
