#pragma once



namespace engine::graphic::opengl::detail {


void createShader(
    ::GLint id,
    ::std::string&& vertexFilepath,
    ::std::string&& fragmentFilepath
);

void createShader(
    ::GLint id,
    ::std::string&& vertexFilepath,
    ::std::string&& fragmentFilepath,
    ::std::string&& geometryFilepath
);

auto compileShader(
    ::GLenum shaderType,
    const ::std::string& filepath
)
    -> ::GLint;

void checkCompilationStatus(
    ::GLuint shader,
    const ::std::string_view filepath
);

void checkLinkageStatus(
    ::GLuint shader
);



} // namespace engine::graphic::opengl::detail
