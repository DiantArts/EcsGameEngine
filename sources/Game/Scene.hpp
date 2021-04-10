#pragma once

#include <Engine/AScene.hpp>

namespace game {



class Scene : public ::engine::AScene {

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

