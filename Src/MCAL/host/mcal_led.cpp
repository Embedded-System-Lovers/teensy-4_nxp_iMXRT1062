///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>

#include <MCAL/mcal_led.h>

namespace local
{
  auto led_is_on() -> bool&
  {
    static auto my_led_is_on = false;

    return my_led_is_on;
  }
}

extern "C"
{
  void mcal_led_init  (void) { }
  void mcal_led_on    (void) { local::led_is_on() = true;  std::cout << "LED0 is: ON"  << std::endl; }
  void mcal_led_off   (void) { local::led_is_on() = false; std::cout << "LED0 is: OFF" << std::endl; }
  void mcal_led_toggle(void) { (local::led_is_on() ? ::mcal_led_off() : mcal_led_on()); }
}
