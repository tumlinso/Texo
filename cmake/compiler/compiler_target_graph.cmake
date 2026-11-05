include_guard(GLOBAL)

function(texo_validate_frozen_compiler_target_graph)
    foreach(target IN ITEMS texo_compiler_core texo_compiler_diagnostics
            texo_compiler_texo_ir texo_compiler_profiles
            texo_compiler_frontend texo_compiler_planning
            texo_compiler_realization texo_compiler_backends
            texo_compiler_tooling)
        if(NOT TARGET ${target})
            message(FATAL_ERROR "missing compiler thin-waist target: ${target}")
        endif()
    endforeach()
    foreach(target IN ITEMS texo_compiler_core texo_compiler_diagnostics
            texo_compiler_texo_ir texo_compiler_profiles
            texo_compiler_frontend texo_compiler_planning
            texo_compiler_tooling)
        get_target_property(links ${target} INTERFACE_LINK_LIBRARIES)
        if(links MATCHES "CUDA::")
            message(FATAL_ERROR "host compiler target has unconditional CUDA edge: ${target}")
        endif()
    endforeach()
endfunction()
