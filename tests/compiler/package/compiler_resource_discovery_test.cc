#include <cassert>
#include <filesystem>
namespace fs = std::filesystem;
fs::path resource(const fs::path& executable, const fs::path& override_path, const char* kind) {
    if (!override_path.empty()) return override_path;
    return (executable.parent_path()/".."/"share"/"texo"/kind).lexically_normal();
}
int main() {
    assert(resource("/old/bin/texo", {}, "stdlib") == "/old/share/texo/stdlib");
    assert(resource("/moved/bin/texo", {}, "profiles") == "/moved/share/texo/profiles");
    assert(resource("/moved/bin/texo", "/explicit/p", "profiles") == "/explicit/p");
}
