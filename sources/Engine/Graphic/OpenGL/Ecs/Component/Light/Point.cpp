#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Light/Point.hpp>
#include <Engine/Graphic/OpenGL/Ecs/Component/Transformable.hpp>
#include <Engine/Graphic/OpenGL/Ubo.hpp>
#include <nbLights.hpp>
#include <Engine/Graphic/OpenGL/Shader.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::ecs::component::light::Point::Point() = default;

::engine::graphic::opengl::ecs::component::light::Point::Point(
    const ::glm::vec3& color
)
    : m_parameters{ color }
{}

::engine::graphic::opengl::ecs::component::light::Point::Point(
    Point::Parameters parameters
)
    : m_parameters{ ::std::move(parameters) }
{}

::engine::graphic::opengl::ecs::component::light::Point::~Point() = default;



// ------------------------------------------------------------------ Move sementic

::engine::graphic::opengl::ecs::component::light::Point::Point(
    Point&&
) noexcept = default;

auto ::engine::graphic::opengl::ecs::component::light::Point::operator=(
    Point&&
) noexcept
    -> Point& = default;



// ------------------------------------------------------------------ Ubo

void ::engine::graphic::opengl::ecs::component::light::Point::setIntoUbo(
    ::std::size_t& offset,
    const ::engine::graphic::opengl::ecs::component::Transformable& transformation
) const
{
    ::engine::graphic::opengl::Ubo::setSubData(offset, transformation.getPosition());
    offset += sizeof(::glm::vec4);
    ::engine::graphic::opengl::Ubo::setSubData(offset, m_parameters.color);
    offset += sizeof(::glm::vec4);
    ::engine::graphic::opengl::Ubo::setSubData(offset, m_parameters.ambient);
    offset += sizeof(::glm::vec4);
    ::engine::graphic::opengl::Ubo::setSubData(offset, m_parameters.diffuse);
    offset += sizeof(::glm::vec4);
    ::engine::graphic::opengl::Ubo::setSubData(offset, m_parameters.specular);
    offset += sizeof(::glm::vec4);
    ::engine::graphic::opengl::Ubo::setSubData(offset, m_parameters.constant);
    offset += sizeof(float);
    ::engine::graphic::opengl::Ubo::setSubData(offset, m_parameters.linear);
    offset += sizeof(float);
    ::engine::graphic::opengl::Ubo::setSubData(offset, m_parameters.quadratic);
    offset += sizeof(float);
    offset += sizeof(float); // float alignment
}

void ::engine::graphic::opengl::ecs::component::light::Point::setIntoShader(
    ::engine::graphic::opengl::Shader& shader,
    const ::std::string& lightName,
    const ::glm::vec3& position
) const
{
    shader.use();
    shader.set(lightName + ".position", ::glm::vec4(position, 0));
    shader.set(lightName + ".ambient", ::glm::vec4(m_parameters.ambient, 0));
    shader.set(lightName + ".diffuse", ::glm::vec4(m_parameters.diffuse, 0));
    shader.set(lightName + ".specular", ::glm::vec4(m_parameters.specular, 0));
    shader.set(lightName + ".constant", m_parameters.constant);
    shader.set(lightName + ".linear", m_parameters.linear);
    shader.set(lightName + ".quadratic", m_parameters.quadratic);
}
