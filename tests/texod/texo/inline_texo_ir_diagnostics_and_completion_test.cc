#include "../../../src/compiler/tooling/texo/tooling_model.hh"
#include <cassert>
using namespace texo::tooling::v1;int main(){for(auto l:{"semantic","planning","realization"}){auto a=assist_inline_texo_ir(l,"missing_type");assert(a.level==l&&!a.operations.empty()&&!a.types.empty()&&!a.attributes.empty()&&!a.profiles.empty()&&!a.candidates.empty()&&!a.namespaces.empty()&&!a.validation_modes.empty()&&!a.diagnostics.empty());}assert(assist_inline_texo_ir("realization","").instructions[0]=="mma.sync");}
