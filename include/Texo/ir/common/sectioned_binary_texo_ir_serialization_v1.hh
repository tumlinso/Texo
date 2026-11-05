#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace texo::ir {

inline constexpr std::uint32_t binary_texo_ir_magic = 0x52495854u; // TXIR, little endian
inline constexpr std::uint16_t binary_texo_ir_major_version = 2u;
struct binary_texo_ir_header {
    std::uint32_t magic{};
    std::uint16_t major{};
    std::uint16_t minor{};
    std::uint32_t total_bytes{};
    std::uint32_t directory_offset{};
    std::uint32_t section_count{};
    std::uint32_t checksum{};
};
struct binary_texo_ir_section {
    std::uint32_t kind{};
    std::uint32_t offset{};
    std::uint32_t size{};
    std::uint32_t checksum{};
};
enum class binary_texo_ir_validation {
    ok, too_small, bad_magic, unsupported_version, bad_size,
    bad_directory, bad_section, bad_checksum
};
struct binary_section_input { std::uint32_t kind{}; std::vector<std::uint8_t> bytes; };

std::uint32_t binary_texo_ir_checksum(const std::uint8_t *data, std::size_t size) noexcept;
std::vector<std::uint8_t> build_binary_texo_ir(
    const std::vector<binary_section_input> &sections, std::uint16_t minor = 0u);
binary_texo_ir_validation validate_binary_texo_ir(
    const std::uint8_t *data, std::size_t size) noexcept;

} // namespace texo::ir
