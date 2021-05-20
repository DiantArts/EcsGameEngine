#include <pch.hpp>
// #include <Engine/Graphic/OpenGL/Ecs/Component/Drawable.hpp>
// #include <Engine/Graphic/OpenGL/Vertices.hpp>



// ------------------------------------------------------------------ *structors

// engine::graphic::opengl::ecs::component::Drawable::Drawable(
    // const ::std::string& shaderFilepath,
    // ::std::size_t numberOfTextures,
    // const std::function<void()>& setAttributesFunc,
    // const ::std::string& verticesFilename
// )
// {
    // this->setBlockBindingIntoShader("CameraInformations", 0);

    // m_textureVector.reserve(numberOfTexturesToReserve);

    // m_vbo.bind();
    // m_vao.bind();
    // setAttributesFunc();
    // engine::graphic::opengl::Vertices(verticesFilename, m_numberOfArrayToDraw).createBuffer();


    // m_shader.use()

    // this->addTexture("container.png", "material.diffuse");
    // this->addTexture("containerBorders.png", "material.specular");

    // this->setIntoShader("spotLight.cutOff", glm::cos(glm::radians(12.5F)));
    // this->setIntoShader("spotLight.outerCutOff", glm::cos(glm::radians(15.0F)));
    // this->setIntoShader("material.shininess", 8.0F);
// }

// engine::graphic::opengl::ecs::component::Drawable::~Drawable() = default;



// ------------------------------------------------------------------ use

// void engine::graphic::opengl::ecs::component::Drawable::operator()()
// {
    // m_shader.use()
    // this->configureShader();
    // m_vao.bind();
    // this->bindTextures();
    // for (const auto& position : this->instances) {
        // this->setIntoShader("model", this->getModel(position));
        // glDrawArrays(GL_TRIANGLES, 0, m_numberOfArrayToDraw);
    // }
// }
