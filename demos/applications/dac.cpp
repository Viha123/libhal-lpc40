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

#include <cinttypes>

#include <libhal-armcortex/dwt_counter.hpp>
// #include "../../include/libhal-lpc40/dac.hpp"
#include <libhal-lpc40/dac.hpp>
#include <libhal-lpc40/clock.hpp>
#include <libhal-lpc40/constants.hpp>
#include <libhal-lpc40/uart.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

void application()
{
  hal::cortex_m::dwt_counter counter(
    hal::lpc40::get_frequency(hal::lpc40::peripheral::cpu));
  std::array<hal::byte, 32> buffer{};
  hal::lpc40::uart uart0(0, buffer);
  hal::print(uart0, "DAC Application Starting...\n");

  hal::lpc40::dac dac;
  while (true) {
    using namespace std::chrono_literals;
    float f1 = 0.0f;
    float f2 = 0.5f;
    float f3 = 1.0f;
    dac.write(f1);
    hal::print<128>(uart0, "Written %f\t", f1);
    hal::delay(counter, 1s);
    dac.write(f2);
    hal::print<128>(uart0, "Written %f\t", f2);
    hal::delay(counter, 1s);
    dac.write(f3);
    hal::print<128>(uart0, "Written %f\t", f3);
    hal::delay(counter, 1s);
  }
}