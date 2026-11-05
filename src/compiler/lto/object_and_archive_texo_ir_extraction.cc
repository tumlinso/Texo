#include <Texo/lto/object_and_archive_texo_ir_extraction_v1.hh>

#include <algorithm>

namespace texo::lto::v1 {
namespace {

bool same_identity(
    const artifact_identity_v1& lhs,
    const artifact_identity_v1& rhs) noexcept {
    return lhs.high == rhs.high && lhs.low == rhs.low;
}

}  // namespace

texo_ir_extraction_status_v1 extract_texo_ir_linker_inputs_v1(
    const std::vector<texo_ir_linker_input_v1>& inputs,
    texo_ir_extraction_index_v1* index) noexcept {
    if (index == nullptr) {
        return texo_ir_extraction_status_v1::invalid_companion;
    }
    *index = {};
    for (const auto& input : inputs) {
        index->bytes_scanned += input.bytes_scanned;
        if (validate_companion_artifact_v1(input.companion) !=
            companion_status_v1::valid) {
            return texo_ir_extraction_status_v1::invalid_companion;
        }
        for (const auto& field : input.companion.fields) {
            const auto existing = std::find_if(
                index->fields.begin(), index->fields.end(),
                [&](const extracted_texo_ir_record_v1& candidate) {
                    return same_identity(candidate.identity, field.field);
                });
            if (existing != index->fields.end()) {
                if (existing->symbol != field.symbol ||
                    !same_identity(existing->profile,
                                   input.companion.profile_reference)) {
                    return texo_ir_extraction_status_v1::conflicting_duplicate;
                }
                ++index->duplicate_members;
                continue;
            }
            index->fields.push_back({field.field,
                                     input.companion.profile_reference,
                                     field.symbol,
                                     input.path,
                                     input.member});
            index->peak_index_bytes = std::max(
                index->peak_index_bytes,
                index->fields.capacity() * sizeof(extracted_texo_ir_record_v1));
        }
    }
    return texo_ir_extraction_status_v1::valid;
}

}  // namespace texo::lto::v1
