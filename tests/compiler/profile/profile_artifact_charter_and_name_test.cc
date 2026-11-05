#include <Texo/profile/profile_artifact_charter_and_name_v1.hh>

#include <array>
#include <cassert>
#include <cstring>
#include <string_view>

int main() {
    using namespace texo::profile::v1;

    static_assert(sizeof(profile_artifact_header_v1) == 112u);
    static_assert(std::string_view(profile_artifact_name_v1) == "Texo Profile Artifact v2");
    static_assert(std::string_view(profile_artifact_suffix_v1) == ".texoprofile");
    constexpr std::array<std::array<unsigned char, 8>, 4> reserved_magics{{
        {{'C', 'E', 'L', 'L', 'P', 'K', '0', '1'}},
        {{'C', 'E', 'L', 'L', 'C', 'S', 'G', '1'}},
        {{'C', 'E', 'L', 'L', 'E', 'X', '0', '2'}},
        {{'C', 'E', 'O', 'R', 'C', 'L', '1', 0}}}};
    for (const auto &reserved : reserved_magics)
        assert(std::memcmp(profile_artifact_magic_v1, reserved.data(),
                           reserved.size()) != 0);
    constexpr unsigned char old_magic[8] = {'C', 'E', 'L', 'L', 'P', 'R', 'F', '1'};
    assert(std::memcmp(profile_artifact_magic_v1, "TEXOPRF2", 8u) == 0);
    assert(std::memcmp(profile_artifact_magic_v1, old_magic, sizeof(old_magic)) != 0);
    static_assert(profile_artifact_schema_version_v1 == 2u);

    auto header = make_profile_artifact_header_v1(1u, 2u, 3u, 4u, 5u);
    assert(validate_profile_artifact_charter_v1(header)
           == profile_artifact_charter_status_v1::ok);
    header.schema_version = 1u;
    assert(validate_profile_artifact_charter_v1(header)
           == profile_artifact_charter_status_v1::unsupported_schema);
    header.schema_version = profile_artifact_schema_version_v1;
    std::memcpy(header.magic, old_magic, sizeof(old_magic));
    assert(validate_profile_artifact_charter_v1(header)
           == profile_artifact_charter_status_v1::invalid_magic);
    std::memcpy(header.magic, profile_artifact_magic_v1, sizeof(old_magic));
    header.flags = profile_artifact_flag_none;
    assert(validate_profile_artifact_charter_v1(header)
           == profile_artifact_charter_status_v1::not_data_derived);
}
