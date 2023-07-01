#include <MCAL/led.h>
#include <MCAL/timer.h>

int main()
{
  mcal_led_init();

  for(;;)
  {
    mcal_led_toggle();

    mcal_timer_delay();
  }

  return 0;
}
