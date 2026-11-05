#include <Texo/api/texo_ir_ownership_and_mutation_api_v1.hh>
namespace texo::api::v1 {
texo_ir_snapshot_v1 parse_texo_ir_v1(texo_ir_level_v1 level, std::string text) { texo_ir_builder_v1 b(level); b.set_text(std::move(text)); b.add_provenance("parsed"); return b.freeze(); }
std::string print_texo_ir_v1(const texo_ir_snapshot_v1& module) { return module ? module->text : std::string{}; }
texo_ir_builder_v1 clone_texo_ir_v1(const texo_ir_snapshot_v1& module) { texo_ir_builder_v1 b(module->level); b.set_text(module->text); for(const auto& p:module->provenance)b.add_provenance(p); return b; }
bool validate_texo_ir_v1(const texo_ir_snapshot_v1& module, texo_ir_validation_v1 mode) noexcept { return module && (mode==texo_ir_validation_v1::unsafe_mode || !module->text.empty()); }
std::vector<std::uint8_t> serialize_texo_ir_v1(const texo_ir_snapshot_v1& module) { if(!module)return {}; std::vector<std::uint8_t> out{static_cast<std::uint8_t>(module->level)}; out.insert(out.end(),module->text.begin(),module->text.end()); return out; }
}
