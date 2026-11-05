#pragma once
#include <array>
#include <cstdint>
#include <string_view>
namespace texo::migration {
enum class partial_owner_v1:std::uint8_t{texo=1,cellshard};
struct partial_interface_row_v1{std::string_view concern;partial_owner_v1 owner;std::string_view dependency;};
inline constexpr std::array<partial_interface_row_v1,8> partial_interface_v1{{
 {"merge algebra",partial_owner_v1::texo,"Texo"},{"dependency closure",partial_owner_v1::texo,"Texo"},{"numerical policy",partial_owner_v1::texo,"Texo"},{"persistence legality",partial_owner_v1::texo,"Texo"},
 {"payload bytes",partial_owner_v1::cellshard,"Texo ABI"},{"replication",partial_owner_v1::cellshard,"Texo ABI"},{"durable persistence",partial_owner_v1::cellshard,"Texo ABI"},{"recovery",partial_owner_v1::cellshard,"Texo ABI"},
}};
[[nodiscard]] constexpr bool acyclic_partial_dependency_v1()noexcept{for(auto row:partial_interface_v1)if(row.owner==partial_owner_v1::texo&&row.dependency!="Texo")return false;return true;}
} // namespace texo::migration
