#pragma once

// Compiler SDK users have direct access to the C++ biological execution ABI,
// operation core, relation algebra, candidate catalog, and planner.
#include <Cellerator/compute/operation/candidate_catalog_v2.hh>
#include <Cellerator/compute/operation/operation_core.hh>
#include <Cellerator/compute/operation/relation_algebra.hh>
#include <Cellerator/execution/biological_abi.hh>
#include <Cellerator/planner/end_to_end_planner.hh>

#include <array>
#include <string_view>

namespace texo::api::v1 {

inline constexpr std::array<std::string_view, 5> direct_runtime_surfaces_v1{
    "biological-abi", "operation-core", "relation-algebra",
    "candidate-catalog", "end-to-end-planner"};

[[nodiscard]] bool is_direct_runtime_surface_v1(std::string_view name) noexcept;

}  // namespace texo::api::v1
