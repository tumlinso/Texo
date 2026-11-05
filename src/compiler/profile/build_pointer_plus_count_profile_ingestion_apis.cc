#include <Texo/profile/build_pointer_plus_count_profile_ingestion_apis_v1.hh>
extern "C" ce_profile_ingestion_status_v1 ce_ingest_profile_observations_v1(
    const ce_profile_ingestion_batch_v1 *batch, const ce_profile_ingestion_sink_v1 *sink) {
    if (batch == nullptr || sink == nullptr || sink->emit == nullptr)
        return CE_PROFILE_INGEST_INVALID_V1;

    const ce_profile_observation_span_v1 spans[] = {
        batch->relation, batch->support, batch->value, batch->trace};
    for (uint32_t i = 0; i < 4u; ++i) {
        const auto &span = spans[i];
        if (span.kind != i + 1u ||
            (span.count != 0u && (span.data == nullptr || span.element_bytes == 0u)))
            return CE_PROFILE_INGEST_INVALID_V1;
        if (span.count != 0u && !sink->emit(sink->context, &span))
            return CE_PROFILE_INGEST_REJECTED_V1;
    }
    return CE_PROFILE_INGEST_OK_V1;
}
