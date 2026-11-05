#include <Texo/driver/downstream_compiler_invocation_v1.hh>
#include <iostream>
int main(int argc, char** argv) { if (argc < 3 || std::string_view(argv[1]) != "--driver") { std::cerr << "usage: texo --driver COMPILER [ARG...]\n"; return 2; } std::vector<std::string> args(argv + 3, argv + argc); return texo::driver::run_downstream_compiler_v1(argv[2], args).downstream_exit_code; }
