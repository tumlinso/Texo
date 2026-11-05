#pragma once
#include <string>
#include <vector>
namespace texo::driver {
struct compilation_record_v1 { std::string directory, source, output, depfile, module_dependencies; std::vector<std::string> arguments; };
std::string compilation_database_entry_v1(const compilation_record_v1&);
std::vector<std::string> dependency_arguments_v1(const compilation_record_v1&);
}  // namespace texo::driver
