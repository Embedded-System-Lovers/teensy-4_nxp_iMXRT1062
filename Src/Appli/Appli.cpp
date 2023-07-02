#include <mcal_gpt.h>
#include <MCAL/led.h>
#include <util/utility/util_time.h>

#if !defined(_MSC_VER)
extern "C"
{
  extern unsigned int __IVT_BASE_ADDRESS;
}
#endif

int main()
{
  mcal::gpt::init(nullptr);

  mcal_led_init();

#if !defined(_MSC_VER)
  /* Set the VTOR register */
  *((volatile int*)(0xE000ED08UL)) = (unsigned int)&__IVT_BASE_ADDRESS;
#endif

  for(;;)
  {
    mcal_led_toggle();

    using timer_type = util::timer<std::uint32_t>;

    constexpr auto one_sec =
      static_cast<std::uint32_t>(timer_type::seconds(static_cast<unsigned>(UINT8_C(1))));

    timer_type::blocking_delay(one_sec);
  }
}
