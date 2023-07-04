///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MCAL_LED_2023_07_01_H
  #define MCAL_LED_2023_07_01_H

  #if defined(__cplusplus)
  extern "C"
  {
  #endif

  void mcal_led_init  (void);
  void mcal_led_on    (void);
  void mcal_led_off   (void);
  void mcal_led_toggle(void);

  #if defined(__cplusplus)
  }
  #endif

#endif // MCAL_LED_2023_07_01_H
