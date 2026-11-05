#include <Texo/diagnostics/what_changed_and_staleness_explanations_v1.hh>
namespace texo::diagnostics::v1 {
staleness_explanation explain_staleness(const generation_change &change) noexcept {
    using stage = cellerator::execution::lowering_resumption::lowering_stage_v1;
    if (!change.statement || !change.before || !change.after || change.before == change.after)
        return {};
    switch (change.kind) {
    case generation_kind::structure: return {true, 0xff, stage::atom_evidence};
    case generation_kind::value: return {true, 0xc0, stage::packed_operand};
    case generation_kind::support: return {true, 0xfe, stage::atom_evidence};
    case generation_kind::order: return {true, 0xfc, stage::semantic_atom};
    case generation_kind::profile: return {true, 0xf8, stage::target_cover};
    }
    return {};
}
}
