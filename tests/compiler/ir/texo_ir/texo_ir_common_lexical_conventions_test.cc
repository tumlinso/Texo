#include <Texo/ir/common/texo_ir_common_lexical_conventions_v1.hh>

#include <array>
#include <cassert>

using namespace texo::ir;

int main() {
    constexpr std::array cases{
        lexical_token{lexical_kind::persistent_identity, "@genes", "genes"},
        lexical_token{lexical_kind::ssa_value, "%value7", "value7"},
        lexical_token{lexical_kind::type_name, "!state", "state"},
        lexical_token{lexical_kind::attribute_name, "#ordered", "ordered"},
        lexical_token{lexical_kind::region_label, "^entry", "entry"},
        lexical_token{lexical_kind::profile_reference, "$pbmc3k", "pbmc3k"}};
    for (const auto expected : cases) {
        const auto actual = classify_texo_ir_token(expected.spelling);
        assert(actual.kind == expected.kind && actual.payload == expected.payload);
    }

    assert(classify_texo_ir_token("`cuda::kernel<int>`").kind
        == lexical_kind::native_payload);
    assert(classify_texo_ir_token("x.vendor.reuse").kind
        == lexical_kind::extension_name);
    assert(classify_texo_ir_token("texo_ir.schedule").kind
        == lexical_kind::abstraction_level);
    assert(classify_texo_ir_token("// identity is cold metadata").kind
        == lexical_kind::comment);

    // TEXO_IR words stay contextual and therefore remain legal C++ identifiers.
    for (const auto word : {"profile", "region", "native", "schedule"}) {
        assert(is_contextual_keyword(word));
        assert(is_texo_ir_identifier(word));
    }
    for (const auto invalid : {"", "1value", "%", "x.", "texo_ir.unknown",
             "has space", "std::vector"})
        assert(classify_texo_ir_token(invalid).kind == lexical_kind::invalid);
}
