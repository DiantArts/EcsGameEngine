#pragma once

#include <Engine/Core/Ecs/AComponent.hpp>

namespace engine::graphic::opengl { class Shader; }



namespace engine::graphic::opengl::ecs::component::light {



class Point
    : public ::engine::core::ecs::AComponent<engine::graphic::opengl::ecs::component::light::Point>
{

public:

    struct Parameters {

        static inline constexpr size_t sizetype{ 5 * sizeof(::glm::vec4) + 4 * sizeof(float) };

        ::glm::vec3 color{ 1.0F };

        ::glm::vec3 ambient{ 0.05F };
        ::glm::vec3 diffuse{ 0.8F };
        ::glm::vec3 specular{ 1.0F };

        float constant{ 1.0F };
        float linear{ 0.09F };
        float quadratic{ 0.032F };

    };



public:

    // ------------------------------------------------------------------ *structors

    Point();

    Point(
        const ::glm::vec3& color
    );

    Point(
        Point::Parameters parameters
    );

    ~Point();



    // ------------------------------------------------------------------ Copy sementic

    Point(
        const Point&
    ) noexcept = delete;

    auto operator=(
        const Point&
    ) noexcept
        -> Point& = delete;



    // ------------------------------------------------------------------ Move sementic

    Point(
        Point&&
    ) noexcept;

    auto operator=(
        Point&&
    ) noexcept
        -> Point&;



    // ------------------------------------------------------------------ Ubo

    void setIntoUbo(
        ::std::size_t& offset
    ) const;

    void setIntoShader(
        ::engine::graphic::opengl::Shader& shader,
        const ::std::string& lightName,
        const ::glm::vec3& position
    ) const;



private:

    Point::Parameters m_parameters;

};



} // namespace engine::graphic::opengl::ecs::component::light
