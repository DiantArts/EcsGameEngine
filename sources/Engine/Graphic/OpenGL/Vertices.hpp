#pragma once

namespace engine::graphic::opengl {



class Vertices {

public:

    // ------------------------------------------------------------------ *structors

    explicit Vertices(
        const std::string& filepath,
        size_t& numberOfArrayToDraw
    );



    // ------------------------------------------------------------------ Buffer

    void createBuffer();



private:

    std::vector<float> m_vertices;

};



} // namespace engine::graphic::opengl
