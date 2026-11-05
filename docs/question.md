# The starting question

> What knowledge about a numerical problem’s structure can become reusable execution machinery, and how should a programming system express and exploit that knowledge?

A numerical problem contains more than the values supplied to one function call. Its relationships, ordering, repeated patterns, permitted numerical transformations, and expected reuse can create opportunities for preparation. Those opportunities have lifetimes: changing a value need not invalidate a representation prepared from connectivity, while changing connectivity may do so.

Texo investigates how a programming system could express, use, and maintain this knowledge. The scope is general numerical computation; biology is one source of motivating problems.

## A computation to reason about

Consider a directed relation with edges $e=(j,i)$ and the computation

$$
y_i = \sum_{e=(j,i)\in E} w_e x_j.
$$

Connectivity $E$ may persist across many evaluations while the input values $x$ and coefficients $w$ change. Some regions may be regular or block-like; others may be irregular. Related computations, including derivatives, may use the same connectivity.

A system could prepare indexing, ordering, partitions, packed representations, or other execution resources from the stable structure. Different regions could use different implementations, with explicit mappings back to the logical result. Preparation could then survive evaluations for which its assumptions remain valid.

This is a motivating example, not a commitment to a sparse-only language or an edge-based universal representation. Dense, structured, conditional, and hybrid computations remain relevant. An activity change must be interpreted according to the operation’s contract: changing a coefficient and changing the set of required contributions can have different consequences.

## Questions for a programming system

- **Meaning:** What identifies the logical inputs, relationships, and outputs? Which effects, precision rules, and ordering requirements must be preserved?
- **Representation:** Which facts justify an index, permutation, packed layout, or materialized intermediate? How are physical positions mapped back to logical identities?
- **Decomposition:** Can one computation use several implementations while preserving every required contribution, including any multiplicity or declared combination of partial results?
- **Preparation and change:** What may be retained, what changes invalidate it, and how can invalidation be checked without repeating all preparation?
- **Execution:** What can an interpreter dispatch to existing numerical operations? When would generated code provide a useful additional capability?
- **Complete cost:** When do savings repay analysis, conversion, allocation, movement, compilation, and maintenance? Comparisons must include the expected reuse and the cost of responding to changes, as well as execution time.

The representation of a program is open. A host-language API, an operation representation, a dedicated syntax, and combinations are possibilities to investigate. The presence of a graph or intermediate representation alone does not settle the programming model.

## Hypotheses to test

1. Separating the lifetimes of structure, support, ordering, values, and parameters can preserve useful preparation through changes that would otherwise trigger unnecessary work.
2. Choosing representations and implementations for different regions can improve a complete workload when recombination is correct and conversion costs are included.
3. Explicit structural assumptions and numerical contracts can make specialization easier to inspect and validate.

These are research hypotheses, not established contributions. A useful result could identify when the machinery fails to repay its cost or when an ordinary prepared library call already solves the problem adequately. Claims of novelty require a specific mechanism and comparison with prior work.

## Relevant precedents

- [Halide](https://halide-lang.org/) separates algorithm descriptions from execution schedules.
- [TACO](https://tensor-compiler.org/docs/) compiles tensor algebra over combinations of sparse and dense representations.
- [Finch: Sparse and Structured Tensor Programming with Control Flow](https://arxiv.org/abs/2404.16730) co-optimizes control flow and structured array representations.
- [Galley: Modern Query Optimization for Sparse Tensor Programs](https://arxiv.org/abs/2408.14706) applies cost-based logical and physical planning to sparse tensor programs.
- [Mosaic: An Interoperable Compiler for Tensor Algebra](https://fredrikbk.com/publications/mosaic.pdf) combines external library functions with generated code.

These systems establish substantial precedent. The task is to find a precise question Texo can answer, and then determine whether an existing system, a small extension, or a separate design is the appropriate vehicle.

## The first experiment

Specify one computation, the structural facts available to the system, the changes allowed between evaluations, and the observable execution contract. Choose a strong conventional baseline and an independent correctness reference. Compare full preparation, execution, and maintenance costs under declared conditions.

The initial deliverable is that experimental specification. It should make a positive, negative, or inconclusive outcome interpretable before implementation begins.
