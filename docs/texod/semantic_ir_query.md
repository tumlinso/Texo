> Extracted design reference: the Texo rename preserves this compiler contract. It is not a claim that the complete compiler or language tooling is integrated. See [current build coverage](../development.md).

# Semantic IR at cursor

This page specifies query semantics; it is not independent evidence that the current server exposes the described query. Check the [current implementation boundary](../current_implementation.qmd) and [source routing guide](../development/routing.md) for current support.

The normalized field or operation view retains source mapping, effects, active profiles, and extension provenance. Controlled code actions round-trip a selected Semantic IR edit back into source.
