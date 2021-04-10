#pragma once

#include <Engine/ID.hpp>
#include <Engine/Ecs/Component/Declaration.hpp>
#include <Engine/Ecs/Component/Detail/AComponent.hpp>



namespace engine::ecs::component {




template <
    typename ComponentType
> class AComponent
    : public engine::ecs::component::declaration::detail::WithID<ComponentType>
{

public:

    using IDType = ::engine::ID;



public:

    // ------------------------------------------------------------------ *structors

    AComponent();

    virtual ~AComponent() = 0;



private:

};



template <
    typename ComponentType
> concept ConceptType =
    ::engine::ecs::component::detail::is_base_of_template_v<
        ::engine::ecs::component::AComponent,
        ComponentType
    >;



constexpr ::engine::ID maxID { ::engine::ecs::component::declaration::detail::numberOfIDs };



} // namespace engine::ecs::component

namespace engine::ecs {
    template <
        typename ComponentType
    > using AComponent = ::engine::ecs::component::AComponent<ComponentType>;
}

#include <Engine/Ecs/Component/AComponent.impl.hpp>
