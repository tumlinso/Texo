> Extracted design reference: the Texo rename preserves this compiler contract. It is not a claim that the complete compiler or language tooling is integrated. See [current build coverage](../development.md).

# Texo syntax completion

This page specifies query semantics; it is not independent evidence that the current server exposes the described query. Check the [current implementation boundary](../current_implementation.qmd) and [source routing guide](../development/routing.md) for current support.

Completion is derived from the source prefix at the cursor and remains available for incomplete or malformed input. The baseline vocabulary covers declarations, fields, typed relations, operation/effect controls, persistence and profiles, reflection, passes, inline TEXO_IR, and native blocks.
