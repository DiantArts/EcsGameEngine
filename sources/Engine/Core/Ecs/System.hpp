#pragma once

#include <Engine/Core/Ecs/System/System.hpp>



namespace engine::core::ecs {
    template <
        auto function,
        ::engine::core::ecs::component::ConceptType... BanishedComponentTypes
    > using System = ::engine::core::ecs::system::System<function, BanishedComponentTypes...>;
}
