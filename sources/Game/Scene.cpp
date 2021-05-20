#include <pch.hpp>
#include <Game/Scene.hpp>
#include <Engine/Graphic/OpenGL/Vertices.hpp>



// ------------------------------------------------------------------ *structors

::game::Scene::Scene(
    ::engine::core::AWindow& window
)
    : ::engine::core::AScene{ window }
{
    m_vao.bind();
    m_vbo.bind();
    engine::graphic::opengl::Vertices("cube", m_numberOfArrayToDraw).createBuffer();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    m_shader.use();
    m_shader.set("texture1", 0);
    m_shader.set("texture2", 1);
}

::game::Scene::~Scene() = default;



// ------------------------------------------------------------------ Update

void ::game::Scene::onUpdate()
{}



// ------------------------------------------------------------------ Draw

void ::game::Scene::onDraw() const
{
    constexpr glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    m_texture1.bind(0);
    m_texture2.bind(1);

    m_shader.use();

    glm::mat4 projection = glm::perspective(glm::radians(fov), 1920.0f / 1080.0f, 0.1f, 100.0f);
    m_shader.set("projection", projection);
    glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    m_shader.set("view", view);

    m_vao.bind();
    for (unsigned int i = 0; i < 10; i++) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        m_shader.set("model", model);
        glDrawArrays(GL_TRIANGLES, 0, m_numberOfArrayToDraw);
    }
}
