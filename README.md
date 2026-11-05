# Texo

A research project exploring languages and runtimes for structured numerical computation.

Texo asks:

> What knowledge about a numerical problem’s structure can become reusable execution machinery, and how should a programming system express and exploit that knowledge?

Connectivity, ordering, repeated substructure, numerical rules, and the lifetime of those facts can affect how a computation should be represented, prepared, and executed. Texo explores making that knowledge available to a programming system while keeping the computation’s meaning explicit.

The project grew out of compiler research in [Cellerator](https://github.com/tumlinso/Cellerator), a biological machine-learning framework. Texo now owns the extracted language/compiler implementation, language resources, tests, and research records. Cellerator retains modeling and numerical operations, derivatives, geometry/layout planning, kernels, and numerical execution. Compiler adapters may consume those Cellerator APIs; Cellerator does not require Texo.

Interpretation through existing numerical operations, execution planning, and ahead-of-time or just-in-time compilation remain approaches to investigate. The transferred implementation is existing work to inspect and develop, rather than a commitment to its syntax, architecture, or backend as the final Texo research design.

The host bootstrap builds the source frontend and the existing downstream-compiler passthrough and architecture-descriptor tools. It runs focused source, parser, AST, IR, and artifact-contract tests. This is not an integrated end-to-end compiler or a demonstrated performance result. See [development and current build coverage](docs/development.md).

Public compiler names use `<Texo/...>`, `texo::...`, `Texo::...`, and the `texo`/`texod` tools. Language resources use `.texo`, `.texoir`, and `.texoprofile`; renamed binary artifacts use new format identities and reject the former formats. [Historical Cellerator records](docs/history/cellerator/) retain their original bytes and claims for provenance, not current capability status.

Read the [starting question](docs/question.md) for the motivating example, hypotheses, and related work. [Issue #1](https://github.com/tumlinso/Texo/issues/1) still calls for an experimental specification with an independent correctness reference and complete-cost comparison. No novelty or speedup is established by the extraction.
