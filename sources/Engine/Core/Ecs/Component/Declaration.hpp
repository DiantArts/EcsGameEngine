#pragma once

#include <Engine/Core/Ecs/Component/Detail/Declaration.hpp>



START_COMPONENT_DECLARATIONS();



#ifdef TEST
DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component::test, Movable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component::test, Transformable);
#endif

DECLARE_COMPONENT_IN_NAMESPACE(engine::graphic::ecs::component, Drawable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component, Movable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component, Controllable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component, Transformable);
DECLARE_COMPONENT_IN_NAMESPACE(engine::core::ecs::component, Attackable);



STOP_COMPONENT_DECLARATIONS();
