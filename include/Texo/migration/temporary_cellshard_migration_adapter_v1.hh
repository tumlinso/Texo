#pragma once
#include <array>
#include <cstdint>
#include <string_view>
namespace texo::migration {
struct temporary_adapter_v1{std::string_view legacy_surface,target_texo_contract,retirement_proof;std::uint32_t version;bool owns_semantics;};
inline constexpr std::array<temporary_adapter_v1,5> temporary_adapters_v1{{
 {"CellShard compiler evidence/discovery","texo::profile","all evidence consumers compile against Texo profile APIs",1,false},
 {"CellShard compiler atom/certification","texo::planning","all exact-certificate tests use Texo Planning IR",1,false},
 {"CellShard compiler grammar/basis/superatom","texo::planning","all rule and promotion tests use public Texo extensions",1,false},
 {"CellShard compiler graph/schedule","texo::program","all portable program and schedule consumers use Texo IR",1,false},
 {"CellShard compiler partial","texo::partial","semantic tests move and only storage-consumer tests remain",1,false},
}};
} // namespace texo::migration
