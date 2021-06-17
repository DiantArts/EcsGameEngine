#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>



namespace engine::graphic::opengl::ecs::component::light {



class Spot
    : public ::engine::core::ecs::AComponent<engine::graphic::opengl::ecs::component::light::Spot>
{

public:

    struct Parameters {

        ::glm::vec3 direction;

        ::glm::vec3 ambient{ 0.5F };
        ::glm::vec3 diffuse{ 0.3F };
        ::glm::vec3 specular{ 1.0F };

        float constant{ 0.3F };
        float linear{ 0.3F };
        float quadratic{ 0.016F };

        float cutOff{ ::glm::cos(glm::radians(12.5F)) };
        float outerCutOff{ ::glm::cos(glm::radians(15.0F)) };

        glm::vec3 color { 1.0F, 1.0F, 1.0F };

    };



public:

    // ------------------------------------------------------------------ *structors

    Spot();

    Spot(
        ::glm::vec3 direction
    );

    Spot(
        float cutOff,
        float outerCutOff
    );

    Spot(
        ::glm::vec3 direction,
        float cutOff,
        float outerCutOff
    );

    Spot(
        const Spot::Parameters& parameters
    );

    Spot(
        Spot::Parameters&& parameters
    );

    ~Spot();



    // ------------------------------------------------------------------ Copy sementic

    Spot(
        const Spot&
    ) noexcept = delete;

    auto operator=(
        const Spot&
    ) noexcept
        -> Spot& = delete;



    // ------------------------------------------------------------------ Move sementic

    Spot(
        Spot&&
    ) noexcept;

    auto operator=(
        Spot&&
    ) noexcept
        -> Spot&;



    // ------------------------------------------------------------------ Ubo

    void setIntoUbo(
        ::std::size_t& offset
    ) const;



private:

    ::std::string m_name;

    Spot::Parameters m_parameters;

};



} // namespace engine::graphic::opengl::ecs::component::light
