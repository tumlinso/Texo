include_guard(GLOBAL)

function(texo_add_compiler_component target alias)
    if(NOT TARGET ${target})
        add_library(${target} INTERFACE)
        add_library(Texo::${alias} ALIAS ${target})
        target_include_directories(${target} INTERFACE
            $<BUILD_INTERFACE:${TEXO_COMPILER_REPOSITORY_ROOT}/include>
            $<INSTALL_INTERFACE:include>)
    endif()
endfunction()

function(texo_create_compiler_component_targets)
    texo_add_compiler_component(texo_compiler_core CompilerCore)
    texo_add_compiler_component(texo_compiler_diagnostics CompilerDiagnostics)
    texo_add_compiler_component(texo_compiler_texo_ir IR)
    texo_add_compiler_component(texo_compiler_profiles CompilerProfiles)
    texo_add_compiler_component(texo_compiler_frontend CompilerFrontend)
    texo_add_compiler_component(texo_compiler_planning CompilerPlanning)
    texo_add_compiler_component(texo_compiler_realization CompilerRealization)
    texo_add_compiler_component(texo_compiler_backends CompilerBackends)
    texo_add_compiler_component(texo_compiler_tooling CompilerTooling)

    target_link_libraries(texo_compiler_diagnostics INTERFACE Texo::CompilerCore)
    target_link_libraries(texo_compiler_texo_ir INTERFACE Texo::CompilerCore Texo::CompilerDiagnostics)
    target_link_libraries(texo_compiler_profiles INTERFACE Texo::IR)
    target_link_libraries(texo_compiler_frontend INTERFACE Texo::IR Texo::CompilerDiagnostics)
    target_link_libraries(texo_compiler_planning INTERFACE Texo::IR Texo::CompilerProfiles)
    target_link_libraries(texo_compiler_realization INTERFACE Texo::CompilerPlanning)
    target_link_libraries(texo_compiler_backends INTERFACE Texo::CompilerRealization)
    target_link_libraries(texo_compiler_tooling INTERFACE
        Texo::CompilerFrontend Texo::CompilerBackends)
endfunction()
