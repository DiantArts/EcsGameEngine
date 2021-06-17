#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>



namespace engine::graphic::opengl::ecs::component::light {



class Directional
    : public ::engine::core::ecs::AComponent<engine::graphic::opengl::ecs::component::light::Directional>
{

public:

    struct Parameters {

        ::glm::vec3 direction;

        ::glm::vec3 ambient{ 0.5F };
        ::glm::vec3 diffuse{ 0.3F };
        ::glm::vec3 specular{ 1.0F };

        ::glm::vec3 color{ 1.0F, 1.0F, 1.0F };

    };



public:

    // ------------------------------------------------------------------ *structors

    Directional();

    Directional(
        ::glm::vec3 direction
    );

    Directional(
        Directional::Parameters parameters
    );

    ~Directional();



    // ------------------------------------------------------------------ Copy sementic

    Directional(
        const Directional&
    ) noexcept = delete;

    auto operator=(
        const Directional&
    ) noexcept
        -> Directional& = delete;



    // ------------------------------------------------------------------ Move sementic

    Directional(
        Directional&&
    ) noexcept;

    auto operator=(
        Directional&&
    ) noexcept
        -> Directional&;



    // ------------------------------------------------------------------ Ubo

    void setIntoUbo(
        ::std::size_t& offset
    ) const;



private:

    Directional::Parameters m_parameters;

};



} // namespace engine::graphic::opengl::ecs::component::light
