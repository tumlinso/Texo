#pragma once

#include <Texo/frontend/source/unified_source_location_model_v1.hh>

#include <cstdint>
#include <vector>

namespace texo::frontend::source {

enum class texo_token_role_v1 : std::uint8_t {
    identifier = 1,
    field_open,
    field_close,
    relation_arrow,
    attribute,
};

struct expanded_texo_token_v1 {
    texo_token_role_v1 role = texo_token_role_v1::identifier;
    source_span_v1 spelling{};
    source_span_v1 expansion{};
    bool expansion_dialect_active = false;
};

[[nodiscard]] constexpr bool macro_token_is_texo_v1(
    const expanded_texo_token_v1& token) noexcept {
    return token.spelling.valid() && token.expansion.valid() && token.expansion_dialect_active;
}
[[nodiscard]] bool macro_construct_is_complete_v1(
    const std::vector<expanded_texo_token_v1>& tokens) noexcept;

} // namespace texo::frontend::source
