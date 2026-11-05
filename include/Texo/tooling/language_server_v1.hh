#pragma once

#include <Texo/tooling/benchmark_baseline_editor_latency_v1.hh>
#include <Texo/tooling/tooling_snapshots_v1.hh>
#include <Texo/tooling/forward_completion_hover_navigation_and_rename_v1.hh>
#include <Texo/tooling/texod_architecture_v1.hh>
#include <Texo/tooling/clangd_worker_lifecycle_v1.hh>
#include <Texo/tooling/compile_command_configuration_v1.hh>
#include <Texo/tooling/document_scheduling_cancellation_v1.hh>
#include <Texo/tooling/host_only_profile_behavior_v1.hh>
#include <Texo/tooling/incremental_source_ast_snapshots_v1.hh>
#include <Texo/tooling/json_rpc_lsp_transport_v1.hh>
#include <Texo/tooling/virtual_shadow_document_mapping_v1.hh>
#include <Texo/tooling/workspace_symbol_indexing_v1.hh>
#include <Texo/tooling/merge_ordinary_c_and_texo_diagnostics_v1.hh>

#include <cstdint>

namespace texo::tooling {
inline constexpr std::uint32_t language_server_contract_version_v1 = 1;
}
