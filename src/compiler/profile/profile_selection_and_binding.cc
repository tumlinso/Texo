#include <Texo/profile/profile_selection_and_binding_v1.hh>
namespace texo::profile::v1 {
namespace {

template <class Identity>
bool same(Identity a, Identity b) {
    return a.low == b.low && a.high == b.high;
}

template <class Identity>
bool zero(Identity identity) {
    return identity.low == 0 && identity.high == 0;
}

}  // namespace

profile_binding_status_v1 bind_profile_v1(const profile_binding_request_v1 &request,
                                           bound_profile_v1 *out) noexcept {
    if (!out || (request.profile_count && !request.profiles))
        return profile_binding_status_v1::invalid_argument;
    if (request.pure_cxx || !request.semantic_activation) {
        *out = {request.symbol, request.field, {}, {}, false, true};
        return profile_binding_status_v1::pure_cxx_fallthrough;
    }

    const available_profile_v1 *chosen = nullptr;
    for (std::uint32_t i = 0; i < request.profile_count; ++i) {
        const auto &profile = request.profiles[i];
        const bool matches = same(profile.domain, request.required_domain) &&
                             same(profile.axis, request.required_axis);
        if (!matches) continue;
        if (profile.generic_reference && !request.allow_generic_reference) continue;
        if (chosen) return profile_binding_status_v1::ambiguous_profile;
        chosen = &profile;
    }
    if (!chosen)
        return request.profile_count ? profile_binding_status_v1::identity_mismatch
                                     : profile_binding_status_v1::missing_profile;
    if (!chosen->environment) return profile_binding_status_v1::invalid_argument;

    const auto *state = zero(request.requested_name)
        ? default_named_profile_state_v1(*chosen->environment)
        : find_named_profile_state_v1(*chosen->environment, request.requested_name);
    if (!state) return profile_binding_status_v1::name_not_found;
    *out = {request.symbol, request.field, chosen->artifact, state->state,
            chosen->generic_reference, false};
    return profile_binding_status_v1::ok;
}
}  // namespace texo::profile::v1
