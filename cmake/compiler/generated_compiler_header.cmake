include_guard(GLOBAL)

set(TEXO_COMPILER_VERSION "1.0.0" CACHE STRING "Compiler version")
set(TEXO_LANGUAGE_REVISION "1" CACHE STRING "Source language revision")
set(TEXO_TEXO_IR_REVISION "1" CACHE STRING "TEXO_IR revision")

function(texo_generate_compiler_build_header output)
    file(GENERATE OUTPUT "${output}" CONTENT
"#pragma once
#define TEXO_COMPILER_VERSION \"${TEXO_COMPILER_VERSION}\"
#define TEXO_LANGUAGE_REVISION ${TEXO_LANGUAGE_REVISION}
#define TEXO_TEXO_IR_REVISION ${TEXO_TEXO_IR_REVISION}
#define TEXO_HAS_CUDA_BACKEND $<BOOL:${TEXO_HAS_CUDA}>
#define TEXO_INSTALL_RESOURCE_PATH \"${CMAKE_INSTALL_PREFIX}/lib/texo\"
")
endfunction()
