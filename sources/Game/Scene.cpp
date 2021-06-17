#include <pch.hpp>
#include <Game/Scene.hpp>
#include <Engine/Graphic/OpenGL/Vertices.hpp>
#include <Game/Object/Box.hpp>



// ------------------------------------------------------------------ *structors

::game::Scene::Scene(
    ::engine::core::AWindow& window
)
    : ::engine::core::AScene{ window, ::game::object::Box{} }
{
    // m_components.get<::engine::graphic::opengl::ecs::component::Transformable>(m_lightID).setScale(0.2);
    // for (auto&& position : ::std::vector<::glm::vec3>{
        // ::glm::vec3( 0.0f,  0.0f,  0.0f),
        // ::glm::vec3( 2.0f,  5.0f, -15.0f),
        // ::glm::vec3(-1.5f, -2.2f, -2.5f),
        // ::glm::vec3(-3.8f, -2.0f, -12.3f),
        // ::glm::vec3( 2.4f, -0.4f, -3.5f),
        // ::glm::vec3(-1.7f,  3.0f, -7.5f),
        // ::glm::vec3( 1.3f, -2.0f, -2.5f),
        // ::glm::vec3( 1.5f,  2.0f, -2.5f),
        // ::glm::vec3( 1.5f,  0.2f, -1.5f),
        // ::glm::vec3(-1.3f,  1.0f, -1.5f)
    // }) {
        // m_entities.emplace(
            // ::game::object::Box{},
            // ::engine::graphic::opengl::ecs::component::Transformable{ ::std::move(position) }
        // );
    // }

    float planeVertices[] = {
        // positions            // normals         // texcoords
         10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
        -10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
        -10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,

         10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
        -10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,
         10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,  10.0f, 10.0f
    };
    // plane VAO
    glGenVertexArrays(1, &planeVAO);
    glGenBuffers(1, &planeVBO);
    glBindVertexArray(planeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glBindVertexArray(0);
    floorShader.use();
    floorShader.set("floorTexture", 0);



    constexpr glm::vec3 lightPositions[] = {
        glm::vec3(-3.0f, 0.0f, 0.0f),
        glm::vec3(-1.0f, 0.0f, 0.0f),
        glm::vec3 (1.0f, 0.0f, 0.0f),
        glm::vec3 (3.0f, 0.0f, 0.0f)
    };
    constexpr glm::vec3 lightColors[] = {
        glm::vec3(0.25),
        glm::vec3(0.50),
        glm::vec3(0.75),
        glm::vec3(1.00)
    };
    for (int i{ 0 }; i < 4; i++) {
        m_entities.emplace(
            ::engine::graphic::opengl::ecs::component::Transformable{ lightPositions[i] },
            ::engine::graphic::opengl::ecs::component::light::Point{ lightColors[i] }
        );
    }
}

::game::Scene::~Scene() = default;



// ------------------------------------------------------------------ Update

void ::game::Scene::onUpdate()
{
    // m_components.get<::engine::graphic::opengl::ecs::component::Transformable>(m_lightID).setPositionX(
        // (sin(glfwGetTime()) * 5)
    // );
}



// ------------------------------------------------------------------ Draw

void ::game::Scene::onDraw() const
{
    floorShader.use();
    floorShader.set("model", ::glm::mat4{ 1.0f });
    glBindVertexArray(planeVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, true ? floorTextureGammaCorrected : floorTexture);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

unsigned int loadTexture(char const * path, bool gammaCorrection)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum internalFormat;
        GLenum dataFormat;
        if (nrComponents == 1)
        {
            internalFormat = dataFormat = GL_RED;
        }
        else if (nrComponents == 3)
        {
            internalFormat = gammaCorrection ? GL_SRGB : GL_RGB;
            dataFormat = GL_RGB;
        }
        else if (nrComponents == 4)
        {
            internalFormat = gammaCorrection ? GL_SRGB_ALPHA : GL_RGBA;
            dataFormat = GL_RGBA;
        }

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}
