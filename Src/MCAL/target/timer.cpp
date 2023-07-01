#include <MCAL/timer.h>

extern "C"
void timer_delay(void)
{
  for(volatile uint32_t count = 0U; count < (uint32_t) UINT32_C(50000000); ++count)
  {
    ;
  }
}
