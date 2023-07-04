///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2023.
//  Copyright Iliass Mahjoub 2023.
//  Copyright Amine Chalandi 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal_gpt.h>
#include <mcal_irq.h>
#include <MCAL/mcal_led.h>
#include <util/utility/util_time.h>

namespace local
{
  using timer_type = util::timer<std::uint32_t>;

  constexpr auto one_sec =
    static_cast<std::uint32_t>
    (
      timer_type::seconds(static_cast<unsigned>(UINT8_C(1)))
    );
}

int main()
{
  mcal::gpt::init(nullptr);
  mcal::irq::init(nullptr);

  mcal_led_init();

  for(;;)
  {
    mcal_led_toggle();

    local::timer_type::blocking_delay(local::one_sec);
  }
}
