#pragma once

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct texo_compiler_session_v1 texo_compiler_session_v1;
typedef void (*texo_diagnostic_callback_v1)(int severity, const char* message,
    void* user_data);
typedef int (*texo_cancel_callback_v1)(void* user_data);

typedef struct texo_compiler_config_v1 {
    uint32_t struct_size;
    const char* target;
    const char* toolchain;
    const char* profile;
    texo_diagnostic_callback_v1 diagnostic;
    texo_cancel_callback_v1 cancelled;
    void* user_data;
} texo_compiler_config_v1;

typedef struct texo_compiler_output_v1 {
    uint32_t struct_size;
    const char* object_identity;
    size_t source_count;
} texo_compiler_output_v1;

texo_compiler_session_v1* texo_compiler_session_create_v1(
    const texo_compiler_config_v1* config);
void texo_compiler_session_destroy_v1(texo_compiler_session_v1* session);
int texo_compiler_session_add_source_buffer_v1(texo_compiler_session_v1* session,
    const char* name, const char* data, size_t size);
int texo_compiler_session_add_source_file_v1(texo_compiler_session_v1* session,
    const char* path);
int texo_compiler_session_compile_v1(texo_compiler_session_v1* session,
    texo_compiler_output_v1* output);

#ifdef __cplusplus
}
#endif
