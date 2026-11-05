#pragma once
#include <string>
#include <vector>
namespace texo::tooling {
enum class editor_capability_v1 { syntax,cxx_semantics,ast,structural_texo_ir,profile_analysis,cuda_analysis };
struct editor_capability_status_v1 { editor_capability_v1 capability; bool available; std::string reason; };
[[nodiscard]] std::vector<editor_capability_status_v1> editor_capabilities_v1(bool cuda_available,bool profile_loaded);
} // namespace texo::tooling
