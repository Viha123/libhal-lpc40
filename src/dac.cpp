// Copyright 2024 Khalil Estell
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "dac_reg.hpp"
#include <libhal-lpc40/dac.hpp>
#include <libhal-lpc40/pin.hpp>
namespace hal::lpc40 {

dac::dac(std::uint8_t p_port, std::uint8_t p_pin)
  : m_port(p_port)
  , m_pin(p_pin)
{
  pin dac_pin(m_port, m_pin);
  dac_pin.analog(true);
  dac_pin.dac(true);
}
/**
 * @brief Convert channel info void pointer to an dac register map type
 *
 * @param p_pointer - pointer to the start
 * @return dac_reg_t*
 */
dac_reg_t* to_reg_map(std::intptr_t p_pointer)
{
  return reinterpret_cast<dac_reg_t*>(p_pointer);  // NOLINT
}

void dac::driver_write(float p_percentage)
{
  auto bits_to_modify = p_percentage >> 22;  // getting the 10 most significant bits to set the value
  // then i need to bit_modify this value on the dac_pin's converter register's
  // value bits.
  auto* dac_register = to_reg_map(lpc_dac_addr); //start to address of dac 
  hal::bit_modify(dac_register->converter).set<dac_converter_register::value>();
  // now voltage on this pin SHOULD BE value * Vref/1024 which makes sense i
  // hope
}
}  // namespace hal::lpc40
