#pragma once
#include <cstdint>
#include <optional>
#include <string>
#include <vector>
namespace texo::lto::v1 {
enum class elf_texo_ir_compression_v1:std::uint8_t{none=0,zlib,zstd};
struct elf_texo_ir_section_v1{std::string name,note,symbol;std::vector<std::uint8_t>payload;elf_texo_ir_compression_v1 compression=elf_texo_ir_compression_v1::none;bool allocatable=false,retain_when_stripped=true;};
[[nodiscard]] bool validate_elf_texo_ir_section_v1(const elf_texo_ir_section_v1&)noexcept;
[[nodiscard]] std::vector<std::uint8_t> emit_elf_texo_ir_section_v1(const elf_texo_ir_section_v1&);
[[nodiscard]] std::optional<elf_texo_ir_section_v1> extract_elf_texo_ir_section_v1(const std::vector<std::uint8_t>&);
[[nodiscard]] std::vector<std::uint8_t> strip_elf_runtime_symbols_v1(const std::vector<std::uint8_t>&);
}
