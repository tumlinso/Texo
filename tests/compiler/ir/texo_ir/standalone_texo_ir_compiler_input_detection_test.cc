#include <Texo/ir/common/standalone_texo_ir_compiler_input_detection_v1.hh>

#include <cassert>

using namespace texo::ir;

int main() {
    struct fixture { const char *level; texo_ir_input_level expected; texo_ir_resume_stage resume; const char *dump; };
    for (const auto &item : {fixture{"semantic", texo_ir_input_level::semantic,
             texo_ir_resume_stage::build_planning, "planning.texoir"},
             fixture{"planning", texo_ir_input_level::planning,
                 texo_ir_resume_stage::build_realization, "realization.texoir"},
             fixture{"realization", texo_ir_input_level::realization,
                 texo_ir_resume_stage::lower_executable, "executable.texoir"}}) {
        const auto input = std::string("texo_ir level ") + item.level + " version 2.0\n";
        const auto detected = detect_standalone_texo_ir("module.texoir", input);
        assert(detected.level == item.expected && detected.resume == item.resume);
        assert(next_texo_ir_dump_name(detected.level) == item.dump);
    }
    assert(!is_standalone_texo_ir_path("module.ceir"));
    assert(detect_standalone_texo_ir("module.texoir", "ceir level semantic version 1.0").resume
        == texo_ir_resume_stage::reject);
    assert(detect_standalone_texo_ir("module.cpp", "texo_ir level semantic version 2.0").resume
        == texo_ir_resume_stage::reject);
    assert(detect_standalone_texo_ir("module.texoir", "texo_ir level semantic version 1.0").resume
        == texo_ir_resume_stage::reject);
    assert(detect_standalone_texo_ir("module.texoir", "semantic.apply").resume
        == texo_ir_resume_stage::reject);
}
