#pragma once

#include <Texo/lto/assign_cross_tu_field_and_symbol_identities_v1.hh>
#include <Texo/lto/texo_link_driver_mode_v1.hh>
#include <Texo/lto/cross_tu_inlining_and_connected_planning_v1.hh>
#include <Texo/lto/cross_tu_semantic_imports_v1.hh>
#include <Texo/lto/explicit_program_planning_authorization_v1.hh>
#include <Texo/lto/incremental_and_thin_summary_lto_v1.hh>
#include <Texo/lto/mixed_backend_re_emission_v1.hh>
#include <Texo/lto/profile_environment_merge_v1.hh>
#include <Texo/lto/program_level_semantic_planning_ir_v1.hh>
#include <Texo/lto/template_instantiation_deduplication_v1.hh>
#include <Texo/lto/object_texo_ir_v1.hh>

namespace texo::lto::v1 {
inline constexpr std::uint32_t texo_lto_contract_version_v1 = 2;
}
