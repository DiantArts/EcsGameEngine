//
// Akanya, Engine
// libraries/Tools/File
// file tools to help easier code
//

#ifndef ___INCLUDE_GUARD_LIBRARIES_TOOLS_FILE_HPP___
#define ___INCLUDE_GUARD_LIBRARIES_TOOLS_FILE_HPP___

#include <string_view>



namespace tool::file {



extern std::stringstream read(std::string_view filepath);
extern bool exists(const std::string& filepath);



} // namespace tool::file



#endif // ___INCLUDE_GUARD_LIBRARIES_TOOLS_FILE_HPP___
