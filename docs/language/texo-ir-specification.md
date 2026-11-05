> Extracted design reference: the Texo rename preserves this compiler contract. It is not a claim that the complete compiler or language tooling is integrated. See [current build coverage](../development.md).

# Texo IR conformance specification

Part One exposes three writable, source-linked levels: Semantic IR preserves
biological identity, orders, generations, effects, and profiles; Planning IR
holds exact-cover problems, candidates, constraints, evidence, and complete
costs; Realization IR records selected projections, stages, resources,
readiness, and native artifacts.

Reflection and inline IR operate on the same versioned contracts. Custom passes
must declare preservation and invalidation, staged transforms retain provenance,
and extensions are versioned. Trust modes never erase verification boundaries.
Native fragments are explicit unsafe boundaries. Text/binary round trips retain
identity, unknown extensions, and source maps. LTO consumes object TEXO_IR summaries
without requiring source reconstruction or a JIT.
