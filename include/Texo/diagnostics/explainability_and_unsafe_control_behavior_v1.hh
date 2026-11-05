#pragma once
#include <Texo/diagnostics/diagnostics_v1.hh>
#include <Texo/diagnostics/provenance_v1.hh>
namespace texo::diagnostics::v1 {struct explainability_receipt{bool verified_failure=false,trusted_continuation=false,unsafe_native_lowering=false,full_candidate_explanation=false,source_native_trace=false,provenance_stripping=false;};[[nodiscard]] bool freeze_explainability(const explainability_receipt&) noexcept;}
