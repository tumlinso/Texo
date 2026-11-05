#include <Texo/driver/temporary_artifact_and_cache_policy_v1.hh>
#include <iostream>
int main() { const auto out = texo::driver::define_artifact_policy_v1({"/tmp/texo", "/cache", "compile-1", "abcdef"}); std::cout << out.action_directory << '\n' << out.cold_cache_path << '\n'; }
