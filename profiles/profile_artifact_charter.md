# Texo Profile Artifact v2

The compiler-owned profile container is named **Texo Profile Artifact
v2**. Its human-facing suffix is `.texoprofile`, its eight-byte magic is
`TEXOPRF2`, and its schema version is `2`.

The format stores representative, data-derived semantic states and their
evidence. It does not store compiler policy, concrete runtime pointers, dataset
paths as language semantics, or claims that statistical evidence establishes
mathematical correctness. The fixed header is standard-layout, trivially
copyable, pointer-free, endian-marked, and explicitly versioned. Artifact and
semantic-environment identities are independent from evidence revision.

## Collision audit

The chosen magic and `.texoprofile` suffix were checked against the repository's
reserved persistent identities: `CPI1`, `CPS1`, `SCR1`, `CELLPK01`, `CELLCSG1`,
`CELLEX02`, `CEORCL1\0`, `CCECHNK1`, `CSH5`, `CSPACK`, and `CPEXEC01`.
`TEXOPRF2` is distinct from each. The former `CELLPRF1` profile identity is
rejected. TEXO_IR's sectioned binary container uses the distinct `TXIR` magic.

Later revisions must use an adjacent versioned identity rather than changing
the meaning of `TEXOPRF2`. Unknown extension sections may be skipped, but the
header identity and correctness boundary remain stable.
