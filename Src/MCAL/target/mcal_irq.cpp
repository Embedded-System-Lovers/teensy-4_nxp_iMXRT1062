
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
