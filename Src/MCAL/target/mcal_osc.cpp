///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2023.
//  Copyright Amine Chalandi 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal_osc.h>

#define CCM_ANALOG_PLL_ARM      *(volatile unsigned int*)(0x400D8000UL) /*BootROM forced to 0x80002042*/
#define CCM_ANALOG_PLL_ARM_SET  *(volatile unsigned int*)(0x400D8004UL)
#define CCM_ANALOG_PLL_ARM_CLR  *(volatile unsigned int*)(0x400D8008UL)
#define CCM_ANALOG_PLL_ARM_TOG  *(volatile unsigned int*)(0x400D800CUL)

#define CCM_CBCDR               *(volatile unsigned int*)(0x400FC014UL) /*BootROM forced to 0x000A8200*/
#define CCM_CACRR               *(volatile unsigned int*)(0x400FC010UL) /*BootROM forced to 0x00000001*/
#define CCM_CBCMR               *(volatile unsigned int*)(0x400FC018UL) /*BootROM forced to 0x75AE8104*/

#define DCDC_REG0               *(volatile unsigned int*)(0x40080000UL)
#define DCDC_REG3               *(volatile unsigned int*)(0x4008000CUL)

auto mcal::osc::init() noexcept -> void
{
  // Increase the power.
  DCDC_REG3 = (DCDC_REG3 & (~(0x1FUL))) | 0x1FUL;

  while((DCDC_REG0 & 0x80000000UL) != 0x80000000UL);

  // Switch the temporary CPU Subsystem clock to PLL2 (528 MHz).
  CCM_CBCMR = (CCM_CBCMR & (~(3UL << 18U)));

  // Enable the PLL1 bypass.
  CCM_ANALOG_PLL_ARM = (CCM_ANALOG_PLL_ARM & (~(3UL << 14U))) | (1UL << 16U);

  // Set PLL1 to 600 MHz.
  CCM_ANALOG_PLL_ARM = (CCM_ANALOG_PLL_ARM & (~((0x7FUL << 0U) | (1UL << 12U)))) | (1UL << 13U) | 0x64U;

  // Wait for the PLL1 to lock.
  while ((CCM_ANALOG_PLL_ARM & 0x80000000UL) == 0UL);

  // Disable the PLL1 bypass.
  CCM_ANALOG_PLL_ARM &= ~(1UL << 16U);

  // Switch the CPU Subsystem clock to the new PLL1 value (of 600 MHz).
  CCM_CBCMR = (CCM_CBCMR & (~(3UL << 18U))) | (3UL << 18U);
}
