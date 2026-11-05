cmake_minimum_required(VERSION 3.20)
project(texo_compiler_d01_tests LANGUAGES CXX)

enable_testing()

get_filename_component(TEXO_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../../.." ABSOLUTE)

add_executable(texo_texo_ir_common_lexical_conventions_test
    texo_ir_common_lexical_conventions_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/texo_ir_common_lexical_conventions.cc")
target_include_directories(texo_texo_ir_common_lexical_conventions_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_texo_ir_common_lexical_conventions_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_texo_ir_common_lexical_conventions_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_texo_ir_common_lexical_conventions_test COMMAND texo_texo_ir_common_lexical_conventions_test)

add_executable(texo_arena_and_ownership_model_test
    arena_and_ownership_model_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/arena_and_ownership_model.cc")
target_include_directories(texo_arena_and_ownership_model_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_arena_and_ownership_model_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_arena_and_ownership_model_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_arena_and_ownership_model_test COMMAND texo_arena_and_ownership_model_test)

add_executable(texo_common_type_and_attribute_interning_test
    common_type_and_attribute_interning_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/common_type_and_attribute_interning.cc")
target_include_directories(texo_common_type_and_attribute_interning_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_common_type_and_attribute_interning_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_common_type_and_attribute_interning_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_common_type_and_attribute_interning_test COMMAND texo_common_type_and_attribute_interning_test)

add_executable(texo_regions_blocks_values_and_use_def_chains_test
    regions_blocks_values_and_use_def_chains_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/regions_blocks_values_and_use_def_chains.cc")
target_include_directories(texo_regions_blocks_values_and_use_def_chains_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_regions_blocks_values_and_use_def_chains_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_regions_blocks_values_and_use_def_chains_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_regions_blocks_values_and_use_def_chains_test COMMAND texo_regions_blocks_values_and_use_def_chains_test)

add_executable(texo_common_operation_and_extension_records_test
    common_operation_and_extension_records_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/common_operation_and_extension_records.cc")
target_include_directories(texo_common_operation_and_extension_records_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_common_operation_and_extension_records_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_common_operation_and_extension_records_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_common_operation_and_extension_records_test COMMAND texo_common_operation_and_extension_records_test)

add_executable(texo_persistent_and_transient_identity_layers_test
    persistent_and_transient_identity_layers_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/persistent_and_transient_identity_layers.cc")
target_include_directories(texo_persistent_and_transient_identity_layers_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_persistent_and_transient_identity_layers_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_persistent_and_transient_identity_layers_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_persistent_and_transient_identity_layers_test COMMAND texo_persistent_and_transient_identity_layers_test)

add_executable(texo_removable_provenance_sidecars_test
    removable_provenance_sidecars_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/removable_provenance_sidecars.cc")
target_include_directories(texo_removable_provenance_sidecars_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_removable_provenance_sidecars_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_removable_provenance_sidecars_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_removable_provenance_sidecars_test COMMAND texo_removable_provenance_sidecars_test)

add_executable(texo_texo_ir_text_lexer_and_parser_framework_test
    texo_ir_text_lexer_and_parser_framework_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/texo_ir_text_lexer_and_parser_framework.cc")
target_include_directories(texo_texo_ir_text_lexer_and_parser_framework_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_texo_ir_text_lexer_and_parser_framework_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_texo_ir_text_lexer_and_parser_framework_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_texo_ir_text_lexer_and_parser_framework_test COMMAND texo_texo_ir_text_lexer_and_parser_framework_test)

add_executable(texo_deterministic_canonical_printing_test
    deterministic_canonical_printing_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/deterministic_canonical_printing.cc"
    "${TEXO_ROOT}/src/compiler/ir/common/texo_ir_text_lexer_and_parser_framework.cc")
target_include_directories(texo_deterministic_canonical_printing_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_deterministic_canonical_printing_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_deterministic_canonical_printing_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_deterministic_canonical_printing_test COMMAND texo_deterministic_canonical_printing_test)

add_executable(texo_sectioned_binary_texo_ir_serialization_test
    sectioned_binary_texo_ir_serialization_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/sectioned_binary_texo_ir_serialization.cc")
target_include_directories(texo_sectioned_binary_texo_ir_serialization_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_sectioned_binary_texo_ir_serialization_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_sectioned_binary_texo_ir_serialization_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_sectioned_binary_texo_ir_serialization_test COMMAND texo_sectioned_binary_texo_ir_serialization_test)

add_executable(texo_standalone_texo_ir_compiler_input_detection_test
    standalone_texo_ir_compiler_input_detection_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/standalone_texo_ir_compiler_input_detection.cc")
target_include_directories(texo_standalone_texo_ir_compiler_input_detection_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_standalone_texo_ir_compiler_input_detection_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_standalone_texo_ir_compiler_input_detection_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_standalone_texo_ir_compiler_input_detection_test COMMAND texo_standalone_texo_ir_compiler_input_detection_test)

add_executable(texo_validation_mode_plumbing_test
    validation_mode_plumbing_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/validation_mode_plumbing.cc")
target_include_directories(texo_validation_mode_plumbing_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_validation_mode_plumbing_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_validation_mode_plumbing_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_validation_mode_plumbing_test COMMAND texo_validation_mode_plumbing_test)

add_executable(texo_texo_ir_builder_api_test
    texo_ir_builder_api_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/texo_ir_builder_api.cc"
    "${TEXO_ROOT}/src/compiler/ir/common/common_operation_and_extension_records.cc"
    "${TEXO_ROOT}/src/compiler/ir/common/deterministic_canonical_printing.cc")
target_include_directories(texo_texo_ir_builder_api_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_texo_ir_builder_api_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_texo_ir_builder_api_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_texo_ir_builder_api_test COMMAND texo_texo_ir_builder_api_test)

add_executable(texo_texo_ir_common_round_trip_and_artifact_compatibility_test
    texo_ir_common_round_trip_and_artifact_compatibility_test.cc
    "${TEXO_ROOT}/src/compiler/ir/common/texo_ir_common_round_trip_and_artifact_compatibility.cc"
    "${TEXO_ROOT}/src/compiler/ir/common/deterministic_canonical_printing.cc"
    "${TEXO_ROOT}/src/compiler/ir/common/texo_ir_text_lexer_and_parser_framework.cc"
    "${TEXO_ROOT}/src/compiler/ir/common/sectioned_binary_texo_ir_serialization.cc"
    "${TEXO_ROOT}/src/compiler/ir/common/standalone_texo_ir_compiler_input_detection.cc")
target_include_directories(texo_texo_ir_common_round_trip_and_artifact_compatibility_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_texo_ir_common_round_trip_and_artifact_compatibility_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_texo_ir_common_round_trip_and_artifact_compatibility_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_texo_ir_common_round_trip_and_artifact_compatibility_test COMMAND texo_texo_ir_common_round_trip_and_artifact_compatibility_test)
