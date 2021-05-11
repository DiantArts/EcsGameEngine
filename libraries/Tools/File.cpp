//
// Akanya, Engine
// File
// file tools to help easier code
//

#include "File.hpp" // std::string_view

#include <fstream> // std::ifstream
#include <iostream>
#include <sstream> // std::stringstream
#include <string>  // std::string

#ifdef __linux__
#include <sys/stat.h>
#endif



namespace tool::file {



std::stringstream read(const std::string_view filepath)
{
    using std::string_literals::operator""s;

    std::stringstream shaderSs;
    {
        std::ifstream shaderFile;
        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try {
            shaderFile.open(std::string(filepath));
        } catch (const std::ifstream::failure& e) {
            throw std::runtime_error("unable to open '"s + std::string(filepath) +
                                     "' file ("s + e.what() + ')');
        }


        shaderSs << shaderFile.rdbuf();
    }
    return shaderSs;
}

bool exists(const std::string& filepath)
{
#ifdef __linux__
    struct stat buffer;
    return stat(filepath.c_str(), &buffer) == 0;
#else
    return std::ifstream(filepath.c_str()).good();
#endif
}


} // namespace tool::file
