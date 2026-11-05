#pragma once

#include <Texo/tooling/language_server_v1.hh>

#include <cstdint>
#include <string>

namespace texo::tooling {

struct texod_cpp_parity_receipt_v1 {
    std::string executable;
    std::string resource_directory;
    std::uint32_t ordinary_cpp_documents = 0;
    std::uint32_t texo_documents = 0;
    bool ordinary_cpp_diagnostics = false;
    bool ordinary_cpp_navigation = false;
    bool ordinary_cpp_completion = false;
    bool texo_syntax_diagnostics = false;
    bool host_only = false;
    bool worker_process_stopped = false;
};

enum class texod_cpp_parity_status_v1 : std::uint8_t {
    valid = 0,
    executable_missing,
    resource_directory_missing,
    mixed_workspace_missing,
    cpp_feature_missing,
    texo_diagnostics_missing,
    cuda_required,
    process_leaked
};

[[nodiscard]] texod_cpp_parity_status_v1
validate_texod_cpp_parity_v1(
    const texod_cpp_parity_receipt_v1&) noexcept;

}  // namespace texo::tooling
