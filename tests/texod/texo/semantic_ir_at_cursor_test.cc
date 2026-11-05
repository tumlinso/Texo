#include "../../../src/compiler/tooling/texo/tooling_model.hh"
#include <cassert>
using namespace texo::tooling::v1;int main(){auto v=semantic_ir_at_cursor("profile p field",10);assert(v.normalized.find("semantic.field")!=v.normalized.npos&&v.source_map=="model.texo:10"&&v.profiles[0]=="named");auto edited=apply_semantic_ir_edit("field",v);assert(edited.find(v.normalized)!=edited.npos);}
