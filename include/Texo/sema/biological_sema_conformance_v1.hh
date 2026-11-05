#pragma once

#include <Texo/sema/numerical_tuple_semantics_v1.hh>
#include <Texo/sema/operation_kind_resolution_v1.hh>
#include <Texo/sema/output_update_effect_semantics_v1.hh>
#include <Cellerator/compute/operation/relation_algebra_v2/relation_algebra.hh>

#include <cstdint>

namespace texo::sema::v1 {

inline constexpr std::uint32_t biological_sema_conformance_version = 1u;

struct biological_sema_problem {
    cellerator::compute::operation::v2::relation_algebra_problem preserved{};
    source_operation_kind operation = source_operation_kind::relation_apply;
    numerical_tuple numeric{};
    output_effect_semantics output{};
    bool relation_algebra_present = false;
};

biological_sema_problem lower_through_biological_sema(
    const cellerator::compute::operation::v2::operation_problem &problem) noexcept;
biological_sema_problem lower_through_biological_sema(
    const cellerator::compute::operation::v2::relation_algebra_problem &problem) noexcept;
cellerator::compute::operation::v2::operation_problem recover_operation_problem(
    const biological_sema_problem &problem) noexcept;
cellerator::compute::operation::v2::relation_algebra_problem recover_relation_algebra_problem(
    const biological_sema_problem &problem) noexcept;
bool planning_information_preserved(
    const cellerator::compute::operation::v2::relation_algebra_problem &source,
    const biological_sema_problem &lowered) noexcept;

}  // namespace texo::sema::v1
