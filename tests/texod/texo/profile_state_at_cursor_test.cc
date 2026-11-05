#include "../../../src/compiler/tooling/texo/tooling_model.hh"
#include <cassert>
using namespace texo::tooling::v1;int main(){auto a=profile_state_at_cursor("field",5),b=profile_state_at_cursor("transform field",15);assert(a.selected=="baseline"&&b.selected=="post-transform");assert(b.confidence>a.confidence&&!b.evidence.empty()&&!b.alternatives.empty()&&!b.unknown_dimensions.empty()&&!b.missing_hints.empty());}
