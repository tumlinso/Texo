# CMake compiler integration helpers v1

`texo_compile_cell` integrates `.texo` compilation through custom
commands with response-safe argument lists, depfiles, explicit standard library,
profile and backend selection, optional LTO, and generator-independent outputs.
The profile argument is mandatory.
