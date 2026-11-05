#include <Texo/ir/common/sectioned_binary_texo_ir_serialization_v1.hh>

#include <cstring>
#include <limits>

namespace texo::ir {

std::uint32_t binary_texo_ir_checksum(const std::uint8_t *data, std::size_t size) noexcept {
    std::uint32_t hash = 2166136261u;
    for (std::size_t index = 0; index < size; ++index) {
        hash ^= data[index];
        hash *= 16777619u;
    }
    return hash;
}

std::vector<std::uint8_t> build_binary_texo_ir(
    const std::vector<binary_section_input> &sections, std::uint16_t minor) {
    const std::size_t directory_bytes = sections.size() * sizeof(binary_texo_ir_section);
    std::size_t total = sizeof(binary_texo_ir_header) + directory_bytes;
    for (const auto &section : sections)
        total += section.bytes.size();
    if (total > std::numeric_limits<std::uint32_t>::max())
        return {};
    std::vector<std::uint8_t> result(total);
    binary_texo_ir_header header{binary_texo_ir_magic, binary_texo_ir_major_version, minor,
        static_cast<std::uint32_t>(total), sizeof(binary_texo_ir_header),
        static_cast<std::uint32_t>(sections.size()), 0u};
    std::memcpy(result.data(), &header, sizeof(header));
    std::size_t offset = sizeof(header) + directory_bytes;
    for (std::size_t index = 0; index < sections.size(); ++index) {
        const auto &input = sections[index];
        const binary_texo_ir_section section{input.kind, static_cast<std::uint32_t>(offset),
            static_cast<std::uint32_t>(input.bytes.size()),
            binary_texo_ir_checksum(input.bytes.data(), input.bytes.size())};
        std::memcpy(result.data() + sizeof(header) + index * sizeof(section),
            &section, sizeof(section));
        std::memcpy(result.data() + offset, input.bytes.data(), input.bytes.size());
        offset += input.bytes.size();
    }
    header.checksum = binary_texo_ir_checksum(
        result.data() + sizeof(header), result.size() - sizeof(header));
    std::memcpy(result.data(), &header, sizeof(header));
    return result;
}

binary_texo_ir_validation validate_binary_texo_ir(
    const std::uint8_t *data, std::size_t size) noexcept {
    if (!data || size < sizeof(binary_texo_ir_header))
        return binary_texo_ir_validation::too_small;
    binary_texo_ir_header header{};
    std::memcpy(&header, data, sizeof(header));
    if (header.magic != binary_texo_ir_magic)
        return binary_texo_ir_validation::bad_magic;
    if (header.major != binary_texo_ir_major_version)
        return binary_texo_ir_validation::unsupported_version;
    if (header.total_bytes != size)
        return binary_texo_ir_validation::bad_size;
    const std::size_t directory_bytes =
        static_cast<std::size_t>(header.section_count) * sizeof(binary_texo_ir_section);
    if (header.directory_offset < sizeof(header)
        || header.directory_offset > size
        || directory_bytes > size - header.directory_offset)
        return binary_texo_ir_validation::bad_directory;
    if (binary_texo_ir_checksum(data + sizeof(header), size - sizeof(header)) != header.checksum)
        return binary_texo_ir_validation::bad_checksum;
    for (std::size_t index = 0; index < header.section_count; ++index) {
        binary_texo_ir_section section{};
        std::memcpy(&section, data + header.directory_offset + index * sizeof(section),
            sizeof(section));
        if (section.offset > size || section.size > size - section.offset)
            return binary_texo_ir_validation::bad_section;
        if (binary_texo_ir_checksum(data + section.offset, section.size) != section.checksum)
            return binary_texo_ir_validation::bad_checksum;
    }
    return binary_texo_ir_validation::ok;
}

} // namespace texo::ir
