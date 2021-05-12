#pragma once

#include <Engine/Core/Ecs/System.hpp>
#include <Engine/Core/Ecs/Component/Container.hpp>
#include <Engine/Core/Ecs/Entity/Container.hpp>



namespace engine::core::ecs::system {



class Container {

public:

    // ------------------------------------------------------------------ *structors

    Container();

    ~Container();



    // ------------------------------------------------------------------ Run

    void run(
        ::engine::core::ecs::entity::Container& entities,
        ::engine::core::ecs::component::Container& components
    );

    // void run(
        // const ::engine::core::ecs::entity::Container& entities,
        // const ::engine::core::ecs::component::Container& components
    // ) const;



    // ------------------------------------------------------------------ Vectors

    template <
        auto func
    > void emplace();



private:

    ::std::vector<::std::unique_ptr<::engine::core::ecs::system::ASystem>> m_systems;

};



} // namespace engine::core::ecs::system

#include <Engine/Core/Ecs/System/Container.impl.hpp>
