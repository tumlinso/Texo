#include <Texo/tooling/document_scheduling_cancellation_v1.hh>

int main() {
    texo::tooling::document_scheduler_v1 scheduler;
    scheduler.edited("stdin.texo", 1, 0, true);
    return scheduler.next_basic(50) ? 0 : 1;
}
