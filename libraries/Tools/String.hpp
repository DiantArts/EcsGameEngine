//
// Akanya, Engine
// libraries/Tools/String
// File tools to help easier and cleaner code
//

#ifndef ___INCLUDE_GUARD_LIBRARIES_TOOLS_STRING_HPP___
#define ___INCLUDE_GUARD_LIBRARIES_TOOLS_STRING_HPP___

#include <string_view>



namespace tools::string {



[[ nodiscard ]] extern auto endsWith(
    ::std::string_view str1,
    ::std::string_view str2
)
    -> bool;



} // namespace tools::string



#endif // ___INCLUDE_GUARD_libraries_Tools_String_hpp___
