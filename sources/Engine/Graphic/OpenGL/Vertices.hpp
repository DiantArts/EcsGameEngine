#pragma once

namespace engine::graphic::opengl {



class Vertices {

public:

    // ------------------------------------------------------------------ *structors

    // put the number of array to draw into the ::std::size_t
    explicit Vertices(
        const std::string& filepath,
        ::std::size_t& numberOfArrayToDraw
    );



    // ------------------------------------------------------------------ Buffer

    // push the content of the vector into an OpenGL buffer
    void createBuffer();



private:

    std::vector<float> m_vertices;

};



} // namespace engine::graphic::opengl
