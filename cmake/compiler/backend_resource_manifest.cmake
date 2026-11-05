include_guard(GLOBAL)

function(texo_generate_backend_resource_manifest output)
    find_program(TEXO_NVCC nvcc)
    find_program(TEXO_CLANG_CUDA NAMES clang++-18 clang++)
    find_program(TEXO_LLVM_CONFIG NAMES llvm-config-18 llvm-config)
    find_program(TEXO_LLC NAMES llc-18 llc)
    find_program(TEXO_PTXAS ptxas)
    find_program(TEXO_LINKER NAMES ld.lld-18 ld.lld ld)
    set(texo_manifest
        "host_cxx=${CMAKE_CXX_COMPILER}\n"
        "nvcc=${TEXO_NVCC}\n"
        "clang_cuda=${TEXO_CLANG_CUDA}\n"
        "llvm_config=${TEXO_LLVM_CONFIG}\n"
        "nvptx=${TEXO_LLC}\n"
        "ptxas=${TEXO_PTXAS}\n"
        "linker=${TEXO_LINKER}\n"
        "resource_dir=${CMAKE_INSTALL_PREFIX}/lib/texo\n")
    file(GENERATE OUTPUT "${output}" CONTENT "${texo_manifest}")
endfunction()
