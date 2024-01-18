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

#include <libhal-armcortex/system_control.hpp>
#include <libhal-lpc40/input_pin.hpp>

int main()
{
  auto input_pin = hal::lpc40::input_pin::get(2, 0).value();
  hal::result<hal::input_pin::level_t> pin_level = input_pin.level();
  if (pin_level) {
    printf("Pin Level = %d\n", pin_level.value().state);
  } else {
    printf("Reading pin level failed!\n");
  }

  return 0;
}

namespace boost {
void throw_exception(std::exception const& e)
{
  hal::halt();
}
}  // namespace boost

extern "C"
{
  struct _reent* _impure_ptr = nullptr;
}