#pragma once

#include <Engine/Ecs/System.hpp>
#include <Engine/Ecs/Component/Container.hpp>
#include <Engine/Ecs/Entity/Container.hpp>



namespace engine::ecs::system {



class Container {

public:

    // ------------------------------------------------------------------ *structors

    Container();

    ~Container();



    // ------------------------------------------------------------------ Run

    void run(
        ::engine::ecs::entity::Container& entities,
        ::engine::ecs::component::Container& components
    );



    // ------------------------------------------------------------------ Vectors

    template <
        auto func
    > void emplace();



private:

    ::std::vector<::std::unique_ptr<::engine::ecs::system::ASystem>> m_systems;

};



} // namespace engine::ecs::system

#include <Engine/Ecs/System/Container.impl.hpp>
