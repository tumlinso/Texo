#include <Texo/pass/open_compiler_extension_surface_v1.hh>

#include <cassert>
#include <cstdlib>
#include <filesystem>
#include <fstream>

namespace cp = texo::pass::v1;

int main() {
    const auto descriptor = cp::open_compiler_extension_surface_descriptor_v1();
    assert(descriptor.abi_version == 1);
    assert(descriptor.pipeline_phase_count == 12 && descriptor.pipeline_stage_count == 24);
    assert((descriptor.capabilities & cp::cold_provenance_v1) != 0);

    const auto directory = std::filesystem::temp_directory_path() / "texo_open_compiler_extension_surface";
    std::filesystem::remove_all(directory);
    const auto install = directory / "install" / "include";
    std::filesystem::create_directories(install);
    std::filesystem::copy(std::filesystem::path(TEXO_TEST_INCLUDE_ROOT) / "Texo",
        install / "Texo", std::filesystem::copy_options::recursive);
    const auto source = directory / "external_plugin.cc";
    const auto library = directory / "external_plugin.so";
    { std::ofstream output(source); output
        << "#include <Texo/pass/pass_v1.hh>\n"
           "#include <Texo/pass/extension_v1.hh>\n"
           "#include <Texo/pass/self_transform_v1.hh>\n"
           "#include <Texo/pass/open_compiler_extension_surface_v1.hh>\n"
           "extern \"C\" unsigned plugin_abi() { return texo::pass::v1::open_compiler_extension_abi_version_v1; }\n"; }
    const std::string command = "g++ -std=c++20 -shared -fPIC -I" + install.string()
        + " " + source.string() + " -o " + library.string();
    assert(std::system(command.c_str()) == 0);
    assert(std::filesystem::is_regular_file(library));
    std::filesystem::remove_all(directory);
}
