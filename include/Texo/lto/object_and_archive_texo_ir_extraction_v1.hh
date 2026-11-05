#pragma once

#include <Texo/lto/texo_ir_companion_object_artifact_contract_v1.hh>

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace texo::lto::v1 {

enum class linker_input_kind_v1 : std::uint8_t {
    object = 1,
    static_archive_member,
    shared_library_metadata,
    sidecar
};

struct texo_ir_linker_input_v1 {
    linker_input_kind_v1 kind = linker_input_kind_v1::object;
    std::string path;
    std::string member;
    std::size_t bytes_scanned = 0;
    texo_ir_companion_artifact_v1 companion{};
};

struct extracted_texo_ir_record_v1 {
    artifact_identity_v1 identity{};
    artifact_identity_v1 profile{};
    std::string symbol;
    std::string source_path;
    std::string archive_member;
};

struct texo_ir_extraction_index_v1 {
    std::vector<extracted_texo_ir_record_v1> fields;
    std::size_t bytes_scanned = 0;
    std::size_t duplicate_members = 0;
    std::size_t peak_index_bytes = 0;
    bool loaded_native_code = false;
};

enum class texo_ir_extraction_status_v1 : std::uint8_t {
    valid = 0,
    invalid_companion,
    conflicting_duplicate
};

[[nodiscard]] texo_ir_extraction_status_v1 extract_texo_ir_linker_inputs_v1(
    const std::vector<texo_ir_linker_input_v1>& inputs,
    texo_ir_extraction_index_v1* index) noexcept;

}  // namespace texo::lto::v1
