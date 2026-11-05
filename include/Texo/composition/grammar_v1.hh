#pragma once

#include <Texo/composition/explicit_grammar_compilation_v1.hh>
#include <Texo/composition/experimental_induced_grammar_search_v1.hh>
#include <Texo/composition/multi_parent_derivation_dags_v1.hh>
#include <Texo/composition/superatom_promotion_v1.hh>
#include <Texo/composition/typed_composition_production_contracts_v1.hh>

#include <cstdint>

namespace texo::composition {

inline constexpr std::uint32_t grammar_contract_version_v1 = 1;

} // namespace texo::composition
