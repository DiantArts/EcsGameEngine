#pragma once

#include <Engine/Ecs/System/System.hpp>

namespace engine::ecs {
    template <
        ::engine::ecs::component::ConceptType... ComponentTypes
    > using System = ::engine::ecs::system::System<ComponentTypes...>;
}
