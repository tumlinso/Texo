#pragma once

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TEXO_HOST_BINDING_ABI_VERSION_V1 1u

typedef enum texo_host_status_v1 {
    TEXO_HOST_SUCCESS_V1 = 0,
    TEXO_HOST_INVALID_ARGUMENT_V1 = 1,
    TEXO_HOST_UNSUPPORTED_ABI_V1 = 2,
    TEXO_HOST_INVALID_OPERAND_V1 = 3,
    TEXO_HOST_INSUFFICIENT_WORKSPACE_V1 = 4,
    TEXO_HOST_STAGE_FAILED_V1 = 5
} texo_host_status_v1;

typedef enum texo_host_operand_kind_v1 {
    TEXO_HOST_INPUT_V1 = 1,
    TEXO_HOST_OUTPUT_V1 = 2,
    TEXO_HOST_MUTABLE_VALUE_V1 = 3
} texo_host_operand_kind_v1;

typedef struct texo_host_operand_v1 {
    void* data;
    size_t bytes;
    uint32_t element_size;
    uint32_t kind;
} texo_host_operand_v1;

typedef struct texo_host_constant_v1 {
    const void* data;
    size_t bytes;
} texo_host_constant_v1;

struct texo_host_binding_v1;
typedef texo_host_status_v1 (*texo_host_stage_v1)(
    void* context, const struct texo_host_binding_v1* binding);

typedef struct texo_host_prepared_stage_v1 {
    texo_host_stage_v1 run;
    void* context;
} texo_host_prepared_stage_v1;

typedef struct texo_host_binding_v1 {
    uint32_t abi_version;
    uint32_t struct_size;
    const texo_host_operand_v1* operands;
    uint32_t operand_count;
    const texo_host_constant_v1* constants;
    uint32_t constant_count;
    void* workspace;
    size_t workspace_bytes;
    size_t required_workspace_bytes;
    const texo_host_prepared_stage_v1* stages;
    uint32_t stage_count;
} texo_host_binding_v1;

texo_host_status_v1 texo_host_execute_v1(
    const texo_host_binding_v1* binding);

#ifdef __cplusplus
}
#endif
