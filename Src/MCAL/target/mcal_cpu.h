///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MCAL_CPU_2009_02_14_H
  #define MCAL_CPU_2009_02_14_H

  namespace mcal { namespace cpu {

  auto init() -> void;

  auto post_init() -> void;

  inline auto nop() -> void;

  } } // namespace mcal::cpu


  inline auto mcal::cpu::nop() -> void { asm volatile("nop"); }

#endif // MCAL_CPU_2009_02_14_H
