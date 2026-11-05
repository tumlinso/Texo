#pragma once

#include <Cellerator/execution/operands.hh>

#include <cstdint>

namespace texo::sema::v1 {

enum class nonfinite_contract : std::uint8_t { propagate = 1, reject, saturate };
enum class precision_contract : std::uint8_t { exact_storage = 1, promote_compute, mixed };
enum class approximation_contract : std::uint8_t { forbidden = 1, bounded, permitted };

struct numerical_tuple {
    cellerator::execution::numeric_type relation_storage = cellerator::execution::numeric_type::invalid;
    cellerator::execution::numeric_type dense_input = cellerator::execution::numeric_type::invalid;
    cellerator::execution::numeric_type compute = cellerator::execution::numeric_type::invalid;
    cellerator::execution::numeric_type accumulation = cellerator::execution::numeric_type::invalid;
    cellerator::execution::numeric_type output = cellerator::execution::numeric_type::invalid;
    nonfinite_contract nonfinite = nonfinite_contract::propagate;
    precision_contract precision = precision_contract::exact_storage;
    approximation_contract approximation = approximation_contract::forbidden;
};

struct numerical_candidate_capability {
    cellerator::execution::numeric_type storage = cellerator::execution::numeric_type::invalid;
    cellerator::execution::numeric_type compute = cellerator::execution::numeric_type::invalid;
    cellerator::execution::numeric_type accumulation = cellerator::execution::numeric_type::invalid;
    bool preserves_nonfinite = true;
    bool approximate = false;
};

bool valid_numerical_tuple(const numerical_tuple &tuple) noexcept;
bool numerical_candidate_legal(const numerical_tuple &tuple,
                               const numerical_candidate_capability &candidate) noexcept;

}  // namespace texo::sema::v1
