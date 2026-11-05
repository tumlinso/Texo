#include <Texo/tooling/clangd_worker_lifecycle_v1.hh>

// Process spawning is supplied by the texod executable integration layer;
// this translation unit pins the independently testable worker lifecycle ABI.
static_assert(texo::tooling::clangd_worker_status_v1::running
              != texo::tooling::clangd_worker_status_v1::crashed);
