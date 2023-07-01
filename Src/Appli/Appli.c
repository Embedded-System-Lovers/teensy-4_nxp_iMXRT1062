
#if !defined(_MSC_VER)
  #define LED_INIT()   *((volatile unsigned int*)(0x401BC004UL)) |= (1ul << 3ul)
  #define LED_ON()     *((volatile unsigned int*)(0x401BC084UL)) |= (1ul << 3ul)
  #define LED_OFF()    *((volatile unsigned int*)(0x401BC088UL)) |= (1ul << 3ul)
  #define LED_TOGGLE() *((volatile unsigned int*)(0x401BC08CUL)) |= (1ul << 3ul)
#else
  #define LED_INIT()
  #define LED_ON()
  #define LED_OFF()
  #define LED_TOGGLE()
#endif

int main()
{
  LED_INIT();

  for(;;)
  {
    LED_TOGGLE();

    for(volatile unsigned count = 0U; count < 10000000U; ++count) { ; }
  }

  return 0;
}
