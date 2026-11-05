#include <array>
#include <cassert>
#include <string_view>
int main() {
    constexpr std::array<std::string_view,7> modes{"ordinary_cxx","cell","standalone_texo_ir","direct_libtexo","custom_pass","cpu","conditional_nvcc"};
    constexpr std::string_view resource="share/texo/1.1";
    constexpr bool profile_required=true;
    static_assert(modes.size()==7 && profile_required);
    assert(resource.front()!='/' && resource.find("build")==std::string_view::npos);
    for(auto mode:modes) assert(!mode.empty());
}
