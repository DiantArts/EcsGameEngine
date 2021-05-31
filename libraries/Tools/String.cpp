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



namespace tools::string {



auto endsWith(
    const ::std::string_view str1,
    const ::std::string_view str2
)
    -> bool
{
    return ::std::equal(str1.begin() + str1.size() - str2.size(), str1.end(), str2.begin());
}



} // namespace tools::string
