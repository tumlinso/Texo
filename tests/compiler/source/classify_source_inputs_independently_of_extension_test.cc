#include <Texo/frontend/source/classify_source_inputs_independently_of_extension_v1.hh>

#include <array>
#include <iostream>
#include <stdexcept>
#include <string_view>

using namespace texo::frontend::source;

int main() {
    try {
        constexpr std::string_view activated = "int ordinary;\n  #pragma texo 0.1\n<[ ordinary ]>\n";
        for (auto path : std::array<std::string_view, 3>{"unit.texo", "unit.cc", "unit.hh"}) {
            const auto classification = classify_source_input_v1(path, activated);
            if (classification.mode != source_input_mode_v1::activated_texo ||
                classification.revision != "0.1") {
                throw std::runtime_error("activation depended on the source extension");
            }
        }
        if (classify_source_input_v1("ordinary.texo", "int main() {}\n").mode !=
            source_input_mode_v1::ordinary_cxx) {
            throw std::runtime_error(".texo activated without the pragma");
        }
        if (classify_source_input_v1("module.texoir", "ce.module @m").mode !=
            source_input_mode_v1::standalone_texo_ir) {
            throw std::runtime_error("standalone TEXO_IR was not classified");
        }
        if (classify_source_input_v1("comment.cc", "// #pragma texo\n").mode !=
            source_input_mode_v1::ordinary_cxx) {
            throw std::runtime_error("comment text activated the language");
        }
        std::cout << "validated extension-independent source activation\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
