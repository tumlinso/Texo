#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace texo::ir {

enum class texo_ir_input_level { semantic, planning, realization, invalid };
enum class texo_ir_resume_stage { build_planning, build_realization, lower_executable, reject };
struct texo_ir_input_header {
    texo_ir_input_level level{texo_ir_input_level::invalid};
    std::uint16_t major{};
    std::uint16_t minor{};
    texo_ir_resume_stage resume{texo_ir_resume_stage::reject};
    std::string diagnostic;
};

bool is_standalone_texo_ir_path(std::string_view path) noexcept;
texo_ir_input_header detect_standalone_texo_ir(
    std::string_view path, std::string_view contents);
std::string_view next_texo_ir_dump_name(texo_ir_input_level level) noexcept;

} // namespace texo::ir
