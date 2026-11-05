#include <Texo/build/host_only_compiler_smoke_targets_v1.hh>

#include <cassert>

#ifndef TEXO_SMOKE_COMPONENT
#define TEXO_SMOKE_COMPONENT "aggregate"
#endif

int main() {
    using namespace texo::build;
    static_assert(host_smoke_components_v1.size() == 5);
    static_assert(!host_smokes_link_cuda_v1);
    assert(std::string_view{TEXO_SMOKE_COMPONENT}.size() != 0);
}
