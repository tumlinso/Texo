include_guard(GLOBAL)

set(TEXO_ENABLE_CLANG_FRONTEND "AUTO" CACHE STRING
    "Discover packaged upstream LLVM and Clang libraries: AUTO, ON, or OFF")
set_property(CACHE TEXO_ENABLE_CLANG_FRONTEND PROPERTY STRINGS AUTO ON OFF)

function(texo_discover_llvm_clang)
    if(TEXO_ENABLE_CLANG_FRONTEND STREQUAL "OFF")
        set(TEXO_HAS_CLANG_FRONTEND FALSE PARENT_SCOPE)
        return()
    endif()
    find_package(LLVM CONFIG QUIET)
    find_package(Clang CONFIG QUIET)
    if(LLVM_FOUND AND Clang_FOUND)
        set(TEXO_HAS_CLANG_FRONTEND TRUE PARENT_SCOPE)
        set(TEXO_LLVM_VERSION "${LLVM_PACKAGE_VERSION}" PARENT_SCOPE)
        set(TEXO_LLVM_ABI_BREAKING_CHECKS
            "${LLVM_ABI_BREAKING_CHECKS}" PARENT_SCOPE)
    elseif(TEXO_ENABLE_CLANG_FRONTEND STREQUAL "ON")
        message(FATAL_ERROR
            "Clang frontend requested, but packaged LLVM and Clang development configs were not both found; set LLVM_DIR and Clang_DIR")
    else()
        set(TEXO_HAS_CLANG_FRONTEND FALSE PARENT_SCOPE)
    endif()
endfunction()
