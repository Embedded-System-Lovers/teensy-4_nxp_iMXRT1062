#include <MCAL/led.h>
#include <MCAL/timer.h>

int main()
{
  led_init();

  for(;;)
  {
    led_toggle();

    timer_delay();
  }

  return 0;
}
