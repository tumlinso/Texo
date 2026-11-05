#include "../../../src/compiler/tooling/texo/tooling_model.hh"
#include <cassert>
using namespace texo::tooling::v1;int main(){auto v=realization_at_cursor();auto a=render_realization_json(v),b=render_realization_json(v);assert(a==b&&a.find("8192")!=a.npos&&v.atoms.size()==2&&v.stages.size()==3&&v.graph_capture&&!v.readiness.empty());}
