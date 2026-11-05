include_guard(GLOBAL)

set(TEXO_COMPILER_CI_PRESETS
    host-clang;host-gcc;cuda-nvcc-sm70;cuda-clang;installed-consumer;sanitizer;language-server)

function(texo_validate_compiler_ci_matrix)
    list(LENGTH TEXO_COMPILER_CI_PRESETS preset_count)
    if(NOT preset_count EQUAL 7)
        message(FATAL_ERROR "compiler CI matrix must contain seven canonical presets")
    endif()
endfunction()
