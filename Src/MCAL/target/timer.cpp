#include <MCAL/timer.h>

extern "C"
void mcal_timer_delay(void)
{
  for(volatile uint32_t count = 0U; count < (uint32_t) UINT32_C(7500000); ++count)
  {
    ;
  }
}

extern "C"
void mcal_timer_SysTick_Init(void)
{
  pSTK_CTRL->u32Register     = 0;
  pSTK_LOAD->bits.u24RELOAD  = OS_SYS_TICK_MS(10);
  pSTK_VAL->u32Register      = 0;
  pSTK_CTRL->bits.u1CLOCKSRC = SYS_TICK_CLKSRC_AHB;
  pSTK_CTRL->bits.u1TICKINT  = SYS_TICK_ENABLE_INT;
}

extern "C"
void mcal_timer_SysTick_Start(void)
{
  pSTK_CTRL->bits.u1ENABLE = SYS_TICK_ENABLE_TIMER;
}
