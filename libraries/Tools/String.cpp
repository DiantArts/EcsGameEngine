//
// Akanya, Engine
// File
// file tools to help easier code
//

#include <fstream> // std::ifstream
#include <iostream>
#include <sstream> // std::stringstream
#include <string>  // std::string

#include "File.hpp" // std::string_view



namespace tools::string {



bool endsWith(const std::string_view a, const std::string_view b)
{
    return std::equal(a.begin() + a.size() - b.size(), a.end(), b.begin());
}



} // namespace tools::string
