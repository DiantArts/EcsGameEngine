#include <pch.hpp>
#include <Engine/Graphic/OpenGL/Detail/Shader.hpp>



static auto readShaderFile(
    const ::std::string& filepath
) -> ::std::string
{
    ::std::stringstream ss { tool::file::read(filepath) };
    ::std::string readFile;
    for (::std::string line; ::std::getline(ss, line); ) {
        if (line.rfind("#include ") == 0) {
            try {
                readFile += readShaderFile(line.substr(10, line.size() - 11));
            } catch (...) {
                readFile += line;
            }
        } else {
            readFile += line;
        }
        readFile += '\n';
    }
    return readFile;
}

void ::engine::graphic::opengl::detail::createShader(
    ::GLint id,
    ::std::string&& vertexFilepath,
    ::std::string&& fragmentFilepath
)
{
    auto vertex { compileShader(GL_VERTEX_SHADER, vertexFilepath) };
    auto fragment { compileShader(GL_FRAGMENT_SHADER, fragmentFilepath) };

    if (vertex && fragment) {
        glAttachShader(id, vertex);
        glAttachShader(id, fragment);
        glLinkProgram(id);
        checkLinkageStatus(id);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void ::engine::graphic::opengl::detail::createShader(
    ::GLint id,
    ::std::string&& vertexFilepath,
    ::std::string&& fragmentFilepath,
    ::std::string&& geometryFilepath
)
{
    auto vertex { compileShader(GL_VERTEX_SHADER, vertexFilepath) };
    auto fragment { compileShader(GL_FRAGMENT_SHADER, fragmentFilepath) };
    auto geometry { compileShader(GL_GEOMETRY_SHADER, geometryFilepath) };


    if (vertex && fragment && geometry) {
        glAttachShader(id, vertex);
        glAttachShader(id, fragment);
        glAttachShader(id, geometry);
        glLinkProgram(id);
        checkLinkageStatus(id);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    glDeleteShader(geometry);
}

auto ::engine::graphic::opengl::detail::compileShader(
    ::GLenum shaderType,
    const ::std::string& filepath
)
    -> ::GLint
{
    ::GLuint shader { glCreateShader(shaderType) };

    try {
        const ::std::string readFile { readShaderFile(filepath) };
        const char* shaderCode { readFile.c_str() };
        glShaderSource(shader, 1, &shaderCode, nullptr);
    } catch (const ::std::ifstream::failure& e) {
        ::std::clog << "Shader file '" << filepath << "' unsuccesfully read (" << e.what() << ")" << ::std::endl;
        return 0;
    }

    glCompileShader(shader);
    checkCompilationStatus(shader, filepath);

    return shader;
}


void ::engine::graphic::opengl::detail::checkCompilationStatus(
    ::GLuint shader,
    const ::std::string_view filepath
)
{
    ::GLint status { 0 };
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        ::GLchar infoLog[512] = { 0 };
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        ::std::clog << "Shader '" << filepath << "' compilation failed: " << infoLog << "\n";
    }
}


void ::engine::graphic::opengl::detail::checkLinkageStatus(
    ::GLuint shader
)
{
    ::GLint status { 0 };
    glGetProgramiv(shader, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        ::GLchar infoLog[1024] = { 0 };
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        ::std::clog << "Program linkage failed (type: " << status << "):" << infoLog << "\n";
    }
}
