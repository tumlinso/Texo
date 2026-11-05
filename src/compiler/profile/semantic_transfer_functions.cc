#include <Texo/profile/semantic_transfer_functions_v1.hh>

namespace texo::profile::v1 {

semantic_transfer_v1 semantic_transfer_for_operation_v1(
    cellerator::compute::operation::v2::operation_kind operation) noexcept {
    using operation_kind = cellerator::compute::operation::v2::operation_kind;
    using transfer = profile_state_transfer_v1;
    switch (operation) {
    case operation_kind::relation_apply:
    case operation_kind::relation_apply_transpose:
    case operation_kind::contract_on_support:
    case operation_kind::segment_reduce:
    case operation_kind::segment_normalize:
        return {transfer::derive, transfer::preserve, transfer::preserve,
                transfer::preserve, transfer::derive};
    case operation_kind::edge_map_or_gate:
        return {transfer::derive, transfer::derive, transfer::preserve,
                transfer::preserve, transfer::derive};
    case operation_kind::relation_bundle_apply:
        return {transfer::derive, transfer::derive, transfer::derive,
                transfer::derive, transfer::derive};
    case operation_kind::sparse_axis_update:
        return {transfer::derive, transfer::derive, transfer::preserve,
                transfer::preserve, transfer::derive};
    }
    return {};
}

semantic_transfer_v1 semantic_transfer_for_native_effect_v1(std::uint32_t publications,
                                                             bool opaque) noexcept {
    using transfer = profile_state_transfer_v1;
    if (opaque)
        return {transfer::unknown, transfer::unknown, transfer::unknown,
                transfer::unknown, transfer::unknown};
    return {publications & native_publishes_values_v1 ? transfer::invalidate : transfer::preserve,
            publications & native_publishes_support_v1 ? transfer::invalidate : transfer::preserve,
            publications & native_publishes_structure_v1 ? transfer::invalidate : transfer::preserve,
            publications & native_publishes_order_v1 ? transfer::invalidate : transfer::preserve,
            publications ? transfer::derive : transfer::preserve};
}

}  // namespace texo::profile::v1
