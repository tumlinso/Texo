#pragma once

#include <array>
#include <string_view>

namespace texo::build {
inline constexpr std::array<std::string_view, 5> generated_header_fields_v1{{
    "compiler_version", "language_revision", "texo_ir_revision",
    "backend_capability", "install_resource_path",
}};
inline constexpr std::string_view generated_header_owner_v1 =
    "compiler build tree";
}  // namespace texo::build
