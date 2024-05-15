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

#pragma once

#include <cstdint>

#include <libhal/dac.hpp>
#include <libhal/initializers.hpp>
#include <libhal/units.hpp>

#include "pin.hpp"

namespace hal::lpc40 {
  /**
 * @brief Digital to Analog converter
 *
 */
class dac : public hal::dac
{
public:

  //TODO figure out constructors
  //not sure if this is a default constructor. Only one pin(i think) can do D/A in this chip
  // P[0]26 which i assume is port 0 pin 26

  dac(std::uint8_t p_port, std::uint8_t p_pin);
  
  virtual ~dac() = default;

private: 
  void driver_write(float p_percentage) override;
  std::uint8_t m_port{};
  std::uint8_t m_pin{};
  pin dac_pin; 
};
}

