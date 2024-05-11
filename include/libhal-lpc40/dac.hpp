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
  static constexpr std::intptr_t lpc_apb0_base = 0x40000000UL;
  static constexpr std::intptr_t lpc_dac_addr = lpc_apb0_base + 0x8C000;

  //TODO figure out constructors
  //it shoudl just be defautl constructor cuz dac doens't seem to have channels
  dac();
  
  virtual ~dac() = default;

private: 
  void driver_write() override;

};
}
