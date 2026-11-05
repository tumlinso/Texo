#pragma once
#include <array>
#include <cstdint>
#include <string_view>
namespace texo::migration {
enum class subsystem_owner_v1:std::uint8_t{texo=1,cellshard,split,temporary_adapter};
struct ownership_rehoming_row_v1{std::string_view old_cellshard_family,new_texo_target;subsystem_owner_v1 owner;};
inline constexpr std::array<ownership_rehoming_row_v1,12> compiler_ownership_rehoming_v1{{
 {"compiler/evidence + discovery","compiler/profile",subsystem_owner_v1::texo},
 {"compiler/certification","compiler/planning/certification",subsystem_owner_v1::texo},
 {"compiler/atom semantic states","compiler/ir/atom",subsystem_owner_v1::texo},
 {"compiler/composition + grammar","compiler/planning/extensions",subsystem_owner_v1::texo},
 {"compiler/basis","compiler/planner/basis",subsystem_owner_v1::texo},
 {"compiler/composition/superatom","compiler/planner/superatom",subsystem_owner_v1::texo},
 {"compiler/partial","compiler/partial + CellShard persistence",subsystem_owner_v1::split},
 {"compiler/graph","compiler/semantic + planning IR",subsystem_owner_v1::texo},
 {"compiler/schedule","compiler/planning + realization IR",subsystem_owner_v1::texo},
 {"atom-store + materialization + runtime","CellShard application",subsystem_owner_v1::cellshard},
 {"legacy compiler includes/tests","Texo public contracts",subsystem_owner_v1::temporary_adapter},
 {"compiled ruleset export","CellShard future consumer",subsystem_owner_v1::split},
}};
[[nodiscard]] constexpr bool complete_ownership_map_v1()noexcept{for(auto r:compiler_ownership_rehoming_v1)if(r.old_cellshard_family.empty()||r.new_texo_target.empty())return false;return true;}
} // namespace texo::migration
