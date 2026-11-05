#include <Texo/diagnostics/structured_diagnostic_queries_v1.hh>
#include <sstream>
namespace texo::diagnostics::v1 {
namespace {

std::string escape(const std::string &text) {
    std::string result;
    for (const char byte : text) {
        if (byte == '"' || byte == '\\') result += '\\';
        result += byte;
    }
    return result;
}

}  // namespace

std::string to_lsp_json(const structured_diagnostic &diagnostic) {
    std::ostringstream out;
    out << "{\"id\":" << diagnostic.stable_id
        << ",\"related\":" << diagnostic.related_id
        << ",\"range\":{\"line\":" << diagnostic.line
        << ",\"column\":" << diagnostic.column
        << "},\"severity\":" << diagnostic.severity
        << ",\"code\":\"" << escape(diagnostic.code)
        << "\",\"message\":\"" << escape(diagnostic.message) << "\"}";
    return out.str();
}

std::size_t stream_diagnostics(const std::vector<structured_diagnostic> &diagnostics,
                               diagnostic_callback callback, void *context,
                               cancellation_query cancelled, void *cancellation_context) {
    if (!callback) return 0;
    std::size_t count = 0;
    for (const auto &diagnostic : diagnostics) {
        if (cancelled && cancelled(cancellation_context)) break;
        if (!callback(diagnostic, context)) break;
        ++count;
    }
    return count;
}
}
