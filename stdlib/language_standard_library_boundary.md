# Language and standard-library boundary v1

Base-language constructs are limited to facts the compiler must parse, type,
validate, preserve, or reason about: file-local opt-in, domains and axes,
orders, states, relation transfer and operation semantics, execution fields,
effects, exact support and contribution ownership, profiles and planning
authority, identity/generations, and typed TEXO_IR/native escape boundaries.

The `.texo` standard library owns convenience and policy: storage owners and
views, binders/builders, containers, reorder/canonicalize helpers, bundles and
exchanges, common biological domain declarations, algorithms, biological
constructions, workflow policies, safe defaults, and reusable helper code.

Every language-spec construction is therefore disposed as one of:

- `semantic_fact`: compiler-reasoned and retained in the base language;
- `library_facility`: expressed as ordinary `.texo` library code;
- `explicit_unsafe_library_facility`: library code that cannot be implicit;
- `implementation_choice`: observable semantics fixed, representation free.

No convenience spelling alone may become privileged compiler syntax.
