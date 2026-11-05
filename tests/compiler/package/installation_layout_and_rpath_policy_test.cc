#include <array>
#include <cassert>
#include <string_view>
int main() {
    constexpr std::array<std::string_view,8> paths{"bin","lib","include","share/texo/stdlib","share/texo/profiles","share/texo/schemas","share/texo/backends","share/texo/docs"};
    for (auto path: paths) assert(!path.empty() && path.front() != '/' && path.find("build") == std::string_view::npos);
    constexpr std::string_view rpath="$ORIGIN/../lib";
    static_assert(rpath.rfind("$ORIGIN",0)==0);
}
