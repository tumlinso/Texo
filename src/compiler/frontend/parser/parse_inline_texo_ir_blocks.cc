#include <Texo/frontend/parser/parse_inline_texo_ir_blocks_v1.hh>

#include <cctype>
#include <optional>

namespace texo::frontend::parser {
namespace {

std::string trim_copy(std::string_view value) {
    while (!value.empty() && std::isspace(static_cast<unsigned char>(value.front())))
        value.remove_prefix(1);
    while (!value.empty() && std::isspace(static_cast<unsigned char>(value.back())))
        value.remove_suffix(1);
    return std::string(value);
}

std::size_t matching(std::string_view source, std::size_t open, char left, char right) {
    unsigned depth = 0;
    bool quoted = false;
    for (auto offset = open; offset < source.size(); ++offset) {
        if (source[offset] == '"' && (offset == 0 || source[offset - 1] != '\\'))
            quoted = !quoted;
        if (quoted)
            continue;
        depth += source[offset] == left ? 1u : 0u;
        if (source[offset] == right && --depth == 0)
            return offset;
    }
    return std::string_view::npos;
}

std::vector<std::string> comma_list(std::string_view source) {
    std::vector<std::string> result;
    std::size_t begin = 0;
    unsigned depth = 0;
    for (std::size_t offset = 0; offset < source.size(); ++offset) {
        depth += source[offset] == '(' || source[offset] == '<' ? 1u : 0u;
        depth -= (source[offset] == ')' || source[offset] == '>') && depth ? 1u : 0u;
        if (source[offset] == ',' && depth == 0) {
            result.push_back(trim_copy(source.substr(begin, offset - begin)));
            begin = offset + 1;
        }
    }
    auto tail = trim_copy(source.substr(begin));
    if (!tail.empty())
        result.push_back(std::move(tail));
    return result;
}

std::optional<inline_texo_ir_level_v1> level_of(std::string_view level) {
    if (level == "semantic") return inline_texo_ir_level_v1::semantic;
    if (level == "planning") return inline_texo_ir_level_v1::planning;
    if (level == "realization") return inline_texo_ir_level_v1::realization;
    return std::nullopt;
}

std::optional<inline_texo_ir_validation_v1> validation_of(std::string_view mode) {
    if (mode == "structural") return inline_texo_ir_validation_v1::structural;
    if (mode == "checked") return inline_texo_ir_validation_v1::checked;
    if (mode == "verified") return inline_texo_ir_validation_v1::verified;
    if (mode == "trusted") return inline_texo_ir_validation_v1::trusted;
    if (mode == "unsafe") return inline_texo_ir_validation_v1::unsafe;
    return std::nullopt;
}

std::string_view call_contents(std::string_view header, std::string_view name) {
    const auto begin = header.find(name);
    if (begin == std::string_view::npos)
        return {};
    const auto open = begin + name.size() - 1;
    const auto close = matching(header, open, '(', ')');
    return close == std::string_view::npos ? std::string_view{}
        : header.substr(open + 1, close - open - 1);
}

} // namespace

inline_texo_ir_parse_v1 parse_inline_texo_ir_blocks_v1(std::string_view source) {
    inline_texo_ir_parse_v1 result;
    std::size_t search = 0;
    constexpr std::string_view prefix = "texo_ir<";
    while ((search = source.find(prefix, search)) != std::string_view::npos) {
        const auto level_begin = search + prefix.size();
        const auto level_end = source.find('>', level_begin);
        if (level_end == std::string_view::npos) {
            result.diagnostics.push_back({"unterminated inline TEXO_IR level", {search, source.size()}});
            break;
        }
        const auto level = level_of(source.substr(level_begin, level_end - level_begin));
        const auto body_open = source.find('{', level_end + 1);
        if (!level || body_open == std::string_view::npos) {
            result.diagnostics.push_back({"invalid inline TEXO_IR level or body", {search, level_end + 1}});
            search = level_end + 1;
            continue;
        }
        const auto body_close = matching(source, body_open, '{', '}');
        if (body_close == std::string_view::npos) {
            result.diagnostics.push_back({"unterminated inline TEXO_IR body", {body_open, source.size()}});
            break;
        }
        inline_texo_ir_block_v1 block;
        block.level = *level;
        block.range = {search, body_close + 1};
        block.spelling = std::string(source.substr(search, body_close - search + 1));
        const auto header = source.substr(level_end + 1, body_open - level_end - 1);
        block.captures = comma_list(call_contents(header, "captures("));
        block.results = comma_list(call_contents(header, "results("));
        const auto validation = call_contents(header, "validation(");
        if (!validation.empty()) {
            const auto mode = validation_of(trim_copy(validation));
            if (!mode)
                result.diagnostics.push_back({"unknown inline TEXO_IR validation mode",
                                              {level_end + 1, body_open}});
            else
                block.validation = *mode;
        }
        const auto transition = comma_list(call_contents(header, "transition("));
        if (!transition.empty()) {
            if (transition.size() != 2)
                result.diagnostics.push_back({"transition requires from and to levels",
                                              {level_end + 1, body_open}});
            else {
                block.transition_from = transition[0];
                block.transition_to = transition[1];
            }
        }
        block.body = std::string(source.substr(body_open + 1, body_close - body_open - 1));
        block.nested = parse_inline_texo_ir_blocks_v1(block.body).blocks;
        result.blocks.push_back(std::move(block));
        search = body_close + 1;
    }
    return result;
}

std::string render_inline_texo_ir_block_v1(const inline_texo_ir_block_v1 &block) {
    return block.spelling;
}

} // namespace texo::frontend::parser
