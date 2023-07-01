#ifndef LED_2023_07_01_H
  #define LED_2023_07_01_H

  #if defined(__cplusplus)
  extern "C"
  {
  #endif

  void mcal_led_init  (void);
  void mcal_led_on    (void);
  void mcal_led_off   (void);
  void mcal_led_toggle(void);

  #if defined(__cplusplus)
  }
  #endif

#endif /* LED_2023_07_01_H */
