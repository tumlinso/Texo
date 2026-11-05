# CMake package exports v1

The relocatable package exposes `Texo::Compiler`, `Runtime`,
`BackendCUDA`, and `ProviderSDK`, plus compiler/runtime/backend feature and
TEXO_IR/profile version variables. Dependencies resolve through installed package
metadata. Exported properties contain no source- or build-tree paths.
