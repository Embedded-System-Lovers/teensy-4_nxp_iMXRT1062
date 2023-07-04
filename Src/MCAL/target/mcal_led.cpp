///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdint>

#include <MCAL/mcal_led.h>
#include <MCAL/mcal_reg_access_static.h>

extern "C"
{
  void mcal_led_init  (void) { mcal::reg::reg_access_static<std::uint32_t, std::uint32_t, static_cast<std::uint32_t>(UINT32_C(0x401BC004)), static_cast<std::uint32_t>(1UL << 3UL)>::reg_or(); }
  void mcal_led_on    (void) { mcal::reg::reg_access_static<std::uint32_t, std::uint32_t, static_cast<std::uint32_t>(UINT32_C(0x401BC084)), static_cast<std::uint32_t>(1UL << 3UL)>::reg_or(); }
  void mcal_led_off   (void) { mcal::reg::reg_access_static<std::uint32_t, std::uint32_t, static_cast<std::uint32_t>(UINT32_C(0x401BC088)), static_cast<std::uint32_t>(1UL << 3UL)>::reg_or(); }
  void mcal_led_toggle(void) { mcal::reg::reg_access_static<std::uint32_t, std::uint32_t, static_cast<std::uint32_t>(UINT32_C(0x401BC08C)), static_cast<std::uint32_t>(1UL << 3UL)>::reg_or(); }
}
