#include <pch.hpp>
#include <Engine/Core/AScene.hpp>
#include <nbLights.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::AScene::AScene(
    ::engine::core::AWindow& window,
    ::engine::graphic::opengl::ecs::component::Drawable mainCharacter
)
    : m_window{ window }
    , m_lightsUbo{
            sizeof(::glm::vec4) +
            MAX_NB_DIRECTIONAL_LIGHT * 0 +
            MAX_NB_POINT_LIGHT * engine::graphic::opengl::ecs::component::light::Point::Parameters::sizetype +
            MAX_NB_SPOT_LIGHT * 0
        , m_lightsUboIndex }
    , m_controlledID{ m_entities.emplace(
            ::engine::core::ecs::component::Controllable{ true },
            ::std::move(mainCharacter),
            ::engine::graphic::opengl::ecs::component::Transformable{ 0.0F, 0.0F, 5.0F },
            ::engine::graphic::opengl::ecs::component::Camera{ m_window, ::glm::vec3{ 0.0F, 1.0F, 0.0F } }
        ).getID() }
{
    this->runInitSystems();
    this->emplaceUpdateSystems();
    this->emplaceDrawSystems();
}

::engine::core::AScene::~AScene() = default;



// ------------------------------------------------------------------ Loop

auto ::engine::core::AScene::isOver() const
    -> bool
{
    return m_isOver || m_window.shouldClose();
}

void ::engine::core::AScene::ends()
{
    m_isOver = true;
}



// ------------------------------------------------------------------ Update

void ::engine::core::AScene::update()
{
    m_window.handleEvents(*this);
    this->onUpdate();
    m_updateSystems.run(m_systemsClock.getRestart(), m_entities, m_components);
}

void ::engine::core::AScene::onUpdate()
{}



// ------------------------------------------------------------------ Draw

void ::engine::core::AScene::draw() const
{
    m_window.clear();
    this->configureUbo();
    // m_drawSystems.run(m_drawSystemsClock.getRestart(), m_entities, m_components);
    this->onDraw();
    m_window.draw();
}

void ::engine::core::AScene::onDraw() const
{}



// ------------------------------------------------------------------ MainControllable

auto ::engine::core::AScene::getMainEntityControllable() const
    -> const ::engine::core::ecs::component::Controllable&
{
    return m_components.get<::engine::core::ecs::component::Controllable>(m_controlledID);
}

auto ::engine::core::AScene::getMainEntityControllable()
    -> ::engine::core::ecs::component::Controllable&
{
    return m_components.get<::engine::core::ecs::component::Controllable>(m_controlledID);
}

auto ::engine::core::AScene::getCamera() const
    -> const ::engine::graphic::opengl::ecs::component::Camera&
{
    return m_components.get<::engine::graphic::opengl::ecs::component::Camera>(m_controlledID);
}

auto ::engine::core::AScene::getCamera()
    -> ::engine::graphic::opengl::ecs::component::Camera&
{
    return m_components.get<::engine::graphic::opengl::ecs::component::Camera>(m_controlledID);
}



// ------------------------------------------------------------------ Systems

void ::engine::core::AScene::runInitSystems()
{}

void ::engine::core::AScene::emplaceUpdateSystems()
{
    m_updateSystems.emplace<
        [](
            ::engine::core::Time deltaTime,
            ::engine::core::ecs::component::Controllable& controllable,
            ::engine::graphic::opengl::ecs::component::Transformable& transformable
        ){
            controllable.updatePosition(deltaTime, transformable);
            controllable.updateRotation(transformable);
        }
    >();
}

void ::engine::core::AScene::emplaceDrawSystems()
{
    m_drawSystems.emplace<
        [](
            const ::engine::graphic::opengl::ecs::component::Drawable& draw,
            const ::engine::graphic::opengl::ecs::component::Transformable& transformable
        ){
            draw(transformable);
        }
    >();
}

// ------------------------------------------------------------------ Detail

void ::engine::core::AScene::configureUbo() const
{
    // Camera
    m_components.get<::engine::graphic::opengl::ecs::component::Camera>(m_controlledID).configureUbo(
        m_components.get<::engine::graphic::opengl::ecs::component::Transformable>(m_controlledID)
    );

    m_lightsUbo.bind();
    ::std::size_t offset{ 0 };
    ::engine::graphic::opengl::Ubo::setSubData(offset, MAX_NB_DIRECTIONAL_LIGHT);
    offset += 4;
    ::engine::graphic::opengl::Ubo::setSubData(offset, MAX_NB_POINT_LIGHT);
    offset += 4;
    ::engine::graphic::opengl::Ubo::setSubData(offset, MAX_NB_SPOT_LIGHT);
    offset += 4;
    offset += 4;
    if (m_components.vectorExists<::engine::graphic::opengl::ecs::component::light::Point>()) {
        for (const auto& light : m_components.getVector<::engine::graphic::opengl::ecs::component::light::Point>()) {
            light.setIntoUbo(offset);
        }
    }
}
