#pragma once

#include <Texo/lto/texo_ir_companion_object_artifact_contract_v1.hh>
#include <Texo/lto/elf_texo_ir_sections_v1.hh>
#include <Texo/lto/mach_o_and_coff_strategies_v1.hh>
#include <Texo/lto/object_and_archive_texo_ir_extraction_v1.hh>
#include <Texo/lto/portable_sidecar_fallback_v1.hh>

namespace texo::lto::v1 {
inline constexpr std::uint32_t object_texo_ir_contract_version_v1 = 2;
}
