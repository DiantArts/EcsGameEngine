#pragma once

#include <Engine/Core/AScene.hpp>



namespace game {



class Scene : public ::engine::core::AScene {

public:

    // ------------------------------------------------------------------ *structors

    Scene();

    ~Scene();



    // ------------------------------------------------------------------ Update

    void onUpdate() override final;



    // ------------------------------------------------------------------ Draw

    void onDraw() const override final;



private:

};



} // namespace engine

