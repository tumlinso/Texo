#include <Texo/migration/atom_semantics_ownership_contract_v1.hh>
#include <Texo/migration/basis_selection_ownership_contract_v1.hh>
#include <Texo/migration/evidence_proposal_ownership_contract_v1.hh>
#include <Texo/migration/exact_certification_ownership_contract_v1.hh>
#include <Texo/migration/global_operation_program_ownership_contract_v1.hh>
#include <Texo/migration/superatom_promotion_ownership_contract_v1.hh>
#include <Texo/migration/typed_composition_graph_ownership_contract_v1.hh>
#include <Texo/migration/portable_schedule_ownership_contract_v1.hh>
#include <Texo/migration/cellshard_ruleset_export_contract_v1.hh>
#include <Texo/migration/temporary_cellshard_migration_adapter_v1.hh>
#include <Texo/migration/retained_cellshard_application_boundary_v1.hh>
#include <Texo/migration/compiler_ownership_rehoming_contract_v1.hh>
#include <Texo/migration/reconcile_old_jbc_documentation_and_active_run_status_v1.hh>
#include <Texo/migration/split_persistent_partial_semantics_from_partial_storage_v1.hh>
#include <iostream>
#include <set>
#include <stdexcept>
using namespace texo::migration;
int main(){try{std::set<std::string_view> old;for(auto r:compiler_ownership_rehoming_v1)if(!old.insert(r.old_cellshard_family).second)throw std::runtime_error("duplicate subsystem");if(old.size()!=12||!complete_ownership_map_v1()||!application_only_boundary_v1()||!acyclic_partial_dependency_v1()||!preserves_history_v1())throw std::runtime_error("ownership contract incomplete");for(auto a:temporary_adapters_v1)if(a.owns_semantics)throw std::runtime_error("adapter owns semantics");if(owner_of(atom_level_v1::resident)!=atom_owner_v1::cellshard_application)throw std::runtime_error("resident instance owner wrong");if(authorizes_execution(proposal_evidence_identity_v1{1,2,3,4,5}))throw std::runtime_error("proposal certifies execution");std::cout<<"validated 12-row complete compiler ownership map\n";return 0;}catch(const std::exception&e){std::cerr<<e.what()<<'\n';return 1;}}
