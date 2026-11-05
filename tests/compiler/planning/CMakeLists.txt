cmake_minimum_required(VERSION 3.20)
project(texo_compiler_planning_tests LANGUAGES CXX)

enable_testing()
get_filename_component(TEXO_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

add_executable(texo_adapt_semantic_geometry_acquisition_to_planning_ir_test
    adapt_semantic_geometry_acquisition_to_planning_ir_test.cc
    "${TEXO_ROOT}/src/compiler/planning/adapt_semantic_geometry_acquisition_to_planning_ir.cc")
target_include_directories(texo_adapt_semantic_geometry_acquisition_to_planning_ir_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_adapt_semantic_geometry_acquisition_to_planning_ir_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_adapt_semantic_geometry_acquisition_to_planning_ir_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_adapt_semantic_geometry_acquisition_to_planning_ir_test COMMAND texo_adapt_semantic_geometry_acquisition_to_planning_ir_test)

add_executable(texo_adapt_decomposition_portfolios_to_planning_ir_test
    adapt_decomposition_portfolios_to_planning_ir_test.cc
    "${TEXO_ROOT}/src/compiler/planning/adapt_decomposition_portfolios_to_planning_ir.cc")
target_include_directories(texo_adapt_decomposition_portfolios_to_planning_ir_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_adapt_decomposition_portfolios_to_planning_ir_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_adapt_decomposition_portfolios_to_planning_ir_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_adapt_decomposition_portfolios_to_planning_ir_test COMMAND texo_adapt_decomposition_portfolios_to_planning_ir_test)

add_executable(texo_represent_split_axes_fragments_halos_and_replicas_test
    represent_split_axes_fragments_halos_and_replicas_test.cc
    "${TEXO_ROOT}/src/compiler/planning/represent_split_axes_fragments_halos_and_replicas.cc")
target_include_directories(texo_represent_split_axes_fragments_halos_and_replicas_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_represent_split_axes_fragments_halos_and_replicas_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_represent_split_axes_fragments_halos_and_replicas_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_represent_split_axes_fragments_halos_and_replicas_test COMMAND texo_represent_split_axes_fragments_halos_and_replicas_test)

add_executable(texo_represent_partial_result_trees_and_algebra_selection_test
    represent_partial_result_trees_and_algebra_selection_test.cc
    "${TEXO_ROOT}/src/compiler/planning/represent_partial_result_trees_and_algebra_selection.cc")
target_include_directories(texo_represent_partial_result_trees_and_algebra_selection_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_represent_partial_result_trees_and_algebra_selection_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_represent_partial_result_trees_and_algebra_selection_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_represent_partial_result_trees_and_algebra_selection_test COMMAND texo_represent_partial_result_trees_and_algebra_selection_test)

add_executable(texo_adapt_multi_extent_direct_binding_and_assembly_fallback_test
    adapt_multi_extent_direct_binding_and_assembly_fallback_test.cc
    "${TEXO_ROOT}/src/compiler/planning/adapt_multi_extent_direct_binding_and_assembly_fallback.cc"
    "${TEXO_ROOT}/src/execution/preparation/external_binding_v1.cc"
    "${TEXO_ROOT}/src/execution/preparation/persistent_identity_v1.cc")
target_include_directories(texo_adapt_multi_extent_direct_binding_and_assembly_fallback_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_adapt_multi_extent_direct_binding_and_assembly_fallback_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_adapt_multi_extent_direct_binding_and_assembly_fallback_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_adapt_multi_extent_direct_binding_and_assembly_fallback_test COMMAND texo_adapt_multi_extent_direct_binding_and_assembly_fallback_test)

add_executable(texo_adapt_candidate_catalog_v3_providers_test
    adapt_candidate_catalog_v3_providers_test.cc
    "${TEXO_ROOT}/src/compiler/planning/adapt_candidate_catalog_v3_providers.cc"
    "${TEXO_ROOT}/src/compute/operation/candidate_catalog/catalog_v3.cc"
    "${TEXO_ROOT}/src/compute/operation/candidate_catalog/inventory_v3.cc")
target_include_directories(texo_adapt_candidate_catalog_v3_providers_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_adapt_candidate_catalog_v3_providers_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_adapt_candidate_catalog_v3_providers_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_adapt_candidate_catalog_v3_providers_test COMMAND texo_adapt_candidate_catalog_v3_providers_test)

add_executable(texo_custom_candidate_registration_test
    custom_candidate_registration_test.cc
    "${TEXO_ROOT}/src/compiler/planning/custom_candidate_registration.cc")
target_include_directories(texo_custom_candidate_registration_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_custom_candidate_registration_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_custom_candidate_registration_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_custom_candidate_registration_test COMMAND texo_custom_candidate_registration_test)

add_executable(texo_candidate_inclusion_exclusion_and_forcing_test
    candidate_inclusion_exclusion_and_forcing_test.cc
    "${TEXO_ROOT}/src/compiler/planning/candidate_inclusion_exclusion_and_forcing.cc")
target_include_directories(texo_candidate_inclusion_exclusion_and_forcing_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_candidate_inclusion_exclusion_and_forcing_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_candidate_inclusion_exclusion_and_forcing_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_candidate_inclusion_exclusion_and_forcing_test COMMAND texo_candidate_inclusion_exclusion_and_forcing_test)

add_executable(texo_adapt_external_global_cost_exchange_test
    adapt_external_global_cost_exchange_test.cc
    "${TEXO_ROOT}/src/compiler/planning/adapt_external_global_cost_exchange.cc"
    "${TEXO_ROOT}/src/planner/external_cost/vector_v1.cc")
target_include_directories(texo_adapt_external_global_cost_exchange_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_adapt_external_global_cost_exchange_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_adapt_external_global_cost_exchange_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_adapt_external_global_cost_exchange_test COMMAND texo_adapt_external_global_cost_exchange_test)

add_executable(texo_complete_cost_normalization_test
    complete_cost_normalization_test.cc
    "${TEXO_ROOT}/src/compiler/planning/complete_cost_normalization.cc")
target_include_directories(texo_complete_cost_normalization_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_complete_cost_normalization_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_complete_cost_normalization_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_complete_cost_normalization_test COMMAND texo_complete_cost_normalization_test)

add_executable(texo_adapt_transition_and_connected_operation_costs_test
    adapt_transition_and_connected_operation_costs_test.cc
    "${TEXO_ROOT}/src/compiler/planning/adapt_transition_and_connected_operation_costs.cc")
target_include_directories(texo_adapt_transition_and_connected_operation_costs_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_adapt_transition_and_connected_operation_costs_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_adapt_transition_and_connected_operation_costs_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_adapt_transition_and_connected_operation_costs_test COMMAND texo_adapt_transition_and_connected_operation_costs_test)

add_executable(texo_planner_portfolio_dispatch_test
    planner_portfolio_dispatch_test.cc
    "${TEXO_ROOT}/src/compiler/planning/planner_portfolio_dispatch.cc")
target_include_directories(texo_planner_portfolio_dispatch_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_planner_portfolio_dispatch_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_planner_portfolio_dispatch_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_planner_portfolio_dispatch_test COMMAND texo_planner_portfolio_dispatch_test)

add_executable(texo_profile_family_plan_variants_test
    profile_family_plan_variants_test.cc
    "${TEXO_ROOT}/src/compiler/planning/profile_family_plan_variants.cc")
target_include_directories(texo_profile_family_plan_variants_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_profile_family_plan_variants_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_profile_family_plan_variants_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_profile_family_plan_variants_test COMMAND texo_profile_family_plan_variants_test)

add_executable(texo_planning_cache_and_invalidation_test
    planning_cache_and_invalidation_test.cc
    "${TEXO_ROOT}/src/compiler/planning/planning_cache_and_invalidation.cc")
target_include_directories(texo_planning_cache_and_invalidation_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_planning_cache_and_invalidation_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_planning_cache_and_invalidation_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_planning_cache_and_invalidation_test COMMAND texo_planning_cache_and_invalidation_test)

add_executable(texo_planning_reports_test
    planning_reports_test.cc
    "${TEXO_ROOT}/src/compiler/planning/planning_reports.cc")
target_include_directories(texo_planning_reports_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_planning_reports_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_planning_reports_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_planning_reports_test COMMAND texo_planning_reports_test)

add_executable(texo_benchmark_planning_scalability_and_boundedness_test
    benchmark_planning_scalability_and_boundedness_test.cc
    "${TEXO_ROOT}/src/compiler/planning/benchmark_planning_scalability_and_boundedness.cc")
target_include_directories(texo_benchmark_planning_scalability_and_boundedness_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_benchmark_planning_scalability_and_boundedness_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_benchmark_planning_scalability_and_boundedness_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_benchmark_planning_scalability_and_boundedness_test COMMAND texo_benchmark_planning_scalability_and_boundedness_test)

set(TEXO_COMPILER_INTERFACE_ROOT "" CACHE PATH
    "Root containing frozen compiler interface headers from a contract-split lane")
if(EXISTS "${TEXO_ROOT}/include/Texo/ir/planning/planning_ir_v1.hh")
    set(TEXO_PLANNING_INTERFACE_INCLUDE "${TEXO_ROOT}/include")
elseif(TEXO_COMPILER_INTERFACE_ROOT AND
       EXISTS "${TEXO_COMPILER_INTERFACE_ROOT}/include/Texo/ir/planning/planning_ir_v1.hh")
    set(TEXO_PLANNING_INTERFACE_INCLUDE
        "${TEXO_COMPILER_INTERFACE_ROOT}/include")
else()
    message(FATAL_ERROR
        "CE-CCP1-I19 planning_ir_v1.hh is required; set TEXO_COMPILER_INTERFACE_ROOT for a contract-split lane build")
endif()

add_executable(texo_source_to_plan_pipeline_test
    source_to_plan_pipeline_test.cc
    "${TEXO_ROOT}/src/compiler/planning/source_to_plan_pipeline.cc"
    "${TEXO_ROOT}/src/compiler/planning/adapt_decomposition_portfolios_to_planning_ir.cc"
    "${TEXO_ROOT}/src/compiler/planning/complete_cost_normalization.cc"
    "${TEXO_ROOT}/src/compiler/ir/semantic/source_to_semantic_ir_vertical_slice.cc")
target_include_directories(texo_source_to_plan_pipeline_test PRIVATE
    "${TEXO_ROOT}/include" "${TEXO_PLANNING_INTERFACE_INCLUDE}")
target_compile_features(texo_source_to_plan_pipeline_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_source_to_plan_pipeline_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_source_to_plan_pipeline_test COMMAND texo_source_to_plan_pipeline_test)

set(TEXO_DISCOVERY_INTERFACE_ROOT "" CACHE PATH
    "Root containing frozen discovery interface headers from a contract-split lane")
set(TEXO_COMPOSITION_INTERFACE_ROOT "" CACHE PATH
    "Root containing frozen composition interface headers from a contract-split lane")

if(EXISTS "${TEXO_ROOT}/include/Texo/discovery/discovery_v1.hh")
    set(TEXO_DISCOVERY_INTERFACE_INCLUDE "${TEXO_ROOT}/include")
elseif(TEXO_DISCOVERY_INTERFACE_ROOT AND
       EXISTS "${TEXO_DISCOVERY_INTERFACE_ROOT}/include/Texo/discovery/discovery_v1.hh")
    set(TEXO_DISCOVERY_INTERFACE_INCLUDE
        "${TEXO_DISCOVERY_INTERFACE_ROOT}/include")
else()
    message(FATAL_ERROR
        "CE-CCP1-I20 discovery_v1.hh is required; set TEXO_DISCOVERY_INTERFACE_ROOT for a contract-split lane build")
endif()

if(EXISTS "${TEXO_ROOT}/include/Texo/composition/grammar_v1.hh" AND
   EXISTS "${TEXO_ROOT}/include/Texo/program/ruleset_v1.hh")
    set(TEXO_COMPOSITION_INTERFACE_INCLUDE "${TEXO_ROOT}/include")
elseif(TEXO_COMPOSITION_INTERFACE_ROOT AND
       EXISTS "${TEXO_COMPOSITION_INTERFACE_ROOT}/include/Texo/composition/grammar_v1.hh" AND
       EXISTS "${TEXO_COMPOSITION_INTERFACE_ROOT}/include/Texo/program/ruleset_v1.hh")
    set(TEXO_COMPOSITION_INTERFACE_INCLUDE
        "${TEXO_COMPOSITION_INTERFACE_ROOT}/include")
else()
    message(FATAL_ERROR
        "CE-CCP1-I21/I22 composition interfaces are required; set TEXO_COMPOSITION_INTERFACE_ROOT for a contract-split lane build")
endif()

add_executable(texo_public_planning_compiler_interface_test
    public_planning_compiler_interface_test.cc
    "${TEXO_ROOT}/src/compiler/planning/public_planning_compiler_interface.cc")
target_include_directories(texo_public_planning_compiler_interface_test PRIVATE
    "${TEXO_ROOT}/include"
    "${TEXO_PLANNING_INTERFACE_INCLUDE}"
    "${TEXO_DISCOVERY_INTERFACE_INCLUDE}"
    "${TEXO_COMPOSITION_INTERFACE_INCLUDE}")
target_compile_features(texo_public_planning_compiler_interface_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_public_planning_compiler_interface_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_public_planning_compiler_interface_test COMMAND texo_public_planning_compiler_interface_test)
