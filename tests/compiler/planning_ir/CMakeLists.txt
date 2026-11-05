cmake_minimum_required(VERSION 3.20)
project(texo_compiler_planning_ir_tests LANGUAGES CXX)

enable_testing()
get_filename_component(TEXO_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

add_executable(texo_planning_ir_module_and_decision_state_model_test
    planning_ir_module_and_decision_state_model_test.cc
    "${TEXO_ROOT}/src/compiler/ir/planning/planning_ir_module_and_decision_state_model.cc")
target_include_directories(texo_planning_ir_module_and_decision_state_model_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_planning_ir_module_and_decision_state_model_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_planning_ir_module_and_decision_state_model_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_planning_ir_module_and_decision_state_model_test COMMAND texo_planning_ir_module_and_decision_state_model_test)

add_executable(texo_planning_problems_and_operation_scopes_test
    planning_problems_and_operation_scopes_test.cc
    "${TEXO_ROOT}/src/compiler/ir/planning/planning_problems_and_operation_scopes.cc")
target_include_directories(texo_planning_problems_and_operation_scopes_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_planning_problems_and_operation_scopes_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_planning_problems_and_operation_scopes_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_planning_problems_and_operation_scopes_test COMMAND texo_planning_problems_and_operation_scopes_test)

add_executable(texo_candidate_family_and_provider_nodes_test
    candidate_family_and_provider_nodes_test.cc
    "${TEXO_ROOT}/src/compiler/ir/planning/candidate_family_and_provider_nodes.cc")
target_include_directories(texo_candidate_family_and_provider_nodes_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_candidate_family_and_provider_nodes_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_candidate_family_and_provider_nodes_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_candidate_family_and_provider_nodes_test COMMAND texo_candidate_family_and_provider_nodes_test)

add_executable(texo_exact_logical_coverage_nodes_test
    exact_logical_coverage_nodes_test.cc
    "${TEXO_ROOT}/src/compiler/ir/planning/exact_logical_coverage_nodes.cc")
target_include_directories(texo_exact_logical_coverage_nodes_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_exact_logical_coverage_nodes_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_exact_logical_coverage_nodes_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_exact_logical_coverage_nodes_test COMMAND texo_exact_logical_coverage_nodes_test)

add_executable(texo_atom_requirement_and_affordance_nodes_test
    atom_requirement_and_affordance_nodes_test.cc
    "${TEXO_ROOT}/src/compiler/ir/planning/atom_requirement_and_affordance_nodes.cc"
    "${TEXO_ROOT}/src/execution/preparation/persistent_identity_v1.cc"
    "${TEXO_ROOT}/src/execution/preparation/atom_requirement_v1.cc"
    "${TEXO_ROOT}/src/execution/preparation/atom_affordance_v1.cc")
target_include_directories(texo_atom_requirement_and_affordance_nodes_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_atom_requirement_and_affordance_nodes_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_atom_requirement_and_affordance_nodes_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_atom_requirement_and_affordance_nodes_test COMMAND texo_atom_requirement_and_affordance_nodes_test)

add_executable(texo_decomposition_alternative_nodes_test
    decomposition_alternative_nodes_test.cc
    "${TEXO_ROOT}/src/compiler/ir/planning/decomposition_alternative_nodes.cc")
target_include_directories(texo_decomposition_alternative_nodes_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_decomposition_alternative_nodes_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_decomposition_alternative_nodes_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_decomposition_alternative_nodes_test COMMAND texo_decomposition_alternative_nodes_test)

add_executable(texo_partial_result_algebra_nodes_test
    partial_result_algebra_nodes_test.cc
    "${TEXO_ROOT}/src/compiler/ir/planning/partial_result_algebra_nodes.cc"
    "${TEXO_ROOT}/src/execution/preparation/persistent_identity_v1.cc"
    "${TEXO_ROOT}/src/execution/preparation/partial_result_algebra_v1.cc")
target_include_directories(texo_partial_result_algebra_nodes_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_partial_result_algebra_nodes_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_partial_result_algebra_nodes_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_partial_result_algebra_nodes_test COMMAND texo_partial_result_algebra_nodes_test)

add_executable(texo_persistent_order_packing_alternatives_test
    persistent_order_packing_alternatives_test.cc
    "${TEXO_ROOT}/src/compiler/ir/planning/persistent_order_packing_alternatives.cc")
target_include_directories(texo_persistent_order_packing_alternatives_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_persistent_order_packing_alternatives_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_persistent_order_packing_alternatives_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_persistent_order_packing_alternatives_test COMMAND texo_persistent_order_packing_alternatives_test)
add_executable(texo_resource_and_stage_inventory_alternatives_test resource_and_stage_inventory_alternatives_test.cc "${TEXO_ROOT}/src/compiler/ir/planning/resource_and_stage_inventory_alternatives.cc")
target_include_directories(texo_resource_and_stage_inventory_alternatives_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_resource_and_stage_inventory_alternatives_test PRIVATE cxx_std_20)
add_test(NAME texo_resource_and_stage_inventory_alternatives_test COMMAND texo_resource_and_stage_inventory_alternatives_test)
add_executable(texo_complete_cost_vectors_test complete_cost_vectors_test.cc "${TEXO_ROOT}/src/compiler/ir/planning/complete_cost_vectors.cc")
target_include_directories(texo_complete_cost_vectors_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_complete_cost_vectors_test PRIVATE cxx_std_20)
add_test(NAME texo_complete_cost_vectors_test COMMAND texo_complete_cost_vectors_test)
add_executable(texo_analytical_measured_and_external_evidence_test analytical_measured_and_external_evidence_test.cc "${TEXO_ROOT}/src/compiler/ir/planning/analytical_measured_and_external_evidence.cc")
target_include_directories(texo_analytical_measured_and_external_evidence_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_analytical_measured_and_external_evidence_test PRIVATE cxx_std_20)
add_test(NAME texo_analytical_measured_and_external_evidence_test COMMAND texo_analytical_measured_and_external_evidence_test)
add_executable(texo_rejection_and_dominance_explanations_test rejection_and_dominance_explanations_test.cc "${TEXO_ROOT}/src/compiler/ir/planning/rejection_and_dominance_explanations.cc")
target_include_directories(texo_rejection_and_dominance_explanations_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_rejection_and_dominance_explanations_test PRIVATE cxx_std_20)
add_test(NAME texo_rejection_and_dominance_explanations_test COMMAND texo_rejection_and_dominance_explanations_test)
add_executable(texo_user_edits_and_authority_hierarchy_test user_edits_and_authority_hierarchy_test.cc "${TEXO_ROOT}/src/compiler/ir/planning/user_edits_and_authority_hierarchy.cc")
target_include_directories(texo_user_edits_and_authority_hierarchy_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_user_edits_and_authority_hierarchy_test PRIVATE cxx_std_20)
add_test(NAME texo_user_edits_and_authority_hierarchy_test COMMAND texo_user_edits_and_authority_hierarchy_test)
add_executable(texo_planning_ir_parser_printer_and_validator_test planning_ir_parser_printer_and_validator_test.cc "${TEXO_ROOT}/src/compiler/ir/planning/planning_ir_parser_printer_and_validator.cc")
target_include_directories(texo_planning_ir_parser_printer_and_validator_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_planning_ir_parser_printer_and_validator_test PRIVATE cxx_std_20)
add_test(NAME texo_planning_ir_parser_printer_and_validator_test COMMAND texo_planning_ir_parser_printer_and_validator_test)

add_executable(texo_semantic_to_planning_lowering_test
    semantic_to_planning_lowering_test.cc
    "${TEXO_ROOT}/src/compiler/ir/planning/semantic_to_planning_lowering.cc"
    "${TEXO_ROOT}/src/compiler/ir/planning/planning_problems_and_operation_scopes.cc"
    "${TEXO_ROOT}/src/compiler/ir/semantic/state_and_value_plane_ir_types.cc")
target_include_directories(texo_semantic_to_planning_lowering_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_semantic_to_planning_lowering_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_semantic_to_planning_lowering_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_semantic_to_planning_lowering_test COMMAND texo_semantic_to_planning_lowering_test)

add_executable(texo_candidate_search_space_inspection_test
    candidate_search_space_inspection_test.cc
    "${TEXO_ROOT}/src/compiler/ir/planning/candidate_search_space_inspection.cc"
    "${TEXO_ROOT}/src/compiler/ir/planning/complete_cost_vectors.cc"
    "${TEXO_ROOT}/src/compiler/ir/planning/planning_problems_and_operation_scopes.cc"
    "${TEXO_ROOT}/src/compiler/ir/planning/planning_ir_module_and_decision_state_model.cc")
target_include_directories(texo_candidate_search_space_inspection_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_candidate_search_space_inspection_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_candidate_search_space_inspection_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_candidate_search_space_inspection_test COMMAND texo_candidate_search_space_inspection_test)
