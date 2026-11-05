#include <Texo/sema/relation_endpoint_semantics_v1.hh>

namespace texo::sema::v1 {
namespace {

cellerator::execution::persistent_axis_identity persist(const axis_type &axis) noexcept {
    return {{cellerator::execution::biological_abi_version,
             cellerator::execution::serialized_record_kind::persistent_axis_identity,
             sizeof(cellerator::execution::persistent_axis_identity)},
            {axis.domain.identity.low, axis.domain.identity.high},
            {axis.logical_order.low, axis.logical_order.high},
            {axis.geometry.low, axis.geometry.high},
            {axis.partition.low, axis.partition.high}};
}

bool same_axis(const cellerator::execution::persistent_axis_identity &a,
               const cellerator::execution::persistent_axis_identity &b) noexcept {
    return ::cellerator::structure::same_identity(a.domain, b.domain)
        && ::cellerator::structure::same_identity(a.order, b.order)
        && ::cellerator::structure::same_identity(a.geometry, b.geometry)
        && ::cellerator::structure::same_identity(a.partition, b.partition);
}

}  // namespace

cellerator::compute::operation::v2::typed_relation to_runtime_relation(
    const relation_endpoint_semantics &relation) noexcept {
    return {relation.structure, relation.epoch, persist(relation.source),
            persist(relation.destination), relation.logical_edge_order,
            relation.logical_edge_count};
}

bool agrees_with_runtime_relation(
    const relation_endpoint_semantics &source,
    const cellerator::compute::operation::v2::typed_relation &runtime) noexcept {
    const auto expected = to_runtime_relation(source);
    return ::cellerator::structure::same_identity(expected.structure, runtime.structure)
        && expected.epoch.value == runtime.epoch.value
        && same_axis(expected.source_axis, runtime.source_axis)
        && same_axis(expected.destination_axis, runtime.destination_axis)
        && ::cellerator::structure::same_identity(expected.logical_edge_order,
                                    runtime.logical_edge_order)
        && expected.logical_edge_count == runtime.logical_edge_count;
}

}  // namespace texo::sema::v1
