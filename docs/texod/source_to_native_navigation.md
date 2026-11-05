> Extracted design reference: the Texo rename preserves this compiler contract. It is not a claim that the complete compiler or language tooling is integrated. See [current build coverage](../development.md).

# Source-to-native navigation

This page specifies query semantics; it is not independent evidence that the current server exposes the described query. Check the [current implementation boundary](../current_implementation.qmd) and [source routing guide](../development/routing.md) for current support.

Navigation links source operations through Semantic, Planning, and Realization nodes to generated C++, CUDA, or PTX, native symbols and resource reports. Native diagnostics reverse-map to the original source location.
