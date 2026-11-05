include_guard(GLOBAL)

function(texo_configure_legacy_cuda_target target)
    if(NOT TEXO_HAS_CUDA)
        message(FATAL_ERROR "legacy CUDA target requested in a host-only build")
    endif()
    find_package(CUDAToolkit REQUIRED)
    set_target_properties(${target} PROPERTIES
        CUDA_STANDARD 20 CUDA_STANDARD_REQUIRED YES
        CUDA_ARCHITECTURES "${CMAKE_CUDA_ARCHITECTURES}")
    target_link_libraries(${target} PRIVATE CUDA::cudart)
endfunction()

function(texo_include_cuda_provider_manifest)
    if(TEXO_HAS_CUDA)
        include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/providers/TexoProviderPolicy.cmake)
        include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/providers/TexoProviderTargets.cmake)
    endif()
endfunction()
