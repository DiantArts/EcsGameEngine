#pragma once

namespace engine::core::config::filepath {



inline const auto textures { "./data/textures/"s };
inline const auto vertices { "./data/vertices/"s };
inline const auto model { "./data/3dModels/"s };



namespace shader {

inline const auto fragments { "./data/shaders/fragments/"s };
inline const auto vertexes { "./data/shaders/vertexes/"s };
inline const auto geometries { "./data/shaders/geometries/"s };

} // namespace shader



} // namespace engine::core::config::filepath
