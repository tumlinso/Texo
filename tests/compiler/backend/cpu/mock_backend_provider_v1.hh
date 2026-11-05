#pragma once

#include <Texo/backend/backend_provider_abi_v1.hh>

[[nodiscard]] texo::backend::v1::backend_provider_v1
make_mock_backend_provider_v1() noexcept;
