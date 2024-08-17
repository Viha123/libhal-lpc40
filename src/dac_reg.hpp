#pragma once

#include <array>

namespace hal::lpc40 {
struct dac_registers
{
  union
  {
    volatile std::uint32_t whole;
    std::array<volatile std::uint8_t, 4> parts;
  } conversion_register;
  volatile std::uint32_t control;
  volatile std::uint32_t count_value;
};

constexpr std::uintptr_t dac_address = 0x4008'C000;
inline auto* dac_reg = reinterpret_cast<dac_registers*>(dac_address);
namespace dac_converter_register {
  /// 
  static constexpr auto value = hal::bit_mask::from<6,15>();

  static constexpr auto bias = hal::bit_mask::from<16>();
}
}  // namespace hal::lpc40// Copyright 2024 Khalil Estell



