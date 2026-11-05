#include <Texo/diagnostics/build_the_provenance_graph_model_v1.hh>
#include <set>
namespace texo::diagnostics::v1 {
bool valid_provenance_graph(const provenance_graph &graph) noexcept {
    std::set<std::uint64_t> ids;
    for (const auto &node : graph.nodes)
        if (!node.id || !ids.insert(node.id).second) return false;
    for (const auto &edge : graph.edges)
        if (!ids.count(edge.from) || !ids.count(edge.to) || edge.from == edge.to) return false;
    return true;
}

std::vector<std::uint64_t> query_provenance(const provenance_graph &graph,
                                            std::uint64_t root, bool reverse) {
    if (!valid_provenance_graph(graph)) return {};
    std::vector<std::uint64_t> result{root};
    std::set<std::uint64_t> seen{root};
    for (std::size_t i = 0; i < result.size(); ++i) {
        for (const auto &edge : graph.edges) {
            const auto from = reverse ? edge.to : edge.from;
            const auto to = reverse ? edge.from : edge.to;
            if (from == result[i] && seen.insert(to).second) result.push_back(to);
        }
    }
    return result;
}
}
