#pragma once

#include <Engine/Core/Ecs/Component/Detail/Declaration.hpp>



START_COMPONENT_DECLARATIONS();



DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component, Movable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component, Drawable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component, Controllable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component, Transformable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component, Attackable);



STOP_COMPONENT_DECLARATIONS();
