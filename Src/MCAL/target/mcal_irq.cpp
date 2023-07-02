///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal_irq.h>

extern "C"
{
  extern unsigned int __IVT_BASE_ADDRESS;
}

auto mcal::irq::init(const config_type*) -> void
{
  // Set the VTOR register.
  *((volatile int*)(0xE000ED08UL)) = (unsigned int)&__IVT_BASE_ADDRESS;
}
