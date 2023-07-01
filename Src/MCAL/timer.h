#ifndef TIMER_2023_07_01_H
  #define TIMER_2023_07_01_H

  #include <stdint.h>

  #if defined(__cplusplus)
  extern "C"
  {
  #endif

  static inline void mcal_timer_delay(void)
  {
    for(volatile uint32_t count = 0U; count < (uint32_t) UINT32_C(50000000); ++count)
    {
      ;
    }
  }

  #if defined(__cplusplus)
  }
  #endif

#endif /* TIMER_2023_07_01_H */
