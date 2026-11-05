#include <Texo/frontend/source/macro_expansion_semantics_for_texo_tokens_v1.hh>

#include <iostream>
#include <stdexcept>

using namespace texo::frontend::source;

int main() {
    try {
        auto token = [](texo_token_role_v1 role, bool active = true) {
            return expanded_texo_token_v1{role, {{1, 0}, {1, 1}},
                                                {{2, 4}, {2, 5}}, active};
        };
        std::vector<expanded_texo_token_v1> field{
            token(texo_token_role_v1::field_open),
            token(texo_token_role_v1::identifier),
            token(texo_token_role_v1::relation_arrow),
            token(texo_token_role_v1::attribute),
            token(texo_token_role_v1::field_close),
        };
        if (!macro_construct_is_complete_v1(field)) throw std::runtime_error("valid expansion rejected");
        field.pop_back();
        if (macro_construct_is_complete_v1(field)) throw std::runtime_error("partial expansion accepted");
        field.push_back(token(texo_token_role_v1::field_close, false));
        if (macro_construct_is_complete_v1(field)) throw std::runtime_error("inactive expansion accepted");
        std::cout << "validated macro expansion provenance and activation semantics\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
