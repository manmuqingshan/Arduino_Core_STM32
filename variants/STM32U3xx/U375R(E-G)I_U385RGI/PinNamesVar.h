/* Alternate pin name */
PA_1_ALT1  = PA_1  | ALT1,
PA_2_ALT1  = PA_2  | ALT1,
PA_3_ALT1  = PA_3  | ALT1,
PA_4_ALT1  = PA_4  | ALT1,
PA_5_ALT1  = PA_5  | ALT1,
PA_6_ALT1  = PA_6  | ALT1,
PA_7_ALT1  = PA_7  | ALT1,
PA_7_ALT2  = PA_7  | ALT2,
PA_9_ALT1  = PA_9  | ALT1,
PA_10_ALT1 = PA_10 | ALT1,
PA_15_ALT1 = PA_15 | ALT1,
PB_0_ALT1  = PB_0  | ALT1,
PB_1_ALT1  = PB_1  | ALT1,
PB_3_ALT1  = PB_3  | ALT1,
PB_4_ALT1  = PB_4  | ALT1,
PB_5_ALT1  = PB_5  | ALT1,
PB_6_ALT1  = PB_6  | ALT1,
PB_7_ALT1  = PB_7  | ALT1,
PB_8_ALT1  = PB_8  | ALT1,
PB_9_ALT1  = PB_9  | ALT1,
PB_10_ALT1 = PB_10 | ALT1,
PB_12_ALT1 = PB_12 | ALT1,
PB_13_ALT1 = PB_13 | ALT1,
PB_14_ALT1 = PB_14 | ALT1,
PB_15_ALT1 = PB_15 | ALT1,
PC_1_ALT1  = PC_1  | ALT1,
PC_4_ALT1  = PC_4  | ALT1,
PC_5_ALT1  = PC_5  | ALT1,
PC_10_ALT1 = PC_10 | ALT1,
PC_11_ALT1 = PC_11 | ALT1,
PH_3_ALT1  = PH_3  | ALT1,

/* SYS_WKUP */
#ifdef PWR_WAKEUP_LINE1
  SYS_WKUP1 = PA_0,
#endif
#ifdef PWR_WAKEUP_LINE1
  SYS_WKUP1_1 = PB_2,
#endif
#ifdef PWR_WAKEUP_LINE2
  SYS_WKUP2 = PC_13,
#endif
#ifdef PWR_WAKEUP_LINE2
  SYS_WKUP2_1 = PA_4,
#endif
#ifdef PWR_WAKEUP_LINE3
  SYS_WKUP3 = PB_6,
#endif
#ifdef PWR_WAKEUP_LINE3
  SYS_WKUP3_1 = PA_1,
#endif
#ifdef PWR_WAKEUP_LINE4
  SYS_WKUP4 = PB_7,
#endif
#ifdef PWR_WAKEUP_LINE4
  SYS_WKUP4_1 = PA_2,
#endif
#ifdef PWR_WAKEUP_LINE4
  SYS_WKUP4_2 = PB_1,
#endif
#ifdef PWR_WAKEUP_LINE5
  SYS_WKUP5 = PB_8,
#endif
#ifdef PWR_WAKEUP_LINE5
  SYS_WKUP5_1 = PA_3,
#endif
#ifdef PWR_WAKEUP_LINE5
  SYS_WKUP5_2 = PC_5,
#endif
#ifdef PWR_WAKEUP_LINE6
  SYS_WKUP6 = PB_5,
#endif
#ifdef PWR_WAKEUP_LINE6
  SYS_WKUP6_1 = PA_5,
#endif
#ifdef PWR_WAKEUP_LINE7
  SYS_WKUP7 = PB_15,
#endif
#ifdef PWR_WAKEUP_LINE7
  SYS_WKUP7_1 = PA_6,
#endif
#ifdef PWR_WAKEUP_LINE8
  SYS_WKUP8 = PB_10,
#endif
#ifdef PWR_WAKEUP_LINE8
  SYS_WKUP8_1 = PA_7,
#endif

/* USB */
#ifdef USBCON
  USB_DM  = PA_11,
  USB_DP  = PA_12,
  #ifdef USB_NOE_PA_13
    USB_NOE = PA_13,
  #endif
  #ifdef USB_NOE_PC_9
    USB_NOE = PC_9,
  #endif
  #ifdef USB_SOF_PA_8
    USB_SOF = PA_8,
  #endif
  #ifdef USB_SOF_PA_14
    USB_SOF = PA_14,
  #endif
#endif
