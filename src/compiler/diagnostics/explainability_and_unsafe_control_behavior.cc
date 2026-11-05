#include <Texo/diagnostics/explainability_and_unsafe_control_behavior_v1.hh>
namespace texo::diagnostics::v1 {
bool freeze_explainability(const explainability_receipt &receipt) noexcept {
    return receipt.verified_failure && receipt.trusted_continuation &&
           receipt.unsafe_native_lowering && receipt.full_candidate_explanation &&
           receipt.source_native_trace && receipt.provenance_stripping;
}
}
