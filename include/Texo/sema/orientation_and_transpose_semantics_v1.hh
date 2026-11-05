#pragma once

#include <Texo/sema/relation_endpoint_semantics_v1.hh>

namespace texo::sema::v1 {

struct oriented_relation_operation {
    const axis_type *input_axis = nullptr;
    const axis_type *output_axis = nullptr;
    semantic_identity logical_edge_identity{};
    relation_orientation orientation = relation_orientation::forward;
    cellerator::compute::operation::v2::operation_kind runtime_kind =
        cellerator::compute::operation::v2::operation_kind::relation_apply;
};

oriented_relation_operation infer_oriented_operation(
    const relation_endpoint_semantics &relation,
    relation_orientation orientation) noexcept;
bool orientation_agrees_with_runtime(
    const oriented_relation_operation &operation,
    cellerator::compute::operation::v2::relation_orientation orientation,
    cellerator::compute::operation::v2::operation_kind kind) noexcept;

}  // namespace texo::sema::v1
