#include <Texo/profile/streaming_profile_builders_v1.hh>

#include <cmath>
#include <cstring>

namespace texo::profile::v1 {

std::uint64_t streaming_profile_workspace_bytes_v1(
    const streaming_profile_policy_v1 &policy) noexcept {
    return 8ull * policy.histogram_bins + 8ull * policy.top_l + 8ull * policy.sketch_slots +
           (policy.exact_small_mode ? 8ull * policy.top_l : 0ull);
}

streaming_profile_status_v1 initialize_streaming_profile_builder_v1(
    const streaming_profile_policy_v1 &policy, streaming_profile_workspace_v1 workspace,
    streaming_profile_builder_v1 *out) noexcept {
    const auto bytes = streaming_profile_workspace_bytes_v1(policy);
    if (!out || !policy.histogram_bins || !policy.sketch_slots)
        return streaming_profile_status_v1::invalid_argument;
    if (bytes > policy.memory_budget_bytes || bytes > workspace.capacity_bytes ||
        !workspace.histogram || !workspace.top_values || !workspace.sketch ||
        (policy.exact_small_mode && !workspace.exact_values))
        return streaming_profile_status_v1::insufficient_budget;

    std::memset(workspace.histogram, 0, 8 * policy.histogram_bins);
    std::memset(workspace.top_values, 0, 8 * policy.top_l);
    std::memset(workspace.sketch, 0, 8 * policy.sketch_slots);
    *out = {policy, workspace};
    return streaming_profile_status_v1::ok;
}

streaming_profile_status_v1 update_streaming_profile_builder_v1(
    streaming_profile_builder_v1 *builder, const double *values, std::uint64_t count) noexcept {
    if (!builder || (count && !values)) return streaming_profile_status_v1::invalid_argument;
    for (std::uint64_t i = 0; i < count; ++i) {
        if (!std::isfinite(values[i])) continue;
        if (!builder->count) builder->minimum = builder->maximum = values[i];
        builder->minimum = values[i] < builder->minimum ? values[i] : builder->minimum;
        builder->maximum = values[i] > builder->maximum ? values[i] : builder->maximum;
        ++builder->count;
        const double delta = values[i] - builder->mean;
        builder->mean += delta / builder->count;
        builder->m2 += delta * (values[i] - builder->mean);

        const auto hash = static_cast<std::uint64_t>(
            std::abs(values[i]) * 11400714819323198485ull);
        builder->workspace.sketch[hash % builder->policy.sketch_slots] |= 1ull << (hash % 63u);
        ++builder->workspace.histogram[hash % builder->policy.histogram_bins];
        for (std::uint32_t j = 0; j < builder->policy.top_l; ++j) {
            if (std::abs(values[i]) <= std::abs(builder->workspace.top_values[j])) continue;
            for (std::uint32_t k = builder->policy.top_l - 1; k > j; --k)
                builder->workspace.top_values[k] = builder->workspace.top_values[k - 1];
            builder->workspace.top_values[j] = values[i];
            break;
        }
        if (builder->policy.exact_small_mode) {
            if (builder->exact_count >= builder->policy.top_l)
                return streaming_profile_status_v1::capacity_exceeded;
            builder->workspace.exact_values[builder->exact_count++] = values[i];
        }
    }
    return streaming_profile_status_v1::ok;
}

streaming_profile_status_v1 finalize_streaming_profile_builder_v1(
    const streaming_profile_builder_v1 &builder, streaming_profile_result_v1 *result) noexcept {
    if (!result) return streaming_profile_status_v1::invalid_argument;
    std::uint64_t occupied_bits = 0;
    for (std::uint32_t i = 0; i < builder.policy.sketch_slots; ++i)
        occupied_bits += __builtin_popcountll(builder.workspace.sketch[i]);
    *result = {builder.count, streaming_profile_workspace_bytes_v1(builder.policy),
               builder.mean, builder.count ? builder.m2 / builder.count : 0.0,
               static_cast<double>(occupied_bits),
               1.0 / std::sqrt(static_cast<double>(builder.policy.sketch_slots))};
    return streaming_profile_status_v1::ok;
}

streaming_profile_status_v1 count_scan_fill_offsets_v1(
    const std::uint32_t *counts, std::uint32_t n, std::uint64_t *offsets,
    std::uint32_t capacity, std::uint64_t *total) noexcept {
    if (!counts || !offsets || !total || capacity < n + 1u)
        return streaming_profile_status_v1::invalid_argument;
    offsets[0] = 0;
    for (std::uint32_t i = 0; i < n; ++i) offsets[i + 1] = offsets[i] + counts[i];
    *total = offsets[n];
    return streaming_profile_status_v1::ok;
}

}  // namespace texo::profile::v1
