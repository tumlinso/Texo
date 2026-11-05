#include <Texo/program/retire_cellshard_compiler_authority_in_documentation_and_v1.hh>
#include <cassert>
using namespace texo::composition;
int main(){assert(std::string(compiler_authority_statement_v1).find("Texo owns")!=std::string::npos);auto ok=audit_retired_cellshard_compiler_authority_v1({{"include/CellShard/compiler/compat.hh",true,false},{"include/Texo/program/x.hh",false,true}});assert(ok.empty());auto bad=audit_retired_cellshard_compiler_authority_v1({{"src/CellShard/compiler/new.cc",false,true},{"include/CellShard/compiler/alias.hh",true,true}});assert(bad.size()==2);}
