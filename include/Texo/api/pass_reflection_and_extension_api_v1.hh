#pragma once
#include <Texo/pass/extension_v1.hh>
#include <Texo/pass/pass_v1.hh>
#include <Texo/pass/self_transform_v1.hh>
#include <Texo/reflection/reflection_v1.hh>
#include <cstdint>
namespace texo::api::v1 {
struct programmable_compiler_surface_v1{std::uint32_t abi_version=1;bool passes=true;bool reflection=true;bool extensions=true;bool same_compilation=true;bool explicit_trust=true;};
[[nodiscard]] programmable_compiler_surface_v1 programmable_compiler_surface() noexcept;
}
