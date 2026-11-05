#include <Texo/reflection/compile_time_texo_ir_builders_v1.hh>
#include <cassert>
using namespace texo::reflection::v1;
int main(){texo_ir_builder_v1 b;auto op=append_texo_ir_node_v1(&b,texo_ir_builder_node_kind_v1::semantic_operation,"apply","f32");auto candidate=append_texo_ir_node_v1(&b,texo_ir_builder_node_kind_v1::planning_alternative,"csr","cost=7",{op});assert(op==0&&candidate==1&&validate_texo_ir_builder_v1(b));assert(append_texo_ir_node_v1(&b,texo_ir_builder_node_kind_v1::candidate,"bad","",{99})==UINT32_MAX&&!b.diagnostics.empty());}
