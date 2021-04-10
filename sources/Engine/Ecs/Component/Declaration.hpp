#pragma once

#include <Engine/Ecs/Component/Detail/Declaration.hpp>



START_COMPONENT_DECLARATIONS();



DECLARE_COMPONENT_IN_NAMESPACE(engine::ecs::component, Movable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::ecs::component, Drawable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::ecs::component, Controllable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::ecs::component, Transformable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::ecs::component, Attackable);



STOP_COMPONENT_DECLARATIONS();
