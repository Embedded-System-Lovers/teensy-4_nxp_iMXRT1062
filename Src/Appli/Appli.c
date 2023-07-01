#if !defined(_MSC_VER)
#define RCC_AHB1ENR *(volatile unsigned*) 0x40023830U
#else
static unsigned RCC_AHB1ENR;
#endif

#if !defined(_MSC_VER)
#define GPIOA_MODER *(volatile unsigned*) 0x40020000U
#else
static unsigned GPIOA_MODER;
#endif

#if !defined(_MSC_VER)
#define GPIOA_ODR *(volatile unsigned*) 0x40020014U
#else
static unsigned GPIOA_ODR;
#endif

int main()
{
  // Supply PortA energy.
  RCC_AHB1ENR |= 1U;

  // Set portA.5 direction to output.
  GPIOA_MODER |= (1U << (5U * 2U));
  GPIOA_MODER &= ~(1U << ((5U * 2U) + 1U));

  for(;;)
  {
    GPIOA_ODR ^= (1U << 5); // Toggle PortA.5.

    for(volatile unsigned count = 0U; count < 100000U; ++count) { ; }
  }

  return 0;
}
