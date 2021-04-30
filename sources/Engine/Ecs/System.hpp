#pragma once

#include <Engine/Ecs/System/System.hpp>



namespace engine::ecs {
    template <
        auto function
    > using System = ::engine::ecs::system::System<function>;
}
