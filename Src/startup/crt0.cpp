///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// Generic Cortex-M startup code.

namespace crt
{
  void init_ram();
  void init_ctors();
}

extern "C" void __my_startup() __attribute__((used, noinline));

void __my_startup()
{
  // Load the stack pointer.
  // The stack pointer is automatically loaded from
  // the base position of the interrupt vector table.
  // So we do nothing here.

  // Chip init: Watchdog, port, and oscillator.
  //mcal::cpu::init();

  #define CCM_ANALOG_PLL_ARM      *(volatile unsigned int*)(0x400D8000UL) /*BootROM forced to 0x80002042*/
  #define CCM_ANALOG_PLL_ARM_SET  *(volatile unsigned int*)(0x400D8004UL)
  #define CCM_ANALOG_PLL_ARM_CLR  *(volatile unsigned int*)(0x400D8008UL)
  #define CCM_ANALOG_PLL_ARM_TOG  *(volatile unsigned int*)(0x400D800CUL)

  #define CCM_CBCDR               *(volatile unsigned int*)(0x400FC014UL) /*BootROM forced to 0x000A8200*/
  #define CCM_CACRR               *(volatile unsigned int*)(0x400FC010UL) /*BootROM forced to 0x00000001*/
  #define CCM_CBCMR               *(volatile unsigned int*)(0x400FC018UL) /*BootROM forced to 0x75AE8104*/

  #define DCDC_REG0               *(volatile unsigned int*)(0x40080000UL)
  #define DCDC_REG3               *(volatile unsigned int*)(0x4008000CUL)

  /* Increase the power */
  DCDC_REG3 = (DCDC_REG3 & (~(0x1Ful))) | 0x1F;

  while((DCDC_REG0 & 0x80000000) != 0x80000000);

  /* Switch temporary the CPU Subsystem clock to PLL2 (528 MHz)*/
  CCM_CBCMR = (CCM_CBCMR & (~(3ul << 18)));


  /* Enable PLL1 bypass */
  CCM_ANALOG_PLL_ARM = (CCM_ANALOG_PLL_ARM & (~(3UL << 14))) | (1UL << 16);

  /* Set the PLL1 to 600 MHz */
  CCM_ANALOG_PLL_ARM = (CCM_ANALOG_PLL_ARM & (~((0x7FUL << 0) | (1UL << 12)))) | (1UL << 13) | 0x64;

  /* Wait for the PLL1 to lock */
  while ((CCM_ANALOG_PLL_ARM & 0x80000000ul) == 0UL);

  /* Disable PLL1 bypass */
  CCM_ANALOG_PLL_ARM &= ~(1UL << 16);


  /* switch back the CPU Subsystem clock to the new PLL1 (600 MHz) */
  CCM_CBCMR = (CCM_CBCMR & (~(3ul << 18))) | (3ul << 18);

  // Initialize statics from ROM to RAM.
  // Zero-clear default-initialized static RAM.
  crt::init_ram();
  //mcal::wdg::secure::trigger();

  // Call all ctor initializations.
  crt::init_ctors();
  //mcal::wdg::secure::trigger();

  // Jump to main (and never return).
  asm volatile("ldr r3, =main");
  asm volatile("blx r3");

  // Catch an unexpected return from main.
  for(;;)
  {
    // Replace with a loud error if desired.
    //mcal::wdg::secure::trigger();
  }
}
