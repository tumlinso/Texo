#include <Texo/diagnostics/optimization_opportunity_remarks_v1.hh>
namespace texo::diagnostics::v1 {
std::vector<remark_record> emit_optimization_remarks(std::uint32_t seen,
                                                       bool enabled,
                                                       std::uint32_t suppressed) {
    if (!enabled) return {};
    static constexpr std::string_view codes[] = {
        "CE-OPT-PERSISTENCE", "CE-OPT-PROFILE-HINT", "CE-OPT-CANONICALIZE",
        "CE-OPT-PACKING", "CE-OPT-ORDER-SHARE", "CE-OPT-BRANCH"};
    std::vector<remark_record> result;
    for (unsigned i = 0; i < 6; ++i)
        if ((seen & (1U << i)) && !(suppressed & (1U << i)))
            result.push_back({static_cast<optimization_remark>(i), codes[i]});
    return result;
}
}
