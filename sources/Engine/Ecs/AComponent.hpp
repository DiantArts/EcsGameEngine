#pragma once

#include <Engine/Ecs/Component/AComponent.hpp>

namespace engine::ecs {
    template <
        typename ComponentTypes
    > using AComponent = ::engine::ecs::component::AComponent<ComponentTypes>;
}
