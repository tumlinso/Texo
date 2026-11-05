#include <Texo/profile/profile_inspection_and_diff_v1.hh>
#include <cstdio>
namespace texo::profile::v1 {
namespace {

profile_inspection_status_v1 finish(int written, std::size_t capacity, std::size_t *size) {
    if (written < 0) return profile_inspection_status_v1::invalid_argument;
    *size = static_cast<std::size_t>(written);
    return static_cast<std::size_t>(written) < capacity
        ? profile_inspection_status_v1::ok
        : profile_inspection_status_v1::insufficient_capacity;
}

}  // namespace

profile_inspection_status_v1 dump_profile_summary_v1(
    const profile_inspection_state_v1 &state, profile_inspection_format_v1 format,
    char *buffer, std::size_t capacity, std::size_t *size) noexcept {
    if (!buffer || !capacity || !size) return profile_inspection_status_v1::invalid_argument;
    const int written = format == profile_inspection_format_v1::machine_json
        ? std::snprintf(buffer, capacity,
            "{\"identity\":\"%llu:%llu\",\"revision\":%llu,\"confidence\":%.3f,\"range\":[%.3f,%.3f],\"expected_mutations\":%u,\"missing_evidence\":%u}",
            (unsigned long long)state.identity_high, (unsigned long long)state.identity_low,
            (unsigned long long)state.evidence_revision, state.confidence, state.minimum,
            state.maximum, state.expected_mutations, state.missing_evidence)
        : std::snprintf(buffer, capacity,
            "profile %llu:%llu revision %llu confidence %.3f range [%.3f, %.3f]; expected mutations 0x%x; missing evidence 0x%x",
            (unsigned long long)state.identity_high, (unsigned long long)state.identity_low,
            (unsigned long long)state.evidence_revision, state.confidence, state.minimum,
            state.maximum, state.expected_mutations, state.missing_evidence);
    return finish(written, capacity, size);
}

profile_inspection_status_v1 diff_profile_states_v1(
    const profile_inspection_state_v1 &before, const profile_inspection_state_v1 &after,
    profile_inspection_format_v1 format, char *out, std::size_t capacity,
    std::size_t *size) noexcept {
    if (!out || !capacity || !size) return profile_inspection_status_v1::invalid_argument;
    const bool range_changed = before.minimum != after.minimum || before.maximum != after.maximum;
    const int written = format == profile_inspection_format_v1::machine_json
        ? std::snprintf(out, capacity,
            "{\"revision_delta\":%lld,\"confidence_delta\":%.3f,\"range_changed\":%s,\"mutation_xor\":%u,\"missing_xor\":%u}",
            (long long)after.evidence_revision - (long long)before.evidence_revision,
            after.confidence - before.confidence, range_changed ? "true" : "false",
            before.expected_mutations ^ after.expected_mutations,
            before.missing_evidence ^ after.missing_evidence)
        : std::snprintf(out, capacity,
            "revision %+lld; confidence %+.3f; range %s; mutation delta 0x%x; missing evidence delta 0x%x",
            (long long)after.evidence_revision - (long long)before.evidence_revision,
            after.confidence - before.confidence, range_changed ? "changed" : "unchanged",
            before.expected_mutations ^ after.expected_mutations,
            before.missing_evidence ^ after.missing_evidence);
    return finish(written, capacity, size);
}
}  // namespace texo::profile::v1
