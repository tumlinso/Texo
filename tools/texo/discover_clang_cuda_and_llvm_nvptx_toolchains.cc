#include <Texo/driver/discover_clang_cuda_and_llvm_nvptx_toolchains_v1.hh>
#include <filesystem>
#include <iostream>
int main() { using namespace texo::driver; const auto out = discover_clang_cuda_and_nvptx_v1({"/usr", "/usr", "/usr/local/cuda", "nvptx64-nvidia-cuda"}, [](std::string_view p){ return std::filesystem::exists(p); }); std::cout << out.diagnostic << '\n'; return out.host_available ? 0 : 1; }
