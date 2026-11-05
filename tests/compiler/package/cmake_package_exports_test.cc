#include <array>
#include <cassert>
#include <string_view>
int main() {
    constexpr std::array<std::string_view,4> targets{"Texo::Compiler","Cellerator::Runtime","Cellerator::BackendCUDA","Cellerator::ProviderSDK"};
    for (auto target: targets) {
        assert(target.rfind("Texo::",0)==0);
        assert(target.find("/home/")==std::string_view::npos);
        assert(target.find("build/")==std::string_view::npos);
    }
}
