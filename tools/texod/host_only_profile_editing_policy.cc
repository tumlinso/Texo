#include <Texo/tooling/host_only_profile_behavior_v1.hh>
int main(){return texo::tooling::editor_capabilities_v1(false,false).front().available?0:1;}
