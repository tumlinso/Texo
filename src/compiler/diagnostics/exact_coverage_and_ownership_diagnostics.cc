#include <Texo/diagnostics/exact_coverage_and_ownership_diagnostics_v1.hh>
namespace texo::diagnostics::v1 {
coverage_diagnostic diagnose_exact_coverage(const coverage_evidence &evidence) noexcept {
    if (evidence.failure == coverage_failure::none)
        return {true, evidence.member, "exact coverage and contribution ownership verified"};
    if (!evidence.member) return {false, 0, "failure lacks member-level evidence"};

    switch (evidence.failure) {
    case coverage_failure::omission:
        return {false, evidence.member, "member omitted from exact cover"};
    case coverage_failure::duplicate:
        return {false, evidence.member, "member has duplicate contributors"};
    case coverage_failure::wrong_role:
        return {false, evidence.member, "member assigned an incompatible contribution role"};
    case coverage_failure::incompatible_partial_algebra:
        return {false, evidence.member, "partial contributors use incompatible algebra"};
    case coverage_failure::halo_as_contributor:
        return {false, evidence.member, "halo member incorrectly owns a contribution"};
    case coverage_failure::canonical_recovery_failure:
        return {false, evidence.member, "member cannot recover canonical identity"};
    case coverage_failure::none:
        break;
    }
    return {false, evidence.member, "unknown coverage failure"};
}
}
