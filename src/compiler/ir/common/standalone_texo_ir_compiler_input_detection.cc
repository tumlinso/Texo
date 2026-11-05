#include <Texo/ir/common/standalone_texo_ir_compiler_input_detection_v1.hh>

#include <charconv>

namespace texo::ir {

bool is_standalone_texo_ir_path(std::string_view path) noexcept {
    constexpr std::string_view suffix = ".texoir";
    return path.size() >= suffix.size() && path.substr(path.size() - suffix.size()) == suffix;
}

texo_ir_input_header detect_standalone_texo_ir(
    std::string_view path, std::string_view contents) {
    texo_ir_input_header result;
    if (!is_standalone_texo_ir_path(path)) {
        result.diagnostic = "standalone TEXO_IR input requires .texoir suffix";
        return result;
    }
    constexpr std::string_view prefix = "texo_ir level ";
    if (contents.substr(0u, prefix.size()) != prefix) {
        result.diagnostic = "missing TEXO_IR level/version header";
        return result;
    }
    contents.remove_prefix(prefix.size());
    const auto separator = contents.find(' ');
    const auto level = contents.substr(0u, separator);
    if (level == "semantic") {
        result.level = texo_ir_input_level::semantic;
        result.resume = texo_ir_resume_stage::build_planning;
    } else if (level == "planning") {
        result.level = texo_ir_input_level::planning;
        result.resume = texo_ir_resume_stage::build_realization;
    } else if (level == "realization") {
        result.level = texo_ir_input_level::realization;
        result.resume = texo_ir_resume_stage::lower_executable;
    } else {
        result.diagnostic = "unsupported TEXO_IR input level";
        return result;
    }
    if (separator == std::string_view::npos) {
        result.level = texo_ir_input_level::invalid;
        result.resume = texo_ir_resume_stage::reject;
        result.diagnostic = "missing TEXO_IR version";
        return result;
    }
    contents.remove_prefix(separator + 1u);
    constexpr std::string_view version = "version ";
    if (contents.substr(0u, version.size()) != version) {
        result.level = texo_ir_input_level::invalid;
        result.resume = texo_ir_resume_stage::reject;
        result.diagnostic = "missing TEXO_IR version";
        return result;
    }
    contents.remove_prefix(version.size());
    const auto dot = contents.find('.');
    const auto end = contents.find_first_of("\r\n ");
    if (dot == std::string_view::npos || (end != std::string_view::npos && dot > end)) {
        result.level = texo_ir_input_level::invalid;
        result.resume = texo_ir_resume_stage::reject;
        result.diagnostic = "malformed TEXO_IR version";
        return result;
    }
    const auto minor_end = end == std::string_view::npos ? contents.size() : end;
    const auto major_result = std::from_chars(
        contents.data(), contents.data() + dot, result.major);
    const auto minor_result = std::from_chars(
        contents.data() + dot + 1u, contents.data() + minor_end, result.minor);
    if (major_result.ec != std::errc{} || minor_result.ec != std::errc{}
        || result.major != 2u) {
        result.level = texo_ir_input_level::invalid;
        result.resume = texo_ir_resume_stage::reject;
        result.diagnostic = "unsupported TEXO_IR version";
    }
    return result;
}

std::string_view next_texo_ir_dump_name(texo_ir_input_level level) noexcept {
    switch (level) {
    case texo_ir_input_level::semantic: return "planning.texoir";
    case texo_ir_input_level::planning: return "realization.texoir";
    case texo_ir_input_level::realization: return "executable.texoir";
    default: return {};
    }
}

} // namespace texo::ir
