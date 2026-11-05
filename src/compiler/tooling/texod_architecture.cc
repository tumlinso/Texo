#include <Texo/tooling/texod_architecture_v1.hh>

#include <array>

namespace texo::tooling {

texod_architecture_status_v1 validate_texod_architecture_v1(
    const texod_architecture_v1 &architecture) noexcept {
    if (architecture.schema_version != texod_architecture_schema_v1)
        return texod_architecture_status_v1::schema_mismatch;
    if (architecture.clangd_command.empty())
        return texod_architecture_status_v1::missing_clangd_command;
    if (architecture.clangd_version_requirement.empty())
        return texod_architecture_status_v1::missing_clangd_version;
    if (architecture.compiler_snapshot_version == 0)
        return texod_architecture_status_v1::missing_snapshot_version;
    if (architecture.source_map_version == 0)
        return texod_architecture_status_v1::missing_source_map_version;
    if (architecture.permanent_clang_fork)
        return texod_architecture_status_v1::permanent_fork_forbidden;
    return texod_architecture_status_v1::valid;
}

lsp_feature_owner_v1 route_lsp_feature_v1(std::string_view method) noexcept {
    static constexpr std::array<std::string_view, 7> texo_methods{{
        "texo/ast", "texo/texo_ir", "texo/fieldPlan",
        "texo/profile", "texo/realization", "texo/sourceMap",
        "texo/verify"
    }};
    for (const auto owned : texo_methods)
        if (method == owned)
            return lsp_feature_owner_v1::lib_texo_snapshot;
    return lsp_feature_owner_v1::upstream_clangd_worker;
}

bool valid_snapshot_ticket_v1(const texod_snapshot_ticket_v1 &ticket) noexcept {
    return ticket.document_revision != 0 && ticket.clangd_document_version >= 0
        && ticket.compiler_snapshot && !ticket.source_map_identity.empty();
}

bool valid_source_mapping_v1(const texod_source_mapping_v1 &mapping) noexcept {
    return !mapping.generated_uri.empty() && !mapping.original_uri.empty()
        && mapping.generated_begin <= mapping.generated_end
        && mapping.original_begin <= mapping.original_end;
}

} // namespace texo::tooling
