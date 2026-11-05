#include <Texo/diagnostics/deterministic_reproducer_bundles_v1.hh>
#include <algorithm>
namespace texo::diagnostics::v1 {
reproducer_bundle make_reproducer_bundle(std::vector<bundle_entry> entries) {
    std::sort(entries.begin(), entries.end(), [](const auto &a, const auto &b) {
        return a.kind < b.kind || (a.kind == b.kind && a.content < b.content);
    });
    std::uint64_t hash = 1469598103934665603ULL;
    for (const auto &entry : entries) {
        hash ^= static_cast<unsigned>(entry.kind);
        hash *= 1099511628211ULL;
        for (const unsigned char byte : entry.content) {
            hash ^= byte;
            hash *= 1099511628211ULL;
        }
    }
    return {std::move(entries), hash, false};
}

bool replay_matches(const reproducer_bundle &bundle, std::uint64_t expected) noexcept {
    return !bundle.contains_dataset_payload && bundle.digest && bundle.digest == expected;
}
}
