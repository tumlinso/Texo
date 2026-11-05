#pragma once
#include <array>
#include <string_view>
namespace texo::api::v1 {
inline constexpr std::array<std::string_view,3> accepted_sdk_umbrellas_v1{"Texo/api/texo_compiler.h","Texo/api/compiler.hpp","Texo/sdk/runtime.hpp"};
[[nodiscard]] bool sdk_public_header_is_dependency_clean_v1(std::string_view contents) noexcept;
}
