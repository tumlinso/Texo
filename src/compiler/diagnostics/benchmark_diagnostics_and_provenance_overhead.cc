#include <Texo/diagnostics/benchmark_diagnostics_and_provenance_overhead_v1.hh>
#include <array>

namespace texo::diagnostics::v1 {
namespace {

bool within(std::uint64_t base, std::uint64_t value, std::uint32_t percent) {
    return base && value <= base + (base * percent) / 100;
}

}  // namespace

bool provenance_overhead_within_budget(const std::vector<provenance_measurement> &measurements,
                                       provenance_budget budget) noexcept {
    for (const auto size : std::array{translation_unit_size::small,
                                      translation_unit_size::large}) {
        const provenance_measurement *baseline = nullptr;
        for (const auto &measurement : measurements)
            if (measurement.size == size && measurement.level == provenance_level::disabled)
                baseline = &measurement;

        if (!baseline || !baseline->compile_ns || !baseline->peak_rss_bytes ||
            !baseline->object_bytes)
            return false;

        for (const auto &measurement : measurements) {
            if (measurement.size != size) continue;
            if (measurement.hot_runtime_bytes != baseline->hot_runtime_bytes ||
                !within(baseline->compile_ns, measurement.compile_ns, budget.compile_percent) ||
                !within(baseline->peak_rss_bytes, measurement.peak_rss_bytes, budget.rss_percent) ||
                !within(baseline->object_bytes, measurement.object_bytes, budget.object_percent))
                return false;
        }
    }
    return true;
}
}
