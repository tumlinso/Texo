#pragma once

#include <Texo/sema/state_semantics_v1.hh>

#include <cstdint>

namespace texo::sema::v1 {

enum class semantic_cast_mode : std::uint8_t { checked = 1, trusted, unsafe };
enum class semantic_cast_status : std::uint8_t {
    ok = 0,
    null_view,
    unrepresentable_rank,
    unrepresentable_type,
    contract_mismatch
};

struct ordinary_cxx_view {
    void *data = nullptr;
    cellerator::execution::numeric_type element_type = cellerator::execution::numeric_type::invalid;
    cellerator::execution::residency_kind residency = cellerator::execution::residency_kind::host;
    std::uint8_t rank = 0;
    std::uint64_t shape[cellerator::execution::biological_operand_max_axes]{};
};

struct semantic_cast_result {
    state_view value{};
    semantic_cast_status status = semantic_cast_status::ok;
    bool warning = false;
    const char *effect_contract = nullptr;
};

semantic_cast_result cast_to_semantic_state(
    const ordinary_cxx_view &source,
    state_type destination,
    semantic_cast_mode mode,
    const char *effect_contract) noexcept;

}  // namespace texo::sema::v1
