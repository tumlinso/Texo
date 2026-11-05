#pragma once

namespace texo::build {
struct accelerator_smoke_contract_v1 {
    bool conditional;
    bool links_realization;
    bool links_runtime_when_available;
    int baseline_sm;
    bool changes_host_only_dependencies;
};
inline constexpr accelerator_smoke_contract_v1 accelerator_smoke_v1{
    true, true, true, 70, false,
};
}  // namespace texo::build
