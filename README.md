# Texo

A research project exploring languages and runtimes for structured numerical computation.

Texo asks:

> What knowledge about a numerical problem’s structure can become reusable execution machinery, and how should a programming system express and exploit that knowledge?

Connectivity, ordering, repeated substructure, numerical rules, and the lifetime of those facts can affect how a computation should be represented, prepared, and executed. Texo explores making that knowledge available to a programming system while keeping the computation’s meaning explicit.

The project grew out of compiler research in [Cellerator](https://github.com/tumlinso/Cellerator), a biological machine-learning framework. Texo investigates the general numerical questions raised by that work. Graph learning, simulation, scientific computing, and other structured workloads are possible applications.

Interpretation through existing numerical operations, execution planning, and ahead-of-time or just-in-time compilation are possible approaches to investigate. No language syntax, implementation strategy, or backend is settled.

**This repository begins with research framing.** It contains no implementation or migrated Cellerator source, and makes no claim of novelty or demonstrated performance.

Read the [starting question](docs/question.md) for the motivating example, hypotheses, and related work. The first task is to define the smallest experiment that can test whether Texo adds value.
