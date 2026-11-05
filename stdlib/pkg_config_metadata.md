# Lightweight package metadata v1

Platforms supporting pkg-config receive `texo.pc` with prefix-relative
include/library paths and only the public `-lTexo` link dependency.
Non-CMake Makefile consumers obtain flags through `pkg-config --cflags --libs
texo`; compiler resource/profile options remain explicit command flags.
