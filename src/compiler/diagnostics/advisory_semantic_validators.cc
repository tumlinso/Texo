#include <Texo/diagnostics/advisory_semantic_validators_v1.hh>
namespace texo::diagnostics::v1 {
advisory_disposition validate_semantic_advisory(const advisory_request &request) noexcept {
    if (!request.representable) return advisory_disposition::error;
    if (request.mode == validation_mode::verified || request.escalate_warning)
        return advisory_disposition::error;
    if (request.mode == validation_mode::trusted && request.force_continuation)
        return advisory_disposition::trusted_continuation;
    if (request.mode == validation_mode::unsafe && request.force_continuation)
        return advisory_disposition::unsafe_continuation;
    if (request.suppress_warning && (request.mode == validation_mode::unsafe ||
                                    request.mode == validation_mode::unchecked))
        return advisory_disposition::suppressed;
    return advisory_disposition::warning;
}
}
