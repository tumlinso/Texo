#pragma once

#include <Texo/frontend/parser/parse_compiler_semantic_declarations_v1.hh>

#include <string>
#include <string_view>
#include <vector>

namespace texo::frontend::parser {

enum class inline_texo_ir_level_v1 { semantic, planning, realization };
enum class inline_texo_ir_validation_v1 { structural, checked, verified, trusted, unsafe };

struct inline_texo_ir_block_v1 {
    inline_texo_ir_level_v1 level = inline_texo_ir_level_v1::semantic;
    inline_texo_ir_validation_v1 validation = inline_texo_ir_validation_v1::checked;
    std::vector<std::string> captures;
    std::vector<std::string> results;
    std::string transition_from;
    std::string transition_to;
    std::string body;
    std::string spelling;
    parser_source_range_v1 range{};
    std::vector<inline_texo_ir_block_v1> nested;
};

struct inline_texo_ir_parse_v1 {
    std::vector<inline_texo_ir_block_v1> blocks;
    std::vector<declaration_diagnostic_v1> diagnostics;
    [[nodiscard]] bool accepted() const noexcept { return diagnostics.empty(); }
};

[[nodiscard]] inline_texo_ir_parse_v1 parse_inline_texo_ir_blocks_v1(
    std::string_view source);
[[nodiscard]] std::string render_inline_texo_ir_block_v1(
    const inline_texo_ir_block_v1 &block);

} // namespace texo::frontend::parser
