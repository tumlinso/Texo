#include <Texo/ir/common/sectioned_binary_texo_ir_serialization_v1.hh>

#include <cassert>
#include <cstring>

using namespace texo::ir;

int main() {
    const auto valid = build_binary_texo_ir({{1u, {1u, 2u, 3u}}, {9u, {0xffu}}}, 2u);
    assert(validate_binary_texo_ir(valid.data(), valid.size()) == binary_texo_ir_validation::ok);
    binary_texo_ir_header header{};
    std::memcpy(&header, valid.data(), sizeof(header));
    assert(header.magic == 0x52495854u);
    assert(header.major == binary_texo_ir_major_version && header.major == 2u);
    assert(validate_binary_texo_ir(valid.data(), sizeof(binary_texo_ir_header) - 1u)
        == binary_texo_ir_validation::too_small);

    auto old_magic = valid;
    const std::uint32_t ceir_magic = 0x52494543u;
    std::memcpy(old_magic.data() + offsetof(binary_texo_ir_header, magic),
        &ceir_magic, sizeof(ceir_magic));
    assert(validate_binary_texo_ir(old_magic.data(), old_magic.size())
        == binary_texo_ir_validation::bad_magic);
    auto old_version = valid;
    const std::uint16_t version_one = 1u;
    std::memcpy(old_version.data() + offsetof(binary_texo_ir_header, major),
        &version_one, sizeof(version_one));
    assert(validate_binary_texo_ir(old_version.data(), old_version.size())
        == binary_texo_ir_validation::unsupported_version);

    for (const auto field : {offsetof(binary_texo_ir_header, magic),
             offsetof(binary_texo_ir_header, major), offsetof(binary_texo_ir_header, total_bytes),
             offsetof(binary_texo_ir_header, directory_offset),
             offsetof(binary_texo_ir_header, section_count),
             offsetof(binary_texo_ir_header, checksum)}) {
        auto corrupt = valid;
        corrupt[field] ^= 0x7fu;
        assert(validate_binary_texo_ir(corrupt.data(), corrupt.size()) != binary_texo_ir_validation::ok);
    }
    for (std::size_t field = 0u; field < sizeof(binary_texo_ir_section); field += 4u) {
        auto corrupt = valid;
        corrupt[sizeof(binary_texo_ir_header) + field] ^= 0x55u;
        assert(validate_binary_texo_ir(corrupt.data(), corrupt.size()) != binary_texo_ir_validation::ok);
    }
    auto payload_corrupt = valid;
    payload_corrupt.back() ^= 1u;
    assert(validate_binary_texo_ir(payload_corrupt.data(), payload_corrupt.size())
        == binary_texo_ir_validation::bad_checksum);
}
