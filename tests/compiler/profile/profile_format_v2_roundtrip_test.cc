#include <Texo/profile/sectioned_binary_profile_storage_v1.hh>
#include <Texo/profile/profile_artifact_charter_and_name_v1.hh>

#include <cassert>
#include <cstdlib>
#include <cstring>

int main() {
    using namespace texo::profile::v1;

    static_assert(profile_artifact_schema_version_v1 == 2u);
    static_assert(profile_artifact_header_bytes_v1 == 112u);
    const unsigned char evidence[] = {1u, 3u, 5u};
    const profile_section_source_v1 sections[] = {{
        static_cast<std::uint32_t>(profile_section_kind_v1::named_environment),
        1u, profile_section_flag_none, profile_compression_v1::none,
        11u, 12u, evidence, sizeof(evidence), sizeof(evidence)}};
    profile_artifact_build_request_v1 request{};
    request.header = make_profile_artifact_header_v1(1u, 2u, 3u, 4u, 5u);
    request.sections = sections;
    request.section_count = 1u;

    profile_artifact_requirements_v1 requirements{};
    assert(query_profile_artifact_requirements_v1(request, &requirements)
           == profile_storage_status_v1::ok);
    const auto allocation_bytes = (requirements.image_bytes + 63u) & ~63ull;
    auto *storage = static_cast<unsigned char *>(
        std::aligned_alloc(profile_artifact_alignment_v1, allocation_bytes));
    assert(storage != nullptr);

    profile_artifact_view_v1 built{};
    assert(build_profile_artifact_v1(request,
               {storage, allocation_bytes}, &built)
           == profile_storage_status_v1::ok);
    assert(std::memcmp(built.header.magic, "TEXOPRF2", 8u) == 0);
    assert(built.header.schema_version == 2u);

    profile_artifact_view_v1 round_trip{};
    assert(validate_profile_artifact_v1(storage, requirements.image_bytes,
               &round_trip) == profile_storage_status_v1::ok);
    profile_section_view_v1 found{};
    assert(find_profile_section_v1(round_trip,
               static_cast<std::uint32_t>(profile_section_kind_v1::named_environment),
               &found) == profile_storage_status_v1::ok);
    assert(found.entry.stored_bytes == sizeof(evidence));
    assert(std::memcmp(found.stored_data, evidence, sizeof(evidence)) == 0);

    auto *legacy = static_cast<unsigned char *>(
        std::aligned_alloc(profile_artifact_alignment_v1, allocation_bytes));
    assert(legacy != nullptr);
    std::memcpy(legacy, storage, requirements.image_bytes);
    std::memcpy(legacy, "CELLPRF1", 8u);
    assert(validate_profile_artifact_v1(legacy, requirements.image_bytes,
               &round_trip) == profile_storage_status_v1::invalid_header);

    std::memcpy(legacy, storage, requirements.image_bytes);
    auto *legacy_header = reinterpret_cast<profile_artifact_header_v1 *>(legacy);
    legacy_header->schema_version = 1u;
    assert(validate_profile_artifact_v1(legacy, requirements.image_bytes,
               &round_trip) == profile_storage_status_v1::invalid_header);

    std::free(legacy);
    std::free(storage);
}
