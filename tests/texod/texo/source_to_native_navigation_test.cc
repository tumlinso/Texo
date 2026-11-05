#include "../../../src/compiler/tooling/texo/tooling_model.hh"
#include <cassert>
using namespace texo::tooling::v1;int main(){for(auto a:{"cpu-cxx","nvcc-cuda","direct-ptx"}){auto n=navigate_to_native(a);assert(n.generated.find(a)!=n.generated.npos&&!n.semantic.empty()&&!n.planning.empty()&&!n.realization.empty()&&!n.resource_report.empty());assert(reverse_map_native_diagnostic("invalid operand",n).find("model.texo:12")!=std::string::npos);}}
