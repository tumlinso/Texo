#pragma once
#include <Texo/reflection/compile_time_ir_handle_model_v1.hh>
#include <cstdint>
#include <string>
#include <vector>
namespace texo::reflection::v1 {
enum class texo_ir_builder_node_kind_v1:std::uint8_t{semantic_operation=1,attribute,region,planning_alternative,candidate,native_fragment};
struct texo_ir_builder_node_v1{ir_handle_v1 handle{};texo_ir_builder_node_kind_v1 kind=texo_ir_builder_node_kind_v1::semantic_operation;std::string name,payload;std::vector<std::uint32_t>children;};
struct texo_ir_builder_v1{std::uint64_t arena_epoch=1,next_identity=1;std::vector<texo_ir_builder_node_v1>nodes;std::vector<std::string>diagnostics;};
[[nodiscard]] std::uint32_t append_texo_ir_node_v1(texo_ir_builder_v1*,texo_ir_builder_node_kind_v1,const std::string&,const std::string&,const std::vector<std::uint32_t>& = {});
[[nodiscard]] bool validate_texo_ir_builder_v1(const texo_ir_builder_v1&)noexcept;
}
