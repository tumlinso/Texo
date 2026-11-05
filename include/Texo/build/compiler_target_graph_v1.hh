#pragma once

#include <Texo/build/compiler_component_target_boundaries_v1.hh>
#include <Texo/build/build_presets_and_ci_matrix_v1.hh>
#include <Texo/build/features_v1.hh>

namespace texo::build {
[[nodiscard]] constexpr bool frozen_compiler_target_graph_v1() {
    return compiler_component_graph_is_acyclic_v1() &&
           compiler_ci_presets_v1.size() == 7 && compiler_cuda_is_optional_v1 &&
           compiler_host_graph_is_cuda_free_v1;
}
}  // namespace texo::build
