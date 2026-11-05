#include <Texo/diagnostics/crash_and_timeout_diagnostics_v1.hh>
namespace texo::diagnostics::v1 {
failure_diagnostic diagnose_failure(const failure_event &event) noexcept {
    const bool isolated = event.extension == extension_mode::custom_isolated &&
                          event.isolation_configured;
    return {event.component != 0, true, isolated, event.owner, event.component};
}
}
