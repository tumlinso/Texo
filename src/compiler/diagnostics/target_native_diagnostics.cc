#include <Texo/diagnostics/target_native_diagnostics_v1.hh>
namespace texo::diagnostics::v1 {
target_native_diagnostic diagnose_target_native(const target_native_request &request) noexcept {
    static constexpr std::string_view messages[] = {
        "unsupported native instruction", "target capability outside supported range",
        "native clobber contract violated", "native operand alignment invalid",
        "native address space mismatch", "collective contract incompatible",
        "native ABI incompatible", "operation is not graph-capture compatible",
        "required fallback unavailable"};
    const auto message = messages[static_cast<unsigned>(request.issue)];
    if (request.fallback_available) return {true, false, message};
    if (request.mode == validation_mode::unsafe && request.unsafe_acknowledged &&
        request.representable)
        return {true, true, message};
    return {false, false, message};
}
}
