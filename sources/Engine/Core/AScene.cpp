#include <pch.hpp>
#include <Engine/Core/AScene.hpp>



// ------------------------------------------------------------------ *structors

::engine::core::AScene::AScene(
    ::engine::core::AWindow& window
)
    : m_window{ window }
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
    m_components.get<::engine::graphic::opengl::ecs::component::Camera>(m_controlledID).configureUbo(
        m_components.get<::engine::graphic::opengl::ecs::component::Transformable>(m_controlledID)
    );
    m_drawSystems.run(m_drawSystemsClock.getRestart(), m_entities, m_components);
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
{
    ::engine::core::ecs::System<
        [](
            ::engine::graphic::opengl::ecs::component::Drawable& drawable,
            ::engine::graphic::opengl::ecs::component::Textures& texture
        ){
            texture.init(drawable);
        }
    >{}(0, m_entities, m_components);

}

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
            const ::engine::graphic::opengl::ecs::component::Transformable& transformable,
            const ::engine::graphic::opengl::ecs::component::Textures& texture
        ){
            texture.bind();
            draw(transformable);
        }
    >();

    m_drawSystems.emplace<
        [](
            const ::engine::graphic::opengl::ecs::component::Drawable& draw,
            const ::engine::graphic::opengl::ecs::component::Transformable& transformable
        ){
            draw(transformable);
        },
        ::engine::graphic::opengl::ecs::component::Textures
    >();
}
