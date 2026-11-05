#include "cmake/compiler/part_one_acceptance_v1.hh"

#include <cassert>
#include <set>
#include <string_view>

int main() {
    using namespace texo::acceptance::v1;
    const std::set<std::string_view> artifacts(host_sdk_artifacts.begin(), host_sdk_artifacts.end());
    assert(artifacts.size() == host_sdk_artifacts.size());
    assert(artifacts.count("texo") == 1);
    assert(artifacts.count("libTexo") == 1);
    assert(artifacts.count("texod") == 1);
    assert(artifacts.count("cmake-package") == 1);
}
