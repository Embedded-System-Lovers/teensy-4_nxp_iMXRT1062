#include <MCAL/led.h>
#include <MCAL/timer.h>

extern unsigned int __IVT_BASE_ADDRESS;
volatile unsigned int cpt = 0;

int main()
{
  mcal_led_init();

#if !defined(_MSC_VER)
  /* Set the VTOR register */
  *((volatile int*)(0xE000ED08UL)) = (unsigned int)&__IVT_BASE_ADDRESS;

  /* Configure and start the systick timer */
  mcal_timer_SysTick_Init();
  mcal_timer_SysTick_Start();
#endif

  for(;;)
  {
#if defined(_MSC_VER)
    mcal_led_toggle();
#endif
    mcal_timer_delay();
  }

  return 0;
}

/* systick timer interrupt handler */
void __sys_tick_handler(void)
{
  cpt++;

  if(cpt >= 100ul)
  {
    mcal_led_toggle();
    cpt = 0;
  }
}

