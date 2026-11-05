cmake_minimum_required(VERSION 3.20)
project(texo_compiler_cpu_backend_tests LANGUAGES CXX)

enable_testing()
get_filename_component(TEXO_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../../.." ABSOLUTE)

add_executable(texo_backend_provider_abi_test
    backend_provider_abi_test.cc
    mock_backend_provider_v1.cc
    "${TEXO_ROOT}/src/compiler/backend/backend_provider_abi.cc")
target_include_directories(texo_backend_provider_abi_test PRIVATE
    "${TEXO_ROOT}/include"
    "${CMAKE_CURRENT_LIST_DIR}")
target_compile_features(texo_backend_provider_abi_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_backend_provider_abi_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_backend_provider_abi_test COMMAND texo_backend_provider_abi_test)

add_executable(texo_backend_registry_and_selection_test
    backend_registry_and_selection_test.cc
    mock_backend_provider_v1.cc
    "${TEXO_ROOT}/src/compiler/backend/backend_provider_abi.cc"
    "${TEXO_ROOT}/src/compiler/backend/backend_registry_and_selection.cc")
target_include_directories(texo_backend_registry_and_selection_test PRIVATE
    "${TEXO_ROOT}/include"
    "${CMAKE_CURRENT_LIST_DIR}")
target_compile_features(texo_backend_registry_and_selection_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_backend_registry_and_selection_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_backend_registry_and_selection_test COMMAND texo_backend_registry_and_selection_test)

add_executable(texo_backend_code_generation_plans_test
    backend_code_generation_plans_test.cc
    "${TEXO_ROOT}/src/compiler/backend/backend_code_generation_plans.cc")
target_include_directories(texo_backend_code_generation_plans_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_backend_code_generation_plans_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_backend_code_generation_plans_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_backend_code_generation_plans_test COMMAND texo_backend_code_generation_plans_test)

add_executable(texo_generated_c_representation_test
    generated_c_representation_test.cc
    "${TEXO_ROOT}/src/compiler/backend/generated_c_representation.cc")
target_include_directories(texo_generated_c_representation_test PRIVATE "${TEXO_ROOT}/include")
target_compile_features(texo_generated_c_representation_test PRIVATE cxx_std_20)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(texo_generated_c_representation_test PRIVATE -Wall -Wextra -Werror)
endif()
add_test(NAME texo_generated_c_representation_test COMMAND texo_generated_c_representation_test)





add_executable(texo_compile_generated_c_into_ordinary_objects_test
  compile_generated_c_into_ordinary_objects_test.cc
  ${TEXO_ROOT}/src/compiler/backend/compile_generated_c_into_ordinary_objects.cc)
target_include_directories(texo_compile_generated_c_into_ordinary_objects_test PRIVATE ${TEXO_ROOT}/include)
target_compile_features(texo_compile_generated_c_into_ordinary_objects_test PRIVATE cxx_std_20)
target_compile_options(texo_compile_generated_c_into_ordinary_objects_test PRIVATE -Wall -Wextra -Werror)
add_test(NAME texo_compile_generated_c_into_ordinary_objects_test COMMAND texo_compile_generated_c_into_ordinary_objects_test)

add_executable(texo_host_runtime_binding_abi_test
  host_runtime_binding_abi_test.cc
  ${TEXO_ROOT}/src/compiler/backend/host_runtime_binding_abi.cc)
target_include_directories(texo_host_runtime_binding_abi_test PRIVATE ${TEXO_ROOT}/include)
target_compile_features(texo_host_runtime_binding_abi_test PRIVATE cxx_std_20)
target_compile_options(texo_host_runtime_binding_abi_test PRIVATE -Wall -Wextra -Werror)
target_compile_definitions(texo_host_runtime_binding_abi_test PRIVATE
  TEXO_TEST_INCLUDE_DIR="${TEXO_ROOT}/include"
  TEXO_TEST_BINDING_OBJECT="$<TARGET_OBJECTS:texo_host_runtime_binding_abi_object>")
add_library(texo_host_runtime_binding_abi_object OBJECT
  ${TEXO_ROOT}/src/compiler/backend/host_runtime_binding_abi.cc)
target_include_directories(texo_host_runtime_binding_abi_object PRIVATE ${TEXO_ROOT}/include)
target_compile_features(texo_host_runtime_binding_abi_object PRIVATE cxx_std_20)
add_test(NAME texo_host_runtime_binding_abi_test COMMAND texo_host_runtime_binding_abi_test)

add_executable(texo_map_backend_diagnostics_to_source_and_texo_ir_test
  map_backend_diagnostics_to_source_and_texo_ir_test.cc
  ${TEXO_ROOT}/src/compiler/backend/map_backend_diagnostics_to_source_and_texo_ir.cc)
target_include_directories(texo_map_backend_diagnostics_to_source_and_texo_ir_test PRIVATE ${TEXO_ROOT}/include)
target_compile_features(texo_map_backend_diagnostics_to_source_and_texo_ir_test PRIVATE cxx_std_20)
target_compile_options(texo_map_backend_diagnostics_to_source_and_texo_ir_test PRIVATE -Wall -Wextra -Werror)
add_test(NAME texo_map_backend_diagnostics_to_source_and_texo_ir_test COMMAND texo_map_backend_diagnostics_to_source_and_texo_ir_test)

add_executable(texo_benchmark_cpu_backend_complete_cost_test
  benchmark_cpu_backend_complete_cost_test.cc
  ${TEXO_ROOT}/src/compiler/backend/benchmark_cpu_backend_complete_cost.cc)
target_include_directories(texo_benchmark_cpu_backend_complete_cost_test PRIVATE ${TEXO_ROOT}/include)
target_compile_features(texo_benchmark_cpu_backend_complete_cost_test PRIVATE cxx_std_20)
target_compile_options(texo_benchmark_cpu_backend_complete_cost_test PRIVATE -Wall -Wextra -Werror)
add_test(NAME texo_benchmark_cpu_backend_complete_cost_test COMMAND texo_benchmark_cpu_backend_complete_cost_test)

add_executable(texo_profile_bound_cpu_object_test
  profile_bound_cpu_object_test.cc
  ${TEXO_ROOT}/src/compiler/backend/profile_bound_cpu_object.cc
  ${TEXO_ROOT}/src/compiler/backend/compile_generated_c_into_ordinary_objects.cc)
target_include_directories(texo_profile_bound_cpu_object_test PRIVATE ${TEXO_ROOT}/include)
target_compile_features(texo_profile_bound_cpu_object_test PRIVATE cxx_std_20)
target_compile_options(texo_profile_bound_cpu_object_test PRIVATE -Wall -Wextra -Werror)
add_test(NAME texo_profile_bound_cpu_object_test COMMAND texo_profile_bound_cpu_object_test)

add_executable(texo_cpu_backend_thin_waist_test
  cpu_backend_thin_waist_test.cc
  ${TEXO_ROOT}/src/compiler/backend/cpu_backend_thin_waist.cc)
target_include_directories(texo_cpu_backend_thin_waist_test PRIVATE ${TEXO_ROOT}/include)
target_compile_features(texo_cpu_backend_thin_waist_test PRIVATE cxx_std_20)
target_compile_options(texo_cpu_backend_thin_waist_test PRIVATE -Wall -Wextra -Werror)
target_compile_definitions(texo_cpu_backend_thin_waist_test PRIVATE
  TEXO_TEST_INCLUDE_ROOT="${TEXO_ROOT}/include")
add_test(NAME texo_cpu_backend_thin_waist_test COMMAND texo_cpu_backend_thin_waist_test)
