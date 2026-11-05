include_guard(GLOBAL)

function(texo_create_accelerator_compiler_smoke_target)
    if(NOT TEXO_HAS_CUDA)
        return()
    endif()
    find_package(CUDAToolkit REQUIRED)
    add_executable(texo_compiler_smoke_accelerator
        "${CMAKE_CURRENT_FUNCTION_LIST_DIR}/../../tests/compiler/build/accelerator_enabled_compiler_smoke_targets_test.cc")
    target_link_libraries(texo_compiler_smoke_accelerator PRIVATE
        Texo::CompilerRealization CUDA::cudart)
    if(TARGET Cellerator::runtime)
        target_link_libraries(texo_compiler_smoke_accelerator PRIVATE Cellerator::runtime)
    endif()
    if(TARGET Cellerator::architecture_provider)
        target_link_libraries(texo_compiler_smoke_accelerator PRIVATE Cellerator::architecture_provider)
    endif()
    set_target_properties(texo_compiler_smoke_accelerator PROPERTIES CUDA_ARCHITECTURES 70)
endfunction()
