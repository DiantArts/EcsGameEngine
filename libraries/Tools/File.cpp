//
// Akanya, Engine
// File
// file tools to help easier code
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <Tools/File.hpp>

#ifdef __linux__
#include <sys/stat.h>
#endif



namespace tool::file {



auto read(const ::std::string_view filepath)
    -> ::std::stringstream
{
    using ::std::string_literals::operator""s;

    ::std::stringstream shaderSs;
    {
        ::std::ifstream shaderFile;
        shaderFile.exceptions(::std::ifstream::failbit | ::std::ifstream::badbit);

        try {
            shaderFile.open(::std::string(filepath));
        } catch (const ::std::ifstream::failure& e) {
            throw ::std::runtime_error("unable to open '"s + ::std::string(filepath) +
                                     "' file ("s + e.what() + ')');
        }


        shaderSs << shaderFile.rdbuf();
    }
    return shaderSs;
}

auto exists(const ::std::string& filepath)
    -> bool
{
#ifdef __linux__
    struct stat buffer;
    return stat(filepath.c_str(), &buffer) == 0;
#else
    return ::std::ifstream(filepath.c_str()).good();
#endif
}


} // namespace tool::file
