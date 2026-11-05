#include <Texo/sdk/texo_ir_ownership_and_mutation_api_v1.hh>
#include <cassert>
namespace ca=texo::api::v1;
int main(){for(auto level:{ca::texo_ir_level_v1::semantic,ca::texo_ir_level_v1::planning,ca::texo_ir_level_v1::realization}){auto m=ca::parse_texo_ir_v1(level,"op %1");assert(ca::validate_texo_ir_v1(m,ca::texo_ir_validation_v1::checked));auto b=ca::clone_texo_ir_v1(m);b.set_text("edited %1");b.add_provenance("external-editor");auto e=b.freeze();assert(ca::print_texo_ir_v1(e)=="edited %1");assert(e->provenance.size()==2);assert(!ca::serialize_texo_ir_v1(e).empty());}}
