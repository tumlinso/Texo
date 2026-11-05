#include <cassert>
struct version_pair { unsigned compiler; unsigned texo_ir; };
constexpr bool compatible(version_pair compiler, version_pair resource) { return compiler.compiler==resource.compiler && compiler.texoir==resource.texoir; }
int main() {
    static_assert(compatible({1,1},{1,1}));
    static_assert(!compatible({1,1},{2,1}));
    static_assert(!compatible({1,1},{1,2}));
    assert(!compatible({2,1},{1,1}));
}
