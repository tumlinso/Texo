#include <Texo/sdk/direct_runtime_execution_access_v1.hh>

int main() {
    [[maybe_unused]] cellerator::execution::persistent_axis_identity axis{};
    [[maybe_unused]] cellerator::compute::math::core::operation_problem operation{};
    [[maybe_unused]] cellerator::compute::operation::relation_algebra_problem_v1 relation{};
    [[maybe_unused]] cellerator::compute::math::core::candidate_descriptor_v2 candidate{};
    [[maybe_unused]] cellerator::planner::planning_keys planning{};

    using texo::api::v1::is_direct_runtime_surface_v1;
    return is_direct_runtime_surface_v1("biological-abi") &&
           is_direct_runtime_surface_v1("operation-core") &&
           is_direct_runtime_surface_v1("relation-algebra") &&
           is_direct_runtime_surface_v1("candidate-catalog") &&
           is_direct_runtime_surface_v1("end-to-end-planner") &&
           !is_direct_runtime_surface_v1("c-runtime-abi") &&
           !is_direct_runtime_surface_v1("compiler-required") ? 0 : 1;
}
