//
// Akanya, Engine
// includes/pch
// g++ -x c++-header -Wpedantic -Wall -Wextra -Wno-volatile -Wno-address -Wno-nonnull-compare -std=c++20 -Ofast -pipe -o includes/pch.hpp.gch -Iincludes -Isources -Ilibraries -Iexterns includes/pch.hpp
//

#ifndef ___INCLUDE_GUARD_INCLUDES_PCH_HPP___
#define ___INCLUDE_GUARD_INCLUDES_PCH_HPP___



#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <ranges>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <variant>
#include <thread>
#include <utility>
#include <concepts>
#include <bitset>
#include <initializer_list>
#include <compare>

#include <experimental/type_traits>

#include <boost/type_index.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/container_hash/hash.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat2x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <stb/stb_image.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Cbitset/Cbitset.hpp>



using std::string_literals::operator""s;
using std::literals::string_view_literals::operator""sv;



#include <Tools/File.hpp>
#include <Tools/Iterator.hpp>
#include <Tools/String.hpp>



#endif // ___INCLUDE_GUARD_INCLUDES_PCH_HPP___
