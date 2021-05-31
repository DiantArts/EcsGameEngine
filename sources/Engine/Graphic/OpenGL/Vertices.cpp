#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Vertices.hpp>
#include <Engine/Core/Config/Filepaths.hpp>



// ------------------------------------------------------------------ *structors

::engine::graphic::opengl::Vertices::Vertices(
    const std::string& filepath,
    ::std::size_t& numberOfArrayToDraw
)
{
    ::std::string str{ tool::file::read(::engine::core::config::filepath::vertices + filepath).str() };

    m_vertices.reserve(std::count(str.begin(), str.end(), '\n'));
    ::std::istringstream iss{ str };
    ::std::getline(iss, str);
    numberOfArrayToDraw = std::stol(str);
    while (::std::getline(iss, str)) {
        try {
            m_vertices.push_back(std::stof(str));
        } catch (...) {
            throw ::std::runtime_error("stof: '"s + str + '\'');
        }
    }
}



// ------------------------------------------------------------------ Buffer

void ::engine::graphic::opengl::Vertices::createBuffer()
{
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), &m_vertices.front(), GL_STATIC_DRAW);
}
