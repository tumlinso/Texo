#include <Texo/discovery/temporary_cellshard_compiler_adapter_v1.hh>

namespace texo::discovery {

const cellshard_compatibility_manifest_v1&
cellshard_compiler_compatibility_manifest_v1() noexcept {
    static constexpr cellshard_compatibility_manifest_v1 manifest{
        "cellshard::compiler::compatibility_v1",
        "texo::discovery",
        "CE-CCP1-E02-018",
    };
    return manifest;
}

}  // namespace texo::discovery
