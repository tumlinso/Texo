#include <Texo/ir/common/texo_ir_text_lexer_and_parser_framework_v1.hh>

#include <cassert>
#include <random>
#include <string>

using namespace texo::ir::text;

int main() {
    parser texo_ir;
    texo_ir.register_dialect("semantic", [](std::string_view name) {
        return name == "semantic.apply";
    });
    const std::string source = "include \"types.texoir\"\nimport semantic\nsemantic.apply { bad ??? }";
    const auto unit = texo_ir.parse(source);
    assert(unit.includes == std::vector<std::string>{"types.texoir"});
    assert(unit.imports == std::vector<std::string>{"semantic"});
    assert(unit.operations.size() == 1u && unit.operations[0].inline_block);
    assert(unit.operations[0].range.begin == source.find("semantic.apply"));

    const auto malformed = texo_ir.parse("include ; unknown.op { \"unterminated");
    assert(!malformed.diagnostics.empty());
    for (const auto &diagnostic : malformed.diagnostics)
        assert(diagnostic.range.begin <= diagnostic.range.end);

    std::mt19937 random(19u);
    std::string fuzz(128u, ' ');
    for (unsigned iteration = 0; iteration < 1000u; ++iteration) {
        for (auto &character : fuzz)
            character = static_cast<char>(random() & 0x7fu);
        const auto parsed = texo_ir.parse(fuzz);
        for (const auto &diagnostic : parsed.diagnostics)
            assert(diagnostic.range.end <= fuzz.size());
    }
}
