#include <Texo/lto/mach_o_and_coff_strategies_v1.hh>
namespace texo::lto::v1 {
platform_texo_ir_strategy_v1 select_platform_texo_ir_strategy_v1(object_format_v1 f,bool available){platform_texo_ir_strategy_v1 r;r.format=f;r.toolchain_available=available;r.sidecar_suffix=".texoir";r.use_sidecar=!available;if(f==object_format_v1::mach_o){r.segment="__TEXO";r.section="__texo_ir";r.symbol="_texo_ir";}else if(f==object_format_v1::coff){r.section=".texo$texo_ir";r.symbol="__texo_ir";}else r.use_sidecar=true;return r;}
bool equivalent_platform_content_v1(const texo_ir_companion_artifact_v1&a,const texo_ir_companion_artifact_v1&b)noexcept{return a.version==b.version&&a.semantic_summary.high==b.semantic_summary.high&&a.semantic_summary.low==b.semantic_summary.low&&a.planning_summary.high==b.planning_summary.high&&a.planning_summary.low==b.planning_summary.low&&a.profile_reference.high==b.profile_reference.high&&a.profile_reference.low==b.profile_reference.low&&a.content_hash==b.content_hash;}
}
