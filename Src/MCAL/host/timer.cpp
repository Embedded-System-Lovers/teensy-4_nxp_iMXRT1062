#include <chrono>
#include <thread>

#include <MCAL/timer.h>

extern "C"
void mcal_timer_delay(void)
{
  std::this_thread::sleep_for(std::chrono::seconds(1U));
}
