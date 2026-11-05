#include <Texo/ir/common/texo_ir_common_round_trip_and_artifact_compatibility_v1.hh>
#include <Texo/ir/common/deterministic_canonical_printing_v1.hh>
#include <Texo/ir/common/sectioned_binary_texo_ir_serialization_v1.hh>
#include <Texo/ir/common/standalone_texo_ir_compiler_input_detection_v1.hh>
#include <Texo/ir/common/texo_ir_text_lexer_and_parser_framework_v1.hh>

#include <cstring>

namespace texo::ir {

round_trip_report verify_common_round_trip(
    const std::vector<common_operation> &operations) {
    round_trip_report report;
    const text::print_document document{2u, 0u, operations};
    const auto canonical = text::canonical_print(document);
    report.text_stable = canonical == text::canonical_print(document);
    report.canonical_hash = binary_texo_ir_checksum(
        reinterpret_cast<const std::uint8_t *>(canonical.data()), canonical.size());

    const std::vector<std::uint8_t> canonical_bytes(canonical.begin(), canonical.end());
    const auto binary = build_binary_texo_ir({{1u, canonical_bytes}});
    report.binary_valid = validate_binary_texo_ir(binary.data(), binary.size())
        == binary_texo_ir_validation::ok;
    if (report.binary_valid) {
        binary_texo_ir_section section{};
        std::memcpy(&section, binary.data() + sizeof(binary_texo_ir_header), sizeof(section));
        report.binary_payload_equal = section.size == canonical_bytes.size()
            && std::memcmp(binary.data() + section.offset, canonical_bytes.data(),
                canonical_bytes.size()) == 0;
    }
    report.unknown_extensions_preserved = true;
    for (const auto &operation : operations) {
        for (const auto &extension : operation.unknown_extensions) {
            if (canonical.find(extension.namespace_name + ':') == std::string::npos)
                report.unknown_extensions_preserved = false;
        }
    }
    const auto standalone = detect_standalone_texo_ir("module.texoir",
        std::string("texo_ir level semantic version 2.0\n") + canonical);
    report.standalone_resumed = standalone.resume == texo_ir_resume_stage::build_planning;

    text::parser parser;
    parser.register_dialect("semantic", [](std::string_view) { return true; });
    const auto inline_unit = parser.parse("semantic.inline { semantic body }");
    report.source_inline_parsed = inline_unit.operations.size() == 1u
        && inline_unit.operations.front().inline_block;
    if (!(report.text_stable && report.binary_valid && report.binary_payload_equal
            && report.unknown_extensions_preserved && report.standalone_resumed
            && report.source_inline_parsed))
        report.diagnostic = "TEXO_IR common compatibility check failed";
    return report;
}

} // namespace texo::ir
