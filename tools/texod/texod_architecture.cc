#include <Texo/tooling/texod_architecture_v1.hh>

#include <iostream>

int main() {
    const texo::tooling::texod_architecture_v1 architecture;
    if (texo::tooling::validate_texod_architecture_v1(architecture)
        != texo::tooling::texod_architecture_status_v1::valid)
        return 1;
    std::cout << "texod architecture v1: libTexo snapshots + upstream clangd\n";
    return 0;
}
