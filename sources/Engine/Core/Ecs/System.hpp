#pragma once

#include <Engine/Core/Ecs/System/System.hpp>



namespace engine::core::ecs {
    template <
        auto function
    > using System = ::engine::core::ecs::system::System<function>;
}
