#include "../../../src/compiler/tooling/texo/tooling_model.hh"
#include <cassert>
using namespace texo::tooling::v1;int main(){auto outer=describe_field_effects("field nested",1);auto inner=describe_field_effects("field native nested",15);assert(outer.boundary=="outer"&&outer.optimization_visible);assert(inner.boundary=="nested"&&!inner.barriers.empty()&&!inner.optimization_visible);assert(!inner.captures.empty()&&!inner.reads.empty()&&!inner.writes.empty()&&!inner.effects.empty());}
