# Development and build coverage

The extraction preserves the Cellerator compiler implementation under Texo ownership. The bootstrap deliberately builds a bounded host subset while the remaining compiler source, tests, and integration records remain available for further integration.

## Host bootstrap

Use CMake 3.28 or later and a C++20 compiler. The qualified extraction build uses Clang 18, its matching `clang-scan-deps-18`, and Ninja:

```sh
cmake -S . -B build -G Ninja \
  -DCMAKE_CXX_COMPILER=clang++-18 -DCMAKE_C_COMPILER=clang-18
cmake --build build
ctest --test-dir build --output-on-failure
cmake --install build --prefix /tmp/texo-install
```

The default build requires neither a Cellerator source tree nor CUDA, LLVM libraries, Python, or Torch. `Texo::Frontend` builds the extracted source/pragma and parser implementations. `Texo::HostTools` builds the downstream invocation helper and daemon architecture descriptor. `texo --driver <compiler> ...` passes arguments to the selected host compiler; `texod` validates and prints the existing descriptor. Neither tool is advertised as an end-to-end language compiler or a working language server.

The default tests exercise extracted source/pragma handling, parser examples, AST ownership, common IR construction/text/binary serialization, profile-format identity, resource-path contracts, and host-compiler passthrough. Assertions remain enabled. Resources install under `share/texo/2.2`, matching the renamed compiler-artifact and IR compatibility majors. Installed CMake metadata exposes the actual bootstrap targets and explicitly records that a complete compiler is unavailable.

## Retained source and integration boundary

Other subsystems under `src/compiler`, `include/Texo`, and `tests/compiler` retain their existing implementations. Semantic analysis and numerical lowering adapters use Cellerator's native identities, operation algebra, layouts, geometry planning, execution preparation, and numerical APIs. They must consume Cellerator rather than recreating those types or embedding a second numerical library in Texo.

The full SDK, planning/realization/backend graph, native numerical integration suites, compiler-to-runtime spine tests, and GPU backend paths are not all assembled by the bootstrap. Their copied CMake modules and tests are integration material, not evidence that each contract is implemented end to end. Existing native-dependent tests need a compatible Cellerator installation and corresponding target linkage before they can join the default build. No GPU workload or performance qualification is part of the extraction.

The numerical CPU loops, numerical geometry planner, native preparation/decomposition contracts, and scaled-tanh provider belong to Cellerator. Texo contains only their compiler-side consumers. Legacy Cellerator compiler headers and compiler command entry points are not compatibility interfaces.

## Formats and historical evidence

Compiler interfaces, resource names, source annotations, and source suffixes now use Texo identity. Serialized IR/profile and companion-object identities have new signatures and incremented major versions. Writers produce the renamed formats; readers reject the former identities instead of accepting old bytes under a new suffix. Fixture hashes are recomputed only for active renamed resources.

Compiler-owned historical reports, benchmark artifacts, and source snapshots remain byte-for-byte intact. They can contain former names, paths, timestamps, hashes, formats, and capability assertions. They are not compiled as part of the host bootstrap. Migration provenance records distinguish these preserved records from transformed active source.

The independent research question in `question.md` remains open. Completing the research experiment, redesigning the language, implementing a JIT, and qualifying compiler or numerical performance are subsequent work.
