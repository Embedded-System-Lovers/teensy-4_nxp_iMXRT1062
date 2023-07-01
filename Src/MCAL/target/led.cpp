#include <MCAL/led.h>

extern "C"
{
  void led_init  (void) { *((volatile unsigned int*)(0x401BC004UL)) |= (1UL << 3UL); }
  void led_on    (void) { *((volatile unsigned int*)(0x401BC084UL)) |= (1UL << 3UL); }
  void led_off   (void) { *((volatile unsigned int*)(0x401BC088UL)) |= (1UL << 3UL); }
  void led_toggle(void) { *((volatile unsigned int*)(0x401BC08CUL)) |= (1UL << 3UL); }
}
