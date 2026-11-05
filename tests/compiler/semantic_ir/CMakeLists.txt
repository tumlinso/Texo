cmake_minimum_required(VERSION 3.20)
project(texo_compiler_semantic_ir_tests LANGUAGES CXX)

enable_testing()

get_filename_component(TEXO_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

add_executable(texo_semantic_ir_module_and_symbol_scopes_test
    semantic_ir_module_and_symbol_scopes_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/semantic_ir_module_and_symbol_scopes.cc")
target_include_directories(texo_semantic_ir_module_and_symbol_scopes_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_semantic_ir_module_and_symbol_scopes_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_semantic_ir_module_and_symbol_scopes_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_semantic_ir_module_and_symbol_scopes_test COMMAND texo_semantic_ir_module_and_symbol_scopes_test)

add_executable(texo_domain_and_axis_ir_types_test
    domain_and_axis_ir_types_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/domain_and_axis_ir_types.cc")
target_include_directories(texo_domain_and_axis_ir_types_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_domain_and_axis_ir_types_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_domain_and_axis_ir_types_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_domain_and_axis_ir_types_test COMMAND texo_domain_and_axis_ir_types_test)

add_executable(texo_state_and_value_plane_ir_types_test
    state_and_value_plane_ir_types_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/state_and_value_plane_ir_types.cc")
target_include_directories(texo_state_and_value_plane_ir_types_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_state_and_value_plane_ir_types_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_state_and_value_plane_ir_types_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_state_and_value_plane_ir_types_test COMMAND texo_state_and_value_plane_ir_types_test)

add_executable(texo_relation_ir_types_test
    relation_ir_types_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/relation_ir_types.cc"
    "${TEXO_ROOT}/src/compiler/ir/semantic/domain_and_axis_ir_types.cc")
target_include_directories(texo_relation_ir_types_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_relation_ir_types_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_relation_ir_types_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_relation_ir_types_test COMMAND texo_relation_ir_types_test)

add_executable(texo_execution_field_regions_test
    execution_field_regions_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/execution_field_regions.cc"
    "${TEXO_ROOT}/src/compiler/ir/semantic/semantic_ir_module_and_symbol_scopes.cc")
target_include_directories(texo_execution_field_regions_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_execution_field_regions_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_execution_field_regions_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_execution_field_regions_test COMMAND texo_execution_field_regions_test)

add_executable(texo_relation_apply_and_transpose_operations_test
    relation_apply_and_transpose_operations_test.cc
    "${TEXO_ROOT}/src/compute/operation/relation_semantics.cc"
    "${TEXO_ROOT}/src/compiler/ir/semantic/relation_apply_and_transpose_operations.cc"
    "${TEXO_ROOT}/src/compiler/ir/semantic/relation_ir_types.cc"
    "${TEXO_ROOT}/src/compiler/ir/semantic/state_and_value_plane_ir_types.cc"
    "${TEXO_ROOT}/src/compiler/ir/semantic/domain_and_axis_ir_types.cc")
target_include_directories(texo_relation_apply_and_transpose_operations_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_relation_apply_and_transpose_operations_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_relation_apply_and_transpose_operations_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_relation_apply_and_transpose_operations_test COMMAND texo_relation_apply_and_transpose_operations_test)

add_executable(texo_contraction_segment_normalization_test
    contraction_segment_normalization_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/contraction_segment_normalization.cc")
target_include_directories(texo_contraction_segment_normalization_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_contraction_segment_normalization_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_contraction_segment_normalization_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_contraction_segment_normalization_test COMMAND texo_contraction_segment_normalization_test)

add_executable(texo_edge_map_gate_support_mask_and_sparse_update_o_test
    edge_map_gate_support_mask_and_sparse_update_o_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/edge_map_gate_support_mask_and_sparse_update_o.cc"
    "${TEXO_ROOT}/src/compiler/ir/semantic/domain_and_axis_ir_types.cc")
target_include_directories(texo_edge_map_gate_support_mask_and_sparse_update_o_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_edge_map_gate_support_mask_and_sparse_update_o_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_edge_map_gate_support_mask_and_sparse_update_o_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_edge_map_gate_support_mask_and_sparse_update_o_test COMMAND texo_edge_map_gate_support_mask_and_sparse_update_o_test)

add_executable(texo_bundle_chain_moments_hierarchy_and_exchange_op_test
    bundle_chain_moments_hierarchy_and_exchange_op_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/bundle_chain_moments_hierarchy_and_exchange_op.cc")
target_include_directories(texo_bundle_chain_moments_hierarchy_and_exchange_op_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_bundle_chain_moments_hierarchy_and_exchange_op_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_bundle_chain_moments_hierarchy_and_exchange_op_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_bundle_chain_moments_hierarchy_and_exchange_op_test COMMAND texo_bundle_chain_moments_hierarchy_and_exchange_op_test)

add_executable(texo_gradient_and_publication_operations_test
    gradient_and_publication_operations_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/gradient_and_publication_operations.cc"
    "${TEXO_ROOT}/src/compute/operation/relation_calculus.cc"
    "${TEXO_ROOT}/src/compute/operation/relation_semantics.cc")
target_include_directories(texo_gradient_and_publication_operations_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_gradient_and_publication_operations_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_gradient_and_publication_operations_test PRIVATE -UNDEBUG -Wall -Wextra -Werror)
endif()
add_test(NAME texo_gradient_and_publication_operations_test COMMAND texo_gradient_and_publication_operations_test)

add_executable(texo_native_and_opaque_c_call_operations_test
    native_and_opaque_c_call_operations_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/native_and_opaque_c_call_operations.cc")
target_include_directories(texo_native_and_opaque_c_call_operations_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_native_and_opaque_c_call_operations_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_native_and_opaque_c_call_operations_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_native_and_opaque_c_call_operations_test COMMAND texo_native_and_opaque_c_call_operations_test)

add_executable(texo_control_flow_and_loop_semantics_test
    control_flow_and_loop_semantics_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/control_flow_and_loop_semantics.cc")
target_include_directories(texo_control_flow_and_loop_semantics_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_control_flow_and_loop_semantics_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_control_flow_and_loop_semantics_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_control_flow_and_loop_semantics_test COMMAND texo_control_flow_and_loop_semantics_test)

add_executable(texo_generation_and_epoch_transition_operations_test
    generation_and_epoch_transition_operations_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/generation_and_epoch_transition_operations.cc")
target_include_directories(texo_generation_and_epoch_transition_operations_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_generation_and_epoch_transition_operations_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_generation_and_epoch_transition_operations_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_generation_and_epoch_transition_operations_test COMMAND texo_generation_and_epoch_transition_operations_test)

add_executable(texo_semantic_ir_inlining_and_composition_test
    semantic_ir_inlining_and_composition_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/semantic_ir_inlining_and_composition.cc")
target_include_directories(texo_semantic_ir_inlining_and_composition_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_semantic_ir_inlining_and_composition_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_semantic_ir_inlining_and_composition_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_semantic_ir_inlining_and_composition_test COMMAND texo_semantic_ir_inlining_and_composition_test)

add_executable(texo_semantic_canonicalization_and_equivalence_test
    semantic_canonicalization_and_equivalence_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/semantic_canonicalization_and_equivalence.cc"
    "${TEXO_ROOT}/src/compiler/ir/semantic/state_and_value_plane_ir_types.cc")
target_include_directories(texo_semantic_canonicalization_and_equivalence_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_semantic_canonicalization_and_equivalence_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_semantic_canonicalization_and_equivalence_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_semantic_canonicalization_and_equivalence_test COMMAND texo_semantic_canonicalization_and_equivalence_test)

add_executable(texo_source_to_semantic_ir_vertical_slice_test
    source_to_semantic_ir_vertical_slice_test.cc
    "${TEXO_ROOT}/src/compiler/ir/semantic/source_to_semantic_ir_vertical_slice.cc")
target_include_directories(texo_source_to_semantic_ir_vertical_slice_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_source_to_semantic_ir_vertical_slice_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_source_to_semantic_ir_vertical_slice_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_source_to_semantic_ir_vertical_slice_test COMMAND texo_source_to_semantic_ir_vertical_slice_test)
