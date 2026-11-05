#include <Texo/tooling/document_scheduling_cancellation_v1.hh>

#include <cassert>

using namespace texo::tooling;

int main() {
    document_scheduler_v1 scheduler(10, 3);
    scheduler.edited("active.texo", 1, 0, true);
    const auto stale = scheduler.next_basic(10);
    assert(stale && !scheduler.cancelled(*stale));
    scheduler.edited("active.texo", 2, 11, true);
    assert(scheduler.cancelled(*stale));
    for (std::uint64_t index = 0; index < 20; ++index)
        scheduler.edited("file" + std::to_string(index) + ".texo", 1, index, false);
    assert(scheduler.pending_basic() <= 4);
    assert(!scheduler.next_basic(20));
    const auto active = scheduler.next_basic(21);
    assert(active && active->uri == "active.texo");

    scheduler.request_slow("active.texo", 2, document_work_kind_v1::profile);
    scheduler.request_slow("active.texo", 2, document_work_kind_v1::plan);
    assert(scheduler.pending_slow() == 2);
    assert(scheduler.next_basic(100));
    assert(scheduler.next_slow()->kind == document_work_kind_v1::profile);
}
