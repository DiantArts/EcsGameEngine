#pragma once

#include <Engine/Core/Ecs/Component/AComponent.hpp>



namespace engine::core::ecs {
    template <
        typename ComponentTypes
    > using AComponent = ::engine::core::ecs::component::AComponent<ComponentTypes>;
}
