#ifndef TIMER_2023_07_01_H
  #define TIMER_2023_07_01_H

  #include <stdint.h>

  #if defined(__cplusplus)
  extern "C"
  {
  #endif
  //=========================================================================================
  // Types definitions
  //=========================================================================================
  typedef union
  {
   struct
   {
    unsigned long u1ENABLE : 1;
    unsigned long u1TICKINT : 1;
    unsigned long u1CLOCKSRC : 1;
    unsigned long : 13;
    unsigned long u1COUNTFLAG : 1;
    unsigned long : 15;
   }bits;
  
   unsigned long u32Register;
  
  }stStkCtrl;
  
  typedef union
  {
   struct
   {
    unsigned long u24RELOAD : 24;
    unsigned long : 8;
   }bits;
  
   unsigned long u32Register;
  
  }stStkLoad;
  
  typedef union
  {
   struct
   {
    unsigned long u24CURRENT : 24;
    unsigned long : 8;
   }bits;
  
   unsigned long u32Register;
  
  }stStkVal;
  
  typedef union
  {
   struct
   {
    unsigned long u24TENMS : 24;
    unsigned long : 6;
    unsigned long u1SKEW : 1;
    unsigned long u1NOREF : 1;
   }bits;
  
   unsigned long u32Register;
  
  }stStkCalib;
  
  //=========================================================================================
  // Macros
  //=========================================================================================
  #define SYS_TICK_BASE_REG (0xE000E010UL)
  
  #define pSTK_CTRL   ((volatile stStkCtrl* const) (SYS_TICK_BASE_REG + 0x00))
  #define pSTK_LOAD   ((volatile stStkLoad* const) (SYS_TICK_BASE_REG + 0x04))
  #define pSTK_VAL    ((volatile stStkVal* const)  (SYS_TICK_BASE_REG + 0x08))
  #define pSTK_CALIB  ((volatile stStkCalib* const)(SYS_TICK_BASE_REG + 0x0C))
  
  #define CPU_FREQ_MHZ         396U
  #define OS_SYS_TICK_MS(x)    ((unsigned long)(CPU_FREQ_MHZ * x * 1000UL) - 1UL)
  #define OS_SYS_TICK_US(x)    ((unsigned long)(CPU_FREQ_MHZ * x) - 1UL)
  
  #define SYS_TICK_CLKSRC_AHB          1U
  #define SYS_TICK_CLKSRC_AHB_DIV_8    0U
  #define SYS_TICK_ENABLE_INT          1U
  #define SYS_TICK_ENABLE_TIMER        1U
  
  //=========================================================================================
  // Prototypes
  //=========================================================================================
  void mcal_timer_delay(void);
  void mcal_timer_SysTick_Init(void);
  void mcal_timer_SysTick_Start(void);

  #if defined(__cplusplus)
  }
  #endif

#endif /* TIMER_2023_07_01_H */
