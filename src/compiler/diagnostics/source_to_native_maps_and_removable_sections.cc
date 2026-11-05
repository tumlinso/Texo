#include <Texo/diagnostics/source_to_native_maps_and_removable_sections_v1.hh>
namespace texo::diagnostics::v1 {
bool valid_source_native_map(const provenance_image &image) noexcept {
    if (!image.hot_bytes) return false;
    for (const auto &entry : image.cold_map)
        if (!entry.source_id || !entry.native_symbol) return false;
    return true;
}

provenance_image strip_provenance(provenance_image image) noexcept {
    image.cold_map.clear();
    return image;
}
}
