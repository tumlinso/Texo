#include <Texo/diagnostics/candidate_decision_reports_v1.hh>
namespace texo::diagnostics::v1 {
decision_report build_candidate_report(std::vector<candidate_record> candidates) {
    decision_report report{std::move(candidates)};
    unsigned selected_count = 0;
    for (const auto &candidate : report.candidates) {
        if (!candidate.id || !candidate.complete_cost_ns ||
            (candidate.legal && candidate.rejection_reason) ||
            (!candidate.legal && !candidate.rejection_reason))
            return report;
        if (candidate.legal) report.legal_total_ns += candidate.complete_cost_ns;
        if (!candidate.selected) continue;
        ++selected_count;
        report.selected_id = candidate.id;
        report.selected_cost_ns = candidate.complete_cost_ns;
        if (!candidate.legal) return report;
    }
    report.valid = selected_count == 1;
    return report;
}
}
