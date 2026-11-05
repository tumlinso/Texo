#include <Texo/profile/profile_state_attachment_to_semantic_ir_v1.hh>
namespace texo::profile::v1 {
namespace {

bool zero(profile_identity_v1 identity) {
    return identity.low == 0 && identity.high == 0;
}

}  // namespace

semantic_ir_profile_attachment_status_v1 validate_semantic_ir_profile_attachment_v1(
    const semantic_ir_profile_attachment_v1 &attachment) noexcept {
    if (attachment.schema_version != 1)
        return semantic_ir_profile_attachment_status_v1::unsupported_schema;
    if (zero(attachment.semantic_ir_node) || zero(attachment.environment) ||
        zero(attachment.state))
        return semantic_ir_profile_attachment_status_v1::invalid_identity;
    if (attachment.location == profile_evidence_location_v1::embedded)
        return attachment.embedded_bytes && !attachment.external_artifact_low &&
                       !attachment.external_artifact_high
            ? semantic_ir_profile_attachment_status_v1::ok
            : semantic_ir_profile_attachment_status_v1::invalid_embedded;
    if (attachment.location == profile_evidence_location_v1::external)
        return !zero(attachment.evidence) &&
                       (attachment.external_artifact_low || attachment.external_artifact_high) &&
                       !attachment.embedded_bytes
            ? semantic_ir_profile_attachment_status_v1::ok
            : semantic_ir_profile_attachment_status_v1::invalid_external;
    return zero(attachment.evidence)
        ? semantic_ir_profile_attachment_status_v1::ok
        : semantic_ir_profile_attachment_status_v1::invalid_identity;
}
}  // namespace texo::profile::v1
