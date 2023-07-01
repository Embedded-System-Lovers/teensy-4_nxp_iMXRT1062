#include <iostream>

#include <MCAL/led.h>

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
