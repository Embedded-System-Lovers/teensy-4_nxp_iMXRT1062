///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#if defined(__GNUC__)
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wvolatile"
#endif

#include <MCAL/led.h>

extern "C"
{
  void mcal_led_init  (void) { *((volatile unsigned int*)(0x401BC004UL)) |= (1UL << 3UL); }
  void mcal_led_on    (void) { *((volatile unsigned int*)(0x401BC084UL)) |= (1UL << 3UL); }
  void mcal_led_off   (void) { *((volatile unsigned int*)(0x401BC088UL)) |= (1UL << 3UL); }
  void mcal_led_toggle(void) { *((volatile unsigned int*)(0x401BC08CUL)) |= (1UL << 3UL); }
}

#if defined(__GNUC__)
  #pragma GCC diagnostic pop
#endif
