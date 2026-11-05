#include <Texo/frontend/source/macro_expansion_semantics_for_texo_tokens_v1.hh>

namespace texo::frontend::source {

bool macro_construct_is_complete_v1(const std::vector<expanded_texo_token_v1>& tokens) noexcept {
    std::uint64_t field_depth = 0;
    for (const auto& token : tokens) {
        if (!macro_token_is_texo_v1(token)) return false;
        if (token.role == texo_token_role_v1::field_open) ++field_depth;
        if (token.role == texo_token_role_v1::field_close) {
            if (field_depth == 0) return false;
            --field_depth;
        }
    }
    return field_depth == 0;
}

} // namespace texo::frontend::source
