#pragma once

#include <Engine/Core/Ecs/Component/Container.hpp>
#include <Engine/Core/Ecs/Entity/Container.hpp>



namespace engine::core::ecs::system {



class ASystem {

public:

    // ------------------------------------------------------------------ *structors

    ASystem();

    virtual ~ASystem() = 0;



    // ------------------------------------------------------------------ Run

    virtual void run(
        ::engine::core::ecs::entity::Container& entities,
        ::engine::core::ecs::component::Container& components
    ) = 0;

    // virtual void run(
        // const ::engine::core::ecs::entity::Container& entities,
        // const ::engine::core::ecs::component::Container& components
    // ) const = 0;



private:

};



} // namespace engine::core::ecs::system
