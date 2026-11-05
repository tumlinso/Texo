#include <Texo/tooling/texod_architecture_v1.hh>

#include <cassert>

using namespace texo::tooling;

int main() {
    texod_architecture_v1 architecture;
    assert(validate_texod_architecture_v1(architecture)
           == texod_architecture_status_v1::valid);
    assert(!architecture.permanent_clang_fork);
    assert(architecture.request_scoped_cancellation);
    assert(architecture.restart_worker_after_protocol_failure);

    assert(route_lsp_feature_v1("texo/texo_ir")
           == lsp_feature_owner_v1::lib_texo_snapshot);
    assert(route_lsp_feature_v1("textDocument/hover")
           == lsp_feature_owner_v1::upstream_clangd_worker);

    architecture.permanent_clang_fork = true;
    assert(validate_texod_architecture_v1(architecture)
           == texod_architecture_status_v1::permanent_fork_forbidden);
    architecture.permanent_clang_fork = false;
    architecture.source_map_version = 0;
    assert(validate_texod_architecture_v1(architecture)
           == texod_architecture_status_v1::missing_source_map_version);

    texod_snapshot_ticket_v1 ticket;
    assert(!valid_snapshot_ticket_v1(ticket));

    texod_source_mapping_v1 mapping{
        "file:///shadow.cc", 12, 20, "file:///source.texo.cc", 4, 10};
    assert(valid_source_mapping_v1(mapping));
    mapping.original_begin = 11;
    assert(!valid_source_mapping_v1(mapping));
}
