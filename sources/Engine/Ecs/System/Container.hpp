#pragma once

#include <Engine/Ecs/System.hpp>



namespace engine::ecs::system {



class Container {

public:

    // ------------------------------------------------------------------ *structors

    Container();

    ~Container();



    // ------------------------------------------------------------------ Vectors



private:

    ::std::vector<int> m_systems;

};



} // namespace engine::ecs::system
