#pragma once

#include <Engine/Core/AScene.hpp>


unsigned int loadTexture(char const * path, bool gammaCorrection);

namespace game {



class Scene : public ::engine::core::AScene {

public:

    // ------------------------------------------------------------------ *structors

    explicit Scene(
        ::engine::core::AWindow& window
    );

    ~Scene();



protected:

    // ------------------------------------------------------------------ Update

    void onUpdate() override final;



    // ------------------------------------------------------------------ Draw

    void onDraw() const override final;



private:

    ::engine::graphic::opengl::Shader floorShader{ "testingFloor" };

    bool isFirst{ true };
    unsigned int VBO, cubeVAO;
    unsigned int lightCubeVAO;
    unsigned int floorTexture = loadTexture("data/textures/woodFloor.jpg", false);
    unsigned int floorTextureGammaCorrected = loadTexture("data/textures/woodFloor.jpg", true);
    unsigned int planeVAO, planeVBO;

};



} // namespace engine

