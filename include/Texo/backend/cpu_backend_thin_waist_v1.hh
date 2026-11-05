#pragma once

#include <Texo/backend/backend_v1.hh>
#include <Texo/backend/cpu/cpu_backend_v1.hh>

#include <cstdint>

namespace texo::backend::v1 {

struct cpu_backend_thin_waist_receipt_v1 {
    std::uint32_t backend_abi_version = 0;
    std::uint32_t cpu_backend_version = 0;
    bool ordinary_objects = false;
    bool generated_cpp = false;
    bool runtime_binding = false;
    bool source_diagnostics = false;
    bool deterministic_fallbacks = false;
};

[[nodiscard]] const cpu_backend_thin_waist_receipt_v1&
freeze_cpu_backend_thin_waist_v1() noexcept;

}  // namespace texo::backend::v1
