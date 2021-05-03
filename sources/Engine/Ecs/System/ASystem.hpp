#pragma once

#include <Engine/Ecs/Component/Container.hpp>
#include <Engine/Ecs/Entity/Container.hpp>



namespace engine::ecs::system {



class ASystem {

public:

    // ------------------------------------------------------------------ *structors

    ASystem();

    virtual ~ASystem() = 0;



    // ------------------------------------------------------------------ Run

    virtual void run(
        ::engine::ecs::entity::Container& entities,
        ::engine::ecs::component::Container& components
    ) = 0;



private:

};



} // namespace engine::ecs::system
