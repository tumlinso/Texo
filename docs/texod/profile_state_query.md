> Extracted design reference: the Texo rename preserves this compiler contract. It is not a claim that the complete compiler or language tooling is integrated. See [current build coverage](../development.md).

# Profile state at cursor

This page specifies query semantics; it is not independent evidence that the current server exposes the described query. Check the [current implementation boundary](../current_implementation.qmd) and [source routing guide](../development/routing.md) for current support.

The query exposes selected and alternate states, supporting evidence and confidence, unknown dimensions and missing hints, plus expected support, value, and mutation state. Results update after incremental transformations.
