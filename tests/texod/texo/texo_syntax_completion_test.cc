#include "../../../src/compiler/tooling/texo/tooling_model.hh"
#include <cassert>
#include <string>
using namespace texo::tooling::v1;
int main(){auto all=complete_texo_syntax("field { rel",11);assert(all.size()==1&&all[0].spelling=="relation");auto malformed=complete_texo_syntax("field {\n  ",10);assert(malformed.size()>=12);auto native=complete_texo_syntax("nat",3);assert(native.size()==1&&native[0].category=="native-block");}
