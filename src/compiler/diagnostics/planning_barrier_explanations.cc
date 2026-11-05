#include <Texo/diagnostics/planning_barrier_explanations_v1.hh>
namespace texo::diagnostics::v1 {
barrier_report explain_planning_barrier(planning_barrier barrier, source_range range) noexcept {
    static constexpr std::string_view explanations[] = {
        "opaque C++ call blocks motion", "field boundary blocks fusion",
        "unknown extension blocks reasoning", "effect contract blocks reordering",
        "alias uncertainty blocks movement", "profile widening blocks specialization",
        "hard constraint rejects candidate"};
    return {barrier, range, explanations[static_cast<unsigned>(barrier)],
            range.file && range.begin && range.end >= range.begin};
}
}
