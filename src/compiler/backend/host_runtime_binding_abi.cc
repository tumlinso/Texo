#include <Texo/backend/host_runtime_binding_abi_v1.hh>

extern "C" texo_host_status_v1 texo_host_execute_v1(
    const texo_host_binding_v1* binding) {
    if (binding == nullptr)
        return TEXO_HOST_INVALID_ARGUMENT_V1;
    if (binding->abi_version != TEXO_HOST_BINDING_ABI_VERSION_V1
        || binding->struct_size < sizeof(texo_host_binding_v1))
        return TEXO_HOST_UNSUPPORTED_ABI_V1;
    if ((binding->operand_count != 0 && binding->operands == nullptr)
        || (binding->constant_count != 0 && binding->constants == nullptr)
        || (binding->stage_count != 0 && binding->stages == nullptr))
        return TEXO_HOST_INVALID_ARGUMENT_V1;
    if (binding->required_workspace_bytes > binding->workspace_bytes
        || (binding->required_workspace_bytes != 0 && binding->workspace == nullptr))
        return TEXO_HOST_INSUFFICIENT_WORKSPACE_V1;
    for (uint32_t index = 0; index < binding->operand_count; ++index) {
        const auto& operand = binding->operands[index];
        if (operand.data == nullptr || operand.bytes == 0
            || operand.element_size == 0
            || (operand.kind != TEXO_HOST_INPUT_V1
                && operand.kind != TEXO_HOST_OUTPUT_V1
                && operand.kind != TEXO_HOST_MUTABLE_VALUE_V1))
            return TEXO_HOST_INVALID_OPERAND_V1;
    }
    for (uint32_t index = 0; index < binding->constant_count; ++index) {
        if (binding->constants[index].data == nullptr
            || binding->constants[index].bytes == 0)
            return TEXO_HOST_INVALID_ARGUMENT_V1;
    }
    for (uint32_t index = 0; index < binding->stage_count; ++index) {
        if (binding->stages[index].run == nullptr)
            return TEXO_HOST_INVALID_ARGUMENT_V1;
        const auto status = binding->stages[index].run(
            binding->stages[index].context, binding);
        if (status != TEXO_HOST_SUCCESS_V1)
            return TEXO_HOST_STAGE_FAILED_V1;
    }
    return TEXO_HOST_SUCCESS_V1;
}
