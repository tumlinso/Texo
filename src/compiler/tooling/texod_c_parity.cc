#include <Texo/tooling/texod_c_parity_v1.hh>

namespace texo::tooling {

texod_cpp_parity_status_v1 validate_texod_cpp_parity_v1(
    const texod_cpp_parity_receipt_v1& receipt) noexcept {
    if (receipt.executable.empty())
        return texod_cpp_parity_status_v1::executable_missing;
    if (receipt.resource_directory.empty())
        return texod_cpp_parity_status_v1::resource_directory_missing;
    if (receipt.ordinary_cpp_documents == 0 || receipt.texo_documents == 0)
        return texod_cpp_parity_status_v1::mixed_workspace_missing;
    if (!receipt.ordinary_cpp_diagnostics || !receipt.ordinary_cpp_navigation ||
        !receipt.ordinary_cpp_completion)
        return texod_cpp_parity_status_v1::cpp_feature_missing;
    if (!receipt.texo_syntax_diagnostics)
        return texod_cpp_parity_status_v1::texo_diagnostics_missing;
    if (!receipt.host_only)
        return texod_cpp_parity_status_v1::cuda_required;
    if (!receipt.worker_process_stopped)
        return texod_cpp_parity_status_v1::process_leaked;
    return texod_cpp_parity_status_v1::valid;
}

}  // namespace texo::tooling
