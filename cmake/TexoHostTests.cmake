enable_testing()

function(texo_host_test name)
    add_executable(${name} ${ARGN})
    target_include_directories(${name} PRIVATE "${PROJECT_SOURCE_DIR}/include")
    target_compile_features(${name} PRIVATE cxx_std_20)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${name} PRIVATE -UNDEBUG)
    endif()
    add_test(NAME ${name} COMMAND ${name})
    set_tests_properties(${name} PROPERTIES WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endfunction()

# These inherited suites exercise source/AST/IR contracts without numerical
# kernels, LLVM discovery, GPU execution, or a Cellerator source checkout.
add_subdirectory(tests/compiler/ast)
add_subdirectory(tests/compiler/ir/texo_ir)
file(GLOB texo_parser_tests CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/tests/compiler/parser/*_test.cc")
file(GLOB texo_source_tests CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/tests/compiler/source/*_test.cc")
foreach(source IN LISTS texo_parser_tests texo_source_tests)
    get_filename_component(stem "${source}" NAME_WE)
    set(target "texo_${stem}")
    texo_host_test(${target} "${source}")
    target_link_libraries(${target} PRIVATE Texo::Frontend)
endforeach()

add_executable(texo_downstream_compiler_invocation_test
    tests/compiler/driver/downstream_compiler_invocation_test.cc)
target_compile_features(texo_downstream_compiler_invocation_test PRIVATE cxx_std_20)
add_test(NAME texo_downstream_compiler_invocation_test
    COMMAND texo_downstream_compiler_invocation_test "$<TARGET_FILE:texo>")
foreach(stem IN ITEMS compiler_resource_discovery resource_manifest)
    texo_host_test(texo_${stem}_test tests/compiler/package/${stem}_test.cc)
endforeach()
texo_host_test(texo_backend_resource_discovery_manifests_test
    tests/compiler/build/backend_resource_discovery_manifests_test.cc)

texo_host_test(texo_profile_artifact_charter_and_name_test
    tests/compiler/profile/profile_artifact_charter_and_name_test.cc
    src/compiler/profile/profile_artifact_charter_and_name.cc)

add_test(NAME texo_driver_passthrough COMMAND texo --driver "${CMAKE_COMMAND}" -E true)
add_test(NAME texod_architecture COMMAND texod)

texo_host_test(texo_profile_format_v2_roundtrip_test
    tests/compiler/profile/profile_format_v2_roundtrip_test.cc
    src/compiler/profile/profile_artifact_charter_and_name.cc
    src/compiler/profile/sectioned_binary_profile_storage.cc)
