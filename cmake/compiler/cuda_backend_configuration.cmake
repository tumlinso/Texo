include_guard(GLOBAL)

set(TEXO_ENABLE_CUDA "AUTO" CACHE STRING
    "Enable CUDA compiler backends: AUTO, ON, or OFF")
set_property(CACHE TEXO_ENABLE_CUDA PROPERTY STRINGS AUTO ON OFF)

macro(texo_configure_optional_cuda_backend)
    string(TOUPPER "${TEXO_ENABLE_CUDA}" texo_cuda_mode)
    if(NOT texo_cuda_mode MATCHES "^(AUTO|ON|OFF)$")
        message(FATAL_ERROR "TEXO_ENABLE_CUDA must be AUTO, ON, or OFF")
    endif()

    if(texo_cuda_mode STREQUAL "OFF")
        set(TEXO_HAS_CUDA FALSE)
        return()
    endif()

    include(CheckLanguage)
    check_language(CUDA)
    if(CMAKE_CUDA_COMPILER)
        enable_language(CUDA)
        set(TEXO_HAS_CUDA TRUE)
    elseif(texo_cuda_mode STREQUAL "ON")
        message(FATAL_ERROR
            "TEXO_ENABLE_CUDA=ON requires a usable CUDA compiler")
    else()
        set(TEXO_HAS_CUDA FALSE)
    endif()
endmacro()
