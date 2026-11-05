#pragma once
#include <Texo/frontend/source/file_local_dialect_state_v1.hh>
#include <Texo/frontend/source/texo_pragma_contract_v1.hh>
namespace texo::frontend::source {
using dialect_state = file_local_dialect_stack_v1;
using dialect_pragma_result = pragma_result_v1;
} // namespace texo::frontend::source
