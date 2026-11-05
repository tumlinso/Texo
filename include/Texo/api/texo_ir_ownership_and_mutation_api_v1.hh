#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
namespace texo::api::v1 {
enum class texo_ir_level_v1 : std::uint8_t { semantic=0, planning, realization };
enum class texo_ir_validation_v1 : std::uint8_t { checked=0, trusted, unsafe_mode };
struct texo_ir_module_v1 { texo_ir_level_v1 level{}; std::string text; std::vector<std::string> provenance; };
using texo_ir_snapshot_v1 = std::shared_ptr<const texo_ir_module_v1>;
class texo_ir_builder_v1 {
public:
 explicit texo_ir_builder_v1(texo_ir_level_v1 level) : module_{level,{},{}} {}
 void set_text(std::string text) { module_.text=std::move(text); }
 void add_provenance(std::string value) { module_.provenance.push_back(std::move(value)); }
 [[nodiscard]] texo_ir_snapshot_v1 freeze() const { return std::make_shared<const texo_ir_module_v1>(module_); }
private: texo_ir_module_v1 module_;
};
[[nodiscard]] texo_ir_snapshot_v1 parse_texo_ir_v1(texo_ir_level_v1 level, std::string text);
[[nodiscard]] std::string print_texo_ir_v1(const texo_ir_snapshot_v1& module);
[[nodiscard]] texo_ir_builder_v1 clone_texo_ir_v1(const texo_ir_snapshot_v1& module);
[[nodiscard]] bool validate_texo_ir_v1(const texo_ir_snapshot_v1& module, texo_ir_validation_v1 mode) noexcept;
[[nodiscard]] std::vector<std::uint8_t> serialize_texo_ir_v1(const texo_ir_snapshot_v1& module);
}
