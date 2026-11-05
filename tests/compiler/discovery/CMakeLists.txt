cmake_minimum_required(VERSION 3.20)
project(texo_compiler_discovery_tests LANGUAGES CXX)

enable_testing()

get_filename_component(TEXO_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)

add_executable(texo_common_jbc_atom_identity_adapters_test
    common_jbc_atom_identity_adapters_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/common_jbc_atom_identity_adapters.cc")
target_include_directories(texo_common_jbc_atom_identity_adapters_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_common_jbc_atom_identity_adapters_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_common_jbc_atom_identity_adapters_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_common_jbc_atom_identity_adapters_test COMMAND texo_common_jbc_atom_identity_adapters_test)

add_executable(texo_overlapping_evidence_atlas_core_test
    overlapping_evidence_atlas_core_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/overlapping_evidence_atlas_core.cc")
target_include_directories(texo_overlapping_evidence_atlas_core_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_overlapping_evidence_atlas_core_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_overlapping_evidence_atlas_core_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_overlapping_evidence_atlas_core_test COMMAND texo_overlapping_evidence_atlas_core_test)

add_executable(texo_support_signature_discovery_test
    support_signature_discovery_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/support_signature_discovery.cc")
target_include_directories(texo_support_signature_discovery_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_support_signature_discovery_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_support_signature_discovery_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_support_signature_discovery_test COMMAND texo_support_signature_discovery_test)

add_executable(texo_co_support_and_overlap_discovery_test
    co_support_and_overlap_discovery_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/co_support_and_overlap_discovery.cc")
target_include_directories(texo_co_support_and_overlap_discovery_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_co_support_and_overlap_discovery_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_co_support_and_overlap_discovery_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_co_support_and_overlap_discovery_test COMMAND texo_co_support_and_overlap_discovery_test)
add_executable(texo_relation_motif_and_operation_trace_discovery_test relation_motif_and_operation_trace_discovery_test.cc "${TEXO_ROOT}/src/compiler/discovery/relation_motif_and_operation_trace_discovery.cc")
target_include_directories(texo_relation_motif_and_operation_trace_discovery_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_relation_motif_and_operation_trace_discovery_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_relation_motif_and_operation_trace_discovery_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_relation_motif_and_operation_trace_discovery_test COMMAND texo_relation_motif_and_operation_trace_discovery_test)

add_executable(texo_trajectory_and_lineage_pattern_discovery_test
    trajectory_and_lineage_pattern_discovery_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/trajectory_and_lineage_pattern_discovery.cc")
target_include_directories(texo_trajectory_and_lineage_pattern_discovery_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_trajectory_and_lineage_pattern_discovery_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_trajectory_and_lineage_pattern_discovery_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_trajectory_and_lineage_pattern_discovery_test COMMAND texo_trajectory_and_lineage_pattern_discovery_test)

add_executable(texo_multimodal_and_identity_spine_discovery_test
    multimodal_and_identity_spine_discovery_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/multimodal_and_identity_spine_discovery.cc")
target_include_directories(texo_multimodal_and_identity_spine_discovery_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_multimodal_and_identity_spine_discovery_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_multimodal_and_identity_spine_discovery_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_multimodal_and_identity_spine_discovery_test COMMAND texo_multimodal_and_identity_spine_discovery_test)

add_executable(texo_factor_bicluster_and_signature_proposal_strategy_test
    factor_bicluster_and_signature_proposal_strategy_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/factor_bicluster_and_signature_proposal_strategy.cc")
target_include_directories(texo_factor_bicluster_and_signature_proposal_strategy_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_factor_bicluster_and_signature_proposal_strategy_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_factor_bicluster_and_signature_proposal_strategy_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_factor_bicluster_and_signature_proposal_strategy_test COMMAND texo_factor_bicluster_and_signature_proposal_strategy_test)

add_executable(texo_exact_rescan_and_proposal_certification_test
    exact_rescan_and_proposal_certification_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/exact_rescan_and_proposal_certification.cc")
target_include_directories(texo_exact_rescan_and_proposal_certification_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_exact_rescan_and_proposal_certification_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_exact_rescan_and_proposal_certification_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_exact_rescan_and_proposal_certification_test COMMAND texo_exact_rescan_and_proposal_certification_test)

add_executable(texo_atom_envelope_and_typed_ports_test
    atom_envelope_and_typed_ports_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/atom_envelope_and_typed_ports.cc"
    "${TEXO_ROOT}/src/compiler/discovery/common_jbc_atom_identity_adapters.cc")
target_include_directories(texo_atom_envelope_and_typed_ports_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_atom_envelope_and_typed_ports_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_atom_envelope_and_typed_ports_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_atom_envelope_and_typed_ports_test COMMAND texo_atom_envelope_and_typed_ports_test)

add_executable(texo_atom_plane_separation_test
    atom_plane_separation_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/atom_plane_separation.cc")
target_include_directories(texo_atom_plane_separation_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_atom_plane_separation_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_atom_plane_separation_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_atom_plane_separation_test COMMAND texo_atom_plane_separation_test)

add_executable(texo_atom_requirement_affordance_matching_test
    atom_requirement_affordance_matching_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/atom_requirement_affordance_matching.cc")
target_include_directories(texo_atom_requirement_affordance_matching_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_atom_requirement_affordance_matching_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_atom_requirement_affordance_matching_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_atom_requirement_affordance_matching_test COMMAND texo_atom_requirement_affordance_matching_test)

add_executable(texo_scalable_certification_indexes_test
    scalable_certification_indexes_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/scalable_certification_indexes.cc")
target_include_directories(texo_scalable_certification_indexes_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_scalable_certification_indexes_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_scalable_certification_indexes_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_scalable_certification_indexes_test COMMAND texo_scalable_certification_indexes_test)

add_executable(texo_migration_provenance_manifest_test
    migration_provenance_manifest_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/migration_provenance_manifest.cc")
target_include_directories(texo_migration_provenance_manifest_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_migration_provenance_manifest_test PRIVATE cxx_std_20)
target_compile_definitions(texo_migration_provenance_manifest_test PRIVATE
    TEXO_SOURCE_ROOT="${TEXO_ROOT}")
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_migration_provenance_manifest_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_migration_provenance_manifest_test COMMAND texo_migration_provenance_manifest_test)

add_executable(texo_temporary_cellshard_compiler_adapter_test
    temporary_cellshard_compiler_adapter_test.cc
    temporary_cellshard_compiler_adapter_old_consumer.cc
    temporary_cellshard_compiler_adapter_new_consumer.cc
    "${TEXO_ROOT}/src/compiler/discovery/temporary_cellshard_compiler_adapter.cc"
    "${TEXO_ROOT}/src/compiler/discovery/atom_envelope_and_typed_ports.cc"
    "${TEXO_ROOT}/src/compiler/discovery/common_jbc_atom_identity_adapters.cc")
target_include_directories(texo_temporary_cellshard_compiler_adapter_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_temporary_cellshard_compiler_adapter_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_temporary_cellshard_compiler_adapter_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_temporary_cellshard_compiler_adapter_test COMMAND texo_temporary_cellshard_compiler_adapter_test)

add_executable(texo_port_discovery_tests_and_evidence_fixtures_test
    port_discovery_tests_and_evidence_fixtures_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/port_discovery_tests_and_evidence_fixtures.cc")
target_include_directories(texo_port_discovery_tests_and_evidence_fixtures_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_port_discovery_tests_and_evidence_fixtures_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_port_discovery_tests_and_evidence_fixtures_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_port_discovery_tests_and_evidence_fixtures_test COMMAND texo_port_discovery_tests_and_evidence_fixtures_test)

add_executable(texo_validate_no_compiler_discovery_remains_authoritative_in_test
    validate_no_compiler_discovery_remains_authoritative_in_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/validate_no_compiler_discovery_remains_authoritative_in.cc")
target_include_directories(texo_validate_no_compiler_discovery_remains_authoritative_in_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_validate_no_compiler_discovery_remains_authoritative_in_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_validate_no_compiler_discovery_remains_authoritative_in_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_validate_no_compiler_discovery_remains_authoritative_in_test COMMAND texo_validate_no_compiler_discovery_remains_authoritative_in_test)

add_executable(texo_migrated_discovery_and_atom_compiler_slice_test
    migrated_discovery_and_atom_compiler_slice_test.cc
    "${TEXO_ROOT}/src/compiler/discovery/migrated_discovery_and_atom_compiler_slice.cc"
    "${TEXO_ROOT}/src/compiler/discovery/atom_envelope_and_typed_ports.cc"
    "${TEXO_ROOT}/src/compiler/discovery/exact_rescan_and_proposal_certification.cc"
    "${TEXO_ROOT}/src/compiler/discovery/support_signature_discovery.cc"
    "${TEXO_ROOT}/src/compiler/discovery/common_jbc_atom_identity_adapters.cc"
    "${TEXO_ROOT}/src/compiler/discovery/temporary_cellshard_compiler_adapter.cc"
    "${TEXO_ROOT}/src/compiler/discovery/port_discovery_tests_and_evidence_fixtures.cc"
    "${TEXO_ROOT}/src/compiler/discovery/migration_provenance_manifest.cc"
    "${TEXO_ROOT}/src/compiler/discovery/validate_no_compiler_discovery_remains_authoritative_in.cc")
target_include_directories(texo_migrated_discovery_and_atom_compiler_slice_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_migrated_discovery_and_atom_compiler_slice_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_migrated_discovery_and_atom_compiler_slice_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_migrated_discovery_and_atom_compiler_slice_test COMMAND texo_migrated_discovery_and_atom_compiler_slice_test)
