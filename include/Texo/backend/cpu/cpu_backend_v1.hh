#pragma once

#include <Texo/backend/benchmark_cpu_backend_complete_cost_v1.hh>
#include <Texo/backend/profile_bound_cpu_object_v1.hh>
#include <Cellerator/compute/cpu/cpu_projection_packing_and_order_transforms_v1.hh>
#include <Cellerator/compute/cpu/cpu_segment_gate_update_bundle_and_chain_paths_v1.hh>
#include <Cellerator/compute/cpu/cpu_transpose_and_contraction_v1.hh>
#include <Cellerator/compute/cpu/generic_cpu_relation_apply_v1.hh>
#include <Texo/backend/host_runtime_binding_abi_v1.hh>

namespace texo::backend::cpu::v1 {
inline constexpr std::uint32_t cpu_backend_contract_version_v1 = 1;
}
