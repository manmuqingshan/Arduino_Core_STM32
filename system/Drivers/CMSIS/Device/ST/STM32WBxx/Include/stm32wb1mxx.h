/**
  ******************************************************************************
  * @file    stm32wb1mxx.h
  * @author  MCD Application Team
  * @brief   CMSIS Cortex Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for stm32wb1mxx devices.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral's registers hardware
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019-2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS_Device
  * @{
  */

/** @addtogroup stm32wb1mxx
  * @{
  */

#ifndef __STM32WB1Mxx_H
#define __STM32WB1Mxx_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */
/**
  * @brief Configuration of the Cortex-M4 Processor and Core Peripherals
  */
#define __CM4_REV                 1U /*!< Core Revision r0p1                            */
#define __MPU_PRESENT             1U /*!< M4 provides an MPU                            */
#define __VTOR_PRESENT            1U /*!< Vector Table Register supported               */
#define __NVIC_PRIO_BITS          4U /*!< STM32WBxx uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0U /*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1U /*!< FPU present                                   */
/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
  * @brief stm32wb1mxx Interrupt Number Definition, according to the selected device
  *        in @ref Library_configuration_section
  */
/*!< Interrupt Number Definition for M4 */
typedef enum
{
  /******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
  NonMaskableInt_IRQn                 = -14,    /*!< Non Maskable Interrupt                                            */
  HardFault_IRQn                      = -13,    /*!< Cortex-M4 Hard Fault Interrupt                                    */
  MemoryManagement_IRQn               = -12,    /*!< Cortex-M4 Memory Management Interrupt                             */
  BusFault_IRQn                       = -11,    /*!< Cortex-M4 Bus Fault Interrupt                                     */
  UsageFault_IRQn                     = -10,    /*!< Cortex-M4 Usage Fault Interrupt                                   */
  SVCall_IRQn                         = -5,     /*!< Cortex-M4 SV Call Interrupt                                       */
  DebugMonitor_IRQn                   = -4,     /*!< Cortex-M4 Debug Monitor Interrupt                                 */
  PendSV_IRQn                         = -2,     /*!< Cortex-M4 Pend SV Interrupt                                       */
  SysTick_IRQn                        = -1,     /*!< Cortex-M4 System Tick Interrupt                                   */

  /*************  STM32WBxx specific Interrupt Numbers on M4 core ************************************************/
  WWDG_IRQn                           = 0,      /*!< Window WatchDog Interrupt                                         */
  PVD_PVM_IRQn                        = 1,      /*!< PVD and PVM detector                                              */
  TAMP_STAMP_LSECSS_IRQn              = 2,      /*!< RTC Tamper and TimeStamp Interrupts and LSECSS Interrupts         */
  RTC_WKUP_IRQn                       = 3,      /*!< RTC Wakeup Interrupt                                              */
  FLASH_IRQn                          = 4,      /*!< FLASH (CFI)  global Interrupt                                     */
  RCC_IRQn                            = 5,      /*!< RCC Interrupt                                                     */
  EXTI0_IRQn                          = 6,      /*!< EXTI Line 0 Interrupt                                             */
  EXTI1_IRQn                          = 7,      /*!< EXTI Line 1 Interrupt                                             */
  EXTI2_IRQn                          = 8,      /*!< EXTI Line 2 Interrupt                                             */
  EXTI3_IRQn                          = 9,      /*!< EXTI Line 3 Interrupt                                             */
  EXTI4_IRQn                          = 10,     /*!< EXTI Line 4 Interrupt                                             */
  DMA1_Channel1_IRQn                  = 11,     /*!< DMA1 Channel 1 Interrupt                                          */
  DMA1_Channel2_IRQn                  = 12,     /*!< DMA1 Channel 2 Interrupt                                          */
  DMA1_Channel3_IRQn                  = 13,     /*!< DMA1 Channel 3 Interrupt                                          */
  DMA1_Channel4_IRQn                  = 14,     /*!< DMA1 Channel 4 Interrupt                                          */
  DMA1_Channel5_IRQn                  = 15,     /*!< DMA1 Channel 5 Interrupt                                          */
  DMA1_Channel6_IRQn                  = 16,     /*!< DMA1 Channel 6 Interrupt                                          */
  DMA1_Channel7_IRQn                  = 17,     /*!< DMA1 Channel 7 Interrupt                                          */
  ADC1_IRQn                           = 18,     /*!< ADC1 Interrupt                                                    */
  C2SEV_PWR_C2H_IRQn                  = 21,     /*!< CPU2 SEV Interrupt                                                */
  COMP_IRQn                           = 22,     /*!< COMP1 Interrupt                                                   */
  EXTI9_5_IRQn                        = 23,     /*!< EXTI Lines [9:5] Interrupt                                        */
  TIM1_BRK_IRQn                       = 24,     /*!< TIM1 Break Interrupt                                              */
  TIM1_UP_IRQn                        = 25,     /*!< TIM1 Update Interrupt                                             */
  TIM1_TRG_COM_IRQn                   = 26,     /*!< TIM1 Trigger and Communication Interrupts                         */
  TIM1_CC_IRQn                        = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                           = 28,     /*!< TIM2 Global Interrupt                                             */
  PKA_IRQn                            = 29,     /*!< PKA Interrupt                                                     */
  I2C1_EV_IRQn                        = 30,     /*!< I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                        = 31,     /*!< I2C1 Error Interrupt                                              */
  SPI1_IRQn                           = 34,     /*!< SPI1 Interrupt                                                    */
  USART1_IRQn                         = 36,     /*!< USART1 Interrupt                                                  */
  LPUART1_IRQn                        = 37,     /*!< LPUART1 Interrupt                                                 */
  TSC_IRQn                            = 39,     /*!< TSC Interrupt                                                     */
  EXTI15_10_IRQn                      = 40,     /*!< EXTI Lines1[15:10 ]Interrupts                                     */
  RTC_Alarm_IRQn                      = 41,     /*!< RTC Alarms (A and B) Interrupt                                    */
  PWR_SOTF_BLEACT_RFPHASE_IRQn        = 43,     /*!< PWR switching on the fly interrupt
                                                     PWR end of BLE activity interrupt
                                                     PWR end of critical radio phase interrupt                         */
  IPCC_C1_RX_IRQn                     = 44,     /*!< IPCC RX Occupied Interrupt                                        */
  IPCC_C1_TX_IRQn                     = 45,     /*!< IPCC TX Free Interrupt                                            */
  HSEM_IRQn                           = 46,     /*!< HSEM Interrupt                                                    */
  LPTIM1_IRQn                         = 47,     /*!< LPTIM1 Interrupt                                                  */
  LPTIM2_IRQn                         = 48,     /*!< LPTIM2 Interrupt                                                  */
  AES2_IRQn                           = 52,     /*!< AES2 Interrupt                                                    */
  RNG_IRQn                            = 53,     /*!< RNG Interrupt                                                     */
  FPU_IRQn                            = 54,     /*!< FPU Interrupt                                                     */
  DMAMUX1_OVR_IRQn                    = 62      /*!< DMAMUX1 overrun Interrupt                                         */
} IRQn_Type;
/**
  * @}
  */

#include "core_cm4.h"                /* Cortex-M4 processor and core peripherals */
#include "system_stm32wbxx.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Analog to Digital Converter
  */
typedef struct
{
  __IO uint32_t ISR;          /*!< ADC interrupt and status register,             Address offset: 0x00 */
  __IO uint32_t IER;          /*!< ADC interrupt enable register,                 Address offset: 0x04 */
  __IO uint32_t CR;           /*!< ADC control register,                          Address offset: 0x08 */
  __IO uint32_t CFGR1;        /*!< ADC configuration register 1,                  Address offset: 0x0C */
  __IO uint32_t CFGR2;        /*!< ADC configuration register 2,                  Address offset: 0x10 */
  __IO uint32_t SMPR;         /*!< ADC sampling time register,                    Address offset: 0x14 */
       uint32_t RESERVED1;    /*!< Reserved,                                                      0x18 */
       uint32_t RESERVED2;    /*!< Reserved,                                                      0x1C */
  __IO uint32_t TR;           /*!< ADC analog watchdog 1 threshold register,      Address offset: 0x20 */
  __IO uint32_t RESERVED3;    /*!< Reserved,                                                      0x24 */
  __IO uint32_t CHSELR;       /*!< ADC group regular sequencer register,          Address offset: 0x28 */
  __IO uint32_t RESERVED4;    /*!< Reserved,                                                      0x2C */
       uint32_t RESERVED5[4]; /*!< Reserved,                                               0x30 - 0x3C */
  __IO uint32_t DR;           /*!< ADC group regular data register,               Address offset: 0x40 */
       uint32_t RESERVED6[23];/*!< Reserved,                                               0x44 - 0x9C */
  __IO uint32_t RESERVED7;    /*!< Reserved,                                                      0xA0 */
  __IO uint32_t RESERVED8;    /*!< Reserved,                                                      0xA4 */
       uint32_t RESERVED9[3]; /*!< Reserved,                                               0xA8 - 0xB0 */
  __IO uint32_t CALFACT;      /*!< ADC Calibration factor register,               Address offset: 0xB4 */
} ADC_TypeDef;

/* Legacy registers naming */
#define TR1     TR


typedef struct
{
  uint32_t      RESERVED1;    /*!< Reserved,                                      Address offset: ADC1 base address + 0x300 */
  uint32_t      RESERVED2;    /*!< Reserved,                                      Address offset: ADC1 base address + 0x304 */
  __IO uint32_t CCR;          /*!< ADC common configuration register,             Address offset: ADC1 base address + 0x308 */
  uint32_t      RESERVED3;    /*!< Reserved,                                      Address offset: ADC1 base address + 0x30C */
} ADC_Common_TypeDef;

/**
  * @brief Comparator
  */
typedef struct
{
  __IO uint32_t CSR;         /*!< COMP control and status register,               Address offset: 0x00 */
} COMP_TypeDef;

/**
  * @brief CRC calculation unit
  */
typedef struct
{
  __IO uint32_t DR;          /*!< CRC Data register,                           Address offset: 0x00 */
  __IO uint32_t IDR;         /*!< CRC Independent data register,               Address offset: 0x04 */
  __IO uint32_t CR;          /*!< CRC Control register,                        Address offset: 0x08 */
       uint32_t RESERVED2;   /*!< Reserved,                                                    0x0C */
  __IO uint32_t INIT;        /*!< Initial CRC value register,                  Address offset: 0x10 */
  __IO uint32_t POL;         /*!< CRC polynomial register,                     Address offset: 0x14 */
} CRC_TypeDef;

/**
  * @brief Debug MCU
  */
typedef struct
{
  __IO uint32_t IDCODE;      /*!< MCU device ID code,                          Address offset: 0x00 */
  __IO uint32_t CR;          /*!< Debug MCU configuration register,            Address offset: 0x04 */
  uint32_t RESERVED1[13];    /*!< Reserved,                                               0x08-0x38 */
  __IO uint32_t APB1FZR1;    /*!< Debug MCU CPU1 APB1 freeze register,         Address offset: 0x3C */
  __IO uint32_t C2APB1FZR1;  /*!< Debug MCU CPU2 APB1 freeze register,         Address offset: 0x40 */
  __IO uint32_t APB1FZR2;    /*!< Debug MCU CPU1 APB1 freeze register,         Address offset: 0x44 */
  __IO uint32_t C2APB1FZR2;  /*!< Debug MCU CPU2 APB1 freeze register,         Address offset: 0x48 */
  __IO uint32_t APB2FZR;     /*!< Debug MCU CPU1 APB2 freeze register,         Address offset: 0x4C */
  __IO uint32_t C2APB2FZR;   /*!< Debug MCU CPU2 APB2 freeze register,         Address offset: 0x50 */
} DBGMCU_TypeDef;

/**
  * @brief DMA Controller
  */
typedef struct
{
  __IO uint32_t CCR;         /*!< DMA channel x configuration register        0x00 */
  __IO uint32_t CNDTR;       /*!< DMA channel x number of data register       0x04 */
  __IO uint32_t CPAR;        /*!< DMA channel x peripheral address register   0x08 */
  __IO uint32_t CMAR;        /*!< DMA channel x memory address register       0x0C */
  uint32_t RESERVED;         /*!< Reserved,                                   0x10 */
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;         /*!< DMA interrupt status register,                 Address offset: 0x00 */
  __IO uint32_t IFCR;        /*!< DMA interrupt flag clear register,             Address offset: 0x04 */
} DMA_TypeDef;

/**
  * @brief DMA Multiplexer
  */
typedef struct
{
  __IO uint32_t   CCR;       /*!< DMA Multiplexer Channel x Control Register    Address offset: 0x0004 * (channel x) */
} DMAMUX_Channel_TypeDef;

typedef struct
{
  __IO uint32_t   CSR;       /*!< DMA Channel Status Register                    Address offset: 0x0080   */
  __IO uint32_t   CFR;       /*!< DMA Channel Clear Flag Register                Address offset: 0x0084   */
} DMAMUX_ChannelStatus_TypeDef;

typedef struct
{
  __IO uint32_t   RGCR;        /*!< DMA Request Generator x Control Register     Address offset: 0x0100 + 0x0004 * (Req Gen x) */
} DMAMUX_RequestGen_TypeDef;

typedef struct
{
  __IO uint32_t   RGSR;        /*!< DMA Request Generator Status Register        Address offset: 0x0140   */
  __IO uint32_t   RGCFR;       /*!< DMA Request Generator Clear Flag Register    Address offset: 0x0144   */
} DMAMUX_RequestGenStatus_TypeDef;

/**
  * @brief FLASH Registers
  */
typedef struct
{
  __IO uint32_t ACR;           /*!< FLASH Access control register,                      Address offset: 0x00      */
  __IO uint32_t RESERVED;      /*!< Reserved,                                           Address offset: 0x04      */
  __IO uint32_t KEYR;          /*!< FLASH Key register,                                 Address offset: 0x08      */
  __IO uint32_t OPTKEYR;       /*!< FLASH Option Key register,                          Address offset: 0x0C      */
  __IO uint32_t SR;            /*!< FLASH Status register,                              Address offset: 0x10      */
  __IO uint32_t CR;            /*!< FLASH Control register,                             Address offset: 0x14      */
  __IO uint32_t ECCR;          /*!< FLASH ECC register,                                 Address offset: 0x18      */
  uint32_t RESERVED1;          /*!< Reserved,                                           Address offset: 0x1C      */
  __IO uint32_t OPTR;          /*!< FLASH Option register,                              Address offset: 0x20      */
  __IO uint32_t PCROP1ASR;     /*!< FLASH Bank 1 PCROP area A Start address register,   Address offset: 0x24      */
  __IO uint32_t PCROP1AER;     /*!< FLASH Bank 1 PCROP area A End address register,     Address offset: 0x28      */
  __IO uint32_t WRP1AR;        /*!< FLASH Bank 1 WRP area A address register,           Address offset: 0x2C      */
  __IO uint32_t WRP1BR;        /*!< FLASH Bank 1 WRP area B address register,           Address offset: 0x30      */
  __IO uint32_t PCROP1BSR;     /*!< FLASH Bank 1 PCROP area B Start address register,   Address offset: 0x34      */
  __IO uint32_t PCROP1BER;     /*!< FLASH Bank 1 PCROP area B End address register,     Address offset: 0x38      */
  __IO uint32_t IPCCBR;        /*!< FLASH IPCC data buffer address,                     Address offset: 0x3C      */
  uint32_t RESERVED2[7];       /*!< Reserved,                                           Address offset: 0x40-0x58 */
  __IO uint32_t C2ACR;         /*!< FLASH Core MO+ Access Control Register ,            Address offset: 0x5C      */
  __IO uint32_t C2SR;          /*!< FLASH Core MO+ Status Register,                     Address offset: 0x60      */
  __IO uint32_t C2CR;          /*!< FLASH Core MO+ Control register,                    Address offset: 0x64      */
  uint32_t RESERVED3[6];       /*!< Reserved,                                           Address offset: 0x68-0x7C */
  __IO uint32_t SFR;           /*!< FLASH secure start address,                         Address offset: 0x80      */
  __IO uint32_t SRRVR;         /*!< FlASH secure SRAM2 start addr and CPU2 reset vector Address offset: 0x84      */
} FLASH_TypeDef;

/**
  * @brief General Purpose I/O
  */
typedef struct
{
  __IO uint32_t MODER;       /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;      /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;     /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;       /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;         /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;         /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;        /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
  __IO uint32_t LCKR;        /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];      /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
  __IO uint32_t BRR;         /*!< GPIO Bit Reset register,               Address offset: 0x28      */
} GPIO_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< I2C Control register 1,            Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< I2C Control register 2,            Address offset: 0x04 */
  __IO uint32_t OAR1;        /*!< I2C Own address 1 register,        Address offset: 0x08 */
  __IO uint32_t OAR2;        /*!< I2C Own address 2 register,        Address offset: 0x0C */
  __IO uint32_t TIMINGR;     /*!< I2C Timing register,               Address offset: 0x10 */
  __IO uint32_t TIMEOUTR;    /*!< I2C Timeout register,              Address offset: 0x14 */
  __IO uint32_t ISR;         /*!< I2C Interrupt and status register, Address offset: 0x18 */
  __IO uint32_t ICR;         /*!< I2C Interrupt clear register,      Address offset: 0x1C */
  __IO uint32_t PECR;        /*!< I2C PEC register,                  Address offset: 0x20 */
  __IO uint32_t RXDR;        /*!< I2C Receive data register,         Address offset: 0x24 */
  __IO uint32_t TXDR;        /*!< I2C Transmit data register,        Address offset: 0x28 */
} I2C_TypeDef;

/**
  * @brief Independent WATCHDOG
  */
typedef struct
{
  __IO uint32_t KR;          /*!< IWDG Key register,       Address offset: 0x00 */
  __IO uint32_t PR;          /*!< IWDG Prescaler register, Address offset: 0x04 */
  __IO uint32_t RLR;         /*!< IWDG Reload register,    Address offset: 0x08 */
  __IO uint32_t SR;          /*!< IWDG Status register,    Address offset: 0x0C */
  __IO uint32_t WINR;        /*!< IWDG Window register,    Address offset: 0x10 */
} IWDG_TypeDef;

/**
  * @brief LPTIMER
  */
typedef struct
{
  __IO uint32_t ISR;         /*!< LPTIM Interrupt and Status register,                Address offset: 0x00 */
  __IO uint32_t ICR;         /*!< LPTIM Interrupt Clear register,                     Address offset: 0x04 */
  __IO uint32_t IER;         /*!< LPTIM Interrupt Enable register,                    Address offset: 0x08 */
  __IO uint32_t CFGR;        /*!< LPTIM Configuration register,                       Address offset: 0x0C */
  __IO uint32_t CR;          /*!< LPTIM Control register,                             Address offset: 0x10 */
  __IO uint32_t CMP;         /*!< LPTIM Compare register,                             Address offset: 0x14 */
  __IO uint32_t ARR;         /*!< LPTIM Autoreload register,                          Address offset: 0x18 */
  __IO uint32_t CNT;         /*!< LPTIM Counter register,                             Address offset: 0x1C */
  __IO uint32_t OR;          /*!< LPTIM Option register,                              Address offset: 0x20 */
} LPTIM_TypeDef;

/**
  * @brief Power Control
  */
typedef struct
{
  __IO uint32_t CR1;          /*!< PWR Power Control Register 1,                     Address offset: 0x00 */
  __IO uint32_t CR2;          /*!< PWR Power Control Register 2,                     Address offset: 0x04 */
  __IO uint32_t CR3;          /*!< PWR Power Control Register 3,                     Address offset: 0x08 */
  __IO uint32_t CR4;          /*!< PWR Power Control Register 4,                     Address offset: 0x0C */
  __IO uint32_t SR1;          /*!< PWR Power Status Register 1,                      Address offset: 0x10 */
  __IO uint32_t SR2;          /*!< PWR Power Status Register 2,                      Address offset: 0x14 */
  __IO uint32_t SCR;          /*!< PWR Power Status Reset Register,                  Address offset: 0x18 */
  __IO uint32_t CR5;          /*!< PWR Power Control Register 5,                     Address offset: 0x1C */
  __IO uint32_t PUCRA;        /*!< PWR Pull-Up Control Register of port A,           Address offset: 0x20 */
  __IO uint32_t PDCRA;        /*!< PWR Pull-Down Control Register of port A,         Address offset: 0x24 */
  __IO uint32_t PUCRB;        /*!< PWR Pull-Up Control Register of port B,           Address offset: 0x28 */
  __IO uint32_t PDCRB;        /*!< PWR Pull-Down Control Register of port B,         Address offset: 0x2C */
  __IO uint32_t PUCRC;        /*!< PWR Pull-Up Control Register of port C,           Address offset: 0x30 */
  __IO uint32_t PDCRC;        /*!< PWR Pull-Down Control Register of port C,         Address offset: 0x34 */
       uint32_t RESERVED2[2]; /*!< Reserved,                                         Address offset: 0x38-0x3C */
  __IO uint32_t PUCRE;        /*!< PWR Pull-Up Control Register of port E,           Address offset: 0x40 */
  __IO uint32_t PDCRE;        /*!< PWR Pull-Down Control Register of port E,         Address offset: 0x44 */
       uint32_t RESERVED0[4]; /*!< Reserved,                                         Address offset: 0x48-0x54 */
  __IO uint32_t PUCRH;        /*!< PWR Pull-Up Control Register of port H,           Address offset: 0x58 */
  __IO uint32_t PDCRH;        /*!< PWR Pull-Down Control Register of port H,         Address offset: 0x5C */
       uint32_t RESERVED1[8]; /*!< Reserved,                                         Address offset: 0x60-0x7C */
  __IO uint32_t C2CR1;        /*!< PWR Power Control Register 1 for CPU2,            Address offset: 0x80 */
  __IO uint32_t C2CR3;        /*!< PWR Power Control Register 3 for CPU2,            Address offset: 0x84 */
  __IO uint32_t EXTSCR;       /*!< PWR Power Status Reset Register for CPU2,         Address offset: 0x88 */
} PWR_TypeDef;

/**
  * @brief Reset and Clock Control
  */
typedef struct
{
  __IO uint32_t CR;            /*!< RCC clock  Control Register,                                                    Address offset: 0x00 */
  __IO uint32_t ICSCR;         /*!< RCC Internal Clock Sources Calibration Register,                                Address offset: 0x04 */
  __IO uint32_t CFGR;          /*!< RCC Clocks Configuration Register,                                              Address offset: 0x08 */
  __IO uint32_t PLLCFGR;       /*!< RCC System PLL configuration Register,                                          Address offset: 0x0C */
       uint32_t RESERVED0[2];  /*!< Reserved,                                                                       Address offset: 0x10-0x14 */
  __IO uint32_t CIER;          /*!< RCC Clock Interrupt Enable Register,                                            Address offset: 0x18 */
  __IO uint32_t CIFR;          /*!< RCC Clock Interrupt Flag Register,                                              Address offset: 0x1C */
  __IO uint32_t CICR;          /*!< RCC Clock Interrupt Clear Register,                                             Address offset: 0x20 */
  __IO uint32_t SMPSCR;        /*!< RCC SMPS step-down converter control register,                                  Address offset: 0x24 */
  __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                                             Address offset: 0x28 */
  __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                                             Address offset: 0x2C */
  __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 & AHB4 peripheral reset register,                                      Address offset: 0x30 */
       uint32_t RESERVED1;     /*!< Reserved,                                                                       Address offset: 0x34 */
  __IO uint32_t APB1RSTR1;     /*!< RCC APB1 peripheral reset register 1,                                           Address offset: 0x38 */
  __IO uint32_t APB1RSTR2;     /*!< RCC APB1 peripheral reset register 2,                                           Address offset: 0x3C */
  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                                             Address offset: 0x40 */
  __IO uint32_t APB3RSTR;      /*!< RCC APB3 peripheral reset register,                                             Address offset: 0x44 */
  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clocks enable register,                                     Address offset: 0x48 */
  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clocks enable register,                                     Address offset: 0x4C */
  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 & AHB4 peripheral clocks enable register,                              Address offset: 0x50 */
       uint32_t RESERVED2;     /*!< Reserved,                                                                       Address offset: 0x54 */
  __IO uint32_t APB1ENR1;      /*!< RCC APB1 peripheral clocks enable register 1,                                   Address offset: 0x58 */
  __IO uint32_t APB1ENR2;      /*!< RCC APB1 peripheral clocks enable register 2,                                   Address offset: 0x5C */
  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clocks enable register,                                     Address offset: 0x60 */
       uint32_t RESERVED3;     /*!< Reserved,                                                                       Address offset: 0x64 */
  __IO uint32_t AHB1SMENR;     /*!< RCC AHB1 peripheral clocks enable in sleep and stop modes register,             Address offset: 0x68 */
  __IO uint32_t AHB2SMENR;     /*!< RCC AHB2 peripheral clocks enable in sleep and stop modes register,             Address offset: 0x6C */
  __IO uint32_t AHB3SMENR;     /*!< RCC AHB3 & AHB4 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x70 */
       uint32_t RESERVED4;     /*!< Reserved,                                                                       Address offset: 0x74 */
  __IO uint32_t APB1SMENR1;    /*!< RCC APB1 peripheral clocks enable in sleep mode and stop modes register 1,      Address offset: 0x78 */
  __IO uint32_t APB1SMENR2;    /*!< RCC APB1 peripheral clocks enable in sleep mode and stop modes register 2,      Address offset: 0x7C */
  __IO uint32_t APB2SMENR;     /*!< RCC APB2 peripheral clocks enable in sleep mode and stop modes register,        Address offset: 0x80 */
       uint32_t RESERVED5;     /*!< Reserved,                                                                       Address offset: 0x84 */
  __IO uint32_t CCIPR;         /*!< RCC Peripherals Clock Configuration Independent Register,                       Address offset: 0x88 */
       uint32_t RESERVED6;     /*!< Reserved,                                                                       Address offset: 0x8C */
  __IO uint32_t BDCR;          /*!< RCC Backup Domain Control Register,                                             Address offset: 0x90 */
  __IO uint32_t CSR;           /*!< RCC Control and Status Register,                                                Address offset: 0x94 */
  __IO uint32_t CRRCR;         /*!< RCC Clock Recovery RC Register,                                                 Address offset: 0x98 */
  __IO uint32_t HSECR;         /*!< RCC HSE Clock Register,                                                         Address offset: 0x9C */
       uint32_t RESERVED7[26]; /*!< Reserved,                                                                       Address offset: 0xA0-0x104 */
  __IO uint32_t EXTCFGR;       /*!< RCC Extended Clock Recovery Register,                                           Address offset: 0x108 */
       uint32_t RESERVED8[15]; /*!< Reserved,                                                                       Address offset: 0x10C-0x144 */
  __IO uint32_t C2AHB1ENR;     /*!< RRCC AHB1 peripheral CPU2 clocks enable register,                               Address offset: 0x148 */
  __IO uint32_t C2AHB2ENR;     /*!< RCC AHB2 peripheral CPU2 clocks enable register,                                Address offset: 0x14C */
  __IO uint32_t C2AHB3ENR;     /*!< RCC AHB3 & AHB4 peripheral CPU2 clocks enable register,,                        Address offset: 0x150 */
       uint32_t RESERVED9;     /*!< Reserved,                                                                       Address offset: 0x154 */
  __IO uint32_t C2APB1ENR1;    /*!< RCC APB1 peripheral CPU2 clocks enable register 1,                              Address offset: 0x158 */
  __IO uint32_t C2APB1ENR2;    /*!< RCC APB1 peripheral CPU2 clocks enable register 2,                              Address offset: 0x15C */
  __IO uint32_t C2APB2ENR;     /*!< RCC APB2 peripheral CPU2 clocks enable register 1,                              Address offset: 0x160 */
  __IO uint32_t C2APB3ENR;     /*!< RCC APB3 peripheral CPU2 clocks enable register 1,                              Address offset: 0x164 */
  __IO uint32_t C2AHB1SMENR;   /*!< RCC AHB1 peripheral CPU2 clocks enable in sleep and stop modes register,        Address offset: 0x168 */
  __IO uint32_t C2AHB2SMENR;   /*!< RCC AHB2 peripheral CPU2 clocks enable in sleep and stop modes register,        Address offset: 0x16C */
  __IO uint32_t C2AHB3SMENR;   /*!< RCC AHB3 & AHB4 peripheral CPU2 clocks enable in sleep and stop modes register, Address offset: 0x170 */
       uint32_t RESERVED10;    /*!< Reserved,                                                                                             */
  __IO uint32_t C2APB1SMENR1;  /*!< RCC APB1 peripheral CPU2 clocks enable in sleep mode and stop modes register 1, Address offset: 0x178 */
  __IO uint32_t C2APB1SMENR2;  /*!< RCC APB1 peripheral CPU2 clocks enable in sleep mode and stop modes register 2, Address offset: 0x17C */
  __IO uint32_t C2APB2SMENR;   /*!< RCC APB2 peripheral CPU2 clocks enable in sleep mode and stop modes register,   Address offset: 0x180 */
  __IO uint32_t C2APB3SMENR;   /*!< RCC APB3 peripheral CPU2 clocks enable in sleep mode and stop modes register,   Address offset: 0x184 */
} RCC_TypeDef;



/**
  * @brief Real-Time Clock
  */
typedef struct
{
  __IO uint32_t TR;         /*!< RTC time register,                                         Address offset: 0x00 */
  __IO uint32_t DR;         /*!< RTC date register,                                         Address offset: 0x04 */
  __IO uint32_t CR;         /*!< RTC control register,                                      Address offset: 0x08 */
  __IO uint32_t ISR;        /*!< RTC initialization and status register,                    Address offset: 0x0C */
  __IO uint32_t PRER;       /*!< RTC prescaler register,                                    Address offset: 0x10 */
  __IO uint32_t WUTR;       /*!< RTC wakeup timer register,                                 Address offset: 0x14 */
       uint32_t RESERVED;   /*!< Reserved,                                                  Address offset: 0x18 */
  __IO uint32_t ALRMAR;     /*!< RTC alarm A register,                                      Address offset: 0x1C */
  __IO uint32_t ALRMBR;     /*!< RTC alarm B register,                                      Address offset: 0x20 */
  __IO uint32_t WPR;        /*!< RTC write protection register,                             Address offset: 0x24 */
  __IO uint32_t SSR;        /*!< RTC sub second register,                                   Address offset: 0x28 */
  __IO uint32_t SHIFTR;     /*!< RTC shift control register,                                Address offset: 0x2C */
  __IO uint32_t TSTR;       /*!< RTC time stamp time register,                              Address offset: 0x30 */
  __IO uint32_t TSDR;       /*!< RTC time stamp date register,                              Address offset: 0x34 */
  __IO uint32_t TSSSR;      /*!< RTC time-stamp sub second register,                        Address offset: 0x38 */
  __IO uint32_t CALR;       /*!< RTC calibration register,                                  Address offset: 0x3C */
  __IO uint32_t TAMPCR;     /*!< RTC tamper configuration register,                         Address offset: 0x40 */
  __IO uint32_t ALRMASSR;   /*!< RTC alarm A sub second register,                           Address offset: 0x44 */
  __IO uint32_t ALRMBSSR;   /*!< RTC alarm B sub second register,                           Address offset: 0x48 */
  __IO uint32_t OR;         /*!< RTC option register,                                       Address offset  0x4C */
  __IO uint32_t BKP0R;      /*!< RTC backup register 0,                                     Address offset: 0x50 */
  __IO uint32_t BKP1R;      /*!< RTC backup register 1,                                     Address offset: 0x54 */
  __IO uint32_t BKP2R;      /*!< RTC backup register 2,                                     Address offset: 0x58 */
  __IO uint32_t BKP3R;      /*!< RTC backup register 3,                                     Address offset: 0x5C */
  __IO uint32_t BKP4R;      /*!< RTC backup register 4,                                     Address offset: 0x60 */
  __IO uint32_t BKP5R;      /*!< RTC backup register 5,                                     Address offset: 0x64 */
  __IO uint32_t BKP6R;      /*!< RTC backup register 6,                                     Address offset: 0x68 */
  __IO uint32_t BKP7R;      /*!< RTC backup register 7,                                     Address offset: 0x6C */
  __IO uint32_t BKP8R;      /*!< RTC backup register 8,                                     Address offset: 0x70 */
  __IO uint32_t BKP9R;      /*!< RTC backup register 9,                                     Address offset: 0x74 */
  __IO uint32_t BKP10R;     /*!< RTC backup register 10,                                    Address offset: 0x78 */
  __IO uint32_t BKP11R;     /*!< RTC backup register 11,                                    Address offset: 0x7C */
  __IO uint32_t BKP12R;     /*!< RTC backup register 12,                                    Address offset: 0x80 */
  __IO uint32_t BKP13R;     /*!< RTC backup register 13,                                    Address offset: 0x84 */
  __IO uint32_t BKP14R;     /*!< RTC backup register 14,                                    Address offset: 0x88 */
  __IO uint32_t BKP15R;     /*!< RTC backup register 15,                                    Address offset: 0x8C */
  __IO uint32_t BKP16R;     /*!< RTC backup register 16,                                    Address offset: 0x90 */
  __IO uint32_t BKP17R;     /*!< RTC backup register 17,                                    Address offset: 0x94 */
  __IO uint32_t BKP18R;     /*!< RTC backup register 18,                                    Address offset: 0x98 */
  __IO uint32_t BKP19R;     /*!< RTC backup register 19,                                    Address offset: 0x9C */
} RTC_TypeDef;




/**
  * @brief Serial Peripheral Interface
  */
typedef struct
{
  __IO uint32_t CR1;      /*!< SPI Control register 1,       Address offset: 0x00 */
  __IO uint32_t CR2;      /*!< SPI Control register 2,       Address offset: 0x04 */
  __IO uint32_t SR;       /*!< SPI Status register,          Address offset: 0x08 */
  __IO uint32_t DR;       /*!< SPI data register,            Address offset: 0x0C */
  __IO uint32_t CRCPR;    /*!< SPI CRC polynomial register,  Address offset: 0x10 */
  __IO uint32_t RXCRCR;   /*!< SPI Rx CRC register,          Address offset: 0x14 */
  __IO uint32_t TXCRCR;   /*!< SPI Tx CRC register,          Address offset: 0x18 */
} SPI_TypeDef;

/**
  * @brief System configuration controller
  */
typedef struct
{
  __IO uint32_t MEMRMP;            /*!< SYSCFG memory remap register                                            Address offset: 0x00       */
  __IO uint32_t CFGR1;             /*!< SYSCFG configuration register 1,                                        Address offset: 0x04       */
  __IO uint32_t EXTICR[4];         /*!< SYSCFG external interrupt configuration registers,                      Address offset: 0x08-0x14  */
  __IO uint32_t SCSR;              /*!< SYSCFG SRAM2 control and status register,                               Address offset: 0x18       */
  __IO uint32_t CFGR2;             /*!< SYSCFG configuration register 2,                                        Address offset: 0x1C       */
  __IO uint32_t SWPR1;             /*!< SYSCFG SRAM2 write protection register part 1,                          Address offset: 0x20       */
  __IO uint32_t SKR;               /*!< SYSCFG SRAM2 key register,                                              Address offset: 0x24       */
  __IO uint32_t SWPR2;             /*!< SYSCFG write protection register part 2,                                Address offset: 0x28       */
       uint32_t RESERVED1[53];     /*!< Reserved,                                                               Address offset: 0x2C-0xFC  */
  __IO uint32_t IMR1;              /*!< SYSCFG CPU1 (CORTEX M4) interrupt masks control-status register part 1, Address offset: 0x100      */
  __IO uint32_t IMR2;              /*!< SYSCFG CPU1 (CORTEX M4) interrupt masks control-status register part 2, Address offset: 0x104      */
  __IO uint32_t C2IMR1;            /*!< SYSCFG CPU2 (CORTEX M0) interrupt masks control-status register part 1, Address offset: 0x108      */
  __IO uint32_t C2IMR2;            /*!< SYSCFG CPU2 (CORTEX M0) interrupt masks control-status register part 2, Address offset: 0x10C      */
  __IO uint32_t SIPCR;             /*!< SYSCFG secure IP control register,                                      Address offset: 0x110      */

} SYSCFG_TypeDef;

/**
  * @brief TIM
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< TIM control register 1,                   Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TIM control register 2,                   Address offset: 0x04 */
  __IO uint32_t SMCR;        /*!< TIM slave mode control register,          Address offset: 0x08 */
  __IO uint32_t DIER;        /*!< TIM DMA/interrupt enable register,        Address offset: 0x0C */
  __IO uint32_t SR;          /*!< TIM status register,                      Address offset: 0x10 */
  __IO uint32_t EGR;         /*!< TIM event generation register,            Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*!< TIM capture/compare mode register 1,      Address offset: 0x18 */
  __IO uint32_t CCMR2;       /*!< TIM capture/compare mode register 2,      Address offset: 0x1C */
  __IO uint32_t CCER;        /*!< TIM capture/compare enable register,      Address offset: 0x20 */
  __IO uint32_t CNT;         /*!< TIM counter register,                     Address offset: 0x24 */
  __IO uint32_t PSC;         /*!< TIM prescaler register,                   Address offset: 0x28 */
  __IO uint32_t ARR;         /*!< TIM auto-reload register,                 Address offset: 0x2C */
  __IO uint32_t RCR;         /*!< TIM repetition counter register,          Address offset: 0x30 */
  __IO uint32_t CCR1;        /*!< TIM capture/compare register 1,           Address offset: 0x34 */
  __IO uint32_t CCR2;        /*!< TIM capture/compare register 2,           Address offset: 0x38 */
  __IO uint32_t CCR3;        /*!< TIM capture/compare register 3,           Address offset: 0x3C */
  __IO uint32_t CCR4;        /*!< TIM capture/compare register 4,           Address offset: 0x40 */
  __IO uint32_t BDTR;        /*!< TIM break and dead-time register,         Address offset: 0x44 */
  __IO uint32_t DCR;         /*!< TIM DMA control register,                 Address offset: 0x48 */
  __IO uint32_t DMAR;        /*!< TIM DMA address for full transfer,        Address offset: 0x4C */
  __IO uint32_t OR;          /*!< TIM option register                       Address offset: 0x50 */
  __IO uint32_t CCMR3;       /*!< TIM capture/compare mode register 3,      Address offset: 0x54 */
  __IO uint32_t CCR5;        /*!< TIM capture/compare register5,            Address offset: 0x58 */
  __IO uint32_t CCR6;        /*!< TIM capture/compare register6,            Address offset: 0x5C */
  __IO uint32_t AF1;         /*!< TIM Alternate function option register 1, Address offset: 0x60 */
  __IO uint32_t AF2;         /*!< TIM Alternate function option register 2, Address offset: 0x64 */
} TIM_TypeDef;

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< USART Control register 1,                 Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< USART Control register 2,                 Address offset: 0x04 */
  __IO uint32_t CR3;         /*!< USART Control register 3,                 Address offset: 0x08 */
  __IO uint32_t BRR;         /*!< USART Baud rate register,                 Address offset: 0x0C */
  __IO uint32_t GTPR;        /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
  __IO uint32_t RTOR;        /*!< USART Receiver Time Out register,         Address offset: 0x14 */
  __IO uint32_t RQR;         /*!< USART Request register,                   Address offset: 0x18 */
  __IO uint32_t ISR;         /*!< USART Interrupt and status register,      Address offset: 0x1C */
  __IO uint32_t ICR;         /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
  __IO uint32_t RDR;         /*!< USART Receive Data register,              Address offset: 0x24 */
  __IO uint32_t TDR;         /*!< USART Transmit Data register,             Address offset: 0x28 */
  __IO uint32_t PRESC;       /*!< USART Prescaler register,                 Address offset: 0x2C */
} USART_TypeDef;


/**
  * @brief Window WATCHDOG
  */
typedef struct
{
  __IO uint32_t CR;          /*!< WWDG Control register,       Address offset: 0x00 */
  __IO uint32_t CFR;         /*!< WWDG Configuration register, Address offset: 0x04 */
  __IO uint32_t SR;          /*!< WWDG Status register,        Address offset: 0x08 */
} WWDG_TypeDef;


/**
  * @brief AES hardware accelerator
  */
typedef struct
{
  __IO uint32_t CR;          /*!< AES control register,                        Address offset: 0x00 */
  __IO uint32_t SR;          /*!< AES status register,                         Address offset: 0x04 */
  __IO uint32_t DINR;        /*!< AES data input register,                     Address offset: 0x08 */
  __IO uint32_t DOUTR;       /*!< AES data output register,                    Address offset: 0x0C */
  __IO uint32_t KEYR0;       /*!< AES key register 0,                          Address offset: 0x10 */
  __IO uint32_t KEYR1;       /*!< AES key register 1,                          Address offset: 0x14 */
  __IO uint32_t KEYR2;       /*!< AES key register 2,                          Address offset: 0x18 */
  __IO uint32_t KEYR3;       /*!< AES key register 3,                          Address offset: 0x1C */
  __IO uint32_t IVR0;        /*!< AES initialization vector register 0,        Address offset: 0x20 */
  __IO uint32_t IVR1;        /*!< AES initialization vector register 1,        Address offset: 0x24 */
  __IO uint32_t IVR2;        /*!< AES initialization vector register 2,        Address offset: 0x28 */
  __IO uint32_t IVR3;        /*!< AES initialization vector register 3,        Address offset: 0x2C */
  __IO uint32_t KEYR4;       /*!< AES key register 4,                          Address offset: 0x30 */
  __IO uint32_t KEYR5;       /*!< AES key register 5,                          Address offset: 0x34 */
  __IO uint32_t KEYR6;       /*!< AES key register 6,                          Address offset: 0x38 */
  __IO uint32_t KEYR7;       /*!< AES key register 7,                          Address offset: 0x3C */
  __IO uint32_t SUSP0R;      /*!< AES Suspend register 0,                      Address offset: 0x40 */
  __IO uint32_t SUSP1R;      /*!< AES Suspend register 1,                      Address offset: 0x44 */
  __IO uint32_t SUSP2R;      /*!< AES Suspend register 2,                      Address offset: 0x48 */
  __IO uint32_t SUSP3R;      /*!< AES Suspend register 3,                      Address offset: 0x4C */
  __IO uint32_t SUSP4R;      /*!< AES Suspend register 4,                      Address offset: 0x50 */
  __IO uint32_t SUSP5R;      /*!< AES Suspend register 5,                      Address offset: 0x54 */
  __IO uint32_t SUSP6R;      /*!< AES Suspend register 6,                      Address offset: 0x58 */
  __IO uint32_t SUSP7R;      /*!< AES Suspend register 7,                      Address offset: 0x6C */
} AES_TypeDef;

/**
  * @brief RNG
  */
typedef struct
{
  __IO uint32_t CR;  /*!< RNG control register, Address offset: 0x00 */
  __IO uint32_t SR;  /*!< RNG status register,  Address offset: 0x04 */
  __IO uint32_t DR;  /*!< RNG data register,    Address offset: 0x08 */
} RNG_TypeDef;

/**
  * @brief Touch Sensing Controller (TSC)
  */
typedef struct
{
  __IO uint32_t CR;            /*!< TSC control register,                     Address offset: 0x00 */
  __IO uint32_t IER;           /*!< TSC interrupt enable register,            Address offset: 0x04 */
  __IO uint32_t ICR;           /*!< TSC interrupt clear register,             Address offset: 0x08 */
  __IO uint32_t ISR;           /*!< TSC interrupt status register,            Address offset: 0x0C */
  __IO uint32_t IOHCR;         /*!< TSC I/O hysteresis control register,      Address offset: 0x10 */
  uint32_t      RESERVED1;     /*!< Reserved,                                 Address offset: 0x14 */
  __IO uint32_t IOASCR;        /*!< TSC I/O analog switch control register,   Address offset: 0x18 */
  uint32_t      RESERVED2;     /*!< Reserved,                                 Address offset: 0x1C */
  __IO uint32_t IOSCR;         /*!< TSC I/O sampling control register,        Address offset: 0x20 */
  uint32_t      RESERVED3;     /*!< Reserved,                                 Address offset: 0x24 */
  __IO uint32_t IOCCR;         /*!< TSC I/O channel control register,         Address offset: 0x28 */
  uint32_t      RESERVED4;     /*!< Reserved,                                 Address offset: 0x2C */
  __IO uint32_t IOGCSR;        /*!< TSC I/O group control status register,    Address offset: 0x30 */
  __IO uint32_t IOGXCR[7];     /*!< TSC I/O group x counter register,         Address offset: 0x34-4C */
} TSC_TypeDef;

/**
  * @brief Inter-Processor Communication
  */
typedef struct
{
  __IO uint32_t C1CR;             /*!< Inter-Processor Communication: C1 control register,                  Address offset: 0x000 */
  __IO uint32_t C1MR ;            /*!< Inter-Processor Communication: C1 mask register,                     Address offset: 0x004 */
  __IO uint32_t C1SCR;            /*!< Inter-Processor Communication: C1 status set clear register,         Address offset: 0x008 */
  __IO uint32_t C1TOC2SR;         /*!< Inter-Processor Communication: C1 to processor M4  status register,  Address offset: 0x00C */
  __IO uint32_t C2CR;             /*!< Inter-Processor Communication: C2 control register,                  Address offset: 0x010 */
  __IO uint32_t C2MR ;            /*!< Inter-Processor Communication: C2 mask register,                     Address offset: 0x014 */
  __IO uint32_t C2SCR;            /*!< Inter-Processor Communication: C2 status set clear register,         Address offset: 0x018 */
  __IO uint32_t C2TOC1SR;         /*!< Inter-Processor Communication: C2 to processor M4 status register,   Address offset: 0x01C */
} IPCC_TypeDef;

typedef struct
{
  __IO uint32_t CR;               /*!< Control register,                                                    Address offset: 0x000 */
  __IO uint32_t MR;               /*!< Mask register,                                                       Address offset: 0x004 */
  __IO uint32_t SCR;              /*!< Status set clear register,                                           Address offset: 0x008 */
  __IO uint32_t SR;               /*!< Status register,                                                     Address offset: 0x00C */
} IPCC_CommonTypeDef;

/**
  * @brief Async Interrupts and Events Controller
  */
typedef struct
{
  __IO uint32_t RTSR1;          /*!< EXTI rising trigger selection register [31:0],            Address offset: 0x00 */
  __IO uint32_t FTSR1;          /*!< EXTI falling trigger selection register [31:0],           Address offset: 0x04 */
  __IO uint32_t SWIER1;         /*!< EXTI software interrupt event register [31:0],            Address offset: 0x08 */
  __IO uint32_t PR1;            /*!< EXTI pending register [31:0],                             Address offset: 0x0C */
  __IO uint32_t RESERVED1[4];   /*!< Reserved,                                                 Address offset: 0x10 - 0x1C */
  __IO uint32_t RTSR2;          /*!< EXTI rising trigger selection register [31:0],            Address offset: 0x20 */
  __IO uint32_t FTSR2;          /*!< EXTI falling trigger selection register [31:0],           Address offset: 0x24 */
  __IO uint32_t SWIER2;         /*!< EXTI software interrupt event register [31:0],            Address offset: 0x28 */
  __IO uint32_t PR2;            /*!< EXTI pending register [31:0],                             Address offset: 0x2C */
  __IO uint32_t RESERVED2[4];   /*!< Reserved,                                                 Address offset: 0x30 - 0x3C */
  __IO uint32_t RESERVED3[8];   /*!< Reserved,                                                 Address offset: 0x40 - 0x5C */
  __IO uint32_t RESERVED4[8];   /*!< Reserved,                                                 Address offset: 0x60 - 0x7C */
  __IO uint32_t IMR1;           /*!< EXTI wakeup with interrupt mask register for cpu1 [31:0], Address offset: 0x80 */
  __IO uint32_t EMR1;           /*!< EXTI wakeup with event mask register for cpu1 [31:0],     Address offset: 0x84 */
  __IO uint32_t RESERVED5[2];   /*!< Reserved,                                                 Address offset: 0x88 - 0x8C */
  __IO uint32_t IMR2;           /*!< EXTI wakeup with interrupt mask register for cpu1 [31:0], Address offset: 0x90 */
  __IO uint32_t EMR2;           /*!< EXTI wakeup with event mask register for cpu1 [31:0],     Address offset: 0x94 */
  __IO uint32_t RESERVED8[10];  /*!< Reserved,                                                 Address offset: 0x98 - 0xBC */
  __IO uint32_t C2IMR1;         /*!< EXTI wakeup with interrupt mask register for cpu2 [31:0], Address offset: 0xC0 */
  __IO uint32_t C2EMR1;         /*!< EXTI wakeup with event mask register for cpu2 [31:0],     Address offset: 0xC4 */
  __IO uint32_t RESERVED9[2];   /*!< Reserved,                                                 Address offset: 0xC8 - 0xCC */
  __IO uint32_t C2IMR2;         /*!< EXTI wakeup with interrupt mask register for cpu2 [31:0], Address offset: 0xD0 */
  __IO uint32_t C2EMR2;         /*!< EXTI wakeup with event mask register for cpu2 [31:0],     Address offset: 0xD4 */
} EXTI_TypeDef;

/**
  * @brief Public Key Accelerator (PKA)
  */
typedef struct
{
  __IO uint32_t CR;          /*!< PKA control register,                 Address offset: 0x00 */
  __IO uint32_t SR;          /*!< PKA status register,                  Address offset: 0x04 */
  __IO uint32_t CLRFR;       /*!< PKA clear flag register,              Address offset: 0x08 */
  uint32_t  Reserved1[253];  /*!< Reserved                              Address offset: 0x000C-0x03FC*/
  __IO uint32_t RAM[894];    /*!< PKA RAM,                              Address offset: 0x0400-0x11F4 */
} PKA_TypeDef;

/**
  * @brief HW Semaphore HSEM
  */
typedef struct
{
  __IO uint32_t R[32];        /*!< HSEM 2-step write lock and read back registers, Address offset: 00h-7Ch  */
  __IO uint32_t RLR[32];      /*!< HSEM 1-step read lock registers,                Address offset: 80h-FCh  */
  __IO uint32_t C1IER;        /*!< HSEM CPU1 interrupt enable register ,           Address offset: 100h     */
  __IO uint32_t C1ICR;        /*!< HSEM CPU1 interrupt clear register ,            Address offset: 104h     */
  __IO uint32_t C1ISR;        /*!< HSEM CPU1 interrupt status register ,           Address offset: 108h     */
  __IO uint32_t C1MISR;       /*!< HSEM CPU1 masked interrupt status register ,    Address offset: 10Ch     */
  __IO uint32_t C2IER;        /*!< HSEM CPU2 interrupt enable register ,           Address offset: 110h     */
  __IO uint32_t C2ICR;        /*!< HSEM CPU2 interrupt clear register ,            Address offset: 114h     */
  __IO uint32_t C2ISR;        /*!< HSEM CPU2 interrupt status register ,           Address offset: 118h     */
  __IO uint32_t C2MISR;       /*!< HSEM CPU2 masked interrupt status register ,    Address offset: 11Ch     */
       uint32_t  Reserved[8]; /*!< Reserved                                        Address offset: 120h-13Ch*/
  __IO uint32_t CR;           /*!< HSEM Semaphore clear register ,                 Address offset: 140h     */
  __IO uint32_t KEYR;         /*!< HSEM Semaphore clear key register ,             Address offset: 144h     */
} HSEM_TypeDef;

typedef struct
{
  __IO uint32_t IER;        /*!< HSEM interrupt enable register ,                Address offset:   0h     */
  __IO uint32_t ICR;        /*!< HSEM interrupt clear register ,                 Address offset:   4h     */
  __IO uint32_t ISR;        /*!< HSEM interrupt status register ,                Address offset:   8h     */
  __IO uint32_t MISR;       /*!< HSEM masked interrupt status register ,         Address offset:   Ch     */
} HSEM_Common_TypeDef;

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */

/*!< Boundary memory map */
#define FLASH_BASE             (0x08000000UL)/*!< FLASH(up to 320KB) base address */
#define SRAM_BASE              (0x20000000UL)/*!< SRAM(up to 12 KB) base address */
#define PERIPH_BASE            (0x40000000UL)/*!< Peripheral base address */

/*!< Memory, OTP and Option bytes */

/* Base addresses */
#define SYSTEM_MEMORY_BASE     (0x1FFF0000UL)  /*!< System Memory : 28Kb (0x1FFF0000 - 0x1FFF6FFF) */
#define OTP_AREA_BASE          (0x1FFF7000UL)  /*!< OTP area : 1kB (0x1FFF7000 - 0x1FFF73FF)       */
#define OPTION_BYTE_BASE       (0x1FFF7800UL)  /*!< Option Bytes : 128B (0x1FFF7800 - 0x1FFF787F)   */
#define ENGI_BYTE_BASE         (0x1FFF7400UL)  /*!< Engi Bytes : 3kB (0x1FFF7400 - 0x1FFF7FFF)     */

#define SRAM1_BASE             SRAM_BASE                 /*!< SRAM1(up to 12 KB) base address */
#define SRAM2A_BASE            (SRAM_BASE + 0x00030000UL)/*!< SRAM2A(32 KB) base address      */
#define SRAM2B_BASE            (SRAM_BASE + 0x00038000UL)/*!< SRAM2B(4 KB) base address       */

/* Memory Size */
#define FLASH_SIZE              (((uint32_t)(*((uint16_t *)FLASHSIZE_BASE)) & (0x07FFUL)) << 10U)
#define SRAM1_SIZE              0x00003000UL   /*!< SRAM1 default size  : 12 KB */
#define SRAM2A_SIZE             0x00008000UL   /*!< SRAM2a default size : 32 KB */
#define SRAM2B_SIZE             0x00001000UL   /*!< SRAM2b default size :  4 KB */

/* End addresses */
#define SRAM1_END_ADDR         (0x20002FFFUL)  /*!< SRAM1               :  12KB (0x20000000 - 0x20002FFF) */
#define SRAM2A_END_ADDR        (0x20037FFFUL)  /*!< SRAM2a (backup)     :  32KB (0x20030000 - 0x20037FFF) */
#define SRAM2B_END_ADDR        (0x20038FFFUL)  /*!< SRAM2b (backup)     :   4KB (0x20038000 - 0x20038FFF) */

#define SYSTEM_MEMORY_END_ADDR (0x1FFF6FFFUL)  /*!< System Memory : 28KB (0x1FFF0000 - 0x1FFF6FFF)  */
#define OTP_AREA_END_ADDR      (0x1FFF73FFUL)  /*!< OTP area : 1KB (0x1FFF7000 - 0x1FFF73FF)        */
#define OPTION_BYTE_END_ADDR   (0x1FFF8FFFUL)  /*!< Option Bytes : 4KB (0x1FFF8000 - 0x1FFF8FFF)    */
#define ENGI_BYTE_END_ADDR     (0x1FFF7FFFUL)  /*!< Engi Bytes : 3kB (0x1FFF7400 - 0x1FFF7FFF)      */

/*!< Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL)
#define AHB4PERIPH_BASE       (PERIPH_BASE + 0x18000000UL)
#define APB3PERIPH_BASE       (PERIPH_BASE + 0x20000000UL)

/*!< APB1 peripherals */
#define TIM2_BASE             (APB1PERIPH_BASE + 0x00000000UL)
#define RTC_BASE              (APB1PERIPH_BASE + 0x00002800UL)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x00002C00UL)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x00003000UL)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x00005400UL)
#define LPTIM1_BASE           (APB1PERIPH_BASE + 0x00007C00UL)
#define LPUART1_BASE          (APB1PERIPH_BASE + 0x00008000UL)
#define LPTIM2_BASE           (APB1PERIPH_BASE + 0x00009400UL)

/*!< APB2 peripherals */
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x00000000UL)
#define COMP1_BASE            (APB2PERIPH_BASE + 0x00000200UL)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x00002400UL)
#define ADC1_COMMON_BASE      (APB2PERIPH_BASE + 0x00002700UL)

#define TIM1_BASE             (APB2PERIPH_BASE + 0x00002C00UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x00003000UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x00003800UL)

/*!< AHB1 peripherals */
#define DMA1_BASE                (AHB1PERIPH_BASE + 0x00000000UL)
#define DMAMUX1_BASE             (AHB1PERIPH_BASE + 0x00000800UL)
#define CRC_BASE                 (AHB1PERIPH_BASE + 0x00003000UL)
#define TSC_BASE                 (AHB1PERIPH_BASE + 0x00004000UL)

#define DMA1_Channel1_BASE       (DMA1_BASE + 0x00000008UL)
#define DMA1_Channel2_BASE       (DMA1_BASE + 0x0000001CUL)
#define DMA1_Channel3_BASE       (DMA1_BASE + 0x00000030UL)
#define DMA1_Channel4_BASE       (DMA1_BASE + 0x00000044UL)
#define DMA1_Channel5_BASE       (DMA1_BASE + 0x00000058UL)
#define DMA1_Channel6_BASE       (DMA1_BASE + 0x0000006CUL)
#define DMA1_Channel7_BASE       (DMA1_BASE + 0x00000080UL)

#define DMAMUX1_Channel0_BASE    (DMAMUX1_BASE)
#define DMAMUX1_Channel1_BASE    (DMAMUX1_BASE + 0x00000004UL)
#define DMAMUX1_Channel2_BASE    (DMAMUX1_BASE + 0x00000008UL)
#define DMAMUX1_Channel3_BASE    (DMAMUX1_BASE + 0x0000000CUL)
#define DMAMUX1_Channel4_BASE    (DMAMUX1_BASE + 0x00000010UL)
#define DMAMUX1_Channel5_BASE    (DMAMUX1_BASE + 0x00000014UL)
#define DMAMUX1_Channel6_BASE    (DMAMUX1_BASE + 0x00000018UL)

#define DMAMUX1_RequestGenerator0_BASE  (DMAMUX1_BASE + 0x00000100UL)
#define DMAMUX1_RequestGenerator1_BASE  (DMAMUX1_BASE + 0x00000104UL)
#define DMAMUX1_RequestGenerator2_BASE  (DMAMUX1_BASE + 0x00000108UL)
#define DMAMUX1_RequestGenerator3_BASE  (DMAMUX1_BASE + 0x0000010CUL)

#define DMAMUX1_ChannelStatus_BASE      (DMAMUX1_BASE + 0x00000080UL)
#define DMAMUX1_RequestGenStatus_BASE   (DMAMUX1_BASE + 0x00000140UL)

/*!< AHB2 peripherals */
#define IOPORT_BASE         (AHB2PERIPH_BASE + 0x00000000UL)
#define GPIOA_BASE          (IOPORT_BASE + 0x00000000UL)
#define GPIOB_BASE          (IOPORT_BASE + 0x00000400UL)
#define GPIOC_BASE          (IOPORT_BASE + 0x00000800UL)
#define GPIOE_BASE          (IOPORT_BASE + 0x00001000UL)
#define GPIOH_BASE          (IOPORT_BASE + 0x00001C00UL)

/*!< AHB Shared peripherals */
#define RCC_BASE              (AHB4PERIPH_BASE + 0x00000000UL)
#define PWR_BASE              (AHB4PERIPH_BASE + 0x00000400UL)
#define EXTI_BASE             (AHB4PERIPH_BASE + 0x00000800UL)
#define IPCC_BASE             (AHB4PERIPH_BASE + 0x00000C00UL)
#define RNG_BASE              (AHB4PERIPH_BASE + 0x00001000UL)
#define HSEM_BASE             (AHB4PERIPH_BASE + 0x00001400UL)
#define AES2_BASE             (AHB4PERIPH_BASE + 0x00001800UL)
#define PKA_BASE              (AHB4PERIPH_BASE + 0x00002000UL)
#define FLASH_REG_BASE        (AHB4PERIPH_BASE + 0x00004000UL)

/* Debug MCU registers base address */
#define DBGMCU_BASE           (0xE0042000UL)


/*!< AHB3 peripherals */

/*!< Device Electronic Signature */
#define PACKAGE_BASE          ((uint32_t)0x1FFF7500UL)       /*!< Package data register base address     */
#define UID64_BASE            ((uint32_t)0x1FFF7580UL)       /*!< 64-bit Unique device Identification    */
#define UID_BASE              ((uint32_t)0x1FFF7590UL)       /*!< Unique device ID register base address */
#define FLASHSIZE_BASE        ((uint32_t)0x1FFF75E0UL)       /*!< Flash size data register base address  */

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */

/* Peripherals available on APB1 bus */
#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define RTC                 ((RTC_TypeDef *) RTC_BASE)
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define LPTIM1              ((LPTIM_TypeDef *) LPTIM1_BASE)
#define LPUART1             ((USART_TypeDef *) LPUART1_BASE)
#define LPTIM2              ((LPTIM_TypeDef *) LPTIM2_BASE)

/* Peripherals available on APB2 bus */
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define COMP1               ((COMP_TypeDef *) COMP1_BASE)
#define COMP1_COMMON        ((COMP_Common_TypeDef *) COMP1_BASE)
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)

/* Peripherals available on AHB1 bus */
#define DMA1                ((DMA_TypeDef *) DMA1_BASE)
#define DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#define DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#define DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#define DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#define DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#define DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)

#define DMAMUX1             ((DMAMUX_Channel_TypeDef *) DMAMUX1_BASE)
#define DMAMUX1_Channel0    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel0_BASE)
#define DMAMUX1_Channel1    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel1_BASE)
#define DMAMUX1_Channel2    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel2_BASE)
#define DMAMUX1_Channel3    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel3_BASE)
#define DMAMUX1_Channel4    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel4_BASE)
#define DMAMUX1_Channel5    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel5_BASE)
#define DMAMUX1_Channel6    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel6_BASE)

#define DMAMUX1_RequestGenerator0  ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGenerator0_BASE)
#define DMAMUX1_RequestGenerator1  ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGenerator1_BASE)
#define DMAMUX1_RequestGenerator2  ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGenerator2_BASE)
#define DMAMUX1_RequestGenerator3  ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGenerator3_BASE)

#define DMAMUX1_ChannelStatus      ((DMAMUX_ChannelStatus_TypeDef *) DMAMUX1_ChannelStatus_BASE)
#define DMAMUX1_RequestGenStatus   ((DMAMUX_RequestGenStatus_TypeDef *) DMAMUX1_RequestGenStatus_BASE)

#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define TSC                 ((TSC_TypeDef *) TSC_BASE)

/* Peripherals available on AHB2 bus */
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)

#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC1_COMMON         ((ADC_Common_TypeDef *) ADC1_COMMON_BASE)


/* Peripherals available on AHB shared bus */
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define IPCC                ((IPCC_TypeDef *) IPCC_BASE)
#define IPCC_C1             ((IPCC_CommonTypeDef *) IPCC_BASE)
#define IPCC_C2             ((IPCC_CommonTypeDef *) (IPCC_BASE + 0x10U))
#define RNG                 ((RNG_TypeDef *) RNG_BASE)
#define HSEM                ((HSEM_TypeDef *) HSEM_BASE)
#define HSEM_COMMON         ((HSEM_Common_TypeDef *) (HSEM_BASE + 0x100U))
#define AES2                ((AES_TypeDef *) AES2_BASE)
#define PKA                 ((PKA_TypeDef *) PKA_BASE)
#define FLASH               ((FLASH_TypeDef *) FLASH_REG_BASE)

/* Peripherals available on AHB3 bus */

#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

/** @addtogroup Hardware_Constant_Definition
  * @{
  */
#define LSI_STARTUP_TIME 130U /*!< LSI Maximum startup time in us */

/**
  * @}
  */


/** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                      Analog to Digital Converter (ADC)                     */
/*                                                                            */
/******************************************************************************/

#define ADC_SUPPORT_2_5_MSPS /* ADC sampling rate 2.5 Msamples/sec */

/********************  Bit definition for ADC_ISR register  *******************/
#define ADC_ISR_ADRDY_Pos              (0U)
#define ADC_ISR_ADRDY_Msk              (0x1UL << ADC_ISR_ADRDY_Pos)            /*!< 0x00000001 */
#define ADC_ISR_ADRDY                  ADC_ISR_ADRDY_Msk                       /*!< ADC ready flag */
#define ADC_ISR_EOSMP_Pos              (1U)
#define ADC_ISR_EOSMP_Msk              (0x1UL << ADC_ISR_EOSMP_Pos)            /*!< 0x00000002 */
#define ADC_ISR_EOSMP                  ADC_ISR_EOSMP_Msk                       /*!< ADC group regular end of sampling flag */
#define ADC_ISR_EOC_Pos                (2U)
#define ADC_ISR_EOC_Msk                (0x1UL << ADC_ISR_EOC_Pos)              /*!< 0x00000004 */
#define ADC_ISR_EOC                    ADC_ISR_EOC_Msk                         /*!< ADC group regular end of unitary conversion flag */
#define ADC_ISR_EOS_Pos                (3U)
#define ADC_ISR_EOS_Msk                (0x1UL << ADC_ISR_EOS_Pos)              /*!< 0x00000008 */
#define ADC_ISR_EOS                    ADC_ISR_EOS_Msk                         /*!< ADC group regular end of sequence conversions flag */
#define ADC_ISR_OVR_Pos                (4U)
#define ADC_ISR_OVR_Msk                (0x1UL << ADC_ISR_OVR_Pos)              /*!< 0x00000010 */
#define ADC_ISR_OVR                    ADC_ISR_OVR_Msk                         /*!< ADC group regular overrun flag */
#define ADC_ISR_AWD1_Pos               (7U)
#define ADC_ISR_AWD1_Msk               (0x1UL << ADC_ISR_AWD1_Pos)             /*!< 0x00000080 */
#define ADC_ISR_AWD1                   ADC_ISR_AWD1_Msk                        /*!< ADC analog watchdog 1 flag */
#define ADC_ISR_AWD2_Pos               (8U)
#define ADC_ISR_AWD2_Msk               (0x1UL << ADC_ISR_AWD2_Pos)             /*!< 0x00000100 */
#define ADC_ISR_AWD2                   ADC_ISR_AWD2_Msk                        /*!< ADC analog watchdog 2 flag */
#define ADC_ISR_AWD3_Pos               (9U)
#define ADC_ISR_AWD3_Msk               (0x1UL << ADC_ISR_AWD3_Pos)             /*!< 0x00000200 */
#define ADC_ISR_AWD3                   ADC_ISR_AWD3_Msk                        /*!< ADC analog watchdog 3 flag */
#define ADC_ISR_EOCAL_Pos              (11U)
#define ADC_ISR_EOCAL_Msk              (0x1UL << ADC_ISR_EOCAL_Pos)            /*!< 0x00000800 */
#define ADC_ISR_EOCAL                  ADC_ISR_EOCAL_Msk                       /*!< ADC end of calibration flag */
#define ADC_ISR_CCRDY_Pos              (13U)
#define ADC_ISR_CCRDY_Msk              (0x1UL << ADC_ISR_CCRDY_Pos)            /*!< 0x00002000 */
#define ADC_ISR_CCRDY                  ADC_ISR_CCRDY_Msk                       /*!< ADC channel configuration ready flag */

/********************  Bit definition for ADC_IER register  *******************/
#define ADC_IER_ADRDYIE_Pos            (0U)
#define ADC_IER_ADRDYIE_Msk            (0x1UL << ADC_IER_ADRDYIE_Pos)          /*!< 0x00000001 */
#define ADC_IER_ADRDYIE                ADC_IER_ADRDYIE_Msk                     /*!< ADC ready interrupt */
#define ADC_IER_EOSMPIE_Pos            (1U)
#define ADC_IER_EOSMPIE_Msk            (0x1UL << ADC_IER_EOSMPIE_Pos)          /*!< 0x00000002 */
#define ADC_IER_EOSMPIE                ADC_IER_EOSMPIE_Msk                     /*!< ADC group regular end of sampling interrupt */
#define ADC_IER_EOCIE_Pos              (2U)
#define ADC_IER_EOCIE_Msk              (0x1UL << ADC_IER_EOCIE_Pos)            /*!< 0x00000004 */
#define ADC_IER_EOCIE                  ADC_IER_EOCIE_Msk                       /*!< ADC group regular end of unitary conversion interrupt */
#define ADC_IER_EOSIE_Pos              (3U)
#define ADC_IER_EOSIE_Msk              (0x1UL << ADC_IER_EOSIE_Pos)            /*!< 0x00000008 */
#define ADC_IER_EOSIE                  ADC_IER_EOSIE_Msk                       /*!< ADC group regular end of sequence conversions interrupt */
#define ADC_IER_OVRIE_Pos              (4U)
#define ADC_IER_OVRIE_Msk              (0x1UL << ADC_IER_OVRIE_Pos)            /*!< 0x00000010 */
#define ADC_IER_OVRIE                  ADC_IER_OVRIE_Msk                       /*!< ADC group regular overrun interrupt */
#define ADC_IER_AWD1IE_Pos             (7U)
#define ADC_IER_AWD1IE_Msk             (0x1UL << ADC_IER_AWD1IE_Pos)           /*!< 0x00000080 */
#define ADC_IER_AWD1IE                 ADC_IER_AWD1IE_Msk                      /*!< ADC analog watchdog 1 interrupt */
#define ADC_IER_AWD2IE_Pos             (8U)
#define ADC_IER_AWD2IE_Msk             (0x1UL << ADC_IER_AWD2IE_Pos)           /*!< 0x00000100 */
#define ADC_IER_AWD2IE                 ADC_IER_AWD2IE_Msk                      /*!< ADC analog watchdog 2 interrupt */
#define ADC_IER_AWD3IE_Pos             (9U)
#define ADC_IER_AWD3IE_Msk             (0x1UL << ADC_IER_AWD3IE_Pos)           /*!< 0x00000200 */
#define ADC_IER_AWD3IE                 ADC_IER_AWD3IE_Msk                      /*!< ADC analog watchdog 3 interrupt */
#define ADC_IER_EOCALIE_Pos            (11U)
#define ADC_IER_EOCALIE_Msk            (0x1UL << ADC_IER_EOCALIE_Pos)          /*!< 0x00000800 */
#define ADC_IER_EOCALIE                ADC_IER_EOCALIE_Msk                     /*!< ADC end of calibration interrupt */
#define ADC_IER_CCRDYIE_Pos            (13U)
#define ADC_IER_CCRDYIE_Msk            (0x1UL << ADC_IER_CCRDYIE_Pos)          /*!< 0x00002000 */
#define ADC_IER_CCRDYIE                ADC_IER_CCRDYIE_Msk                     /*!< ADC channel configuration ready interrupt */

/********************  Bit definition for ADC_CR register  ********************/
#define ADC_CR_ADEN_Pos                (0U)
#define ADC_CR_ADEN_Msk                (0x1UL << ADC_CR_ADEN_Pos)              /*!< 0x00000001 */
#define ADC_CR_ADEN                    ADC_CR_ADEN_Msk                         /*!< ADC enable */
#define ADC_CR_ADDIS_Pos               (1U)
#define ADC_CR_ADDIS_Msk               (0x1UL << ADC_CR_ADDIS_Pos)             /*!< 0x00000002 */
#define ADC_CR_ADDIS                   ADC_CR_ADDIS_Msk                        /*!< ADC disable */
#define ADC_CR_ADSTART_Pos             (2U)
#define ADC_CR_ADSTART_Msk             (0x1UL << ADC_CR_ADSTART_Pos)           /*!< 0x00000004 */
#define ADC_CR_ADSTART                 ADC_CR_ADSTART_Msk                      /*!< ADC group regular conversion start */
#define ADC_CR_ADSTP_Pos               (4U)
#define ADC_CR_ADSTP_Msk               (0x1UL << ADC_CR_ADSTP_Pos)             /*!< 0x00000010 */
#define ADC_CR_ADSTP                   ADC_CR_ADSTP_Msk                        /*!< ADC group regular conversion stop */
#define ADC_CR_ADVREGEN_Pos            (28U)
#define ADC_CR_ADVREGEN_Msk            (0x1UL << ADC_CR_ADVREGEN_Pos)          /*!< 0x10000000 */
#define ADC_CR_ADVREGEN                ADC_CR_ADVREGEN_Msk                     /*!< ADC voltage regulator enable */
#define ADC_CR_ADCAL_Pos               (31U)
#define ADC_CR_ADCAL_Msk               (0x1UL << ADC_CR_ADCAL_Pos)             /*!< 0x80000000 */
#define ADC_CR_ADCAL                   ADC_CR_ADCAL_Msk                        /*!< ADC calibration */

/********************  Bit definition for ADC_CFGR1 register  *****************/
#define ADC_CFGR1_DMAEN_Pos            (0U)
#define ADC_CFGR1_DMAEN_Msk            (0x1UL << ADC_CFGR1_DMAEN_Pos)          /*!< 0x00000001 */
#define ADC_CFGR1_DMAEN                ADC_CFGR1_DMAEN_Msk                     /*!< ADC DMA transfer enable */
#define ADC_CFGR1_DMACFG_Pos           (1U)
#define ADC_CFGR1_DMACFG_Msk           (0x1UL << ADC_CFGR1_DMACFG_Pos)         /*!< 0x00000002 */
#define ADC_CFGR1_DMACFG               ADC_CFGR1_DMACFG_Msk                    /*!< ADC DMA transfer configuration */

#define ADC_CFGR1_SCANDIR_Pos          (2U)
#define ADC_CFGR1_SCANDIR_Msk          (0x1UL << ADC_CFGR1_SCANDIR_Pos)        /*!< 0x00000004 */
#define ADC_CFGR1_SCANDIR              ADC_CFGR1_SCANDIR_Msk                   /*!< ADC group regular sequencer scan direction */

#define ADC_CFGR1_RES_Pos              (3U)
#define ADC_CFGR1_RES_Msk              (0x3UL << ADC_CFGR1_RES_Pos)            /*!< 0x00000018 */
#define ADC_CFGR1_RES                  ADC_CFGR1_RES_Msk                       /*!< ADC data resolution */
#define ADC_CFGR1_RES_0                (0x1UL << ADC_CFGR1_RES_Pos)            /*!< 0x00000008 */
#define ADC_CFGR1_RES_1                (0x2UL << ADC_CFGR1_RES_Pos)            /*!< 0x00000010 */

#define ADC_CFGR1_ALIGN_Pos            (5U)
#define ADC_CFGR1_ALIGN_Msk            (0x1UL << ADC_CFGR1_ALIGN_Pos)          /*!< 0x00000020 */
#define ADC_CFGR1_ALIGN                ADC_CFGR1_ALIGN_Msk                     /*!< ADC data alignment */

#define ADC_CFGR1_EXTSEL_Pos           (6U)
#define ADC_CFGR1_EXTSEL_Msk           (0x7UL << ADC_CFGR1_EXTSEL_Pos)         /*!< 0x000001C0 */
#define ADC_CFGR1_EXTSEL               ADC_CFGR1_EXTSEL_Msk                    /*!< ADC group regular external trigger source */
#define ADC_CFGR1_EXTSEL_0             (0x1UL << ADC_CFGR1_EXTSEL_Pos)         /*!< 0x00000040 */
#define ADC_CFGR1_EXTSEL_1             (0x2UL << ADC_CFGR1_EXTSEL_Pos)         /*!< 0x00000080 */
#define ADC_CFGR1_EXTSEL_2             (0x4UL << ADC_CFGR1_EXTSEL_Pos)         /*!< 0x00000100 */

#define ADC_CFGR1_EXTEN_Pos            (10U)
#define ADC_CFGR1_EXTEN_Msk            (0x3UL << ADC_CFGR1_EXTEN_Pos)          /*!< 0x00000C00 */
#define ADC_CFGR1_EXTEN                ADC_CFGR1_EXTEN_Msk                     /*!< ADC group regular external trigger polarity */
#define ADC_CFGR1_EXTEN_0              (0x1UL << ADC_CFGR1_EXTEN_Pos)          /*!< 0x00000400 */
#define ADC_CFGR1_EXTEN_1              (0x2UL << ADC_CFGR1_EXTEN_Pos)          /*!< 0x00000800 */

#define ADC_CFGR1_OVRMOD_Pos           (12U)
#define ADC_CFGR1_OVRMOD_Msk           (0x1UL << ADC_CFGR1_OVRMOD_Pos)         /*!< 0x00001000 */
#define ADC_CFGR1_OVRMOD               ADC_CFGR1_OVRMOD_Msk                    /*!< ADC group regular overrun configuration */
#define ADC_CFGR1_CONT_Pos             (13U)
#define ADC_CFGR1_CONT_Msk             (0x1UL << ADC_CFGR1_CONT_Pos)           /*!< 0x00002000 */
#define ADC_CFGR1_CONT                 ADC_CFGR1_CONT_Msk                      /*!< ADC group regular continuous conversion mode */
#define ADC_CFGR1_WAIT_Pos             (14U)
#define ADC_CFGR1_WAIT_Msk             (0x1UL << ADC_CFGR1_WAIT_Pos)           /*!< 0x00004000 */
#define ADC_CFGR1_WAIT                 ADC_CFGR1_WAIT_Msk                      /*!< ADC low power auto wait */
#define ADC_CFGR1_AUTOFF_Pos           (15U)
#define ADC_CFGR1_AUTOFF_Msk           (0x1UL << ADC_CFGR1_AUTOFF_Pos)         /*!< 0x00008000 */
#define ADC_CFGR1_AUTOFF               ADC_CFGR1_AUTOFF_Msk                    /*!< ADC low power auto power off */
#define ADC_CFGR1_DISCEN_Pos           (16U)
#define ADC_CFGR1_DISCEN_Msk           (0x1UL << ADC_CFGR1_DISCEN_Pos)         /*!< 0x00010000 */
#define ADC_CFGR1_DISCEN               ADC_CFGR1_DISCEN_Msk                    /*!< ADC group regular sequencer discontinuous mode */
#define ADC_CFGR1_CHSELRMOD_Pos        (21U)
#define ADC_CFGR1_CHSELRMOD_Msk        (0x1UL << ADC_CFGR1_CHSELRMOD_Pos)      /*!< 0x00200000 */
#define ADC_CFGR1_CHSELRMOD            ADC_CFGR1_CHSELRMOD_Msk                 /*!< ADC group regular sequencer mode */

#define ADC_CFGR1_AWD1SGL_Pos          (22U)
#define ADC_CFGR1_AWD1SGL_Msk          (0x1UL << ADC_CFGR1_AWD1SGL_Pos)        /*!< 0x00400000 */
#define ADC_CFGR1_AWD1SGL              ADC_CFGR1_AWD1SGL_Msk                   /*!< ADC analog watchdog 1 monitoring a single channel or all channels */
#define ADC_CFGR1_AWD1EN_Pos           (23U)
#define ADC_CFGR1_AWD1EN_Msk           (0x1UL << ADC_CFGR1_AWD1EN_Pos)         /*!< 0x00800000 */
#define ADC_CFGR1_AWD1EN               ADC_CFGR1_AWD1EN_Msk                    /*!< ADC analog watchdog 1 enable on scope ADC group regular */

#define ADC_CFGR1_AWD1CH_Pos           (26U)
#define ADC_CFGR1_AWD1CH_Msk           (0x1FUL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x7C000000 */
#define ADC_CFGR1_AWD1CH               ADC_CFGR1_AWD1CH_Msk                    /*!< ADC analog watchdog 1 monitored channel selection */
#define ADC_CFGR1_AWD1CH_0             (0x01UL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x04000000 */
#define ADC_CFGR1_AWD1CH_1             (0x02UL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x08000000 */
#define ADC_CFGR1_AWD1CH_2             (0x04UL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x10000000 */
#define ADC_CFGR1_AWD1CH_3             (0x08UL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x20000000 */
#define ADC_CFGR1_AWD1CH_4             (0x10UL << ADC_CFGR1_AWD1CH_Pos)        /*!< 0x40000000 */

/* Definitions for cohabitation of ADC peripherals 2.5Ms/sec and 5Ms/sec across STM32WB series */
#define ADC_CFGR_DMAEN_Pos             ADC_CFGR1_DMAEN_Pos
#define ADC_CFGR_DMAEN_Msk             ADC_CFGR1_DMAEN_Msk
#define ADC_CFGR_DMAEN                 ADC_CFGR1_DMAEN
#define ADC_CFGR_DMACFG_Pos            ADC_CFGR1_DMACFG_Pos
#define ADC_CFGR_DMACFG_Msk            ADC_CFGR1_DMACFG_Msk
#define ADC_CFGR_DMACFG                ADC_CFGR1_DMACFG

#define ADC_CFGR_SCANDIR_Pos           ADC_CFGR1_SCANDIR_Pos
#define ADC_CFGR_SCANDIR_Msk           ADC_CFGR1_SCANDIR_Msk
#define ADC_CFGR_SCANDIR               ADC_CFGR1_SCANDIR

#define ADC_CFGR_RES_Pos               ADC_CFGR1_RES_Pos
#define ADC_CFGR_RES_Msk               ADC_CFGR1_RES_Msk
#define ADC_CFGR_RES                   ADC_CFGR1_RES
#define ADC_CFGR_RES_0                 ADC_CFGR1_RES_0
#define ADC_CFGR_RES_1                 ADC_CFGR1_RES_1

#define ADC_CFGR_ALIGN_Pos             ADC_CFGR1_ALIGN_Pos
#define ADC_CFGR_ALIGN_Msk             ADC_CFGR1_ALIGN_Msk
#define ADC_CFGR_ALIGN                 ADC_CFGR1_ALIGN

#define ADC_CFGR_EXTSEL_Pos            ADC_CFGR1_EXTSEL_Pos
#define ADC_CFGR_EXTSEL_Msk            ADC_CFGR1_EXTSEL_Msk
#define ADC_CFGR_EXTSEL                ADC_CFGR1_EXTSEL
#define ADC_CFGR_EXTSEL_0              ADC_CFGR1_EXTSEL_0
#define ADC_CFGR_EXTSEL_1              ADC_CFGR1_EXTSEL_1
#define ADC_CFGR_EXTSEL_2              ADC_CFGR1_EXTSEL_2

#define ADC_CFGR_EXTEN_Pos             ADC_CFGR1_EXTEN_Pos
#define ADC_CFGR_EXTEN_Msk             ADC_CFGR1_EXTEN_Msk
#define ADC_CFGR_EXTEN                 ADC_CFGR1_EXTEN
#define ADC_CFGR_EXTEN_0               ADC_CFGR1_EXTEN_0
#define ADC_CFGR_EXTEN_1               ADC_CFGR1_EXTEN_1

#define ADC_CFGR_OVRMOD_Pos            ADC_CFGR1_OVRMOD_Pos
#define ADC_CFGR_OVRMOD_Msk            ADC_CFGR1_OVRMOD_Msk
#define ADC_CFGR_OVRMOD                ADC_CFGR1_OVRMOD
#define ADC_CFGR_CONT_Pos              ADC_CFGR1_CONT_Pos
#define ADC_CFGR_CONT_Msk              ADC_CFGR1_CONT_Msk
#define ADC_CFGR_CONT                  ADC_CFGR1_CONT
#define ADC_CFGR_AUTDLY_Pos            ADC_CFGR1_WAIT_Pos
#define ADC_CFGR_AUTDLY_Msk            ADC_CFGR1_WAIT_Msk
#define ADC_CFGR_AUTDLY                ADC_CFGR1_WAIT
#define ADC_CFGR_AUTOFF_Pos            ADC_CFGR1_AUTOFF_Pos
#define ADC_CFGR_AUTOFF_Msk            ADC_CFGR1_AUTOFF_Msk
#define ADC_CFGR_AUTOFF                ADC_CFGR1_AUTOFF
#define ADC_CFGR_DISCEN_Pos            ADC_CFGR1_DISCEN_Pos
#define ADC_CFGR_DISCEN_Msk            ADC_CFGR1_DISCEN_Msk
#define ADC_CFGR_DISCEN                ADC_CFGR1_DISCEN
#define ADC_CFGR_CHSELRMOD_Pos         ADC_CFGR1_CHSELRMOD_Pos
#define ADC_CFGR_CHSELRMOD_Msk         ADC_CFGR1_CHSELRMOD_Msk
#define ADC_CFGR_CHSELRMOD             ADC_CFGR1_CHSELRMOD

#define ADC_CFGR_AWD1SGL_Pos           ADC_CFGR1_AWD1SGL_Pos
#define ADC_CFGR_AWD1SGL_Msk           ADC_CFGR1_AWD1SGL_Msk
#define ADC_CFGR_AWD1SGL               ADC_CFGR1_AWD1SGL
#define ADC_CFGR_AWD1EN_Pos            ADC_CFGR1_AWD1EN_Pos
#define ADC_CFGR_AWD1EN_Msk            ADC_CFGR1_AWD1EN_Msk
#define ADC_CFGR_AWD1EN                ADC_CFGR1_AWD1EN

#define ADC_CFGR_AWD1CH_Pos            ADC_CFGR1_AWD1CH_Pos
#define ADC_CFGR_AWD1CH_Msk            ADC_CFGR1_AWD1CH_Msk
#define ADC_CFGR_AWD1CH                ADC_CFGR1_AWD1CH
#define ADC_CFGR_AWD1CH_0              ADC_CFGR1_AWD1CH_0
#define ADC_CFGR_AWD1CH_1              ADC_CFGR1_AWD1CH_1
#define ADC_CFGR_AWD1CH_2              ADC_CFGR1_AWD1CH_2
#define ADC_CFGR_AWD1CH_3              ADC_CFGR1_AWD1CH_3
#define ADC_CFGR_AWD1CH_4              ADC_CFGR1_AWD1CH_4

/********************  Bit definition for ADC_CFGR2 register  *****************/
#define ADC_CFGR2_LFTRIG_Pos           (29U)
#define ADC_CFGR2_LFTRIG_Msk           (0x1UL << ADC_CFGR2_LFTRIG_Pos)         /*!< 0x20000000 */
#define ADC_CFGR2_LFTRIG               ADC_CFGR2_LFTRIG_Msk                    /*!< ADC low frequency trigger mode */

#define ADC_CFGR2_CKMODE_Pos           (30U)
#define ADC_CFGR2_CKMODE_Msk           (0x3UL << ADC_CFGR2_CKMODE_Pos)         /*!< 0xC0000000 */
#define ADC_CFGR2_CKMODE               ADC_CFGR2_CKMODE_Msk                    /*!< ADC clock source and prescaler (prescaler only for clock source synchronous) */
#define ADC_CFGR2_CKMODE_1             (0x2UL << ADC_CFGR2_CKMODE_Pos)         /*!< 0x80000000 */
#define ADC_CFGR2_CKMODE_0             (0x1UL << ADC_CFGR2_CKMODE_Pos)         /*!< 0x40000000 */

/********************  Bit definition for ADC_SMPR register  ******************/
#define ADC_SMPR_SMP1_Pos              (0U)
#define ADC_SMPR_SMP1_Msk              (0x7UL << ADC_SMPR_SMP1_Pos)            /*!< 0x00000007 */
#define ADC_SMPR_SMP1                  ADC_SMPR_SMP1_Msk                       /*!< ADC group of channels sampling time 1 */
#define ADC_SMPR_SMP1_0                (0x1UL << ADC_SMPR_SMP1_Pos)            /*!< 0x00000001 */
#define ADC_SMPR_SMP1_1                (0x2UL << ADC_SMPR_SMP1_Pos)            /*!< 0x00000002 */
#define ADC_SMPR_SMP1_2                (0x4UL << ADC_SMPR_SMP1_Pos)            /*!< 0x00000004 */

#define ADC_SMPR_SMP2_Pos              (4U)
#define ADC_SMPR_SMP2_Msk              (0x7UL << ADC_SMPR_SMP2_Pos)            /*!< 0x00000070 */
#define ADC_SMPR_SMP2                  ADC_SMPR_SMP2_Msk                       /*!< ADC group of channels sampling time 2 */
#define ADC_SMPR_SMP2_0                (0x1UL << ADC_SMPR_SMP2_Pos)            /*!< 0x00000010 */
#define ADC_SMPR_SMP2_1                (0x2UL << ADC_SMPR_SMP2_Pos)            /*!< 0x00000020 */
#define ADC_SMPR_SMP2_2                (0x4UL << ADC_SMPR_SMP2_Pos)            /*!< 0x00000040 */

#define ADC_SMPR_SMPSEL_Pos            (8U)
#define ADC_SMPR_SMPSEL_Msk            (0x7FFFFUL << ADC_SMPR_SMPSEL_Pos)      /*!< 0x07FFFF00 */
#define ADC_SMPR_SMPSEL                ADC_SMPR_SMPSEL_Msk                     /*!< ADC all channels sampling time selection */
#define ADC_SMPR_SMPSEL0_Pos           (8U)
#define ADC_SMPR_SMPSEL0_Msk           (0x1UL << ADC_SMPR_SMPSEL0_Pos)         /*!< 0x00000100 */
#define ADC_SMPR_SMPSEL0               ADC_SMPR_SMPSEL0_Msk                    /*!< ADC channel 0 sampling time selection */
#define ADC_SMPR_SMPSEL1_Pos           (9U)
#define ADC_SMPR_SMPSEL1_Msk           (0x1UL << ADC_SMPR_SMPSEL1_Pos)         /*!< 0x00000200 */
#define ADC_SMPR_SMPSEL1               ADC_SMPR_SMPSEL1_Msk                    /*!< ADC channel 1 sampling time selection */
#define ADC_SMPR_SMPSEL2_Pos           (10U)
#define ADC_SMPR_SMPSEL2_Msk           (0x1UL << ADC_SMPR_SMPSEL2_Pos)         /*!< 0x00000400 */
#define ADC_SMPR_SMPSEL2               ADC_SMPR_SMPSEL2_Msk                    /*!< ADC channel 2 sampling time selection */
#define ADC_SMPR_SMPSEL3_Pos           (11U)
#define ADC_SMPR_SMPSEL3_Msk           (0x1UL << ADC_SMPR_SMPSEL3_Pos)         /*!< 0x00000800 */
#define ADC_SMPR_SMPSEL3               ADC_SMPR_SMPSEL3_Msk                    /*!< ADC channel 3 sampling time selection */
#define ADC_SMPR_SMPSEL4_Pos           (12U)
#define ADC_SMPR_SMPSEL4_Msk           (0x1UL << ADC_SMPR_SMPSEL4_Pos)         /*!< 0x00001000 */
#define ADC_SMPR_SMPSEL4               ADC_SMPR_SMPSEL4_Msk                    /*!< ADC channel 4 sampling time selection */
#define ADC_SMPR_SMPSEL5_Pos           (13U)
#define ADC_SMPR_SMPSEL5_Msk           (0x1UL << ADC_SMPR_SMPSEL5_Pos)         /*!< 0x00002000 */
#define ADC_SMPR_SMPSEL5               ADC_SMPR_SMPSEL5_Msk                    /*!< ADC channel 5 sampling time selection */
#define ADC_SMPR_SMPSEL6_Pos           (14U)
#define ADC_SMPR_SMPSEL6_Msk           (0x1UL << ADC_SMPR_SMPSEL6_Pos)         /*!< 0x00004000 */
#define ADC_SMPR_SMPSEL6               ADC_SMPR_SMPSEL6_Msk                    /*!< ADC channel 6 sampling time selection */
#define ADC_SMPR_SMPSEL7_Pos           (15U)
#define ADC_SMPR_SMPSEL7_Msk           (0x1UL << ADC_SMPR_SMPSEL7_Pos)         /*!< 0x00008000 */
#define ADC_SMPR_SMPSEL7               ADC_SMPR_SMPSEL7_Msk                    /*!< ADC channel 7 sampling time selection */
#define ADC_SMPR_SMPSEL8_Pos           (16U)
#define ADC_SMPR_SMPSEL8_Msk           (0x1UL << ADC_SMPR_SMPSEL8_Pos)         /*!< 0x00010000 */
#define ADC_SMPR_SMPSEL8               ADC_SMPR_SMPSEL8_Msk                    /*!< ADC channel 8 sampling time selection */
#define ADC_SMPR_SMPSEL9_Pos           (17U)
#define ADC_SMPR_SMPSEL9_Msk           (0x1UL << ADC_SMPR_SMPSEL9_Pos)         /*!< 0x00020000 */
#define ADC_SMPR_SMPSEL9               ADC_SMPR_SMPSEL9_Msk                    /*!< ADC channel 9 sampling time selection */
#define ADC_SMPR_SMPSEL10_Pos          (18U)
#define ADC_SMPR_SMPSEL10_Msk          (0x1UL << ADC_SMPR_SMPSEL10_Pos)        /*!< 0x00040000 */
#define ADC_SMPR_SMPSEL10              ADC_SMPR_SMPSEL10_Msk                   /*!< ADC channel 10 sampling time selection */
#define ADC_SMPR_SMPSEL11_Pos          (19U)
#define ADC_SMPR_SMPSEL11_Msk          (0x1UL << ADC_SMPR_SMPSEL11_Pos)        /*!< 0x00080000 */
#define ADC_SMPR_SMPSEL11              ADC_SMPR_SMPSEL11_Msk                   /*!< ADC channel 11 sampling time selection */
#define ADC_SMPR_SMPSEL12_Pos          (20U)
#define ADC_SMPR_SMPSEL12_Msk          (0x1UL << ADC_SMPR_SMPSEL12_Pos)        /*!< 0x00100000 */
#define ADC_SMPR_SMPSEL12              ADC_SMPR_SMPSEL12_Msk                   /*!< ADC channel 12 sampling time selection */
#define ADC_SMPR_SMPSEL13_Pos          (21U)
#define ADC_SMPR_SMPSEL13_Msk          (0x1UL << ADC_SMPR_SMPSEL13_Pos)        /*!< 0x00200000 */
#define ADC_SMPR_SMPSEL13              ADC_SMPR_SMPSEL13_Msk                   /*!< ADC channel 13 sampling time selection */
#define ADC_SMPR_SMPSEL14_Pos          (22U)
#define ADC_SMPR_SMPSEL14_Msk          (0x1UL << ADC_SMPR_SMPSEL14_Pos)        /*!< 0x00400000 */
#define ADC_SMPR_SMPSEL14              ADC_SMPR_SMPSEL14_Msk                   /*!< ADC channel 14 sampling time selection */
#define ADC_SMPR_SMPSEL15_Pos          (23U)
#define ADC_SMPR_SMPSEL15_Msk          (0x1UL << ADC_SMPR_SMPSEL15_Pos)        /*!< 0x00800000 */
#define ADC_SMPR_SMPSEL15              ADC_SMPR_SMPSEL15_Msk                   /*!< ADC channel 15 sampling time selection */
#define ADC_SMPR_SMPSEL16_Pos          (24U)
#define ADC_SMPR_SMPSEL16_Msk          (0x1UL << ADC_SMPR_SMPSEL16_Pos)        /*!< 0x01000000 */
#define ADC_SMPR_SMPSEL16              ADC_SMPR_SMPSEL16_Msk                   /*!< ADC channel 16 sampling time selection */
#define ADC_SMPR_SMPSEL17_Pos          (25U)
#define ADC_SMPR_SMPSEL17_Msk          (0x1UL << ADC_SMPR_SMPSEL17_Pos)        /*!< 0x02000000 */
#define ADC_SMPR_SMPSEL17              ADC_SMPR_SMPSEL17_Msk                   /*!< ADC channel 17 sampling time selection */
#define ADC_SMPR_SMPSEL18_Pos          (25U)
#define ADC_SMPR_SMPSEL18_Msk          (0x1UL << ADC_SMPR_SMPSEL18_Pos)        /*!< 0x04000000 */
#define ADC_SMPR_SMPSEL18              ADC_SMPR_SMPSEL18_Msk                   /*!< ADC channel 18 sampling time selection */

/********************  Bit definition for ADC_TR register  *******************/
#define ADC_TR_LT_Pos             (0U)
#define ADC_TR_LT_Msk             (0xFFFUL << ADC_TR_LT_Pos)         /*!< 0x00000FFF */
#define ADC_TR_LT                 ADC_TR_LT_Msk                      /*!< ADC analog watchdog 1 threshold low */
#define ADC_TR_LT_0               (0x001UL << ADC_TR_LT_Pos)         /*!< 0x00000001 */
#define ADC_TR_LT_1               (0x002UL << ADC_TR_LT_Pos)         /*!< 0x00000002 */
#define ADC_TR_LT_2               (0x004UL << ADC_TR_LT_Pos)         /*!< 0x00000004 */
#define ADC_TR_LT_3               (0x008UL << ADC_TR_LT_Pos)         /*!< 0x00000008 */
#define ADC_TR_LT_4               (0x010UL << ADC_TR_LT_Pos)         /*!< 0x00000010 */
#define ADC_TR_LT_5               (0x020UL << ADC_TR_LT_Pos)         /*!< 0x00000020 */
#define ADC_TR_LT_6               (0x040UL << ADC_TR_LT_Pos)         /*!< 0x00000040 */
#define ADC_TR_LT_7               (0x080UL << ADC_TR_LT_Pos)         /*!< 0x00000080 */
#define ADC_TR_LT_8               (0x100UL << ADC_TR_LT_Pos)         /*!< 0x00000100 */
#define ADC_TR_LT_9               (0x200UL << ADC_TR_LT_Pos)         /*!< 0x00000200 */
#define ADC_TR_LT_10              (0x400UL << ADC_TR_LT_Pos)         /*!< 0x00000400 */
#define ADC_TR_LT_11              (0x800UL << ADC_TR_LT_Pos)         /*!< 0x00000800 */

#define ADC_TR_HT_Pos             (16U)
#define ADC_TR_HT_Msk             (0xFFFUL << ADC_TR_HT_Pos)         /*!< 0x0FFF0000 */
#define ADC_TR_HT                 ADC_TR_HT_Msk                      /*!< ADC Analog watchdog 1 threshold high */
#define ADC_TR_HT_0               (0x001UL << ADC_TR_HT_Pos)         /*!< 0x00010000 */
#define ADC_TR_HT_1               (0x002UL << ADC_TR_HT_Pos)         /*!< 0x00020000 */
#define ADC_TR_HT_2               (0x004UL << ADC_TR_HT_Pos)         /*!< 0x00040000 */
#define ADC_TR_HT_3               (0x008UL << ADC_TR_HT_Pos)         /*!< 0x00080000 */
#define ADC_TR_HT_4               (0x010UL << ADC_TR_HT_Pos)         /*!< 0x00100000 */
#define ADC_TR_HT_5               (0x020UL << ADC_TR_HT_Pos)         /*!< 0x00200000 */
#define ADC_TR_HT_6               (0x040UL << ADC_TR_HT_Pos)         /*!< 0x00400000 */
#define ADC_TR_HT_7               (0x080UL << ADC_TR_HT_Pos)         /*!< 0x00800000 */
#define ADC_TR_HT_8               (0x100UL << ADC_TR_HT_Pos)         /*!< 0x01000000 */
#define ADC_TR_HT_9               (0x200UL << ADC_TR_HT_Pos)         /*!< 0x02000000 */
#define ADC_TR_HT_10              (0x400UL << ADC_TR_HT_Pos)         /*!< 0x04000000 */
#define ADC_TR_HT_11              (0x800UL << ADC_TR_HT_Pos)         /*!< 0x08000000 */

/* Legacy definitions */
#define ADC_TR1_LT1             ADC_TR_LT
#define ADC_TR1_LT1_0           ADC_TR_LT_0
#define ADC_TR1_LT1_1           ADC_TR_LT_1
#define ADC_TR1_LT1_2           ADC_TR_LT_2
#define ADC_TR1_LT1_3           ADC_TR_LT_3
#define ADC_TR1_LT1_4           ADC_TR_LT_4
#define ADC_TR1_LT1_5           ADC_TR_LT_5
#define ADC_TR1_LT1_6           ADC_TR_LT_6
#define ADC_TR1_LT1_7           ADC_TR_LT_7
#define ADC_TR1_LT1_8           ADC_TR_LT_8
#define ADC_TR1_LT1_9           ADC_TR_LT_9
#define ADC_TR1_LT1_10          ADC_TR_LT_10
#define ADC_TR1_LT1_11          ADC_TR_LT_11

#define ADC_TR1_HT1             ADC_TR_HT
#define ADC_TR1_HT1_0           ADC_TR_HT_0
#define ADC_TR1_HT1_1           ADC_TR_HT_1
#define ADC_TR1_HT1_2           ADC_TR_HT_2
#define ADC_TR1_HT1_3           ADC_TR_HT_3
#define ADC_TR1_HT1_4           ADC_TR_HT_4
#define ADC_TR1_HT1_5           ADC_TR_HT_5
#define ADC_TR1_HT1_6           ADC_TR_HT_6
#define ADC_TR1_HT1_7           ADC_TR_HT_7
#define ADC_TR1_HT1_8           ADC_TR_HT_8
#define ADC_TR1_HT1_9           ADC_TR_HT_9
#define ADC_TR1_HT1_10          ADC_TR_HT_10
#define ADC_TR1_HT1_11          ADC_TR_HT_11

/********************  Bit definition for ADC_CHSELR register  ****************/
#define ADC_CHSELR_CHSEL_Pos           (0U)
#define ADC_CHSELR_CHSEL_Msk           (0x7FFFFUL << ADC_CHSELR_CHSEL_Pos)     /*!< 0x0007FFFF */
#define ADC_CHSELR_CHSEL               ADC_CHSELR_CHSEL_Msk                    /*!< ADC group regular sequencer channels, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL18_Pos         (18U)
#define ADC_CHSELR_CHSEL18_Msk         (0x1UL << ADC_CHSELR_CHSEL18_Pos)       /*!< 0x00040000 */
#define ADC_CHSELR_CHSEL18             ADC_CHSELR_CHSEL18_Msk                  /*!< ADC group regular sequencer channel 18, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL17_Pos         (17U)
#define ADC_CHSELR_CHSEL17_Msk         (0x1UL << ADC_CHSELR_CHSEL17_Pos)       /*!< 0x00020000 */
#define ADC_CHSELR_CHSEL17             ADC_CHSELR_CHSEL17_Msk                  /*!< ADC group regular sequencer channel 17, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL16_Pos         (16U)
#define ADC_CHSELR_CHSEL16_Msk         (0x1UL << ADC_CHSELR_CHSEL16_Pos)       /*!< 0x00010000 */
#define ADC_CHSELR_CHSEL16             ADC_CHSELR_CHSEL16_Msk                  /*!< ADC group regular sequencer channel 16, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL15_Pos         (15U)
#define ADC_CHSELR_CHSEL15_Msk         (0x1UL << ADC_CHSELR_CHSEL15_Pos)       /*!< 0x00008000 */
#define ADC_CHSELR_CHSEL15             ADC_CHSELR_CHSEL15_Msk                  /*!< ADC group regular sequencer channel 15, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL14_Pos         (14U)
#define ADC_CHSELR_CHSEL14_Msk         (0x1UL << ADC_CHSELR_CHSEL14_Pos)       /*!< 0x00004000 */
#define ADC_CHSELR_CHSEL14             ADC_CHSELR_CHSEL14_Msk                  /*!< ADC group regular sequencer channel 14, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL13_Pos         (13U)
#define ADC_CHSELR_CHSEL13_Msk         (0x1UL << ADC_CHSELR_CHSEL13_Pos)       /*!< 0x00002000 */
#define ADC_CHSELR_CHSEL13             ADC_CHSELR_CHSEL13_Msk                  /*!< ADC group regular sequencer channel 13, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL12_Pos         (12U)
#define ADC_CHSELR_CHSEL12_Msk         (0x1UL << ADC_CHSELR_CHSEL12_Pos)       /*!< 0x00001000 */
#define ADC_CHSELR_CHSEL12             ADC_CHSELR_CHSEL12_Msk                  /*!< ADC group regular sequencer channel 12, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL11_Pos         (11U)
#define ADC_CHSELR_CHSEL11_Msk         (0x1UL << ADC_CHSELR_CHSEL11_Pos)       /*!< 0x00000800 */
#define ADC_CHSELR_CHSEL11             ADC_CHSELR_CHSEL11_Msk                  /*!< ADC group regular sequencer channel 11, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL10_Pos         (10U)
#define ADC_CHSELR_CHSEL10_Msk         (0x1UL << ADC_CHSELR_CHSEL10_Pos)       /*!< 0x00000400 */
#define ADC_CHSELR_CHSEL10             ADC_CHSELR_CHSEL10_Msk                  /*!< ADC group regular sequencer channel 10, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL9_Pos          (9U)
#define ADC_CHSELR_CHSEL9_Msk          (0x1UL << ADC_CHSELR_CHSEL9_Pos)        /*!< 0x00000200 */
#define ADC_CHSELR_CHSEL9              ADC_CHSELR_CHSEL9_Msk                   /*!< ADC group regular sequencer channel 9, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL8_Pos          (8U)
#define ADC_CHSELR_CHSEL8_Msk          (0x1UL << ADC_CHSELR_CHSEL8_Pos)        /*!< 0x00000100 */
#define ADC_CHSELR_CHSEL8              ADC_CHSELR_CHSEL8_Msk                   /*!< ADC group regular sequencer channel 8, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL7_Pos          (7U)
#define ADC_CHSELR_CHSEL7_Msk          (0x1UL << ADC_CHSELR_CHSEL7_Pos)        /*!< 0x00000080 */
#define ADC_CHSELR_CHSEL7              ADC_CHSELR_CHSEL7_Msk                   /*!< ADC group regular sequencer channel 7, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL6_Pos          (6U)
#define ADC_CHSELR_CHSEL6_Msk          (0x1UL << ADC_CHSELR_CHSEL6_Pos)        /*!< 0x00000040 */
#define ADC_CHSELR_CHSEL6              ADC_CHSELR_CHSEL6_Msk                   /*!< ADC group regular sequencer channel 6, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL5_Pos          (5U)
#define ADC_CHSELR_CHSEL5_Msk          (0x1UL << ADC_CHSELR_CHSEL5_Pos)        /*!< 0x00000020 */
#define ADC_CHSELR_CHSEL5              ADC_CHSELR_CHSEL5_Msk                   /*!< ADC group regular sequencer channel 5, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL4_Pos          (4U)
#define ADC_CHSELR_CHSEL4_Msk          (0x1UL << ADC_CHSELR_CHSEL4_Pos)        /*!< 0x00000010 */
#define ADC_CHSELR_CHSEL4              ADC_CHSELR_CHSEL4_Msk                   /*!< ADC group regular sequencer channel 4, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL3_Pos          (3U)
#define ADC_CHSELR_CHSEL3_Msk          (0x1UL << ADC_CHSELR_CHSEL3_Pos)        /*!< 0x00000008 */
#define ADC_CHSELR_CHSEL3              ADC_CHSELR_CHSEL3_Msk                   /*!< ADC group regular sequencer channel 3, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL2_Pos          (2U)
#define ADC_CHSELR_CHSEL2_Msk          (0x1UL << ADC_CHSELR_CHSEL2_Pos)        /*!< 0x00000004 */
#define ADC_CHSELR_CHSEL2              ADC_CHSELR_CHSEL2_Msk                   /*!< ADC group regular sequencer channel 2, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL1_Pos          (1U)
#define ADC_CHSELR_CHSEL1_Msk          (0x1UL << ADC_CHSELR_CHSEL1_Pos)        /*!< 0x00000002 */
#define ADC_CHSELR_CHSEL1              ADC_CHSELR_CHSEL1_Msk                   /*!< ADC group regular sequencer channel 1, available when ADC_CFGR1_CHSELRMOD is reset */
#define ADC_CHSELR_CHSEL0_Pos          (0U)
#define ADC_CHSELR_CHSEL0_Msk          (0x1UL << ADC_CHSELR_CHSEL0_Pos)        /*!< 0x00000001 */
#define ADC_CHSELR_CHSEL0              ADC_CHSELR_CHSEL0_Msk                   /*!< ADC group regular sequencer channel 0, available when ADC_CFGR1_CHSELRMOD is reset */

#define ADC_CHSELR_SQ_ALL_Pos          (0U)
#define ADC_CHSELR_SQ_ALL_Msk          (0xFFFFFFFFUL << ADC_CHSELR_SQ_ALL_Pos) /*!< 0xFFFFFFFF */
#define ADC_CHSELR_SQ_ALL              ADC_CHSELR_SQ_ALL_Msk                   /*!< ADC group regular sequencer all ranks, available when ADC_CFGR1_CHSELRMOD is set */

#define ADC_CHSELR_SQ8_Pos             (28U)
#define ADC_CHSELR_SQ8_Msk             (0xFUL << ADC_CHSELR_SQ8_Pos)           /*!< 0xF0000000 */
#define ADC_CHSELR_SQ8                 ADC_CHSELR_SQ8_Msk                      /*!< ADC group regular sequencer rank 8, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ8_0               (0x1UL << ADC_CHSELR_SQ8_Pos)           /*!< 0x10000000 */
#define ADC_CHSELR_SQ8_1               (0x2UL << ADC_CHSELR_SQ8_Pos)           /*!< 0x20000000 */
#define ADC_CHSELR_SQ8_2               (0x4UL << ADC_CHSELR_SQ8_Pos)           /*!< 0x40000000 */
#define ADC_CHSELR_SQ8_3               (0x8UL << ADC_CHSELR_SQ8_Pos)           /*!< 0x80000000 */

#define ADC_CHSELR_SQ7_Pos             (24U)
#define ADC_CHSELR_SQ7_Msk             (0xFUL << ADC_CHSELR_SQ7_Pos)           /*!< 0x0F000000 */
#define ADC_CHSELR_SQ7                 ADC_CHSELR_SQ7_Msk                      /*!< ADC group regular sequencer rank 7, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ7_0               (0x1UL << ADC_CHSELR_SQ7_Pos)           /*!< 0x01000000 */
#define ADC_CHSELR_SQ7_1               (0x2UL << ADC_CHSELR_SQ7_Pos)           /*!< 0x02000000 */
#define ADC_CHSELR_SQ7_2               (0x4UL << ADC_CHSELR_SQ7_Pos)           /*!< 0x04000000 */
#define ADC_CHSELR_SQ7_3               (0x8UL << ADC_CHSELR_SQ7_Pos)           /*!< 0x08000000 */

#define ADC_CHSELR_SQ6_Pos             (20U)
#define ADC_CHSELR_SQ6_Msk             (0xFUL << ADC_CHSELR_SQ6_Pos)           /*!< 0x00F00000 */
#define ADC_CHSELR_SQ6                 ADC_CHSELR_SQ6_Msk                      /*!< ADC group regular sequencer rank 6, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ6_0               (0x1UL << ADC_CHSELR_SQ6_Pos)           /*!< 0x00100000 */
#define ADC_CHSELR_SQ6_1               (0x2UL << ADC_CHSELR_SQ6_Pos)           /*!< 0x00200000 */
#define ADC_CHSELR_SQ6_2               (0x4UL << ADC_CHSELR_SQ6_Pos)           /*!< 0x00400000 */
#define ADC_CHSELR_SQ6_3               (0x8UL << ADC_CHSELR_SQ6_Pos)           /*!< 0x00800000 */

#define ADC_CHSELR_SQ5_Pos             (16U)
#define ADC_CHSELR_SQ5_Msk             (0xFUL << ADC_CHSELR_SQ5_Pos)           /*!< 0x000F0000 */
#define ADC_CHSELR_SQ5                 ADC_CHSELR_SQ5_Msk                      /*!< ADC group regular sequencer rank 5, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ5_0               (0x1UL << ADC_CHSELR_SQ5_Pos)           /*!< 0x00010000 */
#define ADC_CHSELR_SQ5_1               (0x2UL << ADC_CHSELR_SQ5_Pos)           /*!< 0x00020000 */
#define ADC_CHSELR_SQ5_2               (0x4UL << ADC_CHSELR_SQ5_Pos)           /*!< 0x00040000 */
#define ADC_CHSELR_SQ5_3               (0x8UL << ADC_CHSELR_SQ5_Pos)           /*!< 0x00080000 */

#define ADC_CHSELR_SQ4_Pos             (12U)
#define ADC_CHSELR_SQ4_Msk             (0xFUL << ADC_CHSELR_SQ4_Pos)           /*!< 0x0000F000 */
#define ADC_CHSELR_SQ4                 ADC_CHSELR_SQ4_Msk                      /*!< ADC group regular sequencer rank 4, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ4_0               (0x1UL << ADC_CHSELR_SQ4_Pos)           /*!< 0x00001000 */
#define ADC_CHSELR_SQ4_1               (0x2UL << ADC_CHSELR_SQ4_Pos)           /*!< 0x00002000 */
#define ADC_CHSELR_SQ4_2               (0x4UL << ADC_CHSELR_SQ4_Pos)           /*!< 0x00004000 */
#define ADC_CHSELR_SQ4_3               (0x8UL << ADC_CHSELR_SQ4_Pos)           /*!< 0x00008000 */

#define ADC_CHSELR_SQ3_Pos             (8U)
#define ADC_CHSELR_SQ3_Msk             (0xFUL << ADC_CHSELR_SQ3_Pos)           /*!< 0x00000F00 */
#define ADC_CHSELR_SQ3                 ADC_CHSELR_SQ3_Msk                      /*!< ADC group regular sequencer rank 3, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ3_0               (0x1UL << ADC_CHSELR_SQ3_Pos)           /*!< 0x00000100 */
#define ADC_CHSELR_SQ3_1               (0x2UL << ADC_CHSELR_SQ3_Pos)           /*!< 0x00000200 */
#define ADC_CHSELR_SQ3_2               (0x4UL << ADC_CHSELR_SQ3_Pos)           /*!< 0x00000400 */
#define ADC_CHSELR_SQ3_3               (0x8UL << ADC_CHSELR_SQ3_Pos)           /*!< 0x00000800 */

#define ADC_CHSELR_SQ2_Pos             (4U)
#define ADC_CHSELR_SQ2_Msk             (0xFUL << ADC_CHSELR_SQ2_Pos)           /*!< 0x000000F0 */
#define ADC_CHSELR_SQ2                 ADC_CHSELR_SQ2_Msk                      /*!< ADC group regular sequencer rank 2, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ2_0               (0x1UL << ADC_CHSELR_SQ2_Pos)           /*!< 0x00000010 */
#define ADC_CHSELR_SQ2_1               (0x2UL << ADC_CHSELR_SQ2_Pos)           /*!< 0x00000020 */
#define ADC_CHSELR_SQ2_2               (0x4UL << ADC_CHSELR_SQ2_Pos)           /*!< 0x00000040 */
#define ADC_CHSELR_SQ2_3               (0x8UL << ADC_CHSELR_SQ2_Pos)           /*!< 0x00000080 */

#define ADC_CHSELR_SQ1_Pos             (0U)
#define ADC_CHSELR_SQ1_Msk             (0xFUL << ADC_CHSELR_SQ1_Pos)           /*!< 0x0000000F */
#define ADC_CHSELR_SQ1                 ADC_CHSELR_SQ1_Msk                      /*!< ADC group regular sequencer rank 1, available when ADC_CFGR1_CHSELRMOD is set */
#define ADC_CHSELR_SQ1_0               (0x1UL << ADC_CHSELR_SQ1_Pos)           /*!< 0x00000001 */
#define ADC_CHSELR_SQ1_1               (0x2UL << ADC_CHSELR_SQ1_Pos)           /*!< 0x00000002 */
#define ADC_CHSELR_SQ1_2               (0x4UL << ADC_CHSELR_SQ1_Pos)           /*!< 0x00000004 */
#define ADC_CHSELR_SQ1_3               (0x8UL << ADC_CHSELR_SQ1_Pos)           /*!< 0x00000008 */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA_Pos                (0U)
#define ADC_DR_DATA_Msk                (0xFFFFUL << ADC_DR_DATA_Pos)           /*!< 0x0000FFFF */
#define ADC_DR_DATA                    ADC_DR_DATA_Msk                         /*!< ADC group regular conversion data */
#define ADC_DR_DATA_0                  (0x0001UL << ADC_DR_DATA_Pos)           /*!< 0x00000001 */
#define ADC_DR_DATA_1                  (0x0002UL << ADC_DR_DATA_Pos)           /*!< 0x00000002 */
#define ADC_DR_DATA_2                  (0x0004UL << ADC_DR_DATA_Pos)           /*!< 0x00000004 */
#define ADC_DR_DATA_3                  (0x0008UL << ADC_DR_DATA_Pos)           /*!< 0x00000008 */
#define ADC_DR_DATA_4                  (0x0010UL << ADC_DR_DATA_Pos)           /*!< 0x00000010 */
#define ADC_DR_DATA_5                  (0x0020UL << ADC_DR_DATA_Pos)           /*!< 0x00000020 */
#define ADC_DR_DATA_6                  (0x0040UL << ADC_DR_DATA_Pos)           /*!< 0x00000040 */
#define ADC_DR_DATA_7                  (0x0080UL << ADC_DR_DATA_Pos)           /*!< 0x00000080 */
#define ADC_DR_DATA_8                  (0x0100UL << ADC_DR_DATA_Pos)           /*!< 0x00000100 */
#define ADC_DR_DATA_9                  (0x0200UL << ADC_DR_DATA_Pos)           /*!< 0x00000200 */
#define ADC_DR_DATA_10                 (0x0400UL << ADC_DR_DATA_Pos)           /*!< 0x00000400 */
#define ADC_DR_DATA_11                 (0x0800UL << ADC_DR_DATA_Pos)           /*!< 0x00000800 */
#define ADC_DR_DATA_12                 (0x1000UL << ADC_DR_DATA_Pos)           /*!< 0x00001000 */
#define ADC_DR_DATA_13                 (0x2000UL << ADC_DR_DATA_Pos)           /*!< 0x00002000 */
#define ADC_DR_DATA_14                 (0x4000UL << ADC_DR_DATA_Pos)           /*!< 0x00004000 */
#define ADC_DR_DATA_15                 (0x8000UL << ADC_DR_DATA_Pos)           /*!< 0x00008000 */

/* Definitions for cohabitation of ADC peripherals 2.5Ms/sec and 5Ms/sec across STM32WB series */
#define ADC_DR_RDATA_Pos               ADC_DR_DATA_Pos
#define ADC_DR_RDATA_Msk               ADC_DR_DATA_Msk
#define ADC_DR_RDATA                   ADC_DR_DATA

/********************  Bit definition for ADC_CALFACT register  ***************/
#define ADC_CALFACT_CALFACT_Pos        (0U)
#define ADC_CALFACT_CALFACT_Msk        (0x7FUL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x0000007F */
#define ADC_CALFACT_CALFACT            ADC_CALFACT_CALFACT_Msk                 /*!< ADC calibration factor in single-ended mode */
#define ADC_CALFACT_CALFACT_0          (0x01UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000001 */
#define ADC_CALFACT_CALFACT_1          (0x02UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000002 */
#define ADC_CALFACT_CALFACT_2          (0x04UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000004 */
#define ADC_CALFACT_CALFACT_3          (0x08UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000008 */
#define ADC_CALFACT_CALFACT_4          (0x10UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000010 */
#define ADC_CALFACT_CALFACT_5          (0x20UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000020 */
#define ADC_CALFACT_CALFACT_6          (0x40UL << ADC_CALFACT_CALFACT_Pos)     /*!< 0x00000040 */

/*************************  ADC Common registers  *****************************/
/********************  Bit definition for ADC_CCR register  *******************/
#define ADC_CCR_PRESC_Pos              (18U)
#define ADC_CCR_PRESC_Msk              (0xFUL << ADC_CCR_PRESC_Pos)            /*!< 0x003C0000 */
#define ADC_CCR_PRESC                  ADC_CCR_PRESC_Msk                       /*!< ADC common clock prescaler, only for clock source asynchronous */
#define ADC_CCR_PRESC_0                (0x1UL << ADC_CCR_PRESC_Pos)            /*!< 0x00040000 */
#define ADC_CCR_PRESC_1                (0x2UL << ADC_CCR_PRESC_Pos)            /*!< 0x00080000 */
#define ADC_CCR_PRESC_2                (0x4UL << ADC_CCR_PRESC_Pos)            /*!< 0x00100000 */
#define ADC_CCR_PRESC_3                (0x8UL << ADC_CCR_PRESC_Pos)            /*!< 0x00200000 */

#define ADC_CCR_VREFEN_Pos             (22U)
#define ADC_CCR_VREFEN_Msk             (0x1UL << ADC_CCR_VREFEN_Pos)           /*!< 0x00400000 */
#define ADC_CCR_VREFEN                 ADC_CCR_VREFEN_Msk                      /*!< ADC internal path to VrefInt enable */
#define ADC_CCR_TSEN_Pos               (23U)
#define ADC_CCR_TSEN_Msk               (0x1UL << ADC_CCR_TSEN_Pos)             /*!< 0x00800000 */
#define ADC_CCR_TSEN                   ADC_CCR_TSEN_Msk                        /*!< ADC internal path to temperature sensor enable */
#define ADC_CCR_VBATEN_Pos             (24U)
#define ADC_CCR_VBATEN_Msk             (0x1UL << ADC_CCR_VBATEN_Pos)           /*!< 0x01000000 */
#define ADC_CCR_VBATEN                 ADC_CCR_VBATEN_Msk                      /*!< ADC internal path to battery voltage enable */

/******************************************************************************/
/*                                                                            */
/*                      Analog Comparators (COMP)                             */
/*                                                                            */
/******************************************************************************/
/**********************  Bit definition for COMP_CSR register  ***************/
#define COMP_CSR_EN_Pos            (0U)
#define COMP_CSR_EN_Msk            (0x1UL << COMP_CSR_EN_Pos)                  /*!< 0x00000001 */
#define COMP_CSR_EN                COMP_CSR_EN_Msk                             /*!< Comparator enable */
#define COMP_CSR_PWRMODE_Pos       (2U)
#define COMP_CSR_PWRMODE_Msk       (0x3UL << COMP_CSR_PWRMODE_Pos)             /*!< 0x0000000C */
#define COMP_CSR_PWRMODE           COMP_CSR_PWRMODE_Msk                        /*!< Comparator power mode */
#define COMP_CSR_PWRMODE_0         (0x1UL << COMP_CSR_PWRMODE_Pos)             /*!< 0x00000004 */
#define COMP_CSR_PWRMODE_1         (0x2UL << COMP_CSR_PWRMODE_Pos)             /*!< 0x00000008 */
#define COMP_CSR_INMSEL_Pos        (4U)
#define COMP_CSR_INMSEL_Msk        (0x7UL << COMP_CSR_INMSEL_Pos)              /*!< 0x00000070 */
#define COMP_CSR_INMSEL            COMP_CSR_INMSEL_Msk                         /*!< Comparator input minus selection */
#define COMP_CSR_INMSEL_0          (0x1UL << COMP_CSR_INMSEL_Pos)              /*!< 0x00000010 */
#define COMP_CSR_INMSEL_1          (0x2UL << COMP_CSR_INMSEL_Pos)              /*!< 0x00000020 */
#define COMP_CSR_INMSEL_2          (0x4UL << COMP_CSR_INMSEL_Pos)              /*!< 0x00000040 */
#define COMP_CSR_INPSEL_Pos        (7U)
#define COMP_CSR_INPSEL_Msk        (0x3UL << COMP_CSR_INPSEL_Pos)              /*!< 0x00000180 */
#define COMP_CSR_INPSEL            COMP_CSR_INPSEL_Msk                         /*!< Comparator input plus selection */
#define COMP_CSR_INPSEL_0          (0x1UL << COMP_CSR_INPSEL_Pos)              /*!< 0x00000080 */
#define COMP_CSR_INPSEL_1          (0x2UL << COMP_CSR_INPSEL_Pos)              /*!< 0x00000100 */
#define COMP_CSR_POLARITY_Pos      (15U)
#define COMP_CSR_POLARITY_Msk      (0x1UL << COMP_CSR_POLARITY_Pos)            /*!< 0x00008000 */
#define COMP_CSR_POLARITY          COMP_CSR_POLARITY_Msk                       /*!< Comparator output polarity */
#define COMP_CSR_HYST_Pos          (16U)
#define COMP_CSR_HYST_Msk          (0x3UL << COMP_CSR_HYST_Pos)                /*!< 0x00030000 */
#define COMP_CSR_HYST              COMP_CSR_HYST_Msk                           /*!< Comparator hysteresis */
#define COMP_CSR_HYST_0            (0x1UL << COMP_CSR_HYST_Pos)                /*!< 0x00010000 */
#define COMP_CSR_HYST_1            (0x2UL << COMP_CSR_HYST_Pos)                /*!< 0x00020000 */
#define COMP_CSR_BLANKING_Pos      (18U)
#define COMP_CSR_BLANKING_Msk      (0x7UL << COMP_CSR_BLANKING_Pos)            /*!< 0x001C0000 */
#define COMP_CSR_BLANKING          COMP_CSR_BLANKING_Msk                       /*!< Comparator blanking source */
#define COMP_CSR_BLANKING_0        (0x1UL << COMP_CSR_BLANKING_Pos)            /*!< 0x00040000 */
#define COMP_CSR_BLANKING_1        (0x2UL << COMP_CSR_BLANKING_Pos)            /*!< 0x00080000 */
#define COMP_CSR_BLANKING_2        (0x4UL << COMP_CSR_BLANKING_Pos)            /*!< 0x00100000 */
#define COMP_CSR_BRGEN_Pos         (22U)
#define COMP_CSR_BRGEN_Msk         (0x1UL << COMP_CSR_BRGEN_Pos)               /*!< 0x00400000 */
#define COMP_CSR_BRGEN             COMP_CSR_BRGEN_Msk                          /*!< Comparator voltage scaler enable */
#define COMP_CSR_SCALEN_Pos        (23U)
#define COMP_CSR_SCALEN_Msk        (0x1UL << COMP_CSR_SCALEN_Pos)              /*!< 0x00800000 */
#define COMP_CSR_SCALEN            COMP_CSR_SCALEN_Msk                         /*!< Comparator scaler bridge enable */
#define COMP_CSR_INMESEL_Pos       (25U)
#define COMP_CSR_INMESEL_Msk       (0x3UL << COMP_CSR_INMESEL_Pos)             /*!< 0x06000000 */
#define COMP_CSR_INMESEL           COMP_CSR_INMESEL_Msk                        /*!< Comparator input minus extended selection */
#define COMP_CSR_INMESEL_0         (0x1UL << COMP_CSR_INMESEL_Pos)             /*!< 0x02000000 */
#define COMP_CSR_INMESEL_1         (0x2UL << COMP_CSR_INMESEL_Pos)             /*!< 0x04000000 */
#define COMP_CSR_VALUE_Pos         (30U)
#define COMP_CSR_VALUE_Msk         (0x1UL << COMP_CSR_VALUE_Pos)               /*!< 0x40000000 */
#define COMP_CSR_VALUE             COMP_CSR_VALUE_Msk                          /*!< Comparator output level */
#define COMP_CSR_LOCK_Pos          (31U)
#define COMP_CSR_LOCK_Msk          (0x1UL << COMP_CSR_LOCK_Pos)                /*!< 0x80000000 */
#define COMP_CSR_LOCK              COMP_CSR_LOCK_Msk                           /*!< Comparator lock */

/******************************************************************************/
/*                                                                            */
/*                          CRC calculation unit                              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CRC_DR register  *********************/
#define CRC_DR_DR_Pos            (0U)
#define CRC_DR_DR_Msk            (0xFFFFFFFFUL << CRC_DR_DR_Pos)               /*!< 0xFFFFFFFF */
#define CRC_DR_DR                CRC_DR_DR_Msk                                 /*!< Data register bits */

/*******************  Bit definition for CRC_IDR register  ********************/
#define CRC_IDR_IDR_Pos          (0U)
#define CRC_IDR_IDR_Msk          (0xFFFFFFFFUL << CRC_IDR_IDR_Pos)                   /*!< 0x000000FF */
#define CRC_IDR_IDR              CRC_IDR_IDR_Msk                               /*!< General-purpose 8-bits data register bits */

/********************  Bit definition for CRC_CR register  ********************/
#define CRC_CR_RESET_Pos         (0U)
#define CRC_CR_RESET_Msk         (0x1UL << CRC_CR_RESET_Pos)                   /*!< 0x00000001 */
#define CRC_CR_RESET             CRC_CR_RESET_Msk                              /*!< RESET the CRC computation unit bit */
#define CRC_CR_POLYSIZE_Pos      (3U)
#define CRC_CR_POLYSIZE_Msk      (0x3UL << CRC_CR_POLYSIZE_Pos)                /*!< 0x00000018 */
#define CRC_CR_POLYSIZE          CRC_CR_POLYSIZE_Msk                           /*!< Polynomial size bits */
#define CRC_CR_POLYSIZE_0        (0x1U << CRC_CR_POLYSIZE_Pos)                 /*!< 0x00000008 */
#define CRC_CR_POLYSIZE_1        (0x2U << CRC_CR_POLYSIZE_Pos)                 /*!< 0x00000010 */
#define CRC_CR_REV_IN_Pos        (5U)
#define CRC_CR_REV_IN_Msk        (0x3UL << CRC_CR_REV_IN_Pos)                  /*!< 0x00000060 */
#define CRC_CR_REV_IN            CRC_CR_REV_IN_Msk                             /*!< REV_IN Reverse Input Data bits */
#define CRC_CR_REV_IN_0          (0x1U << CRC_CR_REV_IN_Pos)                   /*!< 0x00000020 */
#define CRC_CR_REV_IN_1          (0x2U << CRC_CR_REV_IN_Pos)                   /*!< 0x00000040 */
#define CRC_CR_REV_OUT_Pos       (7U)
#define CRC_CR_REV_OUT_Msk       (0x1UL << CRC_CR_REV_OUT_Pos)                 /*!< 0x00000080 */
#define CRC_CR_REV_OUT           CRC_CR_REV_OUT_Msk                            /*!< REV_OUT Reverse Output Data bits */

/*******************  Bit definition for CRC_INIT register  *******************/
#define CRC_INIT_INIT_Pos        (0U)
#define CRC_INIT_INIT_Msk        (0xFFFFFFFFUL << CRC_INIT_INIT_Pos)           /*!< 0xFFFFFFFF */
#define CRC_INIT_INIT            CRC_INIT_INIT_Msk                             /*!< Initial CRC value bits */

/*******************  Bit definition for CRC_POL register  ********************/
#define CRC_POL_POL_Pos          (0U)
#define CRC_POL_POL_Msk          (0xFFFFFFFFUL << CRC_POL_POL_Pos)             /*!< 0xFFFFFFFF */
#define CRC_POL_POL              CRC_POL_POL_Msk                               /*!< Coefficients of the polynomial */

/******************************************************************************/
/*                                                                            */
/*                       Advanced Encryption Standard (AES)                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for AES_CR register  *********************/
#define AES_CR_EN_Pos            (0U)
#define AES_CR_EN_Msk            (0x1UL << AES_CR_EN_Pos)                      /*!< 0x00000001 */
#define AES_CR_EN                AES_CR_EN_Msk                                 /*!< AES Enable */
#define AES_CR_DATATYPE_Pos      (1U)
#define AES_CR_DATATYPE_Msk      (0x3UL << AES_CR_DATATYPE_Pos)                /*!< 0x00000006 */
#define AES_CR_DATATYPE          AES_CR_DATATYPE_Msk                           /*!< Data type selection */
#define AES_CR_DATATYPE_0        (0x1U << AES_CR_DATATYPE_Pos)                 /*!< 0x00000002 */
#define AES_CR_DATATYPE_1        (0x2U << AES_CR_DATATYPE_Pos)                 /*!< 0x00000004 */

#define AES_CR_MODE_Pos          (3U)
#define AES_CR_MODE_Msk          (0x3UL << AES_CR_MODE_Pos)                    /*!< 0x00000018 */
#define AES_CR_MODE              AES_CR_MODE_Msk                               /*!< AES Mode Of Operation */
#define AES_CR_MODE_0            (0x1U << AES_CR_MODE_Pos)                     /*!< 0x00000008 */
#define AES_CR_MODE_1            (0x2U << AES_CR_MODE_Pos)                     /*!< 0x00000010 */

#define AES_CR_CHMOD_Pos         (5U)
#define AES_CR_CHMOD_Msk         (0x803UL << AES_CR_CHMOD_Pos)                 /*!< 0x00010060 */
#define AES_CR_CHMOD             AES_CR_CHMOD_Msk                              /*!< AES Chaining Mode */
#define AES_CR_CHMOD_0           (0x001U << AES_CR_CHMOD_Pos)                  /*!< 0x00000020 */
#define AES_CR_CHMOD_1           (0x002U << AES_CR_CHMOD_Pos)                  /*!< 0x00000040 */
#define AES_CR_CHMOD_2           (0x800U << AES_CR_CHMOD_Pos)                  /*!< 0x00010000 */

#define AES_CR_CCFC_Pos          (7U)
#define AES_CR_CCFC_Msk          (0x1UL << AES_CR_CCFC_Pos)                    /*!< 0x00000080 */
#define AES_CR_CCFC              AES_CR_CCFC_Msk                               /*!< Computation Complete Flag Clear */
#define AES_CR_ERRC_Pos          (8U)
#define AES_CR_ERRC_Msk          (0x1UL << AES_CR_ERRC_Pos)                    /*!< 0x00000100 */
#define AES_CR_ERRC              AES_CR_ERRC_Msk                               /*!< Error Clear */
#define AES_CR_CCFIE_Pos         (9U)
#define AES_CR_CCFIE_Msk         (0x1UL << AES_CR_CCFIE_Pos)                   /*!< 0x00000200 */
#define AES_CR_CCFIE             AES_CR_CCFIE_Msk                              /*!< Computation Complete Flag Interrupt Enable */
#define AES_CR_ERRIE_Pos         (10U)
#define AES_CR_ERRIE_Msk         (0x1UL << AES_CR_ERRIE_Pos)                   /*!< 0x00000400 */
#define AES_CR_ERRIE             AES_CR_ERRIE_Msk                              /*!< Error Interrupt Enable */
#define AES_CR_DMAINEN_Pos       (11U)
#define AES_CR_DMAINEN_Msk       (0x1UL << AES_CR_DMAINEN_Pos)                 /*!< 0x00000800 */
#define AES_CR_DMAINEN           AES_CR_DMAINEN_Msk                            /*!< Enable data input phase DMA management  */
#define AES_CR_DMAOUTEN_Pos      (12U)
#define AES_CR_DMAOUTEN_Msk      (0x1UL << AES_CR_DMAOUTEN_Pos)                /*!< 0x00001000 */
#define AES_CR_DMAOUTEN          AES_CR_DMAOUTEN_Msk                           /*!< Enable data output phase DMA management */

#define AES_CR_GCMPH_Pos         (13U)
#define AES_CR_GCMPH_Msk         (0x3UL << AES_CR_GCMPH_Pos)                   /*!< 0x00006000 */
#define AES_CR_GCMPH             AES_CR_GCMPH_Msk                              /*!< GCM Phase */
#define AES_CR_GCMPH_0           (0x1U << AES_CR_GCMPH_Pos)                    /*!< 0x00002000 */
#define AES_CR_GCMPH_1           (0x2U << AES_CR_GCMPH_Pos)                    /*!< 0x00004000 */

#define AES_CR_KEYSIZE_Pos       (18U)
#define AES_CR_KEYSIZE_Msk       (0x1UL << AES_CR_KEYSIZE_Pos)                 /*!< 0x00040000 */
#define AES_CR_KEYSIZE           AES_CR_KEYSIZE_Msk                            /*!< Key size selection */

#define AES_CR_NPBLB_Pos         (20U)
#define AES_CR_NPBLB_Msk         (0xFUL << AES_CR_NPBLB_Pos)                   /*!< 0x00F00000 */
#define AES_CR_NPBLB             AES_CR_NPBLB_Msk                              /*!< Number of padding bytes in last payload block */
#define AES_CR_NPBLB_0           (0x1U << AES_CR_NPBLB_Pos)                    /*!< 0x00100000 */
#define AES_CR_NPBLB_1           (0x2U << AES_CR_NPBLB_Pos)                    /*!< 0x00200000 */
#define AES_CR_NPBLB_2           (0x4U << AES_CR_NPBLB_Pos)                    /*!< 0x00400000 */
#define AES_CR_NPBLB_3           (0x8U << AES_CR_NPBLB_Pos)                    /*!< 0x00800000 */

/*******************  Bit definition for AES_SR register  *********************/
#define AES_SR_CCF_Pos           (0U)
#define AES_SR_CCF_Msk           (0x1UL << AES_SR_CCF_Pos)                     /*!< 0x00000001 */
#define AES_SR_CCF               AES_SR_CCF_Msk                                /*!< Computation Complete Flag */
#define AES_SR_RDERR_Pos         (1U)
#define AES_SR_RDERR_Msk         (0x1UL << AES_SR_RDERR_Pos)                   /*!< 0x00000002 */
#define AES_SR_RDERR             AES_SR_RDERR_Msk                              /*!< Read Error Flag */
#define AES_SR_WRERR_Pos         (2U)
#define AES_SR_WRERR_Msk         (0x1UL << AES_SR_WRERR_Pos)                   /*!< 0x00000004 */
#define AES_SR_WRERR             AES_SR_WRERR_Msk                              /*!< Write Error Flag */
#define AES_SR_BUSY_Pos          (3U)
#define AES_SR_BUSY_Msk          (0x1UL << AES_SR_BUSY_Pos)                    /*!< 0x00000008 */
#define AES_SR_BUSY              AES_SR_BUSY_Msk                               /*!< Busy Flag */

/*******************  Bit definition for AES_DINR register  *******************/
#define AES_DINR_Pos             (0U)
#define AES_DINR_Msk             (0xFFFFFFFFUL << AES_DINR_Pos)                /*!< 0xFFFFFFFF */
#define AES_DINR                 AES_DINR_Msk                                  /*!< AES Data Input Register */

/*******************  Bit definition for AES_DOUTR register  ******************/
#define AES_DOUTR_Pos            (0U)
#define AES_DOUTR_Msk            (0xFFFFFFFFUL << AES_DOUTR_Pos)               /*!< 0xFFFFFFFF */
#define AES_DOUTR                AES_DOUTR_Msk                                 /*!< AES Data Output Register */

/*******************  Bit definition for AES_KEYR0 register  ******************/
#define AES_KEYR0_Pos            (0U)
#define AES_KEYR0_Msk            (0xFFFFFFFFUL << AES_KEYR0_Pos)               /*!< 0xFFFFFFFF */
#define AES_KEYR0                AES_KEYR0_Msk                                 /*!< AES Key Register 0 */

/*******************  Bit definition for AES_KEYR1 register  ******************/
#define AES_KEYR1_Pos            (0U)
#define AES_KEYR1_Msk            (0xFFFFFFFFUL << AES_KEYR1_Pos)               /*!< 0xFFFFFFFF */
#define AES_KEYR1                AES_KEYR1_Msk                                 /*!< AES Key Register 1 */

/*******************  Bit definition for AES_KEYR2 register  ******************/
#define AES_KEYR2_Pos            (0U)
#define AES_KEYR2_Msk            (0xFFFFFFFFUL << AES_KEYR2_Pos)               /*!< 0xFFFFFFFF */
#define AES_KEYR2                AES_KEYR2_Msk                                 /*!< AES Key Register 2 */

/*******************  Bit definition for AES_KEYR3 register  ******************/
#define AES_KEYR3_Pos            (0U)
#define AES_KEYR3_Msk            (0xFFFFFFFFUL << AES_KEYR3_Pos)               /*!< 0xFFFFFFFF */
#define AES_KEYR3                AES_KEYR3_Msk                                 /*!< AES Key Register 3 */

/*******************  Bit definition for AES_KEYR4 register  ******************/
#define AES_KEYR4_Pos            (0U)
#define AES_KEYR4_Msk            (0xFFFFFFFFUL << AES_KEYR4_Pos)               /*!< 0xFFFFFFFF */
#define AES_KEYR4                AES_KEYR4_Msk                                 /*!< AES Key Register 4 */

/*******************  Bit definition for AES_KEYR5 register  ******************/
#define AES_KEYR5_Pos            (0U)
#define AES_KEYR5_Msk            (0xFFFFFFFFUL << AES_KEYR5_Pos)               /*!< 0xFFFFFFFF */
#define AES_KEYR5                AES_KEYR5_Msk                                 /*!< AES Key Register 5 */

/*******************  Bit definition for AES_KEYR6 register  ******************/
#define AES_KEYR6_Pos            (0U)
#define AES_KEYR6_Msk            (0xFFFFFFFFUL << AES_KEYR6_Pos)               /*!< 0xFFFFFFFF */
#define AES_KEYR6                AES_KEYR6_Msk                                 /*!< AES Key Register 6 */

/*******************  Bit definition for AES_KEYR7 register  ******************/
#define AES_KEYR7_Pos            (0U)
#define AES_KEYR7_Msk            (0xFFFFFFFFUL << AES_KEYR7_Pos)               /*!< 0xFFFFFFFF */
#define AES_KEYR7                AES_KEYR7_Msk                                 /*!< AES Key Register 7 */

/*******************  Bit definition for AES_IVR0 register   ******************/
#define AES_IVR0_Pos             (0U)
#define AES_IVR0_Msk             (0xFFFFFFFFUL << AES_IVR0_Pos)                /*!< 0xFFFFFFFF */
#define AES_IVR0                 AES_IVR0_Msk                                  /*!< AES Initialization Vector Register 0 */

/*******************  Bit definition for AES_IVR1 register   ******************/
#define AES_IVR1_Pos             (0U)
#define AES_IVR1_Msk             (0xFFFFFFFFUL << AES_IVR1_Pos)                /*!< 0xFFFFFFFF */
#define AES_IVR1                 AES_IVR1_Msk                                  /*!< AES Initialization Vector Register 1 */

/*******************  Bit definition for AES_IVR2 register   ******************/
#define AES_IVR2_Pos             (0U)
#define AES_IVR2_Msk             (0xFFFFFFFFUL << AES_IVR2_Pos)                /*!< 0xFFFFFFFF */
#define AES_IVR2                 AES_IVR2_Msk                                  /*!< AES Initialization Vector Register 2 */

/*******************  Bit definition for AES_IVR3 register   ******************/
#define AES_IVR3_Pos             (0U)
#define AES_IVR3_Msk             (0xFFFFFFFFUL << AES_IVR3_Pos)                /*!< 0xFFFFFFFF */
#define AES_IVR3                 AES_IVR3_Msk                                  /*!< AES Initialization Vector Register 3 */

/*******************  Bit definition for AES_SUSP0R register  ******************/
#define AES_SUSP0R_Pos           (0U)
#define AES_SUSP0R_Msk           (0xFFFFFFFFUL << AES_SUSP0R_Pos)              /*!< 0xFFFFFFFF */
#define AES_SUSP0R               AES_SUSP0R_Msk                                /*!< AES Suspend registers 0 */

/*******************  Bit definition for AES_SUSP1R register  ******************/
#define AES_SUSP1R_Pos           (0U)
#define AES_SUSP1R_Msk           (0xFFFFFFFFUL << AES_SUSP1R_Pos)              /*!< 0xFFFFFFFF */
#define AES_SUSP1R               AES_SUSP1R_Msk                                /*!< AES Suspend registers 1 */

/*******************  Bit definition for AES_SUSP2R register  ******************/
#define AES_SUSP2R_Pos           (0U)
#define AES_SUSP2R_Msk           (0xFFFFFFFFUL << AES_SUSP2R_Pos)              /*!< 0xFFFFFFFF */
#define AES_SUSP2R               AES_SUSP2R_Msk                                /*!< AES Suspend registers 2 */

/*******************  Bit definition for AES_SUSP3R register  ******************/
#define AES_SUSP3R_Pos           (0U)
#define AES_SUSP3R_Msk           (0xFFFFFFFFUL << AES_SUSP3R_Pos)              /*!< 0xFFFFFFFF */
#define AES_SUSP3R               AES_SUSP3R_Msk                                /*!< AES Suspend registers 3 */

/*******************  Bit definition for AES_SUSP4R register  ******************/
#define AES_SUSP4R_Pos           (0U)
#define AES_SUSP4R_Msk           (0xFFFFFFFFUL << AES_SUSP4R_Pos)              /*!< 0xFFFFFFFF */
#define AES_SUSP4R               AES_SUSP4R_Msk                                /*!< AES Suspend registers 4 */

/*******************  Bit definition for AES_SUSP5R register  ******************/
#define AES_SUSP5R_Pos           (0U)
#define AES_SUSP5R_Msk           (0xFFFFFFFFUL << AES_SUSP5R_Pos)              /*!< 0xFFFFFFFF */
#define AES_SUSP5R               AES_SUSP5R_Msk                                /*!< AES Suspend registers 5 */

/*******************  Bit definition for AES_SUSP6R register  ******************/
#define AES_SUSP6R_Pos           (0U)
#define AES_SUSP6R_Msk           (0xFFFFFFFFUL << AES_SUSP6R_Pos)              /*!< 0xFFFFFFFF */
#define AES_SUSP6R               AES_SUSP6R_Msk                                /*!< AES Suspend registers 6 */

/*******************  Bit definition for AES_SUSP7R register  ******************/
#define AES_SUSP7R_Pos           (0U)
#define AES_SUSP7R_Msk           (0xFFFFFFFFUL << AES_SUSP7R_Pos)              /*!< 0xFFFFFFFF */
#define AES_SUSP7R               AES_SUSP7R_Msk                                /*!< AES Suspend registers 7 */

/******************************************************************************/
/*                                                                            */
/*                           DMA Controller (DMA)                             */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for DMA_ISR register  ********************/
#define DMA_ISR_GIF1_Pos       (0U)
#define DMA_ISR_GIF1_Msk       (0x1UL << DMA_ISR_GIF1_Pos)                     /*!< 0x00000001 */
#define DMA_ISR_GIF1           DMA_ISR_GIF1_Msk                                /*!< Channel 1 Global interrupt flag */
#define DMA_ISR_TCIF1_Pos      (1U)
#define DMA_ISR_TCIF1_Msk      (0x1UL << DMA_ISR_TCIF1_Pos)                    /*!< 0x00000002 */
#define DMA_ISR_TCIF1          DMA_ISR_TCIF1_Msk                               /*!< Channel 1 Transfer Complete flag */
#define DMA_ISR_HTIF1_Pos      (2U)
#define DMA_ISR_HTIF1_Msk      (0x1UL << DMA_ISR_HTIF1_Pos)                    /*!< 0x00000004 */
#define DMA_ISR_HTIF1          DMA_ISR_HTIF1_Msk                               /*!< Channel 1 Half Transfer flag */
#define DMA_ISR_TEIF1_Pos      (3U)
#define DMA_ISR_TEIF1_Msk      (0x1UL << DMA_ISR_TEIF1_Pos)                    /*!< 0x00000008 */
#define DMA_ISR_TEIF1          DMA_ISR_TEIF1_Msk                               /*!< Channel 1 Transfer Error flag */
#define DMA_ISR_GIF2_Pos       (4U)
#define DMA_ISR_GIF2_Msk       (0x1UL << DMA_ISR_GIF2_Pos)                     /*!< 0x00000010 */
#define DMA_ISR_GIF2           DMA_ISR_GIF2_Msk                                /*!< Channel 2 Global interrupt flag */
#define DMA_ISR_TCIF2_Pos      (5U)
#define DMA_ISR_TCIF2_Msk      (0x1UL << DMA_ISR_TCIF2_Pos)                    /*!< 0x00000020 */
#define DMA_ISR_TCIF2          DMA_ISR_TCIF2_Msk                               /*!< Channel 2 Transfer Complete flag */
#define DMA_ISR_HTIF2_Pos      (6U)
#define DMA_ISR_HTIF2_Msk      (0x1UL << DMA_ISR_HTIF2_Pos)                    /*!< 0x00000040 */
#define DMA_ISR_HTIF2          DMA_ISR_HTIF2_Msk                               /*!< Channel 2 Half Transfer flag */
#define DMA_ISR_TEIF2_Pos      (7U)
#define DMA_ISR_TEIF2_Msk      (0x1UL << DMA_ISR_TEIF2_Pos)                    /*!< 0x00000080 */
#define DMA_ISR_TEIF2          DMA_ISR_TEIF2_Msk                               /*!< Channel 2 Transfer Error flag */
#define DMA_ISR_GIF3_Pos       (8U)
#define DMA_ISR_GIF3_Msk       (0x1UL << DMA_ISR_GIF3_Pos)                     /*!< 0x00000100 */
#define DMA_ISR_GIF3           DMA_ISR_GIF3_Msk                                /*!< Channel 3 Global interrupt flag */
#define DMA_ISR_TCIF3_Pos      (9U)
#define DMA_ISR_TCIF3_Msk      (0x1UL << DMA_ISR_TCIF3_Pos)                    /*!< 0x00000200 */
#define DMA_ISR_TCIF3          DMA_ISR_TCIF3_Msk                               /*!< Channel 3 Transfer Complete flag */
#define DMA_ISR_HTIF3_Pos      (10U)
#define DMA_ISR_HTIF3_Msk      (0x1UL << DMA_ISR_HTIF3_Pos)                    /*!< 0x00000400 */
#define DMA_ISR_HTIF3          DMA_ISR_HTIF3_Msk                               /*!< Channel 3 Half Transfer flag */
#define DMA_ISR_TEIF3_Pos      (11U)
#define DMA_ISR_TEIF3_Msk      (0x1UL << DMA_ISR_TEIF3_Pos)                    /*!< 0x00000800 */
#define DMA_ISR_TEIF3          DMA_ISR_TEIF3_Msk                               /*!< Channel 3 Transfer Error flag */
#define DMA_ISR_GIF4_Pos       (12U)
#define DMA_ISR_GIF4_Msk       (0x1UL << DMA_ISR_GIF4_Pos)                     /*!< 0x00001000 */
#define DMA_ISR_GIF4           DMA_ISR_GIF4_Msk                                /*!< Channel 4 Global interrupt flag */
#define DMA_ISR_TCIF4_Pos      (13U)
#define DMA_ISR_TCIF4_Msk      (0x1UL << DMA_ISR_TCIF4_Pos)                    /*!< 0x00002000 */
#define DMA_ISR_TCIF4          DMA_ISR_TCIF4_Msk                               /*!< Channel 4 Transfer Complete flag */
#define DMA_ISR_HTIF4_Pos      (14U)
#define DMA_ISR_HTIF4_Msk      (0x1UL << DMA_ISR_HTIF4_Pos)                    /*!< 0x00004000 */
#define DMA_ISR_HTIF4          DMA_ISR_HTIF4_Msk                               /*!< Channel 4 Half Transfer flag */
#define DMA_ISR_TEIF4_Pos      (15U)
#define DMA_ISR_TEIF4_Msk      (0x1UL << DMA_ISR_TEIF4_Pos)                    /*!< 0x00008000 */
#define DMA_ISR_TEIF4          DMA_ISR_TEIF4_Msk                               /*!< Channel 4 Transfer Error flag */
#define DMA_ISR_GIF5_Pos       (16U)
#define DMA_ISR_GIF5_Msk       (0x1UL << DMA_ISR_GIF5_Pos)                     /*!< 0x00010000 */
#define DMA_ISR_GIF5           DMA_ISR_GIF5_Msk                                /*!< Channel 5 Global interrupt flag */
#define DMA_ISR_TCIF5_Pos      (17U)
#define DMA_ISR_TCIF5_Msk      (0x1UL << DMA_ISR_TCIF5_Pos)                    /*!< 0x00020000 */
#define DMA_ISR_TCIF5          DMA_ISR_TCIF5_Msk                               /*!< Channel 5 Transfer Complete flag */
#define DMA_ISR_HTIF5_Pos      (18U)
#define DMA_ISR_HTIF5_Msk      (0x1UL << DMA_ISR_HTIF5_Pos)                    /*!< 0x00040000 */
#define DMA_ISR_HTIF5          DMA_ISR_HTIF5_Msk                               /*!< Channel 5 Half Transfer flag */
#define DMA_ISR_TEIF5_Pos      (19U)
#define DMA_ISR_TEIF5_Msk      (0x1UL << DMA_ISR_TEIF5_Pos)                    /*!< 0x00080000 */
#define DMA_ISR_TEIF5          DMA_ISR_TEIF5_Msk                               /*!< Channel 5 Transfer Error flag */
#define DMA_ISR_GIF6_Pos       (20U)
#define DMA_ISR_GIF6_Msk       (0x1UL << DMA_ISR_GIF6_Pos)                     /*!< 0x00100000 */
#define DMA_ISR_GIF6           DMA_ISR_GIF6_Msk                                /*!< Channel 6 Global interrupt flag */
#define DMA_ISR_TCIF6_Pos      (21U)
#define DMA_ISR_TCIF6_Msk      (0x1UL << DMA_ISR_TCIF6_Pos)                    /*!< 0x00200000 */
#define DMA_ISR_TCIF6          DMA_ISR_TCIF6_Msk                               /*!< Channel 6 Transfer Complete flag */
#define DMA_ISR_HTIF6_Pos      (22U)
#define DMA_ISR_HTIF6_Msk      (0x1UL << DMA_ISR_HTIF6_Pos)                    /*!< 0x00400000 */
#define DMA_ISR_HTIF6          DMA_ISR_HTIF6_Msk                               /*!< Channel 6 Half Transfer flag */
#define DMA_ISR_TEIF6_Pos      (23U)
#define DMA_ISR_TEIF6_Msk      (0x1UL << DMA_ISR_TEIF6_Pos)                    /*!< 0x00800000 */
#define DMA_ISR_TEIF6          DMA_ISR_TEIF6_Msk                               /*!< Channel 6 Transfer Error flag */
#define DMA_ISR_GIF7_Pos       (24U)
#define DMA_ISR_GIF7_Msk       (0x1UL << DMA_ISR_GIF7_Pos)                     /*!< 0x01000000 */
#define DMA_ISR_GIF7           DMA_ISR_GIF7_Msk                                /*!< Channel 7 Global interrupt flag */
#define DMA_ISR_TCIF7_Pos      (25U)
#define DMA_ISR_TCIF7_Msk      (0x1UL << DMA_ISR_TCIF7_Pos)                    /*!< 0x02000000 */
#define DMA_ISR_TCIF7          DMA_ISR_TCIF7_Msk                               /*!< Channel 7 Transfer Complete flag */
#define DMA_ISR_HTIF7_Pos      (26U)
#define DMA_ISR_HTIF7_Msk      (0x1UL << DMA_ISR_HTIF7_Pos)                    /*!< 0x04000000 */
#define DMA_ISR_HTIF7          DMA_ISR_HTIF7_Msk                               /*!< Channel 7 Half Transfer flag */
#define DMA_ISR_TEIF7_Pos      (27U)
#define DMA_ISR_TEIF7_Msk      (0x1UL << DMA_ISR_TEIF7_Pos)                    /*!< 0x08000000 */
#define DMA_ISR_TEIF7          DMA_ISR_TEIF7_Msk                               /*!< Channel 7 Transfer Error flag */

/*******************  Bit definition for DMA_IFCR register  *******************/
#define DMA_IFCR_CGIF1_Pos     (0U)
#define DMA_IFCR_CGIF1_Msk     (0x1UL << DMA_IFCR_CGIF1_Pos)                   /*!< 0x00000001 */
#define DMA_IFCR_CGIF1         DMA_IFCR_CGIF1_Msk                              /*!< Channel 1 Global interrupt clear */
#define DMA_IFCR_CTCIF1_Pos    (1U)
#define DMA_IFCR_CTCIF1_Msk    (0x1UL << DMA_IFCR_CTCIF1_Pos)                  /*!< 0x00000002 */
#define DMA_IFCR_CTCIF1        DMA_IFCR_CTCIF1_Msk                             /*!< Channel 1 Transfer Complete clear */
#define DMA_IFCR_CHTIF1_Pos    (2U)
#define DMA_IFCR_CHTIF1_Msk    (0x1UL << DMA_IFCR_CHTIF1_Pos)                  /*!< 0x00000004 */
#define DMA_IFCR_CHTIF1        DMA_IFCR_CHTIF1_Msk                             /*!< Channel 1 Half Transfer clear */
#define DMA_IFCR_CTEIF1_Pos    (3U)
#define DMA_IFCR_CTEIF1_Msk    (0x1UL << DMA_IFCR_CTEIF1_Pos)                  /*!< 0x00000008 */
#define DMA_IFCR_CTEIF1        DMA_IFCR_CTEIF1_Msk                             /*!< Channel 1 Transfer Error clear */
#define DMA_IFCR_CGIF2_Pos     (4U)
#define DMA_IFCR_CGIF2_Msk     (0x1UL << DMA_IFCR_CGIF2_Pos)                   /*!< 0x00000010 */
#define DMA_IFCR_CGIF2         DMA_IFCR_CGIF2_Msk                              /*!< Channel 2 Global interrupt clear */
#define DMA_IFCR_CTCIF2_Pos    (5U)
#define DMA_IFCR_CTCIF2_Msk    (0x1UL << DMA_IFCR_CTCIF2_Pos)                  /*!< 0x00000020 */
#define DMA_IFCR_CTCIF2        DMA_IFCR_CTCIF2_Msk                             /*!< Channel 2 Transfer Complete clear */
#define DMA_IFCR_CHTIF2_Pos    (6U)
#define DMA_IFCR_CHTIF2_Msk    (0x1UL << DMA_IFCR_CHTIF2_Pos)                  /*!< 0x00000040 */
#define DMA_IFCR_CHTIF2        DMA_IFCR_CHTIF2_Msk                             /*!< Channel 2 Half Transfer clear */
#define DMA_IFCR_CTEIF2_Pos    (7U)
#define DMA_IFCR_CTEIF2_Msk    (0x1UL << DMA_IFCR_CTEIF2_Pos)                  /*!< 0x00000080 */
#define DMA_IFCR_CTEIF2        DMA_IFCR_CTEIF2_Msk                             /*!< Channel 2 Transfer Error clear */
#define DMA_IFCR_CGIF3_Pos     (8U)
#define DMA_IFCR_CGIF3_Msk     (0x1UL << DMA_IFCR_CGIF3_Pos)                   /*!< 0x00000100 */
#define DMA_IFCR_CGIF3         DMA_IFCR_CGIF3_Msk                              /*!< Channel 3 Global interrupt clear */
#define DMA_IFCR_CTCIF3_Pos    (9U)
#define DMA_IFCR_CTCIF3_Msk    (0x1UL << DMA_IFCR_CTCIF3_Pos)                  /*!< 0x00000200 */
#define DMA_IFCR_CTCIF3        DMA_IFCR_CTCIF3_Msk                             /*!< Channel 3 Transfer Complete clear */
#define DMA_IFCR_CHTIF3_Pos    (10U)
#define DMA_IFCR_CHTIF3_Msk    (0x1UL << DMA_IFCR_CHTIF3_Pos)                  /*!< 0x00000400 */
#define DMA_IFCR_CHTIF3        DMA_IFCR_CHTIF3_Msk                             /*!< Channel 3 Half Transfer clear */
#define DMA_IFCR_CTEIF3_Pos    (11U)
#define DMA_IFCR_CTEIF3_Msk    (0x1UL << DMA_IFCR_CTEIF3_Pos)                  /*!< 0x00000800 */
#define DMA_IFCR_CTEIF3        DMA_IFCR_CTEIF3_Msk                             /*!< Channel 3 Transfer Error clear */
#define DMA_IFCR_CGIF4_Pos     (12U)
#define DMA_IFCR_CGIF4_Msk     (0x1UL << DMA_IFCR_CGIF4_Pos)                   /*!< 0x00001000 */
#define DMA_IFCR_CGIF4         DMA_IFCR_CGIF4_Msk                              /*!< Channel 4 Global interrupt clear */
#define DMA_IFCR_CTCIF4_Pos    (13U)
#define DMA_IFCR_CTCIF4_Msk    (0x1UL << DMA_IFCR_CTCIF4_Pos)                  /*!< 0x00002000 */
#define DMA_IFCR_CTCIF4        DMA_IFCR_CTCIF4_Msk                             /*!< Channel 4 Transfer Complete clear */
#define DMA_IFCR_CHTIF4_Pos    (14U)
#define DMA_IFCR_CHTIF4_Msk    (0x1UL << DMA_IFCR_CHTIF4_Pos)                  /*!< 0x00004000 */
#define DMA_IFCR_CHTIF4        DMA_IFCR_CHTIF4_Msk                             /*!< Channel 4 Half Transfer clear */
#define DMA_IFCR_CTEIF4_Pos    (15U)
#define DMA_IFCR_CTEIF4_Msk    (0x1UL << DMA_IFCR_CTEIF4_Pos)                  /*!< 0x00008000 */
#define DMA_IFCR_CTEIF4        DMA_IFCR_CTEIF4_Msk                             /*!< Channel 4 Transfer Error clear */
#define DMA_IFCR_CGIF5_Pos     (16U)
#define DMA_IFCR_CGIF5_Msk     (0x1UL << DMA_IFCR_CGIF5_Pos)                   /*!< 0x00010000 */
#define DMA_IFCR_CGIF5         DMA_IFCR_CGIF5_Msk                              /*!< Channel 5 Global interrupt clear */
#define DMA_IFCR_CTCIF5_Pos    (17U)
#define DMA_IFCR_CTCIF5_Msk    (0x1UL << DMA_IFCR_CTCIF5_Pos)                  /*!< 0x00020000 */
#define DMA_IFCR_CTCIF5        DMA_IFCR_CTCIF5_Msk                             /*!< Channel 5 Transfer Complete clear */
#define DMA_IFCR_CHTIF5_Pos    (18U)
#define DMA_IFCR_CHTIF5_Msk    (0x1UL << DMA_IFCR_CHTIF5_Pos)                  /*!< 0x00040000 */
#define DMA_IFCR_CHTIF5        DMA_IFCR_CHTIF5_Msk                             /*!< Channel 5 Half Transfer clear */
#define DMA_IFCR_CTEIF5_Pos    (19U)
#define DMA_IFCR_CTEIF5_Msk    (0x1UL << DMA_IFCR_CTEIF5_Pos)                  /*!< 0x00080000 */
#define DMA_IFCR_CTEIF5        DMA_IFCR_CTEIF5_Msk                             /*!< Channel 5 Transfer Error clear */
#define DMA_IFCR_CGIF6_Pos     (20U)
#define DMA_IFCR_CGIF6_Msk     (0x1UL << DMA_IFCR_CGIF6_Pos)                   /*!< 0x00100000 */
#define DMA_IFCR_CGIF6         DMA_IFCR_CGIF6_Msk                              /*!< Channel 6 Global interrupt clear */
#define DMA_IFCR_CTCIF6_Pos    (21U)
#define DMA_IFCR_CTCIF6_Msk    (0x1UL << DMA_IFCR_CTCIF6_Pos)                  /*!< 0x00200000 */
#define DMA_IFCR_CTCIF6        DMA_IFCR_CTCIF6_Msk                             /*!< Channel 6 Transfer Complete clear */
#define DMA_IFCR_CHTIF6_Pos    (22U)
#define DMA_IFCR_CHTIF6_Msk    (0x1UL << DMA_IFCR_CHTIF6_Pos)                  /*!< 0x00400000 */
#define DMA_IFCR_CHTIF6        DMA_IFCR_CHTIF6_Msk                             /*!< Channel 6 Half Transfer clear */
#define DMA_IFCR_CTEIF6_Pos    (23U)
#define DMA_IFCR_CTEIF6_Msk    (0x1UL << DMA_IFCR_CTEIF6_Pos)                  /*!< 0x00800000 */
#define DMA_IFCR_CTEIF6        DMA_IFCR_CTEIF6_Msk                             /*!< Channel 6 Transfer Error clear */
#define DMA_IFCR_CGIF7_Pos     (24U)
#define DMA_IFCR_CGIF7_Msk     (0x1UL << DMA_IFCR_CGIF7_Pos)                   /*!< 0x01000000 */
#define DMA_IFCR_CGIF7         DMA_IFCR_CGIF7_Msk                              /*!< Channel 7 Global interrupt clear */
#define DMA_IFCR_CTCIF7_Pos    (25U)
#define DMA_IFCR_CTCIF7_Msk    (0x1UL << DMA_IFCR_CTCIF7_Pos)                  /*!< 0x02000000 */
#define DMA_IFCR_CTCIF7        DMA_IFCR_CTCIF7_Msk                             /*!< Channel 7 Transfer Complete clear */
#define DMA_IFCR_CHTIF7_Pos    (26U)
#define DMA_IFCR_CHTIF7_Msk    (0x1UL << DMA_IFCR_CHTIF7_Pos)                  /*!< 0x04000000 */
#define DMA_IFCR_CHTIF7        DMA_IFCR_CHTIF7_Msk                             /*!< Channel 7 Half Transfer clear */
#define DMA_IFCR_CTEIF7_Pos    (27U)
#define DMA_IFCR_CTEIF7_Msk    (0x1UL << DMA_IFCR_CTEIF7_Pos)                  /*!< 0x08000000 */
#define DMA_IFCR_CTEIF7        DMA_IFCR_CTEIF7_Msk                             /*!< Channel 7 Transfer Error clear */

/*******************  Bit definition for DMA_CCR register  ********************/
#define DMA_CCR_EN_Pos         (0U)
#define DMA_CCR_EN_Msk         (0x1UL << DMA_CCR_EN_Pos)                       /*!< 0x00000001 */
#define DMA_CCR_EN             DMA_CCR_EN_Msk                                  /*!< Channel enable                      */
#define DMA_CCR_TCIE_Pos       (1U)
#define DMA_CCR_TCIE_Msk       (0x1UL << DMA_CCR_TCIE_Pos)                     /*!< 0x00000002 */
#define DMA_CCR_TCIE           DMA_CCR_TCIE_Msk                                /*!< Transfer complete interrupt enable  */
#define DMA_CCR_HTIE_Pos       (2U)
#define DMA_CCR_HTIE_Msk       (0x1UL << DMA_CCR_HTIE_Pos)                     /*!< 0x00000004 */
#define DMA_CCR_HTIE           DMA_CCR_HTIE_Msk                                /*!< Half Transfer interrupt enable      */
#define DMA_CCR_TEIE_Pos       (3U)
#define DMA_CCR_TEIE_Msk       (0x1UL << DMA_CCR_TEIE_Pos)                     /*!< 0x00000008 */
#define DMA_CCR_TEIE           DMA_CCR_TEIE_Msk                                /*!< Transfer error interrupt enable     */
#define DMA_CCR_DIR_Pos        (4U)
#define DMA_CCR_DIR_Msk        (0x1UL << DMA_CCR_DIR_Pos)                      /*!< 0x00000010 */
#define DMA_CCR_DIR            DMA_CCR_DIR_Msk                                 /*!< Data transfer direction             */
#define DMA_CCR_CIRC_Pos       (5U)
#define DMA_CCR_CIRC_Msk       (0x1UL << DMA_CCR_CIRC_Pos)                     /*!< 0x00000020 */
#define DMA_CCR_CIRC           DMA_CCR_CIRC_Msk                                /*!< Circular mode                       */
#define DMA_CCR_PINC_Pos       (6U)
#define DMA_CCR_PINC_Msk       (0x1UL << DMA_CCR_PINC_Pos)                     /*!< 0x00000040 */
#define DMA_CCR_PINC           DMA_CCR_PINC_Msk                                /*!< Peripheral increment mode           */
#define DMA_CCR_MINC_Pos       (7U)
#define DMA_CCR_MINC_Msk       (0x1UL << DMA_CCR_MINC_Pos)                     /*!< 0x00000080 */
#define DMA_CCR_MINC           DMA_CCR_MINC_Msk                                /*!< Memory increment mode               */

#define DMA_CCR_PSIZE_Pos      (8U)
#define DMA_CCR_PSIZE_Msk      (0x3UL << DMA_CCR_PSIZE_Pos)                    /*!< 0x00000300 */
#define DMA_CCR_PSIZE          DMA_CCR_PSIZE_Msk                               /*!< PSIZE[1:0] bits (Peripheral size)   */
#define DMA_CCR_PSIZE_0        (0x1U << DMA_CCR_PSIZE_Pos)                     /*!< 0x00000100 */
#define DMA_CCR_PSIZE_1        (0x2U << DMA_CCR_PSIZE_Pos)                     /*!< 0x00000200 */

#define DMA_CCR_MSIZE_Pos      (10U)
#define DMA_CCR_MSIZE_Msk      (0x3UL << DMA_CCR_MSIZE_Pos)                    /*!< 0x00000C00 */
#define DMA_CCR_MSIZE          DMA_CCR_MSIZE_Msk                               /*!< MSIZE[1:0] bits (Memory size)       */
#define DMA_CCR_MSIZE_0        (0x1U << DMA_CCR_MSIZE_Pos)                     /*!< 0x00000400 */
#define DMA_CCR_MSIZE_1        (0x2U << DMA_CCR_MSIZE_Pos)                     /*!< 0x00000800 */

#define DMA_CCR_PL_Pos         (12U)
#define DMA_CCR_PL_Msk         (0x3UL << DMA_CCR_PL_Pos)                       /*!< 0x00003000 */
#define DMA_CCR_PL             DMA_CCR_PL_Msk                                  /*!< PL[1:0] bits(Channel Priority level)*/
#define DMA_CCR_PL_0           (0x1U << DMA_CCR_PL_Pos)                        /*!< 0x00001000 */
#define DMA_CCR_PL_1           (0x2U << DMA_CCR_PL_Pos)                        /*!< 0x00002000 */

#define DMA_CCR_MEM2MEM_Pos    (14U)
#define DMA_CCR_MEM2MEM_Msk    (0x1UL << DMA_CCR_MEM2MEM_Pos)                  /*!< 0x00004000 */
#define DMA_CCR_MEM2MEM        DMA_CCR_MEM2MEM_Msk                             /*!< Memory to memory mode               */

/******************  Bit definition for DMA_CNDTR register  *******************/
#define DMA_CNDTR_NDT_Pos      (0U)
#define DMA_CNDTR_NDT_Msk      (0xFFFFUL << DMA_CNDTR_NDT_Pos)                 /*!< 0x0000FFFF */
#define DMA_CNDTR_NDT          DMA_CNDTR_NDT_Msk                               /*!< Number of data to Transfer          */

/******************  Bit definition for DMA_CPAR register  ********************/
#define DMA_CPAR_PA_Pos        (0U)
#define DMA_CPAR_PA_Msk        (0xFFFFFFFFUL << DMA_CPAR_PA_Pos)               /*!< 0xFFFFFFFF */
#define DMA_CPAR_PA            DMA_CPAR_PA_Msk                                 /*!< Peripheral Address                  */

/******************  Bit definition for DMA_CMAR register  ********************/
#define DMA_CMAR_MA_Pos        (0U)
#define DMA_CMAR_MA_Msk        (0xFFFFFFFFUL << DMA_CMAR_MA_Pos)               /*!< 0xFFFFFFFF */
#define DMA_CMAR_MA            DMA_CMAR_MA_Msk                                 /*!< Memory Address                      */

/******************************************************************************/
/*                                                                            */
/*                             DMAMUX Controller                              */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DMAMUX_CxCR register  **************/
#define DMAMUX_CxCR_DMAREQ_ID_Pos              (0U)
#define DMAMUX_CxCR_DMAREQ_ID_Msk              (0x3FUL << DMAMUX_CxCR_DMAREQ_ID_Pos) /*!< 0x0000003F */
#define DMAMUX_CxCR_DMAREQ_ID                  DMAMUX_CxCR_DMAREQ_ID_Msk       /*!< DMA Request ID                       */
#define DMAMUX_CxCR_DMAREQ_ID_0                (0x01U << DMAMUX_CxCR_DMAREQ_ID_Pos) /*!< 0x00000001 */
#define DMAMUX_CxCR_DMAREQ_ID_1                (0x02U << DMAMUX_CxCR_DMAREQ_ID_Pos) /*!< 0x00000002 */
#define DMAMUX_CxCR_DMAREQ_ID_2                (0x04U << DMAMUX_CxCR_DMAREQ_ID_Pos) /*!< 0x00000004 */
#define DMAMUX_CxCR_DMAREQ_ID_3                (0x08U << DMAMUX_CxCR_DMAREQ_ID_Pos) /*!< 0x00000008 */
#define DMAMUX_CxCR_DMAREQ_ID_4                (0x10U << DMAMUX_CxCR_DMAREQ_ID_Pos) /*!< 0x00000010 */
#define DMAMUX_CxCR_DMAREQ_ID_5                (0x20U << DMAMUX_CxCR_DMAREQ_ID_Pos) /*!< 0x00000020 */
#define DMAMUX_CxCR_SOIE_Pos                   (8U)
#define DMAMUX_CxCR_SOIE_Msk                   (0x1UL << DMAMUX_CxCR_SOIE_Pos) /*!< 0x00000100 */
#define DMAMUX_CxCR_SOIE                       DMAMUX_CxCR_SOIE_Msk            /*!< Synchro overrun interrupt enable     */
#define DMAMUX_CxCR_EGE_Pos                    (9U)
#define DMAMUX_CxCR_EGE_Msk                    (0x1UL << DMAMUX_CxCR_EGE_Pos)  /*!< 0x00000200 */
#define DMAMUX_CxCR_EGE                        DMAMUX_CxCR_EGE_Msk             /*!< Event generation interrupt enable    */
#define DMAMUX_CxCR_SE_Pos                     (16U)
#define DMAMUX_CxCR_SE_Msk                     (0x1UL << DMAMUX_CxCR_SE_Pos)   /*!< 0x00010000 */
#define DMAMUX_CxCR_SE                         DMAMUX_CxCR_SE_Msk              /*!< Synchronization enable               */
#define DMAMUX_CxCR_SPOL_Pos                   (17U)
#define DMAMUX_CxCR_SPOL_Msk                   (0x3UL << DMAMUX_CxCR_SPOL_Pos) /*!< 0x00060000 */
#define DMAMUX_CxCR_SPOL                       DMAMUX_CxCR_SPOL_Msk            /*!< Synchronization polarity             */
#define DMAMUX_CxCR_SPOL_0                     (0x1U << DMAMUX_CxCR_SPOL_Pos)  /*!< 0x00020000 */
#define DMAMUX_CxCR_SPOL_1                     (0x2U << DMAMUX_CxCR_SPOL_Pos)  /*!< 0x00040000 */
#define DMAMUX_CxCR_NBREQ_Pos                  (19U)
#define DMAMUX_CxCR_NBREQ_Msk                  (0x1FUL << DMAMUX_CxCR_NBREQ_Pos) /*!< 0x00F80000 */
#define DMAMUX_CxCR_NBREQ                      DMAMUX_CxCR_NBREQ_Msk           /*!< Number of request                    */
#define DMAMUX_CxCR_NBREQ_0                    (0x01U << DMAMUX_CxCR_NBREQ_Pos) /*!< 0x00080000 */
#define DMAMUX_CxCR_NBREQ_1                    (0x02U << DMAMUX_CxCR_NBREQ_Pos) /*!< 0x00100000 */
#define DMAMUX_CxCR_NBREQ_2                    (0x04U << DMAMUX_CxCR_NBREQ_Pos) /*!< 0x00200000 */
#define DMAMUX_CxCR_NBREQ_3                    (0x08U << DMAMUX_CxCR_NBREQ_Pos) /*!< 0x00400000 */
#define DMAMUX_CxCR_NBREQ_4                    (0x10U << DMAMUX_CxCR_NBREQ_Pos) /*!< 0x00800000 */
#define DMAMUX_CxCR_SYNC_ID_Pos                (24U)
#define DMAMUX_CxCR_SYNC_ID_Msk                (0x1FUL << DMAMUX_CxCR_SYNC_ID_Pos) /*!< 0x1F000000 */
#define DMAMUX_CxCR_SYNC_ID                    DMAMUX_CxCR_SYNC_ID_Msk         /*!< Synchronization ID                   */
#define DMAMUX_CxCR_SYNC_ID_0                  (0x01U << DMAMUX_CxCR_SYNC_ID_Pos) /*!< 0x01000000 */
#define DMAMUX_CxCR_SYNC_ID_1                  (0x02U << DMAMUX_CxCR_SYNC_ID_Pos) /*!< 0x02000000 */
#define DMAMUX_CxCR_SYNC_ID_2                  (0x04U << DMAMUX_CxCR_SYNC_ID_Pos) /*!< 0x04000000 */
#define DMAMUX_CxCR_SYNC_ID_3                  (0x08U << DMAMUX_CxCR_SYNC_ID_Pos) /*!< 0x08000000 */
#define DMAMUX_CxCR_SYNC_ID_4                  (0x10U << DMAMUX_CxCR_SYNC_ID_Pos) /*!< 0x10000000 */

/*******************  Bits definition for DMAMUX_CSR register  **************/
#define DMAMUX_CSR_SOF0_Pos                    (0U)
#define DMAMUX_CSR_SOF0_Msk                    (0x1UL << DMAMUX_CSR_SOF0_Pos)  /*!< 0x00000001 */
#define DMAMUX_CSR_SOF0                        DMAMUX_CSR_SOF0_Msk             /*!< Synchronization Overrun Flag 0       */
#define DMAMUX_CSR_SOF1_Pos                    (1U)
#define DMAMUX_CSR_SOF1_Msk                    (0x1UL << DMAMUX_CSR_SOF1_Pos)  /*!< 0x00000002 */
#define DMAMUX_CSR_SOF1                        DMAMUX_CSR_SOF1_Msk             /*!< Synchronization Overrun Flag 1       */
#define DMAMUX_CSR_SOF2_Pos                    (2U)
#define DMAMUX_CSR_SOF2_Msk                    (0x1UL << DMAMUX_CSR_SOF2_Pos)  /*!< 0x00000004 */
#define DMAMUX_CSR_SOF2                        DMAMUX_CSR_SOF2_Msk             /*!< Synchronization Overrun Flag 2       */
#define DMAMUX_CSR_SOF3_Pos                    (3U)
#define DMAMUX_CSR_SOF3_Msk                    (0x1UL << DMAMUX_CSR_SOF3_Pos)  /*!< 0x00000008 */
#define DMAMUX_CSR_SOF3                        DMAMUX_CSR_SOF3_Msk             /*!< Synchronization Overrun Flag 3       */
#define DMAMUX_CSR_SOF4_Pos                    (4U)
#define DMAMUX_CSR_SOF4_Msk                    (0x1UL << DMAMUX_CSR_SOF4_Pos)  /*!< 0x00000010 */
#define DMAMUX_CSR_SOF4                        DMAMUX_CSR_SOF4_Msk             /*!< Synchronization Overrun Flag 4       */
#define DMAMUX_CSR_SOF5_Pos                    (5U)
#define DMAMUX_CSR_SOF5_Msk                    (0x1UL << DMAMUX_CSR_SOF5_Pos)  /*!< 0x00000020 */
#define DMAMUX_CSR_SOF5                        DMAMUX_CSR_SOF5_Msk             /*!< Synchronization Overrun Flag 5       */
#define DMAMUX_CSR_SOF6_Pos                    (6U)
#define DMAMUX_CSR_SOF6_Msk                    (0x1UL << DMAMUX_CSR_SOF6_Pos)  /*!< 0x00000040 */
#define DMAMUX_CSR_SOF6                        DMAMUX_CSR_SOF6_Msk             /*!< Synchronization Overrun Flag 6       */

/********************  Bits definition for DMAMUX_CFR register  **************/
#define DMAMUX_CFR_CSOF0_Pos                   (0U)
#define DMAMUX_CFR_CSOF0_Msk                   (0x1UL << DMAMUX_CFR_CSOF0_Pos) /*!< 0x00000001 */
#define DMAMUX_CFR_CSOF0                       DMAMUX_CFR_CSOF0_Msk            /*!< Clear Overrun Flag 0                 */
#define DMAMUX_CFR_CSOF1_Pos                   (1U)
#define DMAMUX_CFR_CSOF1_Msk                   (0x1UL << DMAMUX_CFR_CSOF1_Pos) /*!< 0x00000002 */
#define DMAMUX_CFR_CSOF1                       DMAMUX_CFR_CSOF1_Msk            /*!< Clear Overrun Flag 1                 */
#define DMAMUX_CFR_CSOF2_Pos                   (2U)
#define DMAMUX_CFR_CSOF2_Msk                   (0x1UL << DMAMUX_CFR_CSOF2_Pos) /*!< 0x00000004 */
#define DMAMUX_CFR_CSOF2                       DMAMUX_CFR_CSOF2_Msk            /*!< Clear Overrun Flag 2                 */
#define DMAMUX_CFR_CSOF3_Pos                   (3U)
#define DMAMUX_CFR_CSOF3_Msk                   (0x1UL << DMAMUX_CFR_CSOF3_Pos) /*!< 0x00000008 */
#define DMAMUX_CFR_CSOF3                       DMAMUX_CFR_CSOF3_Msk            /*!< Clear Overrun Flag 3                 */
#define DMAMUX_CFR_CSOF4_Pos                   (4U)
#define DMAMUX_CFR_CSOF4_Msk                   (0x1UL << DMAMUX_CFR_CSOF4_Pos) /*!< 0x00000010 */
#define DMAMUX_CFR_CSOF4                       DMAMUX_CFR_CSOF4_Msk            /*!< Clear Overrun Flag 4                 */
#define DMAMUX_CFR_CSOF5_Pos                   (5U)
#define DMAMUX_CFR_CSOF5_Msk                   (0x1UL << DMAMUX_CFR_CSOF5_Pos) /*!< 0x00000020 */
#define DMAMUX_CFR_CSOF5                       DMAMUX_CFR_CSOF5_Msk            /*!< Clear Overrun Flag 5                 */
#define DMAMUX_CFR_CSOF6_Pos                   (6U)
#define DMAMUX_CFR_CSOF6_Msk                   (0x1UL << DMAMUX_CFR_CSOF6_Pos) /*!< 0x00000040 */
#define DMAMUX_CFR_CSOF6                       DMAMUX_CFR_CSOF6_Msk            /*!< Clear Overrun Flag 6                 */

/********************  Bits definition for DMAMUX_RGxCR register  ************/
#define DMAMUX_RGxCR_SIG_ID_Pos                (0U)
#define DMAMUX_RGxCR_SIG_ID_Msk                (0x1FUL << DMAMUX_RGxCR_SIG_ID_Pos) /*!< 0x0000001F */
#define DMAMUX_RGxCR_SIG_ID                    DMAMUX_RGxCR_SIG_ID_Msk         /*!< Signal ID                            */
#define DMAMUX_RGxCR_SIG_ID_0                  (0x01U << DMAMUX_RGxCR_SIG_ID_Pos) /*!< 0x00000001 */
#define DMAMUX_RGxCR_SIG_ID_1                  (0x02U << DMAMUX_RGxCR_SIG_ID_Pos) /*!< 0x00000002 */
#define DMAMUX_RGxCR_SIG_ID_2                  (0x04U << DMAMUX_RGxCR_SIG_ID_Pos) /*!< 0x00000004 */
#define DMAMUX_RGxCR_SIG_ID_3                  (0x08U << DMAMUX_RGxCR_SIG_ID_Pos) /*!< 0x00000008 */
#define DMAMUX_RGxCR_SIG_ID_4                  (0x10U << DMAMUX_RGxCR_SIG_ID_Pos) /*!< 0x00000010 */
#define DMAMUX_RGxCR_OIE_Pos                   (8U)
#define DMAMUX_RGxCR_OIE_Msk                   (0x1UL << DMAMUX_RGxCR_OIE_Pos) /*!< 0x00000100 */
#define DMAMUX_RGxCR_OIE                       DMAMUX_RGxCR_OIE_Msk            /*!< Overrun interrupt enable             */
#define DMAMUX_RGxCR_GE_Pos                    (16U)
#define DMAMUX_RGxCR_GE_Msk                    (0x1UL << DMAMUX_RGxCR_GE_Pos)  /*!< 0x00010000 */
#define DMAMUX_RGxCR_GE                        DMAMUX_RGxCR_GE_Msk             /*!< Generation enable                    */
#define DMAMUX_RGxCR_GPOL_Pos                  (17U)
#define DMAMUX_RGxCR_GPOL_Msk                  (0x3UL << DMAMUX_RGxCR_GPOL_Pos) /*!< 0x00060000 */
#define DMAMUX_RGxCR_GPOL                      DMAMUX_RGxCR_GPOL_Msk           /*!< Generation polarity                  */
#define DMAMUX_RGxCR_GPOL_0                    (0x1U << DMAMUX_RGxCR_GPOL_Pos) /*!< 0x00020000 */
#define DMAMUX_RGxCR_GPOL_1                    (0x2U << DMAMUX_RGxCR_GPOL_Pos) /*!< 0x00040000 */
#define DMAMUX_RGxCR_GNBREQ_Pos                (19U)
#define DMAMUX_RGxCR_GNBREQ_Msk                (0x1FUL << DMAMUX_RGxCR_GNBREQ_Pos) /*!< 0x00F80000 */
#define DMAMUX_RGxCR_GNBREQ                    DMAMUX_RGxCR_GNBREQ_Msk          /*!< Number of request                    */
#define DMAMUX_RGxCR_GNBREQ_0                  (0x01U << DMAMUX_RGxCR_GNBREQ_Pos) /*!< 0x00080000 */
#define DMAMUX_RGxCR_GNBREQ_1                  (0x02U << DMAMUX_RGxCR_GNBREQ_Pos) /*!< 0x00100000 */
#define DMAMUX_RGxCR_GNBREQ_2                  (0x04U << DMAMUX_RGxCR_GNBREQ_Pos) /*!< 0x00200000 */
#define DMAMUX_RGxCR_GNBREQ_3                  (0x08U << DMAMUX_RGxCR_GNBREQ_Pos) /*!< 0x00400000 */
#define DMAMUX_RGxCR_GNBREQ_4                  (0x10U << DMAMUX_RGxCR_GNBREQ_Pos) /*!< 0x00800000 */

/********************  Bits definition for DMAMUX_RGSR register  **************/
#define DMAMUX_RGSR_OF0_Pos                    (0U)
#define DMAMUX_RGSR_OF0_Msk                    (0x1UL << DMAMUX_RGSR_OF0_Pos)  /*!< 0x00000001 */
#define DMAMUX_RGSR_OF0                        DMAMUX_RGSR_OF0_Msk             /*!< Overrun flag 0                       */
#define DMAMUX_RGSR_OF1_Pos                    (1U)
#define DMAMUX_RGSR_OF1_Msk                    (0x1UL << DMAMUX_RGSR_OF1_Pos)  /*!< 0x00000002 */
#define DMAMUX_RGSR_OF1                        DMAMUX_RGSR_OF1_Msk             /*!< Overrun flag 1                       */
#define DMAMUX_RGSR_OF2_Pos                    (2U)
#define DMAMUX_RGSR_OF2_Msk                    (0x1UL << DMAMUX_RGSR_OF2_Pos)  /*!< 0x00000004 */
#define DMAMUX_RGSR_OF2                        DMAMUX_RGSR_OF2_Msk             /*!< Overrun flag 2                       */
#define DMAMUX_RGSR_OF3_Pos                    (3U)
#define DMAMUX_RGSR_OF3_Msk                    (0x1UL << DMAMUX_RGSR_OF3_Pos)  /*!< 0x00000008 */
#define DMAMUX_RGSR_OF3                        DMAMUX_RGSR_OF3_Msk             /*!< Overrun flag 3                       */

/********************  Bits definition for DMAMUX_RGCFR register  **************/
#define DMAMUX_RGCFR_COF0_Pos                  (0U)
#define DMAMUX_RGCFR_COF0_Msk                  (0x1UL << DMAMUX_RGCFR_COF0_Pos) /*!< 0x00000001 */
#define DMAMUX_RGCFR_COF0                      DMAMUX_RGCFR_COF0_Msk           /*!< Clear Overrun flag 0                 */
#define DMAMUX_RGCFR_COF1_Pos                  (1U)
#define DMAMUX_RGCFR_COF1_Msk                  (0x1UL << DMAMUX_RGCFR_COF1_Pos) /*!< 0x00000002 */
#define DMAMUX_RGCFR_COF1                      DMAMUX_RGCFR_COF1_Msk           /*!< Clear Overrun flag 1                 */
#define DMAMUX_RGCFR_COF2_Pos                  (2U)
#define DMAMUX_RGCFR_COF2_Msk                  (0x1UL << DMAMUX_RGCFR_COF2_Pos) /*!< 0x00000004 */
#define DMAMUX_RGCFR_COF2                      DMAMUX_RGCFR_COF2_Msk           /*!< Clear Overrun flag 2                 */
#define DMAMUX_RGCFR_COF3_Pos                  (3U)
#define DMAMUX_RGCFR_COF3_Msk                  (0x1UL << DMAMUX_RGCFR_COF3_Pos) /*!< 0x00000008 */
#define DMAMUX_RGCFR_COF3                      DMAMUX_RGCFR_COF3_Msk           /*!< Clear Overrun flag 3                 */

/******************************************************************************/
/*                                                                            */
/*                    External Interrupt/Event Controller                     */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for EXTI_RTSR1 register  ******************/
#define EXTI_RTSR1_RT_Pos        (0U)
#define EXTI_RTSR1_RT_Msk        (0x803FFFFFUL << EXTI_RTSR1_RT_Pos)           /*!< 0x803FFFFF */
#define EXTI_RTSR1_RT            EXTI_RTSR1_RT_Msk                             /*!< Rising trigger event configuration bit */
#define EXTI_RTSR1_RT0_Pos       (0U)
#define EXTI_RTSR1_RT0_Msk       (0x1UL << EXTI_RTSR1_RT0_Pos)                 /*!< 0x00000001 */
#define EXTI_RTSR1_RT0           EXTI_RTSR1_RT0_Msk                            /*!< Rising trigger event configuration bit of line 0 */
#define EXTI_RTSR1_RT1_Pos       (1U)
#define EXTI_RTSR1_RT1_Msk       (0x1UL << EXTI_RTSR1_RT1_Pos)                 /*!< 0x00000002 */
#define EXTI_RTSR1_RT1           EXTI_RTSR1_RT1_Msk                            /*!< Rising trigger event configuration bit of line 1 */
#define EXTI_RTSR1_RT2_Pos       (2U)
#define EXTI_RTSR1_RT2_Msk       (0x1UL << EXTI_RTSR1_RT2_Pos)                 /*!< 0x00000004 */
#define EXTI_RTSR1_RT2           EXTI_RTSR1_RT2_Msk                            /*!< Rising trigger event configuration bit of line 2 */
#define EXTI_RTSR1_RT3_Pos       (3U)
#define EXTI_RTSR1_RT3_Msk       (0x1UL << EXTI_RTSR1_RT3_Pos)                 /*!< 0x00000008 */
#define EXTI_RTSR1_RT3           EXTI_RTSR1_RT3_Msk                            /*!< Rising trigger event configuration bit of line 3 */
#define EXTI_RTSR1_RT4_Pos       (4U)
#define EXTI_RTSR1_RT4_Msk       (0x1UL << EXTI_RTSR1_RT4_Pos)                 /*!< 0x00000010 */
#define EXTI_RTSR1_RT4           EXTI_RTSR1_RT4_Msk                            /*!< Rising trigger event configuration bit of line 4 */
#define EXTI_RTSR1_RT5_Pos       (5U)
#define EXTI_RTSR1_RT5_Msk       (0x1UL << EXTI_RTSR1_RT5_Pos)                 /*!< 0x00000020 */
#define EXTI_RTSR1_RT5           EXTI_RTSR1_RT5_Msk                            /*!< Rising trigger event configuration bit of line 5 */
#define EXTI_RTSR1_RT6_Pos       (6U)
#define EXTI_RTSR1_RT6_Msk       (0x1UL << EXTI_RTSR1_RT6_Pos)                 /*!< 0x00000040 */
#define EXTI_RTSR1_RT6           EXTI_RTSR1_RT6_Msk                            /*!< Rising trigger event configuration bit of line 6 */
#define EXTI_RTSR1_RT7_Pos       (7U)
#define EXTI_RTSR1_RT7_Msk       (0x1UL << EXTI_RTSR1_RT7_Pos)                 /*!< 0x00000080 */
#define EXTI_RTSR1_RT7           EXTI_RTSR1_RT7_Msk                            /*!< Rising trigger event configuration bit of line 7 */
#define EXTI_RTSR1_RT8_Pos       (8U)
#define EXTI_RTSR1_RT8_Msk       (0x1UL << EXTI_RTSR1_RT8_Pos)                 /*!< 0x00000100 */
#define EXTI_RTSR1_RT8           EXTI_RTSR1_RT8_Msk                            /*!< Rising trigger event configuration bit of line 8 */
#define EXTI_RTSR1_RT9_Pos       (9U)
#define EXTI_RTSR1_RT9_Msk       (0x1UL << EXTI_RTSR1_RT9_Pos)                 /*!< 0x00000200 */
#define EXTI_RTSR1_RT9           EXTI_RTSR1_RT9_Msk                            /*!< Rising trigger event configuration bit of line 9 */
#define EXTI_RTSR1_RT10_Pos      (10U)
#define EXTI_RTSR1_RT10_Msk      (0x1UL << EXTI_RTSR1_RT10_Pos)                /*!< 0x00000400 */
#define EXTI_RTSR1_RT10          EXTI_RTSR1_RT10_Msk                           /*!< Rising trigger event configuration bit of line 10 */
#define EXTI_RTSR1_RT11_Pos      (11U)
#define EXTI_RTSR1_RT11_Msk      (0x1UL << EXTI_RTSR1_RT11_Pos)                /*!< 0x00000800 */
#define EXTI_RTSR1_RT11          EXTI_RTSR1_RT11_Msk                           /*!< Rising trigger event configuration bit of line 11 */
#define EXTI_RTSR1_RT12_Pos      (12U)
#define EXTI_RTSR1_RT12_Msk      (0x1UL << EXTI_RTSR1_RT12_Pos)                /*!< 0x00001000 */
#define EXTI_RTSR1_RT12          EXTI_RTSR1_RT12_Msk                           /*!< Rising trigger event configuration bit of line 12 */
#define EXTI_RTSR1_RT13_Pos      (13U)
#define EXTI_RTSR1_RT13_Msk      (0x1UL << EXTI_RTSR1_RT13_Pos)                /*!< 0x00002000 */
#define EXTI_RTSR1_RT13          EXTI_RTSR1_RT13_Msk                           /*!< Rising trigger event configuration bit of line 13 */
#define EXTI_RTSR1_RT14_Pos      (14U)
#define EXTI_RTSR1_RT14_Msk      (0x1UL << EXTI_RTSR1_RT14_Pos)                /*!< 0x00004000 */
#define EXTI_RTSR1_RT14          EXTI_RTSR1_RT14_Msk                           /*!< Rising trigger event configuration bit of line 14 */
#define EXTI_RTSR1_RT15_Pos      (15U)
#define EXTI_RTSR1_RT15_Msk      (0x1UL << EXTI_RTSR1_RT15_Pos)                /*!< 0x00008000 */
#define EXTI_RTSR1_RT15          EXTI_RTSR1_RT15_Msk                           /*!< Rising trigger event configuration bit of line 15 */
#define EXTI_RTSR1_RT16_Pos      (16U)
#define EXTI_RTSR1_RT16_Msk      (0x1UL << EXTI_RTSR1_RT16_Pos)                /*!< 0x00010000 */
#define EXTI_RTSR1_RT16          EXTI_RTSR1_RT16_Msk                           /*!< Rising trigger event configuration bit of line 16 */
#define EXTI_RTSR1_RT17_Pos      (17U)
#define EXTI_RTSR1_RT17_Msk      (0x1UL << EXTI_RTSR1_RT17_Pos)                /*!< 0x00020000 */
#define EXTI_RTSR1_RT17          EXTI_RTSR1_RT17_Msk                           /*!< Rising trigger event configuration bit of line 17 */
#define EXTI_RTSR1_RT18_Pos      (18U)
#define EXTI_RTSR1_RT18_Msk      (0x1UL << EXTI_RTSR1_RT18_Pos)                /*!< 0x00040000 */
#define EXTI_RTSR1_RT18          EXTI_RTSR1_RT18_Msk                           /*!< Rising trigger event configuration bit of line 18 */
#define EXTI_RTSR1_RT19_Pos      (19U)
#define EXTI_RTSR1_RT19_Msk      (0x1UL << EXTI_RTSR1_RT19_Pos)                /*!< 0x00080000 */
#define EXTI_RTSR1_RT19          EXTI_RTSR1_RT19_Msk                           /*!< Rising trigger event configuration bit of line 19 */
#define EXTI_RTSR1_RT20_Pos      (20U)
#define EXTI_RTSR1_RT20_Msk      (0x1UL << EXTI_RTSR1_RT20_Pos)                /*!< 0x00100000 */
#define EXTI_RTSR1_RT20          EXTI_RTSR1_RT20_Msk                           /*!< Rising trigger event configuration bit of line 20 */
#define EXTI_RTSR1_RT31_Pos      (31U)
#define EXTI_RTSR1_RT31_Msk      (0x1UL << EXTI_RTSR1_RT31_Pos)                /*!< 0x80000000 */
#define EXTI_RTSR1_RT31          EXTI_RTSR1_RT31_Msk                           /*!< Rising trigger event configuration bit of line 31 */

/******************  Bit definition for EXTI_FTSR1 register  ******************/
#define EXTI_FTSR1_FT_Pos        (0U)
#define EXTI_FTSR1_FT_Msk        (0x803FFFFFUL << EXTI_FTSR1_FT_Pos)           /*!< 0x803FFFFF */
#define EXTI_FTSR1_FT            EXTI_FTSR1_FT_Msk                             /*!< Falling trigger event configuration bit */
#define EXTI_FTSR1_FT0_Pos       (0U)
#define EXTI_FTSR1_FT0_Msk       (0x1UL << EXTI_FTSR1_FT0_Pos)                 /*!< 0x00000001 */
#define EXTI_FTSR1_FT0           EXTI_FTSR1_FT0_Msk                            /*!< Falling trigger event configuration bit of line 0 */
#define EXTI_FTSR1_FT1_Pos       (1U)
#define EXTI_FTSR1_FT1_Msk       (0x1UL << EXTI_FTSR1_FT1_Pos)                 /*!< 0x00000002 */
#define EXTI_FTSR1_FT1           EXTI_FTSR1_FT1_Msk                            /*!< Falling trigger event configuration bit of line 1 */
#define EXTI_FTSR1_FT2_Pos       (2U)
#define EXTI_FTSR1_FT2_Msk       (0x1UL << EXTI_FTSR1_FT2_Pos)                 /*!< 0x00000004 */
#define EXTI_FTSR1_FT2           EXTI_FTSR1_FT2_Msk                            /*!< Falling trigger event configuration bit of line 2 */
#define EXTI_FTSR1_FT3_Pos       (3U)
#define EXTI_FTSR1_FT3_Msk       (0x1UL << EXTI_FTSR1_FT3_Pos)                 /*!< 0x00000008 */
#define EXTI_FTSR1_FT3           EXTI_FTSR1_FT3_Msk                            /*!< Falling trigger event configuration bit of line 3 */
#define EXTI_FTSR1_FT4_Pos       (4U)
#define EXTI_FTSR1_FT4_Msk       (0x1UL << EXTI_FTSR1_FT4_Pos)                 /*!< 0x00000010 */
#define EXTI_FTSR1_FT4           EXTI_FTSR1_FT4_Msk                            /*!< Falling trigger event configuration bit of line 4 */
#define EXTI_FTSR1_FT5_Pos       (5U)
#define EXTI_FTSR1_FT5_Msk       (0x1UL << EXTI_FTSR1_FT5_Pos)                 /*!< 0x00000020 */
#define EXTI_FTSR1_FT5           EXTI_FTSR1_FT5_Msk                            /*!< Falling trigger event configuration bit of line 5 */
#define EXTI_FTSR1_FT6_Pos       (6U)
#define EXTI_FTSR1_FT6_Msk       (0x1UL << EXTI_FTSR1_FT6_Pos)                 /*!< 0x00000040 */
#define EXTI_FTSR1_FT6           EXTI_FTSR1_FT6_Msk                            /*!< Falling trigger event configuration bit of line 6 */
#define EXTI_FTSR1_FT7_Pos       (7U)
#define EXTI_FTSR1_FT7_Msk       (0x1UL << EXTI_FTSR1_FT7_Pos)                 /*!< 0x00000080 */
#define EXTI_FTSR1_FT7           EXTI_FTSR1_FT7_Msk                            /*!< Falling trigger event configuration bit of line 7 */
#define EXTI_FTSR1_FT8_Pos       (8U)
#define EXTI_FTSR1_FT8_Msk       (0x1UL << EXTI_FTSR1_FT8_Pos)                 /*!< 0x00000100 */
#define EXTI_FTSR1_FT8           EXTI_FTSR1_FT8_Msk                            /*!< Falling trigger event configuration bit of line 8 */
#define EXTI_FTSR1_FT9_Pos       (9U)
#define EXTI_FTSR1_FT9_Msk       (0x1UL << EXTI_FTSR1_FT9_Pos)                 /*!< 0x00000200 */
#define EXTI_FTSR1_FT9           EXTI_FTSR1_FT9_Msk                            /*!< Falling trigger event configuration bit of line 9 */
#define EXTI_FTSR1_FT10_Pos      (10U)
#define EXTI_FTSR1_FT10_Msk      (0x1UL << EXTI_FTSR1_FT10_Pos)                /*!< 0x00000400 */
#define EXTI_FTSR1_FT10          EXTI_FTSR1_FT10_Msk                           /*!< Falling trigger event configuration bit of line 10 */
#define EXTI_FTSR1_FT11_Pos      (11U)
#define EXTI_FTSR1_FT11_Msk      (0x1UL << EXTI_FTSR1_FT11_Pos)                /*!< 0x00000800 */
#define EXTI_FTSR1_FT11          EXTI_FTSR1_FT11_Msk                           /*!< Falling trigger event configuration bit of line 11 */
#define EXTI_FTSR1_FT12_Pos      (12U)
#define EXTI_FTSR1_FT12_Msk      (0x1UL << EXTI_FTSR1_FT12_Pos)                /*!< 0x00001000 */
#define EXTI_FTSR1_FT12          EXTI_FTSR1_FT12_Msk                           /*!< Falling trigger event configuration bit of line 12 */
#define EXTI_FTSR1_FT13_Pos      (13U)
#define EXTI_FTSR1_FT13_Msk      (0x1UL << EXTI_FTSR1_FT13_Pos)                /*!< 0x00002000 */
#define EXTI_FTSR1_FT13          EXTI_FTSR1_FT13_Msk                           /*!< Falling trigger event configuration bit of line 13 */
#define EXTI_FTSR1_FT14_Pos      (14U)
#define EXTI_FTSR1_FT14_Msk      (0x1UL << EXTI_FTSR1_FT14_Pos)                /*!< 0x00004000 */
#define EXTI_FTSR1_FT14          EXTI_FTSR1_FT14_Msk                           /*!< Falling trigger event configuration bit of line 14 */
#define EXTI_FTSR1_FT15_Pos      (15U)
#define EXTI_FTSR1_FT15_Msk      (0x1UL << EXTI_FTSR1_FT15_Pos)                /*!< 0x00008000 */
#define EXTI_FTSR1_FT15          EXTI_FTSR1_FT15_Msk                           /*!< Falling trigger event configuration bit of line 15 */
#define EXTI_FTSR1_FT16_Pos      (16U)
#define EXTI_FTSR1_FT16_Msk      (0x1UL << EXTI_FTSR1_FT16_Pos)                /*!< 0x00010000 */
#define EXTI_FTSR1_FT16          EXTI_FTSR1_FT16_Msk                           /*!< Falling trigger event configuration bit of line 16 */
#define EXTI_FTSR1_FT17_Pos      (17U)
#define EXTI_FTSR1_FT17_Msk      (0x1UL << EXTI_FTSR1_FT17_Pos)                /*!< 0x00020000 */
#define EXTI_FTSR1_FT17          EXTI_FTSR1_FT17_Msk                           /*!< Falling trigger event configuration bit of line 17 */
#define EXTI_FTSR1_FT18_Pos      (18U)
#define EXTI_FTSR1_FT18_Msk      (0x1UL << EXTI_FTSR1_FT18_Pos)                /*!< 0x00040000 */
#define EXTI_FTSR1_FT18          EXTI_FTSR1_FT18_Msk                           /*!< Falling trigger event configuration bit of line 18 */
#define EXTI_FTSR1_FT19_Pos      (19U)
#define EXTI_FTSR1_FT19_Msk      (0x1UL << EXTI_FTSR1_FT19_Pos)                /*!< 0x00080000 */
#define EXTI_FTSR1_FT19          EXTI_FTSR1_FT19_Msk                           /*!< Falling trigger event configuration bit of line 19 */
#define EXTI_FTSR1_FT20_Pos      (20U)
#define EXTI_FTSR1_FT20_Msk      (0x1UL << EXTI_FTSR1_FT20_Pos)                /*!< 0x00100000 */
#define EXTI_FTSR1_FT20          EXTI_FTSR1_FT20_Msk                           /*!< Falling trigger event configuration bit of line 20 */
#define EXTI_FTSR1_FT31_Pos      (31U)
#define EXTI_FTSR1_FT31_Msk      (0x1UL << EXTI_FTSR1_FT31_Pos)                /*!< 0x80000000 */
#define EXTI_FTSR1_FT31          EXTI_FTSR1_FT31_Msk                           /*!< Falling trigger event configuration bit of line 31 */

/******************  Bit definition for EXTI_SWIER1 register  *****************/
#define EXTI_SWIER1_SWI_Pos      (0U)
#define EXTI_SWIER1_SWI_Msk      (0x803FFFFFUL << EXTI_SWIER1_SWI_Pos)         /*!< 0x803FFFFF */
#define EXTI_SWIER1_SWI          EXTI_SWIER1_SWI_Msk                           /*!< Software interrupt */
#define EXTI_SWIER1_SWI0_Pos     (0U)
#define EXTI_SWIER1_SWI0_Msk     (0x1UL << EXTI_SWIER1_SWI0_Pos)               /*!< 0x00000001 */
#define EXTI_SWIER1_SWI0         EXTI_SWIER1_SWI0_Msk                          /*!< Software Interrupt on line 0 */
#define EXTI_SWIER1_SWI1_Pos     (1U)
#define EXTI_SWIER1_SWI1_Msk     (0x1UL << EXTI_SWIER1_SWI1_Pos)               /*!< 0x00000002 */
#define EXTI_SWIER1_SWI1         EXTI_SWIER1_SWI1_Msk                          /*!< Software Interrupt on line 1 */
#define EXTI_SWIER1_SWI2_Pos     (2U)
#define EXTI_SWIER1_SWI2_Msk     (0x1UL << EXTI_SWIER1_SWI2_Pos)               /*!< 0x00000004 */
#define EXTI_SWIER1_SWI2         EXTI_SWIER1_SWI2_Msk                          /*!< Software Interrupt on line 2 */
#define EXTI_SWIER1_SWI3_Pos     (3U)
#define EXTI_SWIER1_SWI3_Msk     (0x1UL << EXTI_SWIER1_SWI3_Pos)               /*!< 0x00000008 */
#define EXTI_SWIER1_SWI3         EXTI_SWIER1_SWI3_Msk                          /*!< Software Interrupt on line 3 */
#define EXTI_SWIER1_SWI4_Pos     (4U)
#define EXTI_SWIER1_SWI4_Msk     (0x1UL << EXTI_SWIER1_SWI4_Pos)               /*!< 0x00000010 */
#define EXTI_SWIER1_SWI4         EXTI_SWIER1_SWI4_Msk                          /*!< Software Interrupt on line 4 */
#define EXTI_SWIER1_SWI5_Pos     (5U)
#define EXTI_SWIER1_SWI5_Msk     (0x1UL << EXTI_SWIER1_SWI5_Pos)               /*!< 0x00000020 */
#define EXTI_SWIER1_SWI5         EXTI_SWIER1_SWI5_Msk                          /*!< Software Interrupt on line 5 */
#define EXTI_SWIER1_SWI6_Pos     (6U)
#define EXTI_SWIER1_SWI6_Msk     (0x1UL << EXTI_SWIER1_SWI6_Pos)               /*!< 0x00000040 */
#define EXTI_SWIER1_SWI6         EXTI_SWIER1_SWI6_Msk                          /*!< Software Interrupt on line 6 */
#define EXTI_SWIER1_SWI7_Pos     (7U)
#define EXTI_SWIER1_SWI7_Msk     (0x1UL << EXTI_SWIER1_SWI7_Pos)               /*!< 0x00000080 */
#define EXTI_SWIER1_SWI7         EXTI_SWIER1_SWI7_Msk                          /*!< Software Interrupt on line 7 */
#define EXTI_SWIER1_SWI8_Pos     (8U)
#define EXTI_SWIER1_SWI8_Msk     (0x1UL << EXTI_SWIER1_SWI8_Pos)               /*!< 0x00000100 */
#define EXTI_SWIER1_SWI8         EXTI_SWIER1_SWI8_Msk                          /*!< Software Interrupt on line 8 */
#define EXTI_SWIER1_SWI9_Pos     (9U)
#define EXTI_SWIER1_SWI9_Msk     (0x1UL << EXTI_SWIER1_SWI9_Pos)               /*!< 0x00000200 */
#define EXTI_SWIER1_SWI9         EXTI_SWIER1_SWI9_Msk                          /*!< Software Interrupt on line 9 */
#define EXTI_SWIER1_SWI10_Pos    (10U)
#define EXTI_SWIER1_SWI10_Msk    (0x1UL << EXTI_SWIER1_SWI10_Pos)              /*!< 0x00000400 */
#define EXTI_SWIER1_SWI10        EXTI_SWIER1_SWI10_Msk                         /*!< Software Interrupt on line 10 */
#define EXTI_SWIER1_SWI11_Pos    (11U)
#define EXTI_SWIER1_SWI11_Msk    (0x1UL << EXTI_SWIER1_SWI11_Pos)              /*!< 0x00000800 */
#define EXTI_SWIER1_SWI11        EXTI_SWIER1_SWI11_Msk                         /*!< Software Interrupt on line 11 */
#define EXTI_SWIER1_SWI12_Pos    (12U)
#define EXTI_SWIER1_SWI12_Msk    (0x1UL << EXTI_SWIER1_SWI12_Pos)              /*!< 0x00001000 */
#define EXTI_SWIER1_SWI12        EXTI_SWIER1_SWI12_Msk                         /*!< Software Interrupt on line 12 */
#define EXTI_SWIER1_SWI13_Pos    (13U)
#define EXTI_SWIER1_SWI13_Msk    (0x1UL << EXTI_SWIER1_SWI13_Pos)              /*!< 0x00002000 */
#define EXTI_SWIER1_SWI13        EXTI_SWIER1_SWI13_Msk                         /*!< Software Interrupt on line 13 */
#define EXTI_SWIER1_SWI14_Pos    (14U)
#define EXTI_SWIER1_SWI14_Msk    (0x1UL << EXTI_SWIER1_SWI14_Pos)              /*!< 0x00004000 */
#define EXTI_SWIER1_SWI14        EXTI_SWIER1_SWI14_Msk                         /*!< Software Interrupt on line 14 */
#define EXTI_SWIER1_SWI15_Pos    (15U)
#define EXTI_SWIER1_SWI15_Msk    (0x1UL << EXTI_SWIER1_SWI15_Pos)              /*!< 0x00008000 */
#define EXTI_SWIER1_SWI15        EXTI_SWIER1_SWI15_Msk                         /*!< Software Interrupt on line 15 */
#define EXTI_SWIER1_SWI16_Pos    (16U)
#define EXTI_SWIER1_SWI16_Msk    (0x1UL << EXTI_SWIER1_SWI16_Pos)              /*!< 0x00010000 */
#define EXTI_SWIER1_SWI16        EXTI_SWIER1_SWI16_Msk                         /*!< Software Interrupt on line 16 */
#define EXTI_SWIER1_SWI17_Pos    (17U)
#define EXTI_SWIER1_SWI17_Msk    (0x1UL << EXTI_SWIER1_SWI17_Pos)              /*!< 0x00020000 */
#define EXTI_SWIER1_SWI17        EXTI_SWIER1_SWI17_Msk                         /*!< Software Interrupt on line 17 */
#define EXTI_SWIER1_SWI18_Pos    (18U)
#define EXTI_SWIER1_SWI18_Msk    (0x1UL << EXTI_SWIER1_SWI18_Pos)              /*!< 0x00040000 */
#define EXTI_SWIER1_SWI18        EXTI_SWIER1_SWI18_Msk                         /*!< Software Interrupt on line 18 */
#define EXTI_SWIER1_SWI19_Pos    (19U)
#define EXTI_SWIER1_SWI19_Msk    (0x1UL << EXTI_SWIER1_SWI19_Pos)              /*!< 0x00080000 */
#define EXTI_SWIER1_SWI19        EXTI_SWIER1_SWI19_Msk                         /*!< Software Interrupt on line 19 */
#define EXTI_SWIER1_SWI20_Pos    (20U)
#define EXTI_SWIER1_SWI20_Msk    (0x1UL << EXTI_SWIER1_SWI20_Pos)              /*!< 0x00100000 */
#define EXTI_SWIER1_SWI20        EXTI_SWIER1_SWI20_Msk                         /*!< Software Interrupt on line 20 */
#define EXTI_SWIER1_SWI31_Pos    (31U)
#define EXTI_SWIER1_SWI31_Msk    (0x1UL << EXTI_SWIER1_SWI31_Pos)              /*!< 0x80000000 */
#define EXTI_SWIER1_SWI31         EXTI_SWIER1_SWI31_Msk                        /*!< Software Interrupt on line 31 */

/*******************  Bit definition for EXTI_PR1 register  *******************/
#define EXTI_PR1_PIF_Pos         (0U)
#define EXTI_PR1_PIF_Msk         (0x803FFFFFUL << EXTI_PR1_PIF_Pos)            /*!< 0x803FFFFF */
#define EXTI_PR1_PIF             EXTI_PR1_PIF_Msk                              /*!< Pending bit */
#define EXTI_PR1_PIF0_Pos        (0U)
#define EXTI_PR1_PIF0_Msk        (0x1UL << EXTI_PR1_PIF0_Pos)                  /*!< 0x00000001 */
#define EXTI_PR1_PIF0            EXTI_PR1_PIF0_Msk                             /*!< Pending bit for line 0 */
#define EXTI_PR1_PIF1_Pos        (1U)
#define EXTI_PR1_PIF1_Msk        (0x1UL << EXTI_PR1_PIF1_Pos)                  /*!< 0x00000002 */
#define EXTI_PR1_PIF1            EXTI_PR1_PIF1_Msk                             /*!< Pending bit for line 1 */
#define EXTI_PR1_PIF2_Pos        (2U)
#define EXTI_PR1_PIF2_Msk        (0x1UL << EXTI_PR1_PIF2_Pos)                  /*!< 0x00000004 */
#define EXTI_PR1_PIF2            EXTI_PR1_PIF2_Msk                             /*!< Pending bit for line 2 */
#define EXTI_PR1_PIF3_Pos        (3U)
#define EXTI_PR1_PIF3_Msk        (0x1UL << EXTI_PR1_PIF3_Pos)                  /*!< 0x00000008 */
#define EXTI_PR1_PIF3            EXTI_PR1_PIF3_Msk                             /*!< Pending bit for line 3 */
#define EXTI_PR1_PIF4_Pos        (4U)
#define EXTI_PR1_PIF4_Msk        (0x1UL << EXTI_PR1_PIF4_Pos)                  /*!< 0x00000010 */
#define EXTI_PR1_PIF4            EXTI_PR1_PIF4_Msk                             /*!< Pending bit for line 4 */
#define EXTI_PR1_PIF5_Pos        (5U)
#define EXTI_PR1_PIF5_Msk        (0x1UL << EXTI_PR1_PIF5_Pos)                  /*!< 0x00000020 */
#define EXTI_PR1_PIF5            EXTI_PR1_PIF5_Msk                             /*!< Pending bit for line 5 */
#define EXTI_PR1_PIF6_Pos        (6U)
#define EXTI_PR1_PIF6_Msk        (0x1UL << EXTI_PR1_PIF6_Pos)                  /*!< 0x00000040 */
#define EXTI_PR1_PIF6            EXTI_PR1_PIF6_Msk                             /*!< Pending bit for line 6 */
#define EXTI_PR1_PIF7_Pos        (7U)
#define EXTI_PR1_PIF7_Msk        (0x1UL << EXTI_PR1_PIF7_Pos)                  /*!< 0x00000080 */
#define EXTI_PR1_PIF7            EXTI_PR1_PIF7_Msk                             /*!< Pending bit for line 7 */
#define EXTI_PR1_PIF8_Pos        (8U)
#define EXTI_PR1_PIF8_Msk        (0x1UL << EXTI_PR1_PIF8_Pos)                  /*!< 0x00000100 */
#define EXTI_PR1_PIF8            EXTI_PR1_PIF8_Msk                             /*!< Pending bit for line 8 */
#define EXTI_PR1_PIF9_Pos        (9U)
#define EXTI_PR1_PIF9_Msk        (0x1UL << EXTI_PR1_PIF9_Pos)                  /*!< 0x00000200 */
#define EXTI_PR1_PIF9            EXTI_PR1_PIF9_Msk                             /*!< Pending bit for line 9 */
#define EXTI_PR1_PIF10_Pos       (10U)
#define EXTI_PR1_PIF10_Msk       (0x1UL << EXTI_PR1_PIF10_Pos)                 /*!< 0x00000400 */
#define EXTI_PR1_PIF10           EXTI_PR1_PIF10_Msk                            /*!< Pending bit for line 10 */
#define EXTI_PR1_PIF11_Pos       (11U)
#define EXTI_PR1_PIF11_Msk       (0x1UL << EXTI_PR1_PIF11_Pos)                 /*!< 0x00000800 */
#define EXTI_PR1_PIF11           EXTI_PR1_PIF11_Msk                            /*!< Pending bit for line 11 */
#define EXTI_PR1_PIF12_Pos       (12U)
#define EXTI_PR1_PIF12_Msk       (0x1UL << EXTI_PR1_PIF12_Pos)                 /*!< 0x00001000 */
#define EXTI_PR1_PIF12           EXTI_PR1_PIF12_Msk                            /*!< Pending bit for line 12 */
#define EXTI_PR1_PIF13_Pos       (13U)
#define EXTI_PR1_PIF13_Msk       (0x1UL << EXTI_PR1_PIF13_Pos)                 /*!< 0x00002000 */
#define EXTI_PR1_PIF13           EXTI_PR1_PIF13_Msk                            /*!< Pending bit for line 13 */
#define EXTI_PR1_PIF14_Pos       (14U)
#define EXTI_PR1_PIF14_Msk       (0x1UL << EXTI_PR1_PIF14_Pos)                 /*!< 0x00004000 */
#define EXTI_PR1_PIF14           EXTI_PR1_PIF14_Msk                            /*!< Pending bit for line 14 */
#define EXTI_PR1_PIF15_Pos       (15U)
#define EXTI_PR1_PIF15_Msk       (0x1UL << EXTI_PR1_PIF15_Pos)                 /*!< 0x00008000 */
#define EXTI_PR1_PIF15           EXTI_PR1_PIF15_Msk                            /*!< Pending bit for line 15 */
#define EXTI_PR1_PIF16_Pos       (16U)
#define EXTI_PR1_PIF16_Msk       (0x1UL << EXTI_PR1_PIF16_Pos)                 /*!< 0x00010000 */
#define EXTI_PR1_PIF16           EXTI_PR1_PIF16_Msk                            /*!< Pending bit for line 16 */
#define EXTI_PR1_PIF17_Pos       (17U)
#define EXTI_PR1_PIF17_Msk       (0x1UL << EXTI_PR1_PIF17_Pos)                 /*!< 0x00020000 */
#define EXTI_PR1_PIF17           EXTI_PR1_PIF17_Msk                            /*!< Pending bit for line 17 */
#define EXTI_PR1_PIF18_Pos       (18U)
#define EXTI_PR1_PIF18_Msk       (0x1UL << EXTI_PR1_PIF18_Pos)                 /*!< 0x00040000 */
#define EXTI_PR1_PIF18           EXTI_PR1_PIF18_Msk                            /*!< Pending bit for line 18 */
#define EXTI_PR1_PIF19_Pos       (19U)
#define EXTI_PR1_PIF19_Msk       (0x1UL << EXTI_PR1_PIF19_Pos)                 /*!< 0x00080000 */
#define EXTI_PR1_PIF19           EXTI_PR1_PIF19_Msk                            /*!< Pending bit for line 19 */
#define EXTI_PR1_PIF20_Pos       (20U)
#define EXTI_PR1_PIF20_Msk       (0x1UL << EXTI_PR1_PIF20_Pos)                 /*!< 0x00100000 */
#define EXTI_PR1_PIF20           EXTI_PR1_PIF20_Msk                            /*!< Pending bit for line 20 */
#define EXTI_PR1_PIF31_Pos       (31U)
#define EXTI_PR1_PIF31_Msk       (0x1UL << EXTI_PR1_PIF31_Pos)                 /*!< 0x80000000 */
#define EXTI_PR1_PIF31           EXTI_PR1_PIF31_Msk                            /*!< Pending bit for line 31 */

/******************  Bit definition for EXTI_RTSR2 register  ******************/
#define EXTI_RTSR2_RT_Pos        (0U)
#define EXTI_RTSR2_RT_Msk        (0x302UL << EXTI_RTSR2_RT_Pos)                /*!< 0x00000302 */
#define EXTI_RTSR2_RT            EXTI_RTSR2_RT_Msk                             /*!< Rising trigger event configuration bit */
#define EXTI_RTSR2_RT33_Pos      (1U)
#define EXTI_RTSR2_RT33_Msk      (0x1UL << EXTI_RTSR2_RT33_Pos)                /*!< 0x00000002 */
#define EXTI_RTSR2_RT33          EXTI_RTSR2_RT33_Msk                           /*!< Rising trigger event configuration bit of line 33 */
#define EXTI_RTSR2_RT40_Pos      (8U)
#define EXTI_RTSR2_RT40_Msk      (0x1UL << EXTI_RTSR2_RT40_Pos)                /*!< 0x00000100 */
#define EXTI_RTSR2_RT40          EXTI_RTSR2_RT40_Msk                           /*!< Rising trigger event configuration bit of line 40 */
#define EXTI_RTSR2_RT41_Pos      (9U)
#define EXTI_RTSR2_RT41_Msk      (0x1UL << EXTI_RTSR2_RT41_Pos)                /*!< 0x00000200 */
#define EXTI_RTSR2_RT41          EXTI_RTSR2_RT41_Msk                           /*!< Rising trigger event configuration bit of line 41 */

/******************  Bit definition for EXTI_FTSR2 register  ******************/
#define EXTI_FTSR2_FT_Pos        (0U)
#define EXTI_FTSR2_FT_Msk        (0x302UL << EXTI_FTSR2_FT_Pos)                /*!< 0x00000302 */
#define EXTI_FTSR2_FT            EXTI_FTSR2_FT_Msk                             /*!< Falling trigger event configuration bit */
#define EXTI_FTSR2_FT33_Pos      (1U)
#define EXTI_FTSR2_FT33_Msk      (0x1UL << EXTI_FTSR2_FT33_Pos)                /*!< 0x00000002 */
#define EXTI_FTSR2_FT33          EXTI_FTSR2_FT33_Msk                           /*!< Falling trigger event configuration bit of line 33 */
#define EXTI_FTSR2_FT40_Pos      (8U)
#define EXTI_FTSR2_FT40_Msk      (0x1UL << EXTI_FTSR2_FT40_Pos)                /*!< 0x00000100 */
#define EXTI_FTSR2_FT40          EXTI_FTSR2_FT40_Msk                           /*!< Falling trigger event configuration bit of line 40 */
#define EXTI_FTSR2_FT41_Pos      (9U)
#define EXTI_FTSR2_FT41_Msk      (0x1UL << EXTI_FTSR2_FT41_Pos)                /*!< 0x00000200 */
#define EXTI_FTSR2_FT41          EXTI_FTSR2_FT41_Msk                           /*!< Falling trigger event configuration bit of line 41 */

/******************  Bit definition for EXTI_SWIER2 register  *****************/
#define EXTI_SWIER2_SWI_Pos      (0U)
#define EXTI_SWIER2_SWI_Msk      (0x302UL << EXTI_SWIER2_SWI_Pos)              /*!< 0x00000302 */
#define EXTI_SWIER2_SWI          EXTI_SWIER2_SWI_Msk                           /*!< Falling trigger event configuration bit */
#define EXTI_SWIER2_SWI33_Pos    (1U)
#define EXTI_SWIER2_SWI33_Msk    (0x1UL << EXTI_SWIER2_SWI33_Pos)                /*!< 0x00000002 */
#define EXTI_SWIER2_SWI33        EXTI_SWIER2_SWI33_Msk                           /*!< Software Interrupt on line 33 */
#define EXTI_SWIER2_SWI40_Pos    (8U)
#define EXTI_SWIER2_SWI40_Msk    (0x1UL << EXTI_SWIER2_SWI40_Pos)                /*!< 0x00000100 */
#define EXTI_SWIER2_SWI40        EXTI_SWIER2_SWI40_Msk                           /*!< Software Interrupt on line 40 */
#define EXTI_SWIER2_SWI41_Pos    (9U)
#define EXTI_SWIER2_SWI41_Msk    (0x1UL << EXTI_SWIER2_SWI41_Pos)                /*!< 0x00000200 */
#define EXTI_SWIER2_SWI41        EXTI_SWIER2_SWI41_Msk                           /*!< Software Interrupt on line 41 */

/*******************  Bit definition for EXTI_PR2 register  *******************/
#define EXTI_PR2_PIF_Pos         (0U)
#define EXTI_PR2_PIF_Msk         (0x302UL << EXTI_PR2_PIF_Pos)                 /*!< 0x00000302 */
#define EXTI_PR2_PIF             EXTI_PR2_PIF_Msk                              /*!< Pending bit */
#define EXTI_PR2_PIF33_Pos       (1U)
#define EXTI_PR2_PIF33_Msk       (0x1UL << EXTI_PR2_PIF33_Pos)                 /*!< 0x00000002 */
#define EXTI_PR2_PIF33           EXTI_PR2_PIF33_Msk                            /*!< Pending bit for line 33 */
#define EXTI_PR2_PIF40_Pos       (8U)
#define EXTI_PR2_PIF40_Msk       (0x1UL << EXTI_PR2_PIF40_Pos)                 /*!< 0x00000100 */
#define EXTI_PR2_PIF40           EXTI_PR2_PIF40_Msk                            /*!< Pending bit for line 40 */
#define EXTI_PR2_PIF41_Pos       (9U)
#define EXTI_PR2_PIF41_Msk       (0x1UL << EXTI_PR2_PIF41_Pos)                 /*!< 0x00000200 */
#define EXTI_PR2_PIF41           EXTI_PR2_PIF41_Msk                            /*!< Pending bit for line 41 */

/********************  Bits definition for EXTI_IMR1 register  ****************/
#define EXTI_IMR1_Pos            (0U)
#define EXTI_IMR1_Msk            (0xFFFFFFFFUL << EXTI_IMR1_Pos)               /*!< 0xFFFFFFFF */
#define EXTI_IMR1_IM             EXTI_IMR1_Msk                                 /*!< CPU1 wakeup with interrupt Mask on Event */
#define EXTI_IMR1_IM0_Pos        (0U)
#define EXTI_IMR1_IM0_Msk        (0x1UL << EXTI_IMR1_IM0_Pos)                  /*!< 0x00000001 */
#define EXTI_IMR1_IM0            EXTI_IMR1_IM0_Msk                             /*!< CPU1 Interrupt Mask on line 0 */
#define EXTI_IMR1_IM1_Pos        (1U)
#define EXTI_IMR1_IM1_Msk        (0x1UL << EXTI_IMR1_IM1_Pos)                  /*!< 0x00000002 */
#define EXTI_IMR1_IM1            EXTI_IMR1_IM1_Msk                             /*!< CPU1 Interrupt Mask on line 1 */
#define EXTI_IMR1_IM2_Pos        (2U)
#define EXTI_IMR1_IM2_Msk        (0x1UL << EXTI_IMR1_IM2_Pos)                  /*!< 0x00000004 */
#define EXTI_IMR1_IM2            EXTI_IMR1_IM2_Msk                             /*!< CPU1 Interrupt Mask on line 2 */
#define EXTI_IMR1_IM3_Pos        (3U)
#define EXTI_IMR1_IM3_Msk        (0x1UL << EXTI_IMR1_IM3_Pos)                  /*!< 0x00000008 */
#define EXTI_IMR1_IM3            EXTI_IMR1_IM3_Msk                             /*!< CPU1 Interrupt Mask on line 3 */
#define EXTI_IMR1_IM4_Pos        (4U)
#define EXTI_IMR1_IM4_Msk        (0x1UL << EXTI_IMR1_IM4_Pos)                  /*!< 0x00000010 */
#define EXTI_IMR1_IM4            EXTI_IMR1_IM4_Msk                             /*!< CPU1 Interrupt Mask on line 4 */
#define EXTI_IMR1_IM5_Pos        (5U)
#define EXTI_IMR1_IM5_Msk        (0x1UL << EXTI_IMR1_IM5_Pos)                  /*!< 0x00000020 */
#define EXTI_IMR1_IM5            EXTI_IMR1_IM5_Msk                             /*!< CPU1 Interrupt Mask on line 5 */
#define EXTI_IMR1_IM6_Pos        (6U)
#define EXTI_IMR1_IM6_Msk        (0x1UL << EXTI_IMR1_IM6_Pos)                  /*!< 0x00000040 */
#define EXTI_IMR1_IM6            EXTI_IMR1_IM6_Msk                             /*!< CPU1 Interrupt Mask on line 6 */
#define EXTI_IMR1_IM7_Pos        (7U)
#define EXTI_IMR1_IM7_Msk        (0x1UL << EXTI_IMR1_IM7_Pos)                  /*!< 0x00000080 */
#define EXTI_IMR1_IM7            EXTI_IMR1_IM7_Msk                             /*!< CPU1 Interrupt Mask on line 7 */
#define EXTI_IMR1_IM8_Pos        (8U)
#define EXTI_IMR1_IM8_Msk        (0x1UL << EXTI_IMR1_IM8_Pos)                  /*!< 0x00000100 */
#define EXTI_IMR1_IM8            EXTI_IMR1_IM8_Msk                             /*!< CPU1 Interrupt Mask on line 8 */
#define EXTI_IMR1_IM9_Pos        (9U)
#define EXTI_IMR1_IM9_Msk        (0x1UL << EXTI_IMR1_IM9_Pos)                  /*!< 0x00000200 */
#define EXTI_IMR1_IM9            EXTI_IMR1_IM9_Msk                             /*!< CPU1 Interrupt Mask on line 9 */
#define EXTI_IMR1_IM10_Pos       (10U)
#define EXTI_IMR1_IM10_Msk       (0x1UL << EXTI_IMR1_IM10_Pos)                 /*!< 0x00000400 */
#define EXTI_IMR1_IM10           EXTI_IMR1_IM10_Msk                            /*!< CPU1 Interrupt Mask on line 10 */
#define EXTI_IMR1_IM11_Pos       (11U)
#define EXTI_IMR1_IM11_Msk       (0x1UL << EXTI_IMR1_IM11_Pos)                 /*!< 0x00000800 */
#define EXTI_IMR1_IM11           EXTI_IMR1_IM11_Msk                            /*!< CPU1 Interrupt Mask on line 11 */
#define EXTI_IMR1_IM12_Pos       (12U)
#define EXTI_IMR1_IM12_Msk       (0x1UL << EXTI_IMR1_IM12_Pos)                 /*!< 0x00001000 */
#define EXTI_IMR1_IM12           EXTI_IMR1_IM12_Msk                            /*!< CPU1 Interrupt Mask on line 12 */
#define EXTI_IMR1_IM13_Pos       (13U)
#define EXTI_IMR1_IM13_Msk       (0x1UL << EXTI_IMR1_IM13_Pos)                 /*!< 0x00002000 */
#define EXTI_IMR1_IM13           EXTI_IMR1_IM13_Msk                            /*!< CPU1 Interrupt Mask on line 13 */
#define EXTI_IMR1_IM14_Pos       (14U)
#define EXTI_IMR1_IM14_Msk       (0x1UL << EXTI_IMR1_IM14_Pos)                 /*!< 0x00004000 */
#define EXTI_IMR1_IM14           EXTI_IMR1_IM14_Msk                            /*!< CPU1 Interrupt Mask on line 14 */
#define EXTI_IMR1_IM15_Pos       (15U)
#define EXTI_IMR1_IM15_Msk       (0x1UL << EXTI_IMR1_IM15_Pos)                 /*!< 0x00008000 */
#define EXTI_IMR1_IM15           EXTI_IMR1_IM15_Msk                            /*!< CPU1 Interrupt Mask on line 15 */
#define EXTI_IMR1_IM16_Pos       (16U)
#define EXTI_IMR1_IM16_Msk       (0x1UL << EXTI_IMR1_IM16_Pos)                 /*!< 0x00010000 */
#define EXTI_IMR1_IM16           EXTI_IMR1_IM16_Msk                            /*!< CPU1 Interrupt Mask on line 16 */
#define EXTI_IMR1_IM17_Pos       (17U)
#define EXTI_IMR1_IM17_Msk       (0x1UL << EXTI_IMR1_IM17_Pos)                 /*!< 0x00020000 */
#define EXTI_IMR1_IM17           EXTI_IMR1_IM17_Msk                            /*!< CPU1 Interrupt Mask on line 17 */
#define EXTI_IMR1_IM18_Pos       (18U)
#define EXTI_IMR1_IM18_Msk       (0x1UL << EXTI_IMR1_IM18_Pos)                 /*!< 0x00040000 */
#define EXTI_IMR1_IM18           EXTI_IMR1_IM18_Msk                            /*!< CPU1 Interrupt Mask on line 18 */
#define EXTI_IMR1_IM19_Pos       (19U)
#define EXTI_IMR1_IM19_Msk       (0x1UL << EXTI_IMR1_IM19_Pos)                 /*!< 0x00080000 */
#define EXTI_IMR1_IM19           EXTI_IMR1_IM19_Msk                            /*!< CPU1 Interrupt Mask on line 19 */
#define EXTI_IMR1_IM20_Pos       (20U)
#define EXTI_IMR1_IM20_Msk       (0x1UL << EXTI_IMR1_IM20_Pos)                 /*!< 0x00100000 */
#define EXTI_IMR1_IM20           EXTI_IMR1_IM20_Msk                            /*!< CPU1 Interrupt Mask on line 20 */
#define EXTI_IMR1_IM22_Pos       (22U)
#define EXTI_IMR1_IM22_Msk       (0x1UL << EXTI_IMR1_IM22_Pos)                 /*!< 0x00400000 */
#define EXTI_IMR1_IM22           EXTI_IMR1_IM22_Msk                            /*!< CPU1 Interrupt Mask on line 22 */
#define EXTI_IMR1_IM24_Pos       (24U)
#define EXTI_IMR1_IM24_Msk       (0x1UL << EXTI_IMR1_IM24_Pos)                 /*!< 0x01000000 */
#define EXTI_IMR1_IM24           EXTI_IMR1_IM24_Msk                            /*!< CPU1 Interrupt Mask on line 24 */
#define EXTI_IMR1_IM25_Pos       (25U)
#define EXTI_IMR1_IM25_Msk       (0x1UL << EXTI_IMR1_IM25_Pos)                 /*!< 0x02000000 */
#define EXTI_IMR1_IM25           EXTI_IMR1_IM25_Msk                            /*!< CPU1 Interrupt Mask on line 25 */
#define EXTI_IMR1_IM29_Pos       (29U)
#define EXTI_IMR1_IM29_Msk       (0x1UL << EXTI_IMR1_IM29_Pos)                 /*!< 0x20000000 */
#define EXTI_IMR1_IM29           EXTI_IMR1_IM29_Msk                            /*!< CPU1 Interrupt Mask on line 29 */
#define EXTI_IMR1_IM30_Pos       (30U)
#define EXTI_IMR1_IM30_Msk       (0x1UL << EXTI_IMR1_IM30_Pos)                 /*!< 0x40000000 */
#define EXTI_IMR1_IM30           EXTI_IMR1_IM30_Msk                            /*!< CPU1 Interrupt Mask on line 30 */
#define EXTI_IMR1_IM31_Pos       (31U)
#define EXTI_IMR1_IM31_Msk       (0x1UL << EXTI_IMR1_IM31_Pos)                 /*!< 0x80000000 */
#define EXTI_IMR1_IM31           EXTI_IMR1_IM31_Msk                            /*!< CPU1 Interrupt Mask on line 31 */

/********************  Bits definition for EXTI_EMR1 register  ****************/
#define EXTI_EMR1_Pos            (0U)
#define EXTI_EMR1_Msk            (0x003EFFFFUL << EXTI_EMR1_Pos)               /*!< 0xFFFFFFFF */
#define EXTI_EMR1_EM             EXTI_EMR1_Msk                                 /*!< CPU1 Event Mask */
#define EXTI_EMR1_EM0_Pos        (0U)
#define EXTI_EMR1_EM0_Msk        (0x1UL << EXTI_EMR1_EM0_Pos)                  /*!< 0x00000001 */
#define EXTI_EMR1_EM0            EXTI_EMR1_EM0_Msk                             /*!< CPU1 Event Mask on line 0 */
#define EXTI_EMR1_EM1_Pos        (1U)
#define EXTI_EMR1_EM1_Msk        (0x1UL << EXTI_EMR1_EM1_Pos)                  /*!< 0x00000002 */
#define EXTI_EMR1_EM1            EXTI_EMR1_EM1_Msk                             /*!< CPU1 Event Mask on line 1 */
#define EXTI_EMR1_EM2_Pos        (2U)
#define EXTI_EMR1_EM2_Msk        (0x1UL << EXTI_EMR1_EM2_Pos)                  /*!< 0x00000004 */
#define EXTI_EMR1_EM2            EXTI_EMR1_EM2_Msk                             /*!< CPU1 Event Mask on line 2 */
#define EXTI_EMR1_EM3_Pos        (3U)
#define EXTI_EMR1_EM3_Msk        (0x1UL << EXTI_EMR1_EM3_Pos)                  /*!< 0x00000008 */
#define EXTI_EMR1_EM3            EXTI_EMR1_EM3_Msk                             /*!< CPU1 Event Mask on line 3 */
#define EXTI_EMR1_EM4_Pos        (4U)
#define EXTI_EMR1_EM4_Msk        (0x1UL << EXTI_EMR1_EM4_Pos)                  /*!< 0x00000010 */
#define EXTI_EMR1_EM4            EXTI_EMR1_EM4_Msk                             /*!< CPU1 Event Mask on line 4 */
#define EXTI_EMR1_EM5_Pos        (5U)
#define EXTI_EMR1_EM5_Msk        (0x1UL << EXTI_EMR1_EM5_Pos)                  /*!< 0x00000020 */
#define EXTI_EMR1_EM5            EXTI_EMR1_EM5_Msk                             /*!< CPU1 Event Mask on line 5 */
#define EXTI_EMR1_EM6_Pos        (6U)
#define EXTI_EMR1_EM6_Msk        (0x1UL << EXTI_EMR1_EM6_Pos)                  /*!< 0x00000040 */
#define EXTI_EMR1_EM6            EXTI_EMR1_EM6_Msk                             /*!< CPU1 Event Mask on line 6 */
#define EXTI_EMR1_EM7_Pos        (7U)
#define EXTI_EMR1_EM7_Msk        (0x1UL << EXTI_EMR1_EM7_Pos)                  /*!< 0x00000080 */
#define EXTI_EMR1_EM7            EXTI_EMR1_EM7_Msk                             /*!< CPU1 Event Mask on line 7 */
#define EXTI_EMR1_EM8_Pos        (8U)
#define EXTI_EMR1_EM8_Msk        (0x1UL << EXTI_EMR1_EM8_Pos)                  /*!< 0x00000100 */
#define EXTI_EMR1_EM8            EXTI_EMR1_EM8_Msk                             /*!< CPU1 Event Mask on line 8 */
#define EXTI_EMR1_EM9_Pos        (9U)
#define EXTI_EMR1_EM9_Msk        (0x1UL << EXTI_EMR1_EM9_Pos)                  /*!< 0x00000200 */
#define EXTI_EMR1_EM9            EXTI_EMR1_EM9_Msk                             /*!< CPU1 Event Mask on line 9 */
#define EXTI_EMR1_EM10_Pos       (10U)
#define EXTI_EMR1_EM10_Msk       (0x1UL << EXTI_EMR1_EM10_Pos)                 /*!< 0x00000400 */
#define EXTI_EMR1_EM10           EXTI_EMR1_EM10_Msk                            /*!< CPU1 Event Mask on line 10 */
#define EXTI_EMR1_EM11_Pos       (11U)
#define EXTI_EMR1_EM11_Msk       (0x1UL << EXTI_EMR1_EM11_Pos)                 /*!< 0x00000800 */
#define EXTI_EMR1_EM11           EXTI_EMR1_EM11_Msk                            /*!< CPU1 Event Mask on line 11 */
#define EXTI_EMR1_EM12_Pos       (12U)
#define EXTI_EMR1_EM12_Msk       (0x1UL << EXTI_EMR1_EM12_Pos)                 /*!< 0x00001000 */
#define EXTI_EMR1_EM12           EXTI_EMR1_EM12_Msk                            /*!< CPU1 Event Mask on line 12 */
#define EXTI_EMR1_EM13_Pos       (13U)
#define EXTI_EMR1_EM13_Msk       (0x1UL << EXTI_EMR1_EM13_Pos)                 /*!< 0x00002000 */
#define EXTI_EMR1_EM13           EXTI_EMR1_EM13_Msk                            /*!< CPU1 Event Mask on line 13 */
#define EXTI_EMR1_EM14_Pos       (14U)
#define EXTI_EMR1_EM14_Msk       (0x1UL << EXTI_EMR1_EM14_Pos)                 /*!< 0x00004000 */
#define EXTI_EMR1_EM14           EXTI_EMR1_EM14_Msk                            /*!< CPU1 Event Mask on line 14 */
#define EXTI_EMR1_EM15_Pos       (15U)
#define EXTI_EMR1_EM15_Msk       (0x1UL << EXTI_EMR1_EM15_Pos)                 /*!< 0x00008000 */
#define EXTI_EMR1_EM15           EXTI_EMR1_EM15_Msk                            /*!< CPU1 Event Mask on line 15 */
#define EXTI_EMR1_EM17_Pos       (17U)
#define EXTI_EMR1_EM17_Msk       (0x1UL << EXTI_EMR1_EM17_Pos)                 /*!< 0x00020000 */
#define EXTI_EMR1_EM17           EXTI_EMR1_EM17_Msk                            /*!< CPU1 Event Mask on line 17 */
#define EXTI_EMR1_EM18_Pos       (18U)
#define EXTI_EMR1_EM18_Msk       (0x1UL << EXTI_EMR1_EM18_Pos)                 /*!< 0x00040000 */
#define EXTI_EMR1_EM18           EXTI_EMR1_EM18_Msk                            /*!< CPU1 Event Mask on line 18 */
#define EXTI_EMR1_EM19_Pos       (19U)
#define EXTI_EMR1_EM19_Msk       (0x1UL << EXTI_EMR1_EM19_Pos)                 /*!< 0x00080000 */
#define EXTI_EMR1_EM19           EXTI_EMR1_EM19_Msk                            /*!< CPU1 Event Mask on line 19 */
#define EXTI_EMR1_EM20_Pos       (20U)
#define EXTI_EMR1_EM20_Msk       (0x1UL << EXTI_EMR1_EM20_Pos)                 /*!< 0x00100000 */
#define EXTI_EMR1_EM20           EXTI_EMR1_EM20_Msk                            /*!< CPU1 Event Mask on line 20 */

/********************  Bits definition for EXTI_IMR2 register  ****************/
#define EXTI_IMR2_Pos            (0U)
#define EXTI_IMR2_Msk            (0x0001FFFFUL << EXTI_IMR2_Pos)               /*!< 0x0001FFFF */
#define EXTI_IMR2_IM             EXTI_IMR2_Msk                                 /*!< CPU1 Interrupt Mask  */
#define EXTI_IMR2_IM33_Pos       (1U)
#define EXTI_IMR2_IM33_Msk       (0x1UL << EXTI_IMR2_IM33_Pos)                 /*!< 0x00000002 */
#define EXTI_IMR2_IM33           EXTI_IMR2_IM33_Msk                            /*!< CPU1 Interrupt Mask on line 33 */
#define EXTI_IMR2_IM36_Pos       (4U)
#define EXTI_IMR2_IM36_Msk       (0x1UL << EXTI_IMR2_IM36_Pos)                 /*!< 0x00000010 */
#define EXTI_IMR2_IM36           EXTI_IMR2_IM36_Msk                            /*!< CPU1 Interrupt Mask on line 36 */
#define EXTI_IMR2_IM37_Pos       (5U)
#define EXTI_IMR2_IM37_Msk       (0x1UL << EXTI_IMR2_IM37_Pos)                 /*!< 0x00000020 */
#define EXTI_IMR2_IM37           EXTI_IMR2_IM37_Msk                            /*!< CPU1 Interrupt Mask on line 37 */
#define EXTI_IMR2_IM38_Pos       (6U)
#define EXTI_IMR2_IM38_Msk       (0x1UL << EXTI_IMR2_IM38_Pos)                 /*!< 0x00000040 */
#define EXTI_IMR2_IM38           EXTI_IMR2_IM38_Msk                            /*!< CPU1 Interrupt Mask on line 38 */
#define EXTI_IMR2_IM39_Pos       (7U)
#define EXTI_IMR2_IM39_Msk       (0x1UL << EXTI_IMR2_IM39_Pos)                 /*!< 0x00000080 */
#define EXTI_IMR2_IM39           EXTI_IMR2_IM39_Msk                            /*!< CPU1 Interrupt Mask on line 39 */
#define EXTI_IMR2_IM40_Pos       (8U)
#define EXTI_IMR2_IM40_Msk       (0x1UL << EXTI_IMR2_IM40_Pos)                 /*!< 0x00000100 */
#define EXTI_IMR2_IM40           EXTI_IMR2_IM40_Msk                            /*!< CPU1 Interrupt Mask on line 40 */
#define EXTI_IMR2_IM41_Pos       (9U)
#define EXTI_IMR2_IM41_Msk       (0x1UL << EXTI_IMR2_IM41_Pos)                 /*!< 0x00000200 */
#define EXTI_IMR2_IM41           EXTI_IMR2_IM41_Msk                            /*!< CPU1 Interrupt Mask on line 41 */
#define EXTI_IMR2_IM42_Pos       (10U)
#define EXTI_IMR2_IM42_Msk       (0x1UL << EXTI_IMR2_IM42_Pos)                 /*!< 0x00000400 */
#define EXTI_IMR2_IM42           EXTI_IMR2_IM42_Msk                            /*!< CPU1 Interrupt Mask on line 42 */
#define EXTI_IMR2_IM44_Pos       (12U)
#define EXTI_IMR2_IM44_Msk       (0x1UL << EXTI_IMR2_IM44_Pos)                 /*!< 0x00001000 */
#define EXTI_IMR2_IM44           EXTI_IMR2_IM44_Msk                            /*!< CPU1 Interrupt Mask on line 44 */
#define EXTI_IMR2_IM45_Pos       (13U)
#define EXTI_IMR2_IM45_Msk       (0x1UL << EXTI_IMR2_IM45_Pos)                 /*!< 0x00002000 */
#define EXTI_IMR2_IM45           EXTI_IMR2_IM45_Msk                            /*!< CPU1 Interrupt Mask on line 45 */
#define EXTI_IMR2_IM48_Pos       (16U)
#define EXTI_IMR2_IM48_Msk       (0x1UL << EXTI_IMR2_IM48_Pos)                 /*!< 0x00010000 */
#define EXTI_IMR2_IM48           EXTI_IMR2_IM48_Msk                            /*!< CPU1 Interrupt Mask on line 48 */

/********************  Bits definition for EXTI_EMR2 register  ****************/
#define EXTI_EMR2_Pos            (0U)
#define EXTI_EMR2_Msk            (0x00000300UL << EXTI_EMR2_Pos)               /*!< 0x000003000 */
#define EXTI_EMR2_EM             EXTI_EMR2_Msk                                 /*!< CPU1 Interrupt Mask  */
#define EXTI_EMR2_EM40_Pos       (8U)
#define EXTI_EMR2_EM40_Msk       (0x1UL << EXTI_EMR2_EM40_Pos)                 /*!< 0x00000100 */
#define EXTI_EMR2_EM40           EXTI_EMR2_EM40_Msk                            /*!< CPU1 Event Mask on line 40 */
#define EXTI_EMR2_EM41_Pos       (9U)
#define EXTI_EMR2_EM41_Msk       (0x1UL << EXTI_EMR2_EM41_Pos)                 /*!< 0x00000200 */
#define EXTI_EMR2_EM41           EXTI_EMR2_EM41_Msk                            /*!< CPU1 Event Mask on line 41 */

/********************  Bits definition for EXTI_C2IMR1 register  **************/
#define EXTI_C2IMR1_Pos          (0U)
#define EXTI_C2IMR1_Msk          (0xFFFFFFFFUL << EXTI_C2IMR1_Pos)             /*!< 0xFFFFFFFF */
#define EXTI_C2IMR1_IM           EXTI_C2IMR1_Msk                               /*!< CPU2 wakeup with interrupt Mask on Event */
#define EXTI_C2IMR1_IM0_Pos      (0U)
#define EXTI_C2IMR1_IM0_Msk      (0x1UL << EXTI_C2IMR1_IM0_Pos)                /*!< 0x00000001 */
#define EXTI_C2IMR1_IM0          EXTI_C2IMR1_IM0_Msk                           /*!< CPU2 Interrupt Mask on line 0 */
#define EXTI_C2IMR1_IM1_Pos      (1U)
#define EXTI_C2IMR1_IM1_Msk      (0x1UL << EXTI_C2IMR1_IM1_Pos)                /*!< 0x00000002 */
#define EXTI_C2IMR1_IM1          EXTI_C2IMR1_IM1_Msk                           /*!< CPU2 Interrupt Mask on line 1 */
#define EXTI_C2IMR1_IM2_Pos      (2U)
#define EXTI_C2IMR1_IM2_Msk      (0x1UL << EXTI_C2IMR1_IM2_Pos)                /*!< 0x00000004 */
#define EXTI_C2IMR1_IM2          EXTI_C2IMR1_IM2_Msk                           /*!< CPU2 Interrupt Mask on line 2 */
#define EXTI_C2IMR1_IM3_Pos      (3U)
#define EXTI_C2IMR1_IM3_Msk      (0x1UL << EXTI_C2IMR1_IM3_Pos)                /*!< 0x00000008 */
#define EXTI_C2IMR1_IM3          EXTI_C2IMR1_IM3_Msk                           /*!< CPU2 Interrupt Mask on line 3 */
#define EXTI_C2IMR1_IM4_Pos      (4U)
#define EXTI_C2IMR1_IM4_Msk      (0x1UL << EXTI_C2IMR1_IM4_Pos)                /*!< 0x00000010 */
#define EXTI_C2IMR1_IM4          EXTI_C2IMR1_IM4_Msk                           /*!< CPU2 Interrupt Mask on line 4 */
#define EXTI_C2IMR1_IM5_Pos      (5U)
#define EXTI_C2IMR1_IM5_Msk      (0x1UL << EXTI_C2IMR1_IM5_Pos)                /*!< 0x00000020 */
#define EXTI_C2IMR1_IM5          EXTI_C2IMR1_IM5_Msk                           /*!< CPU2 Interrupt Mask on line 5 */
#define EXTI_C2IMR1_IM6_Pos      (6U)
#define EXTI_C2IMR1_IM6_Msk      (0x1UL << EXTI_C2IMR1_IM6_Pos)                /*!< 0x00000040 */
#define EXTI_C2IMR1_IM6          EXTI_C2IMR1_IM6_Msk                           /*!< CPU2 Interrupt Mask on line 6 */
#define EXTI_C2IMR1_IM7_Pos      (7U)
#define EXTI_C2IMR1_IM7_Msk      (0x1UL << EXTI_C2IMR1_IM7_Pos)                /*!< 0x00000080 */
#define EXTI_C2IMR1_IM7          EXTI_C2IMR1_IM7_Msk                           /*!< CPU2 Interrupt Mask on line 7 */
#define EXTI_C2IMR1_IM8_Pos      (8U)
#define EXTI_C2IMR1_IM8_Msk      (0x1UL << EXTI_C2IMR1_IM8_Pos)                /*!< 0x00000100 */
#define EXTI_C2IMR1_IM8          EXTI_C2IMR1_IM8_Msk                           /*!< CPU2 Interrupt Mask on line 8 */
#define EXTI_C2IMR1_IM9_Pos      (9U)
#define EXTI_C2IMR1_IM9_Msk      (0x1UL << EXTI_C2IMR1_IM9_Pos)                /*!< 0x00000200 */
#define EXTI_C2IMR1_IM9          EXTI_C2IMR1_IM9_Msk                           /*!< CPU2 Interrupt Mask on line 9 */
#define EXTI_C2IMR1_IM10_Pos     (10U)
#define EXTI_C2IMR1_IM10_Msk     (0x1UL << EXTI_C2IMR1_IM10_Pos)               /*!< 0x00000400 */
#define EXTI_C2IMR1_IM10         EXTI_C2IMR1_IM10_Msk                          /*!< CPU2 Interrupt Mask on line 10 */
#define EXTI_C2IMR1_IM11_Pos     (11U)
#define EXTI_C2IMR1_IM11_Msk     (0x1UL << EXTI_C2IMR1_IM11_Pos)               /*!< 0x00000800 */
#define EXTI_C2IMR1_IM11         EXTI_C2IMR1_IM11_Msk                          /*!< CPU2 Interrupt Mask on line 11 */
#define EXTI_C2IMR1_IM12_Pos     (12U)
#define EXTI_C2IMR1_IM12_Msk     (0x1UL << EXTI_C2IMR1_IM12_Pos)               /*!< 0x00001000 */
#define EXTI_C2IMR1_IM12         EXTI_C2IMR1_IM12_Msk                          /*!< CPU2 Interrupt Mask on line 12 */
#define EXTI_C2IMR1_IM13_Pos     (13U)
#define EXTI_C2IMR1_IM13_Msk     (0x1UL << EXTI_C2IMR1_IM13_Pos)               /*!< 0x00002000 */
#define EXTI_C2IMR1_IM13         EXTI_C2IMR1_IM13_Msk                          /*!< CPU2 Interrupt Mask on line 13 */
#define EXTI_C2IMR1_IM14_Pos     (14U)
#define EXTI_C2IMR1_IM14_Msk     (0x1UL << EXTI_C2IMR1_IM14_Pos)               /*!< 0x00004000 */
#define EXTI_C2IMR1_IM14         EXTI_C2IMR1_IM14_Msk                          /*!< CPU2 Interrupt Mask on line 14 */
#define EXTI_C2IMR1_IM15_Pos     (15U)
#define EXTI_C2IMR1_IM15_Msk     (0x1UL << EXTI_C2IMR1_IM15_Pos)               /*!< 0x00008000 */
#define EXTI_C2IMR1_IM15         EXTI_C2IMR1_IM15_Msk                          /*!< CPU2 Interrupt Mask on line 15 */
#define EXTI_C2IMR1_IM16_Pos     (16U)
#define EXTI_C2IMR1_IM16_Msk     (0x1UL << EXTI_C2IMR1_IM16_Pos)               /*!< 0x00010000 */
#define EXTI_C2IMR1_IM16         EXTI_C2IMR1_IM16_Msk                          /*!< CPU2 Interrupt Mask on line 16 */
#define EXTI_C2IMR1_IM17_Pos     (17U)
#define EXTI_C2IMR1_IM17_Msk     (0x1UL << EXTI_C2IMR1_IM17_Pos)               /*!< 0x00020000 */
#define EXTI_C2IMR1_IM17         EXTI_C2IMR1_IM17_Msk                          /*!< CPU2 Interrupt Mask on line 17 */
#define EXTI_C2IMR1_IM18_Pos     (18U)
#define EXTI_C2IMR1_IM18_Msk     (0x1UL << EXTI_C2IMR1_IM18_Pos)               /*!< 0x00040000 */
#define EXTI_C2IMR1_IM18         EXTI_C2IMR1_IM18_Msk                          /*!< CPU2 Interrupt Mask on line 18 */
#define EXTI_C2IMR1_IM19_Pos     (19U)
#define EXTI_C2IMR1_IM19_Msk     (0x1UL << EXTI_C2IMR1_IM19_Pos)               /*!< 0x00080000 */
#define EXTI_C2IMR1_IM19         EXTI_C2IMR1_IM19_Msk                          /*!< CPU2 Interrupt Mask on line 19 */
#define EXTI_C2IMR1_IM20_Pos     (20U)
#define EXTI_C2IMR1_IM20_Msk     (0x1UL << EXTI_C2IMR1_IM20_Pos)               /*!< 0x00100000 */
#define EXTI_C2IMR1_IM20         EXTI_C2IMR1_IM20_Msk                          /*!< CPU2 Interrupt Mask on line 20 */
#define EXTI_C2IMR1_IM22_Pos     (22U)
#define EXTI_C2IMR1_IM22_Msk     (0x1UL << EXTI_C2IMR1_IM22_Pos)               /*!< 0x00400000 */
#define EXTI_C2IMR1_IM22         EXTI_C2IMR1_IM22_Msk                          /*!< CPU2 Interrupt Mask on line 22 */
#define EXTI_C2IMR1_IM24_Pos     (24U)
#define EXTI_C2IMR1_IM24_Msk     (0x1UL << EXTI_C2IMR1_IM24_Pos)               /*!< 0x01000000 */
#define EXTI_C2IMR1_IM24         EXTI_C2IMR1_IM24_Msk                          /*!< CPU2 Interrupt Mask on line 24 */
#define EXTI_C2IMR1_IM25_Pos     (25U)
#define EXTI_C2IMR1_IM25_Msk     (0x1UL << EXTI_C2IMR1_IM25_Pos)               /*!< 0x02000000 */
#define EXTI_C2IMR1_IM25         EXTI_C2IMR1_IM25_Msk                          /*!< CPU2 Interrupt Mask on line 25 */
#define EXTI_C2IMR1_IM29_Pos     (29U)
#define EXTI_C2IMR1_IM29_Msk     (0x1UL << EXTI_C2IMR1_IM29_Pos)               /*!< 0x20000000 */
#define EXTI_C2IMR1_IM29         EXTI_C2IMR1_IM29_Msk                          /*!< CPU2 Interrupt Mask on line 29 */
#define EXTI_C2IMR1_IM30_Pos     (30U)
#define EXTI_C2IMR1_IM30_Msk     (0x1UL << EXTI_C2IMR1_IM30_Pos)               /*!< 0x40000000 */
#define EXTI_C2IMR1_IM30         EXTI_C2IMR1_IM30_Msk                          /*!< CPU2 Interrupt Mask on line 30 */
#define EXTI_C2IMR1_IM31_Pos     (31U)
#define EXTI_C2IMR1_IM31_Msk     (0x1UL << EXTI_C2IMR1_IM31_Pos)               /*!< 0x80000000 */
#define EXTI_C2IMR1_IM31         EXTI_C2IMR1_IM31_Msk                          /*!< CPU2 Interrupt Mask on line 31 */

/********************  Bits definition for EXTI_C2EMR1 register  **************/
#define EXTI_C2EMR1_Pos          (0U)
#define EXTI_C2EMR1_Msk          (0x003EFFFFUL << EXTI_C2EMR1_Pos)             /*!< 0xFFFFFFFF */
#define EXTI_C2EMR1_EM           EXTI_C2EMR1_Msk                               /*!< CPU2 Event Mask */
#define EXTI_C2EMR1_EM0_Pos      (0U)
#define EXTI_C2EMR1_EM0_Msk      (0x1UL << EXTI_C2EMR1_EM0_Pos)                /*!< 0x00000001 */
#define EXTI_C2EMR1_EM0          EXTI_C2EMR1_EM0_Msk                           /*!< CPU2 Event Mask on line 0 */
#define EXTI_C2EMR1_EM1_Pos      (1U)
#define EXTI_C2EMR1_EM1_Msk      (0x1UL << EXTI_C2EMR1_EM1_Pos)                /*!< 0x00000002 */
#define EXTI_C2EMR1_EM1          EXTI_C2EMR1_EM1_Msk                           /*!< CPU2 Event Mask on line 1 */
#define EXTI_C2EMR1_EM2_Pos      (2U)
#define EXTI_C2EMR1_EM2_Msk      (0x1UL << EXTI_C2EMR1_EM2_Pos)                /*!< 0x00000004 */
#define EXTI_C2EMR1_EM2          EXTI_C2EMR1_EM2_Msk                           /*!< CPU2 Event Mask on line 2 */
#define EXTI_C2EMR1_EM3_Pos      (3U)
#define EXTI_C2EMR1_EM3_Msk      (0x1UL << EXTI_C2EMR1_EM3_Pos)                /*!< 0x00000008 */
#define EXTI_C2EMR1_EM3          EXTI_C2EMR1_EM3_Msk                           /*!< CPU2 Event Mask on line 3 */
#define EXTI_C2EMR1_EM4_Pos      (4U)
#define EXTI_C2EMR1_EM4_Msk      (0x1UL << EXTI_C2EMR1_EM4_Pos)                /*!< 0x00000010 */
#define EXTI_C2EMR1_EM4          EXTI_C2EMR1_EM4_Msk                           /*!< CPU2 Event Mask on line 4 */
#define EXTI_C2EMR1_EM5_Pos      (5U)
#define EXTI_C2EMR1_EM5_Msk      (0x1UL << EXTI_C2EMR1_EM5_Pos)                /*!< 0x00000020 */
#define EXTI_C2EMR1_EM5          EXTI_C2EMR1_EM5_Msk                           /*!< CPU2 Event Mask on line 5 */
#define EXTI_C2EMR1_EM6_Pos      (6U)
#define EXTI_C2EMR1_EM6_Msk      (0x1UL << EXTI_C2EMR1_EM6_Pos)                /*!< 0x00000040 */
#define EXTI_C2EMR1_EM6          EXTI_C2EMR1_EM6_Msk                           /*!< CPU2 Event Mask on line 6 */
#define EXTI_C2EMR1_EM7_Pos      (7U)
#define EXTI_C2EMR1_EM7_Msk      (0x1UL << EXTI_C2EMR1_EM7_Pos)                /*!< 0x00000080 */
#define EXTI_C2EMR1_EM7          EXTI_C2EMR1_EM7_Msk                           /*!< CPU2 Event Mask on line 7 */
#define EXTI_C2EMR1_EM8_Pos      (8U)
#define EXTI_C2EMR1_EM8_Msk      (0x1UL << EXTI_C2EMR1_EM8_Pos)                /*!< 0x00000100 */
#define EXTI_C2EMR1_EM8          EXTI_C2EMR1_EM8_Msk                           /*!< CPU2 Event Mask on line 8 */
#define EXTI_C2EMR1_EM9_Pos      (9U)
#define EXTI_C2EMR1_EM9_Msk      (0x1UL << EXTI_C2EMR1_EM9_Pos)                /*!< 0x00000200 */
#define EXTI_C2EMR1_EM9          EXTI_C2EMR1_EM9_Msk                           /*!< CPU2 Event Mask on line 9 */
#define EXTI_C2EMR1_EM10_Pos     (10U)
#define EXTI_C2EMR1_EM10_Msk     (0x1UL << EXTI_C2EMR1_EM10_Pos)               /*!< 0x00000400 */
#define EXTI_C2EMR1_EM10         EXTI_C2EMR1_EM10_Msk                          /*!< CPU2 Event Mask on line 10 */
#define EXTI_C2EMR1_EM11_Pos     (11U)
#define EXTI_C2EMR1_EM11_Msk     (0x1UL << EXTI_C2EMR1_EM11_Pos)               /*!< 0x00000800 */
#define EXTI_C2EMR1_EM11         EXTI_C2EMR1_EM11_Msk                          /*!< CPU2 Event Mask on line 11 */
#define EXTI_C2EMR1_EM12_Pos     (12U)
#define EXTI_C2EMR1_EM12_Msk     (0x1UL << EXTI_C2EMR1_EM12_Pos)               /*!< 0x00001000 */
#define EXTI_C2EMR1_EM12         EXTI_C2EMR1_EM12_Msk                          /*!< CPU2 Event Mask on line 12 */
#define EXTI_C2EMR1_EM13_Pos     (13U)
#define EXTI_C2EMR1_EM13_Msk     (0x1UL << EXTI_C2EMR1_EM13_Pos)               /*!< 0x00002000 */
#define EXTI_C2EMR1_EM13         EXTI_C2EMR1_EM13_Msk                          /*!< CPU2 Event Mask on line 13 */
#define EXTI_C2EMR1_EM14_Pos     (14U)
#define EXTI_C2EMR1_EM14_Msk     (0x1UL << EXTI_C2EMR1_EM14_Pos)               /*!< 0x00004000 */
#define EXTI_C2EMR1_EM14         EXTI_C2EMR1_EM14_Msk                          /*!< CPU2 Event Mask on line 14 */
#define EXTI_C2EMR1_EM15_Pos     (15U)
#define EXTI_C2EMR1_EM15_Msk     (0x1UL << EXTI_C2EMR1_EM15_Pos)               /*!< 0x00008000 */
#define EXTI_C2EMR1_EM15         EXTI_C2EMR1_EM15_Msk                          /*!< CPU2 Event Mask on line 15 */
#define EXTI_C2EMR1_EM17_Pos     (17U)
#define EXTI_C2EMR1_EM17_Msk     (0x1UL << EXTI_C2EMR1_EM17_Pos)               /*!< 0x00020000 */
#define EXTI_C2EMR1_EM17         EXTI_C2EMR1_EM17_Msk                          /*!< CPU2 Event Mask on line 17 */
#define EXTI_C2EMR1_EM18_Pos     (18U)
#define EXTI_C2EMR1_EM18_Msk     (0x1UL << EXTI_C2EMR1_EM18_Pos)               /*!< 0x00040000 */
#define EXTI_C2EMR1_EM18         EXTI_C2EMR1_EM18_Msk                          /*!< CPU2 Event Mask on line 18 */
#define EXTI_C2EMR1_EM19_Pos     (19U)
#define EXTI_C2EMR1_EM19_Msk     (0x1UL << EXTI_C2EMR1_EM19_Pos)               /*!< 0x00080000 */
#define EXTI_C2EMR1_EM19         EXTI_C2EMR1_EM19_Msk                          /*!< CPU2 Event Mask on line 19 */
#define EXTI_C2EMR1_EM20_Pos     (20U)
#define EXTI_C2EMR1_EM20_Msk     (0x1UL << EXTI_C2EMR1_EM20_Pos)               /*!< 0x00100000 */
#define EXTI_C2EMR1_EM20         EXTI_C2EMR1_EM20_Msk                          /*!< CPU2 Event Mask on line 20 */

/********************  Bits definition for EXTI_C2IMR2 register  **************/
#define EXTI_C2IMR2_Pos          (0U)
#define EXTI_C2IMR2_Msk          (0x0001FFFFUL << EXTI_C2IMR2_Pos)             /*!< 0x0001FFFF */
#define EXTI_C2IMR2_IM           EXTI_C2IMR2_Msk                               /*!< CPU2 Interrupt Mask  */
#define EXTI_C2IMR2_IM33_Pos     (1U)
#define EXTI_C2IMR2_IM33_Msk     (0x1UL << EXTI_C2IMR2_IM33_Pos)               /*!< 0x00000002 */
#define EXTI_C2IMR2_IM33         EXTI_C2IMR2_IM33_Msk                          /*!< CPU2 Interrupt Mask on line 33 */
#define EXTI_C2IMR2_IM36_Pos     (4U)
#define EXTI_C2IMR2_IM36_Msk     (0x1UL << EXTI_C2IMR2_IM36_Pos)               /*!< 0x00000010 */
#define EXTI_C2IMR2_IM36         EXTI_C2IMR2_IM36_Msk                          /*!< CPU2 Interrupt Mask on line 36 */
#define EXTI_C2IMR2_IM37_Pos     (5U)
#define EXTI_C2IMR2_IM37_Msk     (0x1UL << EXTI_C2IMR2_IM37_Pos)               /*!< 0x00000020 */
#define EXTI_C2IMR2_IM37         EXTI_C2IMR2_IM37_Msk                          /*!< CPU2 Interrupt Mask on line 37 */
#define EXTI_C2IMR2_IM38_Pos     (6U)
#define EXTI_C2IMR2_IM38_Msk     (0x1UL << EXTI_C2IMR2_IM38_Pos)               /*!< 0x00000040 */
#define EXTI_C2IMR2_IM38         EXTI_C2IMR2_IM38_Msk                          /*!< CPU2 Interrupt Mask on line 38 */
#define EXTI_C2IMR2_IM39_Pos     (7U)
#define EXTI_C2IMR2_IM39_Msk     (0x1UL << EXTI_C2IMR2_IM39_Pos)               /*!< 0x00000080 */
#define EXTI_C2IMR2_IM39         EXTI_C2IMR2_IM39_Msk                          /*!< CPU2 Interrupt Mask on line 39 */
#define EXTI_C2IMR2_IM40_Pos     (8U)
#define EXTI_C2IMR2_IM40_Msk     (0x1UL << EXTI_C2IMR2_IM40_Pos)               /*!< 0x00000100 */
#define EXTI_C2IMR2_IM40         EXTI_C2IMR2_IM40_Msk                          /*!< CPU2 Interrupt Mask on line 40 */
#define EXTI_C2IMR2_IM41_Pos     (9U)
#define EXTI_C2IMR2_IM41_Msk     (0x1UL << EXTI_C2IMR2_IM41_Pos)               /*!< 0x00000200 */
#define EXTI_C2IMR2_IM41         EXTI_C2IMR2_IM41_Msk                          /*!< CPU2 Interrupt Mask on line 41 */
#define EXTI_C2IMR2_IM42_Pos     (10U)
#define EXTI_C2IMR2_IM42_Msk     (0x1UL << EXTI_C2IMR2_IM42_Pos)               /*!< 0x00000400 */
#define EXTI_C2IMR2_IM42         EXTI_C2IMR2_IM42_Msk                          /*!< CPU2 Interrupt Mask on line 42 */
#define EXTI_C2IMR2_IM44_Pos     (12U)
#define EXTI_C2IMR2_IM44_Msk     (0x1UL << EXTI_C2IMR2_IM44_Pos)               /*!< 0x00001000 */
#define EXTI_C2IMR2_IM44         EXTI_C2IMR2_IM44_Msk                          /*!< CPU2 Interrupt Mask on line 44 */
#define EXTI_C2IMR2_IM45_Pos     (13U)
#define EXTI_C2IMR2_IM45_Msk     (0x1UL << EXTI_C2IMR2_IM45_Pos)               /*!< 0x00002000 */
#define EXTI_C2IMR2_IM45         EXTI_C2IMR2_IM45_Msk                          /*!< CPU2 Interrupt Mask on line 45 */
#define EXTI_C2IMR2_IM48_Pos     (16U)
#define EXTI_C2IMR2_IM48_Msk     (0x1UL << EXTI_C2IMR2_IM48_Pos)               /*!< 0x00010000 */
#define EXTI_C2IMR2_IM48         EXTI_C2IMR2_IM48_Msk                          /*!< CPU2 Interrupt Mask on line 48 */

/********************  Bits definition for EXTI_C2EMR2 register  **************/
#define EXTI_C2EMR2_Pos          (8U)
#define EXTI_C2EMR2_Msk          (0x00000300UL << EXTI_C2EMR2_Pos)             /*!< 0x000003000 */
#define EXTI_C2EMR2_EM           EXTI_C2EMR2_Msk                               /*!< CPU2 Interrupt Mask  */
#define EXTI_C2EMR2_EM40_Pos     (8U)
#define EXTI_C2EMR2_EM40_Msk     (0x1UL << EXTI_C2EMR2_EM40_Pos)               /*!< 0x00000100 */
#define EXTI_C2EMR2_EM40         EXTI_C2EMR2_EM40_Msk                          /*!< CPU2 Event Mask on line 40 */
#define EXTI_C2EMR2_EM41_Pos     (9U)
#define EXTI_C2EMR2_EM41_Msk     (0x1UL << EXTI_C2EMR2_EM41_Pos)               /*!< 0x00000200 */
#define EXTI_C2EMR2_EM41         EXTI_C2EMR2_EM41_Msk                          /*!< CPU2 Event Mask on line 41 */

/******************************************************************************/
/*                                                                            */
/*                       Public Key Accelerator (PKA)                         */
/*                                                                            */
/******************************************************************************/

/*******************  Bits definition for PKA_CR register  **************/
#define PKA_CR_EN_Pos              (0U)
#define PKA_CR_EN_Msk              (0x1UL << PKA_CR_EN_Pos)                /*!< 0x00000001 */
#define PKA_CR_EN                  PKA_CR_EN_Msk                           /*!< PKA enable */
#define PKA_CR_START_Pos           (1U)
#define PKA_CR_START_Msk           (0x1UL << PKA_CR_START_Pos)             /*!< 0x00000002 */
#define PKA_CR_START               PKA_CR_START_Msk                        /*!< Start operation */
#define PKA_CR_MODE_Pos            (8U)
#define PKA_CR_MODE_Msk            (0x3FUL << PKA_CR_MODE_Pos)             /*!< 0x00003F00 */
#define PKA_CR_MODE                PKA_CR_MODE_Msk                         /*!< MODE[5:0] PKA operation code */
#define PKA_CR_MODE_0              (0x01U << PKA_CR_MODE_Pos)              /*!< 0x00000100 */
#define PKA_CR_MODE_1              (0x02U << PKA_CR_MODE_Pos)              /*!< 0x00000200 */
#define PKA_CR_MODE_2              (0x04U << PKA_CR_MODE_Pos)              /*!< 0x00000400 */
#define PKA_CR_MODE_3              (0x08U << PKA_CR_MODE_Pos)              /*!< 0x00000800 */
#define PKA_CR_MODE_4              (0x10U << PKA_CR_MODE_Pos)              /*!< 0x00001000 */
#define PKA_CR_MODE_5              (0x20U << PKA_CR_MODE_Pos)              /*!< 0x00002000 */
#define PKA_CR_PROCENDIE_Pos       (17U)
#define PKA_CR_PROCENDIE_Msk       (0x1UL << PKA_CR_PROCENDIE_Pos)         /*!< 0x00020000 */
#define PKA_CR_PROCENDIE           PKA_CR_PROCENDIE_Msk                    /*!< End of operation interrupt enable */
#define PKA_CR_RAMERRIE_Pos        (19U)
#define PKA_CR_RAMERRIE_Msk        (0x1UL << PKA_CR_RAMERRIE_Pos)          /*!< 0x00080000 */
#define PKA_CR_RAMERRIE            PKA_CR_RAMERRIE_Msk                     /*!< RAM error interrupt enable */
#define PKA_CR_ADDRERRIE_Pos       (20U)
#define PKA_CR_ADDRERRIE_Msk       (0x1UL << PKA_CR_ADDRERRIE_Pos)         /*!< 0x00100000 */
#define PKA_CR_ADDRERRIE           PKA_CR_ADDRERRIE_Msk                    /*!< RAM error interrupt enable */

/*******************  Bits definition for PKA_SR register  **************/
#define PKA_SR_BUSY_Pos            (16U)
#define PKA_SR_BUSY_Msk            (0x1UL << PKA_SR_BUSY_Pos)              /*!< 0x00010000 */
#define PKA_SR_BUSY                PKA_SR_BUSY_Msk                         /*!< PKA operation is in progress */
#define PKA_SR_PROCENDF_Pos        (17U)
#define PKA_SR_PROCENDF_Msk        (0x1UL << PKA_SR_PROCENDF_Pos)          /*!< 0x00020000 */
#define PKA_SR_PROCENDF            PKA_SR_PROCENDF_Msk                     /*!< PKA end of operation flag */
#define PKA_SR_RAMERRF_Pos         (19U)
#define PKA_SR_RAMERRF_Msk         (0x1UL << PKA_SR_RAMERRF_Pos)           /*!< 0x00080000 */
#define PKA_SR_RAMERRF             PKA_SR_RAMERRF_Msk                      /*!< PKA RAM error flag */
#define PKA_SR_ADDRERRF_Pos        (20U)
#define PKA_SR_ADDRERRF_Msk        (0x1UL << PKA_SR_ADDRERRF_Pos)          /*!< 0x00100000 */
#define PKA_SR_ADDRERRF            PKA_SR_ADDRERRF_Msk                     /*!< Address error flag */

/*******************  Bits definition for PKA_CLRFR register  **************/
#define PKA_CLRFR_PROCENDFC_Pos    (17U)
#define PKA_CLRFR_PROCENDFC_Msk    (0x1UL << PKA_CLRFR_PROCENDFC_Pos)      /*!< 0x00020000 */
#define PKA_CLRFR_PROCENDFC        PKA_CLRFR_PROCENDFC_Msk                 /*!< Clear PKA end of operation flag */
#define PKA_CLRFR_RAMERRFC_Pos     (19U)
#define PKA_CLRFR_RAMERRFC_Msk     (0x1UL << PKA_CLRFR_RAMERRFC_Pos)       /*!< 0x00080000 */
#define PKA_CLRFR_RAMERRFC         PKA_CLRFR_RAMERRFC_Msk                  /*!< Clear PKA RAM error flag */
#define PKA_CLRFR_ADDRERRFC_Pos    (20U)
#define PKA_CLRFR_ADDRERRFC_Msk    (0x1UL << PKA_CLRFR_ADDRERRFC_Pos)      /*!< 0x00100000 */
#define PKA_CLRFR_ADDRERRFC        PKA_CLRFR_ADDRERRFC_Msk                 /*!< Clear address error flag */

/*******************  Bits definition for PKA RAM  *************************/
#define PKA_RAM_OFFSET                            0x400U                           /*!< PKA RAM address offset */

/* Compute Montgomery parameter input data */
#define PKA_MONTGOMERY_PARAM_IN_MOD_NB_BITS       ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input modulus number of bits */
#define PKA_MONTGOMERY_PARAM_IN_MODULUS           ((0xD5CU - PKA_RAM_OFFSET)>>2)   /*!< Input modulus */

/* Compute Montgomery parameter output data */
#define PKA_MONTGOMERY_PARAM_OUT_PARAMETER        ((0x594U - PKA_RAM_OFFSET)>>2)   /*!< Output Montgomery parameter */

/* Compute modular exponentiation input data */
#define PKA_MODULAR_EXP_IN_EXP_NB_BITS            ((0x400U - PKA_RAM_OFFSET)>>2)   /*!< Input exponent number of bits */
#define PKA_MODULAR_EXP_IN_OP_NB_BITS             ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_MODULAR_EXP_IN_MONTGOMERY_PARAM       ((0x594U - PKA_RAM_OFFSET)>>2)   /*!< Input storage area for Montgomery parameter */
#define PKA_MODULAR_EXP_IN_EXPONENT_BASE          ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input base of the exponentiation */
#define PKA_MODULAR_EXP_IN_EXPONENT               ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Input exponent to process */
#define PKA_MODULAR_EXP_IN_MODULUS                ((0xD5CU - PKA_RAM_OFFSET)>>2)   /*!< Input modulus */

/* Compute modular exponentiation output data */
#define PKA_MODULAR_EXP_OUT_MONTGOMERY_PARAM      ((0x594U - PKA_RAM_OFFSET)>>2)   /*!< Output storage area for Montgomery parameter */
#define PKA_MODULAR_EXP_OUT_SM_ALGO_ACC1          ((0x724U - PKA_RAM_OFFSET)>>2)   /*!< Output SM algorithm accumulator 1 */
#define PKA_MODULAR_EXP_OUT_SM_ALGO_ACC2          ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Output SM algorithm accumulator 2 */
#define PKA_MODULAR_EXP_OUT_EXPONENT_BASE         ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Output base of the exponentiation */
#define PKA_MODULAR_EXP_OUT_SM_ALGO_ACC3          ((0xE3CU - PKA_RAM_OFFSET)>>2)   /*!< Output SM algorithm accumulator 3 */

/* Compute ECC scalar multiplication input data */
#define PKA_ECC_SCALAR_MUL_IN_EXP_NB_BITS         ((0x400U - PKA_RAM_OFFSET)>>2)   /*!< Input exponent number of bits */
#define PKA_ECC_SCALAR_MUL_IN_OP_NB_BITS          ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_ECC_SCALAR_MUL_IN_A_COEFF_SIGN        ((0x408U - PKA_RAM_OFFSET)>>2)   /*!< Input sign of the 'a' coefficient */
#define PKA_ECC_SCALAR_MUL_IN_A_COEFF             ((0x40CU - PKA_RAM_OFFSET)>>2)   /*!< Input ECC curve 'a' coefficient */
#define PKA_ECC_SCALAR_MUL_IN_MOD_GF              ((0x460U - PKA_RAM_OFFSET)>>2)   /*!< Input modulus GF(p) */
#define PKA_ECC_SCALAR_MUL_IN_MONTGOMERY_PARAM    ((0x4B4U - PKA_RAM_OFFSET)>>2)   /*!< Input storage area for Montgomery parameter */
#define PKA_ECC_SCALAR_MUL_IN_K                   ((0x508U - PKA_RAM_OFFSET)>>2)   /*!< Input 'k' of KP */
#define PKA_ECC_SCALAR_MUL_IN_INITIAL_POINT_X     ((0x55CU - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P X coordinate */
#define PKA_ECC_SCALAR_MUL_IN_INITIAL_POINT_Y     ((0x5B0U - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P Y coordinate */

/* Compute ECC scalar multiplication output data */
#define PKA_ECC_SCALAR_MUL_OUT_RESULT_X           ((0x55CU - PKA_RAM_OFFSET)>>2)   /*!< Output result X coordinate */
#define PKA_ECC_SCALAR_MUL_OUT_RESULT_Y           ((0x5B0U - PKA_RAM_OFFSET)>>2)   /*!< Output result Y coordinate */
#define PKA_ECC_SCALAR_MUL_OUT_LAST_DOUBLE_X1     ((0xDE8U - PKA_RAM_OFFSET)>>2)   /*!< Output last double X1 coordinate */
#define PKA_ECC_SCALAR_MUL_OUT_LAST_DOUBLE_Y1     ((0xE3CU - PKA_RAM_OFFSET)>>2)   /*!< Output last double Y1 coordinate */
#define PKA_ECC_SCALAR_MUL_OUT_LAST_DOUBLE_Z1     ((0xE90U - PKA_RAM_OFFSET)>>2)   /*!< Output last double Z1 coordinate */
#define PKA_ECC_SCALAR_MUL_OUT_CHECK_POINT_X2     ((0xEE4U - PKA_RAM_OFFSET)>>2)   /*!< Output check point X2 coordinate */
#define PKA_ECC_SCALAR_MUL_OUT_CHECK_POINT_Y2     ((0xF38U - PKA_RAM_OFFSET)>>2)   /*!< Output check point Y2 coordinate */
#define PKA_ECC_SCALAR_MUL_OUT_CHECK_POINT_Z2     ((0xF8CU - PKA_RAM_OFFSET)>>2)   /*!< Output check point Z2 coordinate */

/* Point check input data */
#define PKA_POINT_CHECK_IN_MOD_NB_BITS            ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input modulus number of bits */
#define PKA_POINT_CHECK_IN_A_COEFF_SIGN           ((0x408U - PKA_RAM_OFFSET)>>2)   /*!< Input sign of the 'a' coefficient */
#define PKA_POINT_CHECK_IN_A_COEFF                ((0x40CU - PKA_RAM_OFFSET)>>2)   /*!< Input ECC curve 'a' coefficient */
#define PKA_POINT_CHECK_IN_B_COEFF                ((0x7FCU - PKA_RAM_OFFSET)>>2)   /*!< Input ECC curve 'b' coefficient */
#define PKA_POINT_CHECK_IN_MOD_GF                 ((0x460U - PKA_RAM_OFFSET)>>2)   /*!< Input modulus GF(p) */
#define PKA_POINT_CHECK_IN_INITIAL_POINT_X        ((0x55CU - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P X coordinate */
#define PKA_POINT_CHECK_IN_INITIAL_POINT_Y        ((0x5B0U - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P Y coordinate */

/* Point check output data */
#define PKA_POINT_CHECK_OUT_ERROR                 ((0x400U - PKA_RAM_OFFSET)>>2)   /*!< Output error */

/* ECDSA signature input data */
#define PKA_ECDSA_SIGN_IN_ORDER_NB_BITS           ((0x400U - PKA_RAM_OFFSET)>>2)   /*!< Input order number of bits */
#define PKA_ECDSA_SIGN_IN_MOD_NB_BITS             ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input modulus number of bits */
#define PKA_ECDSA_SIGN_IN_A_COEFF_SIGN            ((0x408U - PKA_RAM_OFFSET)>>2)   /*!< Input sign of the 'a' coefficient */
#define PKA_ECDSA_SIGN_IN_A_COEFF                 ((0x40CU - PKA_RAM_OFFSET)>>2)   /*!< Input ECC curve 'a' coefficient */
#define PKA_ECDSA_SIGN_IN_MOD_GF                  ((0x460U - PKA_RAM_OFFSET)>>2)   /*!< Input modulus GF(p) */
#define PKA_ECDSA_SIGN_IN_K                       ((0x508U - PKA_RAM_OFFSET)>>2)   /*!< Input k value of the ECDSA */
#define PKA_ECDSA_SIGN_IN_INITIAL_POINT_X         ((0x55CU - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P X coordinate */
#define PKA_ECDSA_SIGN_IN_INITIAL_POINT_Y         ((0x5B0U - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P Y coordinate */
#define PKA_ECDSA_SIGN_IN_HASH_E                  ((0xDE8U - PKA_RAM_OFFSET)>>2)   /*!< Input e, hash of the message */
#define PKA_ECDSA_SIGN_IN_PRIVATE_KEY_D           ((0xE3CU - PKA_RAM_OFFSET)>>2)   /*!< Input d, private key */
#define PKA_ECDSA_SIGN_IN_ORDER_N                 ((0xE94U - PKA_RAM_OFFSET)>>2)   /*!< Input n, order of the curve */

/* ECDSA signature output data */
#define PKA_ECDSA_SIGN_OUT_ERROR                  ((0xEE8U - PKA_RAM_OFFSET)>>2)   /*!< Output error */
#define PKA_ECDSA_SIGN_OUT_SIGNATURE_R            ((0x700U - PKA_RAM_OFFSET)>>2)   /*!< Output signature r */
#define PKA_ECDSA_SIGN_OUT_SIGNATURE_S            ((0x754U - PKA_RAM_OFFSET)>>2)   /*!< Output signature s */
#define PKA_ECDSA_SIGN_OUT_FINAL_POINT_X          ((0x103CU - PKA_RAM_OFFSET)>>2)  /*!< Output final point kP X coordinate */
#define PKA_ECDSA_SIGN_OUT_FINAL_POINT_Y          ((0x1090U - PKA_RAM_OFFSET)>>2)  /*!< Output final point kP Y coordinate */

/* ECDSA verification input data */
#define PKA_ECDSA_VERIF_IN_ORDER_NB_BITS          ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input order number of bits */
#define PKA_ECDSA_VERIF_IN_MOD_NB_BITS            ((0x4B4U - PKA_RAM_OFFSET)>>2)   /*!< Input modulus number of bits */
#define PKA_ECDSA_VERIF_IN_A_COEFF_SIGN           ((0x45CU - PKA_RAM_OFFSET)>>2)   /*!< Input sign of the 'a' coefficient */
#define PKA_ECDSA_VERIF_IN_A_COEFF                ((0x460U - PKA_RAM_OFFSET)>>2)   /*!< Input ECC curve 'a' coefficient */
#define PKA_ECDSA_VERIF_IN_MOD_GF                 ((0x4B8U - PKA_RAM_OFFSET)>>2)   /*!< Input modulus GF(p) */
#define PKA_ECDSA_VERIF_IN_INITIAL_POINT_X        ((0x5E8U - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P X coordinate */
#define PKA_ECDSA_VERIF_IN_INITIAL_POINT_Y        ((0x63CU - PKA_RAM_OFFSET)>>2)   /*!< Input initial point P Y coordinate */
#define PKA_ECDSA_VERIF_IN_PUBLIC_KEY_POINT_X     ((0xF40U - PKA_RAM_OFFSET)>>2)   /*!< Input public key point X coordinate */
#define PKA_ECDSA_VERIF_IN_PUBLIC_KEY_POINT_Y     ((0xF94U - PKA_RAM_OFFSET)>>2)   /*!< Input public key point Y coordinate */
#define PKA_ECDSA_VERIF_IN_SIGNATURE_R            ((0x1098U - PKA_RAM_OFFSET)>>2)  /*!< Input r, part of the signature */
#define PKA_ECDSA_VERIF_IN_SIGNATURE_S            ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input s, part of the signature */
#define PKA_ECDSA_VERIF_IN_HASH_E                 ((0xFE8U - PKA_RAM_OFFSET)>>2)   /*!< Input e, hash of the message */
#define PKA_ECDSA_VERIF_IN_ORDER_N                ((0xD5CU - PKA_RAM_OFFSET)>>2)   /*!< Input n, order of the curve */

/* ECDSA verification output data */
#define PKA_ECDSA_VERIF_OUT_RESULT                ((0x5B0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* RSA CRT exponentiation input data */
#define PKA_RSA_CRT_EXP_IN_MOD_NB_BITS            ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operands number of bits */
#define PKA_RSA_CRT_EXP_IN_DP_CRT                 ((0x65CU - PKA_RAM_OFFSET)>>2)   /*!< Input Dp CRT parameter */
#define PKA_RSA_CRT_EXP_IN_DQ_CRT                 ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Input Dq CRT parameter */
#define PKA_RSA_CRT_EXP_IN_QINV_CRT               ((0x7ECU - PKA_RAM_OFFSET)>>2)   /*!< Input qInv CRT parameter */
#define PKA_RSA_CRT_EXP_IN_PRIME_P                ((0x97CU - PKA_RAM_OFFSET)>>2)   /*!< Input Prime p */
#define PKA_RSA_CRT_EXP_IN_PRIME_Q                ((0xD5CU - PKA_RAM_OFFSET)>>2)   /*!< Input Prime q */
#define PKA_RSA_CRT_EXP_IN_EXPONENT_BASE          ((0xEECU - PKA_RAM_OFFSET)>>2)   /*!< Input base of the exponentiation */

/* RSA CRT exponentiation output data */
#define PKA_RSA_CRT_EXP_OUT_RESULT                ((0x724U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* Modular reduction input data */
#define PKA_MODULAR_REDUC_IN_OP_LENGTH            ((0x400U - PKA_RAM_OFFSET)>>2)   /*!< Input operand length */
#define PKA_MODULAR_REDUC_IN_OPERAND              ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Input operand */
#define PKA_MODULAR_REDUC_IN_MOD_LENGTH           ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input modulus length */
#define PKA_MODULAR_REDUC_IN_MODULUS              ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input modulus */

/* Modular reduction output data */
#define PKA_MODULAR_REDUC_OUT_RESULT              ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* Arithmetic addition input data */
#define PKA_ARITHMETIC_ADD_NB_BITS                ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_ARITHMETIC_ADD_IN_OP1                 ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op1 */
#define PKA_ARITHMETIC_ADD_IN_OP2                 ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 */

/* Arithmetic addition output data */
#define PKA_ARITHMETIC_ADD_OUT_RESULT             ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* Arithmetic subtraction input data */
#define PKA_ARITHMETIC_SUB_NB_BITS                ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_ARITHMETIC_SUB_IN_OP1                 ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op1 */
#define PKA_ARITHMETIC_SUB_IN_OP2                 ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 */

/* Arithmetic subtraction output data */
#define PKA_ARITHMETIC_SUB_OUT_RESULT             ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* Arithmetic multiplication input data */
#define PKA_ARITHMETIC_MUL_NB_BITS                ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_ARITHMETIC_MUL_IN_OP1                 ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op1 */
#define PKA_ARITHMETIC_MUL_IN_OP2                 ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 */

/* Arithmetic multiplication output data */
#define PKA_ARITHMETIC_MUL_OUT_RESULT             ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* Comparison input data */
#define PKA_COMPARISON_NB_BITS                    ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_COMPARISON_IN_OP1                     ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op1 */
#define PKA_COMPARISON_IN_OP2                     ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 */

/* Comparison output data */
#define PKA_COMPARISON_OUT_RESULT                 ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* Modular addition input data */
#define PKA_MODULAR_ADD_NB_BITS                   ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_MODULAR_ADD_IN_OP1                    ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op1 */
#define PKA_MODULAR_ADD_IN_OP2                    ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 */
#define PKA_MODULAR_ADD_IN_OP3_MOD                ((0xD5CU - PKA_RAM_OFFSET)>>2)   /*!< Input operand op3 (modulus) */

/* Modular addition output data */
#define PKA_MODULAR_ADD_OUT_RESULT                ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* Modular inversion input data */
#define PKA_MODULAR_INV_NB_BITS                   ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_MODULAR_INV_IN_OP1                    ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op1 */
#define PKA_MODULAR_INV_IN_OP2_MOD                ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 (modulus) */

/* Modular inversion output data */
#define PKA_MODULAR_INV_OUT_RESULT                ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* Modular subtraction input data */
#define PKA_MODULAR_SUB_NB_BITS                   ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_MODULAR_SUB_IN_OP1                    ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op1 */
#define PKA_MODULAR_SUB_IN_OP2                    ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 */
#define PKA_MODULAR_SUB_IN_OP3_MOD                ((0xD5CU - PKA_RAM_OFFSET)>>2)   /*!< Input operand op3 */

/* Modular subtraction output data */
#define PKA_MODULAR_SUB_OUT_RESULT                ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* Montgomery multiplication input data */
#define PKA_MONTGOMERY_MUL_NB_BITS                ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_MONTGOMERY_MUL_IN_OP1                 ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op1 */
#define PKA_MONTGOMERY_MUL_IN_OP2                 ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 */
#define PKA_MONTGOMERY_MUL_IN_OP3_MOD             ((0xD5CU - PKA_RAM_OFFSET)>>2)   /*!< Input modulus */

/* Montgomery multiplication output data */
#define PKA_MONTGOMERY_MUL_OUT_RESULT             ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/* Generic Arithmetic input data */
#define PKA_ARITHMETIC_ALL_OPS_NB_BITS            ((0x404U - PKA_RAM_OFFSET)>>2)   /*!< Input operand number of bits */
#define PKA_ARITHMETIC_ALL_OPS_IN_OP1             ((0x8B4U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op1 */
#define PKA_ARITHMETIC_ALL_OPS_IN_OP2             ((0xA44U - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 */
#define PKA_ARITHMETIC_ALL_OPS_IN_OP3             ((0xD5CU - PKA_RAM_OFFSET)>>2)   /*!< Input operand op2 */

/* Generic Arithmetic output data */
#define PKA_ARITHMETIC_ALL_OPS_OUT_RESULT         ((0xBD0U - PKA_RAM_OFFSET)>>2)   /*!< Output result */

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos               (0U)
#define FLASH_ACR_LATENCY_Msk               (0x7UL << FLASH_ACR_LATENCY_Pos)   /*!< 0x00000007 */
#define FLASH_ACR_LATENCY                   FLASH_ACR_LATENCY_Msk              /*!< Latency                                             */
#define FLASH_ACR_LATENCY_0                 (0x1UL << FLASH_ACR_LATENCY_Pos)   /*!< 0x00000001 */
#define FLASH_ACR_LATENCY_1                 (0x2UL << FLASH_ACR_LATENCY_Pos)   /*!< 0x00000002 */
#define FLASH_ACR_LATENCY_2                 (0x4UL << FLASH_ACR_LATENCY_Pos)   /*!< 0x00000004 */
#define FLASH_ACR_PRFTEN_Pos                (8U)
#define FLASH_ACR_PRFTEN_Msk                (0x1UL << FLASH_ACR_PRFTEN_Pos)    /*!< 0x00000100 */
#define FLASH_ACR_PRFTEN                    FLASH_ACR_PRFTEN_Msk               /*!< Prefetch enable                                     */
#define FLASH_ACR_ICEN_Pos                  (9U)
#define FLASH_ACR_ICEN_Msk                  (0x1UL << FLASH_ACR_ICEN_Pos)      /*!< 0x00000200 */
#define FLASH_ACR_ICEN                      FLASH_ACR_ICEN_Msk                 /*!< Instruction cache enable                            */
#define FLASH_ACR_DCEN_Pos                  (10U)
#define FLASH_ACR_DCEN_Msk                  (0x1UL << FLASH_ACR_DCEN_Pos)      /*!< 0x00000400 */
#define FLASH_ACR_DCEN                      FLASH_ACR_DCEN_Msk                 /*!< Data cache enable                                   */
#define FLASH_ACR_ICRST_Pos                 (11U)
#define FLASH_ACR_ICRST_Msk                 (0x1UL << FLASH_ACR_ICRST_Pos)     /*!< 0x00000800 */
#define FLASH_ACR_ICRST                     FLASH_ACR_ICRST_Msk                /*!< Instruction cache reset                             */
#define FLASH_ACR_DCRST_Pos                 (12U)
#define FLASH_ACR_DCRST_Msk                 (0x1UL << FLASH_ACR_DCRST_Pos)     /*!< 0x00001000 */
#define FLASH_ACR_DCRST                     FLASH_ACR_DCRST_Msk                /*!< Data cache reset                                    */
#define FLASH_ACR_PES_Pos                   (15U)
#define FLASH_ACR_PES_Msk                   (0x1UL << FLASH_ACR_PES_Pos)       /*!< 0x00008000 */
#define FLASH_ACR_PES                       FLASH_ACR_PES_Msk                  /*!< Program/erase suspend request                       */
#define FLASH_ACR_EMPTY_Pos                 (16U)
#define FLASH_ACR_EMPTY_Msk                 (0x1UL << FLASH_ACR_EMPTY_Pos)     /*!< 0x00010000 */
#define FLASH_ACR_EMPTY                     FLASH_ACR_EMPTY_Msk                /*!< Flash use area empty                                */

#define FLASH_ACR_LATENCY_0WS               (0x0UL << FLASH_ACR_LATENCY_Pos)            /*!< FLASH Zero wait state   */
#define FLASH_ACR_LATENCY_1WS               FLASH_ACR_LATENCY_0                         /*!< FLASH One wait state    */
#define FLASH_ACR_LATENCY_2WS               FLASH_ACR_LATENCY_1                         /*!< FLASH Two wait states   */
#define FLASH_ACR_LATENCY_3WS               (FLASH_ACR_LATENCY_1 | FLASH_ACR_LATENCY_0) /*!< FLASH Three wait states */

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP_Pos                    (0U)
#define FLASH_SR_EOP_Msk                    (0x1UL << FLASH_SR_EOP_Pos)        /*!< 0x00000001 */
#define FLASH_SR_EOP                        FLASH_SR_EOP_Msk                   /*!< End of Operation                                    */
#define FLASH_SR_OPERR_Pos                  (1U)
#define FLASH_SR_OPERR_Msk                  (0x1UL << FLASH_SR_OPERR_Pos)      /*!< 0x00000002 */
#define FLASH_SR_OPERR                      FLASH_SR_OPERR_Msk                 /*!< Operation error                                     */
#define FLASH_SR_PROGERR_Pos                (3U)
#define FLASH_SR_PROGERR_Msk                (0x1UL << FLASH_SR_PROGERR_Pos)    /*!< 0x00000008 */
#define FLASH_SR_PROGERR                    FLASH_SR_PROGERR_Msk               /*!< Programming error                                   */
#define FLASH_SR_WRPERR_Pos                 (4U)
#define FLASH_SR_WRPERR_Msk                 (0x1UL << FLASH_SR_WRPERR_Pos)     /*!< 0x00000010 */
#define FLASH_SR_WRPERR                     FLASH_SR_WRPERR_Msk                /*!< Write protection error                              */
#define FLASH_SR_PGAERR_Pos                 (5U)
#define FLASH_SR_PGAERR_Msk                 (0x1UL << FLASH_SR_PGAERR_Pos)     /*!< 0x00000020 */
#define FLASH_SR_PGAERR                     FLASH_SR_PGAERR_Msk                /*!< Programming alignment error                         */
#define FLASH_SR_SIZERR_Pos                 (6U)
#define FLASH_SR_SIZERR_Msk                 (0x1UL << FLASH_SR_SIZERR_Pos)     /*!< 0x00000040 */
#define FLASH_SR_SIZERR                     FLASH_SR_SIZERR_Msk                /*!< Size error                                          */
#define FLASH_SR_PGSERR_Pos                 (7U)
#define FLASH_SR_PGSERR_Msk                 (0x1UL << FLASH_SR_PGSERR_Pos)     /*!< 0x00000080 */
#define FLASH_SR_PGSERR                     FLASH_SR_PGSERR_Msk                /*!< Programming sequence error                          */
#define FLASH_SR_MISERR_Pos                 (8U)
#define FLASH_SR_MISERR_Msk                 (0x1UL << FLASH_SR_MISERR_Pos)     /*!< 0x00000100 */
#define FLASH_SR_MISERR                     FLASH_SR_MISERR_Msk                /*!< Fast programming data miss error                    */
#define FLASH_SR_FASTERR_Pos                (9U)
#define FLASH_SR_FASTERR_Msk                (0x1UL << FLASH_SR_FASTERR_Pos)    /*!< 0x00000200 */
#define FLASH_SR_FASTERR                    FLASH_SR_FASTERR_Msk               /*!< Fast programming error                              */
#define FLASH_SR_OPTNV_Pos                  (13U)
#define FLASH_SR_OPTNV_Msk                  (0x1UL << FLASH_SR_OPTNV_Pos)     /*!< 0x00002000 */
#define FLASH_SR_OPTNV                      FLASH_SR_OPTNV_Msk                /*!< User option OPTVAL indication                       */
#define FLASH_SR_RDERR_Pos                  (14U)
#define FLASH_SR_RDERR_Msk                  (0x1UL << FLASH_SR_RDERR_Pos)      /*!< 0x00004000 */
#define FLASH_SR_RDERR                      FLASH_SR_RDERR_Msk                 /*!< PCROP read error                                    */
#define FLASH_SR_OPTVERR_Pos                (15U)
#define FLASH_SR_OPTVERR_Msk                (0x1UL << FLASH_SR_OPTVERR_Pos)    /*!< 0x00008000 */
#define FLASH_SR_OPTVERR                    FLASH_SR_OPTVERR_Msk               /*!< Option validity error                               */
#define FLASH_SR_BSY_Pos                    (16U)
#define FLASH_SR_BSY_Msk                    (0x1UL << FLASH_SR_BSY_Pos)        /*!< 0x00010000 */
#define FLASH_SR_BSY                        FLASH_SR_BSY_Msk                   /*!< Flash Busy                                          */
#define FLASH_SR_CFGBSY_Pos                 (18U)
#define FLASH_SR_CFGBSY_Msk                 (0x1UL << FLASH_SR_CFGBSY_Pos)     /*!< 0x00040000 */
#define FLASH_SR_CFGBSY                     FLASH_SR_CFGBSY_Msk                /*!< Programming or erase configuration busy             */
#define FLASH_SR_PESD_Pos                   (19U)
#define FLASH_SR_PESD_Msk                   (0x1UL << FLASH_SR_PESD_Pos)       /*!< 0x00080000 */
#define FLASH_SR_PESD                       FLASH_SR_PESD_Msk                  /*!< Programming/erase operation suspended               */

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG_Pos                     (0U)
#define FLASH_CR_PG_Msk                     (0x1UL << FLASH_CR_PG_Pos)         /*!< 0x00000001 */
#define FLASH_CR_PG                         FLASH_CR_PG_Msk                    /*!< Flash programming                                   */
#define FLASH_CR_PER_Pos                    (1U)
#define FLASH_CR_PER_Msk                    (0x1UL << FLASH_CR_PER_Pos)        /*!< 0x00000002 */
#define FLASH_CR_PER                        FLASH_CR_PER_Msk                   /*!< Page erase                                          */
#define FLASH_CR_MER_Pos                    (2U)
#define FLASH_CR_MER_Msk                    (0x1UL << FLASH_CR_MER_Pos)        /*!< 0x00000004 */
#define FLASH_CR_MER                        FLASH_CR_MER_Msk                   /*!< Mass erase                                          */
#define FLASH_CR_PNB_Pos                    (3U)
#define FLASH_CR_PNB_Msk                    (0xFFUL << FLASH_CR_PNB_Pos)       /*!< 0x000007F8 */
#define FLASH_CR_PNB                        FLASH_CR_PNB_Msk                   /*!< Page number selection mask                          */
#define FLASH_CR_STRT_Pos                   (16U)
#define FLASH_CR_STRT_Msk                   (0x1UL << FLASH_CR_STRT_Pos)       /*!< 0x00010000 */
#define FLASH_CR_STRT                       FLASH_CR_STRT_Msk                  /*!< Start an erase operation                            */
#define FLASH_CR_OPTSTRT_Pos                (17U)
#define FLASH_CR_OPTSTRT_Msk                (0x1UL << FLASH_CR_OPTSTRT_Pos)    /*!< 0x00020000 */
#define FLASH_CR_OPTSTRT                    FLASH_CR_OPTSTRT_Msk               /*!< Options modification start                          */
#define FLASH_CR_FSTPG_Pos                  (18U)
#define FLASH_CR_FSTPG_Msk                  (0x1UL << FLASH_CR_FSTPG_Pos)      /*!< 0x00040000 */
#define FLASH_CR_FSTPG                      FLASH_CR_FSTPG_Msk                 /*!< Fast programming                                    */
#define FLASH_CR_EOPIE_Pos                  (24U)
#define FLASH_CR_EOPIE_Msk                  (0x1UL << FLASH_CR_EOPIE_Pos)      /*!< 0x01000000 */
#define FLASH_CR_EOPIE                      FLASH_CR_EOPIE_Msk                 /*!< End of operation interrupt enable                   */
#define FLASH_CR_ERRIE_Pos                  (25U)
#define FLASH_CR_ERRIE_Msk                  (0x1UL << FLASH_CR_ERRIE_Pos)      /*!< 0x02000000 */
#define FLASH_CR_ERRIE                      FLASH_CR_ERRIE_Msk                 /*!< Error interrupt enable                              */
#define FLASH_CR_RDERRIE_Pos                (26U)
#define FLASH_CR_RDERRIE_Msk                (0x1UL << FLASH_CR_RDERRIE_Pos)    /*!< 0x04000000 */
#define FLASH_CR_RDERRIE                    FLASH_CR_RDERRIE_Msk               /*!< PCROP read error interrupt enable                   */
#define FLASH_CR_OBL_LAUNCH_Pos             (27U)
#define FLASH_CR_OBL_LAUNCH_Msk             (0x1UL << FLASH_CR_OBL_LAUNCH_Pos) /*!< 0x08000000 */
#define FLASH_CR_OBL_LAUNCH                 FLASH_CR_OBL_LAUNCH_Msk            /*!< Force the option byte loading                       */
#define FLASH_CR_OPTLOCK_Pos                (30U)
#define FLASH_CR_OPTLOCK_Msk                (0x1UL << FLASH_CR_OPTLOCK_Pos)    /*!< 0x40000000 */
#define FLASH_CR_OPTLOCK                    FLASH_CR_OPTLOCK_Msk               /*!< Options lock                                        */
#define FLASH_CR_LOCK_Pos                   (31U)
#define FLASH_CR_LOCK_Msk                   (0x1UL << FLASH_CR_LOCK_Pos)       /*!< 0x80000000 */
#define FLASH_CR_LOCK                       FLASH_CR_LOCK_Msk                  /*!< Flash control register lock                         */

/*******************  Bits definition for FLASH_ECCR register  ****************/
#define FLASH_ECCR_ADDR_ECC_Pos             (0U)
#define FLASH_ECCR_ADDR_ECC_Msk             (0x1FFFFUL << FLASH_ECCR_ADDR_ECC_Pos) /*!< 0x0001FFFF */
#define FLASH_ECCR_ADDR_ECC                 FLASH_ECCR_ADDR_ECC_Msk            /*!< double-word address ECC fail                        */
#define FLASH_ECCR_SYSF_ECC_Pos             (20U)
#define FLASH_ECCR_SYSF_ECC_Msk             (0x1UL << FLASH_ECCR_SYSF_ECC_Pos) /*!< 0x00100000 */
#define FLASH_ECCR_SYSF_ECC                 FLASH_ECCR_SYSF_ECC_Msk            /*!< System flash ECC fail                               */
#define FLASH_ECCR_ECCCIE_Pos               (24U)
#define FLASH_ECCR_ECCCIE_Msk               (0x1UL << FLASH_ECCR_ECCCIE_Pos)   /*!< 0x01000000 */
#define FLASH_ECCR_ECCCIE                   FLASH_ECCR_ECCCIE_Msk              /*!< ECC correction interrupt enable                     */
#define FLASH_ECCR_CPUID_Pos                (26U)
#define FLASH_ECCR_CPUID_Msk                (0x7UL << FLASH_ECCR_CPUID_Pos)    /*!< 0x1C000000 */
#define FLASH_ECCR_CPUID                    FLASH_ECCR_CPUID_Msk               /*!< CPU identification                                  */
#define FLASH_ECCR_CPUID_0                  (0x1U << FLASH_ECCR_CPUID_Pos)     /*!< 0x04000000 */
#define FLASH_ECCR_CPUID_1                  (0x2U << FLASH_ECCR_CPUID_Pos)     /*!< 0x08000000 */
#define FLASH_ECCR_CPUID_2                  (0x4U << FLASH_ECCR_CPUID_Pos)     /*!< 0x10000000 */
#define FLASH_ECCR_ECCC_Pos                 (30U)
#define FLASH_ECCR_ECCC_Msk                 (0x1UL << FLASH_ECCR_ECCC_Pos)     /*!< 0x40000000 */
#define FLASH_ECCR_ECCC                     FLASH_ECCR_ECCC_Msk                /*!< ECC correction                                      */
#define FLASH_ECCR_ECCD_Pos                 (31U)
#define FLASH_ECCR_ECCD_Msk                 (0x1UL << FLASH_ECCR_ECCD_Pos)     /*!< 0x80000000 */
#define FLASH_ECCR_ECCD                     FLASH_ECCR_ECCD_Msk                /*!< ECC detection                                       */

/*******************  Bits definition for FLASH_OPTR register  ****************/
#define FLASH_OPTR_RDP_Pos                  (0U)
#define FLASH_OPTR_RDP_Msk                  (0xFFUL << FLASH_OPTR_RDP_Pos)     /*!< 0x000000FF */
#define FLASH_OPTR_RDP                      FLASH_OPTR_RDP_Msk                 /*!< Read protection level                               */
#define FLASH_OPTR_ESE_Pos                  (8U)
#define FLASH_OPTR_ESE_Msk                  (0x1UL << FLASH_OPTR_ESE_Pos)      /*!< 0x00000100 */
#define FLASH_OPTR_ESE                      FLASH_OPTR_ESE_Msk                 /*!< Security enable                                     */
#define FLASH_OPTR_BOR_LEV_Pos              (9U)
#define FLASH_OPTR_BOR_LEV_Msk              (0x7UL << FLASH_OPTR_BOR_LEV_Pos)  /*!< 0x00000E00 */
#define FLASH_OPTR_BOR_LEV                  FLASH_OPTR_BOR_LEV_Msk             /*!< BOR reset level mask                                */
#define FLASH_OPTR_BOR_LEV_0                (0x1U << FLASH_OPTR_BOR_LEV_Pos)   /*!< 0x00000200 */
#define FLASH_OPTR_BOR_LEV_1                (0x2U << FLASH_OPTR_BOR_LEV_Pos)   /*!< 0x00000400 */
#define FLASH_OPTR_BOR_LEV_2                (0x4U << FLASH_OPTR_BOR_LEV_Pos)   /*!< 0x00000800 */
#define FLASH_OPTR_nRST_STOP_Pos            (12U)
#define FLASH_OPTR_nRST_STOP_Msk            (0x1UL << FLASH_OPTR_nRST_STOP_Pos) /*!< 0x00001000 */
#define FLASH_OPTR_nRST_STOP                FLASH_OPTR_nRST_STOP_Msk           /*!< Reset option in Stop mode                           */
#define FLASH_OPTR_nRST_STDBY_Pos           (13U)
#define FLASH_OPTR_nRST_STDBY_Msk           (0x1UL << FLASH_OPTR_nRST_STDBY_Pos) /*!< 0x00002000 */
#define FLASH_OPTR_nRST_STDBY               FLASH_OPTR_nRST_STDBY_Msk          /*!< Reset option in Standby mode                        */
#define FLASH_OPTR_nRST_SHDW_Pos            (14U)
#define FLASH_OPTR_nRST_SHDW_Msk            (0x1UL << FLASH_OPTR_nRST_SHDW_Pos) /*!< 0x00004000 */
#define FLASH_OPTR_nRST_SHDW                FLASH_OPTR_nRST_SHDW_Msk           /*!< Reset option in Shutdown mode                       */
#define FLASH_OPTR_IRHEN_Pos                (15U)
#define FLASH_OPTR_IRHEN_Msk                (0x1UL << FLASH_OPTR_IRHEN_Pos)    /*!< 0x00008000 */
#define FLASH_OPTR_IRHEN                    FLASH_OPTR_IRHEN_Msk               /*!< Internal reset holder enable bit                    */
#define FLASH_OPTR_IWDG_SW_Pos              (16U)
#define FLASH_OPTR_IWDG_SW_Msk              (0x1UL << FLASH_OPTR_IWDG_SW_Pos)  /*!< 0x00010000 */
#define FLASH_OPTR_IWDG_SW                  FLASH_OPTR_IWDG_SW_Msk             /*!< Independent watchdog selection                      */
#define FLASH_OPTR_IWDG_STOP_Pos            (17U)
#define FLASH_OPTR_IWDG_STOP_Msk            (0x1UL << FLASH_OPTR_IWDG_STOP_Pos) /*!< 0x00020000 */
#define FLASH_OPTR_IWDG_STOP                FLASH_OPTR_IWDG_STOP_Msk           /*!< Independent watchdog counter option in Stop mode    */
#define FLASH_OPTR_IWDG_STDBY_Pos           (18U)
#define FLASH_OPTR_IWDG_STDBY_Msk           (0x1UL << FLASH_OPTR_IWDG_STDBY_Pos) /*!< 0x00040000 */
#define FLASH_OPTR_IWDG_STDBY               FLASH_OPTR_IWDG_STDBY_Msk          /*!< Independent watchdog counter option in Standby mode */
#define FLASH_OPTR_WWDG_SW_Pos              (19U)
#define FLASH_OPTR_WWDG_SW_Msk              (0x1UL << FLASH_OPTR_WWDG_SW_Pos)  /*!< 0x00080000 */
#define FLASH_OPTR_WWDG_SW                  FLASH_OPTR_WWDG_SW_Msk             /*!< Window watchdog selection                           */
#define FLASH_OPTR_nRST_MODE_1_Pos          (22U)
#define FLASH_OPTR_nRST_MODE_1_Msk          (0x1UL << FLASH_OPTR_nRST_MODE_1_Pos)  /*!< 0x04000000 */
#define FLASH_OPTR_nRST_MODE_1              FLASH_OPTR_nRST_MODE_1_Msk         /*!< PB11 GPIO normal mode                               */
#define FLASH_OPTR_nBOOT1_Pos               (23U)
#define FLASH_OPTR_nBOOT1_Msk               (0x1UL << FLASH_OPTR_nBOOT1_Pos)   /*!< 0x00800000 */
#define FLASH_OPTR_nBOOT1                   FLASH_OPTR_nBOOT1_Msk              /*!< Boot Configuration                                  */
#define FLASH_OPTR_SRAM2PE_Pos              (24U)
#define FLASH_OPTR_SRAM2PE_Msk              (0x1UL << FLASH_OPTR_SRAM2PE_Pos)  /*!< 0x01000000 */
#define FLASH_OPTR_SRAM2PE                  FLASH_OPTR_SRAM2PE_Msk             /*!< SRAM2 parity check enable                           */
#define FLASH_OPTR_SRAM2RST_Pos             (25U)
#define FLASH_OPTR_SRAM2RST_Msk             (0x1UL << FLASH_OPTR_SRAM2RST_Pos) /*!< 0x02000000 */
#define FLASH_OPTR_SRAM2RST                 FLASH_OPTR_SRAM2RST_Msk            /*!< SRAM2 erase option when system reset                */
#define FLASH_OPTR_nSWBOOT0_Pos             (26U)
#define FLASH_OPTR_nSWBOOT0_Msk             (0x1UL << FLASH_OPTR_nSWBOOT0_Pos) /*!< 0x04000000 */
#define FLASH_OPTR_nSWBOOT0                 FLASH_OPTR_nSWBOOT0_Msk            /*!< Software BOOT0                                      */
#define FLASH_OPTR_nBOOT0_Pos               (27U)
#define FLASH_OPTR_nBOOT0_Msk               (0x1UL << FLASH_OPTR_nBOOT0_Pos)   /*!< 0x08000000 */
#define FLASH_OPTR_nBOOT0                   FLASH_OPTR_nBOOT0_Msk              /*!< BOOT0 option bit                                    */
#define FLASH_OPTR_nRST_MODE_0_Pos          (28U)
#define FLASH_OPTR_nRST_MODE_0_Msk          (0x1UL << FLASH_OPTR_nRST_MODE_0_Pos)  /*!< 0x10000000 */
#define FLASH_OPTR_nRST_MODE_0              FLASH_OPTR_nRST_MODE_0_Msk         /*!< PB11 reset input mode                               */
#define FLASH_OPTR_nRST_MODE_Pos            (22U)
#define FLASH_OPTR_nRST_MODE_Msk            (0x41UL << FLASH_OPTR_nRST_MODE_Pos)  /*!< 0x10400000 */
#define FLASH_OPTR_nRST_MODE                FLASH_OPTR_nRST_MODE_Msk
#define FLASH_OPTR_AGC_TRIM_Pos             (29U)
#define FLASH_OPTR_AGC_TRIM_Msk             (0x7UL << FLASH_OPTR_AGC_TRIM_Pos)  /*!< 0xE0000000 */
#define FLASH_OPTR_AGC_TRIM                 FLASH_OPTR_AGC_TRIM_Msk             /*!< Automatic Gain Control trimming mask               */
#define FLASH_OPTR_AGC_TRIM_0               (0x1U << FLASH_OPTR_AGC_TRIM_Pos)   /*!< 0x20000000 */
#define FLASH_OPTR_AGC_TRIM_1               (0x2U << FLASH_OPTR_AGC_TRIM_Pos)   /*!< 0x40000000 */
#define FLASH_OPTR_AGC_TRIM_2               (0x4U << FLASH_OPTR_AGC_TRIM_Pos)   /*!< 0x80000000 */

/******************  Bits definition for FLASH_PCROP1ASR register  ************/
#define FLASH_PCROP1ASR_PCROP1A_STRT_Pos    (0U)
#define FLASH_PCROP1ASR_PCROP1A_STRT_Msk    (0x1FFUL << FLASH_PCROP1ASR_PCROP1A_STRT_Pos) /*!< 0x000001FF */
#define FLASH_PCROP1ASR_PCROP1A_STRT        FLASH_PCROP1ASR_PCROP1A_STRT_Msk   /*!< PCROP area A start offset                           */

/******************  Bits definition for FLASH_PCROP1AER register  ************/
#define FLASH_PCROP1AER_PCROP1A_END_Pos     (0U)
#define FLASH_PCROP1AER_PCROP1A_END_Msk     (0x1FFUL << FLASH_PCROP1AER_PCROP1A_END_Pos) /*!< 0x000001FF */
#define FLASH_PCROP1AER_PCROP1A_END         FLASH_PCROP1AER_PCROP1A_END_Msk    /*!< PCROP area A end offset                             */
#define FLASH_PCROP1AER_PCROP_RDP_Pos       (31U)
#define FLASH_PCROP1AER_PCROP_RDP_Msk       (0x1UL << FLASH_PCROP1AER_PCROP_RDP_Pos) /*!< 0x80000000 */
#define FLASH_PCROP1AER_PCROP_RDP           FLASH_PCROP1AER_PCROP_RDP_Msk      /*!< PCROP area   preserved when RDP level decreased     */

/******************  Bits definition for FLASH_WRP1AR register  ***************/
#define FLASH_WRP1AR_WRP1A_STRT_Pos         (0U)
#define FLASH_WRP1AR_WRP1A_STRT_Msk         (0xFFUL << FLASH_WRP1AR_WRP1A_STRT_Pos) /*!< 0x000000FF */
#define FLASH_WRP1AR_WRP1A_STRT             FLASH_WRP1AR_WRP1A_STRT_Msk        /*!< WRP area A start offset                             */
#define FLASH_WRP1AR_WRP1A_END_Pos          (16U)
#define FLASH_WRP1AR_WRP1A_END_Msk          (0xFFUL << FLASH_WRP1AR_WRP1A_END_Pos) /*!< 0x00FF0000 */
#define FLASH_WRP1AR_WRP1A_END              FLASH_WRP1AR_WRP1A_END_Msk         /*!< WRP area A end offset                               */

/******************  Bits definition for FLASH_WRP1BR register  ***************/
#define FLASH_WRP1BR_WRP1B_STRT_Pos         (0U)
#define FLASH_WRP1BR_WRP1B_STRT_Msk         (0xFFUL << FLASH_WRP1BR_WRP1B_STRT_Pos) /*!< 0x000000FF */
#define FLASH_WRP1BR_WRP1B_STRT             FLASH_WRP1BR_WRP1B_STRT_Msk        /*!< WRP area B start offset                             */
#define FLASH_WRP1BR_WRP1B_END_Pos          (16U)
#define FLASH_WRP1BR_WRP1B_END_Msk          (0xFFUL << FLASH_WRP1BR_WRP1B_END_Pos) /*!< 0x00FF0000 */
#define FLASH_WRP1BR_WRP1B_END              FLASH_WRP1BR_WRP1B_END_Msk         /*!< WRP area B end offset                               */

/******************  Bits definition for FLASH_PCROP1BSR register  ************/
#define FLASH_PCROP1BSR_PCROP1B_STRT_Pos    (0U)
#define FLASH_PCROP1BSR_PCROP1B_STRT_Msk    (0x1FFUL << FLASH_PCROP1BSR_PCROP1B_STRT_Pos) /*!< 0x000001FF */
#define FLASH_PCROP1BSR_PCROP1B_STRT        FLASH_PCROP1BSR_PCROP1B_STRT_Msk   /*!< PCROP area B start offset                           */

/******************  Bits definition for FLASH_PCROP1BER register  ************/
#define FLASH_PCROP1BER_PCROP1B_END_Pos     (0U)
#define FLASH_PCROP1BER_PCROP1B_END_Msk     (0x1FFUL << FLASH_PCROP1BER_PCROP1B_END_Pos) /*!< 0x000001FF */
#define FLASH_PCROP1BER_PCROP1B_END         FLASH_PCROP1BER_PCROP1B_END_Msk    /*!< PCROP area B end offset                             */

/******************  Bits definition for FLASH_IPCCBR register  ************/
#define FLASH_IPCCBR_IPCCDBA_Pos            (0U)
#define FLASH_IPCCBR_IPCCDBA_Msk            (0x3FFFUL << FLASH_IPCCBR_IPCCDBA_Pos) /*!< 0x00003FFF */
#define FLASH_IPCCBR_IPCCDBA                FLASH_IPCCBR_IPCCDBA_Msk           /*!< IPCC data buffer base address                       */

/******************  Bits definition for FLASH_SFR register  ************/
#define FLASH_SFR_SFSA_Pos                  (0U)
#define FLASH_SFR_SFSA_Msk                  (0xFFUL << FLASH_SFR_SFSA_Pos)     /*!< 0x000000FF */
#define FLASH_SFR_SFSA                      FLASH_SFR_SFSA_Msk                 /* Secure flash start address                             */
#define FLASH_SFR_FSD_Pos                   (8U)
#define FLASH_SFR_FSD_Msk                   (0x1UL << FLASH_SFR_FSD_Pos)       /*!< 0x00000100 */
#define FLASH_SFR_FSD                       FLASH_SFR_FSD_Msk                  /* Flash mode secure                                      */
#define FLASH_SFR_DDS_Pos                   (12U)
#define FLASH_SFR_DDS_Msk                   (0x1UL << FLASH_SFR_DDS_Pos)       /*!< 0x00001000 */
#define FLASH_SFR_DDS                       FLASH_SFR_DDS_Msk                  /* Enabling and disabling CPU2 Debug access               */

/******************  Bits definition for FLASH_SRRVR register  ************/
#define FLASH_SRRVR_SBRV_Pos                (0U)
#define FLASH_SRRVR_SBRV_Msk                (0x1FFFFUL << FLASH_SRRVR_SBRV_Pos) /*!< 0x0001FFFF */
#define FLASH_SRRVR_SBRV                    FLASH_SRRVR_SBRV_Msk                /* CPU2 boot reset vector memory offset                  */

#define FLASH_SRRVR_SBRSA_A_Pos             (18U)
#define FLASH_SRRVR_SBRSA_A_Msk             (0x1FUL << FLASH_SRRVR_SBRSA_A_Pos) /*!< 0x007C0000 */
#define FLASH_SRRVR_SBRSA_A                 FLASH_SRRVR_SBRSA_A_Msk             /* Secure backup SRAM2a start address                    */
#define FLASH_SRRVR_BRSD_A_Pos              (23U)
#define FLASH_SRRVR_BRSD_A_Msk              (0x1UL << FLASH_SRRVR_BRSD_A_Pos)   /*!< 0x00800000 */
#define FLASH_SRRVR_BRSD_A                  FLASH_SRRVR_BRSD_A_Msk              /* Backup SRAM2A secure mode                             */

#define FLASH_SRRVR_SBRSA_B_Pos             (25U)
#define FLASH_SRRVR_SBRSA_B_Msk             (0x3UL << FLASH_SRRVR_SBRSA_B_Pos)  /*!< 0x06000000 */
#define FLASH_SRRVR_SBRSA_B                 FLASH_SRRVR_SBRSA_B_Msk             /* Secure backup SRAM2b start address                    */
#define FLASH_SRRVR_BRSD_B_Pos              (30U)
#define FLASH_SRRVR_BRSD_B_Msk              (0x1UL << FLASH_SRRVR_BRSD_B_Pos)   /*!< 0x40000000 */
#define FLASH_SRRVR_BRSD_B                  FLASH_SRRVR_BRSD_B_Msk              /* Backup SRAM2B secure mode                             */
#define FLASH_SRRVR_C2OPT_Pos               (31U)
#define FLASH_SRRVR_C2OPT_Msk               (0x1UL << FLASH_SRRVR_C2OPT_Pos)    /*!< 0x80000000 */
#define FLASH_SRRVR_C2OPT                   FLASH_SRRVR_C2OPT_Msk               /* CPU2 boot reset vector memory selection                */

/******************  Bits definition for FLASH_C2ACR register  ************/
#define FLASH_C2ACR_PRFTEN_Pos              (8U)
#define FLASH_C2ACR_PRFTEN_Msk              (0x1UL << FLASH_C2ACR_PRFTEN_Pos) /*!< 0x00000100 */
#define FLASH_C2ACR_PRFTEN                  FLASH_C2ACR_PRFTEN_Msk            /*!< CPU2 Prefetch enable                                */
#define FLASH_C2ACR_ICEN_Pos                (9U)
#define FLASH_C2ACR_ICEN_Msk                (0x1UL << FLASH_C2ACR_ICEN_Pos)   /*!< 0x00000200 */
#define FLASH_C2ACR_ICEN                    FLASH_C2ACR_ICEN_Msk              /*!< CPU2 Instruction cache enable                       */
#define FLASH_C2ACR_ICRST_Pos               (11U)
#define FLASH_C2ACR_ICRST_Msk               (0x1UL << FLASH_C2ACR_ICRST_Pos)  /*!< 0x00000800 */
#define FLASH_C2ACR_ICRST                   FLASH_C2ACR_ICRST_Msk             /*!< CPU2 Instruction cache reset                        */
#define FLASH_C2ACR_PES_Pos                 (15U)
#define FLASH_C2ACR_PES_Msk                 (0x1UL << FLASH_C2ACR_PES_Pos)    /*!< 0x00008000 */
#define FLASH_C2ACR_PES                     FLASH_C2ACR_PES_Msk               /*!< CPU2 Program/erase suspend request                  */

/******************  Bits definition for FLASH_C2SR register  ************/
#define FLASH_C2SR_EOP_Pos                  (0U)
#define FLASH_C2SR_EOP_Msk                  (0x1UL << FLASH_C2SR_EOP_Pos)     /*!< 0x00000001 */
#define FLASH_C2SR_EOP                      FLASH_C2SR_EOP_Msk                /*!< CPU2 End of operation                            */
#define FLASH_C2SR_OPERR_Pos                (1U)
#define FLASH_C2SR_OPERR_Msk                (0x1UL << FLASH_C2SR_OPERR_Pos)   /*!< 0x00000002 */
#define FLASH_C2SR_OPERR                    FLASH_C2SR_OPERR_Msk              /*!< CPU2 Operation error                             */
#define FLASH_C2SR_PROGERR_Pos              (3U)
#define FLASH_C2SR_PROGERR_Msk              (0x1UL << FLASH_C2SR_PROGERR_Pos) /*!< 0x00000008 */
#define FLASH_C2SR_PROGERR                  FLASH_C2SR_PROGERR_Msk            /*!< CPU2 Programming error                           */
#define FLASH_C2SR_WRPERR_Pos               (4U)
#define FLASH_C2SR_WRPERR_Msk               (0x1UL << FLASH_C2SR_WRPERR_Pos)  /*!< 0x00000010 */
#define FLASH_C2SR_WRPERR                   FLASH_C2SR_WRPERR_Msk             /*!< CPU2 Write protection error                      */
#define FLASH_C2SR_PGAERR_Pos               (5U)
#define FLASH_C2SR_PGAERR_Msk               (0x1UL << FLASH_C2SR_PGAERR_Pos)  /*!< 0x00000020 */
#define FLASH_C2SR_PGAERR                   FLASH_C2SR_PGAERR_Msk             /*!< CPU2 Programming alignment error                 */
#define FLASH_C2SR_SIZERR_Pos               (6U)
#define FLASH_C2SR_SIZERR_Msk               (0x1UL << FLASH_C2SR_SIZERR_Pos)  /*!< 0x00000040 */
#define FLASH_C2SR_SIZERR                   FLASH_C2SR_SIZERR_Msk             /*!< CPU2 Size error                                  */
#define FLASH_C2SR_PGSERR_Pos               (7U)
#define FLASH_C2SR_PGSERR_Msk               (0x1UL << FLASH_C2SR_PGSERR_Pos)  /*!< 0x00000080 */
#define FLASH_C2SR_PGSERR                   FLASH_C2SR_PGSERR_Msk             /*!< CPU2 Programming sequence error                  */
#define FLASH_C2SR_MISERR_Pos               (8U)
#define FLASH_C2SR_MISERR_Msk               (0x1UL << FLASH_C2SR_MISERR_Pos)  /*!< 0x00000100 */
#define FLASH_C2SR_MISERR                   FLASH_C2SR_MISERR_Msk             /*!< CPU2 Fast programming data miss error            */
#define FLASH_C2SR_FASTERR_Pos              (9U)
#define FLASH_C2SR_FASTERR_Msk              (0x1UL << FLASH_C2SR_FASTERR_Pos) /*!< 0x00000200 */
#define FLASH_C2SR_FASTERR                  FLASH_C2SR_FASTERR_Msk            /*!< CPU2 Fast programming error                      */
#define FLASH_C2SR_RDERR_Pos                (14U)
#define FLASH_C2SR_RDERR_Msk                (0x1UL << FLASH_C2SR_RDERR_Pos)   /*!< 0x00004000 */
#define FLASH_C2SR_RDERR                    FLASH_C2SR_RDERR_Msk              /*!< CPU2 PCROP read error                            */
#define FLASH_C2SR_BSY_Pos                  (16U)
#define FLASH_C2SR_BSY_Msk                  (0x1UL << FLASH_C2SR_BSY_Pos)     /*!< 0x00010000 */
#define FLASH_C2SR_BSY                      FLASH_C2SR_BSY_Msk                /*!< CPU2 Flash busy                                  */
#define FLASH_C2SR_CFGBSY_Pos               (18U)
#define FLASH_C2SR_CFGBSY_Msk               (0x1UL << FLASH_C2SR_CFGBSY_Pos)  /*!< 0x00040000 */
#define FLASH_C2SR_CFGBSY                   FLASH_C2SR_CFGBSY_Msk             /*!< CPU2 Programming or erase configuration busy     */
#define FLASH_C2SR_PESD_Pos                 (19U)
#define FLASH_C2SR_PESD_Msk                 (0x1UL << FLASH_C2SR_PESD_Pos)   /*!< 0x00080000 */
#define FLASH_C2SR_PESD                     FLASH_C2SR_PESD_Msk              /*!< CPU2 Programming/erase operation suspended       */

/******************  Bits definition for FLASH_C2CR register  ************/
#define FLASH_C2CR_PG_Pos                   (0U)
#define FLASH_C2CR_PG_Msk                   (0x1UL << FLASH_C2CR_PG_Pos)      /*!< 0x00000001 */
#define FLASH_C2CR_PG                       FLASH_C2CR_PG_Msk                 /*!< CPU2 Flash programming                                   */
#define FLASH_C2CR_PER_Pos                  (1U)
#define FLASH_C2CR_PER_Msk                  (0x1UL << FLASH_C2CR_PER_Pos)     /*!< 0x00000002 */
#define FLASH_C2CR_PER                      FLASH_C2CR_PER_Msk                /*!< CPU2 Page erase                                          */
#define FLASH_C2CR_MER_Pos                  (2U)
#define FLASH_C2CR_MER_Msk                  (0x1UL << FLASH_C2CR_MER_Pos)     /*!< 0x00000004 */
#define FLASH_C2CR_MER                      FLASH_C2CR_MER_Msk                /*!< CPU2 Mass erase                                          */
#define FLASH_C2CR_PNB_Pos                  (3U)
#define FLASH_C2CR_PNB_Msk                  (0xFFUL << FLASH_C2CR_PNB_Pos)    /*!< 0x000007F8 */
#define FLASH_C2CR_PNB                      FLASH_C2CR_PNB_Msk                /*!< CPU2 Page number selection mask                          */
#define FLASH_C2CR_STRT_Pos                 (16U)
#define FLASH_C2CR_STRT_Msk                 (0x1UL << FLASH_C2CR_STRT_Pos)    /*!< 0x00010000 */
#define FLASH_C2CR_STRT                     FLASH_C2CR_STRT_Msk               /*!< CPU2 Start an erase operation                            */
#define FLASH_C2CR_FSTPG_Pos                (18U)
#define FLASH_C2CR_FSTPG_Msk                (0x1UL << FLASH_C2CR_FSTPG_Pos)   /*!< 0x00040000 */
#define FLASH_C2CR_FSTPG                    FLASH_C2CR_FSTPG_Msk              /*!< CPU2 Fast programming                                    */
#define FLASH_C2CR_EOPIE_Pos                (24U)
#define FLASH_C2CR_EOPIE_Msk                (0x1UL << FLASH_C2CR_EOPIE_Pos)   /*!< 0x01000000 */
#define FLASH_C2CR_EOPIE                    FLASH_C2CR_EOPIE_Msk              /*!< CPU2 End of operation interrupt enable                   */
#define FLASH_C2CR_ERRIE_Pos                (25U)
#define FLASH_C2CR_ERRIE_Msk                (0x1UL << FLASH_C2CR_ERRIE_Pos)   /*!< 0x02000000 */
#define FLASH_C2CR_ERRIE                    FLASH_C2CR_ERRIE_Msk              /*!< CPU2 Error interrupt enable                              */
#define FLASH_C2CR_RDERRIE_Pos              (26U)
#define FLASH_C2CR_RDERRIE_Msk              (0x1UL << FLASH_C2CR_RDERRIE_Pos) /*!< 0x04000000 */
#define FLASH_C2CR_RDERRIE                  FLASH_C2CR_RDERRIE_Msk            /*!< CPU2 PCROP read error interrupt enable                   */

/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O                             */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODE0_Pos           (0U)
#define GPIO_MODER_MODE0_Msk           (0x3UL << GPIO_MODER_MODE0_Pos)         /*!< 0x00000003 */
#define GPIO_MODER_MODE0               GPIO_MODER_MODE0_Msk
#define GPIO_MODER_MODE0_0             (0x1U << GPIO_MODER_MODE0_Pos)          /*!< 0x00000001 */
#define GPIO_MODER_MODE0_1             (0x2U << GPIO_MODER_MODE0_Pos)          /*!< 0x00000002 */
#define GPIO_MODER_MODE1_Pos           (2U)
#define GPIO_MODER_MODE1_Msk           (0x3UL << GPIO_MODER_MODE1_Pos)         /*!< 0x0000000C */
#define GPIO_MODER_MODE1               GPIO_MODER_MODE1_Msk
#define GPIO_MODER_MODE1_0             (0x1U << GPIO_MODER_MODE1_Pos)          /*!< 0x00000004 */
#define GPIO_MODER_MODE1_1             (0x2U << GPIO_MODER_MODE1_Pos)          /*!< 0x00000008 */
#define GPIO_MODER_MODE2_Pos           (4U)
#define GPIO_MODER_MODE2_Msk           (0x3UL << GPIO_MODER_MODE2_Pos)         /*!< 0x00000030 */
#define GPIO_MODER_MODE2               GPIO_MODER_MODE2_Msk
#define GPIO_MODER_MODE2_0             (0x1U << GPIO_MODER_MODE2_Pos)          /*!< 0x00000010 */
#define GPIO_MODER_MODE2_1             (0x2U << GPIO_MODER_MODE2_Pos)          /*!< 0x00000020 */
#define GPIO_MODER_MODE3_Pos           (6U)
#define GPIO_MODER_MODE3_Msk           (0x3UL << GPIO_MODER_MODE3_Pos)         /*!< 0x000000C0 */
#define GPIO_MODER_MODE3               GPIO_MODER_MODE3_Msk
#define GPIO_MODER_MODE3_0             (0x1U << GPIO_MODER_MODE3_Pos)          /*!< 0x00000040 */
#define GPIO_MODER_MODE3_1             (0x2U << GPIO_MODER_MODE3_Pos)          /*!< 0x00000080 */
#define GPIO_MODER_MODE4_Pos           (8U)
#define GPIO_MODER_MODE4_Msk           (0x3UL << GPIO_MODER_MODE4_Pos)         /*!< 0x00000300 */
#define GPIO_MODER_MODE4               GPIO_MODER_MODE4_Msk
#define GPIO_MODER_MODE4_0             (0x1U << GPIO_MODER_MODE4_Pos)          /*!< 0x00000100 */
#define GPIO_MODER_MODE4_1             (0x2U << GPIO_MODER_MODE4_Pos)          /*!< 0x00000200 */
#define GPIO_MODER_MODE5_Pos           (10U)
#define GPIO_MODER_MODE5_Msk           (0x3UL << GPIO_MODER_MODE5_Pos)         /*!< 0x00000C00 */
#define GPIO_MODER_MODE5               GPIO_MODER_MODE5_Msk
#define GPIO_MODER_MODE5_0             (0x1U << GPIO_MODER_MODE5_Pos)          /*!< 0x00000400 */
#define GPIO_MODER_MODE5_1             (0x2U << GPIO_MODER_MODE5_Pos)          /*!< 0x00000800 */
#define GPIO_MODER_MODE6_Pos           (12U)
#define GPIO_MODER_MODE6_Msk           (0x3UL << GPIO_MODER_MODE6_Pos)         /*!< 0x00003000 */
#define GPIO_MODER_MODE6               GPIO_MODER_MODE6_Msk
#define GPIO_MODER_MODE6_0             (0x1U << GPIO_MODER_MODE6_Pos)          /*!< 0x00001000 */
#define GPIO_MODER_MODE6_1             (0x2U << GPIO_MODER_MODE6_Pos)          /*!< 0x00002000 */
#define GPIO_MODER_MODE7_Pos           (14U)
#define GPIO_MODER_MODE7_Msk           (0x3UL << GPIO_MODER_MODE7_Pos)         /*!< 0x0000C000 */
#define GPIO_MODER_MODE7               GPIO_MODER_MODE7_Msk
#define GPIO_MODER_MODE7_0             (0x1U << GPIO_MODER_MODE7_Pos)          /*!< 0x00004000 */
#define GPIO_MODER_MODE7_1             (0x2U << GPIO_MODER_MODE7_Pos)          /*!< 0x00008000 */
#define GPIO_MODER_MODE8_Pos           (16U)
#define GPIO_MODER_MODE8_Msk           (0x3UL << GPIO_MODER_MODE8_Pos)         /*!< 0x00030000 */
#define GPIO_MODER_MODE8               GPIO_MODER_MODE8_Msk
#define GPIO_MODER_MODE8_0             (0x1U << GPIO_MODER_MODE8_Pos)          /*!< 0x00010000 */
#define GPIO_MODER_MODE8_1             (0x2U << GPIO_MODER_MODE8_Pos)          /*!< 0x00020000 */
#define GPIO_MODER_MODE9_Pos           (18U)
#define GPIO_MODER_MODE9_Msk           (0x3UL << GPIO_MODER_MODE9_Pos)         /*!< 0x000C0000 */
#define GPIO_MODER_MODE9               GPIO_MODER_MODE9_Msk
#define GPIO_MODER_MODE9_0             (0x1U << GPIO_MODER_MODE9_Pos)          /*!< 0x00040000 */
#define GPIO_MODER_MODE9_1             (0x2U << GPIO_MODER_MODE9_Pos)          /*!< 0x00080000 */
#define GPIO_MODER_MODE10_Pos          (20U)
#define GPIO_MODER_MODE10_Msk          (0x3UL << GPIO_MODER_MODE10_Pos)        /*!< 0x00300000 */
#define GPIO_MODER_MODE10              GPIO_MODER_MODE10_Msk
#define GPIO_MODER_MODE10_0            (0x1U << GPIO_MODER_MODE10_Pos)         /*!< 0x00100000 */
#define GPIO_MODER_MODE10_1            (0x2U << GPIO_MODER_MODE10_Pos)         /*!< 0x00200000 */
#define GPIO_MODER_MODE11_Pos          (22U)
#define GPIO_MODER_MODE11_Msk          (0x3UL << GPIO_MODER_MODE11_Pos)        /*!< 0x00C00000 */
#define GPIO_MODER_MODE11              GPIO_MODER_MODE11_Msk
#define GPIO_MODER_MODE11_0            (0x1U << GPIO_MODER_MODE11_Pos)         /*!< 0x00400000 */
#define GPIO_MODER_MODE11_1            (0x2U << GPIO_MODER_MODE11_Pos)         /*!< 0x00800000 */
#define GPIO_MODER_MODE12_Pos          (24U)
#define GPIO_MODER_MODE12_Msk          (0x3UL << GPIO_MODER_MODE12_Pos)        /*!< 0x03000000 */
#define GPIO_MODER_MODE12              GPIO_MODER_MODE12_Msk
#define GPIO_MODER_MODE12_0            (0x1U << GPIO_MODER_MODE12_Pos)         /*!< 0x01000000 */
#define GPIO_MODER_MODE12_1            (0x2U << GPIO_MODER_MODE12_Pos)         /*!< 0x02000000 */
#define GPIO_MODER_MODE13_Pos          (26U)
#define GPIO_MODER_MODE13_Msk          (0x3UL << GPIO_MODER_MODE13_Pos)        /*!< 0x0C000000 */
#define GPIO_MODER_MODE13              GPIO_MODER_MODE13_Msk
#define GPIO_MODER_MODE13_0            (0x1U << GPIO_MODER_MODE13_Pos)         /*!< 0x04000000 */
#define GPIO_MODER_MODE13_1            (0x2U << GPIO_MODER_MODE13_Pos)         /*!< 0x08000000 */
#define GPIO_MODER_MODE14_Pos          (28U)
#define GPIO_MODER_MODE14_Msk          (0x3UL << GPIO_MODER_MODE14_Pos)        /*!< 0x30000000 */
#define GPIO_MODER_MODE14              GPIO_MODER_MODE14_Msk
#define GPIO_MODER_MODE14_0            (0x1U << GPIO_MODER_MODE14_Pos)         /*!< 0x10000000 */
#define GPIO_MODER_MODE14_1            (0x2U << GPIO_MODER_MODE14_Pos)         /*!< 0x20000000 */
#define GPIO_MODER_MODE15_Pos          (30U)
#define GPIO_MODER_MODE15_Msk          (0x3UL << GPIO_MODER_MODE15_Pos)        /*!< 0xC0000000 */
#define GPIO_MODER_MODE15              GPIO_MODER_MODE15_Msk
#define GPIO_MODER_MODE15_0            (0x1U << GPIO_MODER_MODE15_Pos)         /*!< 0x40000000 */
#define GPIO_MODER_MODE15_1            (0x2U << GPIO_MODER_MODE15_Pos)         /*!< 0x80000000 */

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT0_Pos            (0U)
#define GPIO_OTYPER_OT0_Msk            (0x1UL << GPIO_OTYPER_OT0_Pos)          /*!< 0x00000001 */
#define GPIO_OTYPER_OT0                GPIO_OTYPER_OT0_Msk
#define GPIO_OTYPER_OT1_Pos            (1U)
#define GPIO_OTYPER_OT1_Msk            (0x1UL << GPIO_OTYPER_OT1_Pos)          /*!< 0x00000002 */
#define GPIO_OTYPER_OT1                GPIO_OTYPER_OT1_Msk
#define GPIO_OTYPER_OT2_Pos            (2U)
#define GPIO_OTYPER_OT2_Msk            (0x1UL << GPIO_OTYPER_OT2_Pos)          /*!< 0x00000004 */
#define GPIO_OTYPER_OT2                GPIO_OTYPER_OT2_Msk
#define GPIO_OTYPER_OT3_Pos            (3U)
#define GPIO_OTYPER_OT3_Msk            (0x1UL << GPIO_OTYPER_OT3_Pos)          /*!< 0x00000008 */
#define GPIO_OTYPER_OT3                GPIO_OTYPER_OT3_Msk
#define GPIO_OTYPER_OT4_Pos            (4U)
#define GPIO_OTYPER_OT4_Msk            (0x1UL << GPIO_OTYPER_OT4_Pos)          /*!< 0x00000010 */
#define GPIO_OTYPER_OT4                GPIO_OTYPER_OT4_Msk
#define GPIO_OTYPER_OT5_Pos            (5U)
#define GPIO_OTYPER_OT5_Msk            (0x1UL << GPIO_OTYPER_OT5_Pos)          /*!< 0x00000020 */
#define GPIO_OTYPER_OT5                GPIO_OTYPER_OT5_Msk
#define GPIO_OTYPER_OT6_Pos            (6U)
#define GPIO_OTYPER_OT6_Msk            (0x1UL << GPIO_OTYPER_OT6_Pos)          /*!< 0x00000040 */
#define GPIO_OTYPER_OT6                GPIO_OTYPER_OT6_Msk
#define GPIO_OTYPER_OT7_Pos            (7U)
#define GPIO_OTYPER_OT7_Msk            (0x1UL << GPIO_OTYPER_OT7_Pos)          /*!< 0x00000080 */
#define GPIO_OTYPER_OT7                GPIO_OTYPER_OT7_Msk
#define GPIO_OTYPER_OT8_Pos            (8U)
#define GPIO_OTYPER_OT8_Msk            (0x1UL << GPIO_OTYPER_OT8_Pos)          /*!< 0x00000100 */
#define GPIO_OTYPER_OT8                GPIO_OTYPER_OT8_Msk
#define GPIO_OTYPER_OT9_Pos            (9U)
#define GPIO_OTYPER_OT9_Msk            (0x1UL << GPIO_OTYPER_OT9_Pos)          /*!< 0x00000200 */
#define GPIO_OTYPER_OT9                GPIO_OTYPER_OT9_Msk
#define GPIO_OTYPER_OT10_Pos           (10U)
#define GPIO_OTYPER_OT10_Msk           (0x1UL << GPIO_OTYPER_OT10_Pos)         /*!< 0x00000400 */
#define GPIO_OTYPER_OT10               GPIO_OTYPER_OT10_Msk
#define GPIO_OTYPER_OT11_Pos           (11U)
#define GPIO_OTYPER_OT11_Msk           (0x1UL << GPIO_OTYPER_OT11_Pos)         /*!< 0x00000800 */
#define GPIO_OTYPER_OT11               GPIO_OTYPER_OT11_Msk
#define GPIO_OTYPER_OT12_Pos           (12U)
#define GPIO_OTYPER_OT12_Msk           (0x1UL << GPIO_OTYPER_OT12_Pos)         /*!< 0x00001000 */
#define GPIO_OTYPER_OT12               GPIO_OTYPER_OT12_Msk
#define GPIO_OTYPER_OT13_Pos           (13U)
#define GPIO_OTYPER_OT13_Msk           (0x1UL << GPIO_OTYPER_OT13_Pos)         /*!< 0x00002000 */
#define GPIO_OTYPER_OT13               GPIO_OTYPER_OT13_Msk
#define GPIO_OTYPER_OT14_Pos           (14U)
#define GPIO_OTYPER_OT14_Msk           (0x1UL << GPIO_OTYPER_OT14_Pos)         /*!< 0x00004000 */
#define GPIO_OTYPER_OT14               GPIO_OTYPER_OT14_Msk
#define GPIO_OTYPER_OT15_Pos           (15U)
#define GPIO_OTYPER_OT15_Msk           (0x1UL << GPIO_OTYPER_OT15_Pos)         /*!< 0x00008000 */
#define GPIO_OTYPER_OT15               GPIO_OTYPER_OT15_Msk

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define GPIO_OSPEEDR_OSPEED0_Pos       (0U)
#define GPIO_OSPEEDR_OSPEED0_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED0_Pos)     /*!< 0x00000003 */
#define GPIO_OSPEEDR_OSPEED0           GPIO_OSPEEDR_OSPEED0_Msk
#define GPIO_OSPEEDR_OSPEED0_0         (0x1U << GPIO_OSPEEDR_OSPEED0_Pos)      /*!< 0x00000001 */
#define GPIO_OSPEEDR_OSPEED0_1         (0x2U << GPIO_OSPEEDR_OSPEED0_Pos)      /*!< 0x00000002 */
#define GPIO_OSPEEDR_OSPEED1_Pos       (2U)
#define GPIO_OSPEEDR_OSPEED1_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED1_Pos)     /*!< 0x0000000C */
#define GPIO_OSPEEDR_OSPEED1           GPIO_OSPEEDR_OSPEED1_Msk
#define GPIO_OSPEEDR_OSPEED1_0         (0x1U << GPIO_OSPEEDR_OSPEED1_Pos)      /*!< 0x00000004 */
#define GPIO_OSPEEDR_OSPEED1_1         (0x2U << GPIO_OSPEEDR_OSPEED1_Pos)      /*!< 0x00000008 */
#define GPIO_OSPEEDR_OSPEED2_Pos       (4U)
#define GPIO_OSPEEDR_OSPEED2_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED2_Pos)     /*!< 0x00000030 */
#define GPIO_OSPEEDR_OSPEED2           GPIO_OSPEEDR_OSPEED2_Msk
#define GPIO_OSPEEDR_OSPEED2_0         (0x1U << GPIO_OSPEEDR_OSPEED2_Pos)      /*!< 0x00000010 */
#define GPIO_OSPEEDR_OSPEED2_1         (0x2U << GPIO_OSPEEDR_OSPEED2_Pos)      /*!< 0x00000020 */
#define GPIO_OSPEEDR_OSPEED3_Pos       (6U)
#define GPIO_OSPEEDR_OSPEED3_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED3_Pos)     /*!< 0x000000C0 */
#define GPIO_OSPEEDR_OSPEED3           GPIO_OSPEEDR_OSPEED3_Msk
#define GPIO_OSPEEDR_OSPEED3_0         (0x1U << GPIO_OSPEEDR_OSPEED3_Pos)      /*!< 0x00000040 */
#define GPIO_OSPEEDR_OSPEED3_1         (0x2U << GPIO_OSPEEDR_OSPEED3_Pos)      /*!< 0x00000080 */
#define GPIO_OSPEEDR_OSPEED4_Pos       (8U)
#define GPIO_OSPEEDR_OSPEED4_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED4_Pos)     /*!< 0x00000300 */
#define GPIO_OSPEEDR_OSPEED4           GPIO_OSPEEDR_OSPEED4_Msk
#define GPIO_OSPEEDR_OSPEED4_0         (0x1U << GPIO_OSPEEDR_OSPEED4_Pos)      /*!< 0x00000100 */
#define GPIO_OSPEEDR_OSPEED4_1         (0x2U << GPIO_OSPEEDR_OSPEED4_Pos)      /*!< 0x00000200 */
#define GPIO_OSPEEDR_OSPEED5_Pos       (10U)
#define GPIO_OSPEEDR_OSPEED5_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED5_Pos)     /*!< 0x00000C00 */
#define GPIO_OSPEEDR_OSPEED5           GPIO_OSPEEDR_OSPEED5_Msk
#define GPIO_OSPEEDR_OSPEED5_0         (0x1U << GPIO_OSPEEDR_OSPEED5_Pos)      /*!< 0x00000400 */
#define GPIO_OSPEEDR_OSPEED5_1         (0x2U << GPIO_OSPEEDR_OSPEED5_Pos)      /*!< 0x00000800 */
#define GPIO_OSPEEDR_OSPEED6_Pos       (12U)
#define GPIO_OSPEEDR_OSPEED6_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED6_Pos)     /*!< 0x00003000 */
#define GPIO_OSPEEDR_OSPEED6           GPIO_OSPEEDR_OSPEED6_Msk
#define GPIO_OSPEEDR_OSPEED6_0         (0x1U << GPIO_OSPEEDR_OSPEED6_Pos)      /*!< 0x00001000 */
#define GPIO_OSPEEDR_OSPEED6_1         (0x2U << GPIO_OSPEEDR_OSPEED6_Pos)      /*!< 0x00002000 */
#define GPIO_OSPEEDR_OSPEED7_Pos       (14U)
#define GPIO_OSPEEDR_OSPEED7_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED7_Pos)     /*!< 0x0000C000 */
#define GPIO_OSPEEDR_OSPEED7           GPIO_OSPEEDR_OSPEED7_Msk
#define GPIO_OSPEEDR_OSPEED7_0         (0x1U << GPIO_OSPEEDR_OSPEED7_Pos)      /*!< 0x00004000 */
#define GPIO_OSPEEDR_OSPEED7_1         (0x2U << GPIO_OSPEEDR_OSPEED7_Pos)      /*!< 0x00008000 */
#define GPIO_OSPEEDR_OSPEED8_Pos       (16U)
#define GPIO_OSPEEDR_OSPEED8_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED8_Pos)     /*!< 0x00030000 */
#define GPIO_OSPEEDR_OSPEED8           GPIO_OSPEEDR_OSPEED8_Msk
#define GPIO_OSPEEDR_OSPEED8_0         (0x1U << GPIO_OSPEEDR_OSPEED8_Pos)      /*!< 0x00010000 */
#define GPIO_OSPEEDR_OSPEED8_1         (0x2U << GPIO_OSPEEDR_OSPEED8_Pos)      /*!< 0x00020000 */
#define GPIO_OSPEEDR_OSPEED9_Pos       (18U)
#define GPIO_OSPEEDR_OSPEED9_Msk       (0x3UL << GPIO_OSPEEDR_OSPEED9_Pos)     /*!< 0x000C0000 */
#define GPIO_OSPEEDR_OSPEED9           GPIO_OSPEEDR_OSPEED9_Msk
#define GPIO_OSPEEDR_OSPEED9_0         (0x1U << GPIO_OSPEEDR_OSPEED9_Pos)      /*!< 0x00040000 */
#define GPIO_OSPEEDR_OSPEED9_1         (0x2U << GPIO_OSPEEDR_OSPEED9_Pos)      /*!< 0x00080000 */
#define GPIO_OSPEEDR_OSPEED10_Pos      (20U)
#define GPIO_OSPEEDR_OSPEED10_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED10_Pos)    /*!< 0x00300000 */
#define GPIO_OSPEEDR_OSPEED10          GPIO_OSPEEDR_OSPEED10_Msk
#define GPIO_OSPEEDR_OSPEED10_0        (0x1U << GPIO_OSPEEDR_OSPEED10_Pos)     /*!< 0x00100000 */
#define GPIO_OSPEEDR_OSPEED10_1        (0x2U << GPIO_OSPEEDR_OSPEED10_Pos)     /*!< 0x00200000 */
#define GPIO_OSPEEDR_OSPEED11_Pos      (22U)
#define GPIO_OSPEEDR_OSPEED11_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED11_Pos)    /*!< 0x00C00000 */
#define GPIO_OSPEEDR_OSPEED11          GPIO_OSPEEDR_OSPEED11_Msk
#define GPIO_OSPEEDR_OSPEED11_0        (0x1U << GPIO_OSPEEDR_OSPEED11_Pos)     /*!< 0x00400000 */
#define GPIO_OSPEEDR_OSPEED11_1        (0x2U << GPIO_OSPEEDR_OSPEED11_Pos)     /*!< 0x00800000 */
#define GPIO_OSPEEDR_OSPEED12_Pos      (24U)
#define GPIO_OSPEEDR_OSPEED12_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED12_Pos)    /*!< 0x03000000 */
#define GPIO_OSPEEDR_OSPEED12          GPIO_OSPEEDR_OSPEED12_Msk
#define GPIO_OSPEEDR_OSPEED12_0        (0x1U << GPIO_OSPEEDR_OSPEED12_Pos)     /*!< 0x01000000 */
#define GPIO_OSPEEDR_OSPEED12_1        (0x2U << GPIO_OSPEEDR_OSPEED12_Pos)     /*!< 0x02000000 */
#define GPIO_OSPEEDR_OSPEED13_Pos      (26U)
#define GPIO_OSPEEDR_OSPEED13_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED13_Pos)    /*!< 0x0C000000 */
#define GPIO_OSPEEDR_OSPEED13          GPIO_OSPEEDR_OSPEED13_Msk
#define GPIO_OSPEEDR_OSPEED13_0        (0x1U << GPIO_OSPEEDR_OSPEED13_Pos)     /*!< 0x04000000 */
#define GPIO_OSPEEDR_OSPEED13_1        (0x2U << GPIO_OSPEEDR_OSPEED13_Pos)     /*!< 0x08000000 */
#define GPIO_OSPEEDR_OSPEED14_Pos      (28U)
#define GPIO_OSPEEDR_OSPEED14_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED14_Pos)    /*!< 0x30000000 */
#define GPIO_OSPEEDR_OSPEED14          GPIO_OSPEEDR_OSPEED14_Msk
#define GPIO_OSPEEDR_OSPEED14_0        (0x1U << GPIO_OSPEEDR_OSPEED14_Pos)     /*!< 0x10000000 */
#define GPIO_OSPEEDR_OSPEED14_1        (0x2U << GPIO_OSPEEDR_OSPEED14_Pos)     /*!< 0x20000000 */
#define GPIO_OSPEEDR_OSPEED15_Pos      (30U)
#define GPIO_OSPEEDR_OSPEED15_Msk      (0x3UL << GPIO_OSPEEDR_OSPEED15_Pos)    /*!< 0xC0000000 */
#define GPIO_OSPEEDR_OSPEED15          GPIO_OSPEEDR_OSPEED15_Msk
#define GPIO_OSPEEDR_OSPEED15_0        (0x1U << GPIO_OSPEEDR_OSPEED15_Pos)     /*!< 0x40000000 */
#define GPIO_OSPEEDR_OSPEED15_1        (0x2U << GPIO_OSPEEDR_OSPEED15_Pos)     /*!< 0x80000000 */

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPD0_Pos           (0U)
#define GPIO_PUPDR_PUPD0_Msk           (0x3UL << GPIO_PUPDR_PUPD0_Pos)         /*!< 0x00000003 */
#define GPIO_PUPDR_PUPD0               GPIO_PUPDR_PUPD0_Msk
#define GPIO_PUPDR_PUPD0_0             (0x1U << GPIO_PUPDR_PUPD0_Pos)          /*!< 0x00000001 */
#define GPIO_PUPDR_PUPD0_1             (0x2U << GPIO_PUPDR_PUPD0_Pos)          /*!< 0x00000002 */
#define GPIO_PUPDR_PUPD1_Pos           (2U)
#define GPIO_PUPDR_PUPD1_Msk           (0x3UL << GPIO_PUPDR_PUPD1_Pos)         /*!< 0x0000000C */
#define GPIO_PUPDR_PUPD1               GPIO_PUPDR_PUPD1_Msk
#define GPIO_PUPDR_PUPD1_0             (0x1U << GPIO_PUPDR_PUPD1_Pos)          /*!< 0x00000004 */
#define GPIO_PUPDR_PUPD1_1             (0x2U << GPIO_PUPDR_PUPD1_Pos)          /*!< 0x00000008 */
#define GPIO_PUPDR_PUPD2_Pos           (4U)
#define GPIO_PUPDR_PUPD2_Msk           (0x3UL << GPIO_PUPDR_PUPD2_Pos)         /*!< 0x00000030 */
#define GPIO_PUPDR_PUPD2               GPIO_PUPDR_PUPD2_Msk
#define GPIO_PUPDR_PUPD2_0             (0x1U << GPIO_PUPDR_PUPD2_Pos)          /*!< 0x00000010 */
#define GPIO_PUPDR_PUPD2_1             (0x2U << GPIO_PUPDR_PUPD2_Pos)          /*!< 0x00000020 */
#define GPIO_PUPDR_PUPD3_Pos           (6U)
#define GPIO_PUPDR_PUPD3_Msk           (0x3UL << GPIO_PUPDR_PUPD3_Pos)         /*!< 0x000000C0 */
#define GPIO_PUPDR_PUPD3               GPIO_PUPDR_PUPD3_Msk
#define GPIO_PUPDR_PUPD3_0             (0x1U << GPIO_PUPDR_PUPD3_Pos)          /*!< 0x00000040 */
#define GPIO_PUPDR_PUPD3_1             (0x2U << GPIO_PUPDR_PUPD3_Pos)          /*!< 0x00000080 */
#define GPIO_PUPDR_PUPD4_Pos           (8U)
#define GPIO_PUPDR_PUPD4_Msk           (0x3UL << GPIO_PUPDR_PUPD4_Pos)         /*!< 0x00000300 */
#define GPIO_PUPDR_PUPD4               GPIO_PUPDR_PUPD4_Msk
#define GPIO_PUPDR_PUPD4_0             (0x1U << GPIO_PUPDR_PUPD4_Pos)          /*!< 0x00000100 */
#define GPIO_PUPDR_PUPD4_1             (0x2U << GPIO_PUPDR_PUPD4_Pos)          /*!< 0x00000200 */
#define GPIO_PUPDR_PUPD5_Pos           (10U)
#define GPIO_PUPDR_PUPD5_Msk           (0x3UL << GPIO_PUPDR_PUPD5_Pos)         /*!< 0x00000C00 */
#define GPIO_PUPDR_PUPD5               GPIO_PUPDR_PUPD5_Msk
#define GPIO_PUPDR_PUPD5_0             (0x1U << GPIO_PUPDR_PUPD5_Pos)          /*!< 0x00000400 */
#define GPIO_PUPDR_PUPD5_1             (0x2U << GPIO_PUPDR_PUPD5_Pos)          /*!< 0x00000800 */
#define GPIO_PUPDR_PUPD6_Pos           (12U)
#define GPIO_PUPDR_PUPD6_Msk           (0x3UL << GPIO_PUPDR_PUPD6_Pos)         /*!< 0x00003000 */
#define GPIO_PUPDR_PUPD6               GPIO_PUPDR_PUPD6_Msk
#define GPIO_PUPDR_PUPD6_0             (0x1U << GPIO_PUPDR_PUPD6_Pos)          /*!< 0x00001000 */
#define GPIO_PUPDR_PUPD6_1             (0x2U << GPIO_PUPDR_PUPD6_Pos)          /*!< 0x00002000 */
#define GPIO_PUPDR_PUPD7_Pos           (14U)
#define GPIO_PUPDR_PUPD7_Msk           (0x3UL << GPIO_PUPDR_PUPD7_Pos)         /*!< 0x0000C000 */
#define GPIO_PUPDR_PUPD7               GPIO_PUPDR_PUPD7_Msk
#define GPIO_PUPDR_PUPD7_0             (0x1U << GPIO_PUPDR_PUPD7_Pos)          /*!< 0x00004000 */
#define GPIO_PUPDR_PUPD7_1             (0x2U << GPIO_PUPDR_PUPD7_Pos)          /*!< 0x00008000 */
#define GPIO_PUPDR_PUPD8_Pos           (16U)
#define GPIO_PUPDR_PUPD8_Msk           (0x3UL << GPIO_PUPDR_PUPD8_Pos)         /*!< 0x00030000 */
#define GPIO_PUPDR_PUPD8               GPIO_PUPDR_PUPD8_Msk
#define GPIO_PUPDR_PUPD8_0             (0x1U << GPIO_PUPDR_PUPD8_Pos)          /*!< 0x00010000 */
#define GPIO_PUPDR_PUPD8_1             (0x2U << GPIO_PUPDR_PUPD8_Pos)          /*!< 0x00020000 */
#define GPIO_PUPDR_PUPD9_Pos           (18U)
#define GPIO_PUPDR_PUPD9_Msk           (0x3UL << GPIO_PUPDR_PUPD9_Pos)         /*!< 0x000C0000 */
#define GPIO_PUPDR_PUPD9               GPIO_PUPDR_PUPD9_Msk
#define GPIO_PUPDR_PUPD9_0             (0x1U << GPIO_PUPDR_PUPD9_Pos)          /*!< 0x00040000 */
#define GPIO_PUPDR_PUPD9_1             (0x2U << GPIO_PUPDR_PUPD9_Pos)          /*!< 0x00080000 */
#define GPIO_PUPDR_PUPD10_Pos          (20U)
#define GPIO_PUPDR_PUPD10_Msk          (0x3UL << GPIO_PUPDR_PUPD10_Pos)        /*!< 0x00300000 */
#define GPIO_PUPDR_PUPD10              GPIO_PUPDR_PUPD10_Msk
#define GPIO_PUPDR_PUPD10_0            (0x1U << GPIO_PUPDR_PUPD10_Pos)         /*!< 0x00100000 */
#define GPIO_PUPDR_PUPD10_1            (0x2U << GPIO_PUPDR_PUPD10_Pos)         /*!< 0x00200000 */
#define GPIO_PUPDR_PUPD11_Pos          (22U)
#define GPIO_PUPDR_PUPD11_Msk          (0x3UL << GPIO_PUPDR_PUPD11_Pos)        /*!< 0x00C00000 */
#define GPIO_PUPDR_PUPD11              GPIO_PUPDR_PUPD11_Msk
#define GPIO_PUPDR_PUPD11_0            (0x1U << GPIO_PUPDR_PUPD11_Pos)         /*!< 0x00400000 */
#define GPIO_PUPDR_PUPD11_1            (0x2U << GPIO_PUPDR_PUPD11_Pos)         /*!< 0x00800000 */
#define GPIO_PUPDR_PUPD12_Pos          (24U)
#define GPIO_PUPDR_PUPD12_Msk          (0x3UL << GPIO_PUPDR_PUPD12_Pos)        /*!< 0x03000000 */
#define GPIO_PUPDR_PUPD12              GPIO_PUPDR_PUPD12_Msk
#define GPIO_PUPDR_PUPD12_0            (0x1U << GPIO_PUPDR_PUPD12_Pos)         /*!< 0x01000000 */
#define GPIO_PUPDR_PUPD12_1            (0x2U << GPIO_PUPDR_PUPD12_Pos)         /*!< 0x02000000 */
#define GPIO_PUPDR_PUPD13_Pos          (26U)
#define GPIO_PUPDR_PUPD13_Msk          (0x3UL << GPIO_PUPDR_PUPD13_Pos)        /*!< 0x0C000000 */
#define GPIO_PUPDR_PUPD13              GPIO_PUPDR_PUPD13_Msk
#define GPIO_PUPDR_PUPD13_0            (0x1U << GPIO_PUPDR_PUPD13_Pos)         /*!< 0x04000000 */
#define GPIO_PUPDR_PUPD13_1            (0x2U << GPIO_PUPDR_PUPD13_Pos)         /*!< 0x08000000 */
#define GPIO_PUPDR_PUPD14_Pos          (28U)
#define GPIO_PUPDR_PUPD14_Msk          (0x3UL << GPIO_PUPDR_PUPD14_Pos)        /*!< 0x30000000 */
#define GPIO_PUPDR_PUPD14              GPIO_PUPDR_PUPD14_Msk
#define GPIO_PUPDR_PUPD14_0            (0x1U << GPIO_PUPDR_PUPD14_Pos)         /*!< 0x10000000 */
#define GPIO_PUPDR_PUPD14_1            (0x2U << GPIO_PUPDR_PUPD14_Pos)         /*!< 0x20000000 */
#define GPIO_PUPDR_PUPD15_Pos          (30U)
#define GPIO_PUPDR_PUPD15_Msk          (0x3UL << GPIO_PUPDR_PUPD15_Pos)        /*!< 0xC0000000 */
#define GPIO_PUPDR_PUPD15              GPIO_PUPDR_PUPD15_Msk
#define GPIO_PUPDR_PUPD15_0            (0x1U << GPIO_PUPDR_PUPD15_Pos)         /*!< 0x40000000 */
#define GPIO_PUPDR_PUPD15_1            (0x2U << GPIO_PUPDR_PUPD15_Pos)         /*!< 0x80000000 */

/******************  Bits definition for GPIO_IDR register  *******************/
#define GPIO_IDR_ID0_Pos               (0U)
#define GPIO_IDR_ID0_Msk               (0x1UL << GPIO_IDR_ID0_Pos)             /*!< 0x00000001 */
#define GPIO_IDR_ID0                   GPIO_IDR_ID0_Msk
#define GPIO_IDR_ID1_Pos               (1U)
#define GPIO_IDR_ID1_Msk               (0x1UL << GPIO_IDR_ID1_Pos)             /*!< 0x00000002 */
#define GPIO_IDR_ID1                   GPIO_IDR_ID1_Msk
#define GPIO_IDR_ID2_Pos               (2U)
#define GPIO_IDR_ID2_Msk               (0x1UL << GPIO_IDR_ID2_Pos)             /*!< 0x00000004 */
#define GPIO_IDR_ID2                   GPIO_IDR_ID2_Msk
#define GPIO_IDR_ID3_Pos               (3U)
#define GPIO_IDR_ID3_Msk               (0x1UL << GPIO_IDR_ID3_Pos)             /*!< 0x00000008 */
#define GPIO_IDR_ID3                   GPIO_IDR_ID3_Msk
#define GPIO_IDR_ID4_Pos               (4U)
#define GPIO_IDR_ID4_Msk               (0x1UL << GPIO_IDR_ID4_Pos)             /*!< 0x00000010 */
#define GPIO_IDR_ID4                   GPIO_IDR_ID4_Msk
#define GPIO_IDR_ID5_Pos               (5U)
#define GPIO_IDR_ID5_Msk               (0x1UL << GPIO_IDR_ID5_Pos)             /*!< 0x00000020 */
#define GPIO_IDR_ID5                   GPIO_IDR_ID5_Msk
#define GPIO_IDR_ID6_Pos               (6U)
#define GPIO_IDR_ID6_Msk               (0x1UL << GPIO_IDR_ID6_Pos)             /*!< 0x00000040 */
#define GPIO_IDR_ID6                   GPIO_IDR_ID6_Msk
#define GPIO_IDR_ID7_Pos               (7U)
#define GPIO_IDR_ID7_Msk               (0x1UL << GPIO_IDR_ID7_Pos)             /*!< 0x00000080 */
#define GPIO_IDR_ID7                   GPIO_IDR_ID7_Msk
#define GPIO_IDR_ID8_Pos               (8U)
#define GPIO_IDR_ID8_Msk               (0x1UL << GPIO_IDR_ID8_Pos)             /*!< 0x00000100 */
#define GPIO_IDR_ID8                   GPIO_IDR_ID8_Msk
#define GPIO_IDR_ID9_Pos               (9U)
#define GPIO_IDR_ID9_Msk               (0x1UL << GPIO_IDR_ID9_Pos)             /*!< 0x00000200 */
#define GPIO_IDR_ID9                   GPIO_IDR_ID9_Msk
#define GPIO_IDR_ID10_Pos              (10U)
#define GPIO_IDR_ID10_Msk              (0x1UL << GPIO_IDR_ID10_Pos)            /*!< 0x00000400 */
#define GPIO_IDR_ID10                  GPIO_IDR_ID10_Msk
#define GPIO_IDR_ID11_Pos              (11U)
#define GPIO_IDR_ID11_Msk              (0x1UL << GPIO_IDR_ID11_Pos)            /*!< 0x00000800 */
#define GPIO_IDR_ID11                  GPIO_IDR_ID11_Msk
#define GPIO_IDR_ID12_Pos              (12U)
#define GPIO_IDR_ID12_Msk              (0x1UL << GPIO_IDR_ID12_Pos)            /*!< 0x00001000 */
#define GPIO_IDR_ID12                  GPIO_IDR_ID12_Msk
#define GPIO_IDR_ID13_Pos              (13U)
#define GPIO_IDR_ID13_Msk              (0x1UL << GPIO_IDR_ID13_Pos)            /*!< 0x00002000 */
#define GPIO_IDR_ID13                  GPIO_IDR_ID13_Msk
#define GPIO_IDR_ID14_Pos              (14U)
#define GPIO_IDR_ID14_Msk              (0x1UL << GPIO_IDR_ID14_Pos)            /*!< 0x00004000 */
#define GPIO_IDR_ID14                  GPIO_IDR_ID14_Msk
#define GPIO_IDR_ID15_Pos              (15U)
#define GPIO_IDR_ID15_Msk              (0x1UL << GPIO_IDR_ID15_Pos)            /*!< 0x00008000 */
#define GPIO_IDR_ID15                  GPIO_IDR_ID15_Msk

/******************  Bits definition for GPIO_ODR register  *******************/
#define GPIO_ODR_OD0_Pos               (0U)
#define GPIO_ODR_OD0_Msk               (0x1UL << GPIO_ODR_OD0_Pos)             /*!< 0x00000001 */
#define GPIO_ODR_OD0                   GPIO_ODR_OD0_Msk
#define GPIO_ODR_OD1_Pos               (1U)
#define GPIO_ODR_OD1_Msk               (0x1UL << GPIO_ODR_OD1_Pos)             /*!< 0x00000002 */
#define GPIO_ODR_OD1                   GPIO_ODR_OD1_Msk
#define GPIO_ODR_OD2_Pos               (2U)
#define GPIO_ODR_OD2_Msk               (0x1UL << GPIO_ODR_OD2_Pos)             /*!< 0x00000004 */
#define GPIO_ODR_OD2                   GPIO_ODR_OD2_Msk
#define GPIO_ODR_OD3_Pos               (3U)
#define GPIO_ODR_OD3_Msk               (0x1UL << GPIO_ODR_OD3_Pos)             /*!< 0x00000008 */
#define GPIO_ODR_OD3                   GPIO_ODR_OD3_Msk
#define GPIO_ODR_OD4_Pos               (4U)
#define GPIO_ODR_OD4_Msk               (0x1UL << GPIO_ODR_OD4_Pos)             /*!< 0x00000010 */
#define GPIO_ODR_OD4                   GPIO_ODR_OD4_Msk
#define GPIO_ODR_OD5_Pos               (5U)
#define GPIO_ODR_OD5_Msk               (0x1UL << GPIO_ODR_OD5_Pos)             /*!< 0x00000020 */
#define GPIO_ODR_OD5                   GPIO_ODR_OD5_Msk
#define GPIO_ODR_OD6_Pos               (6U)
#define GPIO_ODR_OD6_Msk               (0x1UL << GPIO_ODR_OD6_Pos)             /*!< 0x00000040 */
#define GPIO_ODR_OD6                   GPIO_ODR_OD6_Msk
#define GPIO_ODR_OD7_Pos               (7U)
#define GPIO_ODR_OD7_Msk               (0x1UL << GPIO_ODR_OD7_Pos)             /*!< 0x00000080 */
#define GPIO_ODR_OD7                   GPIO_ODR_OD7_Msk
#define GPIO_ODR_OD8_Pos               (8U)
#define GPIO_ODR_OD8_Msk               (0x1UL << GPIO_ODR_OD8_Pos)             /*!< 0x00000100 */
#define GPIO_ODR_OD8                   GPIO_ODR_OD8_Msk
#define GPIO_ODR_OD9_Pos               (9U)
#define GPIO_ODR_OD9_Msk               (0x1UL << GPIO_ODR_OD9_Pos)             /*!< 0x00000200 */
#define GPIO_ODR_OD9                   GPIO_ODR_OD9_Msk
#define GPIO_ODR_OD10_Pos              (10U)
#define GPIO_ODR_OD10_Msk              (0x1UL << GPIO_ODR_OD10_Pos)            /*!< 0x00000400 */
#define GPIO_ODR_OD10                  GPIO_ODR_OD10_Msk
#define GPIO_ODR_OD11_Pos              (11U)
#define GPIO_ODR_OD11_Msk              (0x1UL << GPIO_ODR_OD11_Pos)            /*!< 0x00000800 */
#define GPIO_ODR_OD11                  GPIO_ODR_OD11_Msk
#define GPIO_ODR_OD12_Pos              (12U)
#define GPIO_ODR_OD12_Msk              (0x1UL << GPIO_ODR_OD12_Pos)            /*!< 0x00001000 */
#define GPIO_ODR_OD12                  GPIO_ODR_OD12_Msk
#define GPIO_ODR_OD13_Pos              (13U)
#define GPIO_ODR_OD13_Msk              (0x1UL << GPIO_ODR_OD13_Pos)            /*!< 0x00002000 */
#define GPIO_ODR_OD13                  GPIO_ODR_OD13_Msk
#define GPIO_ODR_OD14_Pos              (14U)
#define GPIO_ODR_OD14_Msk              (0x1UL << GPIO_ODR_OD14_Pos)            /*!< 0x00004000 */
#define GPIO_ODR_OD14                  GPIO_ODR_OD14_Msk
#define GPIO_ODR_OD15_Pos              (15U)
#define GPIO_ODR_OD15_Msk              (0x1UL << GPIO_ODR_OD15_Pos)            /*!< 0x00008000 */
#define GPIO_ODR_OD15                  GPIO_ODR_OD15_Msk

/******************  Bits definition for GPIO_BSRR register  ******************/
#define GPIO_BSRR_BS0_Pos              (0U)
#define GPIO_BSRR_BS0_Msk              (0x1UL << GPIO_BSRR_BS0_Pos)            /*!< 0x00000001 */
#define GPIO_BSRR_BS0                  GPIO_BSRR_BS0_Msk
#define GPIO_BSRR_BS1_Pos              (1U)
#define GPIO_BSRR_BS1_Msk              (0x1UL << GPIO_BSRR_BS1_Pos)            /*!< 0x00000002 */
#define GPIO_BSRR_BS1                  GPIO_BSRR_BS1_Msk
#define GPIO_BSRR_BS2_Pos              (2U)
#define GPIO_BSRR_BS2_Msk              (0x1UL << GPIO_BSRR_BS2_Pos)            /*!< 0x00000004 */
#define GPIO_BSRR_BS2                  GPIO_BSRR_BS2_Msk
#define GPIO_BSRR_BS3_Pos              (3U)
#define GPIO_BSRR_BS3_Msk              (0x1UL << GPIO_BSRR_BS3_Pos)            /*!< 0x00000008 */
#define GPIO_BSRR_BS3                  GPIO_BSRR_BS3_Msk
#define GPIO_BSRR_BS4_Pos              (4U)
#define GPIO_BSRR_BS4_Msk              (0x1UL << GPIO_BSRR_BS4_Pos)            /*!< 0x00000010 */
#define GPIO_BSRR_BS4                  GPIO_BSRR_BS4_Msk
#define GPIO_BSRR_BS5_Pos              (5U)
#define GPIO_BSRR_BS5_Msk              (0x1UL << GPIO_BSRR_BS5_Pos)            /*!< 0x00000020 */
#define GPIO_BSRR_BS5                  GPIO_BSRR_BS5_Msk
#define GPIO_BSRR_BS6_Pos              (6U)
#define GPIO_BSRR_BS6_Msk              (0x1UL << GPIO_BSRR_BS6_Pos)            /*!< 0x00000040 */
#define GPIO_BSRR_BS6                  GPIO_BSRR_BS6_Msk
#define GPIO_BSRR_BS7_Pos              (7U)
#define GPIO_BSRR_BS7_Msk              (0x1UL << GPIO_BSRR_BS7_Pos)            /*!< 0x00000080 */
#define GPIO_BSRR_BS7                  GPIO_BSRR_BS7_Msk
#define GPIO_BSRR_BS8_Pos              (8U)
#define GPIO_BSRR_BS8_Msk              (0x1UL << GPIO_BSRR_BS8_Pos)            /*!< 0x00000100 */
#define GPIO_BSRR_BS8                  GPIO_BSRR_BS8_Msk
#define GPIO_BSRR_BS9_Pos              (9U)
#define GPIO_BSRR_BS9_Msk              (0x1UL << GPIO_BSRR_BS9_Pos)            /*!< 0x00000200 */
#define GPIO_BSRR_BS9                  GPIO_BSRR_BS9_Msk
#define GPIO_BSRR_BS10_Pos             (10U)
#define GPIO_BSRR_BS10_Msk             (0x1UL << GPIO_BSRR_BS10_Pos)           /*!< 0x00000400 */
#define GPIO_BSRR_BS10                 GPIO_BSRR_BS10_Msk
#define GPIO_BSRR_BS11_Pos             (11U)
#define GPIO_BSRR_BS11_Msk             (0x1UL << GPIO_BSRR_BS11_Pos)           /*!< 0x00000800 */
#define GPIO_BSRR_BS11                 GPIO_BSRR_BS11_Msk
#define GPIO_BSRR_BS12_Pos             (12U)
#define GPIO_BSRR_BS12_Msk             (0x1UL << GPIO_BSRR_BS12_Pos)           /*!< 0x00001000 */
#define GPIO_BSRR_BS12                 GPIO_BSRR_BS12_Msk
#define GPIO_BSRR_BS13_Pos             (13U)
#define GPIO_BSRR_BS13_Msk             (0x1UL << GPIO_BSRR_BS13_Pos)           /*!< 0x00002000 */
#define GPIO_BSRR_BS13                 GPIO_BSRR_BS13_Msk
#define GPIO_BSRR_BS14_Pos             (14U)
#define GPIO_BSRR_BS14_Msk             (0x1UL << GPIO_BSRR_BS14_Pos)           /*!< 0x00004000 */
#define GPIO_BSRR_BS14                 GPIO_BSRR_BS14_Msk
#define GPIO_BSRR_BS15_Pos             (15U)
#define GPIO_BSRR_BS15_Msk             (0x1UL << GPIO_BSRR_BS15_Pos)           /*!< 0x00008000 */
#define GPIO_BSRR_BS15                 GPIO_BSRR_BS15_Msk
#define GPIO_BSRR_BR0_Pos              (16U)
#define GPIO_BSRR_BR0_Msk              (0x1UL << GPIO_BSRR_BR0_Pos)            /*!< 0x00010000 */
#define GPIO_BSRR_BR0                  GPIO_BSRR_BR0_Msk
#define GPIO_BSRR_BR1_Pos              (17U)
#define GPIO_BSRR_BR1_Msk              (0x1UL << GPIO_BSRR_BR1_Pos)            /*!< 0x00020000 */
#define GPIO_BSRR_BR1                  GPIO_BSRR_BR1_Msk
#define GPIO_BSRR_BR2_Pos              (18U)
#define GPIO_BSRR_BR2_Msk              (0x1UL << GPIO_BSRR_BR2_Pos)            /*!< 0x00040000 */
#define GPIO_BSRR_BR2                  GPIO_BSRR_BR2_Msk
#define GPIO_BSRR_BR3_Pos              (19U)
#define GPIO_BSRR_BR3_Msk              (0x1UL << GPIO_BSRR_BR3_Pos)            /*!< 0x00080000 */
#define GPIO_BSRR_BR3                  GPIO_BSRR_BR3_Msk
#define GPIO_BSRR_BR4_Pos              (20U)
#define GPIO_BSRR_BR4_Msk              (0x1UL << GPIO_BSRR_BR4_Pos)            /*!< 0x00100000 */
#define GPIO_BSRR_BR4                  GPIO_BSRR_BR4_Msk
#define GPIO_BSRR_BR5_Pos              (21U)
#define GPIO_BSRR_BR5_Msk              (0x1UL << GPIO_BSRR_BR5_Pos)            /*!< 0x00200000 */
#define GPIO_BSRR_BR5                  GPIO_BSRR_BR5_Msk
#define GPIO_BSRR_BR6_Pos              (22U)
#define GPIO_BSRR_BR6_Msk              (0x1UL << GPIO_BSRR_BR6_Pos)            /*!< 0x00400000 */
#define GPIO_BSRR_BR6                  GPIO_BSRR_BR6_Msk
#define GPIO_BSRR_BR7_Pos              (23U)
#define GPIO_BSRR_BR7_Msk              (0x1UL << GPIO_BSRR_BR7_Pos)            /*!< 0x00800000 */
#define GPIO_BSRR_BR7                  GPIO_BSRR_BR7_Msk
#define GPIO_BSRR_BR8_Pos              (24U)
#define GPIO_BSRR_BR8_Msk              (0x1UL << GPIO_BSRR_BR8_Pos)            /*!< 0x01000000 */
#define GPIO_BSRR_BR8                  GPIO_BSRR_BR8_Msk
#define GPIO_BSRR_BR9_Pos              (25U)
#define GPIO_BSRR_BR9_Msk              (0x1UL << GPIO_BSRR_BR9_Pos)            /*!< 0x02000000 */
#define GPIO_BSRR_BR9                  GPIO_BSRR_BR9_Msk
#define GPIO_BSRR_BR10_Pos             (26U)
#define GPIO_BSRR_BR10_Msk             (0x1UL << GPIO_BSRR_BR10_Pos)           /*!< 0x04000000 */
#define GPIO_BSRR_BR10                 GPIO_BSRR_BR10_Msk
#define GPIO_BSRR_BR11_Pos             (27U)
#define GPIO_BSRR_BR11_Msk             (0x1UL << GPIO_BSRR_BR11_Pos)           /*!< 0x08000000 */
#define GPIO_BSRR_BR11                 GPIO_BSRR_BR11_Msk
#define GPIO_BSRR_BR12_Pos             (28U)
#define GPIO_BSRR_BR12_Msk             (0x1UL << GPIO_BSRR_BR12_Pos)           /*!< 0x10000000 */
#define GPIO_BSRR_BR12                 GPIO_BSRR_BR12_Msk
#define GPIO_BSRR_BR13_Pos             (29U)
#define GPIO_BSRR_BR13_Msk             (0x1UL << GPIO_BSRR_BR13_Pos)           /*!< 0x20000000 */
#define GPIO_BSRR_BR13                 GPIO_BSRR_BR13_Msk
#define GPIO_BSRR_BR14_Pos             (30U)
#define GPIO_BSRR_BR14_Msk             (0x1UL << GPIO_BSRR_BR14_Pos)           /*!< 0x40000000 */
#define GPIO_BSRR_BR14                 GPIO_BSRR_BR14_Msk
#define GPIO_BSRR_BR15_Pos             (31U)
#define GPIO_BSRR_BR15_Msk             (0x1UL << GPIO_BSRR_BR15_Pos)           /*!< 0x80000000 */
#define GPIO_BSRR_BR15                 GPIO_BSRR_BR15_Msk

/****************** Bit definition for GPIO_LCKR register *********************/
#define GPIO_LCKR_LCK0_Pos             (0U)
#define GPIO_LCKR_LCK0_Msk             (0x1UL << GPIO_LCKR_LCK0_Pos)           /*!< 0x00000001 */
#define GPIO_LCKR_LCK0                 GPIO_LCKR_LCK0_Msk
#define GPIO_LCKR_LCK1_Pos             (1U)
#define GPIO_LCKR_LCK1_Msk             (0x1UL << GPIO_LCKR_LCK1_Pos)           /*!< 0x00000002 */
#define GPIO_LCKR_LCK1                 GPIO_LCKR_LCK1_Msk
#define GPIO_LCKR_LCK2_Pos             (2U)
#define GPIO_LCKR_LCK2_Msk             (0x1UL << GPIO_LCKR_LCK2_Pos)           /*!< 0x00000004 */
#define GPIO_LCKR_LCK2                 GPIO_LCKR_LCK2_Msk
#define GPIO_LCKR_LCK3_Pos             (3U)
#define GPIO_LCKR_LCK3_Msk             (0x1UL << GPIO_LCKR_LCK3_Pos)           /*!< 0x00000008 */
#define GPIO_LCKR_LCK3                 GPIO_LCKR_LCK3_Msk
#define GPIO_LCKR_LCK4_Pos             (4U)
#define GPIO_LCKR_LCK4_Msk             (0x1UL << GPIO_LCKR_LCK4_Pos)           /*!< 0x00000010 */
#define GPIO_LCKR_LCK4                 GPIO_LCKR_LCK4_Msk
#define GPIO_LCKR_LCK5_Pos             (5U)
#define GPIO_LCKR_LCK5_Msk             (0x1UL << GPIO_LCKR_LCK5_Pos)           /*!< 0x00000020 */
#define GPIO_LCKR_LCK5                 GPIO_LCKR_LCK5_Msk
#define GPIO_LCKR_LCK6_Pos             (6U)
#define GPIO_LCKR_LCK6_Msk             (0x1UL << GPIO_LCKR_LCK6_Pos)           /*!< 0x00000040 */
#define GPIO_LCKR_LCK6                 GPIO_LCKR_LCK6_Msk
#define GPIO_LCKR_LCK7_Pos             (7U)
#define GPIO_LCKR_LCK7_Msk             (0x1UL << GPIO_LCKR_LCK7_Pos)           /*!< 0x00000080 */
#define GPIO_LCKR_LCK7                 GPIO_LCKR_LCK7_Msk
#define GPIO_LCKR_LCK8_Pos             (8U)
#define GPIO_LCKR_LCK8_Msk             (0x1UL << GPIO_LCKR_LCK8_Pos)           /*!< 0x00000100 */
#define GPIO_LCKR_LCK8                 GPIO_LCKR_LCK8_Msk
#define GPIO_LCKR_LCK9_Pos             (9U)
#define GPIO_LCKR_LCK9_Msk             (0x1UL << GPIO_LCKR_LCK9_Pos)           /*!< 0x00000200 */
#define GPIO_LCKR_LCK9                 GPIO_LCKR_LCK9_Msk
#define GPIO_LCKR_LCK10_Pos            (10U)
#define GPIO_LCKR_LCK10_Msk            (0x1UL << GPIO_LCKR_LCK10_Pos)          /*!< 0x00000400 */
#define GPIO_LCKR_LCK10                GPIO_LCKR_LCK10_Msk
#define GPIO_LCKR_LCK11_Pos            (11U)
#define GPIO_LCKR_LCK11_Msk            (0x1UL << GPIO_LCKR_LCK11_Pos)          /*!< 0x00000800 */
#define GPIO_LCKR_LCK11                GPIO_LCKR_LCK11_Msk
#define GPIO_LCKR_LCK12_Pos            (12U)
#define GPIO_LCKR_LCK12_Msk            (0x1UL << GPIO_LCKR_LCK12_Pos)          /*!< 0x00001000 */
#define GPIO_LCKR_LCK12                GPIO_LCKR_LCK12_Msk
#define GPIO_LCKR_LCK13_Pos            (13U)
#define GPIO_LCKR_LCK13_Msk            (0x1UL << GPIO_LCKR_LCK13_Pos)          /*!< 0x00002000 */
#define GPIO_LCKR_LCK13                GPIO_LCKR_LCK13_Msk
#define GPIO_LCKR_LCK14_Pos            (14U)
#define GPIO_LCKR_LCK14_Msk            (0x1UL << GPIO_LCKR_LCK14_Pos)          /*!< 0x00004000 */
#define GPIO_LCKR_LCK14                GPIO_LCKR_LCK14_Msk
#define GPIO_LCKR_LCK15_Pos            (15U)
#define GPIO_LCKR_LCK15_Msk            (0x1UL << GPIO_LCKR_LCK15_Pos)          /*!< 0x00008000 */
#define GPIO_LCKR_LCK15                GPIO_LCKR_LCK15_Msk
#define GPIO_LCKR_LCKK_Pos             (16U)
#define GPIO_LCKR_LCKK_Msk             (0x1UL << GPIO_LCKR_LCKK_Pos)           /*!< 0x00010000 */
#define GPIO_LCKR_LCKK                 GPIO_LCKR_LCKK_Msk

/****************** Bit definition for GPIO_AFRL register *********************/
#define GPIO_AFRL_AFSEL0_Pos           (0U)
#define GPIO_AFRL_AFSEL0_Msk           (0xFUL << GPIO_AFRL_AFSEL0_Pos)         /*!< 0x0000000F */
#define GPIO_AFRL_AFSEL0               GPIO_AFRL_AFSEL0_Msk
#define GPIO_AFRL_AFSEL0_0             (0x1U << GPIO_AFRL_AFSEL0_Pos)          /*!< 0x00000001 */
#define GPIO_AFRL_AFSEL0_1             (0x2U << GPIO_AFRL_AFSEL0_Pos)          /*!< 0x00000002 */
#define GPIO_AFRL_AFSEL0_2             (0x4U << GPIO_AFRL_AFSEL0_Pos)          /*!< 0x00000004 */
#define GPIO_AFRL_AFSEL0_3             (0x8U << GPIO_AFRL_AFSEL0_Pos)          /*!< 0x00000008 */
#define GPIO_AFRL_AFSEL1_Pos           (4U)
#define GPIO_AFRL_AFSEL1_Msk           (0xFUL << GPIO_AFRL_AFSEL1_Pos)         /*!< 0x000000F0 */
#define GPIO_AFRL_AFSEL1               GPIO_AFRL_AFSEL1_Msk
#define GPIO_AFRL_AFSEL1_0             (0x1U << GPIO_AFRL_AFSEL1_Pos)          /*!< 0x00000010 */
#define GPIO_AFRL_AFSEL1_1             (0x2U << GPIO_AFRL_AFSEL1_Pos)          /*!< 0x00000020 */
#define GPIO_AFRL_AFSEL1_2             (0x4U << GPIO_AFRL_AFSEL1_Pos)          /*!< 0x00000040 */
#define GPIO_AFRL_AFSEL1_3             (0x8U << GPIO_AFRL_AFSEL1_Pos)          /*!< 0x00000080 */
#define GPIO_AFRL_AFSEL2_Pos           (8U)
#define GPIO_AFRL_AFSEL2_Msk           (0xFUL << GPIO_AFRL_AFSEL2_Pos)         /*!< 0x00000F00 */
#define GPIO_AFRL_AFSEL2               GPIO_AFRL_AFSEL2_Msk
#define GPIO_AFRL_AFSEL2_0             (0x1U << GPIO_AFRL_AFSEL2_Pos)          /*!< 0x00000100 */
#define GPIO_AFRL_AFSEL2_1             (0x2U << GPIO_AFRL_AFSEL2_Pos)          /*!< 0x00000200 */
#define GPIO_AFRL_AFSEL2_2             (0x4U << GPIO_AFRL_AFSEL2_Pos)          /*!< 0x00000400 */
#define GPIO_AFRL_AFSEL2_3             (0x8U << GPIO_AFRL_AFSEL2_Pos)          /*!< 0x00000800 */
#define GPIO_AFRL_AFSEL3_Pos           (12U)
#define GPIO_AFRL_AFSEL3_Msk           (0xFUL << GPIO_AFRL_AFSEL3_Pos)         /*!< 0x0000F000 */
#define GPIO_AFRL_AFSEL3               GPIO_AFRL_AFSEL3_Msk
#define GPIO_AFRL_AFSEL3_0             (0x1U << GPIO_AFRL_AFSEL3_Pos)          /*!< 0x00001000 */
#define GPIO_AFRL_AFSEL3_1             (0x2U << GPIO_AFRL_AFSEL3_Pos)          /*!< 0x00002000 */
#define GPIO_AFRL_AFSEL3_2             (0x4U << GPIO_AFRL_AFSEL3_Pos)          /*!< 0x00004000 */
#define GPIO_AFRL_AFSEL3_3             (0x8U << GPIO_AFRL_AFSEL3_Pos)          /*!< 0x00008000 */
#define GPIO_AFRL_AFSEL4_Pos           (16U)
#define GPIO_AFRL_AFSEL4_Msk           (0xFUL << GPIO_AFRL_AFSEL4_Pos)         /*!< 0x000F0000 */
#define GPIO_AFRL_AFSEL4               GPIO_AFRL_AFSEL4_Msk
#define GPIO_AFRL_AFSEL4_0             (0x1U << GPIO_AFRL_AFSEL4_Pos)          /*!< 0x00010000 */
#define GPIO_AFRL_AFSEL4_1             (0x2U << GPIO_AFRL_AFSEL4_Pos)          /*!< 0x00020000 */
#define GPIO_AFRL_AFSEL4_2             (0x4U << GPIO_AFRL_AFSEL4_Pos)          /*!< 0x00040000 */
#define GPIO_AFRL_AFSEL4_3             (0x8U << GPIO_AFRL_AFSEL4_Pos)          /*!< 0x00080000 */
#define GPIO_AFRL_AFSEL5_Pos           (20U)
#define GPIO_AFRL_AFSEL5_Msk           (0xFUL << GPIO_AFRL_AFSEL5_Pos)         /*!< 0x00F00000 */
#define GPIO_AFRL_AFSEL5               GPIO_AFRL_AFSEL5_Msk
#define GPIO_AFRL_AFSEL5_0             (0x1U << GPIO_AFRL_AFSEL5_Pos)          /*!< 0x00100000 */
#define GPIO_AFRL_AFSEL5_1             (0x2U << GPIO_AFRL_AFSEL5_Pos)          /*!< 0x00200000 */
#define GPIO_AFRL_AFSEL5_2             (0x4U << GPIO_AFRL_AFSEL5_Pos)          /*!< 0x00400000 */
#define GPIO_AFRL_AFSEL5_3             (0x8U << GPIO_AFRL_AFSEL5_Pos)          /*!< 0x00800000 */
#define GPIO_AFRL_AFSEL6_Pos           (24U)
#define GPIO_AFRL_AFSEL6_Msk           (0xFUL << GPIO_AFRL_AFSEL6_Pos)         /*!< 0x0F000000 */
#define GPIO_AFRL_AFSEL6               GPIO_AFRL_AFSEL6_Msk
#define GPIO_AFRL_AFSEL6_0             (0x1U << GPIO_AFRL_AFSEL6_Pos)          /*!< 0x01000000 */
#define GPIO_AFRL_AFSEL6_1             (0x2U << GPIO_AFRL_AFSEL6_Pos)          /*!< 0x02000000 */
#define GPIO_AFRL_AFSEL6_2             (0x4U << GPIO_AFRL_AFSEL6_Pos)          /*!< 0x04000000 */
#define GPIO_AFRL_AFSEL6_3             (0x8U << GPIO_AFRL_AFSEL6_Pos)          /*!< 0x08000000 */
#define GPIO_AFRL_AFSEL7_Pos           (28U)
#define GPIO_AFRL_AFSEL7_Msk           (0xFUL << GPIO_AFRL_AFSEL7_Pos)         /*!< 0xF0000000 */
#define GPIO_AFRL_AFSEL7               GPIO_AFRL_AFSEL7_Msk
#define GPIO_AFRL_AFSEL7_0             (0x1U << GPIO_AFRL_AFSEL7_Pos)          /*!< 0x10000000 */
#define GPIO_AFRL_AFSEL7_1             (0x2U << GPIO_AFRL_AFSEL7_Pos)          /*!< 0x20000000 */
#define GPIO_AFRL_AFSEL7_2             (0x4U << GPIO_AFRL_AFSEL7_Pos)          /*!< 0x40000000 */
#define GPIO_AFRL_AFSEL7_3             (0x8U << GPIO_AFRL_AFSEL7_Pos)          /*!< 0x80000000 */

/****************** Bit definition for GPIO_AFRH register *********************/
#define GPIO_AFRH_AFSEL8_Pos           (0U)
#define GPIO_AFRH_AFSEL8_Msk           (0xFUL << GPIO_AFRH_AFSEL8_Pos)         /*!< 0x0000000F */
#define GPIO_AFRH_AFSEL8               GPIO_AFRH_AFSEL8_Msk
#define GPIO_AFRH_AFSEL8_0             (0x1U << GPIO_AFRH_AFSEL8_Pos)          /*!< 0x00000001 */
#define GPIO_AFRH_AFSEL8_1             (0x2U << GPIO_AFRH_AFSEL8_Pos)          /*!< 0x00000002 */
#define GPIO_AFRH_AFSEL8_2             (0x4U << GPIO_AFRH_AFSEL8_Pos)          /*!< 0x00000004 */
#define GPIO_AFRH_AFSEL8_3             (0x8U << GPIO_AFRH_AFSEL8_Pos)          /*!< 0x00000008 */
#define GPIO_AFRH_AFSEL9_Pos           (4U)
#define GPIO_AFRH_AFSEL9_Msk           (0xFUL << GPIO_AFRH_AFSEL9_Pos)         /*!< 0x000000F0 */
#define GPIO_AFRH_AFSEL9               GPIO_AFRH_AFSEL9_Msk
#define GPIO_AFRH_AFSEL9_0             (0x1U << GPIO_AFRH_AFSEL9_Pos)          /*!< 0x00000010 */
#define GPIO_AFRH_AFSEL9_1             (0x2U << GPIO_AFRH_AFSEL9_Pos)          /*!< 0x00000020 */
#define GPIO_AFRH_AFSEL9_2             (0x4U << GPIO_AFRH_AFSEL9_Pos)          /*!< 0x00000040 */
#define GPIO_AFRH_AFSEL9_3             (0x8U << GPIO_AFRH_AFSEL9_Pos)          /*!< 0x00000080 */
#define GPIO_AFRH_AFSEL10_Pos          (8U)
#define GPIO_AFRH_AFSEL10_Msk          (0xFUL << GPIO_AFRH_AFSEL10_Pos)        /*!< 0x00000F00 */
#define GPIO_AFRH_AFSEL10              GPIO_AFRH_AFSEL10_Msk
#define GPIO_AFRH_AFSEL10_0            (0x1U << GPIO_AFRH_AFSEL10_Pos)         /*!< 0x00000100 */
#define GPIO_AFRH_AFSEL10_1            (0x2U << GPIO_AFRH_AFSEL10_Pos)         /*!< 0x00000200 */
#define GPIO_AFRH_AFSEL10_2            (0x4U << GPIO_AFRH_AFSEL10_Pos)         /*!< 0x00000400 */
#define GPIO_AFRH_AFSEL10_3            (0x8U << GPIO_AFRH_AFSEL10_Pos)         /*!< 0x00000800 */
#define GPIO_AFRH_AFSEL11_Pos          (12U)
#define GPIO_AFRH_AFSEL11_Msk          (0xFUL << GPIO_AFRH_AFSEL11_Pos)        /*!< 0x0000F000 */
#define GPIO_AFRH_AFSEL11              GPIO_AFRH_AFSEL11_Msk
#define GPIO_AFRH_AFSEL11_0            (0x1U << GPIO_AFRH_AFSEL11_Pos)         /*!< 0x00001000 */
#define GPIO_AFRH_AFSEL11_1            (0x2U << GPIO_AFRH_AFSEL11_Pos)         /*!< 0x00002000 */
#define GPIO_AFRH_AFSEL11_2            (0x4U << GPIO_AFRH_AFSEL11_Pos)         /*!< 0x00004000 */
#define GPIO_AFRH_AFSEL11_3            (0x8U << GPIO_AFRH_AFSEL11_Pos)         /*!< 0x00008000 */
#define GPIO_AFRH_AFSEL12_Pos          (16U)
#define GPIO_AFRH_AFSEL12_Msk          (0xFUL << GPIO_AFRH_AFSEL12_Pos)        /*!< 0x000F0000 */
#define GPIO_AFRH_AFSEL12              GPIO_AFRH_AFSEL12_Msk
#define GPIO_AFRH_AFSEL12_0            (0x1U << GPIO_AFRH_AFSEL12_Pos)         /*!< 0x00010000 */
#define GPIO_AFRH_AFSEL12_1            (0x2U << GPIO_AFRH_AFSEL12_Pos)         /*!< 0x00020000 */
#define GPIO_AFRH_AFSEL12_2            (0x4U << GPIO_AFRH_AFSEL12_Pos)         /*!< 0x00040000 */
#define GPIO_AFRH_AFSEL12_3            (0x8U << GPIO_AFRH_AFSEL12_Pos)         /*!< 0x00080000 */
#define GPIO_AFRH_AFSEL13_Pos          (20U)
#define GPIO_AFRH_AFSEL13_Msk          (0xFUL << GPIO_AFRH_AFSEL13_Pos)        /*!< 0x00F00000 */
#define GPIO_AFRH_AFSEL13              GPIO_AFRH_AFSEL13_Msk
#define GPIO_AFRH_AFSEL13_0            (0x1U << GPIO_AFRH_AFSEL13_Pos)         /*!< 0x00100000 */
#define GPIO_AFRH_AFSEL13_1            (0x2U << GPIO_AFRH_AFSEL13_Pos)         /*!< 0x00200000 */
#define GPIO_AFRH_AFSEL13_2            (0x4U << GPIO_AFRH_AFSEL13_Pos)         /*!< 0x00400000 */
#define GPIO_AFRH_AFSEL13_3            (0x8U << GPIO_AFRH_AFSEL13_Pos)         /*!< 0x00800000 */
#define GPIO_AFRH_AFSEL14_Pos          (24U)
#define GPIO_AFRH_AFSEL14_Msk          (0xFUL << GPIO_AFRH_AFSEL14_Pos)        /*!< 0x0F000000 */
#define GPIO_AFRH_AFSEL14              GPIO_AFRH_AFSEL14_Msk
#define GPIO_AFRH_AFSEL14_0            (0x1U << GPIO_AFRH_AFSEL14_Pos)         /*!< 0x01000000 */
#define GPIO_AFRH_AFSEL14_1            (0x2U << GPIO_AFRH_AFSEL14_Pos)         /*!< 0x02000000 */
#define GPIO_AFRH_AFSEL14_2            (0x4U << GPIO_AFRH_AFSEL14_Pos)         /*!< 0x04000000 */
#define GPIO_AFRH_AFSEL14_3            (0x8U << GPIO_AFRH_AFSEL14_Pos)         /*!< 0x08000000 */
#define GPIO_AFRH_AFSEL15_Pos          (28U)
#define GPIO_AFRH_AFSEL15_Msk          (0xFUL << GPIO_AFRH_AFSEL15_Pos)        /*!< 0xF0000000 */
#define GPIO_AFRH_AFSEL15              GPIO_AFRH_AFSEL15_Msk
#define GPIO_AFRH_AFSEL15_0            (0x1U << GPIO_AFRH_AFSEL15_Pos)         /*!< 0x10000000 */
#define GPIO_AFRH_AFSEL15_1            (0x2U << GPIO_AFRH_AFSEL15_Pos)         /*!< 0x20000000 */
#define GPIO_AFRH_AFSEL15_2            (0x4U << GPIO_AFRH_AFSEL15_Pos)         /*!< 0x40000000 */
#define GPIO_AFRH_AFSEL15_3            (0x8U << GPIO_AFRH_AFSEL15_Pos)         /*!< 0x80000000 */

/******************  Bits definition for GPIO_BRR register  ******************/
#define GPIO_BRR_BR0_Pos               (0U)
#define GPIO_BRR_BR0_Msk               (0x1UL << GPIO_BRR_BR0_Pos)             /*!< 0x00000001 */
#define GPIO_BRR_BR0                   GPIO_BRR_BR0_Msk
#define GPIO_BRR_BR1_Pos               (1U)
#define GPIO_BRR_BR1_Msk               (0x1UL << GPIO_BRR_BR1_Pos)             /*!< 0x00000002 */
#define GPIO_BRR_BR1                   GPIO_BRR_BR1_Msk
#define GPIO_BRR_BR2_Pos               (2U)
#define GPIO_BRR_BR2_Msk               (0x1UL << GPIO_BRR_BR2_Pos)             /*!< 0x00000004 */
#define GPIO_BRR_BR2                   GPIO_BRR_BR2_Msk
#define GPIO_BRR_BR3_Pos               (3U)
#define GPIO_BRR_BR3_Msk               (0x1UL << GPIO_BRR_BR3_Pos)             /*!< 0x00000008 */
#define GPIO_BRR_BR3                   GPIO_BRR_BR3_Msk
#define GPIO_BRR_BR4_Pos               (4U)
#define GPIO_BRR_BR4_Msk               (0x1UL << GPIO_BRR_BR4_Pos)             /*!< 0x00000010 */
#define GPIO_BRR_BR4                   GPIO_BRR_BR4_Msk
#define GPIO_BRR_BR5_Pos               (5U)
#define GPIO_BRR_BR5_Msk               (0x1UL << GPIO_BRR_BR5_Pos)             /*!< 0x00000020 */
#define GPIO_BRR_BR5                   GPIO_BRR_BR5_Msk
#define GPIO_BRR_BR6_Pos               (6U)
#define GPIO_BRR_BR6_Msk               (0x1UL << GPIO_BRR_BR6_Pos)             /*!< 0x00000040 */
#define GPIO_BRR_BR6                   GPIO_BRR_BR6_Msk
#define GPIO_BRR_BR7_Pos               (7U)
#define GPIO_BRR_BR7_Msk               (0x1UL << GPIO_BRR_BR7_Pos)             /*!< 0x00000080 */
#define GPIO_BRR_BR7                   GPIO_BRR_BR7_Msk
#define GPIO_BRR_BR8_Pos               (8U)
#define GPIO_BRR_BR8_Msk               (0x1UL << GPIO_BRR_BR8_Pos)             /*!< 0x00000100 */
#define GPIO_BRR_BR8                   GPIO_BRR_BR8_Msk
#define GPIO_BRR_BR9_Pos               (9U)
#define GPIO_BRR_BR9_Msk               (0x1UL << GPIO_BRR_BR9_Pos)             /*!< 0x00000200 */
#define GPIO_BRR_BR9                   GPIO_BRR_BR9_Msk
#define GPIO_BRR_BR10_Pos              (10U)
#define GPIO_BRR_BR10_Msk              (0x1UL << GPIO_BRR_BR10_Pos)            /*!< 0x00000400 */
#define GPIO_BRR_BR10                  GPIO_BRR_BR10_Msk
#define GPIO_BRR_BR11_Pos              (11U)
#define GPIO_BRR_BR11_Msk              (0x1UL << GPIO_BRR_BR11_Pos)            /*!< 0x00000800 */
#define GPIO_BRR_BR11                  GPIO_BRR_BR11_Msk
#define GPIO_BRR_BR12_Pos              (12U)
#define GPIO_BRR_BR12_Msk              (0x1UL << GPIO_BRR_BR12_Pos)            /*!< 0x00001000 */
#define GPIO_BRR_BR12                  GPIO_BRR_BR12_Msk
#define GPIO_BRR_BR13_Pos              (13U)
#define GPIO_BRR_BR13_Msk              (0x1UL << GPIO_BRR_BR13_Pos)            /*!< 0x00002000 */
#define GPIO_BRR_BR13                  GPIO_BRR_BR13_Msk
#define GPIO_BRR_BR14_Pos              (14U)
#define GPIO_BRR_BR14_Msk              (0x1UL << GPIO_BRR_BR14_Pos)            /*!< 0x00004000 */
#define GPIO_BRR_BR14                  GPIO_BRR_BR14_Msk
#define GPIO_BRR_BR15_Pos              (15U)
#define GPIO_BRR_BR15_Msk              (0x1UL << GPIO_BRR_BR15_Pos)            /*!< 0x00008000 */
#define GPIO_BRR_BR15                  GPIO_BRR_BR15_Msk

/******************************************************************************/
/*                                                                            */
/*                        HSEM HW Semaphore                                   */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for HSEM_R register  ********************/
#define HSEM_R_PROCID_Pos        (0U)
#define HSEM_R_PROCID_Msk        (0xFFUL << HSEM_R_PROCID_Pos)                 /*!< 0x000000FF */
#define HSEM_R_PROCID            HSEM_R_PROCID_Msk                             /*!<Semaphore ProcessID */
#define HSEM_R_COREID_Pos        (8U)
#define HSEM_R_COREID_Msk        (0xFUL << HSEM_R_COREID_Pos)                  /*!< 0x00000F00 */
#define HSEM_R_COREID            HSEM_R_COREID_Msk                             /*!<Semaphore CoreID. */
#define HSEM_R_LOCK_Pos          (31U)
#define HSEM_R_LOCK_Msk          (0x1UL << HSEM_R_LOCK_Pos)                    /*!< 0x80000000 */
#define HSEM_R_LOCK              HSEM_R_LOCK_Msk                               /*!<Lock indication. */

/********************  Bit definition for HSEM_RLR register  ******************/
#define HSEM_RLR_PROCID_Pos      (0U)
#define HSEM_RLR_PROCID_Msk      (0xFFUL << HSEM_RLR_PROCID_Pos)               /*!< 0x000000FF */
#define HSEM_RLR_PROCID          HSEM_RLR_PROCID_Msk                           /*!<Semaphore ProcessID */
#define HSEM_RLR_COREID_Pos      (8U)
#define HSEM_RLR_COREID_Msk      (0xFUL << HSEM_RLR_COREID_Pos)                /*!< 0x00000F00 */
#define HSEM_RLR_COREID          HSEM_RLR_COREID_Msk                           /*!<Semaphore CoreID. */
#define HSEM_RLR_LOCK_Pos        (31U)
#define HSEM_RLR_LOCK_Msk        (0x1UL << HSEM_RLR_LOCK_Pos)                  /*!< 0x80000000 */
#define HSEM_RLR_LOCK            HSEM_RLR_LOCK_Msk                             /*!<Lock indication. */

/********************  Bit definition for HSEM_C1IER register  ****************/
#define HSEM_C1IER_ISE0_Pos      (0U)
#define HSEM_C1IER_ISE0_Msk      (0x1UL << HSEM_C1IER_ISE0_Pos)                /*!< 0x00000001 */
#define HSEM_C1IER_ISE0          HSEM_C1IER_ISE0_Msk                           /*!<semaphore 0 CPU1 interrupt enable bit.  */
#define HSEM_C1IER_ISE1_Pos      (1U)
#define HSEM_C1IER_ISE1_Msk      (0x1UL << HSEM_C1IER_ISE1_Pos)                /*!< 0x00000002 */
#define HSEM_C1IER_ISE1          HSEM_C1IER_ISE1_Msk                           /*!<semaphore 1 CPU1 interrupt enable bit.  */
#define HSEM_C1IER_ISE2_Pos      (2U)
#define HSEM_C1IER_ISE2_Msk      (0x1UL << HSEM_C1IER_ISE2_Pos)                /*!< 0x00000004 */
#define HSEM_C1IER_ISE2          HSEM_C1IER_ISE2_Msk                           /*!<semaphore 2 CPU1 interrupt enable bit.  */
#define HSEM_C1IER_ISE3_Pos      (3U)
#define HSEM_C1IER_ISE3_Msk      (0x1UL << HSEM_C1IER_ISE3_Pos)                /*!< 0x00000008 */
#define HSEM_C1IER_ISE3          HSEM_C1IER_ISE3_Msk                           /*!<semaphore 3 CPU1 interrupt enable bit.  */
#define HSEM_C1IER_ISE4_Pos      (4U)
#define HSEM_C1IER_ISE4_Msk      (0x1UL << HSEM_C1IER_ISE4_Pos)                /*!< 0x00000010 */
#define HSEM_C1IER_ISE4          HSEM_C1IER_ISE4_Msk                           /*!<semaphore 4 CPU1 interrupt enable bit.  */
#define HSEM_C1IER_ISE5_Pos      (5U)
#define HSEM_C1IER_ISE5_Msk      (0x1UL << HSEM_C1IER_ISE5_Pos)                /*!< 0x00000020 */
#define HSEM_C1IER_ISE5          HSEM_C1IER_ISE5_Msk                           /*!<semaphore 5 CPU1 interrupt enable bit.  */
#define HSEM_C1IER_ISE6_Pos      (6U)
#define HSEM_C1IER_ISE6_Msk      (0x1UL << HSEM_C1IER_ISE6_Pos)                /*!< 0x00000040 */
#define HSEM_C1IER_ISE6          HSEM_C1IER_ISE6_Msk                           /*!<semaphore 6 CPU1 interrupt enable bit.  */
#define HSEM_C1IER_ISE7_Pos      (7U)
#define HSEM_C1IER_ISE7_Msk      (0x1UL << HSEM_C1IER_ISE7_Pos)                /*!< 0x00000080 */
#define HSEM_C1IER_ISE7          HSEM_C1IER_ISE7_Msk                           /*!<semaphore 7 CPU1 interrupt enable bit.  */
#define HSEM_C1IER_ISE8_Pos      (8U)
#define HSEM_C1IER_ISE8_Msk      (0x1UL << HSEM_C1IER_ISE8_Pos)                /*!< 0x00000100 */
#define HSEM_C1IER_ISE8          HSEM_C1IER_ISE8_Msk                           /*!<semaphore 8 CPU1 interrupt enable bit.  */
#define HSEM_C1IER_ISE9_Pos      (9U)
#define HSEM_C1IER_ISE9_Msk      (0x1UL << HSEM_C1IER_ISE9_Pos)                /*!< 0x00000200 */
#define HSEM_C1IER_ISE9          HSEM_C1IER_ISE9_Msk                           /*!<semaphore 9 CPU1 interrupt enable bit.  */
#define HSEM_C1IER_ISE10_Pos     (10U)
#define HSEM_C1IER_ISE10_Msk     (0x1UL << HSEM_C1IER_ISE10_Pos)               /*!< 0x00000400 */
#define HSEM_C1IER_ISE10         HSEM_C1IER_ISE10_Msk                          /*!<semaphore 10 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE11_Pos     (11U)
#define HSEM_C1IER_ISE11_Msk     (0x1UL << HSEM_C1IER_ISE11_Pos)               /*!< 0x00000800 */
#define HSEM_C1IER_ISE11         HSEM_C1IER_ISE11_Msk                          /*!<semaphore 11 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE12_Pos     (12U)
#define HSEM_C1IER_ISE12_Msk     (0x1UL << HSEM_C1IER_ISE12_Pos)               /*!< 0x00001000 */
#define HSEM_C1IER_ISE12         HSEM_C1IER_ISE12_Msk                          /*!<semaphore 12 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE13_Pos     (13U)
#define HSEM_C1IER_ISE13_Msk     (0x1UL << HSEM_C1IER_ISE13_Pos)               /*!< 0x00002000 */
#define HSEM_C1IER_ISE13         HSEM_C1IER_ISE13_Msk                          /*!<semaphore 13 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE14_Pos     (14U)
#define HSEM_C1IER_ISE14_Msk     (0x1UL << HSEM_C1IER_ISE14_Pos)               /*!< 0x00004000 */
#define HSEM_C1IER_ISE14         HSEM_C1IER_ISE14_Msk                          /*!<semaphore 14 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE15_Pos     (15U)
#define HSEM_C1IER_ISE15_Msk     (0x1UL << HSEM_C1IER_ISE15_Pos)               /*!< 0x00008000 */
#define HSEM_C1IER_ISE15         HSEM_C1IER_ISE15_Msk                          /*!<semaphore 15 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE16_Pos     (16U)
#define HSEM_C1IER_ISE16_Msk     (0x1UL << HSEM_C1IER_ISE16_Pos)               /*!< 0x00010000 */
#define HSEM_C1IER_ISE16         HSEM_C1IER_ISE16_Msk                          /*!<semaphore 16 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE17_Pos     (17U)
#define HSEM_C1IER_ISE17_Msk     (0x1UL << HSEM_C1IER_ISE17_Pos)               /*!< 0x00020000 */
#define HSEM_C1IER_ISE17         HSEM_C1IER_ISE17_Msk                          /*!<semaphore 17 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE18_Pos     (18U)
#define HSEM_C1IER_ISE18_Msk     (0x1UL << HSEM_C1IER_ISE18_Pos)               /*!< 0x00040000 */
#define HSEM_C1IER_ISE18         HSEM_C1IER_ISE18_Msk                          /*!<semaphore 18 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE19_Pos     (19U)
#define HSEM_C1IER_ISE19_Msk     (0x1UL << HSEM_C1IER_ISE19_Pos)               /*!< 0x00080000 */
#define HSEM_C1IER_ISE19         HSEM_C1IER_ISE19_Msk                          /*!<semaphore 19 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE20_Pos     (20U)
#define HSEM_C1IER_ISE20_Msk     (0x1UL << HSEM_C1IER_ISE20_Pos)               /*!< 0x00100000 */
#define HSEM_C1IER_ISE20         HSEM_C1IER_ISE20_Msk                          /*!<semaphore 20 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE21_Pos     (21U)
#define HSEM_C1IER_ISE21_Msk     (0x1UL << HSEM_C1IER_ISE21_Pos)               /*!< 0x00200000 */
#define HSEM_C1IER_ISE21         HSEM_C1IER_ISE21_Msk                          /*!<semaphore 21 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE22_Pos     (22U)
#define HSEM_C1IER_ISE22_Msk     (0x1UL << HSEM_C1IER_ISE22_Pos)               /*!< 0x00400000 */
#define HSEM_C1IER_ISE22         HSEM_C1IER_ISE22_Msk                          /*!<semaphore 22 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE23_Pos     (23U)
#define HSEM_C1IER_ISE23_Msk     (0x1UL << HSEM_C1IER_ISE23_Pos)               /*!< 0x00800000 */
#define HSEM_C1IER_ISE23         HSEM_C1IER_ISE23_Msk                          /*!<semaphore 23 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE24_Pos     (24U)
#define HSEM_C1IER_ISE24_Msk     (0x1UL << HSEM_C1IER_ISE24_Pos)               /*!< 0x01000000 */
#define HSEM_C1IER_ISE24         HSEM_C1IER_ISE24_Msk                          /*!<semaphore 24 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE25_Pos     (25U)
#define HSEM_C1IER_ISE25_Msk     (0x1UL << HSEM_C1IER_ISE25_Pos)               /*!< 0x02000000 */
#define HSEM_C1IER_ISE25         HSEM_C1IER_ISE25_Msk                          /*!<semaphore 25 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE26_Pos     (26U)
#define HSEM_C1IER_ISE26_Msk     (0x1UL << HSEM_C1IER_ISE26_Pos)               /*!< 0x04000000 */
#define HSEM_C1IER_ISE26         HSEM_C1IER_ISE26_Msk                          /*!<semaphore 26 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE27_Pos     (27U)
#define HSEM_C1IER_ISE27_Msk     (0x1UL << HSEM_C1IER_ISE27_Pos)               /*!< 0x08000000 */
#define HSEM_C1IER_ISE27         HSEM_C1IER_ISE27_Msk                          /*!<semaphore 27 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE28_Pos     (28U)
#define HSEM_C1IER_ISE28_Msk     (0x1UL << HSEM_C1IER_ISE28_Pos)               /*!< 0x10000000 */
#define HSEM_C1IER_ISE28         HSEM_C1IER_ISE28_Msk                          /*!<semaphore 28 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE29_Pos     (29U)
#define HSEM_C1IER_ISE29_Msk     (0x1UL << HSEM_C1IER_ISE29_Pos)               /*!< 0x20000000 */
#define HSEM_C1IER_ISE29         HSEM_C1IER_ISE29_Msk                          /*!<semaphore 29 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE30_Pos     (30U)
#define HSEM_C1IER_ISE30_Msk     (0x1UL << HSEM_C1IER_ISE30_Pos)               /*!< 0x40000000 */
#define HSEM_C1IER_ISE30         HSEM_C1IER_ISE30_Msk                          /*!<semaphore 30 CPU1 interrupt enable bit. */
#define HSEM_C1IER_ISE31_Pos     (31U)
#define HSEM_C1IER_ISE31_Msk     (0x1UL << HSEM_C1IER_ISE31_Pos)               /*!< 0x80000000 */
#define HSEM_C1IER_ISE31         HSEM_C1IER_ISE31_Msk                          /*!<semaphore 31 CPU1 interrupt enable bit. */

/********************  Bit definition for HSEM_C1ICR register  *****************/
#define HSEM_C1ICR_ISC0_Pos      (0U)
#define HSEM_C1ICR_ISC0_Msk      (0x1UL << HSEM_C1ICR_ISC0_Pos)                /*!< 0x00000001 */
#define HSEM_C1ICR_ISC0          HSEM_C1ICR_ISC0_Msk                           /*!<semaphore 0 CPU1 interrupt clear bit.  */
#define HSEM_C1ICR_ISC1_Pos      (1U)
#define HSEM_C1ICR_ISC1_Msk      (0x1UL << HSEM_C1ICR_ISC1_Pos)                /*!< 0x00000002 */
#define HSEM_C1ICR_ISC1          HSEM_C1ICR_ISC1_Msk                           /*!<semaphore 1 CPU1 interrupt clear bit.  */
#define HSEM_C1ICR_ISC2_Pos      (2U)
#define HSEM_C1ICR_ISC2_Msk      (0x1UL << HSEM_C1ICR_ISC2_Pos)                /*!< 0x00000004 */
#define HSEM_C1ICR_ISC2          HSEM_C1ICR_ISC2_Msk                           /*!<semaphore 2 CPU1 interrupt clear bit.  */
#define HSEM_C1ICR_ISC3_Pos      (3U)
#define HSEM_C1ICR_ISC3_Msk      (0x1UL << HSEM_C1ICR_ISC3_Pos)                /*!< 0x00000008 */
#define HSEM_C1ICR_ISC3          HSEM_C1ICR_ISC3_Msk                           /*!<semaphore 3 CPU1 interrupt clear bit.  */
#define HSEM_C1ICR_ISC4_Pos      (4U)
#define HSEM_C1ICR_ISC4_Msk      (0x1UL << HSEM_C1ICR_ISC4_Pos)                /*!< 0x00000010 */
#define HSEM_C1ICR_ISC4          HSEM_C1ICR_ISC4_Msk                           /*!<semaphore 4 CPU1 interrupt clear bit.  */
#define HSEM_C1ICR_ISC5_Pos      (5U)
#define HSEM_C1ICR_ISC5_Msk      (0x1UL << HSEM_C1ICR_ISC5_Pos)                /*!< 0x00000020 */
#define HSEM_C1ICR_ISC5          HSEM_C1ICR_ISC5_Msk                           /*!<semaphore 5 CPU1 interrupt clear bit.  */
#define HSEM_C1ICR_ISC6_Pos      (6U)
#define HSEM_C1ICR_ISC6_Msk      (0x1UL << HSEM_C1ICR_ISC6_Pos)                /*!< 0x00000040 */
#define HSEM_C1ICR_ISC6          HSEM_C1ICR_ISC6_Msk                           /*!<semaphore 6 CPU1 interrupt clear bit.  */
#define HSEM_C1ICR_ISC7_Pos      (7U)
#define HSEM_C1ICR_ISC7_Msk      (0x1UL << HSEM_C1ICR_ISC7_Pos)                /*!< 0x00000080 */
#define HSEM_C1ICR_ISC7          HSEM_C1ICR_ISC7_Msk                           /*!<semaphore 7 CPU1 interrupt clear bit.  */
#define HSEM_C1ICR_ISC8_Pos      (8U)
#define HSEM_C1ICR_ISC8_Msk      (0x1UL << HSEM_C1ICR_ISC8_Pos)                /*!< 0x00000100 */
#define HSEM_C1ICR_ISC8          HSEM_C1ICR_ISC8_Msk                           /*!<semaphore 8 CPU1 interrupt clear bit.  */
#define HSEM_C1ICR_ISC9_Pos      (9U)
#define HSEM_C1ICR_ISC9_Msk      (0x1UL << HSEM_C1ICR_ISC9_Pos)                /*!< 0x00000200 */
#define HSEM_C1ICR_ISC9          HSEM_C1ICR_ISC9_Msk                           /*!<semaphore 9 CPU1 interrupt clear bit.  */
#define HSEM_C1ICR_ISC10_Pos     (10U)
#define HSEM_C1ICR_ISC10_Msk     (0x1UL << HSEM_C1ICR_ISC10_Pos)               /*!< 0x00000400 */
#define HSEM_C1ICR_ISC10         HSEM_C1ICR_ISC10_Msk                          /*!<semaphore 10 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC11_Pos     (11U)
#define HSEM_C1ICR_ISC11_Msk     (0x1UL << HSEM_C1ICR_ISC11_Pos)               /*!< 0x00000800 */
#define HSEM_C1ICR_ISC11         HSEM_C1ICR_ISC11_Msk                          /*!<semaphore 11 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC12_Pos     (12U)
#define HSEM_C1ICR_ISC12_Msk     (0x1UL << HSEM_C1ICR_ISC12_Pos)               /*!< 0x00001000 */
#define HSEM_C1ICR_ISC12         HSEM_C1ICR_ISC12_Msk                          /*!<semaphore 12 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC13_Pos     (13U)
#define HSEM_C1ICR_ISC13_Msk     (0x1UL << HSEM_C1ICR_ISC13_Pos)               /*!< 0x00002000 */
#define HSEM_C1ICR_ISC13         HSEM_C1ICR_ISC13_Msk                          /*!<semaphore 13 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC14_Pos     (14U)
#define HSEM_C1ICR_ISC14_Msk     (0x1UL << HSEM_C1ICR_ISC14_Pos)               /*!< 0x00004000 */
#define HSEM_C1ICR_ISC14         HSEM_C1ICR_ISC14_Msk                          /*!<semaphore 14 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC15_Pos     (15U)
#define HSEM_C1ICR_ISC15_Msk     (0x1UL << HSEM_C1ICR_ISC15_Pos)               /*!< 0x00008000 */
#define HSEM_C1ICR_ISC15         HSEM_C1ICR_ISC15_Msk                          /*!<semaphore 15 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC16_Pos     (16U)
#define HSEM_C1ICR_ISC16_Msk     (0x1UL << HSEM_C1ICR_ISC16_Pos)               /*!< 0x00010000 */
#define HSEM_C1ICR_ISC16         HSEM_C1ICR_ISC16_Msk                          /*!<semaphore 16 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC17_Pos     (17U)
#define HSEM_C1ICR_ISC17_Msk     (0x1UL << HSEM_C1ICR_ISC17_Pos)               /*!< 0x00020000 */
#define HSEM_C1ICR_ISC17         HSEM_C1ICR_ISC17_Msk                          /*!<semaphore 17 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC18_Pos     (18U)
#define HSEM_C1ICR_ISC18_Msk     (0x1UL << HSEM_C1ICR_ISC18_Pos)               /*!< 0x00040000 */
#define HSEM_C1ICR_ISC18         HSEM_C1ICR_ISC18_Msk                          /*!<semaphore 18 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC19_Pos     (19U)
#define HSEM_C1ICR_ISC19_Msk     (0x1UL << HSEM_C1ICR_ISC19_Pos)               /*!< 0x00080000 */
#define HSEM_C1ICR_ISC19         HSEM_C1ICR_ISC19_Msk                          /*!<semaphore 19 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC20_Pos     (20U)
#define HSEM_C1ICR_ISC20_Msk     (0x1UL << HSEM_C1ICR_ISC20_Pos)               /*!< 0x00100000 */
#define HSEM_C1ICR_ISC20         HSEM_C1ICR_ISC20_Msk                          /*!<semaphore 20 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC21_Pos     (21U)
#define HSEM_C1ICR_ISC21_Msk     (0x1UL << HSEM_C1ICR_ISC21_Pos)               /*!< 0x00200000 */
#define HSEM_C1ICR_ISC21         HSEM_C1ICR_ISC21_Msk                          /*!<semaphore 21 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC22_Pos     (22U)
#define HSEM_C1ICR_ISC22_Msk     (0x1UL << HSEM_C1ICR_ISC22_Pos)               /*!< 0x00400000 */
#define HSEM_C1ICR_ISC22         HSEM_C1ICR_ISC22_Msk                          /*!<semaphore 22 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC23_Pos     (23U)
#define HSEM_C1ICR_ISC23_Msk     (0x1UL << HSEM_C1ICR_ISC23_Pos)               /*!< 0x00800000 */
#define HSEM_C1ICR_ISC23         HSEM_C1ICR_ISC23_Msk                          /*!<semaphore 23 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC24_Pos     (24U)
#define HSEM_C1ICR_ISC24_Msk     (0x1UL << HSEM_C1ICR_ISC24_Pos)               /*!< 0x01000000 */
#define HSEM_C1ICR_ISC24         HSEM_C1ICR_ISC24_Msk                          /*!<semaphore 24 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC25_Pos     (25U)
#define HSEM_C1ICR_ISC25_Msk     (0x1UL << HSEM_C1ICR_ISC25_Pos)               /*!< 0x02000000 */
#define HSEM_C1ICR_ISC25         HSEM_C1ICR_ISC25_Msk                          /*!<semaphore 25 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC26_Pos     (26U)
#define HSEM_C1ICR_ISC26_Msk     (0x1UL << HSEM_C1ICR_ISC26_Pos)               /*!< 0x04000000 */
#define HSEM_C1ICR_ISC26         HSEM_C1ICR_ISC26_Msk                          /*!<semaphore 26 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC27_Pos     (27U)
#define HSEM_C1ICR_ISC27_Msk     (0x1UL << HSEM_C1ICR_ISC27_Pos)               /*!< 0x08000000 */
#define HSEM_C1ICR_ISC27         HSEM_C1ICR_ISC27_Msk                          /*!<semaphore 27 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC28_Pos     (28U)
#define HSEM_C1ICR_ISC28_Msk     (0x1UL << HSEM_C1ICR_ISC28_Pos)               /*!< 0x10000000 */
#define HSEM_C1ICR_ISC28         HSEM_C1ICR_ISC28_Msk                          /*!<semaphore 28 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC29_Pos     (29U)
#define HSEM_C1ICR_ISC29_Msk     (0x1UL << HSEM_C1ICR_ISC29_Pos)               /*!< 0x20000000 */
#define HSEM_C1ICR_ISC29         HSEM_C1ICR_ISC29_Msk                          /*!<semaphore 29 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC30_Pos     (30U)
#define HSEM_C1ICR_ISC30_Msk     (0x1UL << HSEM_C1ICR_ISC30_Pos)               /*!< 0x40000000 */
#define HSEM_C1ICR_ISC30         HSEM_C1ICR_ISC30_Msk                          /*!<semaphore 30 CPU1 interrupt clear bit. */
#define HSEM_C1ICR_ISC31_Pos     (31U)
#define HSEM_C1ICR_ISC31_Msk     (0x1UL << HSEM_C1ICR_ISC31_Pos)               /*!< 0x80000000 */
#define HSEM_C1ICR_ISC31         HSEM_C1ICR_ISC31_Msk                          /*!<semaphore 31 CPU1 interrupt clear bit. */

/********************  Bit definition for HSEM_C1ISR register  *****************/
#define HSEM_C1ISR_ISF0_Pos      (0U)
#define HSEM_C1ISR_ISF0_Msk      (0x1UL << HSEM_C1ISR_ISF0_Pos)                /*!< 0x00000001 */
#define HSEM_C1ISR_ISF0          HSEM_C1ISR_ISF0_Msk                           /*!<semaphore 0 CPU1 interrupt status bit.  */
#define HSEM_C1ISR_ISF1_Pos      (1U)
#define HSEM_C1ISR_ISF1_Msk      (0x1UL << HSEM_C1ISR_ISF1_Pos)                /*!< 0x00000002 */
#define HSEM_C1ISR_ISF1          HSEM_C1ISR_ISF1_Msk                           /*!<semaphore 1 CPU1 interrupt status bit.  */
#define HSEM_C1ISR_ISF2_Pos      (2U)
#define HSEM_C1ISR_ISF2_Msk      (0x1UL << HSEM_C1ISR_ISF2_Pos)                /*!< 0x00000004 */
#define HSEM_C1ISR_ISF2          HSEM_C1ISR_ISF2_Msk                           /*!<semaphore 2 CPU1 interrupt status bit.  */
#define HSEM_C1ISR_ISF3_Pos      (3U)
#define HSEM_C1ISR_ISF3_Msk      (0x1UL << HSEM_C1ISR_ISF3_Pos)                /*!< 0x00000008 */
#define HSEM_C1ISR_ISF3          HSEM_C1ISR_ISF3_Msk                           /*!<semaphore 3 CPU1 interrupt status bit.  */
#define HSEM_C1ISR_ISF4_Pos      (4U)
#define HSEM_C1ISR_ISF4_Msk      (0x1UL << HSEM_C1ISR_ISF4_Pos)                /*!< 0x00000010 */
#define HSEM_C1ISR_ISF4          HSEM_C1ISR_ISF4_Msk                           /*!<semaphore 4 CPU1 interrupt status bit.  */
#define HSEM_C1ISR_ISF5_Pos      (5U)
#define HSEM_C1ISR_ISF5_Msk      (0x1UL << HSEM_C1ISR_ISF5_Pos)                /*!< 0x00000020 */
#define HSEM_C1ISR_ISF5          HSEM_C1ISR_ISF5_Msk                           /*!<semaphore 5 CPU1 interrupt status bit.  */
#define HSEM_C1ISR_ISF6_Pos      (6U)
#define HSEM_C1ISR_ISF6_Msk      (0x1UL << HSEM_C1ISR_ISF6_Pos)                /*!< 0x00000040 */
#define HSEM_C1ISR_ISF6          HSEM_C1ISR_ISF6_Msk                           /*!<semaphore 6 CPU1 interrupt status bit.  */
#define HSEM_C1ISR_ISF7_Pos      (7U)
#define HSEM_C1ISR_ISF7_Msk      (0x1UL << HSEM_C1ISR_ISF7_Pos)                /*!< 0x00000080 */
#define HSEM_C1ISR_ISF7          HSEM_C1ISR_ISF7_Msk                           /*!<semaphore 7 CPU1 interrupt status bit.  */
#define HSEM_C1ISR_ISF8_Pos      (8U)
#define HSEM_C1ISR_ISF8_Msk      (0x1UL << HSEM_C1ISR_ISF8_Pos)                /*!< 0x00000100 */
#define HSEM_C1ISR_ISF8          HSEM_C1ISR_ISF8_Msk                           /*!<semaphore 8 CPU1 interrupt status bit.  */
#define HSEM_C1ISR_ISF9_Pos      (9U)
#define HSEM_C1ISR_ISF9_Msk      (0x1UL << HSEM_C1ISR_ISF9_Pos)                /*!< 0x00000200 */
#define HSEM_C1ISR_ISF9          HSEM_C1ISR_ISF9_Msk                           /*!<semaphore 9 CPU1 interrupt status bit.  */
#define HSEM_C1ISR_ISF10_Pos     (10U)
#define HSEM_C1ISR_ISF10_Msk     (0x1UL << HSEM_C1ISR_ISF10_Pos)               /*!< 0x00000400 */
#define HSEM_C1ISR_ISF10         HSEM_C1ISR_ISF10_Msk                          /*!<semaphore 10 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF11_Pos     (11U)
#define HSEM_C1ISR_ISF11_Msk     (0x1UL << HSEM_C1ISR_ISF11_Pos)               /*!< 0x00000800 */
#define HSEM_C1ISR_ISF11         HSEM_C1ISR_ISF11_Msk                          /*!<semaphore 11 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF12_Pos     (12U)
#define HSEM_C1ISR_ISF12_Msk     (0x1UL << HSEM_C1ISR_ISF12_Pos)               /*!< 0x00001000 */
#define HSEM_C1ISR_ISF12         HSEM_C1ISR_ISF12_Msk                          /*!<semaphore 12 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF13_Pos     (13U)
#define HSEM_C1ISR_ISF13_Msk     (0x1UL << HSEM_C1ISR_ISF13_Pos)               /*!< 0x00002000 */
#define HSEM_C1ISR_ISF13         HSEM_C1ISR_ISF13_Msk                          /*!<semaphore 13 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF14_Pos     (14U)
#define HSEM_C1ISR_ISF14_Msk     (0x1UL << HSEM_C1ISR_ISF14_Pos)               /*!< 0x00004000 */
#define HSEM_C1ISR_ISF14         HSEM_C1ISR_ISF14_Msk                          /*!<semaphore 14 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF15_Pos     (15U)
#define HSEM_C1ISR_ISF15_Msk     (0x1UL << HSEM_C1ISR_ISF15_Pos)               /*!< 0x00008000 */
#define HSEM_C1ISR_ISF15         HSEM_C1ISR_ISF15_Msk                          /*!<semaphore 15 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF16_Pos     (16U)
#define HSEM_C1ISR_ISF16_Msk     (0x1UL << HSEM_C1ISR_ISF16_Pos)               /*!< 0x00010000 */
#define HSEM_C1ISR_ISF16         HSEM_C1ISR_ISF16_Msk                          /*!<semaphore 16 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF17_Pos     (17U)
#define HSEM_C1ISR_ISF17_Msk     (0x1UL << HSEM_C1ISR_ISF17_Pos)               /*!< 0x00020000 */
#define HSEM_C1ISR_ISF17         HSEM_C1ISR_ISF17_Msk                          /*!<semaphore 17 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF18_Pos     (18U)
#define HSEM_C1ISR_ISF18_Msk     (0x1UL << HSEM_C1ISR_ISF18_Pos)               /*!< 0x00040000 */
#define HSEM_C1ISR_ISF18         HSEM_C1ISR_ISF18_Msk                          /*!<semaphore 18 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF19_Pos     (19U)
#define HSEM_C1ISR_ISF19_Msk     (0x1UL << HSEM_C1ISR_ISF19_Pos)               /*!< 0x00080000 */
#define HSEM_C1ISR_ISF19         HSEM_C1ISR_ISF19_Msk                          /*!<semaphore 19 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF20_Pos     (20U)
#define HSEM_C1ISR_ISF20_Msk     (0x1UL << HSEM_C1ISR_ISF20_Pos)               /*!< 0x00100000 */
#define HSEM_C1ISR_ISF20         HSEM_C1ISR_ISF20_Msk                          /*!<semaphore 20 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF21_Pos     (21U)
#define HSEM_C1ISR_ISF21_Msk     (0x1UL << HSEM_C1ISR_ISF21_Pos)               /*!< 0x00200000 */
#define HSEM_C1ISR_ISF21         HSEM_C1ISR_ISF21_Msk                          /*!<semaphore 21 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF22_Pos     (22U)
#define HSEM_C1ISR_ISF22_Msk     (0x1UL << HSEM_C1ISR_ISF22_Pos)               /*!< 0x00400000 */
#define HSEM_C1ISR_ISF22         HSEM_C1ISR_ISF22_Msk                          /*!<semaphore 22 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF23_Pos     (23U)
#define HSEM_C1ISR_ISF23_Msk     (0x1UL << HSEM_C1ISR_ISF23_Pos)               /*!< 0x00800000 */
#define HSEM_C1ISR_ISF23         HSEM_C1ISR_ISF23_Msk                          /*!<semaphore 23 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF24_Pos     (24U)
#define HSEM_C1ISR_ISF24_Msk     (0x1UL << HSEM_C1ISR_ISF24_Pos)               /*!< 0x01000000 */
#define HSEM_C1ISR_ISF24         HSEM_C1ISR_ISF24_Msk                          /*!<semaphore 24 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF25_Pos     (25U)
#define HSEM_C1ISR_ISF25_Msk     (0x1UL << HSEM_C1ISR_ISF25_Pos)               /*!< 0x02000000 */
#define HSEM_C1ISR_ISF25         HSEM_C1ISR_ISF25_Msk                          /*!<semaphore 25 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF26_Pos     (26U)
#define HSEM_C1ISR_ISF26_Msk     (0x1UL << HSEM_C1ISR_ISF26_Pos)               /*!< 0x04000000 */
#define HSEM_C1ISR_ISF26         HSEM_C1ISR_ISF26_Msk                          /*!<semaphore 26 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF27_Pos     (27U)
#define HSEM_C1ISR_ISF27_Msk     (0x1UL << HSEM_C1ISR_ISF27_Pos)               /*!< 0x08000000 */
#define HSEM_C1ISR_ISF27         HSEM_C1ISR_ISF27_Msk                          /*!<semaphore 27 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF28_Pos     (28U)
#define HSEM_C1ISR_ISF28_Msk     (0x1UL << HSEM_C1ISR_ISF28_Pos)               /*!< 0x10000000 */
#define HSEM_C1ISR_ISF28         HSEM_C1ISR_ISF28_Msk                          /*!<semaphore 28 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF29_Pos     (29U)
#define HSEM_C1ISR_ISF29_Msk     (0x1UL << HSEM_C1ISR_ISF29_Pos)               /*!< 0x20000000 */
#define HSEM_C1ISR_ISF29         HSEM_C1ISR_ISF29_Msk                          /*!<semaphore 29 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF30_Pos     (30U)
#define HSEM_C1ISR_ISF30_Msk     (0x1UL << HSEM_C1ISR_ISF30_Pos)               /*!< 0x40000000 */
#define HSEM_C1ISR_ISF30         HSEM_C1ISR_ISF30_Msk                          /*!<semaphore 30 CPU1 interrupt status bit. */
#define HSEM_C1ISR_ISF31_Pos     (31U)
#define HSEM_C1ISR_ISF31_Msk     (0x1UL << HSEM_C1ISR_ISF31_Pos)               /*!< 0x80000000 */
#define HSEM_C1ISR_ISF31         HSEM_C1ISR_ISF31_Msk                          /*!<semaphore 31 CPU1 interrupt status bit. */

/********************  Bit definition for HSEM_C1MISR register  *****************/
#define HSEM_C1MISR_MISF0_Pos     (0U)
#define HSEM_C1MISR_MISF0_Msk     (0x1UL << HSEM_C1MISR_MISF0_Pos)               /*!< 0x00000001 */
#define HSEM_C1MISR_MISF0         HSEM_C1MISR_MISF0_Msk                          /*!<semaphore 0 CPU1 interrupt masked status bit.  */
#define HSEM_C1MISR_MISF1_Pos     (1U)
#define HSEM_C1MISR_MISF1_Msk     (0x1UL << HSEM_C1MISR_MISF1_Pos)               /*!< 0x00000002 */
#define HSEM_C1MISR_MISF1         HSEM_C1MISR_MISF1_Msk                          /*!<semaphore 1 CPU1 interrupt masked status bit.  */
#define HSEM_C1MISR_MISF2_Pos     (2U)
#define HSEM_C1MISR_MISF2_Msk     (0x1UL << HSEM_C1MISR_MISF2_Pos)               /*!< 0x00000004 */
#define HSEM_C1MISR_MISF2         HSEM_C1MISR_MISF2_Msk                          /*!<semaphore 2 CPU1 interrupt masked status bit.  */
#define HSEM_C1MISR_MISF3_Pos     (3U)
#define HSEM_C1MISR_MISF3_Msk     (0x1UL << HSEM_C1MISR_MISF3_Pos)               /*!< 0x00000008 */
#define HSEM_C1MISR_MISF3         HSEM_C1MISR_MISF3_Msk                          /*!<semaphore 3 CPU1 interrupt masked status bit.  */
#define HSEM_C1MISR_MISF4_Pos     (4U)
#define HSEM_C1MISR_MISF4_Msk     (0x1UL << HSEM_C1MISR_MISF4_Pos)               /*!< 0x00000010 */
#define HSEM_C1MISR_MISF4         HSEM_C1MISR_MISF4_Msk                          /*!<semaphore 4 CPU1 interrupt masked status bit.  */
#define HSEM_C1MISR_MISF5_Pos     (5U)
#define HSEM_C1MISR_MISF5_Msk     (0x1UL << HSEM_C1MISR_MISF5_Pos)               /*!< 0x00000020 */
#define HSEM_C1MISR_MISF5         HSEM_C1MISR_MISF5_Msk                          /*!<semaphore 5 CPU1 interrupt masked status bit.  */
#define HSEM_C1MISR_MISF6_Pos     (6U)
#define HSEM_C1MISR_MISF6_Msk     (0x1UL << HSEM_C1MISR_MISF6_Pos)               /*!< 0x00000040 */
#define HSEM_C1MISR_MISF6         HSEM_C1MISR_MISF6_Msk                          /*!<semaphore 6 CPU1 interrupt masked status bit.  */
#define HSEM_C1MISR_MISF7_Pos     (7U)
#define HSEM_C1MISR_MISF7_Msk     (0x1UL << HSEM_C1MISR_MISF7_Pos)               /*!< 0x00000080 */
#define HSEM_C1MISR_MISF7         HSEM_C1MISR_MISF7_Msk                          /*!<semaphore 7 CPU1 interrupt masked status bit.  */
#define HSEM_C1MISR_MISF8_Pos     (8U)
#define HSEM_C1MISR_MISF8_Msk     (0x1UL << HSEM_C1MISR_MISF8_Pos)               /*!< 0x00000100 */
#define HSEM_C1MISR_MISF8         HSEM_C1MISR_MISF8_Msk                          /*!<semaphore 8 CPU1 interrupt masked status bit.  */
#define HSEM_C1MISR_MISF9_Pos     (9U)
#define HSEM_C1MISR_MISF9_Msk     (0x1UL << HSEM_C1MISR_MISF9_Pos)               /*!< 0x00000200 */
#define HSEM_C1MISR_MISF9         HSEM_C1MISR_MISF9_Msk                          /*!<semaphore 9 CPU1 interrupt masked status bit.  */
#define HSEM_C1MISR_MISF10_Pos    (10U)
#define HSEM_C1MISR_MISF10_Msk    (0x1UL << HSEM_C1MISR_MISF10_Pos)              /*!< 0x00000400 */
#define HSEM_C1MISR_MISF10        HSEM_C1MISR_MISF10_Msk                         /*!<semaphore 10 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF11_Pos    (11U)
#define HSEM_C1MISR_MISF11_Msk    (0x1UL << HSEM_C1MISR_MISF11_Pos)              /*!< 0x00000800 */
#define HSEM_C1MISR_MISF11        HSEM_C1MISR_MISF11_Msk                         /*!<semaphore 11 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF12_Pos    (12U)
#define HSEM_C1MISR_MISF12_Msk    (0x1UL << HSEM_C1MISR_MISF12_Pos)              /*!< 0x00001000 */
#define HSEM_C1MISR_MISF12        HSEM_C1MISR_MISF12_Msk                         /*!<semaphore 12 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF13_Pos    (13U)
#define HSEM_C1MISR_MISF13_Msk    (0x1UL << HSEM_C1MISR_MISF13_Pos)              /*!< 0x00002000 */
#define HSEM_C1MISR_MISF13        HSEM_C1MISR_MISF13_Msk                         /*!<semaphore 13 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF14_Pos    (14U)
#define HSEM_C1MISR_MISF14_Msk    (0x1UL << HSEM_C1MISR_MISF14_Pos)              /*!< 0x00004000 */
#define HSEM_C1MISR_MISF14        HSEM_C1MISR_MISF14_Msk                         /*!<semaphore 14 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF15_Pos    (15U)
#define HSEM_C1MISR_MISF15_Msk    (0x1UL << HSEM_C1MISR_MISF15_Pos)              /*!< 0x00008000 */
#define HSEM_C1MISR_MISF15        HSEM_C1MISR_MISF15_Msk                         /*!<semaphore 15 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF16_Pos    (16U)
#define HSEM_C1MISR_MISF16_Msk    (0x1UL << HSEM_C1MISR_MISF16_Pos)              /*!< 0x00010000 */
#define HSEM_C1MISR_MISF16        HSEM_C1MISR_MISF16_Msk                         /*!<semaphore 16 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF17_Pos    (17U)
#define HSEM_C1MISR_MISF17_Msk    (0x1UL << HSEM_C1MISR_MISF17_Pos)              /*!< 0x00020000 */
#define HSEM_C1MISR_MISF17        HSEM_C1MISR_MISF17_Msk                         /*!<semaphore 17 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF18_Pos    (18U)
#define HSEM_C1MISR_MISF18_Msk    (0x1UL << HSEM_C1MISR_MISF18_Pos)              /*!< 0x00040000 */
#define HSEM_C1MISR_MISF18        HSEM_C1MISR_MISF18_Msk                         /*!<semaphore 18 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF19_Pos    (19U)
#define HSEM_C1MISR_MISF19_Msk    (0x1UL << HSEM_C1MISR_MISF19_Pos)              /*!< 0x00080000 */
#define HSEM_C1MISR_MISF19        HSEM_C1MISR_MISF19_Msk                         /*!<semaphore 19 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF20_Pos    (20U)
#define HSEM_C1MISR_MISF20_Msk    (0x1UL << HSEM_C1MISR_MISF20_Pos)              /*!< 0x00100000 */
#define HSEM_C1MISR_MISF20        HSEM_C1MISR_MISF20_Msk                         /*!<semaphore 20 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF21_Pos    (21U)
#define HSEM_C1MISR_MISF21_Msk    (0x1UL << HSEM_C1MISR_MISF21_Pos)              /*!< 0x00200000 */
#define HSEM_C1MISR_MISF21        HSEM_C1MISR_MISF21_Msk                         /*!<semaphore 21 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF22_Pos    (22U)
#define HSEM_C1MISR_MISF22_Msk    (0x1UL << HSEM_C1MISR_MISF22_Pos)              /*!< 0x00400000 */
#define HSEM_C1MISR_MISF22        HSEM_C1MISR_MISF22_Msk                         /*!<semaphore 22 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF23_Pos    (23U)
#define HSEM_C1MISR_MISF23_Msk    (0x1UL << HSEM_C1MISR_MISF23_Pos)              /*!< 0x00800000 */
#define HSEM_C1MISR_MISF23        HSEM_C1MISR_MISF23_Msk                         /*!<semaphore 23 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF24_Pos    (24U)
#define HSEM_C1MISR_MISF24_Msk    (0x1UL << HSEM_C1MISR_MISF24_Pos)              /*!< 0x01000000 */
#define HSEM_C1MISR_MISF24        HSEM_C1MISR_MISF24_Msk                         /*!<semaphore 24 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF25_Pos    (25U)
#define HSEM_C1MISR_MISF25_Msk    (0x1UL << HSEM_C1MISR_MISF25_Pos)              /*!< 0x02000000 */
#define HSEM_C1MISR_MISF25        HSEM_C1MISR_MISF25_Msk                         /*!<semaphore 25 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF26_Pos    (26U)
#define HSEM_C1MISR_MISF26_Msk    (0x1UL << HSEM_C1MISR_MISF26_Pos)              /*!< 0x04000000 */
#define HSEM_C1MISR_MISF26        HSEM_C1MISR_MISF26_Msk                         /*!<semaphore 26 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF27_Pos    (27U)
#define HSEM_C1MISR_MISF27_Msk    (0x1UL << HSEM_C1MISR_MISF27_Pos)              /*!< 0x08000000 */
#define HSEM_C1MISR_MISF27        HSEM_C1MISR_MISF27_Msk                         /*!<semaphore 27 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF28_Pos    (28U)
#define HSEM_C1MISR_MISF28_Msk    (0x1UL << HSEM_C1MISR_MISF28_Pos)              /*!< 0x10000000 */
#define HSEM_C1MISR_MISF28        HSEM_C1MISR_MISF28_Msk                         /*!<semaphore 28 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF29_Pos    (29U)
#define HSEM_C1MISR_MISF29_Msk    (0x1UL << HSEM_C1MISR_MISF29_Pos)              /*!< 0x20000000 */
#define HSEM_C1MISR_MISF29        HSEM_C1MISR_MISF29_Msk                         /*!<semaphore 29 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF30_Pos    (30U)
#define HSEM_C1MISR_MISF30_Msk    (0x1UL << HSEM_C1MISR_MISF30_Pos)              /*!< 0x40000000 */
#define HSEM_C1MISR_MISF30        HSEM_C1MISR_MISF30_Msk                         /*!<semaphore 30 CPU1 interrupt masked status bit. */
#define HSEM_C1MISR_MISF31_Pos    (31U)
#define HSEM_C1MISR_MISF31_Msk    (0x1UL << HSEM_C1MISR_MISF31_Pos)              /*!< 0x80000000 */
#define HSEM_C1MISR_MISF31        HSEM_C1MISR_MISF31_Msk                         /*!<semaphore 31 CPU1 interrupt masked status bit. */

/********************  Bit definition for HSEM_C2IER register  *****************/
#define HSEM_C2IER_ISE0_Pos      (0U)
#define HSEM_C2IER_ISE0_Msk      (0x1UL << HSEM_C2IER_ISE0_Pos)                /*!< 0x00000001 */
#define HSEM_C2IER_ISE0          HSEM_C2IER_ISE0_Msk                           /*!<semaphore 0 CPU2 interrupt enable bit.  */
#define HSEM_C2IER_ISE1_Pos      (1U)
#define HSEM_C2IER_ISE1_Msk      (0x1UL << HSEM_C2IER_ISE1_Pos)                /*!< 0x00000002 */
#define HSEM_C2IER_ISE1          HSEM_C2IER_ISE1_Msk                           /*!<semaphore 1 CPU2 interrupt enable bit.  */
#define HSEM_C2IER_ISE2_Pos      (2U)
#define HSEM_C2IER_ISE2_Msk      (0x1UL << HSEM_C2IER_ISE2_Pos)                /*!< 0x00000004 */
#define HSEM_C2IER_ISE2          HSEM_C2IER_ISE2_Msk                           /*!<semaphore 2 CPU2 interrupt enable bit.  */
#define HSEM_C2IER_ISE3_Pos      (3U)
#define HSEM_C2IER_ISE3_Msk      (0x1UL << HSEM_C2IER_ISE3_Pos)                /*!< 0x00000008 */
#define HSEM_C2IER_ISE3          HSEM_C2IER_ISE3_Msk                           /*!<semaphore 3 CPU2 interrupt enable bit.  */
#define HSEM_C2IER_ISE4_Pos      (4U)
#define HSEM_C2IER_ISE4_Msk      (0x1UL << HSEM_C2IER_ISE4_Pos)                /*!< 0x00000010 */
#define HSEM_C2IER_ISE4          HSEM_C2IER_ISE4_Msk                           /*!<semaphore 4 CPU2 interrupt enable bit.  */
#define HSEM_C2IER_ISE5_Pos      (5U)
#define HSEM_C2IER_ISE5_Msk      (0x1UL << HSEM_C2IER_ISE5_Pos)                /*!< 0x00000020 */
#define HSEM_C2IER_ISE5          HSEM_C2IER_ISE5_Msk                           /*!<semaphore 5 CPU2 interrupt enable bit.  */
#define HSEM_C2IER_ISE6_Pos      (6U)
#define HSEM_C2IER_ISE6_Msk      (0x1UL << HSEM_C2IER_ISE6_Pos)                /*!< 0x00000040 */
#define HSEM_C2IER_ISE6          HSEM_C2IER_ISE6_Msk                           /*!<semaphore 6 CPU2 interrupt enable bit.  */
#define HSEM_C2IER_ISE7_Pos      (7U)
#define HSEM_C2IER_ISE7_Msk      (0x1UL << HSEM_C2IER_ISE7_Pos)                /*!< 0x00000080 */
#define HSEM_C2IER_ISE7          HSEM_C2IER_ISE7_Msk                           /*!<semaphore 7 CPU2 interrupt enable bit.  */
#define HSEM_C2IER_ISE8_Pos      (8U)
#define HSEM_C2IER_ISE8_Msk      (0x1UL << HSEM_C2IER_ISE8_Pos)                /*!< 0x00000100 */
#define HSEM_C2IER_ISE8          HSEM_C2IER_ISE8_Msk                           /*!<semaphore 8 CPU2 interrupt enable bit.  */
#define HSEM_C2IER_ISE9_Pos      (9U)
#define HSEM_C2IER_ISE9_Msk      (0x1UL << HSEM_C2IER_ISE9_Pos)                /*!< 0x00000200 */
#define HSEM_C2IER_ISE9          HSEM_C2IER_ISE9_Msk                           /*!<semaphore 9 CPU2 interrupt enable bit.  */
#define HSEM_C2IER_ISE10_Pos     (10U)
#define HSEM_C2IER_ISE10_Msk     (0x1UL << HSEM_C2IER_ISE10_Pos)               /*!< 0x00000400 */
#define HSEM_C2IER_ISE10         HSEM_C2IER_ISE10_Msk                          /*!<semaphore 10 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE11_Pos     (11U)
#define HSEM_C2IER_ISE11_Msk     (0x1UL << HSEM_C2IER_ISE11_Pos)               /*!< 0x00000800 */
#define HSEM_C2IER_ISE11         HSEM_C2IER_ISE11_Msk                          /*!<semaphore 11 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE12_Pos     (12U)
#define HSEM_C2IER_ISE12_Msk     (0x1UL << HSEM_C2IER_ISE12_Pos)               /*!< 0x00001000 */
#define HSEM_C2IER_ISE12         HSEM_C2IER_ISE12_Msk                          /*!<semaphore 12 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE13_Pos     (13U)
#define HSEM_C2IER_ISE13_Msk     (0x1UL << HSEM_C2IER_ISE13_Pos)               /*!< 0x00002000 */
#define HSEM_C2IER_ISE13         HSEM_C2IER_ISE13_Msk                          /*!<semaphore 13 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE14_Pos     (14U)
#define HSEM_C2IER_ISE14_Msk     (0x1UL << HSEM_C2IER_ISE14_Pos)               /*!< 0x00004000 */
#define HSEM_C2IER_ISE14         HSEM_C2IER_ISE14_Msk                          /*!<semaphore 14 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE15_Pos     (15U)
#define HSEM_C2IER_ISE15_Msk     (0x1UL << HSEM_C2IER_ISE15_Pos)               /*!< 0x00008000 */
#define HSEM_C2IER_ISE15         HSEM_C2IER_ISE15_Msk                          /*!<semaphore 15 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE16_Pos     (16U)
#define HSEM_C2IER_ISE16_Msk     (0x1UL << HSEM_C2IER_ISE16_Pos)               /*!< 0x00010000 */
#define HSEM_C2IER_ISE16         HSEM_C2IER_ISE16_Msk                          /*!<semaphore 16 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE17_Pos     (17U)
#define HSEM_C2IER_ISE17_Msk     (0x1UL << HSEM_C2IER_ISE17_Pos)               /*!< 0x00020000 */
#define HSEM_C2IER_ISE17         HSEM_C2IER_ISE17_Msk                          /*!<semaphore 17 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE18_Pos     (18U)
#define HSEM_C2IER_ISE18_Msk     (0x1UL << HSEM_C2IER_ISE18_Pos)               /*!< 0x00040000 */
#define HSEM_C2IER_ISE18         HSEM_C2IER_ISE18_Msk                          /*!<semaphore 18 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE19_Pos     (19U)
#define HSEM_C2IER_ISE19_Msk     (0x1UL << HSEM_C2IER_ISE19_Pos)               /*!< 0x00080000 */
#define HSEM_C2IER_ISE19         HSEM_C2IER_ISE19_Msk                          /*!<semaphore 19 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE20_Pos     (20U)
#define HSEM_C2IER_ISE20_Msk     (0x1UL << HSEM_C2IER_ISE20_Pos)               /*!< 0x00100000 */
#define HSEM_C2IER_ISE20         HSEM_C2IER_ISE20_Msk                          /*!<semaphore 20 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE21_Pos     (21U)
#define HSEM_C2IER_ISE21_Msk     (0x1UL << HSEM_C2IER_ISE21_Pos)               /*!< 0x00200000 */
#define HSEM_C2IER_ISE21         HSEM_C2IER_ISE21_Msk                          /*!<semaphore 21 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE22_Pos     (22U)
#define HSEM_C2IER_ISE22_Msk     (0x1UL << HSEM_C2IER_ISE22_Pos)               /*!< 0x00400000 */
#define HSEM_C2IER_ISE22         HSEM_C2IER_ISE22_Msk                          /*!<semaphore 22 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE23_Pos     (23U)
#define HSEM_C2IER_ISE23_Msk     (0x1UL << HSEM_C2IER_ISE23_Pos)               /*!< 0x00800000 */
#define HSEM_C2IER_ISE23         HSEM_C2IER_ISE23_Msk                          /*!<semaphore 23 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE24_Pos     (24U)
#define HSEM_C2IER_ISE24_Msk     (0x1UL << HSEM_C2IER_ISE24_Pos)               /*!< 0x01000000 */
#define HSEM_C2IER_ISE24         HSEM_C2IER_ISE24_Msk                          /*!<semaphore 24 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE25_Pos     (25U)
#define HSEM_C2IER_ISE25_Msk     (0x1UL << HSEM_C2IER_ISE25_Pos)               /*!< 0x02000000 */
#define HSEM_C2IER_ISE25         HSEM_C2IER_ISE25_Msk                          /*!<semaphore 25 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE26_Pos     (26U)
#define HSEM_C2IER_ISE26_Msk     (0x1UL << HSEM_C2IER_ISE26_Pos)               /*!< 0x04000000 */
#define HSEM_C2IER_ISE26         HSEM_C2IER_ISE26_Msk                          /*!<semaphore 26 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE27_Pos     (27U)
#define HSEM_C2IER_ISE27_Msk     (0x1UL << HSEM_C2IER_ISE27_Pos)               /*!< 0x08000000 */
#define HSEM_C2IER_ISE27         HSEM_C2IER_ISE27_Msk                          /*!<semaphore 27 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE28_Pos     (28U)
#define HSEM_C2IER_ISE28_Msk     (0x1UL << HSEM_C2IER_ISE28_Pos)               /*!< 0x10000000 */
#define HSEM_C2IER_ISE28         HSEM_C2IER_ISE28_Msk                          /*!<semaphore 28 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE29_Pos     (29U)
#define HSEM_C2IER_ISE29_Msk     (0x1UL << HSEM_C2IER_ISE29_Pos)               /*!< 0x20000000 */
#define HSEM_C2IER_ISE29         HSEM_C2IER_ISE29_Msk                          /*!<semaphore 29 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE30_Pos     (30U)
#define HSEM_C2IER_ISE30_Msk     (0x1UL << HSEM_C2IER_ISE30_Pos)               /*!< 0x40000000 */
#define HSEM_C2IER_ISE30         HSEM_C2IER_ISE30_Msk                          /*!<semaphore 30 CPU2 interrupt enable bit. */
#define HSEM_C2IER_ISE31_Pos     (31U)
#define HSEM_C2IER_ISE31_Msk     (0x1UL << HSEM_C2IER_ISE31_Pos)               /*!< 0x80000000 */
#define HSEM_C2IER_ISE31         HSEM_C2IER_ISE31_Msk                          /*!<semaphore 31 CPU2 interrupt enable bit. */

/********************  Bit definition for HSEM_C2ICR register  *****************/
#define HSEM_C2ICR_ISC0_Pos      (0U)
#define HSEM_C2ICR_ISC0_Msk      (0x1UL << HSEM_C2ICR_ISC0_Pos)                /*!< 0x00000001 */
#define HSEM_C2ICR_ISC0          HSEM_C2ICR_ISC0_Msk                           /*!<semaphore 0 CPU2 interrupt clear bit.  */
#define HSEM_C2ICR_ISC1_Pos      (1U)
#define HSEM_C2ICR_ISC1_Msk      (0x1UL << HSEM_C2ICR_ISC1_Pos)                /*!< 0x00000002 */
#define HSEM_C2ICR_ISC1          HSEM_C2ICR_ISC1_Msk                           /*!<semaphore 1 CPU2 interrupt clear bit.  */
#define HSEM_C2ICR_ISC2_Pos      (2U)
#define HSEM_C2ICR_ISC2_Msk      (0x1UL << HSEM_C2ICR_ISC2_Pos)                /*!< 0x00000004 */
#define HSEM_C2ICR_ISC2          HSEM_C2ICR_ISC2_Msk                           /*!<semaphore 2 CPU2 interrupt clear bit.  */
#define HSEM_C2ICR_ISC3_Pos      (3U)
#define HSEM_C2ICR_ISC3_Msk      (0x1UL << HSEM_C2ICR_ISC3_Pos)                /*!< 0x00000008 */
#define HSEM_C2ICR_ISC3          HSEM_C2ICR_ISC3_Msk                           /*!<semaphore 3 CPU2 interrupt clear bit.  */
#define HSEM_C2ICR_ISC4_Pos      (4U)
#define HSEM_C2ICR_ISC4_Msk      (0x1UL << HSEM_C2ICR_ISC4_Pos)                /*!< 0x00000010 */
#define HSEM_C2ICR_ISC4          HSEM_C2ICR_ISC4_Msk                           /*!<semaphore 4 CPU2 interrupt clear bit.  */
#define HSEM_C2ICR_ISC5_Pos      (5U)
#define HSEM_C2ICR_ISC5_Msk      (0x1UL << HSEM_C2ICR_ISC5_Pos)                /*!< 0x00000020 */
#define HSEM_C2ICR_ISC5          HSEM_C2ICR_ISC5_Msk                           /*!<semaphore 5 CPU2 interrupt clear bit.  */
#define HSEM_C2ICR_ISC6_Pos      (6U)
#define HSEM_C2ICR_ISC6_Msk      (0x1UL << HSEM_C2ICR_ISC6_Pos)                /*!< 0x00000040 */
#define HSEM_C2ICR_ISC6          HSEM_C2ICR_ISC6_Msk                           /*!<semaphore 6 CPU2 interrupt clear bit.  */
#define HSEM_C2ICR_ISC7_Pos      (7U)
#define HSEM_C2ICR_ISC7_Msk      (0x1UL << HSEM_C2ICR_ISC7_Pos)                /*!< 0x00000080 */
#define HSEM_C2ICR_ISC7          HSEM_C2ICR_ISC7_Msk                           /*!<semaphore 7 CPU2 interrupt clear bit.  */
#define HSEM_C2ICR_ISC8_Pos      (8U)
#define HSEM_C2ICR_ISC8_Msk      (0x1UL << HSEM_C2ICR_ISC8_Pos)                /*!< 0x00000100 */
#define HSEM_C2ICR_ISC8          HSEM_C2ICR_ISC8_Msk                           /*!<semaphore 8 CPU2 interrupt clear bit.  */
#define HSEM_C2ICR_ISC9_Pos      (9U)
#define HSEM_C2ICR_ISC9_Msk      (0x1UL << HSEM_C2ICR_ISC9_Pos)                /*!< 0x00000200 */
#define HSEM_C2ICR_ISC9          HSEM_C2ICR_ISC9_Msk                           /*!<semaphore 9 CPU2 interrupt clear bit.  */
#define HSEM_C2ICR_ISC10_Pos     (10U)
#define HSEM_C2ICR_ISC10_Msk     (0x1UL << HSEM_C2ICR_ISC10_Pos)               /*!< 0x00000400 */
#define HSEM_C2ICR_ISC10         HSEM_C2ICR_ISC10_Msk                          /*!<semaphore 10 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC11_Pos     (11U)
#define HSEM_C2ICR_ISC11_Msk     (0x1UL << HSEM_C2ICR_ISC11_Pos)               /*!< 0x00000800 */
#define HSEM_C2ICR_ISC11         HSEM_C2ICR_ISC11_Msk                          /*!<semaphore 11 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC12_Pos     (12U)
#define HSEM_C2ICR_ISC12_Msk     (0x1UL << HSEM_C2ICR_ISC12_Pos)               /*!< 0x00001000 */
#define HSEM_C2ICR_ISC12         HSEM_C2ICR_ISC12_Msk                          /*!<semaphore 12 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC13_Pos     (13U)
#define HSEM_C2ICR_ISC13_Msk     (0x1UL << HSEM_C2ICR_ISC13_Pos)               /*!< 0x00002000 */
#define HSEM_C2ICR_ISC13         HSEM_C2ICR_ISC13_Msk                          /*!<semaphore 13 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC14_Pos     (14U)
#define HSEM_C2ICR_ISC14_Msk     (0x1UL << HSEM_C2ICR_ISC14_Pos)               /*!< 0x00004000 */
#define HSEM_C2ICR_ISC14         HSEM_C2ICR_ISC14_Msk                          /*!<semaphore 14 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC15_Pos     (15U)
#define HSEM_C2ICR_ISC15_Msk     (0x1UL << HSEM_C2ICR_ISC15_Pos)               /*!< 0x00008000 */
#define HSEM_C2ICR_ISC15         HSEM_C2ICR_ISC15_Msk                          /*!<semaphore 15 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC16_Pos     (16U)
#define HSEM_C2ICR_ISC16_Msk     (0x1UL << HSEM_C2ICR_ISC16_Pos)               /*!< 0x00010000 */
#define HSEM_C2ICR_ISC16         HSEM_C2ICR_ISC16_Msk                          /*!<semaphore 16 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC17_Pos     (17U)
#define HSEM_C2ICR_ISC17_Msk     (0x1UL << HSEM_C2ICR_ISC17_Pos)               /*!< 0x00020000 */
#define HSEM_C2ICR_ISC17         HSEM_C2ICR_ISC17_Msk                          /*!<semaphore 17 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC18_Pos     (18U)
#define HSEM_C2ICR_ISC18_Msk     (0x1UL << HSEM_C2ICR_ISC18_Pos)               /*!< 0x00040000 */
#define HSEM_C2ICR_ISC18         HSEM_C2ICR_ISC18_Msk                          /*!<semaphore 18 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC19_Pos     (19U)
#define HSEM_C2ICR_ISC19_Msk     (0x1UL << HSEM_C2ICR_ISC19_Pos)               /*!< 0x00080000 */
#define HSEM_C2ICR_ISC19         HSEM_C2ICR_ISC19_Msk                          /*!<semaphore 19 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC20_Pos     (20U)
#define HSEM_C2ICR_ISC20_Msk     (0x1UL << HSEM_C2ICR_ISC20_Pos)               /*!< 0x00100000 */
#define HSEM_C2ICR_ISC20         HSEM_C2ICR_ISC20_Msk                          /*!<semaphore 20 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC21_Pos     (21U)
#define HSEM_C2ICR_ISC21_Msk     (0x1UL << HSEM_C2ICR_ISC21_Pos)               /*!< 0x00200000 */
#define HSEM_C2ICR_ISC21         HSEM_C2ICR_ISC21_Msk                          /*!<semaphore 21 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC22_Pos     (22U)
#define HSEM_C2ICR_ISC22_Msk     (0x1UL << HSEM_C2ICR_ISC22_Pos)               /*!< 0x00400000 */
#define HSEM_C2ICR_ISC22         HSEM_C2ICR_ISC22_Msk                          /*!<semaphore 22 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC23_Pos     (23U)
#define HSEM_C2ICR_ISC23_Msk     (0x1UL << HSEM_C2ICR_ISC23_Pos)               /*!< 0x00800000 */
#define HSEM_C2ICR_ISC23         HSEM_C2ICR_ISC23_Msk                          /*!<semaphore 23 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC24_Pos     (24U)
#define HSEM_C2ICR_ISC24_Msk     (0x1UL << HSEM_C2ICR_ISC24_Pos)               /*!< 0x01000000 */
#define HSEM_C2ICR_ISC24         HSEM_C2ICR_ISC24_Msk                          /*!<semaphore 24 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC25_Pos     (25U)
#define HSEM_C2ICR_ISC25_Msk     (0x1UL << HSEM_C2ICR_ISC25_Pos)               /*!< 0x02000000 */
#define HSEM_C2ICR_ISC25         HSEM_C2ICR_ISC25_Msk                          /*!<semaphore 25 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC26_Pos     (26U)
#define HSEM_C2ICR_ISC26_Msk     (0x1UL << HSEM_C2ICR_ISC26_Pos)               /*!< 0x04000000 */
#define HSEM_C2ICR_ISC26         HSEM_C2ICR_ISC26_Msk                          /*!<semaphore 26 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC27_Pos     (27U)
#define HSEM_C2ICR_ISC27_Msk     (0x1UL << HSEM_C2ICR_ISC27_Pos)               /*!< 0x08000000 */
#define HSEM_C2ICR_ISC27         HSEM_C2ICR_ISC27_Msk                          /*!<semaphore 27 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC28_Pos     (28U)
#define HSEM_C2ICR_ISC28_Msk     (0x1UL << HSEM_C2ICR_ISC28_Pos)               /*!< 0x10000000 */
#define HSEM_C2ICR_ISC28         HSEM_C2ICR_ISC28_Msk                          /*!<semaphore 28 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC29_Pos     (29U)
#define HSEM_C2ICR_ISC29_Msk     (0x1UL << HSEM_C2ICR_ISC29_Pos)               /*!< 0x20000000 */
#define HSEM_C2ICR_ISC29         HSEM_C2ICR_ISC29_Msk                          /*!<semaphore 29 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC30_Pos     (30U)
#define HSEM_C2ICR_ISC30_Msk     (0x1UL << HSEM_C2ICR_ISC30_Pos)               /*!< 0x40000000 */
#define HSEM_C2ICR_ISC30         HSEM_C2ICR_ISC30_Msk                          /*!<semaphore 30 CPU2 interrupt clear bit. */
#define HSEM_C2ICR_ISC31_Pos     (31U)
#define HSEM_C2ICR_ISC31_Msk     (0x1UL << HSEM_C2ICR_ISC31_Pos)               /*!< 0x80000000 */
#define HSEM_C2ICR_ISC31         HSEM_C2ICR_ISC31_Msk                          /*!<semaphore 31 CPU2 interrupt clear bit. */

/********************  Bit definition for HSEM_C2ISR register  *****************/
#define HSEM_C2ISR_ISF0_Pos      (0U)
#define HSEM_C2ISR_ISF0_Msk      (0x1UL << HSEM_C2ISR_ISF0_Pos)                /*!< 0x00000001 */
#define HSEM_C2ISR_ISF0          HSEM_C2ISR_ISF0_Msk                           /*!<semaphore 0 CPU2 interrupt status bit.  */
#define HSEM_C2ISR_ISF1_Pos      (1U)
#define HSEM_C2ISR_ISF1_Msk      (0x1UL << HSEM_C2ISR_ISF1_Pos)                /*!< 0x00000002 */
#define HSEM_C2ISR_ISF1          HSEM_C2ISR_ISF1_Msk                           /*!<semaphore 1 CPU2 interrupt status bit.  */
#define HSEM_C2ISR_ISF2_Pos      (2U)
#define HSEM_C2ISR_ISF2_Msk      (0x1UL << HSEM_C2ISR_ISF2_Pos)                /*!< 0x00000004 */
#define HSEM_C2ISR_ISF2          HSEM_C2ISR_ISF2_Msk                           /*!<semaphore 2 CPU2 interrupt status bit.  */
#define HSEM_C2ISR_ISF3_Pos      (3U)
#define HSEM_C2ISR_ISF3_Msk      (0x1UL << HSEM_C2ISR_ISF3_Pos)                /*!< 0x00000008 */
#define HSEM_C2ISR_ISF3          HSEM_C2ISR_ISF3_Msk                           /*!<semaphore 3 CPU2 interrupt status bit.  */
#define HSEM_C2ISR_ISF4_Pos      (4U)
#define HSEM_C2ISR_ISF4_Msk      (0x1UL << HSEM_C2ISR_ISF4_Pos)                /*!< 0x00000010 */
#define HSEM_C2ISR_ISF4          HSEM_C2ISR_ISF4_Msk                           /*!<semaphore 4 CPU2 interrupt status bit.  */
#define HSEM_C2ISR_ISF5_Pos      (5U)
#define HSEM_C2ISR_ISF5_Msk      (0x1UL << HSEM_C2ISR_ISF5_Pos)                /*!< 0x00000020 */
#define HSEM_C2ISR_ISF5          HSEM_C2ISR_ISF5_Msk                           /*!<semaphore 5 CPU2 interrupt status bit.  */
#define HSEM_C2ISR_ISF6_Pos      (6U)
#define HSEM_C2ISR_ISF6_Msk      (0x1UL << HSEM_C2ISR_ISF6_Pos)                /*!< 0x00000040 */
#define HSEM_C2ISR_ISF6          HSEM_C2ISR_ISF6_Msk                           /*!<semaphore 6 CPU2 interrupt status bit.  */
#define HSEM_C2ISR_ISF7_Pos      (7U)
#define HSEM_C2ISR_ISF7_Msk      (0x1UL << HSEM_C2ISR_ISF7_Pos)                /*!< 0x00000080 */
#define HSEM_C2ISR_ISF7          HSEM_C2ISR_ISF7_Msk                           /*!<semaphore 7 CPU2 interrupt status bit.  */
#define HSEM_C2ISR_ISF8_Pos      (8U)
#define HSEM_C2ISR_ISF8_Msk      (0x1UL << HSEM_C2ISR_ISF8_Pos)                /*!< 0x00000100 */
#define HSEM_C2ISR_ISF8          HSEM_C2ISR_ISF8_Msk                           /*!<semaphore 8 CPU2 interrupt status bit.  */
#define HSEM_C2ISR_ISF9_Pos      (9U)
#define HSEM_C2ISR_ISF9_Msk      (0x1UL << HSEM_C2ISR_ISF9_Pos)                /*!< 0x00000200 */
#define HSEM_C2ISR_ISF9          HSEM_C2ISR_ISF9_Msk                           /*!<semaphore 9 CPU2 interrupt status bit.  */
#define HSEM_C2ISR_ISF10_Pos     (10U)
#define HSEM_C2ISR_ISF10_Msk     (0x1UL << HSEM_C2ISR_ISF10_Pos)               /*!< 0x00000400 */
#define HSEM_C2ISR_ISF10         HSEM_C2ISR_ISF10_Msk                          /*!<semaphore 10 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF11_Pos     (11U)
#define HSEM_C2ISR_ISF11_Msk     (0x1UL << HSEM_C2ISR_ISF11_Pos)               /*!< 0x00000800 */
#define HSEM_C2ISR_ISF11         HSEM_C2ISR_ISF11_Msk                          /*!<semaphore 11 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF12_Pos     (12U)
#define HSEM_C2ISR_ISF12_Msk     (0x1UL << HSEM_C2ISR_ISF12_Pos)               /*!< 0x00001000 */
#define HSEM_C2ISR_ISF12         HSEM_C2ISR_ISF12_Msk                          /*!<semaphore 12 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF13_Pos     (13U)
#define HSEM_C2ISR_ISF13_Msk     (0x1UL << HSEM_C2ISR_ISF13_Pos)               /*!< 0x00002000 */
#define HSEM_C2ISR_ISF13         HSEM_C2ISR_ISF13_Msk                          /*!<semaphore 13 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF14_Pos     (14U)
#define HSEM_C2ISR_ISF14_Msk     (0x1UL << HSEM_C2ISR_ISF14_Pos)               /*!< 0x00004000 */
#define HSEM_C2ISR_ISF14         HSEM_C2ISR_ISF14_Msk                          /*!<semaphore 14 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF15_Pos     (15U)
#define HSEM_C2ISR_ISF15_Msk     (0x1UL << HSEM_C2ISR_ISF15_Pos)               /*!< 0x00008000 */
#define HSEM_C2ISR_ISF15         HSEM_C2ISR_ISF15_Msk                          /*!<semaphore 15 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF16_Pos     (16U)
#define HSEM_C2ISR_ISF16_Msk     (0x1UL << HSEM_C2ISR_ISF16_Pos)               /*!< 0x00010000 */
#define HSEM_C2ISR_ISF16         HSEM_C2ISR_ISF16_Msk                          /*!<semaphore 16 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF17_Pos     (17U)
#define HSEM_C2ISR_ISF17_Msk     (0x1UL << HSEM_C2ISR_ISF17_Pos)               /*!< 0x00020000 */
#define HSEM_C2ISR_ISF17         HSEM_C2ISR_ISF17_Msk                          /*!<semaphore 17 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF18_Pos     (18U)
#define HSEM_C2ISR_ISF18_Msk     (0x1UL << HSEM_C2ISR_ISF18_Pos)               /*!< 0x00040000 */
#define HSEM_C2ISR_ISF18         HSEM_C2ISR_ISF18_Msk                          /*!<semaphore 18 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF19_Pos     (19U)
#define HSEM_C2ISR_ISF19_Msk     (0x1UL << HSEM_C2ISR_ISF19_Pos)               /*!< 0x00080000 */
#define HSEM_C2ISR_ISF19         HSEM_C2ISR_ISF19_Msk                          /*!<semaphore 19 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF20_Pos     (20U)
#define HSEM_C2ISR_ISF20_Msk     (0x1UL << HSEM_C2ISR_ISF20_Pos)               /*!< 0x00100000 */
#define HSEM_C2ISR_ISF20         HSEM_C2ISR_ISF20_Msk                          /*!<semaphore 20 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF21_Pos     (21U)
#define HSEM_C2ISR_ISF21_Msk     (0x1UL << HSEM_C2ISR_ISF21_Pos)               /*!< 0x00200000 */
#define HSEM_C2ISR_ISF21         HSEM_C2ISR_ISF21_Msk                          /*!<semaphore 21 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF22_Pos     (22U)
#define HSEM_C2ISR_ISF22_Msk     (0x1UL << HSEM_C2ISR_ISF22_Pos)               /*!< 0x00400000 */
#define HSEM_C2ISR_ISF22         HSEM_C2ISR_ISF22_Msk                          /*!<semaphore 22 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF23_Pos     (23U)
#define HSEM_C2ISR_ISF23_Msk     (0x1UL << HSEM_C2ISR_ISF23_Pos)               /*!< 0x00800000 */
#define HSEM_C2ISR_ISF23         HSEM_C2ISR_ISF23_Msk                          /*!<semaphore 23 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF24_Pos     (24U)
#define HSEM_C2ISR_ISF24_Msk     (0x1UL << HSEM_C2ISR_ISF24_Pos)               /*!< 0x01000000 */
#define HSEM_C2ISR_ISF24         HSEM_C2ISR_ISF24_Msk                          /*!<semaphore 24 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF25_Pos     (25U)
#define HSEM_C2ISR_ISF25_Msk     (0x1UL << HSEM_C2ISR_ISF25_Pos)               /*!< 0x02000000 */
#define HSEM_C2ISR_ISF25         HSEM_C2ISR_ISF25_Msk                          /*!<semaphore 25 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF26_Pos     (26U)
#define HSEM_C2ISR_ISF26_Msk     (0x1UL << HSEM_C2ISR_ISF26_Pos)               /*!< 0x04000000 */
#define HSEM_C2ISR_ISF26         HSEM_C2ISR_ISF26_Msk                          /*!<semaphore 26 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF27_Pos     (27U)
#define HSEM_C2ISR_ISF27_Msk     (0x1UL << HSEM_C2ISR_ISF27_Pos)               /*!< 0x08000000 */
#define HSEM_C2ISR_ISF27         HSEM_C2ISR_ISF27_Msk                          /*!<semaphore 27 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF28_Pos     (28U)
#define HSEM_C2ISR_ISF28_Msk     (0x1UL << HSEM_C2ISR_ISF28_Pos)               /*!< 0x10000000 */
#define HSEM_C2ISR_ISF28         HSEM_C2ISR_ISF28_Msk                          /*!<semaphore 28 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF29_Pos     (29U)
#define HSEM_C2ISR_ISF29_Msk     (0x1UL << HSEM_C2ISR_ISF29_Pos)               /*!< 0x20000000 */
#define HSEM_C2ISR_ISF29         HSEM_C2ISR_ISF29_Msk                          /*!<semaphore 29 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF30_Pos     (30U)
#define HSEM_C2ISR_ISF30_Msk     (0x1UL << HSEM_C2ISR_ISF30_Pos)               /*!< 0x40000000 */
#define HSEM_C2ISR_ISF30         HSEM_C2ISR_ISF30_Msk                          /*!<semaphore 30 CPU2 interrupt status bit. */
#define HSEM_C2ISR_ISF31_Pos     (31U)
#define HSEM_C2ISR_ISF31_Msk     (0x1UL << HSEM_C2ISR_ISF31_Pos)               /*!< 0x80000000 */
#define HSEM_C2ISR_ISF31         HSEM_C2ISR_ISF31_Msk                          /*!<semaphore 31 CPU2 interrupt status bit. */

/********************  Bit definition for HSEM_C2MISR register  *****************/
#define HSEM_C2MISR_MISF0_Pos     (0U)
#define HSEM_C2MISR_MISF0_Msk     (0x1UL << HSEM_C2MISR_MISF0_Pos)               /*!< 0x00000001 */
#define HSEM_C2MISR_MISF0         HSEM_C2MISR_MISF0_Msk                          /*!<semaphore 0 CPU2 interrupt masked status bit.  */
#define HSEM_C2MISR_MISF1_Pos     (1U)
#define HSEM_C2MISR_MISF1_Msk     (0x1UL << HSEM_C2MISR_MISF1_Pos)               /*!< 0x00000002 */
#define HSEM_C2MISR_MISF1         HSEM_C2MISR_MISF1_Msk                          /*!<semaphore 1 CPU2 interrupt masked status bit.  */
#define HSEM_C2MISR_MISF2_Pos     (2U)
#define HSEM_C2MISR_MISF2_Msk     (0x1UL << HSEM_C2MISR_MISF2_Pos)               /*!< 0x00000004 */
#define HSEM_C2MISR_MISF2         HSEM_C2MISR_MISF2_Msk                          /*!<semaphore 2 CPU2 interrupt masked status bit.  */
#define HSEM_C2MISR_MISF3_Pos     (3U)
#define HSEM_C2MISR_MISF3_Msk     (0x1UL << HSEM_C2MISR_MISF3_Pos)               /*!< 0x00000008 */
#define HSEM_C2MISR_MISF3         HSEM_C2MISR_MISF3_Msk                          /*!<semaphore 3 CPU2 interrupt masked status bit.  */
#define HSEM_C2MISR_MISF4_Pos     (4U)
#define HSEM_C2MISR_MISF4_Msk     (0x1UL << HSEM_C2MISR_MISF4_Pos)               /*!< 0x00000010 */
#define HSEM_C2MISR_MISF4         HSEM_C2MISR_MISF4_Msk                          /*!<semaphore 4 CPU2 interrupt masked status bit.  */
#define HSEM_C2MISR_MISF5_Pos     (5U)
#define HSEM_C2MISR_MISF5_Msk     (0x1UL << HSEM_C2MISR_MISF5_Pos)               /*!< 0x00000020 */
#define HSEM_C2MISR_MISF5         HSEM_C2MISR_MISF5_Msk                          /*!<semaphore 5 CPU2 interrupt masked status bit.  */
#define HSEM_C2MISR_MISF6_Pos     (6U)
#define HSEM_C2MISR_MISF6_Msk     (0x1UL << HSEM_C2MISR_MISF6_Pos)               /*!< 0x00000040 */
#define HSEM_C2MISR_MISF6         HSEM_C2MISR_MISF6_Msk                          /*!<semaphore 6 CPU2 interrupt masked status bit.  */
#define HSEM_C2MISR_MISF7_Pos     (7U)
#define HSEM_C2MISR_MISF7_Msk     (0x1UL << HSEM_C2MISR_MISF7_Pos)               /*!< 0x00000080 */
#define HSEM_C2MISR_MISF7         HSEM_C2MISR_MISF7_Msk                          /*!<semaphore 7 CPU2 interrupt masked status bit.  */
#define HSEM_C2MISR_MISF8_Pos     (8U)
#define HSEM_C2MISR_MISF8_Msk     (0x1UL << HSEM_C2MISR_MISF8_Pos)               /*!< 0x00000100 */
#define HSEM_C2MISR_MISF8         HSEM_C2MISR_MISF8_Msk                          /*!<semaphore 8 CPU2 interrupt masked status bit.  */
#define HSEM_C2MISR_MISF9_Pos     (9U)
#define HSEM_C2MISR_MISF9_Msk     (0x1UL << HSEM_C2MISR_MISF9_Pos)               /*!< 0x00000200 */
#define HSEM_C2MISR_MISF9         HSEM_C2MISR_MISF9_Msk                          /*!<semaphore 9 CPU2 interrupt masked status bit.  */
#define HSEM_C2MISR_MISF10_Pos    (10U)
#define HSEM_C2MISR_MISF10_Msk    (0x1UL << HSEM_C2MISR_MISF10_Pos)              /*!< 0x00000400 */
#define HSEM_C2MISR_MISF10        HSEM_C2MISR_MISF10_Msk                         /*!<semaphore 10 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF11_Pos    (11U)
#define HSEM_C2MISR_MISF11_Msk    (0x1UL << HSEM_C2MISR_MISF11_Pos)              /*!< 0x00000800 */
#define HSEM_C2MISR_MISF11        HSEM_C2MISR_MISF11_Msk                         /*!<semaphore 11 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF12_Pos    (12U)
#define HSEM_C2MISR_MISF12_Msk    (0x1UL << HSEM_C2MISR_MISF12_Pos)              /*!< 0x00001000 */
#define HSEM_C2MISR_MISF12        HSEM_C2MISR_MISF12_Msk                         /*!<semaphore 12 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF13_Pos    (13U)
#define HSEM_C2MISR_MISF13_Msk    (0x1UL << HSEM_C2MISR_MISF13_Pos)              /*!< 0x00002000 */
#define HSEM_C2MISR_MISF13        HSEM_C2MISR_MISF13_Msk                         /*!<semaphore 13 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF14_Pos    (14U)
#define HSEM_C2MISR_MISF14_Msk    (0x1UL << HSEM_C2MISR_MISF14_Pos)              /*!< 0x00004000 */
#define HSEM_C2MISR_MISF14        HSEM_C2MISR_MISF14_Msk                         /*!<semaphore 14 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF15_Pos    (15U)
#define HSEM_C2MISR_MISF15_Msk    (0x1UL << HSEM_C2MISR_MISF15_Pos)              /*!< 0x00008000 */
#define HSEM_C2MISR_MISF15        HSEM_C2MISR_MISF15_Msk                         /*!<semaphore 15 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF16_Pos    (16U)
#define HSEM_C2MISR_MISF16_Msk    (0x1UL << HSEM_C2MISR_MISF16_Pos)              /*!< 0x00010000 */
#define HSEM_C2MISR_MISF16        HSEM_C2MISR_MISF16_Msk                         /*!<semaphore 16 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF17_Pos    (17U)
#define HSEM_C2MISR_MISF17_Msk    (0x1UL << HSEM_C2MISR_MISF17_Pos)              /*!< 0x00020000 */
#define HSEM_C2MISR_MISF17        HSEM_C2MISR_MISF17_Msk                         /*!<semaphore 17 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF18_Pos    (18U)
#define HSEM_C2MISR_MISF18_Msk    (0x1UL << HSEM_C2MISR_MISF18_Pos)              /*!< 0x00040000 */
#define HSEM_C2MISR_MISF18        HSEM_C2MISR_MISF18_Msk                         /*!<semaphore 18 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF19_Pos    (19U)
#define HSEM_C2MISR_MISF19_Msk    (0x1UL << HSEM_C2MISR_MISF19_Pos)              /*!< 0x00080000 */
#define HSEM_C2MISR_MISF19        HSEM_C2MISR_MISF19_Msk                         /*!<semaphore 19 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF20_Pos    (20U)
#define HSEM_C2MISR_MISF20_Msk    (0x1UL << HSEM_C2MISR_MISF20_Pos)              /*!< 0x00100000 */
#define HSEM_C2MISR_MISF20        HSEM_C2MISR_MISF20_Msk                         /*!<semaphore 20 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF21_Pos    (21U)
#define HSEM_C2MISR_MISF21_Msk    (0x1UL << HSEM_C2MISR_MISF21_Pos)              /*!< 0x00200000 */
#define HSEM_C2MISR_MISF21        HSEM_C2MISR_MISF21_Msk                         /*!<semaphore 21 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF22_Pos    (22U)
#define HSEM_C2MISR_MISF22_Msk    (0x1UL << HSEM_C2MISR_MISF22_Pos)              /*!< 0x00400000 */
#define HSEM_C2MISR_MISF22        HSEM_C2MISR_MISF22_Msk                         /*!<semaphore 22 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF23_Pos    (23U)
#define HSEM_C2MISR_MISF23_Msk    (0x1UL << HSEM_C2MISR_MISF23_Pos)              /*!< 0x00800000 */
#define HSEM_C2MISR_MISF23        HSEM_C2MISR_MISF23_Msk                         /*!<semaphore 23 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF24_Pos    (24U)
#define HSEM_C2MISR_MISF24_Msk    (0x1UL << HSEM_C2MISR_MISF24_Pos)              /*!< 0x01000000 */
#define HSEM_C2MISR_MISF24        HSEM_C2MISR_MISF24_Msk                         /*!<semaphore 24 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF25_Pos    (25U)
#define HSEM_C2MISR_MISF25_Msk    (0x1UL << HSEM_C2MISR_MISF25_Pos)              /*!< 0x02000000 */
#define HSEM_C2MISR_MISF25        HSEM_C2MISR_MISF25_Msk                         /*!<semaphore 25 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF26_Pos    (26U)
#define HSEM_C2MISR_MISF26_Msk    (0x1UL << HSEM_C2MISR_MISF26_Pos)              /*!< 0x04000000 */
#define HSEM_C2MISR_MISF26        HSEM_C2MISR_MISF26_Msk                         /*!<semaphore 26 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF27_Pos    (27U)
#define HSEM_C2MISR_MISF27_Msk    (0x1UL << HSEM_C2MISR_MISF27_Pos)              /*!< 0x08000000 */
#define HSEM_C2MISR_MISF27        HSEM_C2MISR_MISF27_Msk                         /*!<semaphore 27 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF28_Pos    (28U)
#define HSEM_C2MISR_MISF28_Msk    (0x1UL << HSEM_C2MISR_MISF28_Pos)              /*!< 0x10000000 */
#define HSEM_C2MISR_MISF28        HSEM_C2MISR_MISF28_Msk                         /*!<semaphore 28 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF29_Pos    (29U)
#define HSEM_C2MISR_MISF29_Msk    (0x1UL << HSEM_C2MISR_MISF29_Pos)              /*!< 0x20000000 */
#define HSEM_C2MISR_MISF29        HSEM_C2MISR_MISF29_Msk                         /*!<semaphore 29 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF30_Pos    (30U)
#define HSEM_C2MISR_MISF30_Msk    (0x1UL << HSEM_C2MISR_MISF30_Pos)              /*!< 0x40000000 */
#define HSEM_C2MISR_MISF30        HSEM_C2MISR_MISF30_Msk                         /*!<semaphore 30 CPU2 interrupt masked status bit. */
#define HSEM_C2MISR_MISF31_Pos    (31U)
#define HSEM_C2MISR_MISF31_Msk    (0x1UL << HSEM_C2MISR_MISF31_Pos)              /*!< 0x80000000 */
#define HSEM_C2MISR_MISF31        HSEM_C2MISR_MISF31_Msk                         /*!<semaphore 31 CPU2 interrupt masked status bit. */

/********************  Bit definition for HSEM_CR register  *****************/
#define HSEM_CR_COREID_Pos       (8U)
#define HSEM_CR_COREID_Msk       (0xFUL << HSEM_CR_COREID_Pos)                 /*!< 0x00000F00 */
#define HSEM_CR_COREID           HSEM_CR_COREID_Msk                            /*!<CoreID of semaphores to be cleared. */
#define HSEM_CR_COREID_CPU1      (0x4U << HSEM_CR_COREID_Pos)
#define HSEM_CR_COREID_CPU2      (0x8U << HSEM_CR_COREID_Pos)
#define HSEM_CR_COREID_CURRENT   HSEM_CR_COREID_CPU1
#define HSEM_CR_KEY_Pos          (16U)
#define HSEM_CR_KEY_Msk          (0xFFFFUL << HSEM_CR_KEY_Pos)                 /*!< 0xFFFF0000 */
#define HSEM_CR_KEY              HSEM_CR_KEY_Msk                               /*!<semaphores clear key. */

/********************  Bit definition for HSEM_KEYR register  *****************/
#define HSEM_KEYR_KEY_Pos        (16U)
#define HSEM_KEYR_KEY_Msk        (0xFFFFUL << HSEM_KEYR_KEY_Pos)               /*!< 0xFFFF0000 */
#define HSEM_KEYR_KEY            HSEM_KEYR_KEY_Msk                             /*!<semaphores clear key. */

/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface (I2C)              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CR1 register  *******************/
#define I2C_CR1_PE_Pos               (0U)
#define I2C_CR1_PE_Msk               (0x1UL << I2C_CR1_PE_Pos)                 /*!< 0x00000001 */
#define I2C_CR1_PE                   I2C_CR1_PE_Msk                            /*!< Peripheral enable */
#define I2C_CR1_TXIE_Pos             (1U)
#define I2C_CR1_TXIE_Msk             (0x1UL << I2C_CR1_TXIE_Pos)               /*!< 0x00000002 */
#define I2C_CR1_TXIE                 I2C_CR1_TXIE_Msk                          /*!< TX interrupt enable */
#define I2C_CR1_RXIE_Pos             (2U)
#define I2C_CR1_RXIE_Msk             (0x1UL << I2C_CR1_RXIE_Pos)               /*!< 0x00000004 */
#define I2C_CR1_RXIE                 I2C_CR1_RXIE_Msk                          /*!< RX interrupt enable */
#define I2C_CR1_ADDRIE_Pos           (3U)
#define I2C_CR1_ADDRIE_Msk           (0x1UL << I2C_CR1_ADDRIE_Pos)             /*!< 0x00000008 */
#define I2C_CR1_ADDRIE               I2C_CR1_ADDRIE_Msk                        /*!< Address match interrupt enable */
#define I2C_CR1_NACKIE_Pos           (4U)
#define I2C_CR1_NACKIE_Msk           (0x1UL << I2C_CR1_NACKIE_Pos)             /*!< 0x00000010 */
#define I2C_CR1_NACKIE               I2C_CR1_NACKIE_Msk                        /*!< NACK received interrupt enable */
#define I2C_CR1_STOPIE_Pos           (5U)
#define I2C_CR1_STOPIE_Msk           (0x1UL << I2C_CR1_STOPIE_Pos)             /*!< 0x00000020 */
#define I2C_CR1_STOPIE               I2C_CR1_STOPIE_Msk                        /*!< STOP detection interrupt enable */
#define I2C_CR1_TCIE_Pos             (6U)
#define I2C_CR1_TCIE_Msk             (0x1UL << I2C_CR1_TCIE_Pos)               /*!< 0x00000040 */
#define I2C_CR1_TCIE                 I2C_CR1_TCIE_Msk                          /*!< Transfer complete interrupt enable */
#define I2C_CR1_ERRIE_Pos            (7U)
#define I2C_CR1_ERRIE_Msk            (0x1UL << I2C_CR1_ERRIE_Pos)              /*!< 0x00000080 */
#define I2C_CR1_ERRIE                I2C_CR1_ERRIE_Msk                         /*!< Errors interrupt enable */
#define I2C_CR1_DNF_Pos              (8U)
#define I2C_CR1_DNF_Msk              (0xFUL << I2C_CR1_DNF_Pos)                /*!< 0x00000F00 */
#define I2C_CR1_DNF                  I2C_CR1_DNF_Msk                           /*!< Digital noise filter */
#define I2C_CR1_ANFOFF_Pos           (12U)
#define I2C_CR1_ANFOFF_Msk           (0x1UL << I2C_CR1_ANFOFF_Pos)             /*!< 0x00001000 */
#define I2C_CR1_ANFOFF               I2C_CR1_ANFOFF_Msk                        /*!< Analog noise filter OFF */
#define I2C_CR1_SWRST_Pos            (13U)
#define I2C_CR1_SWRST_Msk            (0x1UL << I2C_CR1_SWRST_Pos)              /*!< 0x00002000 */
#define I2C_CR1_SWRST                I2C_CR1_SWRST_Msk                         /*!< Software reset */
#define I2C_CR1_TXDMAEN_Pos          (14U)
#define I2C_CR1_TXDMAEN_Msk          (0x1UL << I2C_CR1_TXDMAEN_Pos)            /*!< 0x00004000 */
#define I2C_CR1_TXDMAEN              I2C_CR1_TXDMAEN_Msk                       /*!< DMA transmission requests enable */
#define I2C_CR1_RXDMAEN_Pos          (15U)
#define I2C_CR1_RXDMAEN_Msk          (0x1UL << I2C_CR1_RXDMAEN_Pos)            /*!< 0x00008000 */
#define I2C_CR1_RXDMAEN              I2C_CR1_RXDMAEN_Msk                       /*!< DMA reception requests enable */
#define I2C_CR1_SBC_Pos              (16U)
#define I2C_CR1_SBC_Msk              (0x1UL << I2C_CR1_SBC_Pos)                /*!< 0x00010000 */
#define I2C_CR1_SBC                  I2C_CR1_SBC_Msk                           /*!< Slave byte control */
#define I2C_CR1_NOSTRETCH_Pos        (17U)
#define I2C_CR1_NOSTRETCH_Msk        (0x1UL << I2C_CR1_NOSTRETCH_Pos)          /*!< 0x00020000 */
#define I2C_CR1_NOSTRETCH            I2C_CR1_NOSTRETCH_Msk                     /*!< Clock stretching disable */
#define I2C_CR1_WUPEN_Pos            (18U)
#define I2C_CR1_WUPEN_Msk            (0x1UL << I2C_CR1_WUPEN_Pos)              /*!< 0x00040000 */
#define I2C_CR1_WUPEN                I2C_CR1_WUPEN_Msk                         /*!< Wakeup from STOP enable */
#define I2C_CR1_GCEN_Pos             (19U)
#define I2C_CR1_GCEN_Msk             (0x1UL << I2C_CR1_GCEN_Pos)               /*!< 0x00080000 */
#define I2C_CR1_GCEN                 I2C_CR1_GCEN_Msk                          /*!< General call enable */
#define I2C_CR1_SMBHEN_Pos           (20U)
#define I2C_CR1_SMBHEN_Msk           (0x1UL << I2C_CR1_SMBHEN_Pos)             /*!< 0x00100000 */
#define I2C_CR1_SMBHEN               I2C_CR1_SMBHEN_Msk                        /*!< SMBus host address enable */
#define I2C_CR1_SMBDEN_Pos           (21U)
#define I2C_CR1_SMBDEN_Msk           (0x1UL << I2C_CR1_SMBDEN_Pos)             /*!< 0x00200000 */
#define I2C_CR1_SMBDEN               I2C_CR1_SMBDEN_Msk                        /*!< SMBus device default address enable */
#define I2C_CR1_ALERTEN_Pos          (22U)
#define I2C_CR1_ALERTEN_Msk          (0x1UL << I2C_CR1_ALERTEN_Pos)            /*!< 0x00400000 */
#define I2C_CR1_ALERTEN              I2C_CR1_ALERTEN_Msk                       /*!< SMBus alert enable */
#define I2C_CR1_PECEN_Pos            (23U)
#define I2C_CR1_PECEN_Msk            (0x1UL << I2C_CR1_PECEN_Pos)              /*!< 0x00800000 */
#define I2C_CR1_PECEN                I2C_CR1_PECEN_Msk                         /*!< PEC enable */

/******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_SADD_Pos             (0U)
#define I2C_CR2_SADD_Msk             (0x3FFUL << I2C_CR2_SADD_Pos)             /*!< 0x000003FF */
#define I2C_CR2_SADD                 I2C_CR2_SADD_Msk                          /*!< Slave address (master mode) */
#define I2C_CR2_RD_WRN_Pos           (10U)
#define I2C_CR2_RD_WRN_Msk           (0x1UL << I2C_CR2_RD_WRN_Pos)             /*!< 0x00000400 */
#define I2C_CR2_RD_WRN               I2C_CR2_RD_WRN_Msk                        /*!< Transfer direction (master mode) */
#define I2C_CR2_ADD10_Pos            (11U)
#define I2C_CR2_ADD10_Msk            (0x1UL << I2C_CR2_ADD10_Pos)              /*!< 0x00000800 */
#define I2C_CR2_ADD10                I2C_CR2_ADD10_Msk                         /*!< 10-bit addressing mode (master mode) */
#define I2C_CR2_HEAD10R_Pos          (12U)
#define I2C_CR2_HEAD10R_Msk          (0x1UL << I2C_CR2_HEAD10R_Pos)            /*!< 0x00001000 */
#define I2C_CR2_HEAD10R              I2C_CR2_HEAD10R_Msk                       /*!< 10-bit address header only read direction (master mode) */
#define I2C_CR2_START_Pos            (13U)
#define I2C_CR2_START_Msk            (0x1UL << I2C_CR2_START_Pos)              /*!< 0x00002000 */
#define I2C_CR2_START                I2C_CR2_START_Msk                         /*!< START generation */
#define I2C_CR2_STOP_Pos             (14U)
#define I2C_CR2_STOP_Msk             (0x1UL << I2C_CR2_STOP_Pos)               /*!< 0x00004000 */
#define I2C_CR2_STOP                 I2C_CR2_STOP_Msk                          /*!< STOP generation (master mode) */
#define I2C_CR2_NACK_Pos             (15U)
#define I2C_CR2_NACK_Msk             (0x1UL << I2C_CR2_NACK_Pos)               /*!< 0x00008000 */
#define I2C_CR2_NACK                 I2C_CR2_NACK_Msk                          /*!< NACK generation (slave mode) */
#define I2C_CR2_NBYTES_Pos           (16U)
#define I2C_CR2_NBYTES_Msk           (0xFFUL << I2C_CR2_NBYTES_Pos)            /*!< 0x00FF0000 */
#define I2C_CR2_NBYTES               I2C_CR2_NBYTES_Msk                        /*!< Number of bytes */
#define I2C_CR2_RELOAD_Pos           (24U)
#define I2C_CR2_RELOAD_Msk           (0x1UL << I2C_CR2_RELOAD_Pos)             /*!< 0x01000000 */
#define I2C_CR2_RELOAD               I2C_CR2_RELOAD_Msk                        /*!< NBYTES reload mode */
#define I2C_CR2_AUTOEND_Pos          (25U)
#define I2C_CR2_AUTOEND_Msk          (0x1UL << I2C_CR2_AUTOEND_Pos)            /*!< 0x02000000 */
#define I2C_CR2_AUTOEND              I2C_CR2_AUTOEND_Msk                       /*!< Automatic end mode (master mode) */
#define I2C_CR2_PECBYTE_Pos          (26U)
#define I2C_CR2_PECBYTE_Msk          (0x1UL << I2C_CR2_PECBYTE_Pos)            /*!< 0x04000000 */
#define I2C_CR2_PECBYTE              I2C_CR2_PECBYTE_Msk                       /*!< Packet error checking byte */

/*******************  Bit definition for I2C_OAR1 register  ******************/
#define I2C_OAR1_OA1_Pos             (0U)
#define I2C_OAR1_OA1_Msk             (0x3FFUL << I2C_OAR1_OA1_Pos)             /*!< 0x000003FF */
#define I2C_OAR1_OA1                 I2C_OAR1_OA1_Msk                          /*!< Interface own address 1 */
#define I2C_OAR1_OA1MODE_Pos         (10U)
#define I2C_OAR1_OA1MODE_Msk         (0x1UL << I2C_OAR1_OA1MODE_Pos)           /*!< 0x00000400 */
#define I2C_OAR1_OA1MODE             I2C_OAR1_OA1MODE_Msk                      /*!< Own address 1 10-bit mode */
#define I2C_OAR1_OA1EN_Pos           (15U)
#define I2C_OAR1_OA1EN_Msk           (0x1UL << I2C_OAR1_OA1EN_Pos)             /*!< 0x00008000 */
#define I2C_OAR1_OA1EN               I2C_OAR1_OA1EN_Msk                        /*!< Own address 1 enable */

/*******************  Bit definition for I2C_OAR2 register  ******************/
#define I2C_OAR2_OA2_Pos             (1U)
#define I2C_OAR2_OA2_Msk             (0x7FUL << I2C_OAR2_OA2_Pos)              /*!< 0x000000FE */
#define I2C_OAR2_OA2                 I2C_OAR2_OA2_Msk                          /*!< Interface own address 2 */
#define I2C_OAR2_OA2MSK_Pos          (8U)
#define I2C_OAR2_OA2MSK_Msk          (0x7UL << I2C_OAR2_OA2MSK_Pos)            /*!< 0x00000700 */
#define I2C_OAR2_OA2MSK              I2C_OAR2_OA2MSK_Msk                       /*!< Own address 2 masks */
#define I2C_OAR2_OA2NOMASK           (0x00000000UL)                            /*!< No mask                                        */
#define I2C_OAR2_OA2MASK01_Pos       (8U)
#define I2C_OAR2_OA2MASK01_Msk       (0x1UL << I2C_OAR2_OA2MASK01_Pos)         /*!< 0x00000100 */
#define I2C_OAR2_OA2MASK01           I2C_OAR2_OA2MASK01_Msk                    /*!< OA2[1] is masked, Only OA2[7:2] are compared   */
#define I2C_OAR2_OA2MASK02_Pos       (9U)
#define I2C_OAR2_OA2MASK02_Msk       (0x1UL << I2C_OAR2_OA2MASK02_Pos)         /*!< 0x00000200 */
#define I2C_OAR2_OA2MASK02           I2C_OAR2_OA2MASK02_Msk                    /*!< OA2[2:1] is masked, Only OA2[7:3] are compared */
#define I2C_OAR2_OA2MASK03_Pos       (8U)
#define I2C_OAR2_OA2MASK03_Msk       (0x3UL << I2C_OAR2_OA2MASK03_Pos)         /*!< 0x00000300 */
#define I2C_OAR2_OA2MASK03           I2C_OAR2_OA2MASK03_Msk                    /*!< OA2[3:1] is masked, Only OA2[7:4] are compared */
#define I2C_OAR2_OA2MASK04_Pos       (10U)
#define I2C_OAR2_OA2MASK04_Msk       (0x1UL << I2C_OAR2_OA2MASK04_Pos)         /*!< 0x00000400 */
#define I2C_OAR2_OA2MASK04           I2C_OAR2_OA2MASK04_Msk                    /*!< OA2[4:1] is masked, Only OA2[7:5] are compared */
#define I2C_OAR2_OA2MASK05_Pos       (8U)
#define I2C_OAR2_OA2MASK05_Msk       (0x5UL << I2C_OAR2_OA2MASK05_Pos)         /*!< 0x00000500 */
#define I2C_OAR2_OA2MASK05           I2C_OAR2_OA2MASK05_Msk                    /*!< OA2[5:1] is masked, Only OA2[7:6] are compared */
#define I2C_OAR2_OA2MASK06_Pos       (9U)
#define I2C_OAR2_OA2MASK06_Msk       (0x3UL << I2C_OAR2_OA2MASK06_Pos)         /*!< 0x00000600 */
#define I2C_OAR2_OA2MASK06           I2C_OAR2_OA2MASK06_Msk                    /*!< OA2[6:1] is masked, Only OA2[7] are compared   */
#define I2C_OAR2_OA2MASK07_Pos       (8U)
#define I2C_OAR2_OA2MASK07_Msk       (0x7UL << I2C_OAR2_OA2MASK07_Pos)         /*!< 0x00000700 */
#define I2C_OAR2_OA2MASK07           I2C_OAR2_OA2MASK07_Msk                    /*!< OA2[7:1] is masked, No comparison is done      */
#define I2C_OAR2_OA2EN_Pos           (15U)
#define I2C_OAR2_OA2EN_Msk           (0x1UL << I2C_OAR2_OA2EN_Pos)             /*!< 0x00008000 */
#define I2C_OAR2_OA2EN               I2C_OAR2_OA2EN_Msk                        /*!< Own address 2 enable */

/*******************  Bit definition for I2C_TIMINGR register *******************/
#define I2C_TIMINGR_SCLL_Pos         (0U)
#define I2C_TIMINGR_SCLL_Msk         (0xFFUL << I2C_TIMINGR_SCLL_Pos)          /*!< 0x000000FF */
#define I2C_TIMINGR_SCLL             I2C_TIMINGR_SCLL_Msk                      /*!< SCL low period (master mode) */
#define I2C_TIMINGR_SCLH_Pos         (8U)
#define I2C_TIMINGR_SCLH_Msk         (0xFFUL << I2C_TIMINGR_SCLH_Pos)          /*!< 0x0000FF00 */
#define I2C_TIMINGR_SCLH             I2C_TIMINGR_SCLH_Msk                      /*!< SCL high period (master mode) */
#define I2C_TIMINGR_SDADEL_Pos       (16U)
#define I2C_TIMINGR_SDADEL_Msk       (0xFUL << I2C_TIMINGR_SDADEL_Pos)         /*!< 0x000F0000 */
#define I2C_TIMINGR_SDADEL           I2C_TIMINGR_SDADEL_Msk                    /*!< Data hold time */
#define I2C_TIMINGR_SCLDEL_Pos       (20U)
#define I2C_TIMINGR_SCLDEL_Msk       (0xFUL << I2C_TIMINGR_SCLDEL_Pos)         /*!< 0x00F00000 */
#define I2C_TIMINGR_SCLDEL           I2C_TIMINGR_SCLDEL_Msk                    /*!< Data setup time */
#define I2C_TIMINGR_PRESC_Pos        (28U)
#define I2C_TIMINGR_PRESC_Msk        (0xFUL << I2C_TIMINGR_PRESC_Pos)          /*!< 0xF0000000 */
#define I2C_TIMINGR_PRESC            I2C_TIMINGR_PRESC_Msk                     /*!< Timings prescaler */

/******************* Bit definition for I2C_TIMEOUTR register *******************/
#define I2C_TIMEOUTR_TIMEOUTA_Pos    (0U)
#define I2C_TIMEOUTR_TIMEOUTA_Msk    (0xFFFUL << I2C_TIMEOUTR_TIMEOUTA_Pos)    /*!< 0x00000FFF */
#define I2C_TIMEOUTR_TIMEOUTA        I2C_TIMEOUTR_TIMEOUTA_Msk                 /*!< Bus timeout A */
#define I2C_TIMEOUTR_TIDLE_Pos       (12U)
#define I2C_TIMEOUTR_TIDLE_Msk       (0x1UL << I2C_TIMEOUTR_TIDLE_Pos)         /*!< 0x00001000 */
#define I2C_TIMEOUTR_TIDLE           I2C_TIMEOUTR_TIDLE_Msk                    /*!< Idle clock timeout detection */
#define I2C_TIMEOUTR_TIMOUTEN_Pos    (15U)
#define I2C_TIMEOUTR_TIMOUTEN_Msk    (0x1UL << I2C_TIMEOUTR_TIMOUTEN_Pos)      /*!< 0x00008000 */
#define I2C_TIMEOUTR_TIMOUTEN        I2C_TIMEOUTR_TIMOUTEN_Msk                 /*!< Clock timeout enable */
#define I2C_TIMEOUTR_TIMEOUTB_Pos    (16U)
#define I2C_TIMEOUTR_TIMEOUTB_Msk    (0xFFFUL << I2C_TIMEOUTR_TIMEOUTB_Pos)    /*!< 0x0FFF0000 */
#define I2C_TIMEOUTR_TIMEOUTB        I2C_TIMEOUTR_TIMEOUTB_Msk                 /*!< Bus timeout B*/
#define I2C_TIMEOUTR_TEXTEN_Pos      (31U)
#define I2C_TIMEOUTR_TEXTEN_Msk      (0x1UL << I2C_TIMEOUTR_TEXTEN_Pos)        /*!< 0x80000000 */
#define I2C_TIMEOUTR_TEXTEN          I2C_TIMEOUTR_TEXTEN_Msk                   /*!< Extended clock timeout enable */

/******************  Bit definition for I2C_ISR register  *********************/
#define I2C_ISR_TXE_Pos              (0U)
#define I2C_ISR_TXE_Msk              (0x1UL << I2C_ISR_TXE_Pos)                /*!< 0x00000001 */
#define I2C_ISR_TXE                  I2C_ISR_TXE_Msk                           /*!< Transmit data register empty */
#define I2C_ISR_TXIS_Pos             (1U)
#define I2C_ISR_TXIS_Msk             (0x1UL << I2C_ISR_TXIS_Pos)               /*!< 0x00000002 */
#define I2C_ISR_TXIS                 I2C_ISR_TXIS_Msk                          /*!< Transmit interrupt status */
#define I2C_ISR_RXNE_Pos             (2U)
#define I2C_ISR_RXNE_Msk             (0x1UL << I2C_ISR_RXNE_Pos)               /*!< 0x00000004 */
#define I2C_ISR_RXNE                 I2C_ISR_RXNE_Msk                          /*!< Receive data register not empty */
#define I2C_ISR_ADDR_Pos             (3U)
#define I2C_ISR_ADDR_Msk             (0x1UL << I2C_ISR_ADDR_Pos)               /*!< 0x00000008 */
#define I2C_ISR_ADDR                 I2C_ISR_ADDR_Msk                          /*!< Address matched (slave mode)*/
#define I2C_ISR_NACKF_Pos            (4U)
#define I2C_ISR_NACKF_Msk            (0x1UL << I2C_ISR_NACKF_Pos)              /*!< 0x00000010 */
#define I2C_ISR_NACKF                I2C_ISR_NACKF_Msk                         /*!< NACK received flag */
#define I2C_ISR_STOPF_Pos            (5U)
#define I2C_ISR_STOPF_Msk            (0x1UL << I2C_ISR_STOPF_Pos)              /*!< 0x00000020 */
#define I2C_ISR_STOPF                I2C_ISR_STOPF_Msk                         /*!< STOP detection flag */
#define I2C_ISR_TC_Pos               (6U)
#define I2C_ISR_TC_Msk               (0x1UL << I2C_ISR_TC_Pos)                 /*!< 0x00000040 */
#define I2C_ISR_TC                   I2C_ISR_TC_Msk                            /*!< Transfer complete (master mode) */
#define I2C_ISR_TCR_Pos              (7U)
#define I2C_ISR_TCR_Msk              (0x1UL << I2C_ISR_TCR_Pos)                /*!< 0x00000080 */
#define I2C_ISR_TCR                  I2C_ISR_TCR_Msk                           /*!< Transfer complete reload */
#define I2C_ISR_BERR_Pos             (8U)
#define I2C_ISR_BERR_Msk             (0x1UL << I2C_ISR_BERR_Pos)               /*!< 0x00000100 */
#define I2C_ISR_BERR                 I2C_ISR_BERR_Msk                          /*!< Bus error */
#define I2C_ISR_ARLO_Pos             (9U)
#define I2C_ISR_ARLO_Msk             (0x1UL << I2C_ISR_ARLO_Pos)               /*!< 0x00000200 */
#define I2C_ISR_ARLO                 I2C_ISR_ARLO_Msk                          /*!< Arbitration lost */
#define I2C_ISR_OVR_Pos              (10U)
#define I2C_ISR_OVR_Msk              (0x1UL << I2C_ISR_OVR_Pos)                /*!< 0x00000400 */
#define I2C_ISR_OVR                  I2C_ISR_OVR_Msk                           /*!< Overrun/Underrun */
#define I2C_ISR_PECERR_Pos           (11U)
#define I2C_ISR_PECERR_Msk           (0x1UL << I2C_ISR_PECERR_Pos)             /*!< 0x00000800 */
#define I2C_ISR_PECERR               I2C_ISR_PECERR_Msk                        /*!< PEC error in reception */
#define I2C_ISR_TIMEOUT_Pos          (12U)
#define I2C_ISR_TIMEOUT_Msk          (0x1UL << I2C_ISR_TIMEOUT_Pos)            /*!< 0x00001000 */
#define I2C_ISR_TIMEOUT              I2C_ISR_TIMEOUT_Msk                       /*!< Timeout or Tlow detection flag */
#define I2C_ISR_ALERT_Pos            (13U)
#define I2C_ISR_ALERT_Msk            (0x1UL << I2C_ISR_ALERT_Pos)              /*!< 0x00002000 */
#define I2C_ISR_ALERT                I2C_ISR_ALERT_Msk                         /*!< SMBus alert */
#define I2C_ISR_BUSY_Pos             (15U)
#define I2C_ISR_BUSY_Msk             (0x1UL << I2C_ISR_BUSY_Pos)               /*!< 0x00008000 */
#define I2C_ISR_BUSY                 I2C_ISR_BUSY_Msk                          /*!< Bus busy */
#define I2C_ISR_DIR_Pos              (16U)
#define I2C_ISR_DIR_Msk              (0x1UL << I2C_ISR_DIR_Pos)                /*!< 0x00010000 */
#define I2C_ISR_DIR                  I2C_ISR_DIR_Msk                           /*!< Transfer direction (slave mode) */
#define I2C_ISR_ADDCODE_Pos          (17U)
#define I2C_ISR_ADDCODE_Msk          (0x7FUL << I2C_ISR_ADDCODE_Pos)           /*!< 0x00FE0000 */
#define I2C_ISR_ADDCODE              I2C_ISR_ADDCODE_Msk                       /*!< Address match code (slave mode) */

/******************  Bit definition for I2C_ICR register  *********************/
#define I2C_ICR_ADDRCF_Pos           (3U)
#define I2C_ICR_ADDRCF_Msk           (0x1UL << I2C_ICR_ADDRCF_Pos)             /*!< 0x00000008 */
#define I2C_ICR_ADDRCF               I2C_ICR_ADDRCF_Msk                        /*!< Address matched clear flag */
#define I2C_ICR_NACKCF_Pos           (4U)
#define I2C_ICR_NACKCF_Msk           (0x1UL << I2C_ICR_NACKCF_Pos)             /*!< 0x00000010 */
#define I2C_ICR_NACKCF               I2C_ICR_NACKCF_Msk                        /*!< NACK clear flag */
#define I2C_ICR_STOPCF_Pos           (5U)
#define I2C_ICR_STOPCF_Msk           (0x1UL << I2C_ICR_STOPCF_Pos)             /*!< 0x00000020 */
#define I2C_ICR_STOPCF               I2C_ICR_STOPCF_Msk                        /*!< STOP detection clear flag */
#define I2C_ICR_BERRCF_Pos           (8U)
#define I2C_ICR_BERRCF_Msk           (0x1UL << I2C_ICR_BERRCF_Pos)             /*!< 0x00000100 */
#define I2C_ICR_BERRCF               I2C_ICR_BERRCF_Msk                        /*!< Bus error clear flag */
#define I2C_ICR_ARLOCF_Pos           (9U)
#define I2C_ICR_ARLOCF_Msk           (0x1UL << I2C_ICR_ARLOCF_Pos)             /*!< 0x00000200 */
#define I2C_ICR_ARLOCF               I2C_ICR_ARLOCF_Msk                        /*!< Arbitration lost clear flag */
#define I2C_ICR_OVRCF_Pos            (10U)
#define I2C_ICR_OVRCF_Msk            (0x1UL << I2C_ICR_OVRCF_Pos)              /*!< 0x00000400 */
#define I2C_ICR_OVRCF                I2C_ICR_OVRCF_Msk                         /*!< Overrun/Underrun clear flag */
#define I2C_ICR_PECCF_Pos            (11U)
#define I2C_ICR_PECCF_Msk            (0x1UL << I2C_ICR_PECCF_Pos)              /*!< 0x00000800 */
#define I2C_ICR_PECCF                I2C_ICR_PECCF_Msk                         /*!< PAC error clear flag */
#define I2C_ICR_TIMOUTCF_Pos         (12U)
#define I2C_ICR_TIMOUTCF_Msk         (0x1UL << I2C_ICR_TIMOUTCF_Pos)           /*!< 0x00001000 */
#define I2C_ICR_TIMOUTCF             I2C_ICR_TIMOUTCF_Msk                      /*!< Timeout clear flag */
#define I2C_ICR_ALERTCF_Pos          (13U)
#define I2C_ICR_ALERTCF_Msk          (0x1UL << I2C_ICR_ALERTCF_Pos)            /*!< 0x00002000 */
#define I2C_ICR_ALERTCF              I2C_ICR_ALERTCF_Msk                       /*!< Alert clear flag */

/******************  Bit definition for I2C_PECR register  *********************/
#define I2C_PECR_PEC_Pos             (0U)
#define I2C_PECR_PEC_Msk             (0xFFUL << I2C_PECR_PEC_Pos)              /*!< 0x000000FF */
#define I2C_PECR_PEC                 I2C_PECR_PEC_Msk                          /*!< PEC register */

/******************  Bit definition for I2C_RXDR register  *********************/
#define I2C_RXDR_RXDATA_Pos          (0U)
#define I2C_RXDR_RXDATA_Msk          (0xFFUL << I2C_RXDR_RXDATA_Pos)           /*!< 0x000000FF */
#define I2C_RXDR_RXDATA              I2C_RXDR_RXDATA_Msk                       /*!< 8-bit receive data */

/******************  Bit definition for I2C_TXDR register  *********************/
#define I2C_TXDR_TXDATA_Pos          (0U)
#define I2C_TXDR_TXDATA_Msk          (0xFFUL << I2C_TXDR_TXDATA_Pos)           /*!< 0x000000FF */
#define I2C_TXDR_TXDATA              I2C_TXDR_TXDATA_Msk                       /*!< 8-bit transmit data */

/******************************************************************************/
/*                                                                            */
/*                        Independent WATCHDOG (IWDG)                         */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_KR_KEY_Pos      (0U)
#define IWDG_KR_KEY_Msk      (0xFFFFUL << IWDG_KR_KEY_Pos)                     /*!< 0x0000FFFF */
#define IWDG_KR_KEY          IWDG_KR_KEY_Msk                                   /*!<Key value (write only, read 0000h)  */

/*******************  Bit definition for IWDG_PR register  ********************/
#define IWDG_PR_PR_Pos       (0U)
#define IWDG_PR_PR_Msk       (0x7UL << IWDG_PR_PR_Pos)                         /*!< 0x00000007 */
#define IWDG_PR_PR           IWDG_PR_PR_Msk                                    /*!<PR[2:0] (Prescaler divider)         */
#define IWDG_PR_PR_0         (0x1U << IWDG_PR_PR_Pos)                          /*!< 0x00000001 */
#define IWDG_PR_PR_1         (0x2U << IWDG_PR_PR_Pos)                          /*!< 0x00000002 */
#define IWDG_PR_PR_2         (0x4U << IWDG_PR_PR_Pos)                          /*!< 0x00000004 */

/*******************  Bit definition for IWDG_RLR register  *******************/
#define IWDG_RLR_RL_Pos      (0U)
#define IWDG_RLR_RL_Msk      (0xFFFUL << IWDG_RLR_RL_Pos)                      /*!< 0x00000FFF */
#define IWDG_RLR_RL          IWDG_RLR_RL_Msk                                   /*!<Watchdog counter reload value        */

/*******************  Bit definition for IWDG_SR register  ********************/
#define IWDG_SR_PVU_Pos      (0U)
#define IWDG_SR_PVU_Msk      (0x1UL << IWDG_SR_PVU_Pos)                        /*!< 0x00000001 */
#define IWDG_SR_PVU          IWDG_SR_PVU_Msk                                   /*!< Watchdog prescaler value update */
#define IWDG_SR_RVU_Pos      (1U)
#define IWDG_SR_RVU_Msk      (0x1UL << IWDG_SR_RVU_Pos)                        /*!< 0x00000002 */
#define IWDG_SR_RVU          IWDG_SR_RVU_Msk                                   /*!< Watchdog counter reload value update */
#define IWDG_SR_WVU_Pos      (2U)
#define IWDG_SR_WVU_Msk      (0x1UL << IWDG_SR_WVU_Pos)                        /*!< 0x00000004 */
#define IWDG_SR_WVU          IWDG_SR_WVU_Msk                                   /*!< Watchdog counter window value update */

/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_WINR_WIN_Pos    (0U)
#define IWDG_WINR_WIN_Msk    (0xFFFUL << IWDG_WINR_WIN_Pos)                    /*!< 0x00000FFF */
#define IWDG_WINR_WIN        IWDG_WINR_WIN_Msk                                 /*!< Watchdog counter window value */

/******************************************************************************/
/*                                                                            */
/*                               Power Control                                */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for PWR_CR1 register  ********************/
#define PWR_CR1_LPMS_Pos               (0U)
#define PWR_CR1_LPMS_Msk               (0x7UL << PWR_CR1_LPMS_Pos)             /*!< 0x00000007 */
#define PWR_CR1_LPMS                   PWR_CR1_LPMS_Msk                        /*!< Low Power Mode Selection for CPU1 */
#define PWR_CR1_LPMS_0                 (0x1U << PWR_CR1_LPMS_Pos)              /*!< 0x00000001 */
#define PWR_CR1_LPMS_1                 (0x2U << PWR_CR1_LPMS_Pos)              /*!< 0x00000002 */
#define PWR_CR1_LPMS_2                 (0x4U << PWR_CR1_LPMS_Pos)              /*!< 0x00000004 */

#define PWR_CR1_FPDR_Pos               (4U)
#define PWR_CR1_FPDR_Msk               (0x1UL << PWR_CR1_FPDR_Pos)             /*!< 0x00000010 */
#define PWR_CR1_FPDR                   PWR_CR1_FPDR_Msk                        /*!< Flash power down mode during LPrun for CPU1 */

#define PWR_CR1_FPDS_Pos               (5U)
#define PWR_CR1_FPDS_Msk               (0x1UL << PWR_CR1_FPDS_Pos)             /*!< 0x00000020 */
#define PWR_CR1_FPDS                   PWR_CR1_FPDS_Msk                        /*!< Flash power down mode during LPsleep for CPU1 */

#define PWR_CR1_DBP_Pos                (8U)
#define PWR_CR1_DBP_Msk                (0x1UL << PWR_CR1_DBP_Pos)              /*!< 0x00000100 */
#define PWR_CR1_DBP                    PWR_CR1_DBP_Msk                         /*!< Disable Backup Domain write protection */

#define PWR_CR1_LPR_Pos                (14U)
#define PWR_CR1_LPR_Msk                (0x1UL << PWR_CR1_LPR_Pos)              /*!< 0x00004000 */
#define PWR_CR1_LPR                    PWR_CR1_LPR_Msk                         /*!< Regulator Low-Power Run mode */

/********************  Bit definition for PWR_CR2 register  ********************/
#define PWR_CR2_PVDE_Pos               (0U)
#define PWR_CR2_PVDE_Msk               (0x1UL << PWR_CR2_PVDE_Pos)             /*!< 0x00000001 */
#define PWR_CR2_PVDE                   PWR_CR2_PVDE_Msk                        /*!< Power voltage detector enable */

#define PWR_CR2_PLS_Pos                (1U)
#define PWR_CR2_PLS_Msk                (0x7UL << PWR_CR2_PLS_Pos)              /*!< 0x0000000E */
#define PWR_CR2_PLS                    PWR_CR2_PLS_Msk                         /*!< Power voltage detector level selection */
#define PWR_CR2_PLS_0                  (0x1U << PWR_CR2_PLS_Pos)               /*!< 0x00000002 */
#define PWR_CR2_PLS_1                  (0x2U << PWR_CR2_PLS_Pos)               /*!< 0x00000004 */
#define PWR_CR2_PLS_2                  (0x4U << PWR_CR2_PLS_Pos)               /*!< 0x00000008 */

#define PWR_CR2_PVME_Pos               (4U)
#define PWR_CR2_PVME_Msk               (0x4UL << PWR_CR2_PVME_Pos)             /*!< 0x00000040 */
#define PWR_CR2_PVME                   PWR_CR2_PVME_Msk                        /*!< Peripherical Voltage Monitor Enable for all power domains */
#define PWR_CR2_PVME3_Pos              (6U)
#define PWR_CR2_PVME3_Msk              (0x1UL << PWR_CR2_PVME3_Pos)            /*!< 0x00000040 */
#define PWR_CR2_PVME3                  PWR_CR2_PVME3_Msk                       /*!< Peripherical Voltage Monitor Vdda Enable */

/********************  Bit definition for PWR_CR3 register  ********************/
#define PWR_CR3_EWUP_Pos               (0U)
#define PWR_CR3_EWUP_Msk               (0x09UL << PWR_CR3_EWUP_Pos)            /*!< 0x00000009 */
#define PWR_CR3_EWUP                   PWR_CR3_EWUP_Msk                        /*!< Enable all external Wake-Up lines  */
#define PWR_CR3_EWUP1_Pos              (0U)
#define PWR_CR3_EWUP1_Msk              (0x1UL << PWR_CR3_EWUP1_Pos)            /*!< 0x00000001 */
#define PWR_CR3_EWUP1                  PWR_CR3_EWUP1_Msk                       /*!< Enable external WKUP Pin 1 [line 0] */
#define PWR_CR3_EWUP4_Pos              (3U)
#define PWR_CR3_EWUP4_Msk              (0x1UL << PWR_CR3_EWUP4_Pos)            /*!< 0x00000008 */
#define PWR_CR3_EWUP4                  PWR_CR3_EWUP4_Msk                       /*!< Enable external WKUP Pin 4 [line 3] */

#define PWR_CR3_EBORHSMPSFB_Pos        (8U)
#define PWR_CR3_EBORHSMPSFB_Msk        (0x1UL << PWR_CR3_EBORHSMPSFB_Pos)      /*!< 0x00000100 */
#define PWR_CR3_EBORHSMPSFB            PWR_CR3_EBORHSMPSFB_Msk                 /*!< BORH and SMPS Step Down converter forced in Bypass interrupts for CPU1 */

#define PWR_CR3_RRS_Pos                (9U)
#define PWR_CR3_RRS_Msk                (0x1UL << PWR_CR3_RRS_Pos)              /*!< 0x00000200 */
#define PWR_CR3_RRS                    PWR_CR3_RRS_Msk                         /*!< SRAM2 retention in STANDBY mode */

#define PWR_CR3_APC_Pos                (10U)
#define PWR_CR3_APC_Msk                (0x1UL << PWR_CR3_APC_Pos)              /*!< 0x00000400 */
#define PWR_CR3_APC                    PWR_CR3_APC_Msk                         /*!< Apply pull-up and pull-down configuration for CPU1 */

#define PWR_CR3_ECRPE_Pos              (11U)
#define PWR_CR3_ECRPE_Msk              (0x1UL << PWR_CR3_ECRPE_Pos)            /*!< 0x00000800 */
#define PWR_CR3_ECRPE                  PWR_CR3_ECRPE_Msk                       /*!< Critical radio phase end of activity interrupt for CPU1 */
#define PWR_CR3_EBLEA_Pos              (12U)
#define PWR_CR3_EBLEA_Msk              (0x1UL << PWR_CR3_EBLEA_Pos)            /*!< 0x00010000 */
#define PWR_CR3_EBLEA                  PWR_CR3_EBLEA_Msk                       /*!< BLE end of activity interrupt for CPU1 */
#define PWR_CR3_EC2H_Pos               (14U)
#define PWR_CR3_EC2H_Msk               (0x1UL << PWR_CR3_EC2H_Pos)             /*!< 0x00040000 */
#define PWR_CR3_EC2H                    PWR_CR3_EC2H_Msk                       /*!< CPU2 Hold interrupt for CPU1 */

#define PWR_CR3_EIWUL_Pos              (15U)
#define PWR_CR3_EIWUL_Msk              (0x1UL << PWR_CR3_EIWUL_Pos)            /*!< 0x00080000 */
#define PWR_CR3_EIWUL                  PWR_CR3_EIWUL_Msk                       /*!< Internal Wake-Up line interrupt for CPU1 */

/********************  Bit definition for PWR_CR4 register  ********************/
#define PWR_CR4_WP_Pos                 (0U)
#define PWR_CR4_WP_Msk                 (0x09UL << PWR_CR4_WP_Pos)              /*!< 0x00000009 */
#define PWR_CR4_WP                     PWR_CR4_WP_Msk                          /*!< Wake-Up polarity for all pins */
#define PWR_CR4_WP1_Pos                (0U)
#define PWR_CR4_WP1_Msk                (0x1UL << PWR_CR4_WP1_Pos)              /*!< 0x00000001 */
#define PWR_CR4_WP1                    PWR_CR4_WP1_Msk                         /*!< Wake-Up Pin 1 [line 0] polarity */
#define PWR_CR4_WP4_Pos                (3U)
#define PWR_CR4_WP4_Msk                (0x1UL << PWR_CR4_WP4_Pos)              /*!< 0x00000008 */
#define PWR_CR4_WP4                    PWR_CR4_WP4_Msk                         /*!< Wake-Up Pin 4 [line 3] polarity */

#define PWR_CR4_VBE_Pos                (8U)
#define PWR_CR4_VBE_Msk                (0x1UL << PWR_CR4_VBE_Pos)              /*!< 0x00000100 */
#define PWR_CR4_VBE                    PWR_CR4_VBE_Msk                         /*!< VBAT battery charging enable  */
#define PWR_CR4_VBRS_Pos               (9U)
#define PWR_CR4_VBRS_Msk               (0x1UL << PWR_CR4_VBRS_Pos)             /*!< 0x00000200 */
#define PWR_CR4_VBRS                   PWR_CR4_VBRS_Msk                        /*!< VBAT battery charging resistor selection */

#define PWR_CR4_C2BOOT_Pos             (15U)
#define PWR_CR4_C2BOOT_Msk             (0x1UL << PWR_CR4_C2BOOT_Pos)           /*!< 0x00008000 */
#define PWR_CR4_C2BOOT                 PWR_CR4_C2BOOT_Msk                      /*!< Boot CPU2 after reset or wakeup from Stop or Standby modes */

/********************  Bit definition for PWR_SR1 register  ********************/
#define PWR_SR1_WUF_Pos                (0U)
#define PWR_SR1_WUF_Msk                (0x09UL << PWR_SR1_WUF_Pos)             /*!< 0x00000009 */
#define PWR_SR1_WUF                    PWR_SR1_WUF_Msk                         /*!< Wakeup Flags of all pins */
#define PWR_SR1_WUF1_Pos               (0U)
#define PWR_SR1_WUF1_Msk               (0x1UL << PWR_SR1_WUF1_Pos)             /*!< 0x00000001 */
#define PWR_SR1_WUF1                   PWR_SR1_WUF1_Msk                        /*!< Wakeup Pin 1 [Flag 0] */
#define PWR_SR1_WUF4_Pos               (3U)
#define PWR_SR1_WUF4_Msk               (0x1UL << PWR_SR1_WUF4_Pos)             /*!< 0x00000008 */
#define PWR_SR1_WUF4                   PWR_SR1_WUF4_Msk                        /*!< Wakeup Pin 4 [Flag 3] */

#define PWR_SR1_SMPSFBF_Pos            (7U)
#define PWR_SR1_SMPSFBF_Msk            (0x1UL << PWR_SR1_SMPSFBF_Pos)          /*!< 0x00000100 */
#define PWR_SR1_SMPSFBF                PWR_SR1_SMPSFBF_Msk                     /*!< SMPS Step Down converter forced in bypass mode interrupt flag */

#define PWR_SR1_BORHF_Pos              (8U)
#define PWR_SR1_BORHF_Msk              (0x1UL << PWR_SR1_BORHF_Pos)            /*!< 0x00000100 */
#define PWR_SR1_BORHF                  PWR_SR1_BORHF_Msk                       /*!< BORH interrupt flag */

#define PWR_SR1_BLEWUF_Pos             (9U)
#define PWR_SR1_BLEWUF_Msk             (0x1UL << PWR_SR1_BLEWUF_Pos)           /*!< 0x00000200 */
#define PWR_SR1_BLEWUF                 PWR_SR1_BLEWUF_Msk                      /*!< BLE wakeup interrupt flag */

#define PWR_SR1_CRPEF_Pos              (11U)
#define PWR_SR1_CRPEF_Msk              (0x1UL << PWR_SR1_CRPEF_Pos)            /*!< 0x00000800 */
#define PWR_SR1_CRPEF                  PWR_SR1_CRPEF_Msk                       /*!< Critical radio phase end of activity interrupt flag */
#define PWR_SR1_BLEAF_Pos              (12U)
#define PWR_SR1_BLEAF_Msk              (0x1UL << PWR_SR1_BLEAF_Pos)            /*!< 0x00001000 */
#define PWR_SR1_BLEAF                  PWR_SR1_BLEAF_Msk                       /*!< BLE end of activity interrupt flag */

#define PWR_SR1_C2HF_Pos               (14U)
#define PWR_SR1_C2HF_Msk               (0x1UL << PWR_SR1_C2HF_Pos)             /*!< 0x00004000 */
#define PWR_SR1_C2HF                   PWR_SR1_C2HF_Msk                        /*!< CPU2 Hold interrupt flag */

#define PWR_SR1_WUFI_Pos               (15U)
#define PWR_SR1_WUFI_Msk               (0x1UL << PWR_SR1_WUFI_Pos)             /*!< 0x00008000 */
#define PWR_SR1_WUFI                   PWR_SR1_WUFI_Msk                        /*!< Internal wakeup interrupt flag */

/********************  Bit definition for PWR_SR2 register  ********************/
#define PWR_SR2_SMPSBF_Pos             (0U)
#define PWR_SR2_SMPSBF_Msk             (0x1UL << PWR_SR2_SMPSBF_Pos)           /*!< 0x00000001 */
#define PWR_SR2_SMPSBF                 PWR_SR2_SMPSBF_Msk                      /*!< SMPS step down converter in operating mode bypass flag */
#define PWR_SR2_SMPSF_Pos              (1U)
#define PWR_SR2_SMPSF_Msk              (0x1UL << PWR_SR2_SMPSF_Pos)            /*!< 0x00000002 */
#define PWR_SR2_SMPSF                  PWR_SR2_SMPSF_Msk                       /*!< SMPS step down converter in operating mode step down flag */

#define PWR_SR2_REGLPS_Pos             (8U)
#define PWR_SR2_REGLPS_Msk             (0x1UL << PWR_SR2_REGLPS_Pos)           /*!< 0x00000100 */
#define PWR_SR2_REGLPS                 PWR_SR2_REGLPS_Msk                      /*!< Low-power regulator started */
#define PWR_SR2_REGLPF_Pos             (9U)
#define PWR_SR2_REGLPF_Msk             (0x1UL << PWR_SR2_REGLPF_Pos)           /*!< 0x00000200 */
#define PWR_SR2_REGLPF                 PWR_SR2_REGLPF_Msk                      /*!< Low-power regulator flag */

#define PWR_SR2_PVDO_Pos               (11U)
#define PWR_SR2_PVDO_Msk               (0x1UL << PWR_SR2_PVDO_Pos)             /*!< 0x00000800 */
#define PWR_SR2_PVDO                   PWR_SR2_PVDO_Msk                        /*!< Power voltage detector output */

#define PWR_SR2_PVMO3_Pos              (14U)
#define PWR_SR2_PVMO3_Msk              (0x1UL << PWR_SR2_PVMO3_Pos)            /*!< 0x00004000 */
#define PWR_SR2_PVMO3                  PWR_SR2_PVMO3_Msk                       /*!< Peripheral voltage monitor output 3: VDDA vs. 1.62V */

/********************  Bit definition for PWR_SCR register  ********************/
#define PWR_SCR_CWUF_Pos               (0U)
#define PWR_SCR_CWUF_Msk               (0x09UL << PWR_SCR_CWUF_Pos)            /*!< 0x00000009 */
#define PWR_SCR_CWUF                   PWR_SCR_CWUF_Msk                        /*!< Clear Wake-up Flags for all pins */
#define PWR_SCR_CWUF1_Pos              (0U)
#define PWR_SCR_CWUF1_Msk              (0x1UL << PWR_SCR_CWUF1_Pos)            /*!< 0x00000001 */
#define PWR_SCR_CWUF1                  PWR_SCR_CWUF1_Msk                       /*!< Clear Wake-up Pin 1 [Flag 0] */
#define PWR_SCR_CWUF4_Pos              (3U)
#define PWR_SCR_CWUF4_Msk              (0x1UL << PWR_SCR_CWUF4_Pos)            /*!< 0x00000008 */
#define PWR_SCR_CWUF4                  PWR_SCR_CWUF4_Msk                       /*!< Clear Wake-up Pin 4 [Flag 3] */

#define PWR_SCR_CSMPSFBF_Pos           (7U)
#define PWR_SCR_CSMPSFBF_Msk           (0x1UL << PWR_SCR_CSMPSFBF_Pos)         /*!< 0x00000080 */
#define PWR_SCR_CSMPSFBF               PWR_SCR_CSMPSFBF_Msk                    /*!< Clear SMPS Step Down converter forced in bypass mode interrupt flag  */

#define PWR_SCR_CBORHF_Pos             (8U)
#define PWR_SCR_CBORHF_Msk             (0x1UL << PWR_SCR_CBORHF_Pos)           /*!< 0x00000100 */
#define PWR_SCR_CBORHF                 PWR_SCR_CBORHF_Msk                      /*!< Clear BORH interrupt flag  */

#define PWR_SCR_CBLEWUF_Pos            (9U)
#define PWR_SCR_CBLEWUF_Msk            (0x1UL << PWR_SCR_CBLEWUF_Pos)          /*!< 0x00000200 */
#define PWR_SCR_CBLEWUF                PWR_SCR_CBLEWUF_Msk                     /*!< Clear BLE wakeup interrupt flag */

#define PWR_SCR_CCRPEF_Pos             (11U)
#define PWR_SCR_CCRPEF_Msk             (0x1UL << PWR_SCR_CCRPEF_Pos)           /*!< 0x00000800 */
#define PWR_SCR_CCRPEF                 PWR_SCR_CCRPEF_Msk                      /*!< Clear Critical radio phase end of activity interrupt flag */
#define PWR_SCR_CBLEAF_Pos             (12U)
#define PWR_SCR_CBLEAF_Msk             (0x1UL << PWR_SCR_CBLEAF_Pos)           /*!< 0x00001000 */
#define PWR_SCR_CBLEAF                 PWR_SCR_CBLEAF_Msk                      /*!< Clear BLE end of activity interrupt flag */

#define PWR_SCR_CC2HF_Pos              (14U)
#define PWR_SCR_CC2HF_Msk              (0x1UL << PWR_SCR_CC2HF_Pos)            /*!< 0x00004000 */
#define PWR_SCR_CC2HF                  PWR_SCR_CC2HF_Msk                       /*!< Clear CPU2 Hold interrupt flag */

/********************  Bit definition for PWR_CR5 register  ********************/
#define PWR_CR5_SMPSVOS_Pos            (0U)
#define PWR_CR5_SMPSVOS_Msk            (0xFUL << PWR_CR5_SMPSVOS_Pos)          /*!< 0x0000000F */
#define PWR_CR5_SMPSVOS                PWR_CR5_SMPSVOS_Msk                     /*!< SMPS step down converter voltage output scaling voltage level */
#define PWR_CR5_SMPSVOS_0              (0x01U << PWR_CR5_SMPSVOS_Pos)          /*!< 0x00000001 */
#define PWR_CR5_SMPSVOS_1              (0x02U << PWR_CR5_SMPSVOS_Pos)          /*!< 0x00000002 */
#define PWR_CR5_SMPSVOS_2              (0x04U << PWR_CR5_SMPSVOS_Pos)          /*!< 0x00000004 */
#define PWR_CR5_SMPSVOS_3              (0x08U << PWR_CR5_SMPSVOS_Pos)          /*!< 0x00000008 */

#define PWR_CR5_SMPSSC_Pos             (4U)
#define PWR_CR5_SMPSSC_Msk             (0x7UL << PWR_CR5_SMPSSC_Pos)           /*!< 0x00000070 */
#define PWR_CR5_SMPSSC                 PWR_CR5_SMPSSC_Msk                      /*!< SMPS step down converter supply startup current selection */
#define PWR_CR5_SMPSSC_0               (0x01U << PWR_CR5_SMPSSC_Pos)           /*!< 0x00000010 */
#define PWR_CR5_SMPSSC_1               (0x02U << PWR_CR5_SMPSSC_Pos)           /*!< 0x00000020 */
#define PWR_CR5_SMPSSC_2               (0x04U << PWR_CR5_SMPSSC_Pos)           /*!< 0x00000040 */

#define PWR_CR5_BORHC_Pos              (8U)
#define PWR_CR5_BORHC_Msk              (0x1UL << PWR_CR5_BORHC_Pos)            /*!< 0x00000100 */
#define PWR_CR5_BORHC                  PWR_CR5_BORHC_Msk                       /*!< BORH configuration selection */

#define PWR_CR5_SMPSEN_Pos             (15U)
#define PWR_CR5_SMPSEN_Msk             (0x1UL << PWR_CR5_SMPSEN_Pos)           /*!< 0x00008000 */
#define PWR_CR5_SMPSEN                 PWR_CR5_SMPSEN_Msk                      /*!< Enable SMPS Step Down converter SMPS mode enable */

/********************  Bit definition for PWR_PUCRA register  *****************/
#define PWR_PUCRA_PA0_Pos              (0U)
#define PWR_PUCRA_PA0_Msk              (0x1UL << PWR_PUCRA_PA0_Pos)            /*!< 0x00000001 */
#define PWR_PUCRA_PA0                  PWR_PUCRA_PA0_Msk                       /*!< Pin PA0 Pull-Up set */
#define PWR_PUCRA_PA1_Pos              (1U)
#define PWR_PUCRA_PA1_Msk              (0x1UL << PWR_PUCRA_PA1_Pos)            /*!< 0x00000002 */
#define PWR_PUCRA_PA1                  PWR_PUCRA_PA1_Msk                       /*!< Pin PA1 Pull-Up set */
#define PWR_PUCRA_PA2_Pos              (2U)
#define PWR_PUCRA_PA2_Msk              (0x1UL << PWR_PUCRA_PA2_Pos)            /*!< 0x00000004 */
#define PWR_PUCRA_PA2                  PWR_PUCRA_PA2_Msk                       /*!< Pin PA2 Pull-Up set */
#define PWR_PUCRA_PA3_Pos              (3U)
#define PWR_PUCRA_PA3_Msk              (0x1UL << PWR_PUCRA_PA3_Pos)            /*!< 0x00000008 */
#define PWR_PUCRA_PA3                  PWR_PUCRA_PA3_Msk                       /*!< Pin PA3 Pull-Up set */
#define PWR_PUCRA_PA4_Pos              (4U)
#define PWR_PUCRA_PA4_Msk              (0x1UL << PWR_PUCRA_PA4_Pos)            /*!< 0x00000010 */
#define PWR_PUCRA_PA4                  PWR_PUCRA_PA4_Msk                       /*!< Pin PA4 Pull-Up set */
#define PWR_PUCRA_PA5_Pos              (5U)
#define PWR_PUCRA_PA5_Msk              (0x1UL << PWR_PUCRA_PA5_Pos)            /*!< 0x00000020 */
#define PWR_PUCRA_PA5                  PWR_PUCRA_PA5_Msk                       /*!< Pin PA5 Pull-Up set */
#define PWR_PUCRA_PA6_Pos              (6U)
#define PWR_PUCRA_PA6_Msk              (0x1UL << PWR_PUCRA_PA6_Pos)            /*!< 0x00000040 */
#define PWR_PUCRA_PA6                  PWR_PUCRA_PA6_Msk                       /*!< Pin PA6 Pull-Up set */
#define PWR_PUCRA_PA7_Pos              (7U)
#define PWR_PUCRA_PA7_Msk              (0x1UL << PWR_PUCRA_PA7_Pos)            /*!< 0x00000080 */
#define PWR_PUCRA_PA7                  PWR_PUCRA_PA7_Msk                       /*!< Pin PA7 Pull-Up set */
#define PWR_PUCRA_PA8_Pos              (8U)
#define PWR_PUCRA_PA8_Msk              (0x1UL << PWR_PUCRA_PA8_Pos)            /*!< 0x00000100 */
#define PWR_PUCRA_PA8                  PWR_PUCRA_PA8_Msk                       /*!< Pin PA8 Pull-Up set */
#define PWR_PUCRA_PA9_Pos              (9U)
#define PWR_PUCRA_PA9_Msk              (0x1UL << PWR_PUCRA_PA9_Pos)            /*!< 0x00000200 */
#define PWR_PUCRA_PA9                  PWR_PUCRA_PA9_Msk                       /*!< Pin PA9 Pull-Up set */
#define PWR_PUCRA_PA10_Pos             (10U)
#define PWR_PUCRA_PA10_Msk             (0x1UL << PWR_PUCRA_PA10_Pos)           /*!< 0x00000400 */
#define PWR_PUCRA_PA10                 PWR_PUCRA_PA10_Msk                      /*!< Pin PA10 Pull-Up set */
#define PWR_PUCRA_PA11_Pos             (11U)
#define PWR_PUCRA_PA11_Msk             (0x1UL << PWR_PUCRA_PA11_Pos)           /*!< 0x00000800 */
#define PWR_PUCRA_PA11                 PWR_PUCRA_PA11_Msk                      /*!< Pin PA11 Pull-Up set */
#define PWR_PUCRA_PA12_Pos             (12U)
#define PWR_PUCRA_PA12_Msk             (0x1UL << PWR_PUCRA_PA12_Pos)           /*!< 0x00001000 */
#define PWR_PUCRA_PA12                 PWR_PUCRA_PA12_Msk                      /*!< Pin PA12 Pull-Up set */
#define PWR_PUCRA_PA13_Pos             (13U)
#define PWR_PUCRA_PA13_Msk             (0x1UL << PWR_PUCRA_PA13_Pos)           /*!< 0x00002000 */
#define PWR_PUCRA_PA13                 PWR_PUCRA_PA13_Msk                      /*!< Pin PA13 Pull-Up set */
#define PWR_PUCRA_PA15_Pos             (15U)
#define PWR_PUCRA_PA15_Msk             (0x1UL << PWR_PUCRA_PA15_Pos)           /*!< 0x00008000 */
#define PWR_PUCRA_PA15                 PWR_PUCRA_PA15_Msk                      /*!< Pin PA15 Pull-Up set */

/********************  Bit definition for PWR_PDCRA register  *****************/
#define PWR_PDCRA_PA0_Pos              (0U)
#define PWR_PDCRA_PA0_Msk              (0x1UL << PWR_PDCRA_PA0_Pos)            /*!< 0x00000001 */
#define PWR_PDCRA_PA0                  PWR_PDCRA_PA0_Msk                       /*!< Pin PA0 Pull-Down set */
#define PWR_PDCRA_PA1_Pos              (1U)
#define PWR_PDCRA_PA1_Msk              (0x1UL << PWR_PDCRA_PA1_Pos)            /*!< 0x00000002 */
#define PWR_PDCRA_PA1                  PWR_PDCRA_PA1_Msk                       /*!< Pin PA1 Pull-Down set */
#define PWR_PDCRA_PA2_Pos              (2U)
#define PWR_PDCRA_PA2_Msk              (0x1UL << PWR_PDCRA_PA2_Pos)            /*!< 0x00000004 */
#define PWR_PDCRA_PA2                  PWR_PDCRA_PA2_Msk                       /*!< Pin PA2 Pull-Down set */
#define PWR_PDCRA_PA3_Pos              (3U)
#define PWR_PDCRA_PA3_Msk              (0x1UL << PWR_PDCRA_PA3_Pos)            /*!< 0x00000008 */
#define PWR_PDCRA_PA3                  PWR_PDCRA_PA3_Msk                       /*!< Pin PA3 Pull-Down set */
#define PWR_PDCRA_PA4_Pos              (4U)
#define PWR_PDCRA_PA4_Msk              (0x1UL << PWR_PDCRA_PA4_Pos)            /*!< 0x00000010 */
#define PWR_PDCRA_PA4                  PWR_PDCRA_PA4_Msk                       /*!< Pin PA4 Pull-Down set */
#define PWR_PDCRA_PA5_Pos              (5U)
#define PWR_PDCRA_PA5_Msk              (0x1UL << PWR_PDCRA_PA5_Pos)            /*!< 0x00000020 */
#define PWR_PDCRA_PA5                  PWR_PDCRA_PA5_Msk                       /*!< Pin PA5 Pull-Down set */
#define PWR_PDCRA_PA6_Pos              (6U)
#define PWR_PDCRA_PA6_Msk              (0x1UL << PWR_PDCRA_PA6_Pos)            /*!< 0x00000040 */
#define PWR_PDCRA_PA6                  PWR_PDCRA_PA6_Msk                       /*!< Pin PA6 Pull-Down set */
#define PWR_PDCRA_PA7_Pos              (7U)
#define PWR_PDCRA_PA7_Msk              (0x1UL << PWR_PDCRA_PA7_Pos)            /*!< 0x00000080 */
#define PWR_PDCRA_PA7                  PWR_PDCRA_PA7_Msk                       /*!< Pin PA7 Pull-Down set */
#define PWR_PDCRA_PA8_Pos              (8U)
#define PWR_PDCRA_PA8_Msk              (0x1UL << PWR_PDCRA_PA8_Pos)            /*!< 0x00000100 */
#define PWR_PDCRA_PA8                  PWR_PDCRA_PA8_Msk                       /*!< Pin PA8 Pull-Down set */
#define PWR_PDCRA_PA9_Pos              (9U)
#define PWR_PDCRA_PA9_Msk              (0x1UL << PWR_PDCRA_PA9_Pos)            /*!< 0x00000200 */
#define PWR_PDCRA_PA9                  PWR_PDCRA_PA9_Msk                       /*!< Pin PA9 Pull-Down set */
#define PWR_PDCRA_PA10_Pos             (10U)
#define PWR_PDCRA_PA10_Msk             (0x1UL << PWR_PDCRA_PA10_Pos)           /*!< 0x00000400 */
#define PWR_PDCRA_PA10                 PWR_PDCRA_PA10_Msk                      /*!< Pin PA10 Pull-Down set */
#define PWR_PDCRA_PA11_Pos             (11U)
#define PWR_PDCRA_PA11_Msk             (0x1UL << PWR_PDCRA_PA11_Pos)           /*!< 0x00000800 */
#define PWR_PDCRA_PA11                 PWR_PDCRA_PA11_Msk                      /*!< Pin PA11 Pull-Down set */
#define PWR_PDCRA_PA12_Pos             (12U)
#define PWR_PDCRA_PA12_Msk             (0x1UL << PWR_PDCRA_PA12_Pos)           /*!< 0x00001000 */
#define PWR_PDCRA_PA12                 PWR_PDCRA_PA12_Msk                      /*!< Pin PA12 Pull-Down set */
#define PWR_PDCRA_PA14_Pos             (14U)
#define PWR_PDCRA_PA14_Msk             (0x1UL << PWR_PDCRA_PA14_Pos)           /*!< 0x00004000 */
#define PWR_PDCRA_PA14                 PWR_PDCRA_PA14_Msk                      /*!< Pin PA14 Pull-Down set */

/********************  Bit definition for PWR_PUCRB register  *****************/
#define PWR_PUCRB_PB0_Pos              (0U)
#define PWR_PUCRB_PB0_Msk              (0x1UL << PWR_PUCRB_PB0_Pos)            /*!< 0x00000001 */
#define PWR_PUCRB_PB0                  PWR_PUCRB_PB0_Msk                       /*!< Pin PB0 Pull-Up set */
#define PWR_PUCRB_PB1_Pos              (1U)
#define PWR_PUCRB_PB1_Msk              (0x1UL << PWR_PUCRB_PB1_Pos)            /*!< 0x00000002 */
#define PWR_PUCRB_PB1                  PWR_PUCRB_PB1_Msk                       /*!< Pin PB1 Pull-Up set */
#define PWR_PUCRB_PB2_Pos              (2U)
#define PWR_PUCRB_PB2_Msk              (0x1UL << PWR_PUCRB_PB2_Pos)            /*!< 0x00000004 */
#define PWR_PUCRB_PB2                  PWR_PUCRB_PB2_Msk                       /*!< Pin PB2 Pull-Up set */
#define PWR_PUCRB_PB3_Pos              (3U)
#define PWR_PUCRB_PB3_Msk              (0x1UL << PWR_PUCRB_PB3_Pos)            /*!< 0x00000008 */
#define PWR_PUCRB_PB3                  PWR_PUCRB_PB3_Msk                       /*!< Pin PB3 Pull-Up set */
#define PWR_PUCRB_PB4_Pos              (4U)
#define PWR_PUCRB_PB4_Msk              (0x1UL << PWR_PUCRB_PB4_Pos)            /*!< 0x00000010 */
#define PWR_PUCRB_PB4                  PWR_PUCRB_PB4_Msk                       /*!< Pin PB4 Pull-Up set */
#define PWR_PUCRB_PB5_Pos              (5U)
#define PWR_PUCRB_PB5_Msk              (0x1UL << PWR_PUCRB_PB5_Pos)            /*!< 0x00000020 */
#define PWR_PUCRB_PB5                  PWR_PUCRB_PB5_Msk                       /*!< Pin PB5 Pull-Up set */
#define PWR_PUCRB_PB6_Pos              (6U)
#define PWR_PUCRB_PB6_Msk              (0x1UL << PWR_PUCRB_PB6_Pos)            /*!< 0x00000040 */
#define PWR_PUCRB_PB6                  PWR_PUCRB_PB6_Msk                       /*!< Pin PB6 Pull-Up set */
#define PWR_PUCRB_PB7_Pos              (7U)
#define PWR_PUCRB_PB7_Msk              (0x1UL << PWR_PUCRB_PB7_Pos)            /*!< 0x00000080 */
#define PWR_PUCRB_PB7                  PWR_PUCRB_PB7_Msk                       /*!< Pin PB7 Pull-Up set */
#define PWR_PUCRB_PB8_Pos              (8U)
#define PWR_PUCRB_PB8_Msk              (0x1UL << PWR_PUCRB_PB8_Pos)            /*!< 0x00000100 */
#define PWR_PUCRB_PB8                  PWR_PUCRB_PB8_Msk                       /*!< Pin PB8 Pull-Up set */
#define PWR_PUCRB_PB9_Pos              (9U)
#define PWR_PUCRB_PB9_Msk              (0x1UL << PWR_PUCRB_PB9_Pos)            /*!< 0x00000200 */
#define PWR_PUCRB_PB9                  PWR_PUCRB_PB9_Msk                       /*!< Pin PB9 Pull-Up set */

/********************  Bit definition for PWR_PDCRB register  *****************/
#define PWR_PDCRB_PB0_Pos              (0U)
#define PWR_PDCRB_PB0_Msk              (0x1UL << PWR_PDCRB_PB0_Pos)            /*!< 0x00000001 */
#define PWR_PDCRB_PB0                  PWR_PDCRB_PB0_Msk                       /*!< Pin PB0 Pull-Down set */
#define PWR_PDCRB_PB1_Pos              (1U)
#define PWR_PDCRB_PB1_Msk              (0x1UL << PWR_PDCRB_PB1_Pos)            /*!< 0x00000002 */
#define PWR_PDCRB_PB1                  PWR_PDCRB_PB1_Msk                       /*!< Pin PB1 Pull-Down set */
#define PWR_PDCRB_PB2_Pos              (2U)
#define PWR_PDCRB_PB2_Msk              (0x1UL << PWR_PDCRB_PB2_Pos)            /*!< 0x00000004 */
#define PWR_PDCRB_PB2                  PWR_PDCRB_PB2_Msk                       /*!< Pin PB2 Pull-Down set */
#define PWR_PDCRB_PB3_Pos              (3U)
#define PWR_PDCRB_PB3_Msk              (0x1UL << PWR_PDCRB_PB3_Pos)            /*!< 0x00000008 */
#define PWR_PDCRB_PB3                  PWR_PDCRB_PB3_Msk                       /*!< Pin PB3 Pull-Down set */
#define PWR_PDCRB_PB5_Pos              (5U)
#define PWR_PDCRB_PB5_Msk              (0x1UL << PWR_PDCRB_PB5_Pos)            /*!< 0x00000020 */
#define PWR_PDCRB_PB5                  PWR_PDCRB_PB5_Msk                       /*!< Pin PB5 Pull-Down set */
#define PWR_PDCRB_PB6_Pos              (6U)
#define PWR_PDCRB_PB6_Msk              (0x1UL << PWR_PDCRB_PB6_Pos)            /*!< 0x00000040 */
#define PWR_PDCRB_PB6                  PWR_PDCRB_PB6_Msk                       /*!< Pin PB6 Pull-Down set */
#define PWR_PDCRB_PB7_Pos              (7U)
#define PWR_PDCRB_PB7_Msk              (0x1UL << PWR_PDCRB_PB7_Pos)            /*!< 0x00000080 */
#define PWR_PDCRB_PB7                  PWR_PDCRB_PB7_Msk                       /*!< Pin PB7 Pull-Down set */
#define PWR_PDCRB_PB8_Pos              (8U)
#define PWR_PDCRB_PB8_Msk              (0x1UL << PWR_PDCRB_PB8_Pos)            /*!< 0x00000100 */
#define PWR_PDCRB_PB8                  PWR_PDCRB_PB8_Msk                       /*!< Pin PB8 Pull-Down set */
#define PWR_PDCRB_PB9_Pos              (9U)
#define PWR_PDCRB_PB9_Msk              (0x1UL << PWR_PDCRB_PB9_Pos)            /*!< 0x00000200 */
#define PWR_PDCRB_PB9                  PWR_PDCRB_PB9_Msk                       /*!< Pin PB9 Pull-Down set */

/********************  Bit definition for PWR_PUCRC register  *****************/
#define PWR_PUCRC_PC14_Pos             (14U)
#define PWR_PUCRC_PC14_Msk             (0x1UL << PWR_PUCRC_PC14_Pos)           /*!< 0x00004000 */
#define PWR_PUCRC_PC14                 PWR_PUCRC_PC14_Msk                      /*!< Pin PC14 Pull-Up set */
#define PWR_PUCRC_PC15_Pos             (15U)
#define PWR_PUCRC_PC15_Msk             (0x1UL << PWR_PUCRC_PC15_Pos)           /*!< 0x00008000 */
#define PWR_PUCRC_PC15                 PWR_PUCRC_PC15_Msk                      /*!< Pin PC15 Pull-Up set */

/********************  Bit definition for PWR_PDCRC register  *****************/
#define PWR_PDCRC_PC14_Pos             (14U)
#define PWR_PDCRC_PC14_Msk             (0x1UL << PWR_PDCRC_PC14_Pos)           /*!< 0x00004000 */
#define PWR_PDCRC_PC14                 PWR_PDCRC_PC14_Msk                      /*!< Pin PC14 Pull-Down set */
#define PWR_PDCRC_PC15_Pos             (15U)
#define PWR_PDCRC_PC15_Msk             (0x1UL << PWR_PDCRC_PC15_Pos)           /*!< 0x00008000 */
#define PWR_PDCRC_PC15                 PWR_PDCRC_PC15_Msk                      /*!< Pin PC15 Pull-Down set */

/********************  Bit definition for PWR_PUCRE register  *****************/
#define PWR_PUCRE_PE4_Pos              (4U)
#define PWR_PUCRE_PE4_Msk              (0x1UL << PWR_PUCRE_PE4_Pos)            /*!< 0x00000010 */
#define PWR_PUCRE_PE4                  PWR_PUCRE_PE4_Msk                       /*!< Pin PE4 Pull-Up set */

/********************  Bit definition for PWR_PDCRE register  *****************/
#define PWR_PDCRE_PE4_Pos              (4U)
#define PWR_PDCRE_PE4_Msk              (0x1UL << PWR_PDCRE_PE4_Pos)            /*!< 0x00000010 */
#define PWR_PDCRE_PE4                  PWR_PDCRE_PE4_Msk                       /*!< Pin PE4 Pull-Down set */

/********************  Bit definition for PWR_PUCRH register  *****************/
#define PWR_PUCRH_PH3_Pos              (3U)
#define PWR_PUCRH_PH3_Msk              (0x1UL << PWR_PUCRH_PH3_Pos)            /*!< 0x00000004 */
#define PWR_PUCRH_PH3                  PWR_PUCRH_PH3_Msk                       /*!< Pin PH3 Pull-Up set */

/********************  Bit definition for PWR_PDCRH register  *****************/
#define PWR_PDCRH_PH3_Pos              (3U)
#define PWR_PDCRH_PH3_Msk              (0x1UL << PWR_PDCRH_PH3_Pos)            /*!< 0x00000004 */
#define PWR_PDCRH_PH3                  PWR_PDCRH_PH3_Msk                       /*!< Pin PH3 Pull-Down set */

/********************  Bit definition for PWR_C2CR1 register  ********************/
#define PWR_C2CR1_LPMS_Pos             (0U)
#define PWR_C2CR1_LPMS_Msk             (0x7UL << PWR_C2CR1_LPMS_Pos)           /*!< 0x00000007 */
#define PWR_C2CR1_LPMS                 PWR_C2CR1_LPMS_Msk                      /*!< Low Power Mode Selection for CPU2 */
#define PWR_C2CR1_LPMS_0               (0x1U << PWR_C2CR1_LPMS_Pos)            /*!< 0x00000001 */
#define PWR_C2CR1_LPMS_1               (0x2U << PWR_C2CR1_LPMS_Pos)            /*!< 0x00000002 */
#define PWR_C2CR1_LPMS_2               (0x4U << PWR_C2CR1_LPMS_Pos)            /*!< 0x00000004 */

#define PWR_C2CR1_FPDR_Pos             (4U)
#define PWR_C2CR1_FPDR_Msk             (0x1UL << PWR_C2CR1_FPDR_Pos)           /*!< 0x00000010 */
#define PWR_C2CR1_FPDR                 PWR_C2CR1_FPDR_Msk                      /*!< Flash power down mode during LPrun for CPU2 */

#define PWR_C2CR1_FPDS_Pos             (5U)
#define PWR_C2CR1_FPDS_Msk             (0x1UL << PWR_C2CR1_FPDS_Pos)           /*!< 0x00000020 */
#define PWR_C2CR1_FPDS                 PWR_C2CR1_FPDS_Msk                      /*!< Flash power down mode during LPsleep for CPU2 */

#define PWR_C2CR1_BLEEWKUP_Pos         (14U)
#define PWR_C2CR1_BLEEWKUP_Msk         (0x1UL << PWR_C2CR1_BLEEWKUP_Pos)       /*!< 0x00008000 */
#define PWR_C2CR1_BLEEWKUP             PWR_C2CR1_BLEEWKUP_Msk                  /*!< Radio BLE external wakeup signal */

/********************  Bit definition for PWR_C2CR3 register  ********************/
#define PWR_C2CR3_EWUP_Pos             (0U)
#define PWR_C2CR3_EWUP_Msk             (0x09UL << PWR_C2CR3_EWUP_Pos)           /*!< 0x00000009 */
#define PWR_C2CR3_EWUP                 PWR_C2CR3_EWUP_Msk                       /*!< Enable all external Wake-Up lines for CPU2 */
#define PWR_C2CR3_EWUP1_Pos            (0U)
#define PWR_C2CR3_EWUP1_Msk            (0x1UL << PWR_C2CR3_EWUP1_Pos)           /*!< 0x00000001 */
#define PWR_C2CR3_EWUP1                PWR_C2CR3_EWUP1_Msk                      /*!< Enable external WKUP Pin 1 [line 0] for CPU2 */
#define PWR_C2CR3_EWUP4_Pos            (3U)
#define PWR_C2CR3_EWUP4_Msk            (0x1UL << PWR_C2CR3_EWUP4_Pos)           /*!< 0x00000008 */
#define PWR_C2CR3_EWUP4                PWR_C2CR3_EWUP4_Msk                      /*!< Enable external WKUP Pin 4 [line 3] for CPU2 */

#define PWR_C2CR3_EBLEWUP_Pos          (9U)
#define PWR_C2CR3_EBLEWUP_Msk          (0x1UL << PWR_C2CR3_EBLEWUP_Pos)       /*!< 0x00000200 */
#define PWR_C2CR3_EBLEWUP              PWR_C2CR3_EBLEWUP_Msk                 /*!< Enable BLE host wakeup interrupt for CPU2 */

#define PWR_C2CR3_APC_Pos              (12U)
#define PWR_C2CR3_APC_Msk              (0x1UL << PWR_C2CR3_APC_Pos)            /*!< 0x00001000 */
#define PWR_C2CR3_APC                  PWR_C2CR3_APC_Msk                       /*!< Apply pull-up and pull-down configuration for CPU2 */

#define PWR_C2CR3_EIWUL_Pos            (15U)
#define PWR_C2CR3_EIWUL_Msk            (0x1UL << PWR_C2CR3_EIWUL_Pos)          /*!< 0x00008000 */
#define PWR_C2CR3_EIWUL                PWR_C2CR3_EIWUL_Msk                     /*!< Internal Wake-Up line interrupt for CPU2 */

/********************  Bit definition for PWR_EXTSCR register  ********************/
#define PWR_EXTSCR_C1CSSF_Pos          (0U)
#define PWR_EXTSCR_C1CSSF_Msk          (0x1UL << PWR_EXTSCR_C1CSSF_Pos)        /*!< 0x00000001 */
#define PWR_EXTSCR_C1CSSF              PWR_EXTSCR_C1CSSF_Msk                   /*!< Clear standby and stop flags for CPU1 */
#define PWR_EXTSCR_C2CSSF_Pos          (1U)
#define PWR_EXTSCR_C2CSSF_Msk          (0x1UL << PWR_EXTSCR_C2CSSF_Pos)        /*!< 0x00000002 */
#define PWR_EXTSCR_C2CSSF              PWR_EXTSCR_C2CSSF_Msk                   /*!< Clear standby and stop flags for CPU2 */
#define PWR_EXTSCR_CCRPF_Pos           (2U)
#define PWR_EXTSCR_CCRPF_Msk           (0x1UL << PWR_EXTSCR_CCRPF_Pos)         /*!< 0x00000004 */
#define PWR_EXTSCR_CCRPF               PWR_EXTSCR_CCRPF_Msk                    /*!< Clear critical radio system phase flag */

#define PWR_EXTSCR_C1SBF_Pos           (8U)
#define PWR_EXTSCR_C1SBF_Msk           (0x1UL << PWR_EXTSCR_C1SBF_Pos)         /*!< 0x00000100 */
#define PWR_EXTSCR_C1SBF               PWR_EXTSCR_C1SBF_Msk                    /*!< System standby flag for CPU1 */
#define PWR_EXTSCR_C1STOPF_Pos         (9U)
#define PWR_EXTSCR_C1STOPF_Msk         (0x1UL << PWR_EXTSCR_C1STOPF_Pos)       /*!< 0x00000200 */
#define PWR_EXTSCR_C1STOPF             PWR_EXTSCR_C1STOPF_Msk                  /*!< System stop flag for CPU1 */
#define PWR_EXTSCR_C2SBF_Pos           (10U)
#define PWR_EXTSCR_C2SBF_Msk           (0x1UL << PWR_EXTSCR_C2SBF_Pos)         /*!< 0x00000400 */
#define PWR_EXTSCR_C2SBF               PWR_EXTSCR_C2SBF_Msk                    /*!< System standby flag for CPU2 */
#define PWR_EXTSCR_C2STOPF_Pos         (11U)
#define PWR_EXTSCR_C2STOPF_Msk         (0x1UL << PWR_EXTSCR_C2STOPF_Pos)       /*!< 0x00000800 */
#define PWR_EXTSCR_C2STOPF             PWR_EXTSCR_C2STOPF_Msk                  /*!< System stop flag for CPU2 */

#define PWR_EXTSCR_CRPF_Pos            (13U)
#define PWR_EXTSCR_CRPF_Msk            (0x1UL << PWR_EXTSCR_CRPF_Pos)          /*!< 0x00002000 */
#define PWR_EXTSCR_CRPF                PWR_EXTSCR_CRPF_Msk                     /*!< Critical radio system phase flag */

#define PWR_EXTSCR_C1DS_Pos            (14U)
#define PWR_EXTSCR_C1DS_Msk            (0x1UL << PWR_EXTSCR_C1DS_Pos)          /*!< 0x00004000 */
#define PWR_EXTSCR_C1DS                PWR_EXTSCR_C1DS_Msk                     /*!< CPU1 deepsleep mode flag */
#define PWR_EXTSCR_C2DS_Pos            (15U)
#define PWR_EXTSCR_C2DS_Msk            (0x1UL << PWR_EXTSCR_C2DS_Pos)          /*!< 0x00008000 */
#define PWR_EXTSCR_C2DS                PWR_EXTSCR_C2DS_Msk                     /*!< CPU2 deepsleep mode flag */

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/*
  * @brief Specific device feature definitions
  */
#define RCC_SMPS_SUPPORT

/********************  Bit definition for RCC_CR register  *****************/
#define RCC_CR_MSION_Pos                     (0U)
#define RCC_CR_MSION_Msk                     (0x1UL << RCC_CR_MSION_Pos)       /*!< 0x00000001 */
#define RCC_CR_MSION                         RCC_CR_MSION_Msk                  /*!< Internal Multi Speed oscillator (MSI) clock enable */
#define RCC_CR_MSIRDY_Pos                    (1U)
#define RCC_CR_MSIRDY_Msk                    (0x1UL << RCC_CR_MSIRDY_Pos)      /*!< 0x00000002 */
#define RCC_CR_MSIRDY                        RCC_CR_MSIRDY_Msk                 /*!< Internal Multi Speed oscillator (MSI) clock ready flag */
#define RCC_CR_MSIPLLEN_Pos                  (2U)
#define RCC_CR_MSIPLLEN_Msk                  (0x1UL << RCC_CR_MSIPLLEN_Pos)    /*!< 0x00000004 */
#define RCC_CR_MSIPLLEN                      RCC_CR_MSIPLLEN_Msk               /*!< Internal Multi Speed oscillator (MSI) PLL enable */

/*!< MSIRANGE configuration : 12 frequency ranges available */
#define RCC_CR_MSIRANGE_Pos                  (4U)
#define RCC_CR_MSIRANGE_Msk                  (0xFUL << RCC_CR_MSIRANGE_Pos)    /*!< 0x000000F0 */
#define RCC_CR_MSIRANGE                      RCC_CR_MSIRANGE_Msk               /*!< Internal Multi Speed oscillator (MSI) clock Range */
#define RCC_CR_MSIRANGE_0                    (0x0U << RCC_CR_MSIRANGE_Pos)     /*!< 0x00000000 */
#define RCC_CR_MSIRANGE_1                    (0x1U << RCC_CR_MSIRANGE_Pos)     /*!< 0x00000010 */
#define RCC_CR_MSIRANGE_2                    (0x2U << RCC_CR_MSIRANGE_Pos)     /*!< 0x00000020 */
#define RCC_CR_MSIRANGE_3                    (0x3U << RCC_CR_MSIRANGE_Pos)     /*!< 0x00000030 */
#define RCC_CR_MSIRANGE_4                    (0x4U << RCC_CR_MSIRANGE_Pos)     /*!< 0x00000040 */
#define RCC_CR_MSIRANGE_5                    (0x5U << RCC_CR_MSIRANGE_Pos)     /*!< 0x00000050 */
#define RCC_CR_MSIRANGE_6                    (0x6U << RCC_CR_MSIRANGE_Pos)     /*!< 0x00000060 */
#define RCC_CR_MSIRANGE_7                    (0x7U << RCC_CR_MSIRANGE_Pos)     /*!< 0x00000070 */
#define RCC_CR_MSIRANGE_8                    (0x8U << RCC_CR_MSIRANGE_Pos)     /*!< 0x00000080 */
#define RCC_CR_MSIRANGE_9                    (0x9U << RCC_CR_MSIRANGE_Pos)     /*!< 0x00000090 */
#define RCC_CR_MSIRANGE_10                   (0xAU << RCC_CR_MSIRANGE_Pos)     /*!< 0x000000A0 */
#define RCC_CR_MSIRANGE_11                   (0xBU << RCC_CR_MSIRANGE_Pos)     /*!< 0x000000B0 */

#define RCC_CR_HSION_Pos                     (8U)
#define RCC_CR_HSION_Msk                     (0x1UL << RCC_CR_HSION_Pos)       /*!< 0x00000100 */
#define RCC_CR_HSION                         RCC_CR_HSION_Msk                  /*!< Internal High Speed oscillator (HSI16) clock enable */
#define RCC_CR_HSIKERON_Pos                  (9U)
#define RCC_CR_HSIKERON_Msk                  (0x1UL << RCC_CR_HSIKERON_Pos)    /*!< 0x00000200 */
#define RCC_CR_HSIKERON                      RCC_CR_HSIKERON_Msk               /*!< Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel */
#define RCC_CR_HSIRDY_Pos                    (10U)
#define RCC_CR_HSIRDY_Msk                    (0x1UL << RCC_CR_HSIRDY_Pos)      /*!< 0x00000400 */
#define RCC_CR_HSIRDY                        RCC_CR_HSIRDY_Msk                 /*!< Internal High Speed oscillator (HSI16) clock ready flag */
#define RCC_CR_HSIASFS_Pos                   (11U)
#define RCC_CR_HSIASFS_Msk                   (0x1UL << RCC_CR_HSIASFS_Pos)     /*!< 0x00000800 */
#define RCC_CR_HSIASFS                       RCC_CR_HSIASFS_Msk                /*!< HSI16 Automatic Start from Stop */
#define RCC_CR_HSIKERDY_Pos                  (12U)
#define RCC_CR_HSIKERDY_Msk                  (0x1UL << RCC_CR_HSIKERDY_Pos)     /*!< 0x00001000 */
#define RCC_CR_HSIKERDY                       RCC_CR_HSIKERDY_Msk               /*!< Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel ready flag*/

#define RCC_CR_HSEON_Pos                     (16U)
#define RCC_CR_HSEON_Msk                     (0x1UL << RCC_CR_HSEON_Pos)       /*!< 0x00010000 */
#define RCC_CR_HSEON                         RCC_CR_HSEON_Msk                  /*!< External High Speed oscillator (HSE) clock enable */
#define RCC_CR_HSERDY_Pos                    (17U)
#define RCC_CR_HSERDY_Msk                    (0x1UL << RCC_CR_HSERDY_Pos)      /*!< 0x00020000 */
#define RCC_CR_HSERDY                        RCC_CR_HSERDY_Msk                 /*!< External High Speed oscillator (HSE) clock ready */
#define RCC_CR_CSSON_Pos                     (19U)
#define RCC_CR_CSSON_Msk                     (0x1UL << RCC_CR_CSSON_Pos)       /*!< 0x00080000 */
#define RCC_CR_CSSON                         RCC_CR_CSSON_Msk                  /*!< HSE Clock Security System enable */
#define RCC_CR_HSEPRE_Pos                    (20U)
#define RCC_CR_HSEPRE_Msk                    (0x1UL << RCC_CR_HSEPRE_Pos)       /*!< 0x00100000 */
#define RCC_CR_HSEPRE                        RCC_CR_HSEPRE_Msk                  /*!< HSE sysclk prescaler */

#define RCC_CR_PLLON_Pos                     (24U)
#define RCC_CR_PLLON_Msk                     (0x1UL << RCC_CR_PLLON_Pos)       /*!< 0x01000000 */
#define RCC_CR_PLLON                         RCC_CR_PLLON_Msk                  /*!< System PLL clock enable */
#define RCC_CR_PLLRDY_Pos                    (25U)
#define RCC_CR_PLLRDY_Msk                    (0x1UL << RCC_CR_PLLRDY_Pos)      /*!< 0x02000000 */
#define RCC_CR_PLLRDY                        RCC_CR_PLLRDY_Msk                 /*!< System PLL clock ready */

/********************  Bit definition for RCC_ICSCR register  ***************/
/*!< MSICAL configuration */
#define RCC_ICSCR_MSICAL_Pos                 (0U)
#define RCC_ICSCR_MSICAL_Msk                 (0xFFUL << RCC_ICSCR_MSICAL_Pos)  /*!< 0x000000FF */
#define RCC_ICSCR_MSICAL                     RCC_ICSCR_MSICAL_Msk              /*!< MSICAL[7:0] bits */
#define RCC_ICSCR_MSICAL_0                   (0x01U << RCC_ICSCR_MSICAL_Pos)   /*!< 0x00000001 */
#define RCC_ICSCR_MSICAL_1                   (0x02U << RCC_ICSCR_MSICAL_Pos)   /*!< 0x00000002 */
#define RCC_ICSCR_MSICAL_2                   (0x04U << RCC_ICSCR_MSICAL_Pos)   /*!< 0x00000004 */
#define RCC_ICSCR_MSICAL_3                   (0x08U << RCC_ICSCR_MSICAL_Pos)   /*!< 0x00000008 */
#define RCC_ICSCR_MSICAL_4                   (0x10U << RCC_ICSCR_MSICAL_Pos)   /*!< 0x00000010 */
#define RCC_ICSCR_MSICAL_5                   (0x20U << RCC_ICSCR_MSICAL_Pos)   /*!< 0x00000020 */
#define RCC_ICSCR_MSICAL_6                   (0x40U << RCC_ICSCR_MSICAL_Pos)   /*!< 0x00000040 */
#define RCC_ICSCR_MSICAL_7                   (0x80U << RCC_ICSCR_MSICAL_Pos)   /*!< 0x00000080 */

/*!< MSITRIM configuration */
#define RCC_ICSCR_MSITRIM_Pos                (8U)
#define RCC_ICSCR_MSITRIM_Msk                (0xFFUL << RCC_ICSCR_MSITRIM_Pos) /*!< 0x0000FF00 */
#define RCC_ICSCR_MSITRIM                    RCC_ICSCR_MSITRIM_Msk             /*!< MSITRIM[7:0] bits */
#define RCC_ICSCR_MSITRIM_0                  (0x01U << RCC_ICSCR_MSITRIM_Pos)  /*!< 0x00000100 */
#define RCC_ICSCR_MSITRIM_1                  (0x02U << RCC_ICSCR_MSITRIM_Pos)  /*!< 0x00000200 */
#define RCC_ICSCR_MSITRIM_2                  (0x04U << RCC_ICSCR_MSITRIM_Pos)  /*!< 0x00000400 */
#define RCC_ICSCR_MSITRIM_3                  (0x08U << RCC_ICSCR_MSITRIM_Pos)  /*!< 0x00000800 */
#define RCC_ICSCR_MSITRIM_4                  (0x10U << RCC_ICSCR_MSITRIM_Pos)  /*!< 0x00001000 */
#define RCC_ICSCR_MSITRIM_5                  (0x20U << RCC_ICSCR_MSITRIM_Pos)  /*!< 0x00002000 */
#define RCC_ICSCR_MSITRIM_6                  (0x40U << RCC_ICSCR_MSITRIM_Pos)  /*!< 0x00004000 */
#define RCC_ICSCR_MSITRIM_7                  (0x80U << RCC_ICSCR_MSITRIM_Pos)  /*!< 0x00008000 */

/*!< HSICAL configuration */
#define RCC_ICSCR_HSICAL_Pos                 (16U)
#define RCC_ICSCR_HSICAL_Msk                 (0xFFUL << RCC_ICSCR_HSICAL_Pos)  /*!< 0x00FF0000 */
#define RCC_ICSCR_HSICAL                     RCC_ICSCR_HSICAL_Msk              /*!< HSICAL[7:0] bits */
#define RCC_ICSCR_HSICAL_0                   (0x01U << RCC_ICSCR_HSICAL_Pos)   /*!< 0x00010000 */
#define RCC_ICSCR_HSICAL_1                   (0x02U << RCC_ICSCR_HSICAL_Pos)   /*!< 0x00020000 */
#define RCC_ICSCR_HSICAL_2                   (0x04U << RCC_ICSCR_HSICAL_Pos)   /*!< 0x00040000 */
#define RCC_ICSCR_HSICAL_3                   (0x08U << RCC_ICSCR_HSICAL_Pos)   /*!< 0x00080000 */
#define RCC_ICSCR_HSICAL_4                   (0x10U << RCC_ICSCR_HSICAL_Pos)   /*!< 0x00100000 */
#define RCC_ICSCR_HSICAL_5                   (0x20U << RCC_ICSCR_HSICAL_Pos)   /*!< 0x00200000 */
#define RCC_ICSCR_HSICAL_6                   (0x40U << RCC_ICSCR_HSICAL_Pos)   /*!< 0x00400000 */
#define RCC_ICSCR_HSICAL_7                   (0x80U << RCC_ICSCR_HSICAL_Pos)   /*!< 0x00800000 */

/*!< HSITRIM configuration */
#define RCC_ICSCR_HSITRIM_Pos                (24U)
#define RCC_ICSCR_HSITRIM_Msk                (0x7FUL << RCC_ICSCR_HSITRIM_Pos) /*!< 0x7F000000 */
#define RCC_ICSCR_HSITRIM                    RCC_ICSCR_HSITRIM_Msk             /*!< HSITRIM[6:0] bits */
#define RCC_ICSCR_HSITRIM_0                  (0x01U << RCC_ICSCR_HSITRIM_Pos)  /*!< 0x01000000 */
#define RCC_ICSCR_HSITRIM_1                  (0x02U << RCC_ICSCR_HSITRIM_Pos)  /*!< 0x02000000 */
#define RCC_ICSCR_HSITRIM_2                  (0x04U << RCC_ICSCR_HSITRIM_Pos)  /*!< 0x04000000 */
#define RCC_ICSCR_HSITRIM_3                  (0x08U << RCC_ICSCR_HSITRIM_Pos)  /*!< 0x08000000 */
#define RCC_ICSCR_HSITRIM_4                  (0x10U << RCC_ICSCR_HSITRIM_Pos)  /*!< 0x10000000 */
#define RCC_ICSCR_HSITRIM_5                  (0x20U << RCC_ICSCR_HSITRIM_Pos)  /*!< 0x20000000 */
#define RCC_ICSCR_HSITRIM_6                  (0x40U << RCC_ICSCR_HSITRIM_Pos)  /*!< 0x40000000 */

/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                      (0U)
#define RCC_CFGR_SW_Msk                      (0x3UL << RCC_CFGR_SW_Pos)        /*!< 0x00000003 */
#define RCC_CFGR_SW                          RCC_CFGR_SW_Msk                   /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                        (0x1U << RCC_CFGR_SW_Pos)         /*!< 0x00000001 */
#define RCC_CFGR_SW_1                        (0x2U << RCC_CFGR_SW_Pos)         /*!< 0x00000002 */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                     (2U)
#define RCC_CFGR_SWS_Msk                     (0x3UL << RCC_CFGR_SWS_Pos)       /*!< 0x0000000C */
#define RCC_CFGR_SWS                         RCC_CFGR_SWS_Msk                  /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                       (0x1U << RCC_CFGR_SWS_Pos)        /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                       (0x2U << RCC_CFGR_SWS_Pos)        /*!< 0x00000008 */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                    (4U)
#define RCC_CFGR_HPRE_Msk                    (0xFUL << RCC_CFGR_HPRE_Pos)      /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                        RCC_CFGR_HPRE_Msk                 /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                      (0x1U << RCC_CFGR_HPRE_Pos)       /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                      (0x2U << RCC_CFGR_HPRE_Pos)       /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                      (0x4U << RCC_CFGR_HPRE_Pos)       /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                      (0x8U << RCC_CFGR_HPRE_Pos)       /*!< 0x00000080 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                   (8U)
#define RCC_CFGR_PPRE1_Msk                   (0x7UL << RCC_CFGR_PPRE1_Pos)     /*!< 0x00000700 */
#define RCC_CFGR_PPRE1                       RCC_CFGR_PPRE1_Msk                /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0                     (0x1U << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000100 */
#define RCC_CFGR_PPRE1_1                     (0x2U << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000200 */
#define RCC_CFGR_PPRE1_2                     (0x4U << RCC_CFGR_PPRE1_Pos)      /*!< 0x00000400 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                   (11U)
#define RCC_CFGR_PPRE2_Msk                   (0x7UL << RCC_CFGR_PPRE2_Pos)     /*!< 0x00003800 */
#define RCC_CFGR_PPRE2                       RCC_CFGR_PPRE2_Msk                /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                     (0x1U << RCC_CFGR_PPRE2_Pos)      /*!< 0x00000800 */
#define RCC_CFGR_PPRE2_1                     (0x2U << RCC_CFGR_PPRE2_Pos)      /*!< 0x00001000 */
#define RCC_CFGR_PPRE2_2                     (0x4U << RCC_CFGR_PPRE2_Pos)      /*!< 0x00002000 */

/*!< STOPWUCK configuration */
#define RCC_CFGR_STOPWUCK_Pos                (15U)
#define RCC_CFGR_STOPWUCK_Msk                (0x1UL << RCC_CFGR_STOPWUCK_Pos)  /*!< 0x00008000 */
#define RCC_CFGR_STOPWUCK                    RCC_CFGR_STOPWUCK_Msk             /*!< Wake Up from stop and CSS backup clock selection */

/*!< HPREF configuration */
#define RCC_CFGR_HPREF_Pos                   (16U)
#define RCC_CFGR_HPREF_Msk                   (0x1UL << RCC_CFGR_HPREF_Pos)     /*!< 0x00010000 */
#define RCC_CFGR_HPREF                       RCC_CFGR_HPREF_Msk                /*!< AHB prescaler flag */

/*!< PPRE1F configuration */
#define RCC_CFGR_PPRE1F_Pos                  (17U)
#define RCC_CFGR_PPRE1F_Msk                  (0x1UL << RCC_CFGR_PPRE1F_Pos)    /*!< 0x00020000 */
#define RCC_CFGR_PPRE1F                      RCC_CFGR_PPRE1F_Msk               /*!< CPU1 APB1 prescaler flag */

/*!< PPRE2F configuration */
#define RCC_CFGR_PPRE2F_Pos                  (18U)
#define RCC_CFGR_PPRE2F_Msk                  (0x1UL << RCC_CFGR_PPRE2F_Pos)    /*!< 0x00040000 */
#define RCC_CFGR_PPRE2F                      RCC_CFGR_PPRE2F_Msk               /*!< APB2 prescaler flag */

/*!< MCOSEL configuration */
#define RCC_CFGR_MCOSEL_Pos                  (24U)
#define RCC_CFGR_MCOSEL_Msk                  (0xFUL << RCC_CFGR_MCOSEL_Pos)    /*!< 0x0F000000 */
#define RCC_CFGR_MCOSEL                      RCC_CFGR_MCOSEL_Msk               /*!< MCOSEL [3:0] bits (Clock output selection) */
#define RCC_CFGR_MCOSEL_0                    (0x1U << RCC_CFGR_MCOSEL_Pos)     /*!< 0x01000000 */
#define RCC_CFGR_MCOSEL_1                    (0x2U << RCC_CFGR_MCOSEL_Pos)     /*!< 0x02000000 */
#define RCC_CFGR_MCOSEL_2                    (0x4U << RCC_CFGR_MCOSEL_Pos)     /*!< 0x04000000 */
#define RCC_CFGR_MCOSEL_3                    (0x8U << RCC_CFGR_MCOSEL_Pos)     /*!< 0x08000000 */

/*!< MCOPRE configuration */
#define RCC_CFGR_MCOPRE_Pos                  (28U)
#define RCC_CFGR_MCOPRE_Msk                  (0x7UL << RCC_CFGR_MCOPRE_Pos)    /*!< 0x70000000 */
#define RCC_CFGR_MCOPRE                      RCC_CFGR_MCOPRE_Msk               /*!< MCO prescaler */
#define RCC_CFGR_MCOPRE_0                    (0x1U << RCC_CFGR_MCOPRE_Pos)     /*!< 0x10000000 */
#define RCC_CFGR_MCOPRE_1                    (0x2U << RCC_CFGR_MCOPRE_Pos)     /*!< 0x20000000 */
#define RCC_CFGR_MCOPRE_2                    (0x4U << RCC_CFGR_MCOPRE_Pos)     /*!< 0x40000000 */

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLSRC_Pos               (0U)
#define RCC_PLLCFGR_PLLSRC_Msk               (0x3UL << RCC_PLLCFGR_PLLSRC_Pos) /*!< 0x00000003 */
#define RCC_PLLCFGR_PLLSRC                   RCC_PLLCFGR_PLLSRC_Msk
#define RCC_PLLCFGR_PLLSRC_0                 (0x1U << RCC_PLLCFGR_PLLSRC_Pos) /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLSRC_1                 (0x2U << RCC_PLLCFGR_PLLSRC_Pos) /*!< 0x00000002 */

#define RCC_PLLCFGR_PLLM_Pos                 (4U)
#define RCC_PLLCFGR_PLLM_Msk                 (0x7UL << RCC_PLLCFGR_PLLM_Pos) /*!< 0x00000070 */
#define RCC_PLLCFGR_PLLM                     RCC_PLLCFGR_PLLM_Msk
#define RCC_PLLCFGR_PLLM_0                   (0x1U << RCC_PLLCFGR_PLLM_Pos)  /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_1                   (0x2U << RCC_PLLCFGR_PLLM_Pos)  /*!< 0x00000020 */
#define RCC_PLLCFGR_PLLM_2                   (0x4U << RCC_PLLCFGR_PLLM_Pos)  /*!< 0x00000040 */

#define RCC_PLLCFGR_PLLN_Pos                 (8U)
#define RCC_PLLCFGR_PLLN_Msk                 (0x7FUL << RCC_PLLCFGR_PLLN_Pos) /*!< 0x00007F00 */
#define RCC_PLLCFGR_PLLN                     RCC_PLLCFGR_PLLN_Msk
#define RCC_PLLCFGR_PLLN_0                   (0x01U << RCC_PLLCFGR_PLLN_Pos) /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_1                   (0x02U << RCC_PLLCFGR_PLLN_Pos) /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_2                   (0x04U << RCC_PLLCFGR_PLLN_Pos) /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_3                   (0x08U << RCC_PLLCFGR_PLLN_Pos) /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_4                   (0x10U << RCC_PLLCFGR_PLLN_Pos) /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_5                   (0x20U << RCC_PLLCFGR_PLLN_Pos) /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_6                   (0x40U << RCC_PLLCFGR_PLLN_Pos) /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLPEN_Pos               (16U)
#define RCC_PLLCFGR_PLLPEN_Msk               (0x1UL << RCC_PLLCFGR_PLLPEN_Pos) /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLPEN                   RCC_PLLCFGR_PLLPEN_Msk
#define RCC_PLLCFGR_PLLP_Pos                 (17U)
#define RCC_PLLCFGR_PLLP_Msk                 (0x1FUL << RCC_PLLCFGR_PLLP_Pos) /*!< 0x003E0000 */
#define RCC_PLLCFGR_PLLP                     RCC_PLLCFGR_PLLP_Msk
#define RCC_PLLCFGR_PLLP_0                   (0x01U << RCC_PLLCFGR_PLLP_Pos) /*!< 0x00020000 */
#define RCC_PLLCFGR_PLLP_1                   (0x02U << RCC_PLLCFGR_PLLP_Pos) /*!< 0x00040000 */
#define RCC_PLLCFGR_PLLP_2                   (0x04U << RCC_PLLCFGR_PLLP_Pos) /*!< 0x00080000 */
#define RCC_PLLCFGR_PLLP_3                   (0x08U << RCC_PLLCFGR_PLLP_Pos) /*!< 0x00100000 */
#define RCC_PLLCFGR_PLLP_4                   (0x10U << RCC_PLLCFGR_PLLP_Pos) /*!< 0x00200000 */

#define RCC_PLLCFGR_PLLQEN_Pos               (24U)
#define RCC_PLLCFGR_PLLQEN_Msk               (0x1UL << RCC_PLLCFGR_PLLQEN_Pos) /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLQEN                   RCC_PLLCFGR_PLLQEN_Msk
#define RCC_PLLCFGR_PLLQ_Pos                 (25U)
#define RCC_PLLCFGR_PLLQ_Msk                 (0x7UL << RCC_PLLCFGR_PLLQ_Pos) /*!< 0x0E000000 */
#define RCC_PLLCFGR_PLLQ                     RCC_PLLCFGR_PLLQ_Msk
#define RCC_PLLCFGR_PLLQ_0                   (0x1U << RCC_PLLCFGR_PLLQ_Pos) /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLQ_1                   (0x2U << RCC_PLLCFGR_PLLQ_Pos) /*!< 0x04000000 */
#define RCC_PLLCFGR_PLLQ_2                   (0x4U << RCC_PLLCFGR_PLLQ_Pos) /*!< 0x08000000 */

#define RCC_PLLCFGR_PLLREN_Pos               (28U)
#define RCC_PLLCFGR_PLLREN_Msk               (0x1UL << RCC_PLLCFGR_PLLREN_Pos) /*!< 0x10000000 */
#define RCC_PLLCFGR_PLLREN                   RCC_PLLCFGR_PLLREN_Msk
#define RCC_PLLCFGR_PLLR_Pos                 (29U)
#define RCC_PLLCFGR_PLLR_Msk                 (0x7UL << RCC_PLLCFGR_PLLR_Pos) /*!< 0xE0000000 */
#define RCC_PLLCFGR_PLLR                     RCC_PLLCFGR_PLLR_Msk
#define RCC_PLLCFGR_PLLR_0                   (0x1U << RCC_PLLCFGR_PLLR_Pos) /*!< 0x20000000 */
#define RCC_PLLCFGR_PLLR_1                   (0x2U << RCC_PLLCFGR_PLLR_Pos) /*!< 0x40000000 */
#define RCC_PLLCFGR_PLLR_2                   (0x4U << RCC_PLLCFGR_PLLR_Pos) /*!< 0x80000000 */

/********************  Bit definition for RCC_CIER register  ******************/
#define RCC_CIER_LSI1RDYIE_Pos               (0U)
#define RCC_CIER_LSI1RDYIE_Msk               (0x1UL << RCC_CIER_LSI1RDYIE_Pos)  /*!< 0x00000001 */
#define RCC_CIER_LSI1RDYIE                   RCC_CIER_LSI1RDYIE_Msk
#define RCC_CIER_LSERDYIE_Pos                (1U)
#define RCC_CIER_LSERDYIE_Msk                (0x1UL << RCC_CIER_LSERDYIE_Pos)   /*!< 0x00000002 */
#define RCC_CIER_LSERDYIE                    RCC_CIER_LSERDYIE_Msk
#define RCC_CIER_MSIRDYIE_Pos                (2U)
#define RCC_CIER_MSIRDYIE_Msk                (0x1UL << RCC_CIER_MSIRDYIE_Pos)   /*!< 0x00000004 */
#define RCC_CIER_MSIRDYIE                    RCC_CIER_MSIRDYIE_Msk
#define RCC_CIER_HSIRDYIE_Pos                (3U)
#define RCC_CIER_HSIRDYIE_Msk                (0x1UL << RCC_CIER_HSIRDYIE_Pos)   /*!< 0x00000008 */
#define RCC_CIER_HSIRDYIE                    RCC_CIER_HSIRDYIE_Msk
#define RCC_CIER_HSERDYIE_Pos                (4U)
#define RCC_CIER_HSERDYIE_Msk                (0x1UL << RCC_CIER_HSERDYIE_Pos)   /*!< 0x00000010 */
#define RCC_CIER_HSERDYIE                    RCC_CIER_HSERDYIE_Msk
#define RCC_CIER_PLLRDYIE_Pos                (5U)
#define RCC_CIER_PLLRDYIE_Msk                (0x1UL << RCC_CIER_PLLRDYIE_Pos) /*!< 0x00000020 */
#define RCC_CIER_PLLRDYIE                    RCC_CIER_PLLRDYIE_Msk
#define RCC_CIER_LSECSSIE_Pos                (9U)
#define RCC_CIER_LSECSSIE_Msk                (0x1UL << RCC_CIER_LSECSSIE_Pos)   /*!< 0x00000200 */
#define RCC_CIER_LSECSSIE                    RCC_CIER_LSECSSIE_Msk
#define RCC_CIER_LSI2RDYIE_Pos               (11U)
#define RCC_CIER_LSI2RDYIE_Msk               (0x1UL << RCC_CIER_LSI2RDYIE_Pos)  /*!< 0x00000800 */
#define RCC_CIER_LSI2RDYIE                   RCC_CIER_LSI2RDYIE_Msk


/********************  Bit definition for RCC_CIFR register  ******************/
#define RCC_CIFR_LSI1RDYF_Pos                (0U)
#define RCC_CIFR_LSI1RDYF_Msk                (0x1UL << RCC_CIFR_LSI1RDYF_Pos)  /*!< 0x00000001 */
#define RCC_CIFR_LSI1RDYF                    RCC_CIFR_LSI1RDYF_Msk
#define RCC_CIFR_LSERDYF_Pos                 (1U)
#define RCC_CIFR_LSERDYF_Msk                 (0x1UL << RCC_CIFR_LSERDYF_Pos)   /*!< 0x00000002 */
#define RCC_CIFR_LSERDYF                     RCC_CIFR_LSERDYF_Msk
#define RCC_CIFR_MSIRDYF_Pos                 (2U)
#define RCC_CIFR_MSIRDYF_Msk                 (0x1UL << RCC_CIFR_MSIRDYF_Pos)   /*!< 0x00000004 */
#define RCC_CIFR_MSIRDYF                     RCC_CIFR_MSIRDYF_Msk
#define RCC_CIFR_HSIRDYF_Pos                 (3U)
#define RCC_CIFR_HSIRDYF_Msk                 (0x1UL << RCC_CIFR_HSIRDYF_Pos)   /*!< 0x00000008 */
#define RCC_CIFR_HSIRDYF                     RCC_CIFR_HSIRDYF_Msk
#define RCC_CIFR_HSERDYF_Pos                 (4U)
#define RCC_CIFR_HSERDYF_Msk                 (0x1UL << RCC_CIFR_HSERDYF_Pos)   /*!< 0x00000010 */
#define RCC_CIFR_HSERDYF                     RCC_CIFR_HSERDYF_Msk
#define RCC_CIFR_PLLRDYF_Pos                 (5U)
#define RCC_CIFR_PLLRDYF_Msk                 (0x1UL << RCC_CIFR_PLLRDYF_Pos) /*!< 0x00000020 */
#define RCC_CIFR_PLLRDYF                     RCC_CIFR_PLLRDYF_Msk
#define RCC_CIFR_CSSF_Pos                    (8U)
#define RCC_CIFR_CSSF_Msk                    (0x1UL << RCC_CIFR_CSSF_Pos)   /*!< 0x00000100 */
#define RCC_CIFR_CSSF                        RCC_CIFR_CSSF_Msk
#define RCC_CIFR_LSECSSF_Pos                 (9U)
#define RCC_CIFR_LSECSSF_Msk                 (0x1UL << RCC_CIFR_LSECSSF_Pos)   /*!< 0x00000200 */
#define RCC_CIFR_LSECSSF                     RCC_CIFR_LSECSSF_Msk
#define RCC_CIFR_LSI2RDYF_Pos                (11U)
#define RCC_CIFR_LSI2RDYF_Msk                (0x1UL << RCC_CIFR_LSI2RDYF_Pos)  /*!< 0x00000800 */
#define RCC_CIFR_LSI2RDYF                    RCC_CIFR_LSI2RDYF_Msk

/********************  Bit definition for RCC_CICR register  ******************/
#define RCC_CICR_LSI1RDYC_Pos               (0U)
#define RCC_CICR_LSI1RDYC_Msk               (0x1UL << RCC_CICR_LSI1RDYC_Pos)  /*!< 0x00000001 */
#define RCC_CICR_LSI1RDYC                   RCC_CICR_LSI1RDYC_Msk
#define RCC_CICR_LSERDYC_Pos                (1U)
#define RCC_CICR_LSERDYC_Msk                (0x1UL << RCC_CICR_LSERDYC_Pos)   /*!< 0x00000002 */
#define RCC_CICR_LSERDYC                    RCC_CICR_LSERDYC_Msk
#define RCC_CICR_MSIRDYC_Pos                (2U)
#define RCC_CICR_MSIRDYC_Msk                (0x1UL << RCC_CICR_MSIRDYC_Pos)   /*!< 0x00000004 */
#define RCC_CICR_MSIRDYC                    RCC_CICR_MSIRDYC_Msk
#define RCC_CICR_HSIRDYC_Pos                (3U)
#define RCC_CICR_HSIRDYC_Msk                (0x1UL << RCC_CICR_HSIRDYC_Pos)   /*!< 0x00000008 */
#define RCC_CICR_HSIRDYC                    RCC_CICR_HSIRDYC_Msk
#define RCC_CICR_HSERDYC_Pos                (4U)
#define RCC_CICR_HSERDYC_Msk                (0x1UL << RCC_CICR_HSERDYC_Pos)   /*!< 0x00000010 */
#define RCC_CICR_HSERDYC                    RCC_CICR_HSERDYC_Msk
#define RCC_CICR_PLLRDYC_Pos                (5U)
#define RCC_CICR_PLLRDYC_Msk                (0x1UL << RCC_CICR_PLLRDYC_Pos) /*!< 0x00000020 */
#define RCC_CICR_PLLRDYC                    RCC_CICR_PLLRDYC_Msk
#define RCC_CICR_CSSC_Pos                   (8U)
#define RCC_CICR_CSSC_Msk                   (0x1UL << RCC_CICR_CSSC_Pos)   /*!< 0x00000100 */
#define RCC_CICR_CSSC                       RCC_CICR_CSSC_Msk
#define RCC_CICR_LSECSSC_Pos                (9U)
#define RCC_CICR_LSECSSC_Msk                (0x1UL << RCC_CICR_LSECSSC_Pos)   /*!< 0x00000200 */
#define RCC_CICR_LSECSSC                    RCC_CICR_LSECSSC_Msk
#define RCC_CICR_LSI2RDYC_Pos               (11U)
#define RCC_CICR_LSI2RDYC_Msk               (0x1UL << RCC_CICR_LSI2RDYC_Pos)  /*!< 0x00000800 */
#define RCC_CICR_LSI2RDYC                   RCC_CICR_LSI2RDYC_Msk

/********************  Bit definition for RCC_SMPSCR register  ******************/
#define RCC_SMPSCR_SMPSSEL_Pos               (0U)
#define RCC_SMPSCR_SMPSSEL_Msk               (0x3UL << RCC_SMPSCR_SMPSSEL_Pos)  /*!< 0x00000003 */
#define RCC_SMPSCR_SMPSSEL                   RCC_SMPSCR_SMPSSEL_Msk
#define RCC_SMPSCR_SMPSSEL_0                 (0x1U << RCC_SMPSCR_SMPSSEL_Pos)   /*!< 0x00000001 */
#define RCC_SMPSCR_SMPSSEL_1                 (0x2U << RCC_SMPSCR_SMPSSEL_Pos)   /*!< 0x00000002 */

#define RCC_SMPSCR_SMPSDIV_Pos               (4U)
#define RCC_SMPSCR_SMPSDIV_Msk               (0x3UL << RCC_SMPSCR_SMPSDIV_Pos)  /*!< 0x00000030 */
#define RCC_SMPSCR_SMPSDIV                   RCC_SMPSCR_SMPSDIV_Msk
#define RCC_SMPSCR_SMPSDIV_0                 (0x1U << RCC_SMPSCR_SMPSDIV_Pos)   /*!< 0x00000010 */
#define RCC_SMPSCR_SMPSDIV_1                 (0x2U << RCC_SMPSCR_SMPSDIV_Pos)   /*!< 0x00000020 */

#define RCC_SMPSCR_SMPSSWS_Pos               (8U)
#define RCC_SMPSCR_SMPSSWS_Msk               (0x3UL << RCC_SMPSCR_SMPSSWS_Pos)  /*!< 0x00000300 */
#define RCC_SMPSCR_SMPSSWS                   RCC_SMPSCR_SMPSSWS_Msk
#define RCC_SMPSCR_SMPSSWS_0                 (0x1U << RCC_SMPSCR_SMPSSWS_Pos)   /*!< 0x00000100 */
#define RCC_SMPSCR_SMPSSWS_1                 (0x2U << RCC_SMPSCR_SMPSSWS_Pos)   /*!< 0x00000200 */

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_DMA1RST_Pos             (0U)
#define RCC_AHB1RSTR_DMA1RST_Msk             (0x1UL << RCC_AHB1RSTR_DMA1RST_Pos) /*!< 0x00000001 */
#define RCC_AHB1RSTR_DMA1RST                 RCC_AHB1RSTR_DMA1RST_Msk
#define RCC_AHB1RSTR_DMAMUX1RST_Pos          (2U)
#define RCC_AHB1RSTR_DMAMUX1RST_Msk          (0x1UL << RCC_AHB1RSTR_DMAMUX1RST_Pos) /*!< 0x00000004 */
#define RCC_AHB1RSTR_DMAMUX1RST              RCC_AHB1RSTR_DMAMUX1RST_Msk
#define RCC_AHB1RSTR_CRCRST_Pos              (12U)
#define RCC_AHB1RSTR_CRCRST_Msk              (0x1UL << RCC_AHB1RSTR_CRCRST_Pos) /*!< 0x00001000 */
#define RCC_AHB1RSTR_CRCRST                  RCC_AHB1RSTR_CRCRST_Msk
#define RCC_AHB1RSTR_TSCRST_Pos              (16U)
#define RCC_AHB1RSTR_TSCRST_Msk              (0x1UL << RCC_AHB1RSTR_TSCRST_Pos) /*!< 0x00010000 */
#define RCC_AHB1RSTR_TSCRST                  RCC_AHB1RSTR_TSCRST_Msk

/********************  Bit definition for RCC_AHB2RSTR register  ***************/
#define RCC_AHB2RSTR_GPIOARST_Pos           (0U)
#define RCC_AHB2RSTR_GPIOARST_Msk           (0x1UL << RCC_AHB2RSTR_GPIOARST_Pos) /*!< 0x00000001 */
#define RCC_AHB2RSTR_GPIOARST               RCC_AHB2RSTR_GPIOARST_Msk
#define RCC_AHB2RSTR_GPIOBRST_Pos           (1U)
#define RCC_AHB2RSTR_GPIOBRST_Msk           (0x1UL << RCC_AHB2RSTR_GPIOBRST_Pos) /*!< 0x00000002 */
#define RCC_AHB2RSTR_GPIOBRST               RCC_AHB2RSTR_GPIOBRST_Msk
#define RCC_AHB2RSTR_GPIOCRST_Pos           (2U)
#define RCC_AHB2RSTR_GPIOCRST_Msk           (0x1UL << RCC_AHB2RSTR_GPIOCRST_Pos) /*!< 0x00000004 */
#define RCC_AHB2RSTR_GPIOCRST               RCC_AHB2RSTR_GPIOCRST_Msk
#define RCC_AHB2RSTR_GPIOERST_Pos           (4U)
#define RCC_AHB2RSTR_GPIOERST_Msk           (0x1UL << RCC_AHB2RSTR_GPIOERST_Pos) /*!< 0x00000010 */
#define RCC_AHB2RSTR_GPIOERST               RCC_AHB2RSTR_GPIOERST_Msk
#define RCC_AHB2RSTR_GPIOHRST_Pos           (7U)
#define RCC_AHB2RSTR_GPIOHRST_Msk           (0x1UL << RCC_AHB2RSTR_GPIOHRST_Pos) /*!< 0x00000080 */
#define RCC_AHB2RSTR_GPIOHRST               RCC_AHB2RSTR_GPIOHRST_Msk

/********************  Bit definition for RCC_AHB3RSTR register  ***************/
#define RCC_AHB3RSTR_PKARST_Pos             (16U)
#define RCC_AHB3RSTR_PKARST_Msk             (0x1UL << RCC_AHB3RSTR_PKARST_Pos) /*!< 0x00010000 */
#define RCC_AHB3RSTR_PKARST                 RCC_AHB3RSTR_PKARST_Msk
#define RCC_AHB3RSTR_AES2RST_Pos            (17U)
#define RCC_AHB3RSTR_AES2RST_Msk            (0x1UL << RCC_AHB3RSTR_AES2RST_Pos) /*!< 0x00020000 */
#define RCC_AHB3RSTR_AES2RST                RCC_AHB3RSTR_AES2RST_Msk
#define RCC_AHB3RSTR_RNGRST_Pos             (18U)
#define RCC_AHB3RSTR_RNGRST_Msk             (0x1UL << RCC_AHB3RSTR_RNGRST_Pos) /*!< 0x00040000 */
#define RCC_AHB3RSTR_RNGRST                 RCC_AHB3RSTR_RNGRST_Msk
#define RCC_AHB3RSTR_HSEMRST_Pos            (19U)
#define RCC_AHB3RSTR_HSEMRST_Msk            (0x1UL << RCC_AHB3RSTR_HSEMRST_Pos) /*!< 0x00080000 */
#define RCC_AHB3RSTR_HSEMRST                RCC_AHB3RSTR_HSEMRST_Msk
#define RCC_AHB3RSTR_IPCCRST_Pos            (20U)
#define RCC_AHB3RSTR_IPCCRST_Msk            (0x1UL << RCC_AHB3RSTR_IPCCRST_Pos) /*!< 0x00100000 */
#define RCC_AHB3RSTR_IPCCRST                RCC_AHB3RSTR_IPCCRST_Msk
#define RCC_AHB3RSTR_FLASHRST_Pos           (25U)
#define RCC_AHB3RSTR_FLASHRST_Msk           (0x1UL << RCC_AHB3RSTR_FLASHRST_Pos) /*!< 0x02000000 */
#define RCC_AHB3RSTR_FLASHRST               RCC_AHB3RSTR_FLASHRST_Msk

/********************  Bit definition for RCC_APB1RSTR1 register  **************/
#define RCC_APB1RSTR1_TIM2RST_Pos           (0U)
#define RCC_APB1RSTR1_TIM2RST_Msk           (0x1UL << RCC_APB1RSTR1_TIM2RST_Pos) /*!< 0x00000001 */
#define RCC_APB1RSTR1_TIM2RST               RCC_APB1RSTR1_TIM2RST_Msk
#define RCC_APB1RSTR1_I2C1RST_Pos           (21U)
#define RCC_APB1RSTR1_I2C1RST_Msk           (0x1UL << RCC_APB1RSTR1_I2C1RST_Pos) /*!< 0x00200000 */
#define RCC_APB1RSTR1_I2C1RST               RCC_APB1RSTR1_I2C1RST_Msk
#define RCC_APB1RSTR1_LPTIM1RST_Pos         (31U)
#define RCC_APB1RSTR1_LPTIM1RST_Msk         (0x1UL << RCC_APB1RSTR1_LPTIM1RST_Pos) /*!< 0x80000000 */
#define RCC_APB1RSTR1_LPTIM1RST             RCC_APB1RSTR1_LPTIM1RST_Msk

/********************  Bit definition for RCC_APB1RSTR2 register  **************/
#define RCC_APB1RSTR2_LPUART1RST_Pos        (0U)
#define RCC_APB1RSTR2_LPUART1RST_Msk        (0x1UL << RCC_APB1RSTR2_LPUART1RST_Pos) /*!< 0x00000001 */
#define RCC_APB1RSTR2_LPUART1RST            RCC_APB1RSTR2_LPUART1RST_Msk
#define RCC_APB1RSTR2_LPTIM2RST_Pos         (5U)
#define RCC_APB1RSTR2_LPTIM2RST_Msk         (0x1UL << RCC_APB1RSTR2_LPTIM2RST_Pos) /*!< 0x00000020 */
#define RCC_APB1RSTR2_LPTIM2RST             RCC_APB1RSTR2_LPTIM2RST_Msk

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_ADCRST_Pos             (9U)
#define RCC_APB2RSTR_ADCRST_Msk             (0x1UL << RCC_APB2RSTR_ADCRST_Pos)    /*!< 0x00000200 */
#define RCC_APB2RSTR_ADCRST                 RCC_APB2RSTR_ADCRST_Msk
#define RCC_APB2RSTR_TIM1RST_Pos            (11U)
#define RCC_APB2RSTR_TIM1RST_Msk            (0x1UL << RCC_APB2RSTR_TIM1RST_Pos)   /*!< 0x00000800 */
#define RCC_APB2RSTR_TIM1RST                RCC_APB2RSTR_TIM1RST_Msk
#define RCC_APB2RSTR_SPI1RST_Pos            (12U)
#define RCC_APB2RSTR_SPI1RST_Msk            (0x1UL << RCC_APB2RSTR_SPI1RST_Pos)   /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST                RCC_APB2RSTR_SPI1RST_Msk
#define RCC_APB2RSTR_USART1RST_Pos          (14U)
#define RCC_APB2RSTR_USART1RST_Msk          (0x1UL << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_USART1RST              RCC_APB2RSTR_USART1RST_Msk

/********************  Bit definition for RCC_APB3RSTR register  **************/
#define RCC_APB3RSTR_RFRST_Pos             (0U)
#define RCC_APB3RSTR_RFRST_Msk             (0x1UL << RCC_APB3RSTR_RFRST_Pos) /*!< 0x00000001 */
#define RCC_APB3RSTR_RFRST                 RCC_APB3RSTR_RFRST_Msk

/********************  Bit definition for RCC_AHB1ENR register  ****************/
#define RCC_AHB1ENR_DMA1EN_Pos              (0U)
#define RCC_AHB1ENR_DMA1EN_Msk              (0x1UL << RCC_AHB1ENR_DMA1EN_Pos)  /*!< 0x00000001 */
#define RCC_AHB1ENR_DMA1EN                  RCC_AHB1ENR_DMA1EN_Msk
#define RCC_AHB1ENR_DMAMUX1EN_Pos           (2U)
#define RCC_AHB1ENR_DMAMUX1EN_Msk           (0x1UL << RCC_AHB1ENR_DMAMUX1EN_Pos) /*!< 0x00000004 */
#define RCC_AHB1ENR_DMAMUX1EN               RCC_AHB1ENR_DMAMUX1EN_Msk
#define RCC_AHB1ENR_CRCEN_Pos               (12U)
#define RCC_AHB1ENR_CRCEN_Msk               (0x1UL << RCC_AHB1ENR_CRCEN_Pos)   /*!< 0x00001000 */
#define RCC_AHB1ENR_CRCEN                   RCC_AHB1ENR_CRCEN_Msk
#define RCC_AHB1ENR_TSCEN_Pos               (16U)
#define RCC_AHB1ENR_TSCEN_Msk               (0x1UL << RCC_AHB1ENR_TSCEN_Pos)   /*!< 0x00010000 */
#define RCC_AHB1ENR_TSCEN                   RCC_AHB1ENR_TSCEN_Msk

/********************  Bit definition for RCC_AHB2ENR register  ***************/
#define RCC_AHB2ENR_GPIOAEN_Pos             (0U)
#define RCC_AHB2ENR_GPIOAEN_Msk             (0x1UL << RCC_AHB2ENR_GPIOAEN_Pos) /*!< 0x00000001 */
#define RCC_AHB2ENR_GPIOAEN                 RCC_AHB2ENR_GPIOAEN_Msk
#define RCC_AHB2ENR_GPIOBEN_Pos             (1U)
#define RCC_AHB2ENR_GPIOBEN_Msk             (0x1UL << RCC_AHB2ENR_GPIOBEN_Pos) /*!< 0x00000002 */
#define RCC_AHB2ENR_GPIOBEN                 RCC_AHB2ENR_GPIOBEN_Msk
#define RCC_AHB2ENR_GPIOCEN_Pos             (2U)
#define RCC_AHB2ENR_GPIOCEN_Msk             (0x1UL << RCC_AHB2ENR_GPIOCEN_Pos) /*!< 0x00000004 */
#define RCC_AHB2ENR_GPIOCEN                 RCC_AHB2ENR_GPIOCEN_Msk
#define RCC_AHB2ENR_GPIOEEN_Pos             (4U)
#define RCC_AHB2ENR_GPIOEEN_Msk             (0x1UL << RCC_AHB2ENR_GPIOEEN_Pos) /*!< 0x00000010 */
#define RCC_AHB2ENR_GPIOEEN                 RCC_AHB2ENR_GPIOEEN_Msk
#define RCC_AHB2ENR_GPIOHEN_Pos             (7U)
#define RCC_AHB2ENR_GPIOHEN_Msk             (0x1UL << RCC_AHB2ENR_GPIOHEN_Pos) /*!< 0x00000080 */
#define RCC_AHB2ENR_GPIOHEN                 RCC_AHB2ENR_GPIOHEN_Msk

/********************  Bit definition for RCC_AHB3ENR register  ***************/
#define RCC_AHB3ENR_PKAEN_Pos               (16U)
#define RCC_AHB3ENR_PKAEN_Msk               (0x1UL << RCC_AHB3ENR_PKAEN_Pos)   /*!< 0x00010000 */
#define RCC_AHB3ENR_PKAEN                   RCC_AHB3ENR_PKAEN_Msk
#define RCC_AHB3ENR_AES2EN_Pos              (17U)
#define RCC_AHB3ENR_AES2EN_Msk              (0x1UL << RCC_AHB3ENR_AES2EN_Pos) /*!< 0x00020000 */
#define RCC_AHB3ENR_AES2EN                  RCC_AHB3ENR_AES2EN_Msk
#define RCC_AHB3ENR_RNGEN_Pos               (18U)
#define RCC_AHB3ENR_RNGEN_Msk               (0x1UL << RCC_AHB3ENR_RNGEN_Pos)  /*!< 0x00040000 */
#define RCC_AHB3ENR_RNGEN                   RCC_AHB3ENR_RNGEN_Msk
#define RCC_AHB3ENR_HSEMEN_Pos              (19U)
#define RCC_AHB3ENR_HSEMEN_Msk              (0x1UL << RCC_AHB3ENR_HSEMEN_Pos)  /*!< 0x00080000 */
#define RCC_AHB3ENR_HSEMEN                  RCC_AHB3ENR_HSEMEN_Msk
#define RCC_AHB3ENR_IPCCEN_Pos              (20U)
#define RCC_AHB3ENR_IPCCEN_Msk              (0x1UL << RCC_AHB3ENR_IPCCEN_Pos)  /*!< 0x00100000 */
#define RCC_AHB3ENR_IPCCEN                  RCC_AHB3ENR_IPCCEN_Msk
#define RCC_AHB3ENR_FLASHEN_Pos             (25U)
#define RCC_AHB3ENR_FLASHEN_Msk             (0x1UL << RCC_AHB3ENR_FLASHEN_Pos)   /*!< 0x02000000 */
#define RCC_AHB3ENR_FLASHEN                 RCC_AHB3ENR_FLASHEN_Msk

/********************  Bit definition for RCC_APB1ENR1 register  **************/
#define RCC_APB1ENR1_TIM2EN_Pos             (0U)
#define RCC_APB1ENR1_TIM2EN_Msk             (0x1UL << RCC_APB1ENR1_TIM2EN_Pos) /*!< 0x00000001 */
#define RCC_APB1ENR1_TIM2EN                 RCC_APB1ENR1_TIM2EN_Msk
#define RCC_APB1ENR1_RTCAPBEN_Pos           (10U)
#define RCC_APB1ENR1_RTCAPBEN_Msk           (0x1UL << RCC_APB1ENR1_RTCAPBEN_Pos) /*!< 0x00000400 */
#define RCC_APB1ENR1_RTCAPBEN               RCC_APB1ENR1_RTCAPBEN_Msk
#define RCC_APB1ENR1_WWDGEN_Pos             (11U)
#define RCC_APB1ENR1_WWDGEN_Msk             (0x1UL << RCC_APB1ENR1_WWDGEN_Pos) /*!< 0x00000800 */
#define RCC_APB1ENR1_WWDGEN                 RCC_APB1ENR1_WWDGEN_Msk
#define RCC_APB1ENR1_I2C1EN_Pos             (21U)
#define RCC_APB1ENR1_I2C1EN_Msk             (0x1UL << RCC_APB1ENR1_I2C1EN_Pos) /*!< 0x00200000 */
#define RCC_APB1ENR1_I2C1EN                 RCC_APB1ENR1_I2C1EN_Msk
#define RCC_APB1ENR1_LPTIM1EN_Pos           (31U)
#define RCC_APB1ENR1_LPTIM1EN_Msk           (0x1UL << RCC_APB1ENR1_LPTIM1EN_Pos) /*!< 0x80000000 */
#define RCC_APB1ENR1_LPTIM1EN               RCC_APB1ENR1_LPTIM1EN_Msk

/********************  Bit definition for RCC_APB1ENR2 register  **************/
#define RCC_APB1ENR2_LPUART1EN_Pos          (0U)
#define RCC_APB1ENR2_LPUART1EN_Msk         (0x1UL << RCC_APB1ENR2_LPUART1EN_Pos) /*!< 0x00000001 */
#define RCC_APB1ENR2_LPUART1EN              RCC_APB1ENR2_LPUART1EN_Msk
#define RCC_APB1ENR2_LPTIM2EN_Pos           (5U)
#define RCC_APB1ENR2_LPTIM2EN_Msk           (0x1UL << RCC_APB1ENR2_LPTIM2EN_Pos) /*!< 0x00000020 */
#define RCC_APB1ENR2_LPTIM2EN               RCC_APB1ENR2_LPTIM2EN_Msk

/********************  Bit definition for RCC_APB2ENR register  **************/
#define RCC_APB2ENR_ADCEN_Pos               (9U)
#define RCC_APB2ENR_ADCEN_Msk               (0x1UL << RCC_APB2ENR_ADCEN_Pos)    /*!< 0x00000200 */
#define RCC_APB2ENR_ADCEN                   RCC_APB2ENR_ADCEN_Msk
#define RCC_APB2ENR_TIM1EN_Pos              (11U)
#define RCC_APB2ENR_TIM1EN_Msk              (0x1UL << RCC_APB2ENR_TIM1EN_Pos)   /*!< 0x00000800 */
#define RCC_APB2ENR_TIM1EN                  RCC_APB2ENR_TIM1EN_Msk
#define RCC_APB2ENR_SPI1EN_Pos              (12U)
#define RCC_APB2ENR_SPI1EN_Msk              (0x1UL << RCC_APB2ENR_SPI1EN_Pos)   /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                  RCC_APB2ENR_SPI1EN_Msk
#define RCC_APB2ENR_USART1EN_Pos            (14U)
#define RCC_APB2ENR_USART1EN_Msk            (0x1UL << RCC_APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                RCC_APB2ENR_USART1EN_Msk

/********************  Bit definition for RCC_AHB1SMENR register  ****************/
#define RCC_AHB1SMENR_DMA1SMEN_Pos          (0U)
#define RCC_AHB1SMENR_DMA1SMEN_Msk          (0x1UL << RCC_AHB1SMENR_DMA1SMEN_Pos) /*!< 0x00000001 */
#define RCC_AHB1SMENR_DMA1SMEN              RCC_AHB1SMENR_DMA1SMEN_Msk
#define RCC_AHB1SMENR_DMAMUX1SMEN_Pos       (2U)
#define RCC_AHB1SMENR_DMAMUX1SMEN_Msk       (0x1UL << RCC_AHB1SMENR_DMAMUX1SMEN_Pos) /*!< 0x00000004 */
#define RCC_AHB1SMENR_DMAMUX1SMEN           RCC_AHB1SMENR_DMAMUX1SMEN_Msk
#define RCC_AHB1SMENR_SRAM1SMEN_Pos         (9U)
#define RCC_AHB1SMENR_SRAM1SMEN_Msk         (0x1UL << RCC_AHB1SMENR_SRAM1SMEN_Pos) /*!< 0x00000200 */
#define RCC_AHB1SMENR_SRAM1SMEN             RCC_AHB1SMENR_SRAM1SMEN_Msk
#define RCC_AHB1SMENR_CRCSMEN_Pos           (12U)
#define RCC_AHB1SMENR_CRCSMEN_Msk           (0x1UL << RCC_AHB1SMENR_CRCSMEN_Pos) /*!< 0x00001000 */
#define RCC_AHB1SMENR_CRCSMEN               RCC_AHB1SMENR_CRCSMEN_Msk
#define RCC_AHB1SMENR_TSCSMEN_Pos           (16U)
#define RCC_AHB1SMENR_TSCSMEN_Msk           (0x1UL << RCC_AHB1SMENR_TSCSMEN_Pos) /*!< 0x00010000 */
#define RCC_AHB1SMENR_TSCSMEN               RCC_AHB1SMENR_TSCSMEN_Msk

/********************  Bit definition for RCC_AHB2SMENR register  ***************/
#define RCC_AHB2SMENR_GPIOASMEN_Pos         (0U)
#define RCC_AHB2SMENR_GPIOASMEN_Msk         (0x1UL << RCC_AHB2SMENR_GPIOASMEN_Pos) /*!< 0x00000001 */
#define RCC_AHB2SMENR_GPIOASMEN             RCC_AHB2SMENR_GPIOASMEN_Msk
#define RCC_AHB2SMENR_GPIOBSMEN_Pos         (1U)
#define RCC_AHB2SMENR_GPIOBSMEN_Msk         (0x1UL << RCC_AHB2SMENR_GPIOBSMEN_Pos) /*!< 0x00000002 */
#define RCC_AHB2SMENR_GPIOBSMEN             RCC_AHB2SMENR_GPIOBSMEN_Msk
#define RCC_AHB2SMENR_GPIOCSMEN_Pos         (2U)
#define RCC_AHB2SMENR_GPIOCSMEN_Msk         (0x1UL << RCC_AHB2SMENR_GPIOCSMEN_Pos) /*!< 0x00000004 */
#define RCC_AHB2SMENR_GPIOCSMEN             RCC_AHB2SMENR_GPIOCSMEN_Msk
#define RCC_AHB2SMENR_GPIOESMEN_Pos         (4U)
#define RCC_AHB2SMENR_GPIOESMEN_Msk         (0x1UL << RCC_AHB2SMENR_GPIOESMEN_Pos) /*!< 0x00000010 */
#define RCC_AHB2SMENR_GPIOESMEN             RCC_AHB2SMENR_GPIOESMEN_Msk
#define RCC_AHB2SMENR_GPIOHSMEN_Pos         (7U)
#define RCC_AHB2SMENR_GPIOHSMEN_Msk         (0x1UL << RCC_AHB2SMENR_GPIOHSMEN_Pos) /*!< 0x00000080 */
#define RCC_AHB2SMENR_GPIOHSMEN             RCC_AHB2SMENR_GPIOHSMEN_Msk

/********************  Bit definition for RCC_AHB3SMENR register  ***************/
#define RCC_AHB3SMENR_PKASMEN_Pos           (16U)
#define RCC_AHB3SMENR_PKASMEN_Msk           (0x1UL << RCC_AHB3SMENR_PKASMEN_Pos) /*!< 0x00010000 */
#define RCC_AHB3SMENR_PKASMEN               RCC_AHB3SMENR_PKASMEN_Msk
#define RCC_AHB3SMENR_AES2SMEN_Pos          (17U)
#define RCC_AHB3SMENR_AES2SMEN_Msk          (0x1UL << RCC_AHB3SMENR_AES2SMEN_Pos) /*!< 0x00020000 */
#define RCC_AHB3SMENR_AES2SMEN              RCC_AHB3SMENR_AES2SMEN_Msk
#define RCC_AHB3SMENR_RNGSMEN_Pos           (18U)
#define RCC_AHB3SMENR_RNGSMEN_Msk           (0x1UL << RCC_AHB3SMENR_RNGSMEN_Pos) /*!< 0x00040000 */
#define RCC_AHB3SMENR_RNGSMEN                RCC_AHB3SMENR_RNGSMEN_Msk
#define RCC_AHB3SMENR_SRAM2SMEN_Pos         (24U)
#define RCC_AHB3SMENR_SRAM2SMEN_Msk         (0x1UL << RCC_AHB3SMENR_SRAM2SMEN_Pos) /*!< 0x01000000 */
#define RCC_AHB3SMENR_SRAM2SMEN             RCC_AHB3SMENR_SRAM2SMEN_Msk
#define RCC_AHB3SMENR_FLASHSMEN_Pos         (25U)
#define RCC_AHB3SMENR_FLASHSMEN_Msk         (0x1UL << RCC_AHB3SMENR_FLASHSMEN_Pos) /*!< 0x02000000 */
#define RCC_AHB3SMENR_FLASHSMEN             RCC_AHB3SMENR_FLASHSMEN_Msk

/********************  Bit definition for RCC_APB1SMENR1 register  **************/
#define RCC_APB1SMENR1_TIM2SMEN_Pos         (0U)
#define RCC_APB1SMENR1_TIM2SMEN_Msk         (0x1UL << RCC_APB1SMENR1_TIM2SMEN_Pos) /*!< 0x00000001 */
#define RCC_APB1SMENR1_TIM2SMEN             RCC_APB1SMENR1_TIM2SMEN_Msk
#define RCC_APB1SMENR1_RTCAPBSMEN_Pos       (10U)
#define RCC_APB1SMENR1_RTCAPBSMEN_Msk       (0x1UL << RCC_APB1SMENR1_RTCAPBSMEN_Pos) /*!< 0x00000400 */
#define RCC_APB1SMENR1_RTCAPBSMEN           RCC_APB1SMENR1_RTCAPBSMEN_Msk
#define RCC_APB1SMENR1_WWDGSMEN_Pos         (11U)
#define RCC_APB1SMENR1_WWDGSMEN_Msk         (0x1UL << RCC_APB1SMENR1_WWDGSMEN_Pos) /*!< 0x00000800 */
#define RCC_APB1SMENR1_WWDGSMEN             RCC_APB1SMENR1_WWDGSMEN_Msk
#define RCC_APB1SMENR1_I2C1SMEN_Pos         (21U)
#define RCC_APB1SMENR1_I2C1SMEN_Msk         (0x1UL << RCC_APB1SMENR1_I2C1SMEN_Pos) /*!< 0x00200000 */
#define RCC_APB1SMENR1_I2C1SMEN             RCC_APB1SMENR1_I2C1SMEN_Msk
#define RCC_APB1SMENR1_LPTIM1SMEN_Pos       (31U)
#define RCC_APB1SMENR1_LPTIM1SMEN_Msk       (0x1UL << RCC_APB1SMENR1_LPTIM1SMEN_Pos) /*!< 0x80000000 */
#define RCC_APB1SMENR1_LPTIM1SMEN           RCC_APB1SMENR1_LPTIM1SMEN_Msk

/********************  Bit definition for RCC_APB1SMENR2 register  **************/
#define RCC_APB1SMENR2_LPUART1SMEN_Pos      (0U)
#define RCC_APB1SMENR2_LPUART1SMEN_Msk      (0x1UL << RCC_APB1SMENR2_LPUART1SMEN_Pos) /*!< 0x00000001 */
#define RCC_APB1SMENR2_LPUART1SMEN          RCC_APB1SMENR2_LPUART1SMEN_Msk
#define RCC_APB1SMENR2_LPTIM2SMEN_Pos       (5U)
#define RCC_APB1SMENR2_LPTIM2SMEN_Msk       (0x1UL << RCC_APB1SMENR2_LPTIM2SMEN_Pos) /*!< 0x00000020 */
#define RCC_APB1SMENR2_LPTIM2SMEN           RCC_APB1SMENR2_LPTIM2SMEN_Msk

/********************  Bit definition for RCC_APB2SMENR register  **************/
#define RCC_APB2SMENR_ADCSMEN_Pos           (9U)
#define RCC_APB2SMENR_ADCSMEN_Msk           (0x1UL << RCC_APB2SMENR_ADCSMEN_Pos)    /*!< 0x00000200 */
#define RCC_APB2SMENR_ADCSMEN               RCC_APB2SMENR_ADCSMEN_Msk
#define RCC_APB2SMENR_TIM1SMEN_Pos          (11U)
#define RCC_APB2SMENR_TIM1SMEN_Msk          (0x1UL << RCC_APB2SMENR_TIM1SMEN_Pos)   /*!< 0x00000800 */
#define RCC_APB2SMENR_TIM1SMEN              RCC_APB2SMENR_TIM1SMEN_Msk
#define RCC_APB2SMENR_SPI1SMEN_Pos          (12U)
#define RCC_APB2SMENR_SPI1SMEN_Msk          (0x1UL << RCC_APB2SMENR_SPI1SMEN_Pos)   /*!< 0x00001000 */
#define RCC_APB2SMENR_SPI1SMEN              RCC_APB2SMENR_SPI1SMEN_Msk
#define RCC_APB2SMENR_USART1SMEN_Pos        (14U)
#define RCC_APB2SMENR_USART1SMEN_Msk        (0x1UL << RCC_APB2SMENR_USART1SMEN_Pos) /*!< 0x00004000 */
#define RCC_APB2SMENR_USART1SMEN            RCC_APB2SMENR_USART1SMEN_Msk

/********************  Bit definition for RCC_CCIPR register  ******************/
#define RCC_CCIPR_USART1SEL_Pos             (0U)
#define RCC_CCIPR_USART1SEL_Msk             (0x3UL << RCC_CCIPR_USART1SEL_Pos) /*!< 0x00000003 */
#define RCC_CCIPR_USART1SEL                 RCC_CCIPR_USART1SEL_Msk
#define RCC_CCIPR_USART1SEL_0               (0x1U << RCC_CCIPR_USART1SEL_Pos)  /*!< 0x00000001 */
#define RCC_CCIPR_USART1SEL_1               (0x2U << RCC_CCIPR_USART1SEL_Pos)  /*!< 0x00000002 */

#define RCC_CCIPR_LPUART1SEL_Pos            (10U)
#define RCC_CCIPR_LPUART1SEL_Msk            (0x3UL << RCC_CCIPR_LPUART1SEL_Pos) /*!< 0x00000C00 */
#define RCC_CCIPR_LPUART1SEL                RCC_CCIPR_LPUART1SEL_Msk
#define RCC_CCIPR_LPUART1SEL_0              (0x1U << RCC_CCIPR_LPUART1SEL_Pos)  /*!< 0x00000400 */
#define RCC_CCIPR_LPUART1SEL_1              (0x2U << RCC_CCIPR_LPUART1SEL_Pos)  /*!< 0x00000800 */

#define RCC_CCIPR_I2C1SEL_Pos               (12U)
#define RCC_CCIPR_I2C1SEL_Msk               (0x3UL << RCC_CCIPR_I2C1SEL_Pos)   /*!< 0x00003000 */
#define RCC_CCIPR_I2C1SEL                   RCC_CCIPR_I2C1SEL_Msk
#define RCC_CCIPR_I2C1SEL_0                 (0x1U << RCC_CCIPR_I2C1SEL_Pos)    /*!< 0x00001000 */
#define RCC_CCIPR_I2C1SEL_1                 (0x2U << RCC_CCIPR_I2C1SEL_Pos)    /*!< 0x00002000 */

#define RCC_CCIPR_LPTIM1SEL_Pos             (18U)
#define RCC_CCIPR_LPTIM1SEL_Msk             (0x3UL << RCC_CCIPR_LPTIM1SEL_Pos) /*!< 0x000C0000 */
#define RCC_CCIPR_LPTIM1SEL                 RCC_CCIPR_LPTIM1SEL_Msk
#define RCC_CCIPR_LPTIM1SEL_0               (0x1U << RCC_CCIPR_LPTIM1SEL_Pos)  /*!< 0x00040000 */
#define RCC_CCIPR_LPTIM1SEL_1               (0x2U << RCC_CCIPR_LPTIM1SEL_Pos)  /*!< 0x00080000 */

#define RCC_CCIPR_LPTIM2SEL_Pos             (20U)
#define RCC_CCIPR_LPTIM2SEL_Msk             (0x3UL << RCC_CCIPR_LPTIM2SEL_Pos) /*!< 0x00300000 */
#define RCC_CCIPR_LPTIM2SEL                 RCC_CCIPR_LPTIM2SEL_Msk
#define RCC_CCIPR_LPTIM2SEL_0               (0x1U << RCC_CCIPR_LPTIM2SEL_Pos)  /*!< 0x00100000 */
#define RCC_CCIPR_LPTIM2SEL_1               (0x2U << RCC_CCIPR_LPTIM2SEL_Pos)  /*!< 0x00200000 */

#define RCC_CCIPR_CLK48SEL_Pos              (26U)
#define RCC_CCIPR_CLK48SEL_Msk              (0x3UL << RCC_CCIPR_CLK48SEL_Pos)  /*!< 0x0C000000 */
#define RCC_CCIPR_CLK48SEL                  RCC_CCIPR_CLK48SEL_Msk
#define RCC_CCIPR_CLK48SEL_0                (0x1U << RCC_CCIPR_CLK48SEL_Pos)   /*!< 0x04000000 */
#define RCC_CCIPR_CLK48SEL_1                (0x2U << RCC_CCIPR_CLK48SEL_Pos)   /*!< 0x08000000 */

#define RCC_CCIPR_ADCSEL_Pos                (28U)
#define RCC_CCIPR_ADCSEL_Msk                (0x3UL << RCC_CCIPR_ADCSEL_Pos)    /*!< 0x30000000 */
#define RCC_CCIPR_ADCSEL                    RCC_CCIPR_ADCSEL_Msk
#define RCC_CCIPR_ADCSEL_0                  (0x1U << RCC_CCIPR_ADCSEL_Pos)     /*!< 0x10000000 */
#define RCC_CCIPR_ADCSEL_1                  (0x2U << RCC_CCIPR_ADCSEL_Pos)     /*!< 0x20000000 */

#define RCC_CCIPR_RNGSEL_Pos                (30U)
#define RCC_CCIPR_RNGSEL_Msk                (0x3UL << RCC_CCIPR_RNGSEL_Pos)    /*!< 0xC0000000 */
#define RCC_CCIPR_RNGSEL                    RCC_CCIPR_RNGSEL_Msk
#define RCC_CCIPR_RNGSEL_0                  (0x1U << RCC_CCIPR_RNGSEL_Pos)     /*!< 0x40000000 */
#define RCC_CCIPR_RNGSEL_1                  (0x2U << RCC_CCIPR_RNGSEL_Pos)     /*!< 0x80000000 */

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos                  (0U)
#define RCC_BDCR_LSEON_Msk                  (0x1UL << RCC_BDCR_LSEON_Pos)      /*!< 0x00000001 */
#define RCC_BDCR_LSEON                      RCC_BDCR_LSEON_Msk
#define RCC_BDCR_LSERDY_Pos                 (1U)
#define RCC_BDCR_LSERDY_Msk                 (0x1UL << RCC_BDCR_LSERDY_Pos)     /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                     RCC_BDCR_LSERDY_Msk
#define RCC_BDCR_LSEBYP_Pos                 (2U)
#define RCC_BDCR_LSEBYP_Msk                 (0x1UL << RCC_BDCR_LSEBYP_Pos)     /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                     RCC_BDCR_LSEBYP_Msk

#define RCC_BDCR_LSEDRV_Pos                 (3U)
#define RCC_BDCR_LSEDRV_Msk                 (0x3UL << RCC_BDCR_LSEDRV_Pos)     /*!< 0x00000018 */
#define RCC_BDCR_LSEDRV                     RCC_BDCR_LSEDRV_Msk
#define RCC_BDCR_LSEDRV_0                   (0x1U << RCC_BDCR_LSEDRV_Pos)      /*!< 0x00000008 */
#define RCC_BDCR_LSEDRV_1                   (0x2U << RCC_BDCR_LSEDRV_Pos)      /*!< 0x00000010 */

#define RCC_BDCR_LSECSSON_Pos               (5U)
#define RCC_BDCR_LSECSSON_Msk               (0x1UL << RCC_BDCR_LSECSSON_Pos)   /*!< 0x00000020 */
#define RCC_BDCR_LSECSSON                   RCC_BDCR_LSECSSON_Msk
#define RCC_BDCR_LSECSSD_Pos                (6U)
#define RCC_BDCR_LSECSSD_Msk                (0x1UL << RCC_BDCR_LSECSSD_Pos)    /*!< 0x00000040 */
#define RCC_BDCR_LSECSSD                    RCC_BDCR_LSECSSD_Msk

#define RCC_BDCR_RTCSEL_Pos                 (8U)
#define RCC_BDCR_RTCSEL_Msk                 (0x3UL << RCC_BDCR_RTCSEL_Pos)     /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                     RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0                   (0x1U << RCC_BDCR_RTCSEL_Pos)      /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                   (0x2U << RCC_BDCR_RTCSEL_Pos)      /*!< 0x00000200 */

#define RCC_BDCR_RTCEN_Pos                  (15U)
#define RCC_BDCR_RTCEN_Msk                  (0x1UL << RCC_BDCR_RTCEN_Pos)      /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                      RCC_BDCR_RTCEN_Msk

#define RCC_BDCR_BDRST_Pos                  (16U)
#define RCC_BDCR_BDRST_Msk                  (0x1UL << RCC_BDCR_BDRST_Pos)      /*!< 0x00010000 */
#define RCC_BDCR_BDRST                      RCC_BDCR_BDRST_Msk

#define RCC_BDCR_LSCOEN_Pos                 (24U)
#define RCC_BDCR_LSCOEN_Msk                 (0x1UL << RCC_BDCR_LSCOEN_Pos)     /*!< 0x01000000 */
#define RCC_BDCR_LSCOEN                     RCC_BDCR_LSCOEN_Msk
#define RCC_BDCR_LSCOSEL_Pos                (25U)
#define RCC_BDCR_LSCOSEL_Msk                (0x1UL << RCC_BDCR_LSCOSEL_Pos)    /*!< 0x02000000 */
#define RCC_BDCR_LSCOSEL                    RCC_BDCR_LSCOSEL_Msk

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSI1ON_Pos                  (0U)
#define RCC_CSR_LSI1ON_Msk                  (0x1UL << RCC_CSR_LSI1ON_Pos)      /*!< 0x00000001 */
#define RCC_CSR_LSI1ON                      RCC_CSR_LSI1ON_Msk
#define RCC_CSR_LSI1RDY_Pos                 (1U)
#define RCC_CSR_LSI1RDY_Msk                 (0x1UL << RCC_CSR_LSI1RDY_Pos)     /*!< 0x00000002 */
#define RCC_CSR_LSI1RDY                     RCC_CSR_LSI1RDY_Msk
#define RCC_CSR_LSI2ON_Pos                  (2U)
#define RCC_CSR_LSI2ON_Msk                  (0x1UL << RCC_CSR_LSI2ON_Pos)      /*!< 0x00000004 */
#define RCC_CSR_LSI2ON                      RCC_CSR_LSI2ON_Msk
#define RCC_CSR_LSI2RDY_Pos                 (3U)
#define RCC_CSR_LSI2RDY_Msk                 (0x1UL << RCC_CSR_LSI2RDY_Pos)     /*!< 0x00000008 */
#define RCC_CSR_LSI2RDY                     RCC_CSR_LSI2RDY_Msk
#define RCC_CSR_LSI2TRIM_Pos                (8U)
#define RCC_CSR_LSI2TRIM_Msk                (0xFUL << RCC_CSR_LSI2TRIM_Pos)      /*!< 0x00000F00 */
#define RCC_CSR_LSI2TRIM                    RCC_CSR_LSI2TRIM_Msk
#define RCC_CSR_LSI2TRIM_0                  (0x1U << RCC_CSR_LSI2TRIM_Pos)       /*!< 0x00000100 */
#define RCC_CSR_LSI2TRIM_1                  (0x2U << RCC_CSR_LSI2TRIM_Pos)       /*!< 0x00000200 */
#define RCC_CSR_LSI2TRIM_2                  (0x4U << RCC_CSR_LSI2TRIM_Pos)       /*!< 0x00000400 */
#define RCC_CSR_LSI2TRIM_3                  (0x8U << RCC_CSR_LSI2TRIM_Pos)       /*!< 0x00000800 */
#define RCC_CSR_RFWKPSEL_Pos                (14U)
#define RCC_CSR_RFWKPSEL_Msk                (0x3UL << RCC_CSR_RFWKPSEL_Pos)    /*!< 0x0000C000 */
#define RCC_CSR_RFWKPSEL                    RCC_CSR_RFWKPSEL_Msk
#define RCC_CSR_RFWKPSEL_0                  (0x1U << RCC_CSR_RFWKPSEL_Pos)     /*!< 0x00004000 */
#define RCC_CSR_RFWKPSEL_1                  (0x2U << RCC_CSR_RFWKPSEL_Pos)     /*!< 0x00008000 */
#define RCC_CSR_RFRSTS_Pos                  (16U)
#define RCC_CSR_RFRSTS_Msk                  (0x1UL << RCC_CSR_RFRSTS_Pos)      /*!< 0x00010000 */
#define RCC_CSR_RFRSTS                      RCC_CSR_RFRSTS_Msk
#define RCC_CSR_RMVF_Pos                    (23U)
#define RCC_CSR_RMVF_Msk                    (0x1UL << RCC_CSR_RMVF_Pos)        /*!< 0x00800000 */
#define RCC_CSR_RMVF                        RCC_CSR_RMVF_Msk
#define RCC_CSR_OBLRSTF_Pos                 (25U)
#define RCC_CSR_OBLRSTF_Msk                 (0x1UL << RCC_CSR_OBLRSTF_Pos)     /*!< 0x02000000 */
#define RCC_CSR_OBLRSTF                     RCC_CSR_OBLRSTF_Msk
#define RCC_CSR_PINRSTF_Pos                 (26U)
#define RCC_CSR_PINRSTF_Msk                 (0x1UL << RCC_CSR_PINRSTF_Pos)     /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                     RCC_CSR_PINRSTF_Msk
#define RCC_CSR_BORRSTF_Pos                 (27U)
#define RCC_CSR_BORRSTF_Msk                 (0x1UL << RCC_CSR_BORRSTF_Pos)     /*!< 0x08000000 */
#define RCC_CSR_BORRSTF                     RCC_CSR_BORRSTF_Msk
#define RCC_CSR_SFTRSTF_Pos                 (28U)
#define RCC_CSR_SFTRSTF_Msk                 (0x1UL << RCC_CSR_SFTRSTF_Pos)     /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                     RCC_CSR_SFTRSTF_Msk
#define RCC_CSR_IWDGRSTF_Pos                (29U)
#define RCC_CSR_IWDGRSTF_Msk                (0x1UL << RCC_CSR_IWDGRSTF_Pos)     /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                    RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos                (30U)
#define RCC_CSR_WWDGRSTF_Msk                (0x1UL << RCC_CSR_WWDGRSTF_Pos)    /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                    RCC_CSR_WWDGRSTF_Msk
#define RCC_CSR_LPWRRSTF_Pos                (31U)
#define RCC_CSR_LPWRRSTF_Msk                (0x1UL << RCC_CSR_LPWRRSTF_Pos)    /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                    RCC_CSR_LPWRRSTF_Msk

/********************  Bit definition for RCC_HSECR register  *******************/
#define RCC_HSECR_UNLOCKED_Pos              (0U)
#define RCC_HSECR_UNLOCKED_Msk              (0x1UL << RCC_HSECR_UNLOCKED_Pos)  /*!< 0x00000001 */
#define RCC_HSECR_UNLOCKED                  RCC_HSECR_UNLOCKED_Msk

#define RCC_HSECR_HSES_Pos                  (3U)
#define RCC_HSECR_HSES_Msk                  (0x1UL << RCC_HSECR_HSES_Pos)      /*!< 0x00000008 */
#define RCC_HSECR_HSES                      RCC_HSECR_HSES_Msk

#define RCC_HSECR_HSEGMC_Pos                (4U)
#define RCC_HSECR_HSEGMC_Msk                (0x7UL << RCC_HSECR_HSEGMC_Pos)       /*!< 0x00000070 */
#define RCC_HSECR_HSEGMC                    RCC_HSECR_HSEGMC_Msk
#define RCC_HSECR_HSEGMC0_Pos               (4U)
#define RCC_HSECR_HSEGMC0_Msk               (0x1UL << RCC_HSECR_HSEGMC0_Pos)      /*!< 0x00000010 */
#define RCC_HSECR_HSEGMC0                   RCC_HSECR_HSEGMC0_Msk
#define RCC_HSECR_HSEGMC1_Pos               (5U)
#define RCC_HSECR_HSEGMC1_Msk               (0x1UL << RCC_HSECR_HSEGMC1_Pos)      /*!< 0x00000020 */
#define RCC_HSECR_HSEGMC1                   RCC_HSECR_HSEGMC1_Msk
#define RCC_HSECR_HSEGMC2_Pos               (6U)
#define RCC_HSECR_HSEGMC2_Msk               (0x1UL << RCC_HSECR_HSEGMC2_Pos)      /*!< 0x00000040 */
#define RCC_HSECR_HSEGMC2                   RCC_HSECR_HSEGMC2_Msk

#define RCC_HSECR_HSETUNE_Pos              (8U)
#define RCC_HSECR_HSETUNE_Msk              (0x3FUL << RCC_HSECR_HSETUNE_Pos)   /*!< 0x00003F00 */
#define RCC_HSECR_HSETUNE                  RCC_HSECR_HSETUNE_Msk
#define RCC_HSECR_HSETUNE0_Pos             (8U)
#define RCC_HSECR_HSETUNE0_Msk             (0x1UL << RCC_HSECR_HSETUNE0_Pos)   /*!< 0x00000100 */
#define RCC_HSECR_HSETUNE0                 RCC_HSECR_HSETUNE0_Msk
#define RCC_HSECR_HSETUNE1_Pos             (9U)
#define RCC_HSECR_HSETUNE1_Msk             (0x1UL << RCC_HSECR_HSETUNE1_Pos)   /*!< 0x00000200 */
#define RCC_HSECR_HSETUNE1                 RCC_HSECR_HSETUNE1_Msk
#define RCC_HSECR_HSETUNE2_Pos             (10U)
#define RCC_HSECR_HSETUNE2_Msk             (0x1UL << RCC_HSECR_HSETUNE2_Pos)   /*!< 0x00000400 */
#define RCC_HSECR_HSETUNE2                 RCC_HSECR_HSETUNE2_Msk
#define RCC_HSECR_HSETUNE3_Pos             (11U)
#define RCC_HSECR_HSETUNE3_Msk             (0x1UL << RCC_HSECR_HSETUNE3_Pos)   /*!< 0x00000800 */
#define RCC_HSECR_HSETUNE3                 RCC_HSECR_HSETUNE3_Msk
#define RCC_HSECR_HSETUNE4_Pos             (12U)
#define RCC_HSECR_HSETUNE4_Msk             (0x1UL << RCC_HSECR_HSETUNE4_Pos)   /*!< 0x00001000 */
#define RCC_HSECR_HSETUNE4                 RCC_HSECR_HSETUNE4_Msk
#define RCC_HSECR_HSETUNE5_Pos             (13U)
#define RCC_HSECR_HSETUNE5_Msk             (0x1UL << RCC_HSECR_HSETUNE5_Pos)   /*!< 0x00002000 */
#define RCC_HSECR_HSETUNE5                 RCC_HSECR_HSETUNE5_Msk

/********************  Bit definition for RCC_EXTCFGR register  *******************/
#define RCC_EXTCFGR_SHDHPRE_Pos             (0U)
#define RCC_EXTCFGR_SHDHPRE_Msk             (0xFUL << RCC_EXTCFGR_SHDHPRE_Pos) /*!< 0x0000000F */
#define RCC_EXTCFGR_SHDHPRE                 RCC_EXTCFGR_SHDHPRE_Msk
#define RCC_EXTCFGR_SHDHPRE_0               (0x1U << RCC_EXTCFGR_SHDHPRE_Pos)  /*!< 0x00000001 */
#define RCC_EXTCFGR_SHDHPRE_1               (0x2U << RCC_EXTCFGR_SHDHPRE_Pos)  /*!< 0x00000002 */
#define RCC_EXTCFGR_SHDHPRE_2               (0x4U << RCC_EXTCFGR_SHDHPRE_Pos)  /*!< 0x00000004 */
#define RCC_EXTCFGR_SHDHPRE_3               (0x8U << RCC_EXTCFGR_SHDHPRE_Pos)  /*!< 0x00000008 */

#define RCC_EXTCFGR_C2HPRE_Pos              (4U)
#define RCC_EXTCFGR_C2HPRE_Msk              (0xFUL << RCC_EXTCFGR_C2HPRE_Pos) /*!< 0x000000F0 */
#define RCC_EXTCFGR_C2HPRE                  RCC_EXTCFGR_C2HPRE_Msk
#define RCC_EXTCFGR_C2HPRE_0                (0x1U << RCC_EXTCFGR_C2HPRE_Pos) /*!< 0x00000010 */
#define RCC_EXTCFGR_C2HPRE_1                (0x2U << RCC_EXTCFGR_C2HPRE_Pos) /*!< 0x00000020 */
#define RCC_EXTCFGR_C2HPRE_2                (0x4U << RCC_EXTCFGR_C2HPRE_Pos) /*!< 0x00000040 */
#define RCC_EXTCFGR_C2HPRE_3                (0x8U << RCC_EXTCFGR_C2HPRE_Pos) /*!< 0x00000080 */

#define RCC_EXTCFGR_SHDHPREF_Pos            (16U)
#define RCC_EXTCFGR_SHDHPREF_Msk            (0x1UL << RCC_EXTCFGR_SHDHPREF_Pos) /*!< 0x00010000 */
#define RCC_EXTCFGR_SHDHPREF                RCC_EXTCFGR_SHDHPREF_Msk
#define RCC_EXTCFGR_C2HPREF_Pos             (17U)
#define RCC_EXTCFGR_C2HPREF_Msk             (0x1UL << RCC_EXTCFGR_C2HPREF_Pos) /*!< 0x00020000 */
#define RCC_EXTCFGR_C2HPREF                 RCC_EXTCFGR_C2HPREF_Msk
#define RCC_EXTCFGR_RFCSS_Pos               (20U)
#define RCC_EXTCFGR_RFCSS_Msk               (0x1UL << RCC_EXTCFGR_RFCSS_Pos)   /*!< 0x00100000 */
#define RCC_EXTCFGR_RFCSS                   RCC_EXTCFGR_RFCSS_Msk

/********************  Bit definition for RCC_C2AHB1ENR register  ****************/
#define RCC_C2AHB1ENR_DMA1EN_Pos            (0U)
#define RCC_C2AHB1ENR_DMA1EN_Msk            (0x1UL << RCC_C2AHB1ENR_DMA1EN_Pos) /*!< 0x00000001 */
#define RCC_C2AHB1ENR_DMA1EN                RCC_C2AHB1ENR_DMA1EN_Msk
#define RCC_C2AHB1ENR_DMAMUX1EN_Pos         (2U)
#define RCC_C2AHB1ENR_DMAMUX1EN_Msk         (0x1UL << RCC_C2AHB1ENR_DMAMUX1EN_Pos) /*!< 0x00000004 */
#define RCC_C2AHB1ENR_DMAMUX1EN             RCC_C2AHB1ENR_DMAMUX1EN_Msk
#define RCC_C2AHB1ENR_SRAM1EN_Pos           (9U)
#define RCC_C2AHB1ENR_SRAM1EN_Msk           (0x1UL << RCC_C2AHB1ENR_SRAM1EN_Pos) /*!< 0x00000200 */
#define RCC_C2AHB1ENR_SRAM1EN                RCC_C2AHB1ENR_SRAM1EN_Msk
#define RCC_C2AHB1ENR_CRCEN_Pos             (12U)
#define RCC_C2AHB1ENR_CRCEN_Msk             (0x1UL << RCC_C2AHB1ENR_CRCEN_Pos) /*!< 0x00001000 */
#define RCC_C2AHB1ENR_CRCEN                  RCC_C2AHB1ENR_CRCEN_Msk
#define RCC_C2AHB1ENR_TSCEN_Pos             (16U)
#define RCC_C2AHB1ENR_TSCEN_Msk             (0x1UL << RCC_C2AHB1ENR_TSCEN_Pos) /*!< 0x00010000 */
#define RCC_C2AHB1ENR_TSCEN                 RCC_C2AHB1ENR_TSCEN_Msk

/********************  Bit definition for RCC_C2AHB2ENR register  ***************/
#define RCC_C2AHB2ENR_GPIOAEN_Pos          (0U)
#define RCC_C2AHB2ENR_GPIOAEN_Msk          (0x1UL << RCC_C2AHB2ENR_GPIOAEN_Pos) /*!< 0x00000001 */
#define RCC_C2AHB2ENR_GPIOAEN              RCC_C2AHB2ENR_GPIOAEN_Msk
#define RCC_C2AHB2ENR_GPIOBEN_Pos          (1U)
#define RCC_C2AHB2ENR_GPIOBEN_Msk          (0x1UL << RCC_C2AHB2ENR_GPIOBEN_Pos) /*!< 0x00000002 */
#define RCC_C2AHB2ENR_GPIOBEN              RCC_C2AHB2ENR_GPIOBEN_Msk
#define RCC_C2AHB2ENR_GPIOCEN_Pos          (2U)
#define RCC_C2AHB2ENR_GPIOCEN_Msk          (0x1UL << RCC_C2AHB2ENR_GPIOCEN_Pos) /*!< 0x00000004 */
#define RCC_C2AHB2ENR_GPIOCEN              RCC_C2AHB2ENR_GPIOCEN_Msk
#define RCC_C2AHB2ENR_GPIOEEN_Pos          (4U)
#define RCC_C2AHB2ENR_GPIOEEN_Msk          (0x1UL << RCC_C2AHB2ENR_GPIOEEN_Pos) /*!< 0x00000010 */
#define RCC_C2AHB2ENR_GPIOEEN              RCC_C2AHB2ENR_GPIOEEN_Msk
#define RCC_C2AHB2ENR_GPIOHEN_Pos          (7U)
#define RCC_C2AHB2ENR_GPIOHEN_Msk          (0x1UL << RCC_C2AHB2ENR_GPIOHEN_Pos) /*!< 0x00000080 */
#define RCC_C2AHB2ENR_GPIOHEN              RCC_C2AHB2ENR_GPIOHEN_Msk

/********************  Bit definition for RCC_C2AHB3ENR register  ***************/
#define RCC_C2AHB3ENR_PKAEN_Pos            (16U)
#define RCC_C2AHB3ENR_PKAEN_Msk            (0x1UL << RCC_C2AHB3ENR_PKAEN_Pos) /*!< 0x00010000 */
#define RCC_C2AHB3ENR_PKAEN                RCC_C2AHB3ENR_PKAEN_Msk
#define RCC_C2AHB3ENR_AES2EN_Pos           (17U)
#define RCC_C2AHB3ENR_AES2EN_Msk           (0x1UL << RCC_C2AHB3ENR_AES2EN_Pos) /*!< 0x00020000 */
#define RCC_C2AHB3ENR_AES2EN               RCC_C2AHB3ENR_AES2EN_Msk
#define RCC_C2AHB3ENR_RNGEN_Pos            (18U)
#define RCC_C2AHB3ENR_RNGEN_Msk            (0x1UL << RCC_C2AHB3ENR_RNGEN_Pos) /*!< 0x00040000 */
#define RCC_C2AHB3ENR_RNGEN                RCC_C2AHB3ENR_RNGEN_Msk
#define RCC_C2AHB3ENR_HSEMEN_Pos           (19U)
#define RCC_C2AHB3ENR_HSEMEN_Msk           (0x1UL << RCC_C2AHB3ENR_HSEMEN_Pos) /*!< 0x00080000 */
#define RCC_C2AHB3ENR_HSEMEN               RCC_C2AHB3ENR_HSEMEN_Msk
#define RCC_C2AHB3ENR_IPCCEN_Pos           (20U)
#define RCC_C2AHB3ENR_IPCCEN_Msk           (0x1UL << RCC_C2AHB3ENR_IPCCEN_Pos) /*!< 0x00100000 */
#define RCC_C2AHB3ENR_IPCCEN               RCC_C2AHB3ENR_IPCCEN_Msk
#define RCC_C2AHB3ENR_FLASHEN_Pos          (25U)
#define RCC_C2AHB3ENR_FLASHEN_Msk          (0x1UL << RCC_C2AHB3ENR_FLASHEN_Pos) /*!< 0x02000000 */
#define RCC_C2AHB3ENR_FLASHEN              RCC_C2AHB3ENR_FLASHEN_Msk

/********************  Bit definition for RCC_C2APB1ENR1 register  **************/
#define RCC_C2APB1ENR1_TIM2EN_Pos          (0U)
#define RCC_C2APB1ENR1_TIM2EN_Msk          (0x1UL << RCC_C2APB1ENR1_TIM2EN_Pos) /*!< 0x00000001 */
#define RCC_C2APB1ENR1_TIM2EN              RCC_C2APB1ENR1_TIM2EN_Msk
#define RCC_C2APB1ENR1_RTCAPBEN_Pos        (10U)
#define RCC_C2APB1ENR1_RTCAPBEN_Msk        (0x1UL << RCC_C2APB1ENR1_RTCAPBEN_Pos) /*!< 0x00000400 */
#define RCC_C2APB1ENR1_RTCAPBEN            RCC_C2APB1ENR1_RTCAPBEN_Msk
#define RCC_C2APB1ENR1_I2C1EN_Pos          (21U)
#define RCC_C2APB1ENR1_I2C1EN_Msk          (0x1UL << RCC_C2APB1ENR1_I2C1EN_Pos) /*!< 0x00200000 */
#define RCC_C2APB1ENR1_I2C1EN              RCC_C2APB1ENR1_I2C1EN_Msk
#define RCC_C2APB1ENR1_LPTIM1EN_Pos        (31U)
#define RCC_C2APB1ENR1_LPTIM1EN_Msk        (0x1UL << RCC_C2APB1ENR1_LPTIM1EN_Pos) /*!< 0x80000000 */
#define RCC_C2APB1ENR1_LPTIM1EN            RCC_C2APB1ENR1_LPTIM1EN_Msk

/********************  Bit definition for RCC_C2APB1ENR2 register  **************/
#define RCC_C2APB1ENR2_LPUART1EN_Pos       (0U)
#define RCC_C2APB1ENR2_LPUART1EN_Msk       (0x1UL << RCC_C2APB1ENR2_LPUART1EN_Pos) /*!< 0x00000001 */
#define RCC_C2APB1ENR2_LPUART1EN           RCC_C2APB1ENR2_LPUART1EN_Msk
#define RCC_C2APB1ENR2_LPTIM2EN_Pos        (5U)
#define RCC_C2APB1ENR2_LPTIM2EN_Msk        (0x1UL << RCC_C2APB1ENR2_LPTIM2EN_Pos) /*!< 0x00000020 */
#define RCC_C2APB1ENR2_LPTIM2EN            RCC_C2APB1ENR2_LPTIM2EN_Msk

/********************  Bit definition for RCC_C2APB2ENR register  **************/
#define RCC_C2APB2ENR_ADCEN_Pos            (9U)
#define RCC_C2APB2ENR_ADCEN_Msk            (0x1UL << RCC_C2APB2ENR_ADCEN_Pos)    /*!< 0x00000200 */
#define RCC_C2APB2ENR_ADCEN                RCC_C2APB2ENR_ADCEN_Msk
#define RCC_C2APB2ENR_TIM1EN_Pos           (11U)
#define RCC_C2APB2ENR_TIM1EN_Msk           (0x1UL << RCC_C2APB2ENR_TIM1EN_Pos)   /*!< 0x00000800 */
#define RCC_C2APB2ENR_TIM1EN               RCC_C2APB2ENR_TIM1EN_Msk
#define RCC_C2APB2ENR_SPI1EN_Pos           (12U)
#define RCC_C2APB2ENR_SPI1EN_Msk           (0x1UL << RCC_C2APB2ENR_SPI1EN_Pos)   /*!< 0x00001000 */
#define RCC_C2APB2ENR_SPI1EN               RCC_C2APB2ENR_SPI1EN_Msk
#define RCC_C2APB2ENR_USART1EN_Pos         (14U)
#define RCC_C2APB2ENR_USART1EN_Msk         (0x1UL << RCC_C2APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_C2APB2ENR_USART1EN             RCC_C2APB2ENR_USART1EN_Msk

/********************  Bit definition for RCC_C2APB3ENR register  **************/
#define RCC_C2APB3ENR_BLEEN_Pos            (0U)
#define RCC_C2APB3ENR_BLEEN_Msk            (0x1UL << RCC_C2APB3ENR_BLEEN_Pos) /*!< 0x00000001 */
#define RCC_C2APB3ENR_BLEEN                RCC_C2APB3ENR_BLEEN_Msk

/********************  Bit definition for RCC_C2AHB1SMENR register  ****************/
#define RCC_C2AHB1SMENR_DMA1SMEN_Pos       (0U)
#define RCC_C2AHB1SMENR_DMA1SMEN_Msk       (0x1UL << RCC_C2AHB1SMENR_DMA1SMEN_Pos) /*!< 0x00000001 */
#define RCC_C2AHB1SMENR_DMA1SMEN           RCC_C2AHB1SMENR_DMA1SMEN_Msk
#define RCC_C2AHB1SMENR_DMAMUX1SMEN_Pos    (2U)
#define RCC_C2AHB1SMENR_DMAMUX1SMEN_Msk    (0x1UL << RCC_C2AHB1SMENR_DMAMUX1SMEN_Pos) /*!< 0x00000004 */
#define RCC_C2AHB1SMENR_DMAMUX1SMEN        RCC_C2AHB1SMENR_DMAMUX1SMEN_Msk
#define RCC_C2AHB1SMENR_SRAM1SMEN_Pos      (9U)
#define RCC_C2AHB1SMENR_SRAM1SMEN_Msk      (0x1UL << RCC_C2AHB1SMENR_SRAM1SMEN_Pos) /*!< 0x00000200 */
#define RCC_C2AHB1SMENR_SRAM1SMEN          RCC_C2AHB1SMENR_SRAM1SMEN_Msk
#define RCC_C2AHB1SMENR_CRCSMEN_Pos        (12U)
#define RCC_C2AHB1SMENR_CRCSMEN_Msk        (0x1UL << RCC_C2AHB1SMENR_CRCSMEN_Pos) /*!< 0x00001000 */
#define RCC_C2AHB1SMENR_CRCSMEN            RCC_C2AHB1SMENR_CRCSMEN_Msk
#define RCC_C2AHB1SMENR_TSCSMEN_Pos        (16U)
#define RCC_C2AHB1SMENR_TSCSMEN_Msk        (0x1UL << RCC_C2AHB1SMENR_TSCSMEN_Pos) /*!< 0x00010000 */
#define RCC_C2AHB1SMENR_TSCSMEN            RCC_C2AHB1SMENR_TSCSMEN_Msk

/********************  Bit definition for RCC_C2AHB2SMENR register  ***************/
#define RCC_C2AHB2SMENR_GPIOASMEN_Pos      (0U)
#define RCC_C2AHB2SMENR_GPIOASMEN_Msk      (0x1UL << RCC_C2AHB2SMENR_GPIOASMEN_Pos) /*!< 0x00000001 */
#define RCC_C2AHB2SMENR_GPIOASMEN          RCC_C2AHB2SMENR_GPIOASMEN_Msk
#define RCC_C2AHB2SMENR_GPIOBSMEN_Pos      (1U)
#define RCC_C2AHB2SMENR_GPIOBSMEN_Msk      (0x1UL << RCC_C2AHB2SMENR_GPIOBSMEN_Pos) /*!< 0x00000002 */
#define RCC_C2AHB2SMENR_GPIOBSMEN          RCC_C2AHB2SMENR_GPIOBSMEN_Msk
#define RCC_C2AHB2SMENR_GPIOCSMEN_Pos      (2U)
#define RCC_C2AHB2SMENR_GPIOCSMEN_Msk      (0x1UL << RCC_C2AHB2SMENR_GPIOCSMEN_Pos) /*!< 0x00000004 */
#define RCC_C2AHB2SMENR_GPIOCSMEN          RCC_C2AHB2SMENR_GPIOCSMEN_Msk
#define RCC_C2AHB2SMENR_GPIOESMEN_Pos      (4U)
#define RCC_C2AHB2SMENR_GPIOESMEN_Msk      (0x1UL << RCC_C2AHB2SMENR_GPIOESMEN_Pos) /*!< 0x00000010 */
#define RCC_C2AHB2SMENR_GPIOESMEN          RCC_C2AHB2SMENR_GPIOESMEN_Msk
#define RCC_C2AHB2SMENR_GPIOHSMEN_Pos      (7U)
#define RCC_C2AHB2SMENR_GPIOHSMEN_Msk      (0x1UL << RCC_C2AHB2SMENR_GPIOHSMEN_Pos) /*!< 0x00000080 */
#define RCC_C2AHB2SMENR_GPIOHSMEN          RCC_C2AHB2SMENR_GPIOHSMEN_Msk

/********************  Bit definition for RCC_C2AHB3SMENR register  ***************/
#define RCC_C2AHB3SMENR_PKASMEN_Pos        (16U)
#define RCC_C2AHB3SMENR_PKASMEN_Msk        (0x1UL << RCC_C2AHB3SMENR_PKASMEN_Pos) /*!< 0x00010000 */
#define RCC_C2AHB3SMENR_PKASMEN            RCC_C2AHB3SMENR_PKASMEN_Msk
#define RCC_C2AHB3SMENR_AES2SMEN_Pos       (17U)
#define RCC_C2AHB3SMENR_AES2SMEN_Msk       (0x1UL << RCC_C2AHB3SMENR_AES2SMEN_Pos) /*!< 0x00020000 */
#define RCC_C2AHB3SMENR_AES2SMEN           RCC_C2AHB3SMENR_AES2SMEN_Msk
#define RCC_C2AHB3SMENR_RNGSMEN_Pos        (18U)
#define RCC_C2AHB3SMENR_RNGSMEN_Msk        (0x1UL << RCC_C2AHB3SMENR_RNGSMEN_Pos) /*!< 0x00040000 */
#define RCC_C2AHB3SMENR_RNGSMEN            RCC_C2AHB3SMENR_RNGSMEN_Msk
#define RCC_C2AHB3SMENR_SRAM2SMEN_Pos      (24U)
#define RCC_C2AHB3SMENR_SRAM2SMEN_Msk      (0x1UL << RCC_C2AHB3SMENR_SRAM2SMEN_Pos) /*!< 0x01000000 */
#define RCC_C2AHB3SMENR_SRAM2SMEN           RCC_C2AHB3SMENR_SRAM2SMEN_Msk
#define RCC_C2AHB3SMENR_FLASHSMEN_Pos      (25U)
#define RCC_C2AHB3SMENR_FLASHSMEN_Msk      (0x1UL << RCC_C2AHB3SMENR_FLASHSMEN_Pos) /*!< 0x02000000 */
#define RCC_C2AHB3SMENR_FLASHSMEN          RCC_C2AHB3SMENR_FLASHSMEN_Msk

/********************  Bit definition for RCC_C2APB1SMENR1 register  **************/
#define RCC_C2APB1SMENR1_TIM2SMEN_Pos      (0U)
#define RCC_C2APB1SMENR1_TIM2SMEN_Msk      (0x1UL << RCC_C2APB1SMENR1_TIM2SMEN_Pos) /*!< 0x00000001 */
#define RCC_C2APB1SMENR1_TIM2SMEN          RCC_C2APB1SMENR1_TIM2SMEN_Msk
#define RCC_C2APB1SMENR1_RTCAPBSMEN_Pos    (10U)
#define RCC_C2APB1SMENR1_RTCAPBSMEN_Msk    (0x1UL << RCC_C2APB1SMENR1_RTCAPBSMEN_Pos) /*!< 0x00000400 */
#define RCC_C2APB1SMENR1_RTCAPBSMEN        RCC_C2APB1SMENR1_RTCAPBSMEN_Msk
#define RCC_C2APB1SMENR1_I2C1SMEN_Pos      (21U)
#define RCC_C2APB1SMENR1_I2C1SMEN_Msk      (0x1UL << RCC_C2APB1SMENR1_I2C1SMEN_Pos) /*!< 0x00200000 */
#define RCC_C2APB1SMENR1_I2C1SMEN          RCC_C2APB1SMENR1_I2C1SMEN_Msk
#define RCC_C2APB1SMENR1_LPTIM1SMEN_Pos    (31U)
#define RCC_C2APB1SMENR1_LPTIM1SMEN_Msk    (0x1UL << RCC_C2APB1SMENR1_LPTIM1SMEN_Pos) /*!< 0x80000000 */
#define RCC_C2APB1SMENR1_LPTIM1SMEN        RCC_C2APB1SMENR1_LPTIM1SMEN_Msk

/********************  Bit definition for RCC_C2APB1SMENR2 register  **************/
#define RCC_C2APB1SMENR2_LPUART1SMEN_Pos    (0U)
#define RCC_C2APB1SMENR2_LPUART1SMEN_Msk    (0x1UL << RCC_C2APB1SMENR2_LPUART1SMEN_Pos) /*!< 0x00000001 */
#define RCC_C2APB1SMENR2_LPUART1SMEN        RCC_C2APB1SMENR2_LPUART1SMEN_Msk
#define RCC_C2APB1SMENR2_LPTIM2SMEN_Pos     (5U)
#define RCC_C2APB1SMENR2_LPTIM2SMEN_Msk     (0x1UL << RCC_C2APB1SMENR2_LPTIM2SMEN_Pos) /*!< 0x00000020 */
#define RCC_C2APB1SMENR2_LPTIM2SMEN         RCC_C2APB1SMENR2_LPTIM2SMEN_Msk

/********************  Bit definition for RCC_C2APB2SMENR register  **************/
#define RCC_C2APB2SMENR_ADCSMEN_Pos        (9U)
#define RCC_C2APB2SMENR_ADCSMEN_Msk        (0x1UL << RCC_C2APB2SMENR_ADCSMEN_Pos)    /*!< 0x00000200 */
#define RCC_C2APB2SMENR_ADCSMEN            RCC_C2APB2SMENR_ADCSMEN_Msk
#define RCC_C2APB2SMENR_TIM1SMEN_Pos       (11U)
#define RCC_C2APB2SMENR_TIM1SMEN_Msk       (0x1UL << RCC_C2APB2SMENR_TIM1SMEN_Pos)   /*!< 0x00000800 */
#define RCC_C2APB2SMENR_TIM1SMEN           RCC_C2APB2SMENR_TIM1SMEN_Msk
#define RCC_C2APB2SMENR_SPI1SMEN_Pos       (12U)
#define RCC_C2APB2SMENR_SPI1SMEN_Msk       (0x1UL << RCC_C2APB2SMENR_SPI1SMEN_Pos)   /*!< 0x00001000 */
#define RCC_C2APB2SMENR_SPI1SMEN           RCC_C2APB2SMENR_SPI1SMEN_Msk
#define RCC_C2APB2SMENR_USART1SMEN_Pos     (14U)
#define RCC_C2APB2SMENR_USART1SMEN_Msk     (0x1UL << RCC_C2APB2SMENR_USART1SMEN_Pos) /*!< 0x00004000 */
#define RCC_C2APB2SMENR_USART1SMEN         RCC_C2APB2SMENR_USART1SMEN_Msk

/********************  Bit definition for RCC_C2APB3SMENR register  **************/
#define RCC_C2APB3SMENR_BLESMEN_Pos        (0U)
#define RCC_C2APB3SMENR_BLESMEN_Msk        (0x1UL << RCC_C2APB3SMENR_BLESMEN_Pos) /*!< 0x00000001 */
#define RCC_C2APB3SMENR_BLESMEN            RCC_C2APB3SMENR_BLESMEN_Msk

/******************************************************************************/
/*                                                                            */
/*                                    RNG                                     */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for  register  *******************/
#define RNG_CR_RNGEN_Pos    (2U)
#define RNG_CR_RNGEN_Msk    (0x1UL << RNG_CR_RNGEN_Pos)                        /*!< 0x00000004 */
#define RNG_CR_RNGEN        RNG_CR_RNGEN_Msk
#define RNG_CR_IE_Pos       (3U)
#define RNG_CR_IE_Msk       (0x1UL << RNG_CR_IE_Pos)                           /*!< 0x00000008 */
#define RNG_CR_IE           RNG_CR_IE_Msk
#define RNG_CR_CED_Pos      (5U)
#define RNG_CR_CED_Msk      (0x1UL << RNG_CR_CED_Pos)                          /*!< 0x00000020 */
#define RNG_CR_CED          RNG_CR_CED_Msk

/********************  Bits definition for RNG_SR register  *******************/
#define RNG_SR_DRDY_Pos     (0U)
#define RNG_SR_DRDY_Msk     (0x1UL << RNG_SR_DRDY_Pos)                         /*!< 0x00000001 */
#define RNG_SR_DRDY         RNG_SR_DRDY_Msk
#define RNG_SR_CECS_Pos     (1U)
#define RNG_SR_CECS_Msk     (0x1UL << RNG_SR_CECS_Pos)                         /*!< 0x00000002 */
#define RNG_SR_CECS         RNG_SR_CECS_Msk
#define RNG_SR_SECS_Pos     (2U)
#define RNG_SR_SECS_Msk     (0x1UL << RNG_SR_SECS_Pos)                         /*!< 0x00000004 */
#define RNG_SR_SECS         RNG_SR_SECS_Msk
#define RNG_SR_CEIS_Pos     (5U)
#define RNG_SR_CEIS_Msk     (0x1UL << RNG_SR_CEIS_Pos)                         /*!< 0x00000020 */
#define RNG_SR_CEIS         RNG_SR_CEIS_Msk
#define RNG_SR_SEIS_Pos     (6U)
#define RNG_SR_SEIS_Msk     (0x1UL << RNG_SR_SEIS_Pos)                         /*!< 0x00000040 */
#define RNG_SR_SEIS         RNG_SR_SEIS_Msk

/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/*
  * @brief Specific device feature definitions
  */
#define RTC_TAMPER2_SUPPORT
#define RTC_WAKEUP_SUPPORT
#define RTC_BACKUP_SUPPORT
#define RTC_CPU2_SUPPORT_D
#define RTC_INTERNALTS_SUPPORT

/********************  Bits definition for RTC_TR register  *******************/
#define RTC_TR_PM_Pos                  (22U)
#define RTC_TR_PM_Msk                  (0x1UL << RTC_TR_PM_Pos)                /*!< 0x00400000 */
#define RTC_TR_PM                      RTC_TR_PM_Msk                           /*!< AM/PM notation */
#define RTC_TR_HT_Pos                  (20U)
#define RTC_TR_HT_Msk                  (0x3UL << RTC_TR_HT_Pos)                /*!< 0x00300000 */
#define RTC_TR_HT                      RTC_TR_HT_Msk                           /*!< Hour tens in BCD format */
#define RTC_TR_HT_0                    (0x1U << RTC_TR_HT_Pos)                 /*!< 0x00100000 */
#define RTC_TR_HT_1                    (0x2U << RTC_TR_HT_Pos)                 /*!< 0x00200000 */
#define RTC_TR_HU_Pos                  (16U)
#define RTC_TR_HU_Msk                  (0xFUL << RTC_TR_HU_Pos)                /*!< 0x000F0000 */
#define RTC_TR_HU                      RTC_TR_HU_Msk                           /*!< Hour units in BCD format */
#define RTC_TR_HU_0                    (0x1U << RTC_TR_HU_Pos)                 /*!< 0x00010000 */
#define RTC_TR_HU_1                    (0x2U << RTC_TR_HU_Pos)                 /*!< 0x00020000 */
#define RTC_TR_HU_2                    (0x4U << RTC_TR_HU_Pos)                 /*!< 0x00040000 */
#define RTC_TR_HU_3                    (0x8U << RTC_TR_HU_Pos)                 /*!< 0x00080000 */
#define RTC_TR_MNT_Pos                 (12U)
#define RTC_TR_MNT_Msk                 (0x7UL << RTC_TR_MNT_Pos)               /*!< 0x00007000 */
#define RTC_TR_MNT                     RTC_TR_MNT_Msk                          /*!< Minute tens in BCD format */
#define RTC_TR_MNT_0                   (0x1U << RTC_TR_MNT_Pos)                /*!< 0x00001000 */
#define RTC_TR_MNT_1                   (0x2U << RTC_TR_MNT_Pos)                /*!< 0x00002000 */
#define RTC_TR_MNT_2                   (0x4U << RTC_TR_MNT_Pos)                /*!< 0x00004000 */
#define RTC_TR_MNU_Pos                 (8U)
#define RTC_TR_MNU_Msk                 (0xFUL << RTC_TR_MNU_Pos)               /*!< 0x00000F00 */
#define RTC_TR_MNU                     RTC_TR_MNU_Msk                          /*!< Minute unit in BCD format */
#define RTC_TR_MNU_0                   (0x1U << RTC_TR_MNU_Pos)                /*!< 0x00000100 */
#define RTC_TR_MNU_1                   (0x2U << RTC_TR_MNU_Pos)                /*!< 0x00000200 */
#define RTC_TR_MNU_2                   (0x4U << RTC_TR_MNU_Pos)                /*!< 0x00000400 */
#define RTC_TR_MNU_3                   (0x8U << RTC_TR_MNU_Pos)                /*!< 0x00000800 */
#define RTC_TR_ST_Pos                  (4U)
#define RTC_TR_ST_Msk                  (0x7UL << RTC_TR_ST_Pos)                /*!< 0x00000070 */
#define RTC_TR_ST                      RTC_TR_ST_Msk                           /*!< Second tens in BCD format */
#define RTC_TR_ST_0                    (0x1U << RTC_TR_ST_Pos)                 /*!< 0x00000010 */
#define RTC_TR_ST_1                    (0x2U << RTC_TR_ST_Pos)                 /*!< 0x00000020 */
#define RTC_TR_ST_2                    (0x4U << RTC_TR_ST_Pos)                 /*!< 0x00000040 */
#define RTC_TR_SU_Pos                  (0U)
#define RTC_TR_SU_Msk                  (0xFUL << RTC_TR_SU_Pos)                /*!< 0x0000000F */
#define RTC_TR_SU                      RTC_TR_SU_Msk                           /*!< Second units in BCD format */
#define RTC_TR_SU_0                    (0x1U << RTC_TR_SU_Pos)                 /*!< 0x00000001 */
#define RTC_TR_SU_1                    (0x2U << RTC_TR_SU_Pos)                 /*!< 0x00000002 */
#define RTC_TR_SU_2                    (0x4U << RTC_TR_SU_Pos)                 /*!< 0x00000004 */
#define RTC_TR_SU_3                    (0x8U << RTC_TR_SU_Pos)                 /*!< 0x00000008 */

/********************  Bits definition for RTC_DR register  *******************/
#define RTC_DR_YT_Pos                  (20U)
#define RTC_DR_YT_Msk                  (0xFUL << RTC_DR_YT_Pos)                /*!< 0x00F00000 */
#define RTC_DR_YT                      RTC_DR_YT_Msk                           /*!< Year tens in BCD format */
#define RTC_DR_YT_0                    (0x1U << RTC_DR_YT_Pos)                 /*!< 0x00100000 */
#define RTC_DR_YT_1                    (0x2U << RTC_DR_YT_Pos)                 /*!< 0x00200000 */
#define RTC_DR_YT_2                    (0x4U << RTC_DR_YT_Pos)                 /*!< 0x00400000 */
#define RTC_DR_YT_3                    (0x8U << RTC_DR_YT_Pos)                 /*!< 0x00800000 */
#define RTC_DR_YU_Pos                  (16U)
#define RTC_DR_YU_Msk                  (0xFUL << RTC_DR_YU_Pos)                /*!< 0x000F0000 */
#define RTC_DR_YU                      RTC_DR_YU_Msk                           /*!< Years units in BCD format */
#define RTC_DR_YU_0                    (0x1U << RTC_DR_YU_Pos)                 /*!< 0x00010000 */
#define RTC_DR_YU_1                    (0x2U << RTC_DR_YU_Pos)                 /*!< 0x00020000 */
#define RTC_DR_YU_2                    (0x4U << RTC_DR_YU_Pos)                 /*!< 0x00040000 */
#define RTC_DR_YU_3                    (0x8U << RTC_DR_YU_Pos)                 /*!< 0x00080000 */
#define RTC_DR_WDU_Pos                 (13U)
#define RTC_DR_WDU_Msk                 (0x7UL << RTC_DR_WDU_Pos)               /*!< 0x0000E000 */
#define RTC_DR_WDU                     RTC_DR_WDU_Msk                          /*!< Week day units */
#define RTC_DR_WDU_0                   (0x1U << RTC_DR_WDU_Pos)                /*!< 0x00002000 */
#define RTC_DR_WDU_1                   (0x2U << RTC_DR_WDU_Pos)                /*!< 0x00004000 */
#define RTC_DR_WDU_2                   (0x4U << RTC_DR_WDU_Pos)                /*!< 0x00008000 */
#define RTC_DR_MT_Pos                  (12U)
#define RTC_DR_MT_Msk                  (0x1UL << RTC_DR_MT_Pos)                /*!< 0x00001000 */
#define RTC_DR_MT                      RTC_DR_MT_Msk                           /*!< Month tens in BCD format */
#define RTC_DR_MU_Pos                  (8U)
#define RTC_DR_MU_Msk                  (0xFUL << RTC_DR_MU_Pos)                /*!< 0x00000F00 */
#define RTC_DR_MU                      RTC_DR_MU_Msk                           /*!< Month units in BCD format */
#define RTC_DR_MU_0                    (0x1U << RTC_DR_MU_Pos)                 /*!< 0x00000100 */
#define RTC_DR_MU_1                    (0x2U << RTC_DR_MU_Pos)                 /*!< 0x00000200 */
#define RTC_DR_MU_2                    (0x4U << RTC_DR_MU_Pos)                 /*!< 0x00000400 */
#define RTC_DR_MU_3                    (0x8U << RTC_DR_MU_Pos)                 /*!< 0x00000800 */
#define RTC_DR_DT_Pos                  (4U)
#define RTC_DR_DT_Msk                  (0x3UL << RTC_DR_DT_Pos)                /*!< 0x00000030 */
#define RTC_DR_DT                      RTC_DR_DT_Msk                           /*!< Date tens in BCD format */
#define RTC_DR_DT_0                    (0x1U << RTC_DR_DT_Pos)                 /*!< 0x00000010 */
#define RTC_DR_DT_1                    (0x2U << RTC_DR_DT_Pos)                 /*!< 0x00000020 */
#define RTC_DR_DU_Pos                  (0U)
#define RTC_DR_DU_Msk                  (0xFUL << RTC_DR_DU_Pos)                /*!< 0x0000000F */
#define RTC_DR_DU                      RTC_DR_DU_Msk                           /*!< Date units in BCD format */
#define RTC_DR_DU_0                    (0x1U << RTC_DR_DU_Pos)                 /*!< 0x00000001 */
#define RTC_DR_DU_1                    (0x2U << RTC_DR_DU_Pos)                 /*!< 0x00000002 */
#define RTC_DR_DU_2                    (0x4U << RTC_DR_DU_Pos)                 /*!< 0x00000004 */
#define RTC_DR_DU_3                    (0x8U << RTC_DR_DU_Pos)                 /*!< 0x00000008 */

/********************  Bits definition for RTC_CR register  *******************/
#define RTC_CR_ITSE_Pos                (24U)
#define RTC_CR_ITSE_Msk                (0x1UL << RTC_CR_ITSE_Pos)              /*!< 0x01000000 */
#define RTC_CR_ITSE                    RTC_CR_ITSE_Msk                         /*!< Timestamp on internal event enable */
#define RTC_CR_COE_Pos                 (23U)
#define RTC_CR_COE_Msk                 (0x1UL << RTC_CR_COE_Pos)               /*!< 0x00800000 */
#define RTC_CR_COE                     RTC_CR_COE_Msk                          /*!< Calibration output enable */
#define RTC_CR_OSEL_Pos                (21U)
#define RTC_CR_OSEL_Msk                (0x3UL << RTC_CR_OSEL_Pos)              /*!< 0x00600000 */
#define RTC_CR_OSEL                    RTC_CR_OSEL_Msk                         /*!< Output selection */
#define RTC_CR_OSEL_0                  (0x1U << RTC_CR_OSEL_Pos)               /*!< 0x00200000 */
#define RTC_CR_OSEL_1                  (0x2U << RTC_CR_OSEL_Pos)               /*!< 0x00400000 */
#define RTC_CR_POL_Pos                 (20U)
#define RTC_CR_POL_Msk                 (0x1UL << RTC_CR_POL_Pos)               /*!< 0x00100000 */
#define RTC_CR_POL                     RTC_CR_POL_Msk                          /*!< Output polarity */
#define RTC_CR_COSEL_Pos               (19U)
#define RTC_CR_COSEL_Msk               (0x1UL << RTC_CR_COSEL_Pos)             /*!< 0x00080000 */
#define RTC_CR_COSEL                   RTC_CR_COSEL_Msk                        /*!< Calibration output selection */
#define RTC_CR_BKP_Pos                 (18U)
#define RTC_CR_BKP_Msk                 (0x1UL << RTC_CR_BKP_Pos)               /*!< 0x00040000 */
#define RTC_CR_BKP                     RTC_CR_BKP_Msk                          /*!< Backup */
#define RTC_CR_SUB1H_Pos               (17U)
#define RTC_CR_SUB1H_Msk               (0x1UL << RTC_CR_SUB1H_Pos)             /*!< 0x00020000 */
#define RTC_CR_SUB1H                   RTC_CR_SUB1H_Msk                        /*!< Subtract 1 hour (winter time change) */
#define RTC_CR_ADD1H_Pos               (16U)
#define RTC_CR_ADD1H_Msk               (0x1UL << RTC_CR_ADD1H_Pos)             /*!< 0x00010000 */
#define RTC_CR_ADD1H                   RTC_CR_ADD1H_Msk                        /*!< Add 1 hour (summer time change) */
#define RTC_CR_TSIE_Pos                (15U)
#define RTC_CR_TSIE_Msk                (0x1UL << RTC_CR_TSIE_Pos)              /*!< 0x00008000 */
#define RTC_CR_TSIE                    RTC_CR_TSIE_Msk                         /*!< Time-stamp interrupt enable */
#define RTC_CR_WUTIE_Pos               (14U)
#define RTC_CR_WUTIE_Msk               (0x1UL << RTC_CR_WUTIE_Pos)             /*!< 0x00004000 */
#define RTC_CR_WUTIE                   RTC_CR_WUTIE_Msk                        /*!< Wakeup timer interrupt enable */
#define RTC_CR_ALRBIE_Pos              (13U)
#define RTC_CR_ALRBIE_Msk              (0x1UL << RTC_CR_ALRBIE_Pos)            /*!< 0x00002000 */
#define RTC_CR_ALRBIE                  RTC_CR_ALRBIE_Msk                       /*!< Alarm B interrupt enable */
#define RTC_CR_ALRAIE_Pos              (12U)
#define RTC_CR_ALRAIE_Msk              (0x1UL << RTC_CR_ALRAIE_Pos)            /*!< 0x00001000 */
#define RTC_CR_ALRAIE                  RTC_CR_ALRAIE_Msk                       /*!< Alarm A interrupt enable */
#define RTC_CR_TSE_Pos                 (11U)
#define RTC_CR_TSE_Msk                 (0x1UL << RTC_CR_TSE_Pos)               /*!< 0x00000800 */
#define RTC_CR_TSE                     RTC_CR_TSE_Msk                          /*!< Timestamp on RTC TS input edge enable */
#define RTC_CR_WUTE_Pos                (10U)
#define RTC_CR_WUTE_Msk                (0x1UL << RTC_CR_WUTE_Pos)              /*!< 0x00000400 */
#define RTC_CR_WUTE                    RTC_CR_WUTE_Msk                         /*!< Wakeup timer enable */
#define RTC_CR_ALRBE_Pos               (9U)
#define RTC_CR_ALRBE_Msk               (0x1UL << RTC_CR_ALRBE_Pos)             /*!< 0x00000200 */
#define RTC_CR_ALRBE                   RTC_CR_ALRBE_Msk                        /*!< Alarm B enable */
#define RTC_CR_ALRAE_Pos               (8U)
#define RTC_CR_ALRAE_Msk               (0x1UL << RTC_CR_ALRAE_Pos)             /*!< 0x00000100 */
#define RTC_CR_ALRAE                   RTC_CR_ALRAE_Msk                        /*!< Alarm A enable */
#define RTC_CR_FMT_Pos                 (6U)
#define RTC_CR_FMT_Msk                 (0x1UL << RTC_CR_FMT_Pos)               /*!< 0x00000040 */
#define RTC_CR_FMT                     RTC_CR_FMT_Msk                          /*!< Hour AM/PM or 24H format */
#define RTC_CR_BYPSHAD_Pos             (5U)
#define RTC_CR_BYPSHAD_Msk             (0x1UL << RTC_CR_BYPSHAD_Pos)           /*!< 0x00000020 */
#define RTC_CR_BYPSHAD                 RTC_CR_BYPSHAD_Msk                      /*!< Bypass the shadow registers */
#define RTC_CR_REFCKON_Pos             (4U)
#define RTC_CR_REFCKON_Msk             (0x1UL << RTC_CR_REFCKON_Pos)           /*!< 0x00000010 */
#define RTC_CR_REFCKON                 RTC_CR_REFCKON_Msk                      /*!< RTC_REFIN reference clock detection enable (50 or 60 Hz) */
#define RTC_CR_TSEDGE_Pos              (3U)
#define RTC_CR_TSEDGE_Msk              (0x1UL << RTC_CR_TSEDGE_Pos)            /*!< 0x00000008 */
#define RTC_CR_TSEDGE                  RTC_CR_TSEDGE_Msk                       /*!< Timestamp event active edge */
#define RTC_CR_WUCKSEL_Pos             (0U)
#define RTC_CR_WUCKSEL_Msk             (0x7UL << RTC_CR_WUCKSEL_Pos)           /*!< 0x00000007 */
#define RTC_CR_WUCKSEL                 RTC_CR_WUCKSEL_Msk                      /*!< Wakekup clock selection */
#define RTC_CR_WUCKSEL_0               (0x1U << RTC_CR_WUCKSEL_Pos)            /*!< 0x00000001 */
#define RTC_CR_WUCKSEL_1               (0x2U << RTC_CR_WUCKSEL_Pos)            /*!< 0x00000002 */
#define RTC_CR_WUCKSEL_2               (0x4U << RTC_CR_WUCKSEL_Pos)            /*!< 0x00000004 */

/********************  Bits definition for RTC_ISR register  ******************/
#define RTC_ISR_ITSF_Pos               (17U)
#define RTC_ISR_ITSF_Msk               (0x1UL << RTC_ISR_ITSF_Pos)             /*!< 0x00020000 */
#define RTC_ISR_ITSF                   RTC_ISR_ITSF_Msk                        /*!< Internal timestamp flag */
#define RTC_ISR_RECALPF_Pos            (16U)
#define RTC_ISR_RECALPF_Msk            (0x1UL << RTC_ISR_RECALPF_Pos)          /*!< 0x00010000 */
#define RTC_ISR_RECALPF                RTC_ISR_RECALPF_Msk                     /*!< Recalibration pending flag */
#define RTC_ISR_TAMP2F_Pos             (14U)
#define RTC_ISR_TAMP2F_Msk             (0x1UL << RTC_ISR_TAMP2F_Pos)           /*!< 0x00004000 */
#define RTC_ISR_TAMP2F                 RTC_ISR_TAMP2F_Msk                      /*!< RTC_TAMP2 detection flag */
#define RTC_ISR_TSOVF_Pos              (12U)
#define RTC_ISR_TSOVF_Msk              (0x1UL << RTC_ISR_TSOVF_Pos)            /*!< 0x00001000 */
#define RTC_ISR_TSOVF                  RTC_ISR_TSOVF_Msk                       /*!< Timestamp overflow flag */
#define RTC_ISR_TSF_Pos                (11U)
#define RTC_ISR_TSF_Msk                (0x1UL << RTC_ISR_TSF_Pos)              /*!< 0x00000800 */
#define RTC_ISR_TSF                    RTC_ISR_TSF_Msk                         /*!< Timestamp flag */
#define RTC_ISR_WUTF_Pos               (10U)
#define RTC_ISR_WUTF_Msk               (0x1UL << RTC_ISR_WUTF_Pos)             /*!< 0x00000400 */
#define RTC_ISR_WUTF                   RTC_ISR_WUTF_Msk                        /*!< Wakeup timer flag */
#define RTC_ISR_ALRBF_Pos              (9U)
#define RTC_ISR_ALRBF_Msk              (0x1UL << RTC_ISR_ALRBF_Pos)            /*!< 0x00000200 */
#define RTC_ISR_ALRBF                  RTC_ISR_ALRBF_Msk                       /*!< Alarm B flag */
#define RTC_ISR_ALRAF_Pos              (8U)
#define RTC_ISR_ALRAF_Msk              (0x1UL << RTC_ISR_ALRAF_Pos)            /*!< 0x00000100 */
#define RTC_ISR_ALRAF                  RTC_ISR_ALRAF_Msk                       /*!< Alarm A flag */
#define RTC_ISR_INIT_Pos               (7U)
#define RTC_ISR_INIT_Msk               (0x1UL << RTC_ISR_INIT_Pos)             /*!< 0x00000080 */
#define RTC_ISR_INIT                   RTC_ISR_INIT_Msk                        /*!< Initialization mode */
#define RTC_ISR_INITF_Pos              (6U)
#define RTC_ISR_INITF_Msk              (0x1UL << RTC_ISR_INITF_Pos)            /*!< 0x00000040 */
#define RTC_ISR_INITF                  RTC_ISR_INITF_Msk                       /*!< Initialization flag */
#define RTC_ISR_RSF_Pos                (5U)
#define RTC_ISR_RSF_Msk                (0x1UL << RTC_ISR_RSF_Pos)              /*!< 0x00000020 */
#define RTC_ISR_RSF                    RTC_ISR_RSF_Msk                         /*!< Registers synchronization flag */
#define RTC_ISR_INITS_Pos              (4U)
#define RTC_ISR_INITS_Msk              (0x1UL << RTC_ISR_INITS_Pos)            /*!< 0x00000010 */
#define RTC_ISR_INITS                  RTC_ISR_INITS_Msk                       /*!< Initialization status flag */
#define RTC_ISR_SHPF_Pos               (3U)
#define RTC_ISR_SHPF_Msk               (0x1UL << RTC_ISR_SHPF_Pos)             /*!< 0x00000008 */
#define RTC_ISR_SHPF                   RTC_ISR_SHPF_Msk                        /*!< Shift operation pending */
#define RTC_ISR_WUTWF_Pos              (2U)
#define RTC_ISR_WUTWF_Msk              (0x1UL << RTC_ISR_WUTWF_Pos)            /*!< 0x00000004 */
#define RTC_ISR_WUTWF                  RTC_ISR_WUTWF_Msk                       /*!< Wakeup timer write flag */
#define RTC_ISR_ALRBWF_Pos             (1U)
#define RTC_ISR_ALRBWF_Msk             (0x1UL << RTC_ISR_ALRBWF_Pos)           /*!< 0x00000002 */
#define RTC_ISR_ALRBWF                 RTC_ISR_ALRBWF_Msk                      /*!< Alarm B write flag */
#define RTC_ISR_ALRAWF_Pos             (0U)
#define RTC_ISR_ALRAWF_Msk             (0x1UL << RTC_ISR_ALRAWF_Pos)           /*!< 0x00000001 */
#define RTC_ISR_ALRAWF                 RTC_ISR_ALRAWF_Msk                      /*!< Alarm A write flag */

/********************  Bits definition for RTC_PRER register  *****************/
#define RTC_PRER_PREDIV_A_Pos          (16U)
#define RTC_PRER_PREDIV_A_Msk          (0x7FUL << RTC_PRER_PREDIV_A_Pos)       /*!< 0x007F0000 */
#define RTC_PRER_PREDIV_A              RTC_PRER_PREDIV_A_Msk                   /*!< Asynchronous prescaler factor */
#define RTC_PRER_PREDIV_S_Pos          (0U)
#define RTC_PRER_PREDIV_S_Msk          (0x7FFFUL << RTC_PRER_PREDIV_S_Pos)     /*!< 0x00007FFF */
#define RTC_PRER_PREDIV_S              RTC_PRER_PREDIV_S_Msk                   /*!< Synchronous prescaler factor */

/********************  Bits definition for RTC_WUTR register  *****************/
#define RTC_WUTR_WUT_Pos               (0U)
#define RTC_WUTR_WUT_Msk               (0xFFFFUL << RTC_WUTR_WUT_Pos)          /*!< 0x0000FFFF */
#define RTC_WUTR_WUT                   RTC_WUTR_WUT_Msk                        /*!< Wakeup auto-reload value bits */

/********************  Bits definition for RTC_ALRMAR register  ***************/
#define RTC_ALRMAR_MSK4_Pos            (31U)
#define RTC_ALRMAR_MSK4_Msk            (0x1UL << RTC_ALRMAR_MSK4_Pos)          /*!< 0x80000000 */
#define RTC_ALRMAR_MSK4                RTC_ALRMAR_MSK4_Msk                     /*!< Alarm A date mask */
#define RTC_ALRMAR_WDSEL_Pos           (30U)
#define RTC_ALRMAR_WDSEL_Msk           (0x1UL << RTC_ALRMAR_WDSEL_Pos)         /*!< 0x40000000 */
#define RTC_ALRMAR_WDSEL               RTC_ALRMAR_WDSEL_Msk                    /*!< Alarm A week day selection */
#define RTC_ALRMAR_DT_Pos              (28U)
#define RTC_ALRMAR_DT_Msk              (0x3UL << RTC_ALRMAR_DT_Pos)            /*!< 0x30000000 */
#define RTC_ALRMAR_DT                  RTC_ALRMAR_DT_Msk                       /*!< Alarm A date tens in BCD format */
#define RTC_ALRMAR_DT_0                (0x1U << RTC_ALRMAR_DT_Pos)             /*!< 0x10000000 */
#define RTC_ALRMAR_DT_1                (0x2U << RTC_ALRMAR_DT_Pos)             /*!< 0x20000000 */
#define RTC_ALRMAR_DU_Pos              (24U)
#define RTC_ALRMAR_DU_Msk              (0xFUL << RTC_ALRMAR_DU_Pos)            /*!< 0x0F000000 */
#define RTC_ALRMAR_DU                  RTC_ALRMAR_DU_Msk                       /*!< Alarm A date units in BCD format */
#define RTC_ALRMAR_DU_0                (0x1U << RTC_ALRMAR_DU_Pos)             /*!< 0x01000000 */
#define RTC_ALRMAR_DU_1                (0x2U << RTC_ALRMAR_DU_Pos)             /*!< 0x02000000 */
#define RTC_ALRMAR_DU_2                (0x4U << RTC_ALRMAR_DU_Pos)             /*!< 0x04000000 */
#define RTC_ALRMAR_DU_3                (0x8U << RTC_ALRMAR_DU_Pos)             /*!< 0x08000000 */
#define RTC_ALRMAR_MSK3_Pos            (23U)
#define RTC_ALRMAR_MSK3_Msk            (0x1UL << RTC_ALRMAR_MSK3_Pos)          /*!< 0x00800000 */
#define RTC_ALRMAR_MSK3                RTC_ALRMAR_MSK3_Msk                     /*!< Alarm A hours mask */
#define RTC_ALRMAR_PM_Pos              (22U)
#define RTC_ALRMAR_PM_Msk              (0x1UL << RTC_ALRMAR_PM_Pos)            /*!< 0x00400000 */
#define RTC_ALRMAR_PM                  RTC_ALRMAR_PM_Msk                       /*!< Alarm A AM/PM or 24H format */
#define RTC_ALRMAR_HT_Pos              (20U)
#define RTC_ALRMAR_HT_Msk              (0x3UL << RTC_ALRMAR_HT_Pos)            /*!< 0x00300000 */
#define RTC_ALRMAR_HT                  RTC_ALRMAR_HT_Msk                       /*!< Alarm A hour tens in BCD format */
#define RTC_ALRMAR_HT_0                (0x1U << RTC_ALRMAR_HT_Pos)             /*!< 0x00100000 */
#define RTC_ALRMAR_HT_1                (0x2U << RTC_ALRMAR_HT_Pos)             /*!< 0x00200000 */
#define RTC_ALRMAR_HU_Pos              (16U)
#define RTC_ALRMAR_HU_Msk              (0xFUL << RTC_ALRMAR_HU_Pos)            /*!< 0x000F0000 */
#define RTC_ALRMAR_HU                  RTC_ALRMAR_HU_Msk                       /*!< Alarm A hour units in BCD format */
#define RTC_ALRMAR_HU_0                (0x1U << RTC_ALRMAR_HU_Pos)             /*!< 0x00010000 */
#define RTC_ALRMAR_HU_1                (0x2U << RTC_ALRMAR_HU_Pos)             /*!< 0x00020000 */
#define RTC_ALRMAR_HU_2                (0x4U << RTC_ALRMAR_HU_Pos)             /*!< 0x00040000 */
#define RTC_ALRMAR_HU_3                (0x8U << RTC_ALRMAR_HU_Pos)             /*!< 0x00080000 */
#define RTC_ALRMAR_MSK2_Pos            (15U)
#define RTC_ALRMAR_MSK2_Msk            (0x1UL << RTC_ALRMAR_MSK2_Pos)          /*!< 0x00008000 */
#define RTC_ALRMAR_MSK2                RTC_ALRMAR_MSK2_Msk                     /*!< Alarm A minutes mask */
#define RTC_ALRMAR_MNT_Pos             (12U)
#define RTC_ALRMAR_MNT_Msk             (0x7UL << RTC_ALRMAR_MNT_Pos)           /*!< 0x00007000 */
#define RTC_ALRMAR_MNT                 RTC_ALRMAR_MNT_Msk                      /*!< Alarm A minute tens in BCD format */
#define RTC_ALRMAR_MNT_0               (0x1U << RTC_ALRMAR_MNT_Pos)            /*!< 0x00001000 */
#define RTC_ALRMAR_MNT_1               (0x2U << RTC_ALRMAR_MNT_Pos)            /*!< 0x00002000 */
#define RTC_ALRMAR_MNT_2               (0x4U << RTC_ALRMAR_MNT_Pos)            /*!< 0x00004000 */
#define RTC_ALRMAR_MNU_Pos             (8U)
#define RTC_ALRMAR_MNU_Msk             (0xFUL << RTC_ALRMAR_MNU_Pos)           /*!< 0x00000F00 */
#define RTC_ALRMAR_MNU                 RTC_ALRMAR_MNU_Msk                      /*!< Alarm A minute units in BCD format */
#define RTC_ALRMAR_MNU_0               (0x1U << RTC_ALRMAR_MNU_Pos)            /*!< 0x00000100 */
#define RTC_ALRMAR_MNU_1               (0x2U << RTC_ALRMAR_MNU_Pos)            /*!< 0x00000200 */
#define RTC_ALRMAR_MNU_2               (0x4U << RTC_ALRMAR_MNU_Pos)            /*!< 0x00000400 */
#define RTC_ALRMAR_MNU_3               (0x8U << RTC_ALRMAR_MNU_Pos)            /*!< 0x00000800 */
#define RTC_ALRMAR_MSK1_Pos            (7U)
#define RTC_ALRMAR_MSK1_Msk            (0x1UL << RTC_ALRMAR_MSK1_Pos)          /*!< 0x00000080 */
#define RTC_ALRMAR_MSK1                RTC_ALRMAR_MSK1_Msk                     /*!< Alarm A seconds mask */
#define RTC_ALRMAR_ST_Pos              (4U)
#define RTC_ALRMAR_ST_Msk              (0x7UL << RTC_ALRMAR_ST_Pos)            /*!< 0x00000070 */
#define RTC_ALRMAR_ST                  RTC_ALRMAR_ST_Msk                       /*!< Alarm A second tens in BCD format */
#define RTC_ALRMAR_ST_0                (0x1U << RTC_ALRMAR_ST_Pos)             /*!< 0x00000010 */
#define RTC_ALRMAR_ST_1                (0x2U << RTC_ALRMAR_ST_Pos)             /*!< 0x00000020 */
#define RTC_ALRMAR_ST_2                (0x4U << RTC_ALRMAR_ST_Pos)             /*!< 0x00000040 */
#define RTC_ALRMAR_SU_Pos              (0U)
#define RTC_ALRMAR_SU_Msk              (0xFUL << RTC_ALRMAR_SU_Pos)            /*!< 0x0000000F */
#define RTC_ALRMAR_SU                  RTC_ALRMAR_SU_Msk                       /*!< Alarm A second units in BCD format */
#define RTC_ALRMAR_SU_0                (0x1U << RTC_ALRMAR_SU_Pos)             /*!< 0x00000001 */
#define RTC_ALRMAR_SU_1                (0x2U << RTC_ALRMAR_SU_Pos)             /*!< 0x00000002 */
#define RTC_ALRMAR_SU_2                (0x4U << RTC_ALRMAR_SU_Pos)             /*!< 0x00000004 */
#define RTC_ALRMAR_SU_3                (0x8U << RTC_ALRMAR_SU_Pos)             /*!< 0x00000008 */

/********************  Bits definition for RTC_ALRMBR register  ***************/
#define RTC_ALRMBR_MSK4_Pos            (31U)
#define RTC_ALRMBR_MSK4_Msk            (0x1UL << RTC_ALRMBR_MSK4_Pos)          /*!< 0x80000000 */
#define RTC_ALRMBR_MSK4                RTC_ALRMBR_MSK4_Msk                     /*!< Alarm B date mask */
#define RTC_ALRMBR_WDSEL_Pos           (30U)
#define RTC_ALRMBR_WDSEL_Msk           (0x1UL << RTC_ALRMBR_WDSEL_Pos)         /*!< 0x40000000 */
#define RTC_ALRMBR_WDSEL               RTC_ALRMBR_WDSEL_Msk                    /*!< Alarm B week day selection */
#define RTC_ALRMBR_DT_Pos              (28U)
#define RTC_ALRMBR_DT_Msk              (0x3UL << RTC_ALRMBR_DT_Pos)            /*!< 0x30000000 */
#define RTC_ALRMBR_DT                  RTC_ALRMBR_DT_Msk                       /*!< Alarm B data tens in BCD format */
#define RTC_ALRMBR_DT_0                (0x1U << RTC_ALRMBR_DT_Pos)             /*!< 0x10000000 */
#define RTC_ALRMBR_DT_1                (0x2U << RTC_ALRMBR_DT_Pos)             /*!< 0x20000000 */
#define RTC_ALRMBR_DU_Pos              (24U)
#define RTC_ALRMBR_DU_Msk              (0xFUL << RTC_ALRMBR_DU_Pos)            /*!< 0x0F000000 */
#define RTC_ALRMBR_DU                  RTC_ALRMBR_DU_Msk                       /*!< Alarm B data units or day in BCD format */
#define RTC_ALRMBR_DU_0                (0x1U << RTC_ALRMBR_DU_Pos)             /*!< 0x01000000 */
#define RTC_ALRMBR_DU_1                (0x2U << RTC_ALRMBR_DU_Pos)             /*!< 0x02000000 */
#define RTC_ALRMBR_DU_2                (0x4U << RTC_ALRMBR_DU_Pos)             /*!< 0x04000000 */
#define RTC_ALRMBR_DU_3                (0x8U << RTC_ALRMBR_DU_Pos)             /*!< 0x08000000 */
#define RTC_ALRMBR_MSK3_Pos            (23U)
#define RTC_ALRMBR_MSK3_Msk            (0x1UL << RTC_ALRMBR_MSK3_Pos)          /*!< 0x00800000 */
#define RTC_ALRMBR_MSK3                RTC_ALRMBR_MSK3_Msk                     /*!< Alarm B hour mask */
#define RTC_ALRMBR_PM_Pos              (22U)
#define RTC_ALRMBR_PM_Msk              (0x1UL << RTC_ALRMBR_PM_Pos)            /*!< 0x00400000 */
#define RTC_ALRMBR_PM                  RTC_ALRMBR_PM_Msk                       /*!< Alarm B AM/PM or 24H format */
#define RTC_ALRMBR_HT_Pos              (20U)
#define RTC_ALRMBR_HT_Msk              (0x3UL << RTC_ALRMBR_HT_Pos)            /*!< 0x00300000 */
#define RTC_ALRMBR_HT                  RTC_ALRMBR_HT_Msk                       /*!< Alarm B hour tens in BCD format */
#define RTC_ALRMBR_HT_0                (0x1U << RTC_ALRMBR_HT_Pos)             /*!< 0x00100000 */
#define RTC_ALRMBR_HT_1                (0x2U << RTC_ALRMBR_HT_Pos)             /*!< 0x00200000 */
#define RTC_ALRMBR_HU_Pos              (16U)
#define RTC_ALRMBR_HU_Msk              (0xFUL << RTC_ALRMBR_HU_Pos)            /*!< 0x000F0000 */
#define RTC_ALRMBR_HU                  RTC_ALRMBR_HU_Msk                       /*!< Alarm B hour units in BCD format */
#define RTC_ALRMBR_HU_0                (0x1U << RTC_ALRMBR_HU_Pos)             /*!< 0x00010000 */
#define RTC_ALRMBR_HU_1                (0x2U << RTC_ALRMBR_HU_Pos)             /*!< 0x00020000 */
#define RTC_ALRMBR_HU_2                (0x4U << RTC_ALRMBR_HU_Pos)             /*!< 0x00040000 */
#define RTC_ALRMBR_HU_3                (0x8U << RTC_ALRMBR_HU_Pos)             /*!< 0x00080000 */
#define RTC_ALRMBR_MSK2_Pos            (15U)
#define RTC_ALRMBR_MSK2_Msk            (0x1UL << RTC_ALRMBR_MSK2_Pos)          /*!< 0x00008000 */
#define RTC_ALRMBR_MSK2                RTC_ALRMBR_MSK2_Msk                     /*!< Alarm B minutes mask */
#define RTC_ALRMBR_MNT_Pos             (12U)
#define RTC_ALRMBR_MNT_Msk             (0x7UL << RTC_ALRMBR_MNT_Pos)           /*!< 0x00007000 */
#define RTC_ALRMBR_MNT                 RTC_ALRMBR_MNT_Msk                      /*!< Alarm B minute tens in BCD format */
#define RTC_ALRMBR_MNT_0               (0x1U << RTC_ALRMBR_MNT_Pos)            /*!< 0x00001000 */
#define RTC_ALRMBR_MNT_1               (0x2U << RTC_ALRMBR_MNT_Pos)            /*!< 0x00002000 */
#define RTC_ALRMBR_MNT_2               (0x4U << RTC_ALRMBR_MNT_Pos)            /*!< 0x00004000 */
#define RTC_ALRMBR_MNU_Pos             (8U)
#define RTC_ALRMBR_MNU_Msk             (0xFUL << RTC_ALRMBR_MNU_Pos)           /*!< 0x00000F00 */
#define RTC_ALRMBR_MNU                 RTC_ALRMBR_MNU_Msk                      /*!< Alarm B minute units in BCD format */
#define RTC_ALRMBR_MNU_0               (0x1U << RTC_ALRMBR_MNU_Pos)            /*!< 0x00000100 */
#define RTC_ALRMBR_MNU_1               (0x2U << RTC_ALRMBR_MNU_Pos)            /*!< 0x00000200 */
#define RTC_ALRMBR_MNU_2               (0x4U << RTC_ALRMBR_MNU_Pos)            /*!< 0x00000400 */
#define RTC_ALRMBR_MNU_3               (0x8U << RTC_ALRMBR_MNU_Pos)            /*!< 0x00000800 */
#define RTC_ALRMBR_MSK1_Pos            (7U)
#define RTC_ALRMBR_MSK1_Msk            (0x1UL << RTC_ALRMBR_MSK1_Pos)          /*!< 0x00000080 */
#define RTC_ALRMBR_MSK1                RTC_ALRMBR_MSK1_Msk                     /*!< Alarm B seconds mask */
#define RTC_ALRMBR_ST_Pos              (4U)
#define RTC_ALRMBR_ST_Msk              (0x7UL << RTC_ALRMBR_ST_Pos)            /*!< 0x00000070 */
#define RTC_ALRMBR_ST                  RTC_ALRMBR_ST_Msk                       /*!< Alarm B second tens in BCD format */
#define RTC_ALRMBR_ST_0                (0x1U << RTC_ALRMBR_ST_Pos)             /*!< 0x00000010 */
#define RTC_ALRMBR_ST_1                (0x2U << RTC_ALRMBR_ST_Pos)             /*!< 0x00000020 */
#define RTC_ALRMBR_ST_2                (0x4U << RTC_ALRMBR_ST_Pos)             /*!< 0x00000040 */
#define RTC_ALRMBR_SU_Pos              (0U)
#define RTC_ALRMBR_SU_Msk              (0xFUL << RTC_ALRMBR_SU_Pos)            /*!< 0x0000000F */
#define RTC_ALRMBR_SU                  RTC_ALRMBR_SU_Msk                       /*!< Alarm B second units in BCD format */
#define RTC_ALRMBR_SU_0                (0x1U << RTC_ALRMBR_SU_Pos)             /*!< 0x00000001 */
#define RTC_ALRMBR_SU_1                (0x2U << RTC_ALRMBR_SU_Pos)             /*!< 0x00000002 */
#define RTC_ALRMBR_SU_2                (0x4U << RTC_ALRMBR_SU_Pos)             /*!< 0x00000004 */
#define RTC_ALRMBR_SU_3                (0x8U << RTC_ALRMBR_SU_Pos)             /*!< 0x00000008 */

/********************  Bits definition for RTC_WPR register  ******************/
#define RTC_WPR_KEY_Pos                (0U)
#define RTC_WPR_KEY_Msk                (0xFFUL << RTC_WPR_KEY_Pos)             /*!< 0x000000FF */
#define RTC_WPR_KEY                    RTC_WPR_KEY_Msk                         /*!< Write protection key */

/********************  Bits definition for RTC_SSR register  ******************/
#define RTC_SSR_SS_Pos                 (0U)
#define RTC_SSR_SS_Msk                 (0xFFFFUL << RTC_SSR_SS_Pos)            /*!< 0x0000FFFF */
#define RTC_SSR_SS                     RTC_SSR_SS_Msk                          /*!< Sub second value */

/********************  Bits definition for RTC_SHIFTR register  ***************/
#define RTC_SHIFTR_SUBFS_Pos           (0U)
#define RTC_SHIFTR_SUBFS_Msk           (0x7FFFUL << RTC_SHIFTR_SUBFS_Pos)      /*!< 0x00007FFF */
#define RTC_SHIFTR_SUBFS               RTC_SHIFTR_SUBFS_Msk                    /*!< Subtract a fraction of a second */
#define RTC_SHIFTR_ADD1S_Pos           (31U)
#define RTC_SHIFTR_ADD1S_Msk           (0x1UL << RTC_SHIFTR_ADD1S_Pos)         /*!< 0x80000000 */
#define RTC_SHIFTR_ADD1S               RTC_SHIFTR_ADD1S_Msk                    /*!< Add on second */

/********************  Bits definition for RTC_TSTR register  *****************/
#define RTC_TSTR_PM_Pos                (22U)
#define RTC_TSTR_PM_Msk                (0x1UL << RTC_TSTR_PM_Pos)              /*!< 0x00400000 */
#define RTC_TSTR_PM                    RTC_TSTR_PM_Msk                         /*!< Timestamp AM/PM or 24H format */
#define RTC_TSTR_HT_Pos                (20U)
#define RTC_TSTR_HT_Msk                (0x3UL << RTC_TSTR_HT_Pos)              /*!< 0x00300000 */
#define RTC_TSTR_HT                    RTC_TSTR_HT_Msk                         /*!< Timestamp hour tens in BCD format */
#define RTC_TSTR_HT_0                  (0x1U << RTC_TSTR_HT_Pos)               /*!< 0x00100000 */
#define RTC_TSTR_HT_1                  (0x2U << RTC_TSTR_HT_Pos)               /*!< 0x00200000 */
#define RTC_TSTR_HU_Pos                (16U)
#define RTC_TSTR_HU_Msk                (0xFUL << RTC_TSTR_HU_Pos)              /*!< 0x000F0000 */
#define RTC_TSTR_HU                    RTC_TSTR_HU_Msk                         /*!< Timestamp hour units in BCD format */
#define RTC_TSTR_HU_0                  (0x1U << RTC_TSTR_HU_Pos)               /*!< 0x00010000 */
#define RTC_TSTR_HU_1                  (0x2U << RTC_TSTR_HU_Pos)               /*!< 0x00020000 */
#define RTC_TSTR_HU_2                  (0x4U << RTC_TSTR_HU_Pos)               /*!< 0x00040000 */
#define RTC_TSTR_HU_3                  (0x8U << RTC_TSTR_HU_Pos)               /*!< 0x00080000 */
#define RTC_TSTR_MNT_Pos               (12U)
#define RTC_TSTR_MNT_Msk               (0x7UL << RTC_TSTR_MNT_Pos)             /*!< 0x00007000 */
#define RTC_TSTR_MNT                   RTC_TSTR_MNT_Msk                        /*!< Timestamp minute tens in BCD format */
#define RTC_TSTR_MNT_0                 (0x1U << RTC_TSTR_MNT_Pos)              /*!< 0x00001000 */
#define RTC_TSTR_MNT_1                 (0x2U << RTC_TSTR_MNT_Pos)              /*!< 0x00002000 */
#define RTC_TSTR_MNT_2                 (0x4U << RTC_TSTR_MNT_Pos)              /*!< 0x00004000 */
#define RTC_TSTR_MNU_Pos               (8U)
#define RTC_TSTR_MNU_Msk               (0xFUL << RTC_TSTR_MNU_Pos)             /*!< 0x00000F00 */
#define RTC_TSTR_MNU                   RTC_TSTR_MNU_Msk                        /*!< Timestamp minute units in BCD format */
#define RTC_TSTR_MNU_0                 (0x1U << RTC_TSTR_MNU_Pos)              /*!< 0x00000100 */
#define RTC_TSTR_MNU_1                 (0x2U << RTC_TSTR_MNU_Pos)              /*!< 0x00000200 */
#define RTC_TSTR_MNU_2                 (0x4U << RTC_TSTR_MNU_Pos)              /*!< 0x00000400 */
#define RTC_TSTR_MNU_3                 (0x8U << RTC_TSTR_MNU_Pos)              /*!< 0x00000800 */
#define RTC_TSTR_ST_Pos                (4U)
#define RTC_TSTR_ST_Msk                (0x7UL << RTC_TSTR_ST_Pos)              /*!< 0x00000070 */
#define RTC_TSTR_ST                    RTC_TSTR_ST_Msk                         /*!< Timestamp second tens in BCD format */
#define RTC_TSTR_ST_0                  (0x1U << RTC_TSTR_ST_Pos)               /*!< 0x00000010 */
#define RTC_TSTR_ST_1                  (0x2U << RTC_TSTR_ST_Pos)               /*!< 0x00000020 */
#define RTC_TSTR_ST_2                  (0x4U << RTC_TSTR_ST_Pos)               /*!< 0x00000040 */
#define RTC_TSTR_SU_Pos                (0U)
#define RTC_TSTR_SU_Msk                (0xFUL << RTC_TSTR_SU_Pos)              /*!< 0x0000000F */
#define RTC_TSTR_SU                    RTC_TSTR_SU_Msk                         /*!< Timestamp second units in BCD format */
#define RTC_TSTR_SU_0                  (0x1U << RTC_TSTR_SU_Pos)               /*!< 0x00000001 */
#define RTC_TSTR_SU_1                  (0x2U << RTC_TSTR_SU_Pos)               /*!< 0x00000002 */
#define RTC_TSTR_SU_2                  (0x4U << RTC_TSTR_SU_Pos)               /*!< 0x00000004 */
#define RTC_TSTR_SU_3                  (0x8U << RTC_TSTR_SU_Pos)               /*!< 0x00000008 */

/********************  Bits definition for RTC_TSDR register  *****************/
#define RTC_TSDR_WDU_Pos               (13U)
#define RTC_TSDR_WDU_Msk               (0x7UL << RTC_TSDR_WDU_Pos)             /*!< 0x0000E000 */
#define RTC_TSDR_WDU                   RTC_TSDR_WDU_Msk                        /*!< Timestamp week day units */
#define RTC_TSDR_WDU_0                 (0x1U << RTC_TSDR_WDU_Pos)              /*!< 0x00002000 */
#define RTC_TSDR_WDU_1                 (0x2U << RTC_TSDR_WDU_Pos)              /*!< 0x00004000 */
#define RTC_TSDR_WDU_2                 (0x4U << RTC_TSDR_WDU_Pos)              /*!< 0x00008000 */
#define RTC_TSDR_MT_Pos                (12U)
#define RTC_TSDR_MT_Msk                (0x1UL << RTC_TSDR_MT_Pos)              /*!< 0x00001000 */
#define RTC_TSDR_MT                    RTC_TSDR_MT_Msk                         /*!< Timestamp month tens in BCD format */
#define RTC_TSDR_MU_Pos                (8U)
#define RTC_TSDR_MU_Msk                (0xFUL << RTC_TSDR_MU_Pos)              /*!< 0x00000F00 */
#define RTC_TSDR_MU                    RTC_TSDR_MU_Msk                         /*!< Timestamp month units in BCD format */
#define RTC_TSDR_MU_0                  (0x1U << RTC_TSDR_MU_Pos)               /*!< 0x00000100 */
#define RTC_TSDR_MU_1                  (0x2U << RTC_TSDR_MU_Pos)               /*!< 0x00000200 */
#define RTC_TSDR_MU_2                  (0x4U << RTC_TSDR_MU_Pos)               /*!< 0x00000400 */
#define RTC_TSDR_MU_3                  (0x8U << RTC_TSDR_MU_Pos)               /*!< 0x00000800 */
#define RTC_TSDR_DT_Pos                (4U)
#define RTC_TSDR_DT_Msk                (0x3UL << RTC_TSDR_DT_Pos)              /*!< 0x00000030 */
#define RTC_TSDR_DT                    RTC_TSDR_DT_Msk                         /*!< Timestamp date tens in BCD format */
#define RTC_TSDR_DT_0                  (0x1U << RTC_TSDR_DT_Pos)               /*!< 0x00000010 */
#define RTC_TSDR_DT_1                  (0x2U << RTC_TSDR_DT_Pos)               /*!< 0x00000020 */
#define RTC_TSDR_DU_Pos                (0U)
#define RTC_TSDR_DU_Msk                (0xFUL << RTC_TSDR_DU_Pos)              /*!< 0x0000000F */
#define RTC_TSDR_DU                    RTC_TSDR_DU_Msk                         /*!< Timestamp date units in BCD format */
#define RTC_TSDR_DU_0                  (0x1U << RTC_TSDR_DU_Pos)               /*!< 0x00000001 */
#define RTC_TSDR_DU_1                  (0x2U << RTC_TSDR_DU_Pos)               /*!< 0x00000002 */
#define RTC_TSDR_DU_2                  (0x4U << RTC_TSDR_DU_Pos)               /*!< 0x00000004 */
#define RTC_TSDR_DU_3                  (0x8U << RTC_TSDR_DU_Pos)               /*!< 0x00000008 */

/********************  Bits definition for RTC_TSSSR register  ****************/
#define RTC_TSSSR_SS_Pos               (0U)
#define RTC_TSSSR_SS_Msk               (0xFFFFUL << RTC_TSSSR_SS_Pos)          /*!< 0x0000FFFF */
#define RTC_TSSSR_SS                   RTC_TSSSR_SS_Msk                        /*!< Timestamp sub second value */

/********************  Bits definition for RTC_CALR register  *****************/
#define RTC_CALR_CALP_Pos              (15U)
#define RTC_CALR_CALP_Msk              (0x1UL << RTC_CALR_CALP_Pos)            /*!< 0x00008000 */
#define RTC_CALR_CALP                  RTC_CALR_CALP_Msk                       /*!< Increase frequency of RTC 488.5 ppm */
#define RTC_CALR_CALW8_Pos             (14U)
#define RTC_CALR_CALW8_Msk             (0x1UL << RTC_CALR_CALW8_Pos)           /*!< 0x00004000 */
#define RTC_CALR_CALW8                 RTC_CALR_CALW8_Msk                      /*!< Use a 8-second calibration cycle period */
#define RTC_CALR_CALW16_Pos            (13U)
#define RTC_CALR_CALW16_Msk            (0x1UL << RTC_CALR_CALW16_Pos)          /*!< 0x00002000 */
#define RTC_CALR_CALW16                RTC_CALR_CALW16_Msk                     /*!< Use a 16-second calibration cycle period */
#define RTC_CALR_CALM_Pos              (0U)
#define RTC_CALR_CALM_Msk              (0x1FFUL << RTC_CALR_CALM_Pos)          /*!< 0x000001FF */
#define RTC_CALR_CALM                  RTC_CALR_CALM_Msk                       /*!< Calibration minus */
#define RTC_CALR_CALM_0                (0x001U << RTC_CALR_CALM_Pos)           /*!< 0x00000001 */
#define RTC_CALR_CALM_1                (0x002U << RTC_CALR_CALM_Pos)           /*!< 0x00000002 */
#define RTC_CALR_CALM_2                (0x004U << RTC_CALR_CALM_Pos)           /*!< 0x00000004 */
#define RTC_CALR_CALM_3                (0x008U << RTC_CALR_CALM_Pos)           /*!< 0x00000008 */
#define RTC_CALR_CALM_4                (0x010U << RTC_CALR_CALM_Pos)           /*!< 0x00000010 */
#define RTC_CALR_CALM_5                (0x020U << RTC_CALR_CALM_Pos)           /*!< 0x00000020 */
#define RTC_CALR_CALM_6                (0x040U << RTC_CALR_CALM_Pos)           /*!< 0x00000040 */
#define RTC_CALR_CALM_7                (0x080U << RTC_CALR_CALM_Pos)           /*!< 0x00000080 */
#define RTC_CALR_CALM_8                (0x100U << RTC_CALR_CALM_Pos)           /*!< 0x00000100 */

/********************  Bits definition for RTC_TAMPCR register  ****************/
#define RTC_TAMPCR_TAMP2MF_Pos         (21U)
#define RTC_TAMPCR_TAMP2MF_Msk         (0x1UL << RTC_TAMPCR_TAMP2MF_Pos)       /*!< 0x00200000 */
#define RTC_TAMPCR_TAMP2MF             RTC_TAMPCR_TAMP2MF_Msk                  /*!< Tamper 2 generates a trigger event */
#define RTC_TAMPCR_TAMP2NOERASE_Pos    (20U)
#define RTC_TAMPCR_TAMP2NOERASE_Msk    (0x1UL << RTC_TAMPCR_TAMP2NOERASE_Pos)  /*!< 0x00100000 */
#define RTC_TAMPCR_TAMP2NOERASE        RTC_TAMPCR_TAMP2NOERASE_Msk             /*!< Tamper 2 no erase backup registers */
#define RTC_TAMPCR_TAMP2IE_Pos         (19U)
#define RTC_TAMPCR_TAMP2IE_Msk         (0x1UL << RTC_TAMPCR_TAMP2IE_Pos)       /*!< 0x00080000 */
#define RTC_TAMPCR_TAMP2IE             RTC_TAMPCR_TAMP2IE_Msk                  /*!< Tamper 2 interrupt enable */
#define RTC_TAMPCR_TAMPPUDIS_Pos       (15U)
#define RTC_TAMPCR_TAMPPUDIS_Msk       (0x1UL << RTC_TAMPCR_TAMPPUDIS_Pos)     /*!< 0x00008000 */
#define RTC_TAMPCR_TAMPPUDIS           RTC_TAMPCR_TAMPPUDIS_Msk                /*!< RTC_TAMPx pull-up disable */
#define RTC_TAMPCR_TAMPPRCH_Pos        (13U)
#define RTC_TAMPCR_TAMPPRCH_Msk        (0x3UL << RTC_TAMPCR_TAMPPRCH_Pos)      /*!< 0x00006000 */
#define RTC_TAMPCR_TAMPPRCH            RTC_TAMPCR_TAMPPRCH_Msk                 /*!< RTC_TAMPx precharge duration */
#define RTC_TAMPCR_TAMPPRCH_0          (0x1U << RTC_TAMPCR_TAMPPRCH_Pos)       /*!< 0x00002000 */
#define RTC_TAMPCR_TAMPPRCH_1          (0x2U << RTC_TAMPCR_TAMPPRCH_Pos)       /*!< 0x00004000 */
#define RTC_TAMPCR_TAMPFLT_Pos         (11U)
#define RTC_TAMPCR_TAMPFLT_Msk         (0x3UL << RTC_TAMPCR_TAMPFLT_Pos)       /*!< 0x00001800 */
#define RTC_TAMPCR_TAMPFLT             RTC_TAMPCR_TAMPFLT_Msk                  /*!< RTC_TAMPx filter count */
#define RTC_TAMPCR_TAMPFLT_0           (0x1U << RTC_TAMPCR_TAMPFLT_Pos)        /*!< 0x00000800 */
#define RTC_TAMPCR_TAMPFLT_1           (0x2U << RTC_TAMPCR_TAMPFLT_Pos)        /*!< 0x00001000 */
#define RTC_TAMPCR_TAMPFREQ_Pos        (8U)
#define RTC_TAMPCR_TAMPFREQ_Msk        (0x7UL << RTC_TAMPCR_TAMPFREQ_Pos)      /*!< 0x00000700 */
#define RTC_TAMPCR_TAMPFREQ            RTC_TAMPCR_TAMPFREQ_Msk                 /*!< Tamper sampling frequency */
#define RTC_TAMPCR_TAMPFREQ_0          (0x1U << RTC_TAMPCR_TAMPFREQ_Pos)       /*!< 0x00000100 */
#define RTC_TAMPCR_TAMPFREQ_1          (0x2U << RTC_TAMPCR_TAMPFREQ_Pos)       /*!< 0x00000200 */
#define RTC_TAMPCR_TAMPFREQ_2          (0x4U << RTC_TAMPCR_TAMPFREQ_Pos)       /*!< 0x00000400 */
#define RTC_TAMPCR_TAMPTS_Pos          (7U)
#define RTC_TAMPCR_TAMPTS_Msk          (0x1UL << RTC_TAMPCR_TAMPTS_Pos)        /*!< 0x00000080 */
#define RTC_TAMPCR_TAMPTS              RTC_TAMPCR_TAMPTS_Msk                   /*!< Activate timestamp on tamper detection event */
#define RTC_TAMPCR_TAMP2TRG_Pos        (4U)
#define RTC_TAMPCR_TAMP2TRG_Msk        (0x1UL << RTC_TAMPCR_TAMP2TRG_Pos)      /*!< 0x00000010 */
#define RTC_TAMPCR_TAMP2TRG            RTC_TAMPCR_TAMP2TRG_Msk                 /*!< Active level for RTC_TAMP2 input */
#define RTC_TAMPCR_TAMP2E_Pos          (3U)
#define RTC_TAMPCR_TAMP2E_Msk          (0x1UL << RTC_TAMPCR_TAMP2E_Pos)        /*!< 0x00000008 */
#define RTC_TAMPCR_TAMP2E              RTC_TAMPCR_TAMP2E_Msk                   /*!< RTC_TAMP2 detection enable */
#define RTC_TAMPCR_TAMPIE_Pos          (2U)
#define RTC_TAMPCR_TAMPIE_Msk          (0x1UL << RTC_TAMPCR_TAMPIE_Pos)        /*!< 0x00000004 */
#define RTC_TAMPCR_TAMPIE              RTC_TAMPCR_TAMPIE_Msk                   /*!< Tampers interrupt enable */

/********************  Bits definition for RTC_ALRMASSR register  *************/
#define RTC_ALRMASSR_MASKSS_Pos        (24U)
#define RTC_ALRMASSR_MASKSS_Msk        (0xFUL << RTC_ALRMASSR_MASKSS_Pos)      /*!< 0x0F000000 */
#define RTC_ALRMASSR_MASKSS            RTC_ALRMASSR_MASKSS_Msk                 /*!< Alarm A mask the most-significant bits starting at this bit */
#define RTC_ALRMASSR_MASKSS_0          (0x1U << RTC_ALRMASSR_MASKSS_Pos)       /*!< 0x01000000 */
#define RTC_ALRMASSR_MASKSS_1          (0x2U << RTC_ALRMASSR_MASKSS_Pos)       /*!< 0x02000000 */
#define RTC_ALRMASSR_MASKSS_2          (0x4U << RTC_ALRMASSR_MASKSS_Pos)       /*!< 0x04000000 */
#define RTC_ALRMASSR_MASKSS_3          (0x8U << RTC_ALRMASSR_MASKSS_Pos)       /*!< 0x08000000 */
#define RTC_ALRMASSR_SS_Pos            (0U)                                    /*!< Alarm A sub seconds value*/
#define RTC_ALRMASSR_SS_Msk            (0x7FFFUL << RTC_ALRMASSR_SS_Pos)       /*!< 0x00007FFF */
#define RTC_ALRMASSR_SS                RTC_ALRMASSR_SS_Msk

/********************  Bits definition for RTC_ALRMBSSR register  *************/
#define RTC_ALRMBSSR_MASKSS_Pos        (24U)
#define RTC_ALRMBSSR_MASKSS_Msk        (0xFUL << RTC_ALRMBSSR_MASKSS_Pos)      /*!< 0x0F000000 */
#define RTC_ALRMBSSR_MASKSS            RTC_ALRMBSSR_MASKSS_Msk                 /*!< Alarm B mask the most-significant bits starting at this bit */
#define RTC_ALRMBSSR_MASKSS_0          (0x1U << RTC_ALRMBSSR_MASKSS_Pos)       /*!< 0x01000000 */
#define RTC_ALRMBSSR_MASKSS_1          (0x2U << RTC_ALRMBSSR_MASKSS_Pos)       /*!< 0x02000000 */
#define RTC_ALRMBSSR_MASKSS_2          (0x4U << RTC_ALRMBSSR_MASKSS_Pos)       /*!< 0x04000000 */
#define RTC_ALRMBSSR_MASKSS_3          (0x8U << RTC_ALRMBSSR_MASKSS_Pos)       /*!< 0x08000000 */
#define RTC_ALRMBSSR_SS_Pos            (0U)                                    /*!< Alarm B sub seconds value*/
#define RTC_ALRMBSSR_SS_Msk            (0x7FFFUL << RTC_ALRMBSSR_SS_Pos)       /*!< 0x00007FFF */
#define RTC_ALRMBSSR_SS                RTC_ALRMBSSR_SS_Msk

/********************  Bits definition for RTC_OR register  ****************/
#define RTC_OR_OUT_RMP_Pos             (1U)
#define RTC_OR_OUT_RMP_Msk             (0x1UL << RTC_OR_OUT_RMP_Pos)       /*!< 0x00000002 */
#define RTC_OR_OUT_RMP                 RTC_OR_OUT_RMP_Msk                  /*!< RTC_OUT remap */

/********************  Bits definition for RTC_BKP0R register  ****************/
#define RTC_BKP0R_Pos                  (0U)
#define RTC_BKP0R_Msk                  (0xFFFFFFFFUL << RTC_BKP0R_Pos)         /*!< 0xFFFFFFFF */
#define RTC_BKP0R                      RTC_BKP0R_Msk                           /*!< RTC backup register 0 */

/********************  Bits definition for RTC_BKP1R register  ****************/
#define RTC_BKP1R_Pos                  (0U)
#define RTC_BKP1R_Msk                  (0xFFFFFFFFUL << RTC_BKP1R_Pos)         /*!< 0xFFFFFFFF */
#define RTC_BKP1R                      RTC_BKP1R_Msk                           /*!< RTC backup register 1 */

/********************  Bits definition for RTC_BKP2R register  ****************/
#define RTC_BKP2R_Pos                  (0U)
#define RTC_BKP2R_Msk                  (0xFFFFFFFFUL << RTC_BKP2R_Pos)         /*!< 0xFFFFFFFF */
#define RTC_BKP2R                      RTC_BKP2R_Msk                           /*!< RTC backup register 2 */

/********************  Bits definition for RTC_BKP3R register  ****************/
#define RTC_BKP3R_Pos                  (0U)
#define RTC_BKP3R_Msk                  (0xFFFFFFFFUL << RTC_BKP3R_Pos)         /*!< 0xFFFFFFFF */
#define RTC_BKP3R                      RTC_BKP3R_Msk                           /*!< RTC backup register 3 */

/********************  Bits definition for RTC_BKP4R register  ****************/
#define RTC_BKP4R_Pos                  (0U)
#define RTC_BKP4R_Msk                  (0xFFFFFFFFUL << RTC_BKP4R_Pos)         /*!< 0xFFFFFFFF */
#define RTC_BKP4R                      RTC_BKP4R_Msk                           /*!< RTC backup register 4 */

/********************  Bits definition for RTC_BKP5R register  ****************/
#define RTC_BKP5R_Pos                  (0U)
#define RTC_BKP5R_Msk                  (0xFFFFFFFFUL << RTC_BKP5R_Pos)         /*!< 0xFFFFFFFF */
#define RTC_BKP5R                      RTC_BKP5R_Msk                           /*!< RTC backup register 5 */

/********************  Bits definition for RTC_BKP6R register  ****************/
#define RTC_BKP6R_Pos                  (0U)
#define RTC_BKP6R_Msk                  (0xFFFFFFFFUL << RTC_BKP6R_Pos)         /*!< 0xFFFFFFFF */
#define RTC_BKP6R                      RTC_BKP6R_Msk                           /*!< RTC backup register 6 */

/********************  Bits definition for RTC_BKP7R register  ****************/
#define RTC_BKP7R_Pos                  (0U)
#define RTC_BKP7R_Msk                  (0xFFFFFFFFUL << RTC_BKP7R_Pos)         /*!< 0xFFFFFFFF */
#define RTC_BKP7R                      RTC_BKP7R_Msk                           /*!< RTC backup register 7 */

/********************  Bits definition for RTC_BKP8R register  ****************/
#define RTC_BKP8R_Pos                  (0U)
#define RTC_BKP8R_Msk                  (0xFFFFFFFFUL << RTC_BKP8R_Pos)         /*!< 0xFFFFFFFF */
#define RTC_BKP8R                      RTC_BKP8R_Msk                           /*!< RTC backup register 8 */

/********************  Bits definition for RTC_BKP9R register  ****************/
#define RTC_BKP9R_Pos                  (0U)
#define RTC_BKP9R_Msk                  (0xFFFFFFFFUL << RTC_BKP9R_Pos)         /*!< 0xFFFFFFFF */
#define RTC_BKP9R                      RTC_BKP9R_Msk                           /*!< RTC backup register 9 */

/********************  Bits definition for RTC_BKP10R register  ***************/
#define RTC_BKP10R_Pos                 (0U)
#define RTC_BKP10R_Msk                 (0xFFFFFFFFUL << RTC_BKP10R_Pos)        /*!< 0xFFFFFFFF */
#define RTC_BKP10R                     RTC_BKP10R_Msk                          /*!< RTC backup register 10 */

/********************  Bits definition for RTC_BKP11R register  ***************/
#define RTC_BKP11R_Pos                 (0U)
#define RTC_BKP11R_Msk                 (0xFFFFFFFFUL << RTC_BKP11R_Pos)        /*!< 0xFFFFFFFF */
#define RTC_BKP11R                     RTC_BKP11R_Msk                          /*!< RTC backup register 11 */

/********************  Bits definition for RTC_BKP12R register  ***************/
#define RTC_BKP12R_Pos                 (0U)
#define RTC_BKP12R_Msk                 (0xFFFFFFFFUL << RTC_BKP12R_Pos)        /*!< 0xFFFFFFFF */
#define RTC_BKP12R                     RTC_BKP12R_Msk                          /*!< RTC backup register 12 */

/********************  Bits definition for RTC_BKP13R register  ***************/
#define RTC_BKP13R_Pos                 (0U)
#define RTC_BKP13R_Msk                 (0xFFFFFFFFUL << RTC_BKP13R_Pos)        /*!< 0xFFFFFFFF */
#define RTC_BKP13R                     RTC_BKP13R_Msk                          /*!< RTC backup register 13 */

/********************  Bits definition for RTC_BKP14R register  ***************/
#define RTC_BKP14R_Pos                 (0U)
#define RTC_BKP14R_Msk                 (0xFFFFFFFFUL << RTC_BKP14R_Pos)        /*!< 0xFFFFFFFF */
#define RTC_BKP14R                     RTC_BKP14R_Msk                          /*!< RTC backup register 14 */

/********************  Bits definition for RTC_BKP15R register  ***************/
#define RTC_BKP15R_Pos                 (0U)
#define RTC_BKP15R_Msk                 (0xFFFFFFFFUL << RTC_BKP15R_Pos)        /*!< 0xFFFFFFFF */
#define RTC_BKP15R                     RTC_BKP15R_Msk                          /*!< RTC backup register 15 */

/********************  Bits definition for RTC_BKP16R register  ***************/
#define RTC_BKP16R_Pos                 (0U)
#define RTC_BKP16R_Msk                 (0xFFFFFFFFUL << RTC_BKP16R_Pos)        /*!< 0xFFFFFFFF */
#define RTC_BKP16R                     RTC_BKP16R_Msk                          /*!< RTC backup register 16 */

/********************  Bits definition for RTC_BKP17R register  ***************/
#define RTC_BKP17R_Pos                 (0U)
#define RTC_BKP17R_Msk                 (0xFFFFFFFFUL << RTC_BKP17R_Pos)        /*!< 0xFFFFFFFF */
#define RTC_BKP17R                     RTC_BKP17R_Msk                          /*!< RTC backup register 17 */

/********************  Bits definition for RTC_BKP18R register  ***************/
#define RTC_BKP18R_Pos                 (0U)
#define RTC_BKP18R_Msk                 (0xFFFFFFFFUL << RTC_BKP18R_Pos)        /*!< 0xFFFFFFFF */
#define RTC_BKP18R                     RTC_BKP18R_Msk                          /*!< RTC backup register 18 */

/********************  Bits definition for RTC_BKP19R register  ***************/
#define RTC_BKP19R_Pos                 (0U)
#define RTC_BKP19R_Msk                 (0xFFFFFFFFUL << RTC_BKP19R_Pos)        /*!< 0xFFFFFFFF */
#define RTC_BKP19R                     RTC_BKP19R_Msk                          /*!< RTC backup register 19 */

/******************** Number of backup registers ******************************/
#define RTC_BKP_NUMBER                 (20U)

/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface (SPI)                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for SPI_CR1 register  ********************/
#define SPI_CR1_CPHA_Pos            (0U)
#define SPI_CR1_CPHA_Msk            (0x1UL << SPI_CR1_CPHA_Pos)                /*!< 0x00000001 */
#define SPI_CR1_CPHA                SPI_CR1_CPHA_Msk                           /*!<Clock Phase      */
#define SPI_CR1_CPOL_Pos            (1U)
#define SPI_CR1_CPOL_Msk            (0x1UL << SPI_CR1_CPOL_Pos)                /*!< 0x00000002 */
#define SPI_CR1_CPOL                SPI_CR1_CPOL_Msk                           /*!<Clock Polarity   */
#define SPI_CR1_MSTR_Pos            (2U)
#define SPI_CR1_MSTR_Msk            (0x1UL << SPI_CR1_MSTR_Pos)                /*!< 0x00000004 */
#define SPI_CR1_MSTR                SPI_CR1_MSTR_Msk                           /*!<Master Selection */

#define SPI_CR1_BR_Pos              (3U)
#define SPI_CR1_BR_Msk              (0x7UL << SPI_CR1_BR_Pos)                  /*!< 0x00000038 */
#define SPI_CR1_BR                  SPI_CR1_BR_Msk                             /*!<BR[2:0] bits (Baud Rate Control) */
#define SPI_CR1_BR_0                (0x1UL << SPI_CR1_BR_Pos)                  /*!< 0x00000008 */
#define SPI_CR1_BR_1                (0x2UL << SPI_CR1_BR_Pos)                  /*!< 0x00000010 */
#define SPI_CR1_BR_2                (0x4UL << SPI_CR1_BR_Pos)                  /*!< 0x00000020 */

#define SPI_CR1_SPE_Pos             (6U)
#define SPI_CR1_SPE_Msk             (0x1UL << SPI_CR1_SPE_Pos)                 /*!< 0x00000040 */
#define SPI_CR1_SPE                 SPI_CR1_SPE_Msk                            /*!<SPI Enable                          */
#define SPI_CR1_LSBFIRST_Pos        (7U)
#define SPI_CR1_LSBFIRST_Msk        (0x1UL << SPI_CR1_LSBFIRST_Pos)            /*!< 0x00000080 */
#define SPI_CR1_LSBFIRST            SPI_CR1_LSBFIRST_Msk                       /*!<Frame Format                        */
#define SPI_CR1_SSI_Pos             (8U)
#define SPI_CR1_SSI_Msk             (0x1UL << SPI_CR1_SSI_Pos)                 /*!< 0x00000100 */
#define SPI_CR1_SSI                 SPI_CR1_SSI_Msk                            /*!<Internal slave select               */
#define SPI_CR1_SSM_Pos             (9U)
#define SPI_CR1_SSM_Msk             (0x1UL << SPI_CR1_SSM_Pos)                 /*!< 0x00000200 */
#define SPI_CR1_SSM                 SPI_CR1_SSM_Msk                            /*!<Software slave management           */
#define SPI_CR1_RXONLY_Pos          (10U)
#define SPI_CR1_RXONLY_Msk          (0x1UL << SPI_CR1_RXONLY_Pos)              /*!< 0x00000400 */
#define SPI_CR1_RXONLY              SPI_CR1_RXONLY_Msk                         /*!<Receive only                        */
#define SPI_CR1_CRCL_Pos            (11U)
#define SPI_CR1_CRCL_Msk            (0x1UL << SPI_CR1_CRCL_Pos)                /*!< 0x00000800 */
#define SPI_CR1_CRCL                SPI_CR1_CRCL_Msk                           /*!< CRC Length */
#define SPI_CR1_CRCNEXT_Pos         (12U)
#define SPI_CR1_CRCNEXT_Msk         (0x1UL << SPI_CR1_CRCNEXT_Pos)             /*!< 0x00001000 */
#define SPI_CR1_CRCNEXT             SPI_CR1_CRCNEXT_Msk                        /*!<Transmit CRC next                   */
#define SPI_CR1_CRCEN_Pos           (13U)
#define SPI_CR1_CRCEN_Msk           (0x1UL << SPI_CR1_CRCEN_Pos)               /*!< 0x00002000 */
#define SPI_CR1_CRCEN               SPI_CR1_CRCEN_Msk                          /*!<Hardware CRC calculation enable     */
#define SPI_CR1_BIDIOE_Pos          (14U)
#define SPI_CR1_BIDIOE_Msk          (0x1UL << SPI_CR1_BIDIOE_Pos)              /*!< 0x00004000 */
#define SPI_CR1_BIDIOE              SPI_CR1_BIDIOE_Msk                         /*!<Output enable in bidirectional mode */
#define SPI_CR1_BIDIMODE_Pos        (15U)
#define SPI_CR1_BIDIMODE_Msk        (0x1UL << SPI_CR1_BIDIMODE_Pos)            /*!< 0x00008000 */
#define SPI_CR1_BIDIMODE            SPI_CR1_BIDIMODE_Msk                       /*!<Bidirectional data mode enable      */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define SPI_CR2_RXDMAEN_Pos         (0U)
#define SPI_CR2_RXDMAEN_Msk         (0x1UL << SPI_CR2_RXDMAEN_Pos)             /*!< 0x00000001 */
#define SPI_CR2_RXDMAEN             SPI_CR2_RXDMAEN_Msk                        /*!< Rx Buffer DMA Enable */
#define SPI_CR2_TXDMAEN_Pos         (1U)
#define SPI_CR2_TXDMAEN_Msk         (0x1UL << SPI_CR2_TXDMAEN_Pos)             /*!< 0x00000002 */
#define SPI_CR2_TXDMAEN             SPI_CR2_TXDMAEN_Msk                        /*!< Tx Buffer DMA Enable */
#define SPI_CR2_SSOE_Pos            (2U)
#define SPI_CR2_SSOE_Msk            (0x1UL << SPI_CR2_SSOE_Pos)                /*!< 0x00000004 */
#define SPI_CR2_SSOE                SPI_CR2_SSOE_Msk                           /*!< SS Output Enable */
#define SPI_CR2_NSSP_Pos            (3U)
#define SPI_CR2_NSSP_Msk            (0x1UL << SPI_CR2_NSSP_Pos)                /*!< 0x00000008 */
#define SPI_CR2_NSSP                SPI_CR2_NSSP_Msk                           /*!< NSS pulse management Enable */
#define SPI_CR2_FRF_Pos             (4U)
#define SPI_CR2_FRF_Msk             (0x1UL << SPI_CR2_FRF_Pos)                 /*!< 0x00000010 */
#define SPI_CR2_FRF                 SPI_CR2_FRF_Msk                            /*!< Frame Format Enable */
#define SPI_CR2_ERRIE_Pos           (5U)
#define SPI_CR2_ERRIE_Msk           (0x1UL << SPI_CR2_ERRIE_Pos)               /*!< 0x00000020 */
#define SPI_CR2_ERRIE               SPI_CR2_ERRIE_Msk                          /*!< Error Interrupt Enable */
#define SPI_CR2_RXNEIE_Pos          (6U)
#define SPI_CR2_RXNEIE_Msk          (0x1UL << SPI_CR2_RXNEIE_Pos)              /*!< 0x00000040 */
#define SPI_CR2_RXNEIE              SPI_CR2_RXNEIE_Msk                         /*!< RX buffer Not Empty Interrupt Enable */
#define SPI_CR2_TXEIE_Pos           (7U)
#define SPI_CR2_TXEIE_Msk           (0x1UL << SPI_CR2_TXEIE_Pos)               /*!< 0x00000080 */
#define SPI_CR2_TXEIE               SPI_CR2_TXEIE_Msk                          /*!< Tx buffer Empty Interrupt Enable */
#define SPI_CR2_DS_Pos              (8U)
#define SPI_CR2_DS_Msk              (0xFUL << SPI_CR2_DS_Pos)                  /*!< 0x00000F00 */
#define SPI_CR2_DS                  SPI_CR2_DS_Msk                             /*!< DS[3:0] Data Size */
#define SPI_CR2_DS_0                (0x1UL << SPI_CR2_DS_Pos)                  /*!< 0x00000100 */
#define SPI_CR2_DS_1                (0x2UL << SPI_CR2_DS_Pos)                  /*!< 0x00000200 */
#define SPI_CR2_DS_2                (0x4UL << SPI_CR2_DS_Pos)                  /*!< 0x00000400 */
#define SPI_CR2_DS_3                (0x8UL << SPI_CR2_DS_Pos)                  /*!< 0x00000800 */
#define SPI_CR2_FRXTH_Pos           (12U)
#define SPI_CR2_FRXTH_Msk           (0x1UL << SPI_CR2_FRXTH_Pos)               /*!< 0x00001000 */
#define SPI_CR2_FRXTH               SPI_CR2_FRXTH_Msk                          /*!< FIFO reception Threshold */
#define SPI_CR2_LDMARX_Pos          (13U)
#define SPI_CR2_LDMARX_Msk          (0x1UL << SPI_CR2_LDMARX_Pos)              /*!< 0x00002000 */
#define SPI_CR2_LDMARX              SPI_CR2_LDMARX_Msk                         /*!< Last DMA transfer for reception */
#define SPI_CR2_LDMATX_Pos          (14U)
#define SPI_CR2_LDMATX_Msk          (0x1UL << SPI_CR2_LDMATX_Pos)              /*!< 0x00004000 */
#define SPI_CR2_LDMATX              SPI_CR2_LDMATX_Msk                         /*!< Last DMA transfer for transmission */

/********************  Bit definition for SPI_SR register  ********************/
#define SPI_SR_RXNE_Pos             (0U)
#define SPI_SR_RXNE_Msk             (0x1UL << SPI_SR_RXNE_Pos)                 /*!< 0x00000001 */
#define SPI_SR_RXNE                 SPI_SR_RXNE_Msk                            /*!< Receive buffer Not Empty */
#define SPI_SR_TXE_Pos              (1U)
#define SPI_SR_TXE_Msk              (0x1UL << SPI_SR_TXE_Pos)                  /*!< 0x00000002 */
#define SPI_SR_TXE                  SPI_SR_TXE_Msk                             /*!< Transmit buffer Empty */
#define SPI_SR_CRCERR_Pos           (4U)
#define SPI_SR_CRCERR_Msk           (0x1UL << SPI_SR_CRCERR_Pos)               /*!< 0x00000010 */
#define SPI_SR_CRCERR               SPI_SR_CRCERR_Msk                          /*!< CRC Error flag */
#define SPI_SR_MODF_Pos             (5U)
#define SPI_SR_MODF_Msk             (0x1UL << SPI_SR_MODF_Pos)                 /*!< 0x00000020 */
#define SPI_SR_MODF                 SPI_SR_MODF_Msk                            /*!< Mode fault */
#define SPI_SR_OVR_Pos              (6U)
#define SPI_SR_OVR_Msk              (0x1UL << SPI_SR_OVR_Pos)                  /*!< 0x00000040 */
#define SPI_SR_OVR                  SPI_SR_OVR_Msk                             /*!< Overrun flag */
#define SPI_SR_BSY_Pos              (7U)
#define SPI_SR_BSY_Msk              (0x1UL << SPI_SR_BSY_Pos)                  /*!< 0x00000080 */
#define SPI_SR_BSY                  SPI_SR_BSY_Msk                             /*!< Busy flag */
#define SPI_SR_FRE_Pos              (8U)
#define SPI_SR_FRE_Msk              (0x1UL << SPI_SR_FRE_Pos)                  /*!< 0x00000100 */
#define SPI_SR_FRE                  SPI_SR_FRE_Msk                             /*!< TI frame format error */
#define SPI_SR_FRLVL_Pos            (9U)
#define SPI_SR_FRLVL_Msk            (0x3UL << SPI_SR_FRLVL_Pos)                /*!< 0x00000600 */
#define SPI_SR_FRLVL                SPI_SR_FRLVL_Msk                           /*!< FIFO Reception Level */
#define SPI_SR_FRLVL_0              (0x1UL << SPI_SR_FRLVL_Pos)                /*!< 0x00000200 */
#define SPI_SR_FRLVL_1              (0x2UL << SPI_SR_FRLVL_Pos)                /*!< 0x00000400 */
#define SPI_SR_FTLVL_Pos            (11U)
#define SPI_SR_FTLVL_Msk            (0x3UL << SPI_SR_FTLVL_Pos)                /*!< 0x00001800 */
#define SPI_SR_FTLVL                SPI_SR_FTLVL_Msk                           /*!< FIFO Transmission Level */
#define SPI_SR_FTLVL_0              (0x1UL << SPI_SR_FTLVL_Pos)                /*!< 0x00000800 */
#define SPI_SR_FTLVL_1              (0x2UL << SPI_SR_FTLVL_Pos)                /*!< 0x00001000 */

/********************  Bit definition for SPI_DR register  ********************/
#define SPI_DR_DR_Pos               (0U)
#define SPI_DR_DR_Msk               (0xFFFFUL << SPI_DR_DR_Pos)                /*!< 0x0000FFFF */
#define SPI_DR_DR                   SPI_DR_DR_Msk                              /*!<Data Register           */

/*******************  Bit definition for SPI_CRCPR register  ******************/
#define SPI_CRCPR_CRCPOLY_Pos       (0U)
#define SPI_CRCPR_CRCPOLY_Msk       (0xFFFFUL << SPI_CRCPR_CRCPOLY_Pos)        /*!< 0x0000FFFF */
#define SPI_CRCPR_CRCPOLY           SPI_CRCPR_CRCPOLY_Msk                      /*!<CRC polynomial register */

/******************  Bit definition for SPI_RXCRCR register  ******************/
#define SPI_RXCRCR_RXCRC_Pos        (0U)
#define SPI_RXCRCR_RXCRC_Msk        (0xFFFFUL << SPI_RXCRCR_RXCRC_Pos)         /*!< 0x0000FFFF */
#define SPI_RXCRCR_RXCRC            SPI_RXCRCR_RXCRC_Msk                       /*!<Rx CRC Register         */

/******************  Bit definition for SPI_TXCRCR register  ******************/
#define SPI_TXCRCR_TXCRC_Pos        (0U)
#define SPI_TXCRCR_TXCRC_Msk        (0xFFFFUL << SPI_TXCRCR_TXCRC_Pos)         /*!< 0x0000FFFF */
#define SPI_TXCRCR_TXCRC            SPI_TXCRCR_TXCRC_Msk                       /*!<Tx CRC Register         */

/******************************************************************************/
/*                                                                            */
/*                          Touch Sensing Controller (TSC)                    */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TSC_CR register  *********************/
#define TSC_CR_TSCE_Pos          (0U)
#define TSC_CR_TSCE_Msk          (0x1UL << TSC_CR_TSCE_Pos)                    /*!< 0x00000001 */
#define TSC_CR_TSCE              TSC_CR_TSCE_Msk                               /*!< Touch sensing controller enable */
#define TSC_CR_START_Pos         (1U)
#define TSC_CR_START_Msk         (0x1UL << TSC_CR_START_Pos)                   /*!< 0x00000002 */
#define TSC_CR_START             TSC_CR_START_Msk                              /*!< Start a new acquisition */
#define TSC_CR_AM_Pos            (2U)
#define TSC_CR_AM_Msk            (0x1UL << TSC_CR_AM_Pos)                      /*!< 0x00000004 */
#define TSC_CR_AM                TSC_CR_AM_Msk                                 /*!< Acquisition mode */
#define TSC_CR_SYNCPOL_Pos       (3U)
#define TSC_CR_SYNCPOL_Msk       (0x1UL << TSC_CR_SYNCPOL_Pos)                 /*!< 0x00000008 */
#define TSC_CR_SYNCPOL           TSC_CR_SYNCPOL_Msk                            /*!< Synchronization pin polarity */
#define TSC_CR_IODEF_Pos         (4U)
#define TSC_CR_IODEF_Msk         (0x1UL << TSC_CR_IODEF_Pos)                   /*!< 0x00000010 */
#define TSC_CR_IODEF             TSC_CR_IODEF_Msk                              /*!< IO default mode */

#define TSC_CR_MCV_Pos           (5U)
#define TSC_CR_MCV_Msk           (0x7UL << TSC_CR_MCV_Pos)                     /*!< 0x000000E0 */
#define TSC_CR_MCV               TSC_CR_MCV_Msk                                /*!< MCV[2:0] bits (Max Count Value) */
#define TSC_CR_MCV_0             (0x1U << TSC_CR_MCV_Pos)                      /*!< 0x00000020 */
#define TSC_CR_MCV_1             (0x2U << TSC_CR_MCV_Pos)                      /*!< 0x00000040 */
#define TSC_CR_MCV_2             (0x4U << TSC_CR_MCV_Pos)                      /*!< 0x00000080 */

#define TSC_CR_PGPSC_Pos         (12U)
#define TSC_CR_PGPSC_Msk         (0x7UL << TSC_CR_PGPSC_Pos)                   /*!< 0x00007000 */
#define TSC_CR_PGPSC             TSC_CR_PGPSC_Msk                              /*!< PGPSC[2:0] bits (Pulse Generator Prescaler) */
#define TSC_CR_PGPSC_0           (0x1U << TSC_CR_PGPSC_Pos)                    /*!< 0x00001000 */
#define TSC_CR_PGPSC_1           (0x2U << TSC_CR_PGPSC_Pos)                    /*!< 0x00002000 */
#define TSC_CR_PGPSC_2           (0x4U << TSC_CR_PGPSC_Pos)                    /*!< 0x00004000 */

#define TSC_CR_SSPSC_Pos         (15U)
#define TSC_CR_SSPSC_Msk         (0x1UL << TSC_CR_SSPSC_Pos)                   /*!< 0x00008000 */
#define TSC_CR_SSPSC             TSC_CR_SSPSC_Msk                              /*!< Spread Spectrum Prescaler */
#define TSC_CR_SSE_Pos           (16U)
#define TSC_CR_SSE_Msk           (0x1UL << TSC_CR_SSE_Pos)                     /*!< 0x00010000 */
#define TSC_CR_SSE               TSC_CR_SSE_Msk                                /*!< Spread Spectrum Enable */

#define TSC_CR_SSD_Pos           (17U)
#define TSC_CR_SSD_Msk           (0x7FUL << TSC_CR_SSD_Pos)                    /*!< 0x00FE0000 */
#define TSC_CR_SSD               TSC_CR_SSD_Msk                                /*!< SSD[6:0] bits (Spread Spectrum Deviation) */
#define TSC_CR_SSD_0             (0x01U << TSC_CR_SSD_Pos)                     /*!< 0x00020000 */
#define TSC_CR_SSD_1             (0x02U << TSC_CR_SSD_Pos)                     /*!< 0x00040000 */
#define TSC_CR_SSD_2             (0x04U << TSC_CR_SSD_Pos)                     /*!< 0x00080000 */
#define TSC_CR_SSD_3             (0x08U << TSC_CR_SSD_Pos)                     /*!< 0x00100000 */
#define TSC_CR_SSD_4             (0x10U << TSC_CR_SSD_Pos)                     /*!< 0x00200000 */
#define TSC_CR_SSD_5             (0x20U << TSC_CR_SSD_Pos)                     /*!< 0x00400000 */
#define TSC_CR_SSD_6             (0x40U << TSC_CR_SSD_Pos)                     /*!< 0x00800000 */

#define TSC_CR_CTPL_Pos          (24U)
#define TSC_CR_CTPL_Msk          (0xFUL << TSC_CR_CTPL_Pos)                    /*!< 0x0F000000 */
#define TSC_CR_CTPL              TSC_CR_CTPL_Msk                               /*!< CTPL[3:0] bits (Charge Transfer pulse low) */
#define TSC_CR_CTPL_0            (0x1U << TSC_CR_CTPL_Pos)                     /*!< 0x01000000 */
#define TSC_CR_CTPL_1            (0x2U << TSC_CR_CTPL_Pos)                     /*!< 0x02000000 */
#define TSC_CR_CTPL_2            (0x4U << TSC_CR_CTPL_Pos)                     /*!< 0x04000000 */
#define TSC_CR_CTPL_3            (0x8U << TSC_CR_CTPL_Pos)                     /*!< 0x08000000 */

#define TSC_CR_CTPH_Pos          (28U)
#define TSC_CR_CTPH_Msk          (0xFUL << TSC_CR_CTPH_Pos)                    /*!< 0xF0000000 */
#define TSC_CR_CTPH              TSC_CR_CTPH_Msk                               /*!< CTPH[3:0] bits (Charge Transfer pulse high) */
#define TSC_CR_CTPH_0            (0x1U << TSC_CR_CTPH_Pos)                     /*!< 0x10000000 */
#define TSC_CR_CTPH_1            (0x2U << TSC_CR_CTPH_Pos)                     /*!< 0x20000000 */
#define TSC_CR_CTPH_2            (0x4U << TSC_CR_CTPH_Pos)                     /*!< 0x40000000 */
#define TSC_CR_CTPH_3            (0x8U << TSC_CR_CTPH_Pos)                     /*!< 0x80000000 */

/*******************  Bit definition for TSC_IER register  ********************/
#define TSC_IER_EOAIE_Pos        (0U)
#define TSC_IER_EOAIE_Msk        (0x1UL << TSC_IER_EOAIE_Pos)                  /*!< 0x00000001 */
#define TSC_IER_EOAIE            TSC_IER_EOAIE_Msk                             /*!< End of acquisition interrupt enable */
#define TSC_IER_MCEIE_Pos        (1U)
#define TSC_IER_MCEIE_Msk        (0x1UL << TSC_IER_MCEIE_Pos)                  /*!< 0x00000002 */
#define TSC_IER_MCEIE            TSC_IER_MCEIE_Msk                             /*!< Max count error interrupt enable */

/*******************  Bit definition for TSC_ICR register  ********************/
#define TSC_ICR_EOAIC_Pos        (0U)
#define TSC_ICR_EOAIC_Msk        (0x1UL << TSC_ICR_EOAIC_Pos)                  /*!< 0x00000001 */
#define TSC_ICR_EOAIC            TSC_ICR_EOAIC_Msk                             /*!< End of acquisition interrupt clear */
#define TSC_ICR_MCEIC_Pos        (1U)
#define TSC_ICR_MCEIC_Msk        (0x1UL << TSC_ICR_MCEIC_Pos)                  /*!< 0x00000002 */
#define TSC_ICR_MCEIC            TSC_ICR_MCEIC_Msk                             /*!< Max count error interrupt clear */

/*******************  Bit definition for TSC_ISR register  ********************/
#define TSC_ISR_EOAF_Pos         (0U)
#define TSC_ISR_EOAF_Msk         (0x1UL << TSC_ISR_EOAF_Pos)                   /*!< 0x00000001 */
#define TSC_ISR_EOAF             TSC_ISR_EOAF_Msk                              /*!< End of acquisition flag */
#define TSC_ISR_MCEF_Pos         (1U)
#define TSC_ISR_MCEF_Msk         (0x1UL << TSC_ISR_MCEF_Pos)                   /*!< 0x00000002 */
#define TSC_ISR_MCEF             TSC_ISR_MCEF_Msk                              /*!< Max count error flag */

/*******************  Bit definition for TSC_IOHCR register  ******************/
#define TSC_IOHCR_G1_IO1_Pos     (0U)
#define TSC_IOHCR_G1_IO1_Msk     (0x1UL << TSC_IOHCR_G1_IO1_Pos)               /*!< 0x00000001 */
#define TSC_IOHCR_G1_IO1         TSC_IOHCR_G1_IO1_Msk                          /*!< GROUP1_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G1_IO2_Pos     (1U)
#define TSC_IOHCR_G1_IO2_Msk     (0x1UL << TSC_IOHCR_G1_IO2_Pos)               /*!< 0x00000002 */
#define TSC_IOHCR_G1_IO2         TSC_IOHCR_G1_IO2_Msk                          /*!< GROUP1_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G1_IO3_Pos     (2U)
#define TSC_IOHCR_G1_IO3_Msk     (0x1UL << TSC_IOHCR_G1_IO3_Pos)               /*!< 0x00000004 */
#define TSC_IOHCR_G1_IO3         TSC_IOHCR_G1_IO3_Msk                          /*!< GROUP1_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G1_IO4_Pos     (3U)
#define TSC_IOHCR_G1_IO4_Msk     (0x1UL << TSC_IOHCR_G1_IO4_Pos)               /*!< 0x00000008 */
#define TSC_IOHCR_G1_IO4         TSC_IOHCR_G1_IO4_Msk                          /*!< GROUP1_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO1_Pos     (4U)
#define TSC_IOHCR_G2_IO1_Msk     (0x1UL << TSC_IOHCR_G2_IO1_Pos)               /*!< 0x00000010 */
#define TSC_IOHCR_G2_IO1         TSC_IOHCR_G2_IO1_Msk                          /*!< GROUP2_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO2_Pos     (5U)
#define TSC_IOHCR_G2_IO2_Msk     (0x1UL << TSC_IOHCR_G2_IO2_Pos)               /*!< 0x00000020 */
#define TSC_IOHCR_G2_IO2         TSC_IOHCR_G2_IO2_Msk                          /*!< GROUP2_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO3_Pos     (6U)
#define TSC_IOHCR_G2_IO3_Msk     (0x1UL << TSC_IOHCR_G2_IO3_Pos)               /*!< 0x00000040 */
#define TSC_IOHCR_G2_IO3         TSC_IOHCR_G2_IO3_Msk                          /*!< GROUP2_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G2_IO4_Pos     (7U)
#define TSC_IOHCR_G2_IO4_Msk     (0x1UL << TSC_IOHCR_G2_IO4_Pos)               /*!< 0x00000080 */
#define TSC_IOHCR_G2_IO4         TSC_IOHCR_G2_IO4_Msk                          /*!< GROUP2_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO1_Pos     (8U)
#define TSC_IOHCR_G3_IO1_Msk     (0x1UL << TSC_IOHCR_G3_IO1_Pos)               /*!< 0x00000100 */
#define TSC_IOHCR_G3_IO1         TSC_IOHCR_G3_IO1_Msk                          /*!< GROUP3_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO2_Pos     (9U)
#define TSC_IOHCR_G3_IO2_Msk     (0x1UL << TSC_IOHCR_G3_IO2_Pos)               /*!< 0x00000200 */
#define TSC_IOHCR_G3_IO2         TSC_IOHCR_G3_IO2_Msk                          /*!< GROUP3_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO3_Pos     (10U)
#define TSC_IOHCR_G3_IO3_Msk     (0x1UL << TSC_IOHCR_G3_IO3_Pos)               /*!< 0x00000400 */
#define TSC_IOHCR_G3_IO3         TSC_IOHCR_G3_IO3_Msk                          /*!< GROUP3_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G3_IO4_Pos     (11U)
#define TSC_IOHCR_G3_IO4_Msk     (0x1UL << TSC_IOHCR_G3_IO4_Pos)               /*!< 0x00000800 */
#define TSC_IOHCR_G3_IO4         TSC_IOHCR_G3_IO4_Msk                          /*!< GROUP3_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO1_Pos     (12U)
#define TSC_IOHCR_G4_IO1_Msk     (0x1UL << TSC_IOHCR_G4_IO1_Pos)               /*!< 0x00001000 */
#define TSC_IOHCR_G4_IO1         TSC_IOHCR_G4_IO1_Msk                          /*!< GROUP4_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO2_Pos     (13U)
#define TSC_IOHCR_G4_IO2_Msk     (0x1UL << TSC_IOHCR_G4_IO2_Pos)               /*!< 0x00002000 */
#define TSC_IOHCR_G4_IO2         TSC_IOHCR_G4_IO2_Msk                          /*!< GROUP4_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO3_Pos     (14U)
#define TSC_IOHCR_G4_IO3_Msk     (0x1UL << TSC_IOHCR_G4_IO3_Pos)               /*!< 0x00004000 */
#define TSC_IOHCR_G4_IO3         TSC_IOHCR_G4_IO3_Msk                          /*!< GROUP4_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G4_IO4_Pos     (15U)
#define TSC_IOHCR_G4_IO4_Msk     (0x1UL << TSC_IOHCR_G4_IO4_Pos)               /*!< 0x00008000 */
#define TSC_IOHCR_G4_IO4         TSC_IOHCR_G4_IO4_Msk                          /*!< GROUP4_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO1_Pos     (16U)
#define TSC_IOHCR_G5_IO1_Msk     (0x1UL << TSC_IOHCR_G5_IO1_Pos)               /*!< 0x00010000 */
#define TSC_IOHCR_G5_IO1         TSC_IOHCR_G5_IO1_Msk                          /*!< GROUP5_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO2_Pos     (17U)
#define TSC_IOHCR_G5_IO2_Msk     (0x1UL << TSC_IOHCR_G5_IO2_Pos)               /*!< 0x00020000 */
#define TSC_IOHCR_G5_IO2         TSC_IOHCR_G5_IO2_Msk                          /*!< GROUP5_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO3_Pos     (18U)
#define TSC_IOHCR_G5_IO3_Msk     (0x1UL << TSC_IOHCR_G5_IO3_Pos)               /*!< 0x00040000 */
#define TSC_IOHCR_G5_IO3         TSC_IOHCR_G5_IO3_Msk                          /*!< GROUP5_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G5_IO4_Pos     (19U)
#define TSC_IOHCR_G5_IO4_Msk     (0x1UL << TSC_IOHCR_G5_IO4_Pos)               /*!< 0x00080000 */
#define TSC_IOHCR_G5_IO4         TSC_IOHCR_G5_IO4_Msk                          /*!< GROUP5_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G6_IO1_Pos     (20U)
#define TSC_IOHCR_G6_IO1_Msk     (0x1UL << TSC_IOHCR_G6_IO1_Pos)               /*!< 0x00100000 */
#define TSC_IOHCR_G6_IO1         TSC_IOHCR_G6_IO1_Msk                          /*!< GROUP6_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G6_IO2_Pos     (21U)
#define TSC_IOHCR_G6_IO2_Msk     (0x1UL << TSC_IOHCR_G6_IO2_Pos)               /*!< 0x00200000 */
#define TSC_IOHCR_G6_IO2         TSC_IOHCR_G6_IO2_Msk                          /*!< GROUP6_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G6_IO3_Pos     (22U)
#define TSC_IOHCR_G6_IO3_Msk     (0x1UL << TSC_IOHCR_G6_IO3_Pos)               /*!< 0x00400000 */
#define TSC_IOHCR_G6_IO3         TSC_IOHCR_G6_IO3_Msk                          /*!< GROUP6_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G6_IO4_Pos     (23U)
#define TSC_IOHCR_G6_IO4_Msk     (0x1UL << TSC_IOHCR_G6_IO4_Pos)               /*!< 0x00800000 */
#define TSC_IOHCR_G6_IO4         TSC_IOHCR_G6_IO4_Msk                          /*!< GROUP6_IO4 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G7_IO1_Pos     (24U)
#define TSC_IOHCR_G7_IO1_Msk     (0x1UL << TSC_IOHCR_G7_IO1_Pos)               /*!< 0x01000000 */
#define TSC_IOHCR_G7_IO1         TSC_IOHCR_G7_IO1_Msk                          /*!< GROUP7_IO1 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G7_IO2_Pos     (25U)
#define TSC_IOHCR_G7_IO2_Msk     (0x1UL << TSC_IOHCR_G7_IO2_Pos)               /*!< 0x02000000 */
#define TSC_IOHCR_G7_IO2         TSC_IOHCR_G7_IO2_Msk                          /*!< GROUP7_IO2 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G7_IO3_Pos     (26U)
#define TSC_IOHCR_G7_IO3_Msk     (0x1UL << TSC_IOHCR_G7_IO3_Pos)               /*!< 0x04000000 */
#define TSC_IOHCR_G7_IO3         TSC_IOHCR_G7_IO3_Msk                          /*!< GROUP7_IO3 schmitt trigger hysteresis mode */
#define TSC_IOHCR_G7_IO4_Pos     (27U)
#define TSC_IOHCR_G7_IO4_Msk     (0x1UL << TSC_IOHCR_G7_IO4_Pos)               /*!< 0x08000000 */
#define TSC_IOHCR_G7_IO4         TSC_IOHCR_G7_IO4_Msk                          /*!< GROUP7_IO4 schmitt trigger hysteresis mode */

/*******************  Bit definition for TSC_IOASCR register  *****************/
#define TSC_IOASCR_G1_IO1_Pos    (0U)
#define TSC_IOASCR_G1_IO1_Msk    (0x1UL << TSC_IOASCR_G1_IO1_Pos)              /*!< 0x00000001 */
#define TSC_IOASCR_G1_IO1        TSC_IOASCR_G1_IO1_Msk                         /*!< GROUP1_IO1 analog switch enable */
#define TSC_IOASCR_G1_IO2_Pos    (1U)
#define TSC_IOASCR_G1_IO2_Msk    (0x1UL << TSC_IOASCR_G1_IO2_Pos)              /*!< 0x00000002 */
#define TSC_IOASCR_G1_IO2        TSC_IOASCR_G1_IO2_Msk                         /*!< GROUP1_IO2 analog switch enable */
#define TSC_IOASCR_G1_IO3_Pos    (2U)
#define TSC_IOASCR_G1_IO3_Msk    (0x1UL << TSC_IOASCR_G1_IO3_Pos)              /*!< 0x00000004 */
#define TSC_IOASCR_G1_IO3        TSC_IOASCR_G1_IO3_Msk                         /*!< GROUP1_IO3 analog switch enable */
#define TSC_IOASCR_G1_IO4_Pos    (3U)
#define TSC_IOASCR_G1_IO4_Msk    (0x1UL << TSC_IOASCR_G1_IO4_Pos)              /*!< 0x00000008 */
#define TSC_IOASCR_G1_IO4        TSC_IOASCR_G1_IO4_Msk                         /*!< GROUP1_IO4 analog switch enable */
#define TSC_IOASCR_G2_IO1_Pos    (4U)
#define TSC_IOASCR_G2_IO1_Msk    (0x1UL << TSC_IOASCR_G2_IO1_Pos)              /*!< 0x00000010 */
#define TSC_IOASCR_G2_IO1        TSC_IOASCR_G2_IO1_Msk                         /*!< GROUP2_IO1 analog switch enable */
#define TSC_IOASCR_G2_IO2_Pos    (5U)
#define TSC_IOASCR_G2_IO2_Msk    (0x1UL << TSC_IOASCR_G2_IO2_Pos)              /*!< 0x00000020 */
#define TSC_IOASCR_G2_IO2        TSC_IOASCR_G2_IO2_Msk                         /*!< GROUP2_IO2 analog switch enable */
#define TSC_IOASCR_G2_IO3_Pos    (6U)
#define TSC_IOASCR_G2_IO3_Msk    (0x1UL << TSC_IOASCR_G2_IO3_Pos)              /*!< 0x00000040 */
#define TSC_IOASCR_G2_IO3        TSC_IOASCR_G2_IO3_Msk                         /*!< GROUP2_IO3 analog switch enable */
#define TSC_IOASCR_G2_IO4_Pos    (7U)
#define TSC_IOASCR_G2_IO4_Msk    (0x1UL << TSC_IOASCR_G2_IO4_Pos)              /*!< 0x00000080 */
#define TSC_IOASCR_G2_IO4        TSC_IOASCR_G2_IO4_Msk                         /*!< GROUP2_IO4 analog switch enable */
#define TSC_IOASCR_G3_IO1_Pos    (8U)
#define TSC_IOASCR_G3_IO1_Msk    (0x1UL << TSC_IOASCR_G3_IO1_Pos)              /*!< 0x00000100 */
#define TSC_IOASCR_G3_IO1        TSC_IOASCR_G3_IO1_Msk                         /*!< GROUP3_IO1 analog switch enable */
#define TSC_IOASCR_G3_IO2_Pos    (9U)
#define TSC_IOASCR_G3_IO2_Msk    (0x1UL << TSC_IOASCR_G3_IO2_Pos)              /*!< 0x00000200 */
#define TSC_IOASCR_G3_IO2        TSC_IOASCR_G3_IO2_Msk                         /*!< GROUP3_IO2 analog switch enable */
#define TSC_IOASCR_G3_IO3_Pos    (10U)
#define TSC_IOASCR_G3_IO3_Msk    (0x1UL << TSC_IOASCR_G3_IO3_Pos)              /*!< 0x00000400 */
#define TSC_IOASCR_G3_IO3        TSC_IOASCR_G3_IO3_Msk                         /*!< GROUP3_IO3 analog switch enable */
#define TSC_IOASCR_G3_IO4_Pos    (11U)
#define TSC_IOASCR_G3_IO4_Msk    (0x1UL << TSC_IOASCR_G3_IO4_Pos)              /*!< 0x00000800 */
#define TSC_IOASCR_G3_IO4        TSC_IOASCR_G3_IO4_Msk                         /*!< GROUP3_IO4 analog switch enable */
#define TSC_IOASCR_G4_IO1_Pos    (12U)
#define TSC_IOASCR_G4_IO1_Msk    (0x1UL << TSC_IOASCR_G4_IO1_Pos)              /*!< 0x00001000 */
#define TSC_IOASCR_G4_IO1        TSC_IOASCR_G4_IO1_Msk                         /*!< GROUP4_IO1 analog switch enable */
#define TSC_IOASCR_G4_IO2_Pos    (13U)
#define TSC_IOASCR_G4_IO2_Msk    (0x1UL << TSC_IOASCR_G4_IO2_Pos)              /*!< 0x00002000 */
#define TSC_IOASCR_G4_IO2        TSC_IOASCR_G4_IO2_Msk                         /*!< GROUP4_IO2 analog switch enable */
#define TSC_IOASCR_G4_IO3_Pos    (14U)
#define TSC_IOASCR_G4_IO3_Msk    (0x1UL << TSC_IOASCR_G4_IO3_Pos)              /*!< 0x00004000 */
#define TSC_IOASCR_G4_IO3        TSC_IOASCR_G4_IO3_Msk                         /*!< GROUP4_IO3 analog switch enable */
#define TSC_IOASCR_G4_IO4_Pos    (15U)
#define TSC_IOASCR_G4_IO4_Msk    (0x1UL << TSC_IOASCR_G4_IO4_Pos)              /*!< 0x00008000 */
#define TSC_IOASCR_G4_IO4        TSC_IOASCR_G4_IO4_Msk                         /*!< GROUP4_IO4 analog switch enable */
#define TSC_IOASCR_G5_IO1_Pos    (16U)
#define TSC_IOASCR_G5_IO1_Msk    (0x1UL << TSC_IOASCR_G5_IO1_Pos)              /*!< 0x00010000 */
#define TSC_IOASCR_G5_IO1        TSC_IOASCR_G5_IO1_Msk                         /*!< GROUP5_IO1 analog switch enable */
#define TSC_IOASCR_G5_IO2_Pos    (17U)
#define TSC_IOASCR_G5_IO2_Msk    (0x1UL << TSC_IOASCR_G5_IO2_Pos)              /*!< 0x00020000 */
#define TSC_IOASCR_G5_IO2        TSC_IOASCR_G5_IO2_Msk                         /*!< GROUP5_IO2 analog switch enable */
#define TSC_IOASCR_G5_IO3_Pos    (18U)
#define TSC_IOASCR_G5_IO3_Msk    (0x1UL << TSC_IOASCR_G5_IO3_Pos)              /*!< 0x00040000 */
#define TSC_IOASCR_G5_IO3        TSC_IOASCR_G5_IO3_Msk                         /*!< GROUP5_IO3 analog switch enable */
#define TSC_IOASCR_G5_IO4_Pos    (19U)
#define TSC_IOASCR_G5_IO4_Msk    (0x1UL << TSC_IOASCR_G5_IO4_Pos)              /*!< 0x00080000 */
#define TSC_IOASCR_G5_IO4        TSC_IOASCR_G5_IO4_Msk                         /*!< GROUP5_IO4 analog switch enable */
#define TSC_IOASCR_G6_IO1_Pos    (20U)
#define TSC_IOASCR_G6_IO1_Msk    (0x1UL << TSC_IOASCR_G6_IO1_Pos)              /*!< 0x00100000 */
#define TSC_IOASCR_G6_IO1        TSC_IOASCR_G6_IO1_Msk                         /*!< GROUP6_IO1 analog switch enable */
#define TSC_IOASCR_G6_IO2_Pos    (21U)
#define TSC_IOASCR_G6_IO2_Msk    (0x1UL << TSC_IOASCR_G6_IO2_Pos)              /*!< 0x00200000 */
#define TSC_IOASCR_G6_IO2        TSC_IOASCR_G6_IO2_Msk                         /*!< GROUP6_IO2 analog switch enable */
#define TSC_IOASCR_G6_IO3_Pos    (22U)
#define TSC_IOASCR_G6_IO3_Msk    (0x1UL << TSC_IOASCR_G6_IO3_Pos)              /*!< 0x00400000 */
#define TSC_IOASCR_G6_IO3        TSC_IOASCR_G6_IO3_Msk                         /*!< GROUP6_IO3 analog switch enable */
#define TSC_IOASCR_G6_IO4_Pos    (23U)
#define TSC_IOASCR_G6_IO4_Msk    (0x1UL << TSC_IOASCR_G6_IO4_Pos)              /*!< 0x00800000 */
#define TSC_IOASCR_G6_IO4        TSC_IOASCR_G6_IO4_Msk                         /*!< GROUP6_IO4 analog switch enable */
#define TSC_IOASCR_G7_IO1_Pos    (24U)
#define TSC_IOASCR_G7_IO1_Msk    (0x1UL << TSC_IOASCR_G7_IO1_Pos)              /*!< 0x01000000 */
#define TSC_IOASCR_G7_IO1        TSC_IOASCR_G7_IO1_Msk                         /*!< GROUP7_IO1 analog switch enable */
#define TSC_IOASCR_G7_IO2_Pos    (25U)
#define TSC_IOASCR_G7_IO2_Msk    (0x1UL << TSC_IOASCR_G7_IO2_Pos)              /*!< 0x02000000 */
#define TSC_IOASCR_G7_IO2        TSC_IOASCR_G7_IO2_Msk                         /*!< GROUP7_IO2 analog switch enable */
#define TSC_IOASCR_G7_IO3_Pos    (26U)
#define TSC_IOASCR_G7_IO3_Msk    (0x1UL << TSC_IOASCR_G7_IO3_Pos)              /*!< 0x04000000 */
#define TSC_IOASCR_G7_IO3        TSC_IOASCR_G7_IO3_Msk                         /*!< GROUP7_IO3 analog switch enable */
#define TSC_IOASCR_G7_IO4_Pos    (27U)
#define TSC_IOASCR_G7_IO4_Msk    (0x1UL << TSC_IOASCR_G7_IO4_Pos)              /*!< 0x08000000 */
#define TSC_IOASCR_G7_IO4        TSC_IOASCR_G7_IO4_Msk                         /*!< GROUP7_IO4 analog switch enable */

/*******************  Bit definition for TSC_IOSCR register  ******************/
#define TSC_IOSCR_G1_IO1_Pos     (0U)
#define TSC_IOSCR_G1_IO1_Msk     (0x1UL << TSC_IOSCR_G1_IO1_Pos)               /*!< 0x00000001 */
#define TSC_IOSCR_G1_IO1         TSC_IOSCR_G1_IO1_Msk                          /*!< GROUP1_IO1 sampling mode */
#define TSC_IOSCR_G1_IO2_Pos     (1U)
#define TSC_IOSCR_G1_IO2_Msk     (0x1UL << TSC_IOSCR_G1_IO2_Pos)               /*!< 0x00000002 */
#define TSC_IOSCR_G1_IO2         TSC_IOSCR_G1_IO2_Msk                          /*!< GROUP1_IO2 sampling mode */
#define TSC_IOSCR_G1_IO3_Pos     (2U)
#define TSC_IOSCR_G1_IO3_Msk     (0x1UL << TSC_IOSCR_G1_IO3_Pos)               /*!< 0x00000004 */
#define TSC_IOSCR_G1_IO3         TSC_IOSCR_G1_IO3_Msk                          /*!< GROUP1_IO3 sampling mode */
#define TSC_IOSCR_G1_IO4_Pos     (3U)
#define TSC_IOSCR_G1_IO4_Msk     (0x1UL << TSC_IOSCR_G1_IO4_Pos)               /*!< 0x00000008 */
#define TSC_IOSCR_G1_IO4         TSC_IOSCR_G1_IO4_Msk                          /*!< GROUP1_IO4 sampling mode */
#define TSC_IOSCR_G2_IO1_Pos     (4U)
#define TSC_IOSCR_G2_IO1_Msk     (0x1UL << TSC_IOSCR_G2_IO1_Pos)               /*!< 0x00000010 */
#define TSC_IOSCR_G2_IO1         TSC_IOSCR_G2_IO1_Msk                          /*!< GROUP2_IO1 sampling mode */
#define TSC_IOSCR_G2_IO2_Pos     (5U)
#define TSC_IOSCR_G2_IO2_Msk     (0x1UL << TSC_IOSCR_G2_IO2_Pos)               /*!< 0x00000020 */
#define TSC_IOSCR_G2_IO2         TSC_IOSCR_G2_IO2_Msk                          /*!< GROUP2_IO2 sampling mode */
#define TSC_IOSCR_G2_IO3_Pos     (6U)
#define TSC_IOSCR_G2_IO3_Msk     (0x1UL << TSC_IOSCR_G2_IO3_Pos)               /*!< 0x00000040 */
#define TSC_IOSCR_G2_IO3         TSC_IOSCR_G2_IO3_Msk                          /*!< GROUP2_IO3 sampling mode */
#define TSC_IOSCR_G2_IO4_Pos     (7U)
#define TSC_IOSCR_G2_IO4_Msk     (0x1UL << TSC_IOSCR_G2_IO4_Pos)               /*!< 0x00000080 */
#define TSC_IOSCR_G2_IO4         TSC_IOSCR_G2_IO4_Msk                          /*!< GROUP2_IO4 sampling mode */
#define TSC_IOSCR_G3_IO1_Pos     (8U)
#define TSC_IOSCR_G3_IO1_Msk     (0x1UL << TSC_IOSCR_G3_IO1_Pos)               /*!< 0x00000100 */
#define TSC_IOSCR_G3_IO1         TSC_IOSCR_G3_IO1_Msk                          /*!< GROUP3_IO1 sampling mode */
#define TSC_IOSCR_G3_IO2_Pos     (9U)
#define TSC_IOSCR_G3_IO2_Msk     (0x1UL << TSC_IOSCR_G3_IO2_Pos)               /*!< 0x00000200 */
#define TSC_IOSCR_G3_IO2         TSC_IOSCR_G3_IO2_Msk                          /*!< GROUP3_IO2 sampling mode */
#define TSC_IOSCR_G3_IO3_Pos     (10U)
#define TSC_IOSCR_G3_IO3_Msk     (0x1UL << TSC_IOSCR_G3_IO3_Pos)               /*!< 0x00000400 */
#define TSC_IOSCR_G3_IO3         TSC_IOSCR_G3_IO3_Msk                          /*!< GROUP3_IO3 sampling mode */
#define TSC_IOSCR_G3_IO4_Pos     (11U)
#define TSC_IOSCR_G3_IO4_Msk     (0x1UL << TSC_IOSCR_G3_IO4_Pos)               /*!< 0x00000800 */
#define TSC_IOSCR_G3_IO4         TSC_IOSCR_G3_IO4_Msk                          /*!< GROUP3_IO4 sampling mode */
#define TSC_IOSCR_G4_IO1_Pos     (12U)
#define TSC_IOSCR_G4_IO1_Msk     (0x1UL << TSC_IOSCR_G4_IO1_Pos)               /*!< 0x00001000 */
#define TSC_IOSCR_G4_IO1         TSC_IOSCR_G4_IO1_Msk                          /*!< GROUP4_IO1 sampling mode */
#define TSC_IOSCR_G4_IO2_Pos     (13U)
#define TSC_IOSCR_G4_IO2_Msk     (0x1UL << TSC_IOSCR_G4_IO2_Pos)               /*!< 0x00002000 */
#define TSC_IOSCR_G4_IO2         TSC_IOSCR_G4_IO2_Msk                          /*!< GROUP4_IO2 sampling mode */
#define TSC_IOSCR_G4_IO3_Pos     (14U)
#define TSC_IOSCR_G4_IO3_Msk     (0x1UL << TSC_IOSCR_G4_IO3_Pos)               /*!< 0x00004000 */
#define TSC_IOSCR_G4_IO3         TSC_IOSCR_G4_IO3_Msk                          /*!< GROUP4_IO3 sampling mode */
#define TSC_IOSCR_G4_IO4_Pos     (15U)
#define TSC_IOSCR_G4_IO4_Msk     (0x1UL << TSC_IOSCR_G4_IO4_Pos)               /*!< 0x00008000 */
#define TSC_IOSCR_G4_IO4         TSC_IOSCR_G4_IO4_Msk                          /*!< GROUP4_IO4 sampling mode */
#define TSC_IOSCR_G5_IO1_Pos     (16U)
#define TSC_IOSCR_G5_IO1_Msk     (0x1UL << TSC_IOSCR_G5_IO1_Pos)               /*!< 0x00010000 */
#define TSC_IOSCR_G5_IO1         TSC_IOSCR_G5_IO1_Msk                          /*!< GROUP5_IO1 sampling mode */
#define TSC_IOSCR_G5_IO2_Pos     (17U)
#define TSC_IOSCR_G5_IO2_Msk     (0x1UL << TSC_IOSCR_G5_IO2_Pos)               /*!< 0x00020000 */
#define TSC_IOSCR_G5_IO2         TSC_IOSCR_G5_IO2_Msk                          /*!< GROUP5_IO2 sampling mode */
#define TSC_IOSCR_G5_IO3_Pos     (18U)
#define TSC_IOSCR_G5_IO3_Msk     (0x1UL << TSC_IOSCR_G5_IO3_Pos)               /*!< 0x00040000 */
#define TSC_IOSCR_G5_IO3         TSC_IOSCR_G5_IO3_Msk                          /*!< GROUP5_IO3 sampling mode */
#define TSC_IOSCR_G5_IO4_Pos     (19U)
#define TSC_IOSCR_G5_IO4_Msk     (0x1UL << TSC_IOSCR_G5_IO4_Pos)               /*!< 0x00080000 */
#define TSC_IOSCR_G5_IO4         TSC_IOSCR_G5_IO4_Msk                          /*!< GROUP5_IO4 sampling mode */
#define TSC_IOSCR_G6_IO1_Pos     (20U)
#define TSC_IOSCR_G6_IO1_Msk     (0x1UL << TSC_IOSCR_G6_IO1_Pos)               /*!< 0x00100000 */
#define TSC_IOSCR_G6_IO1         TSC_IOSCR_G6_IO1_Msk                          /*!< GROUP6_IO1 sampling mode */
#define TSC_IOSCR_G6_IO2_Pos     (21U)
#define TSC_IOSCR_G6_IO2_Msk     (0x1UL << TSC_IOSCR_G6_IO2_Pos)               /*!< 0x00200000 */
#define TSC_IOSCR_G6_IO2         TSC_IOSCR_G6_IO2_Msk                          /*!< GROUP6_IO2 sampling mode */
#define TSC_IOSCR_G6_IO3_Pos     (22U)
#define TSC_IOSCR_G6_IO3_Msk     (0x1UL << TSC_IOSCR_G6_IO3_Pos)               /*!< 0x00400000 */
#define TSC_IOSCR_G6_IO3         TSC_IOSCR_G6_IO3_Msk                          /*!< GROUP6_IO3 sampling mode */
#define TSC_IOSCR_G6_IO4_Pos     (23U)
#define TSC_IOSCR_G6_IO4_Msk     (0x1UL << TSC_IOSCR_G6_IO4_Pos)               /*!< 0x00800000 */
#define TSC_IOSCR_G6_IO4         TSC_IOSCR_G6_IO4_Msk                          /*!< GROUP6_IO4 sampling mode */
#define TSC_IOSCR_G7_IO1_Pos     (24U)
#define TSC_IOSCR_G7_IO1_Msk     (0x1UL << TSC_IOSCR_G7_IO1_Pos)               /*!< 0x01000000 */
#define TSC_IOSCR_G7_IO1         TSC_IOSCR_G7_IO1_Msk                          /*!< GROUP7_IO1 sampling mode */
#define TSC_IOSCR_G7_IO2_Pos     (25U)
#define TSC_IOSCR_G7_IO2_Msk     (0x1UL << TSC_IOSCR_G7_IO2_Pos)               /*!< 0x02000000 */
#define TSC_IOSCR_G7_IO2         TSC_IOSCR_G7_IO2_Msk                          /*!< GROUP7_IO2 sampling mode */
#define TSC_IOSCR_G7_IO3_Pos     (26U)
#define TSC_IOSCR_G7_IO3_Msk     (0x1UL << TSC_IOSCR_G7_IO3_Pos)               /*!< 0x04000000 */
#define TSC_IOSCR_G7_IO3         TSC_IOSCR_G7_IO3_Msk                          /*!< GROUP7_IO3 sampling mode */
#define TSC_IOSCR_G7_IO4_Pos     (27U)
#define TSC_IOSCR_G7_IO4_Msk     (0x1UL << TSC_IOSCR_G7_IO4_Pos)               /*!< 0x08000000 */
#define TSC_IOSCR_G7_IO4         TSC_IOSCR_G7_IO4_Msk                          /*!< GROUP7_IO4 sampling mode */

/*******************  Bit definition for TSC_IOCCR register  ******************/
#define TSC_IOCCR_G1_IO1_Pos     (0U)
#define TSC_IOCCR_G1_IO1_Msk     (0x1UL << TSC_IOCCR_G1_IO1_Pos)               /*!< 0x00000001 */
#define TSC_IOCCR_G1_IO1         TSC_IOCCR_G1_IO1_Msk                          /*!< GROUP1_IO1 channel mode */
#define TSC_IOCCR_G1_IO2_Pos     (1U)
#define TSC_IOCCR_G1_IO2_Msk     (0x1UL << TSC_IOCCR_G1_IO2_Pos)               /*!< 0x00000002 */
#define TSC_IOCCR_G1_IO2         TSC_IOCCR_G1_IO2_Msk                          /*!< GROUP1_IO2 channel mode */
#define TSC_IOCCR_G1_IO3_Pos     (2U)
#define TSC_IOCCR_G1_IO3_Msk     (0x1UL << TSC_IOCCR_G1_IO3_Pos)               /*!< 0x00000004 */
#define TSC_IOCCR_G1_IO3         TSC_IOCCR_G1_IO3_Msk                          /*!< GROUP1_IO3 channel mode */
#define TSC_IOCCR_G1_IO4_Pos     (3U)
#define TSC_IOCCR_G1_IO4_Msk     (0x1UL << TSC_IOCCR_G1_IO4_Pos)               /*!< 0x00000008 */
#define TSC_IOCCR_G1_IO4         TSC_IOCCR_G1_IO4_Msk                          /*!< GROUP1_IO4 channel mode */
#define TSC_IOCCR_G2_IO1_Pos     (4U)
#define TSC_IOCCR_G2_IO1_Msk     (0x1UL << TSC_IOCCR_G2_IO1_Pos)               /*!< 0x00000010 */
#define TSC_IOCCR_G2_IO1         TSC_IOCCR_G2_IO1_Msk                          /*!< GROUP2_IO1 channel mode */
#define TSC_IOCCR_G2_IO2_Pos     (5U)
#define TSC_IOCCR_G2_IO2_Msk     (0x1UL << TSC_IOCCR_G2_IO2_Pos)               /*!< 0x00000020 */
#define TSC_IOCCR_G2_IO2         TSC_IOCCR_G2_IO2_Msk                          /*!< GROUP2_IO2 channel mode */
#define TSC_IOCCR_G2_IO3_Pos     (6U)
#define TSC_IOCCR_G2_IO3_Msk     (0x1UL << TSC_IOCCR_G2_IO3_Pos)               /*!< 0x00000040 */
#define TSC_IOCCR_G2_IO3         TSC_IOCCR_G2_IO3_Msk                          /*!< GROUP2_IO3 channel mode */
#define TSC_IOCCR_G2_IO4_Pos     (7U)
#define TSC_IOCCR_G2_IO4_Msk     (0x1UL << TSC_IOCCR_G2_IO4_Pos)               /*!< 0x00000080 */
#define TSC_IOCCR_G2_IO4         TSC_IOCCR_G2_IO4_Msk                          /*!< GROUP2_IO4 channel mode */
#define TSC_IOCCR_G3_IO1_Pos     (8U)
#define TSC_IOCCR_G3_IO1_Msk     (0x1UL << TSC_IOCCR_G3_IO1_Pos)               /*!< 0x00000100 */
#define TSC_IOCCR_G3_IO1         TSC_IOCCR_G3_IO1_Msk                          /*!< GROUP3_IO1 channel mode */
#define TSC_IOCCR_G3_IO2_Pos     (9U)
#define TSC_IOCCR_G3_IO2_Msk     (0x1UL << TSC_IOCCR_G3_IO2_Pos)               /*!< 0x00000200 */
#define TSC_IOCCR_G3_IO2         TSC_IOCCR_G3_IO2_Msk                          /*!< GROUP3_IO2 channel mode */
#define TSC_IOCCR_G3_IO3_Pos     (10U)
#define TSC_IOCCR_G3_IO3_Msk     (0x1UL << TSC_IOCCR_G3_IO3_Pos)               /*!< 0x00000400 */
#define TSC_IOCCR_G3_IO3         TSC_IOCCR_G3_IO3_Msk                          /*!< GROUP3_IO3 channel mode */
#define TSC_IOCCR_G3_IO4_Pos     (11U)
#define TSC_IOCCR_G3_IO4_Msk     (0x1UL << TSC_IOCCR_G3_IO4_Pos)               /*!< 0x00000800 */
#define TSC_IOCCR_G3_IO4         TSC_IOCCR_G3_IO4_Msk                          /*!< GROUP3_IO4 channel mode */
#define TSC_IOCCR_G4_IO1_Pos     (12U)
#define TSC_IOCCR_G4_IO1_Msk     (0x1UL << TSC_IOCCR_G4_IO1_Pos)               /*!< 0x00001000 */
#define TSC_IOCCR_G4_IO1         TSC_IOCCR_G4_IO1_Msk                          /*!< GROUP4_IO1 channel mode */
#define TSC_IOCCR_G4_IO2_Pos     (13U)
#define TSC_IOCCR_G4_IO2_Msk     (0x1UL << TSC_IOCCR_G4_IO2_Pos)               /*!< 0x00002000 */
#define TSC_IOCCR_G4_IO2         TSC_IOCCR_G4_IO2_Msk                          /*!< GROUP4_IO2 channel mode */
#define TSC_IOCCR_G4_IO3_Pos     (14U)
#define TSC_IOCCR_G4_IO3_Msk     (0x1UL << TSC_IOCCR_G4_IO3_Pos)               /*!< 0x00004000 */
#define TSC_IOCCR_G4_IO3         TSC_IOCCR_G4_IO3_Msk                          /*!< GROUP4_IO3 channel mode */
#define TSC_IOCCR_G4_IO4_Pos     (15U)
#define TSC_IOCCR_G4_IO4_Msk     (0x1UL << TSC_IOCCR_G4_IO4_Pos)               /*!< 0x00008000 */
#define TSC_IOCCR_G4_IO4         TSC_IOCCR_G4_IO4_Msk                          /*!< GROUP4_IO4 channel mode */
#define TSC_IOCCR_G5_IO1_Pos     (16U)
#define TSC_IOCCR_G5_IO1_Msk     (0x1UL << TSC_IOCCR_G5_IO1_Pos)               /*!< 0x00010000 */
#define TSC_IOCCR_G5_IO1         TSC_IOCCR_G5_IO1_Msk                          /*!< GROUP5_IO1 channel mode */
#define TSC_IOCCR_G5_IO2_Pos     (17U)
#define TSC_IOCCR_G5_IO2_Msk     (0x1UL << TSC_IOCCR_G5_IO2_Pos)               /*!< 0x00020000 */
#define TSC_IOCCR_G5_IO2         TSC_IOCCR_G5_IO2_Msk                          /*!< GROUP5_IO2 channel mode */
#define TSC_IOCCR_G5_IO3_Pos     (18U)
#define TSC_IOCCR_G5_IO3_Msk     (0x1UL << TSC_IOCCR_G5_IO3_Pos)               /*!< 0x00040000 */
#define TSC_IOCCR_G5_IO3         TSC_IOCCR_G5_IO3_Msk                          /*!< GROUP5_IO3 channel mode */
#define TSC_IOCCR_G5_IO4_Pos     (19U)
#define TSC_IOCCR_G5_IO4_Msk     (0x1UL << TSC_IOCCR_G5_IO4_Pos)               /*!< 0x00080000 */
#define TSC_IOCCR_G5_IO4         TSC_IOCCR_G5_IO4_Msk                          /*!< GROUP5_IO4 channel mode */
#define TSC_IOCCR_G6_IO1_Pos     (20U)
#define TSC_IOCCR_G6_IO1_Msk     (0x1UL << TSC_IOCCR_G6_IO1_Pos)               /*!< 0x00100000 */
#define TSC_IOCCR_G6_IO1         TSC_IOCCR_G6_IO1_Msk                          /*!< GROUP6_IO1 channel mode */
#define TSC_IOCCR_G6_IO2_Pos     (21U)
#define TSC_IOCCR_G6_IO2_Msk     (0x1UL << TSC_IOCCR_G6_IO2_Pos)               /*!< 0x00200000 */
#define TSC_IOCCR_G6_IO2         TSC_IOCCR_G6_IO2_Msk                          /*!< GROUP6_IO2 channel mode */
#define TSC_IOCCR_G6_IO3_Pos     (22U)
#define TSC_IOCCR_G6_IO3_Msk     (0x1UL << TSC_IOCCR_G6_IO3_Pos)               /*!< 0x00400000 */
#define TSC_IOCCR_G6_IO3         TSC_IOCCR_G6_IO3_Msk                          /*!< GROUP6_IO3 channel mode */
#define TSC_IOCCR_G6_IO4_Pos     (23U)
#define TSC_IOCCR_G6_IO4_Msk     (0x1UL << TSC_IOCCR_G6_IO4_Pos)               /*!< 0x00800000 */
#define TSC_IOCCR_G6_IO4         TSC_IOCCR_G6_IO4_Msk                          /*!< GROUP6_IO4 channel mode */
#define TSC_IOCCR_G7_IO1_Pos     (24U)
#define TSC_IOCCR_G7_IO1_Msk     (0x1UL << TSC_IOCCR_G7_IO1_Pos)               /*!< 0x01000000 */
#define TSC_IOCCR_G7_IO1         TSC_IOCCR_G7_IO1_Msk                          /*!< GROUP7_IO1 channel mode */
#define TSC_IOCCR_G7_IO2_Pos     (25U)
#define TSC_IOCCR_G7_IO2_Msk     (0x1UL << TSC_IOCCR_G7_IO2_Pos)               /*!< 0x02000000 */
#define TSC_IOCCR_G7_IO2         TSC_IOCCR_G7_IO2_Msk                          /*!< GROUP7_IO2 channel mode */
#define TSC_IOCCR_G7_IO3_Pos     (26U)
#define TSC_IOCCR_G7_IO3_Msk     (0x1UL << TSC_IOCCR_G7_IO3_Pos)               /*!< 0x04000000 */
#define TSC_IOCCR_G7_IO3         TSC_IOCCR_G7_IO3_Msk                          /*!< GROUP7_IO3 channel mode */
#define TSC_IOCCR_G7_IO4_Pos     (27U)
#define TSC_IOCCR_G7_IO4_Msk     (0x1UL << TSC_IOCCR_G7_IO4_Pos)               /*!< 0x08000000 */
#define TSC_IOCCR_G7_IO4         TSC_IOCCR_G7_IO4_Msk                          /*!< GROUP7_IO4 channel mode */

/*******************  Bit definition for TSC_IOGCSR register  *****************/
#define TSC_IOGCSR_G1E_Pos       (0U)
#define TSC_IOGCSR_G1E_Msk       (0x1UL << TSC_IOGCSR_G1E_Pos)                 /*!< 0x00000001 */
#define TSC_IOGCSR_G1E           TSC_IOGCSR_G1E_Msk                            /*!< Analog IO GROUP1 enable */
#define TSC_IOGCSR_G2E_Pos       (1U)
#define TSC_IOGCSR_G2E_Msk       (0x1UL << TSC_IOGCSR_G2E_Pos)                 /*!< 0x00000002 */
#define TSC_IOGCSR_G2E           TSC_IOGCSR_G2E_Msk                            /*!< Analog IO GROUP2 enable */
#define TSC_IOGCSR_G3E_Pos       (2U)
#define TSC_IOGCSR_G3E_Msk       (0x1UL << TSC_IOGCSR_G3E_Pos)                 /*!< 0x00000004 */
#define TSC_IOGCSR_G3E           TSC_IOGCSR_G3E_Msk                            /*!< Analog IO GROUP3 enable */
#define TSC_IOGCSR_G4E_Pos       (3U)
#define TSC_IOGCSR_G4E_Msk       (0x1UL << TSC_IOGCSR_G4E_Pos)                 /*!< 0x00000008 */
#define TSC_IOGCSR_G4E           TSC_IOGCSR_G4E_Msk                            /*!< Analog IO GROUP4 enable */
#define TSC_IOGCSR_G5E_Pos       (4U)
#define TSC_IOGCSR_G5E_Msk       (0x1UL << TSC_IOGCSR_G5E_Pos)                 /*!< 0x00000010 */
#define TSC_IOGCSR_G5E           TSC_IOGCSR_G5E_Msk                            /*!< Analog IO GROUP5 enable */
#define TSC_IOGCSR_G6E_Pos       (5U)
#define TSC_IOGCSR_G6E_Msk       (0x1UL << TSC_IOGCSR_G6E_Pos)                 /*!< 0x00000020 */
#define TSC_IOGCSR_G6E           TSC_IOGCSR_G6E_Msk                            /*!< Analog IO GROUP6 enable */
#define TSC_IOGCSR_G7E_Pos       (6U)
#define TSC_IOGCSR_G7E_Msk       (0x1UL << TSC_IOGCSR_G7E_Pos)                 /*!< 0x00000040 */
#define TSC_IOGCSR_G7E           TSC_IOGCSR_G7E_Msk                            /*!< Analog IO GROUP7 enable */
#define TSC_IOGCSR_G1S_Pos       (16U)
#define TSC_IOGCSR_G1S_Msk       (0x1UL << TSC_IOGCSR_G1S_Pos)                 /*!< 0x00010000 */
#define TSC_IOGCSR_G1S           TSC_IOGCSR_G1S_Msk                            /*!< Analog IO GROUP1 status */
#define TSC_IOGCSR_G2S_Pos       (17U)
#define TSC_IOGCSR_G2S_Msk       (0x1UL << TSC_IOGCSR_G2S_Pos)                 /*!< 0x00020000 */
#define TSC_IOGCSR_G2S           TSC_IOGCSR_G2S_Msk                            /*!< Analog IO GROUP2 status */
#define TSC_IOGCSR_G3S_Pos       (18U)
#define TSC_IOGCSR_G3S_Msk       (0x1UL << TSC_IOGCSR_G3S_Pos)                 /*!< 0x00040000 */
#define TSC_IOGCSR_G3S           TSC_IOGCSR_G3S_Msk                            /*!< Analog IO GROUP3 status */
#define TSC_IOGCSR_G4S_Pos       (19U)
#define TSC_IOGCSR_G4S_Msk       (0x1UL << TSC_IOGCSR_G4S_Pos)                 /*!< 0x00080000 */
#define TSC_IOGCSR_G4S           TSC_IOGCSR_G4S_Msk                            /*!< Analog IO GROUP4 status */
#define TSC_IOGCSR_G5S_Pos       (20U)
#define TSC_IOGCSR_G5S_Msk       (0x1UL << TSC_IOGCSR_G5S_Pos)                 /*!< 0x00100000 */
#define TSC_IOGCSR_G5S           TSC_IOGCSR_G5S_Msk                            /*!< Analog IO GROUP5 status */
#define TSC_IOGCSR_G6S_Pos       (21U)
#define TSC_IOGCSR_G6S_Msk       (0x1UL << TSC_IOGCSR_G6S_Pos)                 /*!< 0x00200000 */
#define TSC_IOGCSR_G6S           TSC_IOGCSR_G6S_Msk                            /*!< Analog IO GROUP6 status */
#define TSC_IOGCSR_G7S_Pos       (22U)
#define TSC_IOGCSR_G7S_Msk       (0x1UL << TSC_IOGCSR_G7S_Pos)                 /*!< 0x00400000 */
#define TSC_IOGCSR_G7S           TSC_IOGCSR_G7S_Msk                            /*!< Analog IO GROUP7 status */

/*******************  Bit definition for TSC_IOGXCR register  *****************/
#define TSC_IOGXCR_CNT_Pos       (0U)
#define TSC_IOGXCR_CNT_Msk       (0x3FFFUL << TSC_IOGXCR_CNT_Pos)              /*!< 0x00003FFF */
#define TSC_IOGXCR_CNT           TSC_IOGXCR_CNT_Msk                            /*!< CNT[13:0] bits (Counter value) */

/******************************************************************************/
/*                                                                            */
/*                                 SYSCFG                                     */
/*                                                                            */
/******************************************************************************/
/*****************  Bit definition for SYSCFG_MEMRMP register  (SYSCFG memory remap register) ***********************************/
#define SYSCFG_MEMRMP_MEM_MODE_Pos              (0U)
#define SYSCFG_MEMRMP_MEM_MODE_Msk              (0x7UL << SYSCFG_MEMRMP_MEM_MODE_Pos)           /*!< 0x00000007 */
#define SYSCFG_MEMRMP_MEM_MODE                  SYSCFG_MEMRMP_MEM_MODE_Msk                      /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_MEMRMP_MEM_MODE_0                (0x1U << SYSCFG_MEMRMP_MEM_MODE_Pos)            /*!< 0x00000001 */
#define SYSCFG_MEMRMP_MEM_MODE_1                (0x2U << SYSCFG_MEMRMP_MEM_MODE_Pos)            /*!< 0x00000002 */
#define SYSCFG_MEMRMP_MEM_MODE_2                (0x4U << SYSCFG_MEMRMP_MEM_MODE_Pos)            /*!< 0x00000004 */

/*****************  Bit definition for SYSCFG_CFGR1 register  (SYSCFG configuration register 1) ****************************************************************/
#define SYSCFG_CFGR1_BOOSTEN_Pos                (8U)
#define SYSCFG_CFGR1_BOOSTEN_Msk                (0x1UL << SYSCFG_CFGR1_BOOSTEN_Pos)             /*!< 0x00000100 */
#define SYSCFG_CFGR1_BOOSTEN                    SYSCFG_CFGR1_BOOSTEN_Msk                        /*!< I/O analog switch voltage booster enable                  */
#define SYSCFG_CFGR1_I2C_PB6_FMP_Pos            (16U)
#define SYSCFG_CFGR1_I2C_PB6_FMP_Msk            (0x1UL << SYSCFG_CFGR1_I2C_PB6_FMP_Pos)         /*!< 0x00010000 */
#define SYSCFG_CFGR1_I2C_PB6_FMP                SYSCFG_CFGR1_I2C_PB6_FMP_Msk                    /*!< Fast-mode Plus (Fm+) driving capability activation on PB6 */
#define SYSCFG_CFGR1_I2C_PB7_FMP_Pos            (17U)
#define SYSCFG_CFGR1_I2C_PB7_FMP_Msk            (0x1UL << SYSCFG_CFGR1_I2C_PB7_FMP_Pos)         /*!< 0x00020000 */
#define SYSCFG_CFGR1_I2C_PB7_FMP                SYSCFG_CFGR1_I2C_PB7_FMP_Msk                    /*!< Fast-mode Plus (Fm+) driving capability activation on PB7 */
#define SYSCFG_CFGR1_I2C_PB8_FMP_Pos            (18U)
#define SYSCFG_CFGR1_I2C_PB8_FMP_Msk            (0x1UL << SYSCFG_CFGR1_I2C_PB8_FMP_Pos)         /*!< 0x00040000 */
#define SYSCFG_CFGR1_I2C_PB8_FMP                SYSCFG_CFGR1_I2C_PB8_FMP_Msk                    /*!< Fast-mode Plus (Fm+) driving capability activation on PB8 */
#define SYSCFG_CFGR1_I2C_PB9_FMP_Pos            (19U)
#define SYSCFG_CFGR1_I2C_PB9_FMP_Msk            (0x1UL << SYSCFG_CFGR1_I2C_PB9_FMP_Pos)         /*!< 0x00080000 */
#define SYSCFG_CFGR1_I2C_PB9_FMP                SYSCFG_CFGR1_I2C_PB9_FMP_Msk                    /*!< Fast-mode Plus (Fm+) driving capability activation on PB9 */
#define SYSCFG_CFGR1_I2C1_FMP_Pos               (20U)
#define SYSCFG_CFGR1_I2C1_FMP_Msk               (0x1UL << SYSCFG_CFGR1_I2C1_FMP_Pos)            /*!< 0x00100000 */
#define SYSCFG_CFGR1_I2C1_FMP                   SYSCFG_CFGR1_I2C1_FMP_Msk                       /*!< I2C1 Fast-mode Plus (Fm+) driving capability activation   */
#define SYSCFG_CFGR1_FPU_IE_Pos                 (26U)
#define SYSCFG_CFGR1_FPU_IE_Msk                 (0x3FUL << SYSCFG_CFGR1_FPU_IE_Pos)             /*!< 0xFC000000 */
#define SYSCFG_CFGR1_FPU_IE                     SYSCFG_CFGR1_FPU_IE_Msk                         /*!< Cortex M4 Floating Point Unit interrupts enable bits      */
#define SYSCFG_CFGR1_FPU_IE_0                   (0x01U << SYSCFG_CFGR1_FPU_IE_Pos)              /*!< 0x04000000 */
#define SYSCFG_CFGR1_FPU_IE_1                   (0x02U << SYSCFG_CFGR1_FPU_IE_Pos)              /*!< 0x08000000 */
#define SYSCFG_CFGR1_FPU_IE_2                   (0x04U << SYSCFG_CFGR1_FPU_IE_Pos)              /*!< 0x10000000 */
#define SYSCFG_CFGR1_FPU_IE_3                   (0x08U << SYSCFG_CFGR1_FPU_IE_Pos)              /*!< 0x20000000 */
#define SYSCFG_CFGR1_FPU_IE_4                   (0x10U << SYSCFG_CFGR1_FPU_IE_Pos)              /*!< 0x40000000 */
#define SYSCFG_CFGR1_FPU_IE_5                   (0x20U << SYSCFG_CFGR1_FPU_IE_Pos)              /*!< 0x80000000 */

/*****************  Bit definition for SYSCFG_EXTICR1 register  (External interrupt configuration register 1) ********************************/
#define SYSCFG_EXTICR1_EXTI0_Pos                (0U)
#define SYSCFG_EXTICR1_EXTI0_Msk                (0x7UL << SYSCFG_EXTICR1_EXTI0_Pos)             /*!< 0x00000007 */
#define SYSCFG_EXTICR1_EXTI0                    SYSCFG_EXTICR1_EXTI0_Msk                        /*!< External Interrupt Line 0 configuration */
#define SYSCFG_EXTICR1_EXTI1_Pos                (4U)
#define SYSCFG_EXTICR1_EXTI1_Msk                (0x7UL << SYSCFG_EXTICR1_EXTI1_Pos)             /*!< 0x00000070 */
#define SYSCFG_EXTICR1_EXTI1                    SYSCFG_EXTICR1_EXTI1_Msk                        /*!< External Interrupt Line 1 configuration */
#define SYSCFG_EXTICR1_EXTI2_Pos                (8U)
#define SYSCFG_EXTICR1_EXTI2_Msk                (0x7UL << SYSCFG_EXTICR1_EXTI2_Pos)             /*!< 0x00000700 */
#define SYSCFG_EXTICR1_EXTI2                    SYSCFG_EXTICR1_EXTI2_Msk                        /*!< External Interrupt Line 2 configuration */
#define SYSCFG_EXTICR1_EXTI3_Pos                (12U)
#define SYSCFG_EXTICR1_EXTI3_Msk                (0x7UL << SYSCFG_EXTICR1_EXTI3_Pos)             /*!< 0x00007000 */
#define SYSCFG_EXTICR1_EXTI3                    SYSCFG_EXTICR1_EXTI3_Msk                        /*!< External Interrupt Line 3 configuration */

/**
  * @brief  External Interrupt Line 0 Source Input configuration
  */
#define SYSCFG_EXTICR1_EXTI0_PA                 (0x00000000UL)  /*!< PA[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PB                 (0x00000001UL)  /*!< PB[0] pin */

/**
  * @brief  External Interrupt Line 1 Source Input configuration
  */
#define SYSCFG_EXTICR1_EXTI1_PA                 (0x00000000UL)  /*!< PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB                 (0x00000010UL)  /*!< PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC                 (0x00000020UL)  /*!< PC[1] pin */

/**
  * @brief  External Interrupt Line 2 Source Input configuration
  */
#define SYSCFG_EXTICR1_EXTI2_PA                 (0x00000000UL)  /*!< PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB                 (0x00000100UL)  /*!< PB[2] pin */

/**
  * @brief  External Interrupt Line 3 Source Input configuration
  */
#define SYSCFG_EXTICR1_EXTI3_PA                 (0x00000000UL)  /*!< PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB                 (0x00001000UL)  /*!< PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PH                 (0x00007000UL)  /*!< PH[3] pin */

/*****************  Bit definition for SYSCFG_EXTICR2 register  (External interrupt configuration register 2) ********************************/
#define SYSCFG_EXTICR2_EXTI4_Pos                (0U)
#define SYSCFG_EXTICR2_EXTI4_Msk                (0x7UL << SYSCFG_EXTICR2_EXTI4_Pos)             /*!< 0x00000007 */
#define SYSCFG_EXTICR2_EXTI4                    SYSCFG_EXTICR2_EXTI4_Msk                        /*!< External Interrupt Line 4 configuration */
#define SYSCFG_EXTICR2_EXTI5_Pos                (4U)
#define SYSCFG_EXTICR2_EXTI5_Msk                (0x7UL << SYSCFG_EXTICR2_EXTI5_Pos)             /*!< 0x00000070 */
#define SYSCFG_EXTICR2_EXTI5                    SYSCFG_EXTICR2_EXTI5_Msk                        /*!< External Interrupt Line 5 configuration */
#define SYSCFG_EXTICR2_EXTI6_Pos                (8U)
#define SYSCFG_EXTICR2_EXTI6_Msk                (0x7UL << SYSCFG_EXTICR2_EXTI6_Pos)             /*!< 0x00000700 */
#define SYSCFG_EXTICR2_EXTI6                    SYSCFG_EXTICR2_EXTI6_Msk                        /*!< External Interrupt Line 6 configuration */
#define SYSCFG_EXTICR2_EXTI7_Pos                (12U)
#define SYSCFG_EXTICR2_EXTI7_Msk                (0x7UL << SYSCFG_EXTICR2_EXTI7_Pos)             /*!< 0x00007000 */
#define SYSCFG_EXTICR2_EXTI7                    SYSCFG_EXTICR2_EXTI7_Msk                        /*!< External Interrupt Line 7 configuration */

/**
  * @brief  External Interrupt Line 4 Source Input configuration
  */
#define SYSCFG_EXTICR2_EXTI4_PA                 (0x00000000UL)  /*!< PA[4] pin  */
#define SYSCFG_EXTICR2_EXTI4_PB                 (0x00000001UL)  /*!< PB[4] pin  */
#define SYSCFG_EXTICR2_EXTI4_PE                 (0x00000004UL)  /*!< PE[4] pin  */

/**
  * @brief  External Interrupt Line 5 Source Input configuration
  */
#define SYSCFG_EXTICR2_EXTI5_PA                 (0x00000000UL)  /*!< PA[5] pin  */
#define SYSCFG_EXTICR2_EXTI5_PB                 (0x00000010UL)  /*!< PB[5] pin  */

/**
  * @brief  External Interrupt Line 6 Source Input configuration
  */
#define SYSCFG_EXTICR2_EXTI6_PA                 (0x00000000UL)  /*!< PA[6] pin  */
#define SYSCFG_EXTICR2_EXTI6_PB                 (0x00000100UL)  /*!< PB[6] pin  */

/**
  * @brief  External Interrupt Line 7 Source Input configuration
  */
#define SYSCFG_EXTICR2_EXTI7_PA                 (0x00000000UL)  /*!< PA[7] pin  */
#define SYSCFG_EXTICR2_EXTI7_PB                 (0x00001000UL)  /*!< PB[7] pin  */

/*****************  Bit definition for SYSCFG_EXTICR3 register  (External interrupt configuration register 3) ********************************/
#define SYSCFG_EXTICR3_EXTI8_Pos                (0U)
#define SYSCFG_EXTICR3_EXTI8_Msk                (0x7UL << SYSCFG_EXTICR3_EXTI8_Pos)             /*!< 0x00000007 */
#define SYSCFG_EXTICR3_EXTI8                    SYSCFG_EXTICR3_EXTI8_Msk                        /*!< External Interrupt Line 8 configuration */
#define SYSCFG_EXTICR3_EXTI9_Pos                (4U)
#define SYSCFG_EXTICR3_EXTI9_Msk                (0x7UL << SYSCFG_EXTICR3_EXTI9_Pos)             /*!< 0x00000070 */
#define SYSCFG_EXTICR3_EXTI9                    SYSCFG_EXTICR3_EXTI9_Msk                        /*!< External Interrupt Line 9 configuration */
#define SYSCFG_EXTICR3_EXTI10_Pos               (8U)
#define SYSCFG_EXTICR3_EXTI10_Msk               (0x7UL << SYSCFG_EXTICR3_EXTI10_Pos)            /*!< 0x00000700 */
#define SYSCFG_EXTICR3_EXTI10                   SYSCFG_EXTICR3_EXTI10_Msk                       /*!< External Interrupt Line 10 configuration */
#define SYSCFG_EXTICR3_EXTI11_Pos               (12U)
#define SYSCFG_EXTICR3_EXTI11_Msk               (0xFUL << SYSCFG_EXTICR3_EXTI11_Pos)            /*!< 0x0000F000 */
#define SYSCFG_EXTICR3_EXTI11                   SYSCFG_EXTICR3_EXTI11_Msk                       /*!< External Interrupt Line 11 configuration */

/**
  * @brief  External Interrupt Line 8 Source Input configuration
  */
#define SYSCFG_EXTICR3_EXTI8_PA                 (0x00000000UL)  /*!< PA[8] pin  */
#define SYSCFG_EXTICR3_EXTI8_PB                 (0x00000001UL)  /*!< PB[8] pin  */

/**
  * @brief  External Interrupt Line 9 Source Input configuration
  */
#define SYSCFG_EXTICR3_EXTI9_PA                 (0x00000000UL)  /*!< PA[9] pin  */
#define SYSCFG_EXTICR3_EXTI9_PB                 (0x00000010UL)  /*!< PB[9] pin  */

/**
  * @brief  External Interrupt Line 10 Source Input configuration
  */
#define SYSCFG_EXTICR3_EXTI10_PA                (0x00000000UL)  /*!< PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB                (0x00000100UL)  /*!< PB[10] pin */

/**
  * @brief  External Interrupt Line 11 Source Input configuration
  */
#define SYSCFG_EXTICR3_EXTI11_PA                (0x00000000UL)  /*!< PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB                (0x00001000UL)  /*!< PB[11] pin */

/*****************  Bit definition for SYSCFG_EXTICR4 register  (External interrupt configuration register 4) *********************************/
#define SYSCFG_EXTICR4_EXTI12_Pos               (0U)
#define SYSCFG_EXTICR4_EXTI12_Msk               (0x7UL << SYSCFG_EXTICR4_EXTI12_Pos)            /*!< 0x00000007 */
#define SYSCFG_EXTICR4_EXTI12                   SYSCFG_EXTICR4_EXTI12_Msk                       /*!< External Interrupt Line 12 configuration */
#define SYSCFG_EXTICR4_EXTI13_Pos               (4U)
#define SYSCFG_EXTICR4_EXTI13_Msk               (0x7UL << SYSCFG_EXTICR4_EXTI13_Pos)            /*!< 0x00000070 */
#define SYSCFG_EXTICR4_EXTI13                   SYSCFG_EXTICR4_EXTI13_Msk                       /*!< External Interrupt Line 13 configuration */
#define SYSCFG_EXTICR4_EXTI14_Pos               (8U)
#define SYSCFG_EXTICR4_EXTI14_Msk               (0x7UL << SYSCFG_EXTICR4_EXTI14_Pos)            /*!< 0x00000700 */
#define SYSCFG_EXTICR4_EXTI14                   SYSCFG_EXTICR4_EXTI14_Msk                       /*!< External Interrupt Line 14 configuration */
#define SYSCFG_EXTICR4_EXTI15_Pos               (12U)
#define SYSCFG_EXTICR4_EXTI15_Msk               (0x7UL << SYSCFG_EXTICR4_EXTI15_Pos)            /*!< 0x00007000 */
#define SYSCFG_EXTICR4_EXTI15                   SYSCFG_EXTICR4_EXTI15_Msk                       /*!< External Interrupt Line 15 configuration */

/**
  * @brief  External Interrupt Line 12 Source Input configuration
  */
#define SYSCFG_EXTICR4_EXTI12_PA                (0x00000000UL)  /*!< PA[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PB                (0x00000001UL)  /*!< PB[12] pin */

/**
  * @brief  External Interrupt Line 13 Source Input configuration
  */
#define SYSCFG_EXTICR4_EXTI13_PA                (0x00000000UL)  /*!< PA[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PB                (0x00000010UL)  /*!< PB[13] pin */

/**
  * @brief  External Interrupt Line 14 Source Input configuration
  */
#define SYSCFG_EXTICR4_EXTI14_PA                (0x00000000UL)  /*!< PA[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PB                (0x00000100UL)  /*!< PB[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PC                (0x00000200UL)  /*!< PC[14] pin */

/**
  * @brief  External Interrupt Line 15 Source Input configuration
  */
#define SYSCFG_EXTICR4_EXTI15_PA                (0x00000000UL)  /*!< PA[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PB                (0x00001000UL)  /*!< PB[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PC                (0x00002000UL)  /*!< PC[15] pin */

/*****************  Bit definition for SYSCFG_SCSR register  (SYSCFG SRAM2 control and status register) *********************************************************/
#define SYSCFG_SCSR_SRAM2ER_Pos                 (0U)
#define SYSCFG_SCSR_SRAM2ER_Msk                 (0x1UL << SYSCFG_SCSR_SRAM2ER_Pos)              /*!< 0x00000001 */
#define SYSCFG_SCSR_SRAM2ER                     SYSCFG_SCSR_SRAM2ER_Msk                         /*!< SRAM2 and PKA RAM Erase                                    */
#define SYSCFG_SCSR_SRAM2BSY_Pos                (1U)
#define SYSCFG_SCSR_SRAM2BSY_Msk                (0x1UL << SYSCFG_SCSR_SRAM2BSY_Pos)             /*!< 0x00000002 */
#define SYSCFG_SCSR_SRAM2BSY                    SYSCFG_SCSR_SRAM2BSY_Msk                        /*!< SRAM2 and PKA RAM busy by erase operation                  */
#define SYSCFG_SCSR_C2RFD_Pos                   (31U)
#define SYSCFG_SCSR_C2RFD_Msk                   (0x1UL << SYSCFG_SCSR_C2RFD_Pos)                /*!< 0x80000000 */
#define SYSCFG_SCSR_C2RFD                       SYSCFG_SCSR_C2RFD_Msk                           /*!< CPU2 SRAM fetch (execution) disable                        */

/*****************  Bit definition for SYSCFG_CFGR2 register  (SYSCFG configuration register 2) *****************************************************************/
#define SYSCFG_CFGR2_CLL_Pos                    (0U)
#define SYSCFG_CFGR2_CLL_Msk                    (0x1UL << SYSCFG_CFGR2_CLL_Pos)                 /*!< 0x00000001 */
#define SYSCFG_CFGR2_CLL                        SYSCFG_CFGR2_CLL_Msk                            /*!< Cortex M4 LOCKUP (hardfault) output enable                 */
#define SYSCFG_CFGR2_SPL_Pos                    (1U)
#define SYSCFG_CFGR2_SPL_Msk                    (0x1UL << SYSCFG_CFGR2_SPL_Pos)                 /*!< 0x00000002 */
#define SYSCFG_CFGR2_SPL                        SYSCFG_CFGR2_SPL_Msk                            /*!< SRAM2 Parity Lock                                          */
#define SYSCFG_CFGR2_PVDL_Pos                   (2U)
#define SYSCFG_CFGR2_PVDL_Msk                   (0x1UL << SYSCFG_CFGR2_PVDL_Pos)                /*!< 0x00000004 */
#define SYSCFG_CFGR2_PVDL                       SYSCFG_CFGR2_PVDL_Msk                           /*!< PVD Lock                                                   */
#define SYSCFG_CFGR2_ECCL_Pos                   (3U)
#define SYSCFG_CFGR2_ECCL_Msk                   (0x1UL << SYSCFG_CFGR2_ECCL_Pos)                /*!< 0x00000008 */
#define SYSCFG_CFGR2_ECCL                       SYSCFG_CFGR2_ECCL_Msk                           /*!< ECC Lock                                                   */
#define SYSCFG_CFGR2_SPF_Pos                    (8U)
#define SYSCFG_CFGR2_SPF_Msk                    (0x1UL << SYSCFG_CFGR2_SPF_Pos)                 /*!< 0x00000100 */
#define SYSCFG_CFGR2_SPF                        SYSCFG_CFGR2_SPF_Msk                            /*!< SRAM2 Parity Lock                                          */

/*****************  Bit definition for SYSCFG_SWPR1 register  (SYSCFG SRAM2A write protection register) *********************************************************/
#define SYSCFG_SWPR1_PAGE0_Pos                  (0U)
#define SYSCFG_SWPR1_PAGE0_Msk                  (0x1UL << SYSCFG_SWPR1_PAGE0_Pos)               /*!< 0x00000001 */
#define SYSCFG_SWPR1_PAGE0                      SYSCFG_SWPR1_PAGE0_Msk                          /*!< SRAM2A Write protection page 0 (0x20030000 - 0x200303FF)   */
#define SYSCFG_SWPR1_PAGE1_Pos                  (1U)
#define SYSCFG_SWPR1_PAGE1_Msk                  (0x1UL << SYSCFG_SWPR1_PAGE1_Pos)               /*!< 0x00000002 */
#define SYSCFG_SWPR1_PAGE1                      SYSCFG_SWPR1_PAGE1_Msk                          /*!< SRAM2A Write protection page 1 (0x20030400 - 0x200307FF)   */
#define SYSCFG_SWPR1_PAGE2_Pos                  (2U)
#define SYSCFG_SWPR1_PAGE2_Msk                  (0x1UL << SYSCFG_SWPR1_PAGE2_Pos)               /*!< 0x00000004 */
#define SYSCFG_SWPR1_PAGE2                      SYSCFG_SWPR1_PAGE2_Msk                          /*!< SRAM2A Write protection page 2 (0x20030800 - 0x20030BFF)   */
#define SYSCFG_SWPR1_PAGE3_Pos                  (3U)
#define SYSCFG_SWPR1_PAGE3_Msk                  (0x1UL << SYSCFG_SWPR1_PAGE3_Pos)               /*!< 0x00000008 */
#define SYSCFG_SWPR1_PAGE3                      SYSCFG_SWPR1_PAGE3_Msk                          /*!< SRAM2A Write protection page 3 (0x20030C00 - 0x20030FFF)   */
#define SYSCFG_SWPR1_PAGE4_Pos                  (4U)
#define SYSCFG_SWPR1_PAGE4_Msk                  (0x1UL << SYSCFG_SWPR1_PAGE4_Pos)               /*!< 0x00000010 */
#define SYSCFG_SWPR1_PAGE4                      SYSCFG_SWPR1_PAGE4_Msk                          /*!< SRAM2A Write protection page 4 (0x20031000 - 0x200313FF)   */
#define SYSCFG_SWPR1_PAGE5_Pos                  (5U)
#define SYSCFG_SWPR1_PAGE5_Msk                  (0x1UL << SYSCFG_SWPR1_PAGE5_Pos)               /*!< 0x00000020 */
#define SYSCFG_SWPR1_PAGE5                      SYSCFG_SWPR1_PAGE5_Msk                          /*!< SRAM2A Write protection page 5 (0x20031400 - 0x200317FF)   */
#define SYSCFG_SWPR1_PAGE6_Pos                  (6U)
#define SYSCFG_SWPR1_PAGE6_Msk                  (0x1UL << SYSCFG_SWPR1_PAGE6_Pos)               /*!< 0x00000040 */
#define SYSCFG_SWPR1_PAGE6                      SYSCFG_SWPR1_PAGE6_Msk                          /*!< SRAM2A Write protection page 6 (0x20031800 - 0x20031BFF)   */
#define SYSCFG_SWPR1_PAGE7_Pos                  (7U)
#define SYSCFG_SWPR1_PAGE7_Msk                  (0x1UL << SYSCFG_SWPR1_PAGE7_Pos)               /*!< 0x00000080 */
#define SYSCFG_SWPR1_PAGE7                      SYSCFG_SWPR1_PAGE7_Msk                          /*!< SRAM2A Write protection page 7 (0x20031C00 - 0x20031FFF)   */
#define SYSCFG_SWPR1_PAGE8_Pos                  (8U)
#define SYSCFG_SWPR1_PAGE8_Msk                  (0x1UL << SYSCFG_SWPR1_PAGE8_Pos)               /*!< 0x00000100 */
#define SYSCFG_SWPR1_PAGE8                      SYSCFG_SWPR1_PAGE8_Msk                          /*!< SRAM2A Write protection page 8 (0x20032000 - 0x200323FF)   */
#define SYSCFG_SWPR1_PAGE9_Pos                  (9U)
#define SYSCFG_SWPR1_PAGE9_Msk                  (0x1UL << SYSCFG_SWPR1_PAGE9_Pos)               /*!< 0x00000200 */
#define SYSCFG_SWPR1_PAGE9                      SYSCFG_SWPR1_PAGE9_Msk                          /*!< SRAM2A Write protection page 9 (0x20032400 - 0x200327FF)   */
#define SYSCFG_SWPR1_PAGE10_Pos                 (10U)
#define SYSCFG_SWPR1_PAGE10_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE10_Pos)              /*!< 0x00000400 */
#define SYSCFG_SWPR1_PAGE10                     SYSCFG_SWPR1_PAGE10_Msk                         /*!< SRAM2A Write protection page 10 (0x20032800 - 0x20032BFF)  */
#define SYSCFG_SWPR1_PAGE11_Pos                 (11U)
#define SYSCFG_SWPR1_PAGE11_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE11_Pos)              /*!< 0x00000800 */
#define SYSCFG_SWPR1_PAGE11                     SYSCFG_SWPR1_PAGE11_Msk                         /*!< SRAM2A Write protection page 11 (0x20032C00 - 0x20032FFF)  */
#define SYSCFG_SWPR1_PAGE12_Pos                 (12U)
#define SYSCFG_SWPR1_PAGE12_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE12_Pos)              /*!< 0x00001000 */
#define SYSCFG_SWPR1_PAGE12                     SYSCFG_SWPR1_PAGE12_Msk                         /*!< SRAM2A Write protection page 12 (0x20033000 - 0x200333FF)  */
#define SYSCFG_SWPR1_PAGE13_Pos                 (13U)
#define SYSCFG_SWPR1_PAGE13_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE13_Pos)              /*!< 0x00002000 */
#define SYSCFG_SWPR1_PAGE13                     SYSCFG_SWPR1_PAGE13_Msk                         /*!< SRAM2A Write protection page 13 (0x20033400 - 0x200337FF)  */
#define SYSCFG_SWPR1_PAGE14_Pos                 (14U)
#define SYSCFG_SWPR1_PAGE14_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE14_Pos)              /*!< 0x00004000 */
#define SYSCFG_SWPR1_PAGE14                     SYSCFG_SWPR1_PAGE14_Msk                         /*!< SRAM2A Write protection page 14 (0x20033800 - 0x20033BFF)  */
#define SYSCFG_SWPR1_PAGE15_Pos                 (15U)
#define SYSCFG_SWPR1_PAGE15_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE15_Pos)              /*!< 0x00008000 */
#define SYSCFG_SWPR1_PAGE15                     SYSCFG_SWPR1_PAGE15_Msk                         /*!< SRAM2A Write protection page 15 (0x20033C00 - 0x20033FFF)  */
#define SYSCFG_SWPR1_PAGE16_Pos                 (16U)
#define SYSCFG_SWPR1_PAGE16_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE16_Pos)              /*!< 0x00010000 */
#define SYSCFG_SWPR1_PAGE16                     SYSCFG_SWPR1_PAGE16_Msk                         /*!< SRAM2A Write protection page 16 (0x20034000 - 0x200343FF)  */
#define SYSCFG_SWPR1_PAGE17_Pos                 (17U)
#define SYSCFG_SWPR1_PAGE17_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE17_Pos)              /*!< 0x00020000 */
#define SYSCFG_SWPR1_PAGE17                     SYSCFG_SWPR1_PAGE17_Msk                         /*!< SRAM2A Write protection page 17 (0x20034400 - 0x200347FF)  */
#define SYSCFG_SWPR1_PAGE18_Pos                 (18U)
#define SYSCFG_SWPR1_PAGE18_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE18_Pos)              /*!< 0x00040000 */
#define SYSCFG_SWPR1_PAGE18                     SYSCFG_SWPR1_PAGE18_Msk                         /*!< SRAM2A Write protection page 18 (0x20034800 - 0x20034BFF)  */
#define SYSCFG_SWPR1_PAGE19_Pos                 (19U)
#define SYSCFG_SWPR1_PAGE19_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE19_Pos)              /*!< 0x00080000 */
#define SYSCFG_SWPR1_PAGE19                     SYSCFG_SWPR1_PAGE19_Msk                         /*!< SRAM2A Write protection page 19 (0x20034C00 - 0x20034FFF)  */
#define SYSCFG_SWPR1_PAGE20_Pos                 (20U)
#define SYSCFG_SWPR1_PAGE20_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE20_Pos)              /*!< 0x00100000 */
#define SYSCFG_SWPR1_PAGE20                     SYSCFG_SWPR1_PAGE20_Msk                         /*!< SRAM2A Write protection page 20 (0x20035000 - 0x200353FF)  */
#define SYSCFG_SWPR1_PAGE21_Pos                 (21U)
#define SYSCFG_SWPR1_PAGE21_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE21_Pos)              /*!< 0x00200000 */
#define SYSCFG_SWPR1_PAGE21                     SYSCFG_SWPR1_PAGE21_Msk                         /*!< SRAM2A Write protection page 21 (0x20035400 - 0x200357FF)  */
#define SYSCFG_SWPR1_PAGE22_Pos                 (22U)
#define SYSCFG_SWPR1_PAGE22_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE22_Pos)              /*!< 0x00400000 */
#define SYSCFG_SWPR1_PAGE22                     SYSCFG_SWPR1_PAGE22_Msk                         /*!< SRAM2A Write protection page 22 (0x20035800 - 0x20035BFF)  */
#define SYSCFG_SWPR1_PAGE23_Pos                 (23U)
#define SYSCFG_SWPR1_PAGE23_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE23_Pos)              /*!< 0x00800000 */
#define SYSCFG_SWPR1_PAGE23                     SYSCFG_SWPR1_PAGE23_Msk                         /*!< SRAM2A Write protection page 23 (0x20035C00 - 0x20035FFF)  */
#define SYSCFG_SWPR1_PAGE24_Pos                 (24U)
#define SYSCFG_SWPR1_PAGE24_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE24_Pos)              /*!< 0x01000000 */
#define SYSCFG_SWPR1_PAGE24                     SYSCFG_SWPR1_PAGE24_Msk                         /*!< SRAM2A Write protection page 24 (0x20036000 - 0x200363FF)  */
#define SYSCFG_SWPR1_PAGE25_Pos                 (25U)
#define SYSCFG_SWPR1_PAGE25_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE25_Pos)              /*!< 0x02000000 */
#define SYSCFG_SWPR1_PAGE25                     SYSCFG_SWPR1_PAGE25_Msk                         /*!< SRAM2A Write protection page 25 (0x20036400 - 0x200367FF)  */
#define SYSCFG_SWPR1_PAGE26_Pos                 (26U)
#define SYSCFG_SWPR1_PAGE26_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE26_Pos)              /*!< 0x04000000 */
#define SYSCFG_SWPR1_PAGE26                     SYSCFG_SWPR1_PAGE26_Msk                         /*!< SRAM2A Write protection page 26 (0x20036800 - 0x20036BFF)  */
#define SYSCFG_SWPR1_PAGE27_Pos                 (27U)
#define SYSCFG_SWPR1_PAGE27_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE27_Pos)              /*!< 0x08000000 */
#define SYSCFG_SWPR1_PAGE27                     SYSCFG_SWPR1_PAGE27_Msk                         /*!< SRAM2A Write protection page 27 (0x20036C00 - 0x20036FFF)  */
#define SYSCFG_SWPR1_PAGE28_Pos                 (28U)
#define SYSCFG_SWPR1_PAGE28_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE28_Pos)              /*!< 0x10000000 */
#define SYSCFG_SWPR1_PAGE28                     SYSCFG_SWPR1_PAGE28_Msk                         /*!< SRAM2A Write protection page 28 (0x20037000 - 0x200373FF)  */
#define SYSCFG_SWPR1_PAGE29_Pos                 (29U)
#define SYSCFG_SWPR1_PAGE29_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE29_Pos)              /*!< 0x20000000 */
#define SYSCFG_SWPR1_PAGE29                     SYSCFG_SWPR1_PAGE29_Msk                         /*!< SRAM2A Write protection page 29 (0x20037400 - 0x200377FF)  */
#define SYSCFG_SWPR1_PAGE30_Pos                 (30U)
#define SYSCFG_SWPR1_PAGE30_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE30_Pos)              /*!< 0x40000000 */
#define SYSCFG_SWPR1_PAGE30                     SYSCFG_SWPR1_PAGE30_Msk                         /*!< SRAM2A Write protection page 30 (0x20037800 - 0x20037BFF)  */
#define SYSCFG_SWPR1_PAGE31_Pos                 (31U)
#define SYSCFG_SWPR1_PAGE31_Msk                 (0x1UL << SYSCFG_SWPR1_PAGE31_Pos)              /*!< 0x80000000 */
#define SYSCFG_SWPR1_PAGE31                     SYSCFG_SWPR1_PAGE31_Msk                         /*!< SRAM2A Write protection page 31 (0x20037C00 - 0x20037FFF)  */

/*****************  Bit definition for SYSCFG_SKR register  (SYSCFG SRAM2 key register) *************************************************************************/
#define SYSCFG_SKR_KEY_Pos                      (0U)
#define SYSCFG_SKR_KEY_Msk                      (0xFFUL << SYSCFG_SKR_KEY_Pos)                  /*!< 0x000000FF */
#define SYSCFG_SKR_KEY                          SYSCFG_SKR_KEY_Msk                              /*!< SRAM2 write protection key for software erase              */

/*****************  Bit definition for SYSCFG_SWPR2 register  (SYSCFG SRAM2 write protection register) **********************************************************/
#define SYSCFG_SWPR2_PAGE32_Pos                 (0U)
#define SYSCFG_SWPR2_PAGE32_Msk                 (0x1UL << SYSCFG_SWPR2_PAGE32_Pos)              /*!< 0x00000001 */
#define SYSCFG_SWPR2_PAGE32                     SYSCFG_SWPR2_PAGE32_Msk                         /*!< SRAM2B Write protection page 0 (0x20038000 - 0x200383FF)   */
#define SYSCFG_SWPR2_PAGE33_Pos                 (1U)
#define SYSCFG_SWPR2_PAGE33_Msk                 (0x1UL << SYSCFG_SWPR2_PAGE33_Pos)              /*!< 0x00000002 */
#define SYSCFG_SWPR2_PAGE33                     SYSCFG_SWPR2_PAGE33_Msk                         /*!< SRAM2B Write protection page 1 (0x20038400 - 0x200387FF)   */
#define SYSCFG_SWPR2_PAGE34_Pos                 (2U)
#define SYSCFG_SWPR2_PAGE34_Msk                 (0x1UL << SYSCFG_SWPR2_PAGE34_Pos)              /*!< 0x00000004 */
#define SYSCFG_SWPR2_PAGE34                     SYSCFG_SWPR2_PAGE34_Msk                         /*!< SRAM2B Write protection page 2 (0x20038800 - 0x20038bFF)   */
#define SYSCFG_SWPR2_PAGE35_Pos                 (3U)
#define SYSCFG_SWPR2_PAGE35_Msk                 (0x1UL << SYSCFG_SWPR2_PAGE35_Pos)              /*!< 0x00000008 */
#define SYSCFG_SWPR2_PAGE35                     SYSCFG_SWPR2_PAGE35_Msk                         /*!< SRAM2B Write protection page 3 (0x20038C00 - 0x20038FFF)   */

/*****************  Bit definition for SYSCFG_IMR1 register (Interrupt masks control and status register on CPU1 - part 1) *******************************************/
#define SYSCFG_IMR1_TIM1IM_Pos                  (13U)
#define SYSCFG_IMR1_TIM1IM_Msk                  (0x1UL << SYSCFG_IMR1_TIM1IM_Pos)             /*!< 0x00002000 */
#define SYSCFG_IMR1_TIM1IM                      SYSCFG_IMR1_TIM1IM_Msk                        /*!< Enabling of interrupt from Timer 1 to CPU1                        */
#define SYSCFG_IMR1_EXTI5IM_Pos                 (21U)
#define SYSCFG_IMR1_EXTI5IM_Msk                 (0x1UL << SYSCFG_IMR1_EXTI5IM_Pos)            /*!< 0x00200000 */
#define SYSCFG_IMR1_EXTI5IM                     SYSCFG_IMR1_EXTI5IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 5 to CPU1      */
#define SYSCFG_IMR1_EXTI6IM_Pos                 (22U)
#define SYSCFG_IMR1_EXTI6IM_Msk                 (0x1UL << SYSCFG_IMR1_EXTI6IM_Pos)            /*!< 0x00400000 */
#define SYSCFG_IMR1_EXTI6IM                     SYSCFG_IMR1_EXTI6IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 6 to CPU1      */
#define SYSCFG_IMR1_EXTI7IM_Pos                 (23U)
#define SYSCFG_IMR1_EXTI7IM_Msk                 (0x1UL << SYSCFG_IMR1_EXTI7IM_Pos)            /*!< 0x00800000 */
#define SYSCFG_IMR1_EXTI7IM                     SYSCFG_IMR1_EXTI7IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 7 to CPU1      */
#define SYSCFG_IMR1_EXTI8IM_Pos                 (24U)
#define SYSCFG_IMR1_EXTI8IM_Msk                 (0x1UL << SYSCFG_IMR1_EXTI8IM_Pos)            /*!< 0x01000000 */
#define SYSCFG_IMR1_EXTI8IM                     SYSCFG_IMR1_EXTI8IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 8 to CPU1      */
#define SYSCFG_IMR1_EXTI9IM_Pos                 (25U)
#define SYSCFG_IMR1_EXTI9IM_Msk                 (0x1UL << SYSCFG_IMR1_EXTI9IM_Pos)            /*!< 0x02000000 */
#define SYSCFG_IMR1_EXTI9IM                     SYSCFG_IMR1_EXTI9IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 9 to CPU1      */
#define SYSCFG_IMR1_EXTI10IM_Pos                (26U)
#define SYSCFG_IMR1_EXTI10IM_Msk                (0x1UL << SYSCFG_IMR1_EXTI10IM_Pos)           /*!< 0x04000000 */
#define SYSCFG_IMR1_EXTI10IM                    SYSCFG_IMR1_EXTI10IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 10 to CPU1     */
#define SYSCFG_IMR1_EXTI11IM_Pos                (27U)
#define SYSCFG_IMR1_EXTI11IM_Msk                (0x1UL << SYSCFG_IMR1_EXTI11IM_Pos)           /*!< 0x08000000 */
#define SYSCFG_IMR1_EXTI11IM                    SYSCFG_IMR1_EXTI11IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 11 to CPU1     */
#define SYSCFG_IMR1_EXTI12IM_Pos                (28U)
#define SYSCFG_IMR1_EXTI12IM_Msk                (0x1UL << SYSCFG_IMR1_EXTI12IM_Pos)           /*!< 0x10000000 */
#define SYSCFG_IMR1_EXTI12IM                    SYSCFG_IMR1_EXTI12IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 12 to CPU1     */
#define SYSCFG_IMR1_EXTI13IM_Pos                (29U)
#define SYSCFG_IMR1_EXTI13IM_Msk                (0x1UL << SYSCFG_IMR1_EXTI13IM_Pos)           /*!< 0x20000000 */
#define SYSCFG_IMR1_EXTI13IM                    SYSCFG_IMR1_EXTI13IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 13 to CPU1     */
#define SYSCFG_IMR1_EXTI14IM_Pos                (30U)
#define SYSCFG_IMR1_EXTI14IM_Msk                (0x1UL << SYSCFG_IMR1_EXTI14IM_Pos)           /*!< 0x40000000 */
#define SYSCFG_IMR1_EXTI14IM                    SYSCFG_IMR1_EXTI14IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 14 to CPU1     */
#define SYSCFG_IMR1_EXTI15IM_Pos                (31U)
#define SYSCFG_IMR1_EXTI15IM_Msk                (0x1UL << SYSCFG_IMR1_EXTI15IM_Pos)           /*!< 0x80000000 */
#define SYSCFG_IMR1_EXTI15IM                    SYSCFG_IMR1_EXTI15IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 15 to CPU1     */

/*****************  Bit definition for SYSCFG_IMR2 register (Interrupt masks control and status register on CPU1 - part 2) *******************************************/
#define SYSCFG_IMR2_PVM3IM_Pos                  (18U)
#define SYSCFG_IMR2_PVM3IM_Msk                  (0x1UL << SYSCFG_IMR2_PVM3IM_Pos)             /*!< 0x00040000 */
#define SYSCFG_IMR2_PVM3IM                      SYSCFG_IMR2_PVM3IM_Msk                        /*!< Enabling of interrupt from Power Voltage Monitoring 3 to CPU1     */
#define SYSCFG_IMR2_PVDIM_Pos                   (20U)
#define SYSCFG_IMR2_PVDIM_Msk                   (0x1UL << SYSCFG_IMR2_PVDIM_Pos)              /*!< 0x00100000 */
#define SYSCFG_IMR2_PVDIM                       SYSCFG_IMR2_PVDIM_Msk                         /*!< Enabling of interrupt from Power Voltage Detector to CPU1         */

/*****************  Bit definition for SYSCFG_C2IMR1 register (Interrupt masks control and status register on CPU2 - part 1) *******************************************/
#define SYSCFG_C2IMR1_RTCSTAMPTAMPLSECSSIM_Pos    (0U)
#define SYSCFG_C2IMR1_RTCSTAMPTAMPLSECSSIM_Msk    (0x1UL << SYSCFG_C2IMR1_RTCSTAMPTAMPLSECSSIM_Pos) /*!< 0x00000001 */
#define SYSCFG_C2IMR1_RTCSTAMPTAMPLSECSSIM        SYSCFG_C2IMR1_RTCSTAMPTAMPLSECSSIM_Msk            /* !< Enabling of interrupt from RTC TimeStamp, RTC Tampers
                                                                                                      and LSE Clock Security System to CPU2                            */
#define SYSCFG_C2IMR1_RTCWKUPIM_Pos             (3U)
#define SYSCFG_C2IMR1_RTCWKUPIM_Msk             (0x1UL << SYSCFG_C2IMR1_RTCWKUPIM_Pos)          /*!< 0x00000008 */
#define SYSCFG_C2IMR1_RTCWKUPIM                 SYSCFG_C2IMR1_RTCWKUPIM_Msk                     /*!< Enabling of interrupt from RTC Wakeup to CPU2                     */
#define SYSCFG_C2IMR1_RTCALARMIM_Pos            (4U)
#define SYSCFG_C2IMR1_RTCALARMIM_Msk            (0x1UL << SYSCFG_C2IMR1_RTCALARMIM_Pos)         /*!< 0x00000010 */
#define SYSCFG_C2IMR1_RTCALARMIM                SYSCFG_C2IMR1_RTCALARMIM_Msk                    /*!< Enabling of interrupt from RTC Alarms to CPU2                     */
#define SYSCFG_C2IMR1_RCCIM_Pos                 (5U)
#define SYSCFG_C2IMR1_RCCIM_Msk                 (0x1UL << SYSCFG_C2IMR1_RCCIM_Pos)              /*!< 0x00000020 */
#define SYSCFG_C2IMR1_RCCIM                     SYSCFG_C2IMR1_RCCIM_Msk                         /*!< Enabling of interrupt from RCC to CPU2                            */
#define SYSCFG_C2IMR1_FLASHIM_Pos               (6U)
#define SYSCFG_C2IMR1_FLASHIM_Msk               (0x1UL << SYSCFG_C2IMR1_FLASHIM_Pos)            /*!< 0x00000040 */
#define SYSCFG_C2IMR1_FLASHIM                   SYSCFG_C2IMR1_FLASHIM_Msk                       /*!< Enabling of interrupt from FLASH to CPU2                          */
#define SYSCFG_C2IMR1_PKAIM_Pos                 (8U)
#define SYSCFG_C2IMR1_PKAIM_Msk                 (0x1UL << SYSCFG_C2IMR1_PKAIM_Pos)              /*!< 0x00000100 */
#define SYSCFG_C2IMR1_PKAIM                     SYSCFG_C2IMR1_PKAIM_Msk                         /*!< Enabling of interrupt from Public Key Accelerator to CPU2         */
#define SYSCFG_C2IMR1_RNGIM_Pos                 (9U)
#define SYSCFG_C2IMR1_RNGIM_Msk                 (0x1UL << SYSCFG_C2IMR1_RNGIM_Pos)              /*!< 0x00000200 */
#define SYSCFG_C2IMR1_RNGIM                     SYSCFG_C2IMR1_RNGIM_Msk                         /*!< Enabling of interrupt from Random Number Generator to CPU2        */
#define SYSCFG_C2IMR1_COMPIM_Pos                (11U)
#define SYSCFG_C2IMR1_COMPIM_Msk                (0x1UL << SYSCFG_C2IMR1_COMPIM_Pos)             /*!< 0x00000800 */
#define SYSCFG_C2IMR1_COMPIM                    SYSCFG_C2IMR1_COMPIM_Msk                        /*!< Enabling of interrupt from Comparator to CPU2                     */
#define SYSCFG_C2IMR1_ADCIM_Pos                 (12U)
#define SYSCFG_C2IMR1_ADCIM_Msk                 (0x1UL << SYSCFG_C2IMR1_ADCIM_Pos)              /*!< 0x00001000 */
#define SYSCFG_C2IMR1_ADCIM                     SYSCFG_C2IMR1_ADCIM_Msk                         /*!< Enabling of interrupt from Analog Digital Converter to CPU2       */
#define SYSCFG_C2IMR1_EXTI0IM_Pos               (16U)
#define SYSCFG_C2IMR1_EXTI0IM_Msk               (0x1UL << SYSCFG_C2IMR1_EXTI0IM_Pos)            /*!< 0x00010000 */
#define SYSCFG_C2IMR1_EXTI0IM                   SYSCFG_C2IMR1_EXTI0IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 0 to CPU2      */
#define SYSCFG_C2IMR1_EXTI1IM_Pos               (17U)
#define SYSCFG_C2IMR1_EXTI1IM_Msk               (0x1UL << SYSCFG_C2IMR1_EXTI1IM_Pos)            /*!< 0x00020000 */
#define SYSCFG_C2IMR1_EXTI1IM                   SYSCFG_C2IMR1_EXTI1IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 1 to CPU2      */
#define SYSCFG_C2IMR1_EXTI2IM_Pos               (18U)
#define SYSCFG_C2IMR1_EXTI2IM_Msk               (0x1UL << SYSCFG_C2IMR1_EXTI2IM_Pos)            /*!< 0x00040000 */
#define SYSCFG_C2IMR1_EXTI2IM                   SYSCFG_C2IMR1_EXTI2IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 2 to CPU2      */
#define SYSCFG_C2IMR1_EXTI3IM_Pos               (19U)
#define SYSCFG_C2IMR1_EXTI3IM_Msk               (0x1UL << SYSCFG_C2IMR1_EXTI3IM_Pos)            /*!< 0x00080000 */
#define SYSCFG_C2IMR1_EXTI3IM                   SYSCFG_C2IMR1_EXTI3IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 3 to CPU2      */
#define SYSCFG_C2IMR1_EXTI4IM_Pos               (20U)
#define SYSCFG_C2IMR1_EXTI4IM_Msk               (0x1UL << SYSCFG_C2IMR1_EXTI4IM_Pos)            /*!< 0x00100000 */
#define SYSCFG_C2IMR1_EXTI4IM                   SYSCFG_C2IMR1_EXTI4IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 4 to CPU2      */
#define SYSCFG_C2IMR1_EXTI5IM_Pos               (21U)
#define SYSCFG_C2IMR1_EXTI5IM_Msk               (0x1UL << SYSCFG_C2IMR1_EXTI5IM_Pos)            /*!< 0x00200000 */
#define SYSCFG_C2IMR1_EXTI5IM                   SYSCFG_C2IMR1_EXTI5IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 5 to CPU2      */
#define SYSCFG_C2IMR1_EXTI6IM_Pos               (22U)
#define SYSCFG_C2IMR1_EXTI6IM_Msk               (0x1UL << SYSCFG_C2IMR1_EXTI6IM_Pos)            /*!< 0x00400000 */
#define SYSCFG_C2IMR1_EXTI6IM                   SYSCFG_C2IMR1_EXTI6IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 6 to CPU2      */
#define SYSCFG_C2IMR1_EXTI7IM_Pos               (23U)
#define SYSCFG_C2IMR1_EXTI7IM_Msk               (0x1UL << SYSCFG_C2IMR1_EXTI7IM_Pos)            /*!< 0x00800000 */
#define SYSCFG_C2IMR1_EXTI7IM                   SYSCFG_C2IMR1_EXTI7IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 7 to CPU2      */
#define SYSCFG_C2IMR1_EXTI8IM_Pos               (24U)
#define SYSCFG_C2IMR1_EXTI8IM_Msk               (0x1UL << SYSCFG_C2IMR1_EXTI8IM_Pos)            /*!< 0x01000000 */
#define SYSCFG_C2IMR1_EXTI8IM                   SYSCFG_C2IMR1_EXTI8IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 8 to CPU2      */
#define SYSCFG_C2IMR1_EXTI9IM_Pos               (25U)
#define SYSCFG_C2IMR1_EXTI9IM_Msk               (0x1UL << SYSCFG_C2IMR1_EXTI9IM_Pos)            /*!< 0x02000000 */
#define SYSCFG_C2IMR1_EXTI9IM                   SYSCFG_C2IMR1_EXTI9IM_Msk                       /*!< Enabling of interrupt from External Interrupt Line 9 to CPU2      */
#define SYSCFG_C2IMR1_EXTI10IM_Pos              (26U)
#define SYSCFG_C2IMR1_EXTI10IM_Msk              (0x1UL << SYSCFG_C2IMR1_EXTI10IM_Pos)           /*!< 0x04000000 */
#define SYSCFG_C2IMR1_EXTI10IM                  SYSCFG_C2IMR1_EXTI10IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 10 to CPU2     */
#define SYSCFG_C2IMR1_EXTI11IM_Pos              (27U)
#define SYSCFG_C2IMR1_EXTI11IM_Msk              (0x1UL << SYSCFG_C2IMR1_EXTI11IM_Pos)           /*!< 0x08000000 */
#define SYSCFG_C2IMR1_EXTI11IM                  SYSCFG_C2IMR1_EXTI11IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 11 to CPU2     */
#define SYSCFG_C2IMR1_EXTI12IM_Pos              (28U)
#define SYSCFG_C2IMR1_EXTI12IM_Msk              (0x1UL << SYSCFG_C2IMR1_EXTI12IM_Pos)           /*!< 0x10000000 */
#define SYSCFG_C2IMR1_EXTI12IM                  SYSCFG_C2IMR1_EXTI12IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 12 to CPU2     */
#define SYSCFG_C2IMR1_EXTI13IM_Pos              (29U)
#define SYSCFG_C2IMR1_EXTI13IM_Msk              (0x1UL << SYSCFG_C2IMR1_EXTI13IM_Pos)           /*!< 0x20000000 */
#define SYSCFG_C2IMR1_EXTI13IM                  SYSCFG_C2IMR1_EXTI13IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 13 to CPU2     */
#define SYSCFG_C2IMR1_EXTI14IM_Pos              (30U)
#define SYSCFG_C2IMR1_EXTI14IM_Msk              (0x1UL << SYSCFG_C2IMR1_EXTI14IM_Pos)           /*!< 0x40000000 */
#define SYSCFG_C2IMR1_EXTI14IM                  SYSCFG_C2IMR1_EXTI14IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 14 to CPU2     */
#define SYSCFG_C2IMR1_EXTI15IM_Pos              (31U)
#define SYSCFG_C2IMR1_EXTI15IM_Msk              (0x1UL << SYSCFG_C2IMR1_EXTI15IM_Pos)           /*!< 0x80000000 */
#define SYSCFG_C2IMR1_EXTI15IM                  SYSCFG_C2IMR1_EXTI15IM_Msk                      /*!< Enabling of interrupt from External Interrupt Line 15 to CPU2     */

/*****************  Bit definition for SYSCFG_C2IMR2 register (Interrupt masks control and status register on CPU2 - part 2) *******************************************/
#define SYSCFG_C2IMR2_DMA1CH1IM_Pos             (0U)
#define SYSCFG_C2IMR2_DMA1CH1IM_Msk             (0x1UL << SYSCFG_C2IMR2_DMA1CH1IM_Pos)          /*!< 0x00000001 */
#define SYSCFG_C2IMR2_DMA1CH1IM                 SYSCFG_C2IMR2_DMA1CH1IM_Msk                     /*!< Enabling of interrupt from DMA1 Channel 1 to CPU2                 */
#define SYSCFG_C2IMR2_DMA1CH2IM_Pos             (1U)
#define SYSCFG_C2IMR2_DMA1CH2IM_Msk             (0x1UL << SYSCFG_C2IMR2_DMA1CH2IM_Pos)          /*!< 0x00000002 */
#define SYSCFG_C2IMR2_DMA1CH2IM                 SYSCFG_C2IMR2_DMA1CH2IM_Msk                     /*!< Enabling of interrupt from DMA1 Channel 2 to CPU2                 */
#define SYSCFG_C2IMR2_DMA1CH3IM_Pos             (2U)
#define SYSCFG_C2IMR2_DMA1CH3IM_Msk             (0x1UL << SYSCFG_C2IMR2_DMA1CH3IM_Pos)          /*!< 0x00000004 */
#define SYSCFG_C2IMR2_DMA1CH3IM                 SYSCFG_C2IMR2_DMA1CH3IM_Msk                     /*!< Enabling of interrupt from DMA1 Channel 3 to CPU2                 */
#define SYSCFG_C2IMR2_DMA1CH4IM_Pos             (3U)
#define SYSCFG_C2IMR2_DMA1CH4IM_Msk             (0x1UL << SYSCFG_C2IMR2_DMA1CH4IM_Pos)          /*!< 0x00000008 */
#define SYSCFG_C2IMR2_DMA1CH4IM                 SYSCFG_C2IMR2_DMA1CH4IM_Msk                     /*!< Enabling of interrupt from DMA1 Channel 4 to CPU2                 */
#define SYSCFG_C2IMR2_DMA1CH5IM_Pos             (4U)
#define SYSCFG_C2IMR2_DMA1CH5IM_Msk             (0x1UL << SYSCFG_C2IMR2_DMA1CH5IM_Pos)          /*!< 0x00000010 */
#define SYSCFG_C2IMR2_DMA1CH5IM                 SYSCFG_C2IMR2_DMA1CH5IM_Msk                     /*!< Enabling of interrupt from DMA1 Channel 5 to CPU2                 */
#define SYSCFG_C2IMR2_DMA1CH6IM_Pos             (5U)
#define SYSCFG_C2IMR2_DMA1CH6IM_Msk             (0x1UL << SYSCFG_C2IMR2_DMA1CH6IM_Pos)          /*!< 0x00000020 */
#define SYSCFG_C2IMR2_DMA1CH6IM                 SYSCFG_C2IMR2_DMA1CH6IM_Msk                     /*!< Enabling of interrupt from DMA1 Channel 6 to CPU2                 */
#define SYSCFG_C2IMR2_DMA1CH7IM_Pos             (6U)
#define SYSCFG_C2IMR2_DMA1CH7IM_Msk             (0x1UL << SYSCFG_C2IMR2_DMA1CH7IM_Pos)          /*!< 0x00000040 */
#define SYSCFG_C2IMR2_DMA1CH7IM                 SYSCFG_C2IMR2_DMA1CH7IM_Msk                     /*!< Enabling of interrupt from DMA1 Channel 7 to CPU2                 */
#define SYSCFG_C2IMR2_DMAMUX1IM_Pos             (15U)
#define SYSCFG_C2IMR2_DMAMUX1IM_Msk             (0x1UL << SYSCFG_C2IMR2_DMAMUX1IM_Pos)          /*!< 0x00008000 */
#define SYSCFG_C2IMR2_DMAMUX1IM                 SYSCFG_C2IMR2_DMAMUX1IM_Msk                     /*!< Enabling of interrupt from DMAMUX1 to CPU2                        */
#define SYSCFG_C2IMR2_PVM3IM_Pos                (18U)
#define SYSCFG_C2IMR2_PVM3IM_Msk                (0x1UL << SYSCFG_C2IMR2_PVM3IM_Pos)             /*!< 0x00040000 */
#define SYSCFG_C2IMR2_PVM3IM                    SYSCFG_C2IMR2_PVM3IM_Msk                        /*!< Enabling of interrupt from Power Voltage Monitoring 3 to CPU2     */
#define SYSCFG_C2IMR2_PVDIM_Pos                 (20U)
#define SYSCFG_C2IMR2_PVDIM_Msk                 (0x1UL << SYSCFG_C2IMR2_PVDIM_Pos)              /*!< 0x00100000 */
#define SYSCFG_C2IMR2_PVDIM                     SYSCFG_C2IMR2_PVDIM_Msk                         /*!< Enabling of interrupt from Power Voltage Detector to CPU2         */
#define SYSCFG_C2IMR2_TSCIM_Pos                 (21U)
#define SYSCFG_C2IMR2_TSCIM_Msk                 (0x1UL << SYSCFG_C2IMR2_TSCIM_Pos)              /*!< 0x00200000 */
#define SYSCFG_C2IMR2_TSCIM                     SYSCFG_C2IMR2_TSCIM_Msk                         /*!< Enabling of interrupt from Touch Sensing Controller to CPU2       */

/*****************  Bit definition for SYSCFG_SIPCR register (SYSCFG secure IP control register) *****************************************************************************/
#define SYSCFG_SIPCR_SAES2_Pos                  (1U)
#define SYSCFG_SIPCR_SAES2_Msk                  (0x1UL << SYSCFG_SIPCR_SAES2_Pos)               /*!< 0x00000002 */
#define SYSCFG_SIPCR_SAES2                      SYSCFG_SIPCR_SAES2_Msk                          /*!< Enabling the security access of Advanced Encryption Standard 2          */
#define SYSCFG_SIPCR_SPKA_Pos                   (2U)
#define SYSCFG_SIPCR_SPKA_Msk                   (0x1UL << SYSCFG_SIPCR_SPKA_Pos)                /*!< 0x00000004 */
#define SYSCFG_SIPCR_SPKA                       SYSCFG_SIPCR_SPKA_Msk                           /*!< Enabling the security access of Public Key Accelerator                  */
#define SYSCFG_SIPCR_SRNG_Pos                   (3U)
#define SYSCFG_SIPCR_SRNG_Msk                   (0x1UL << SYSCFG_SIPCR_SRNG_Pos)                /*!< 0x00000008 */
#define SYSCFG_SIPCR_SRNG                       SYSCFG_SIPCR_SRNG_Msk                           /*!< Enabling the security access of Random Number Generator                 */

/******************************************************************************/
/*                                                                            */
/*                                    TIM                                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TIM_CR1 register  ********************/
#define TIM_CR1_CEN_Pos           (0U)
#define TIM_CR1_CEN_Msk           (0x1UL << TIM_CR1_CEN_Pos)                   /*!< 0x00000001 */
#define TIM_CR1_CEN               TIM_CR1_CEN_Msk                              /*!<Counter enable */
#define TIM_CR1_UDIS_Pos          (1U)
#define TIM_CR1_UDIS_Msk          (0x1UL << TIM_CR1_UDIS_Pos)                  /*!< 0x00000002 */
#define TIM_CR1_UDIS              TIM_CR1_UDIS_Msk                             /*!<Update disable */
#define TIM_CR1_URS_Pos           (2U)
#define TIM_CR1_URS_Msk           (0x1UL << TIM_CR1_URS_Pos)                   /*!< 0x00000004 */
#define TIM_CR1_URS               TIM_CR1_URS_Msk                              /*!<Update request source */
#define TIM_CR1_OPM_Pos           (3U)
#define TIM_CR1_OPM_Msk           (0x1UL << TIM_CR1_OPM_Pos)                   /*!< 0x00000008 */
#define TIM_CR1_OPM               TIM_CR1_OPM_Msk                              /*!<One pulse mode */
#define TIM_CR1_DIR_Pos           (4U)
#define TIM_CR1_DIR_Msk           (0x1UL << TIM_CR1_DIR_Pos)                   /*!< 0x00000010 */
#define TIM_CR1_DIR               TIM_CR1_DIR_Msk                              /*!<Direction */

#define TIM_CR1_CMS_Pos           (5U)
#define TIM_CR1_CMS_Msk           (0x3UL << TIM_CR1_CMS_Pos)                   /*!< 0x00000060 */
#define TIM_CR1_CMS               TIM_CR1_CMS_Msk                              /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CR1_CMS_0             (0x1U << TIM_CR1_CMS_Pos)                    /*!< 0x00000020 */
#define TIM_CR1_CMS_1             (0x2U << TIM_CR1_CMS_Pos)                    /*!< 0x00000040 */

#define TIM_CR1_ARPE_Pos          (7U)
#define TIM_CR1_ARPE_Msk          (0x1UL << TIM_CR1_ARPE_Pos)                  /*!< 0x00000080 */
#define TIM_CR1_ARPE              TIM_CR1_ARPE_Msk                             /*!<Auto-reload preload enable */

#define TIM_CR1_CKD_Pos           (8U)
#define TIM_CR1_CKD_Msk           (0x3UL << TIM_CR1_CKD_Pos)                   /*!< 0x00000300 */
#define TIM_CR1_CKD               TIM_CR1_CKD_Msk                              /*!<CKD[1:0] bits (clock division) */
#define TIM_CR1_CKD_0             (0x1U << TIM_CR1_CKD_Pos)                    /*!< 0x00000100 */
#define TIM_CR1_CKD_1             (0x2U << TIM_CR1_CKD_Pos)                    /*!< 0x00000200 */

#define TIM_CR1_UIFREMAP_Pos      (11U)
#define TIM_CR1_UIFREMAP_Msk      (0x1UL << TIM_CR1_UIFREMAP_Pos)              /*!< 0x00000800 */
#define TIM_CR1_UIFREMAP          TIM_CR1_UIFREMAP_Msk                         /*!<Update interrupt flag remap */

/*******************  Bit definition for TIM_CR2 register  ********************/
#define TIM_CR2_CCPC_Pos          (0U)
#define TIM_CR2_CCPC_Msk          (0x1UL << TIM_CR2_CCPC_Pos)                  /*!< 0x00000001 */
#define TIM_CR2_CCPC              TIM_CR2_CCPC_Msk                             /*!<Capture/Compare Preloaded Control */
#define TIM_CR2_CCUS_Pos          (2U)
#define TIM_CR2_CCUS_Msk          (0x1UL << TIM_CR2_CCUS_Pos)                  /*!< 0x00000004 */
#define TIM_CR2_CCUS              TIM_CR2_CCUS_Msk                             /*!<Capture/Compare Control Update Selection */
#define TIM_CR2_CCDS_Pos          (3U)
#define TIM_CR2_CCDS_Msk          (0x1UL << TIM_CR2_CCDS_Pos)                  /*!< 0x00000008 */
#define TIM_CR2_CCDS              TIM_CR2_CCDS_Msk                             /*!<Capture/Compare DMA Selection */

#define TIM_CR2_MMS_Pos           (4U)
#define TIM_CR2_MMS_Msk           (0x7UL << TIM_CR2_MMS_Pos)                   /*!< 0x00000070 */
#define TIM_CR2_MMS               TIM_CR2_MMS_Msk                              /*!<MMS[2:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS_0             (0x1U << TIM_CR2_MMS_Pos)                    /*!< 0x00000010 */
#define TIM_CR2_MMS_1             (0x2U << TIM_CR2_MMS_Pos)                    /*!< 0x00000020 */
#define TIM_CR2_MMS_2             (0x4U << TIM_CR2_MMS_Pos)                    /*!< 0x00000040 */

#define TIM_CR2_TI1S_Pos          (7U)
#define TIM_CR2_TI1S_Msk          (0x1UL << TIM_CR2_TI1S_Pos)                  /*!< 0x00000080 */
#define TIM_CR2_TI1S              TIM_CR2_TI1S_Msk                             /*!<TI1 Selection */
#define TIM_CR2_OIS1_Pos          (8U)
#define TIM_CR2_OIS1_Msk          (0x1UL << TIM_CR2_OIS1_Pos)                  /*!< 0x00000100 */
#define TIM_CR2_OIS1              TIM_CR2_OIS1_Msk                             /*!<Output Idle state 1 (OC1 output) */
#define TIM_CR2_OIS1N_Pos         (9U)
#define TIM_CR2_OIS1N_Msk         (0x1UL << TIM_CR2_OIS1N_Pos)                 /*!< 0x00000200 */
#define TIM_CR2_OIS1N             TIM_CR2_OIS1N_Msk                            /*!<Output Idle state 1 (OC1N output) */
#define TIM_CR2_OIS2_Pos          (10U)
#define TIM_CR2_OIS2_Msk          (0x1UL << TIM_CR2_OIS2_Pos)                  /*!< 0x00000400 */
#define TIM_CR2_OIS2              TIM_CR2_OIS2_Msk                             /*!<Output Idle state 2 (OC2 output) */
#define TIM_CR2_OIS2N_Pos         (11U)
#define TIM_CR2_OIS2N_Msk         (0x1UL << TIM_CR2_OIS2N_Pos)                 /*!< 0x00000800 */
#define TIM_CR2_OIS2N             TIM_CR2_OIS2N_Msk                            /*!<Output Idle state 2 (OC2N output) */
#define TIM_CR2_OIS3_Pos          (12U)
#define TIM_CR2_OIS3_Msk          (0x1UL << TIM_CR2_OIS3_Pos)                  /*!< 0x00001000 */
#define TIM_CR2_OIS3              TIM_CR2_OIS3_Msk                             /*!<Output Idle state 3 (OC3 output) */
#define TIM_CR2_OIS3N_Pos         (13U)
#define TIM_CR2_OIS3N_Msk         (0x1UL << TIM_CR2_OIS3N_Pos)                 /*!< 0x00002000 */
#define TIM_CR2_OIS3N             TIM_CR2_OIS3N_Msk                            /*!<Output Idle state 3 (OC3N output) */
#define TIM_CR2_OIS4_Pos          (14U)
#define TIM_CR2_OIS4_Msk          (0x1UL << TIM_CR2_OIS4_Pos)                  /*!< 0x00004000 */
#define TIM_CR2_OIS4              TIM_CR2_OIS4_Msk                             /*!<Output Idle state 4 (OC4 output) */
#define TIM_CR2_OIS5_Pos          (16U)
#define TIM_CR2_OIS5_Msk          (0x1UL << TIM_CR2_OIS5_Pos)                  /*!< 0x00010000 */
#define TIM_CR2_OIS5              TIM_CR2_OIS5_Msk                             /*!<Output Idle state 5 (OC5 output) */
#define TIM_CR2_OIS6_Pos          (18U)
#define TIM_CR2_OIS6_Msk          (0x1UL << TIM_CR2_OIS6_Pos)                  /*!< 0x00040000 */
#define TIM_CR2_OIS6              TIM_CR2_OIS6_Msk                             /*!<Output Idle state 6 (OC6 output) */

#define TIM_CR2_MMS2_Pos          (20U)
#define TIM_CR2_MMS2_Msk          (0xFUL << TIM_CR2_MMS2_Pos)                  /*!< 0x00F00000 */
#define TIM_CR2_MMS2              TIM_CR2_MMS2_Msk                             /*!<MMS[2:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS2_0            (0x1U << TIM_CR2_MMS2_Pos)                   /*!< 0x00100000 */
#define TIM_CR2_MMS2_1            (0x2U << TIM_CR2_MMS2_Pos)                   /*!< 0x00200000 */
#define TIM_CR2_MMS2_2            (0x4U << TIM_CR2_MMS2_Pos)                   /*!< 0x00400000 */
#define TIM_CR2_MMS2_3            (0x8U << TIM_CR2_MMS2_Pos)                   /*!< 0x00800000 */

/*******************  Bit definition for TIM_SMCR register  *******************/
#define TIM_SMCR_SMS_Pos          (0U)
#define TIM_SMCR_SMS_Msk          (0x10007UL << TIM_SMCR_SMS_Pos)              /*!< 0x00010007 */
#define TIM_SMCR_SMS              TIM_SMCR_SMS_Msk                             /*!<SMS[2:0] bits (Slave mode selection) */
#define TIM_SMCR_SMS_0            (0x00001U << TIM_SMCR_SMS_Pos)               /*!< 0x00000001 */
#define TIM_SMCR_SMS_1            (0x00002U << TIM_SMCR_SMS_Pos)               /*!< 0x00000002 */
#define TIM_SMCR_SMS_2            (0x00004U << TIM_SMCR_SMS_Pos)               /*!< 0x00000004 */
#define TIM_SMCR_SMS_3            (0x10000U << TIM_SMCR_SMS_Pos)               /*!< 0x00010000 */

#define TIM_SMCR_OCCS_Pos         (3U)
#define TIM_SMCR_OCCS_Msk         (0x1UL << TIM_SMCR_OCCS_Pos)                 /*!< 0x00000008 */
#define TIM_SMCR_OCCS             TIM_SMCR_OCCS_Msk                            /*!< OCREF clear selection */

#define TIM_SMCR_TS_Pos           (4U)
#define TIM_SMCR_TS_Msk           (0x30007UL << TIM_SMCR_TS_Pos)               /*!< 0x00300070 */
#define TIM_SMCR_TS               TIM_SMCR_TS_Msk                              /*!<TS[2:0] bits (Trigger selection) */
#define TIM_SMCR_TS_0             (0x00001U << TIM_SMCR_TS_Pos)                /*!< 0x00000010 */
#define TIM_SMCR_TS_1             (0x00002U << TIM_SMCR_TS_Pos)                /*!< 0x00000020 */
#define TIM_SMCR_TS_2             (0x00004U << TIM_SMCR_TS_Pos)                /*!< 0x00000040 */
#define TIM_SMCR_TS_3             (0x10000U << TIM_SMCR_TS_Pos)                /*!< 0x00100000 */
#define TIM_SMCR_TS_4             (0x20000U << TIM_SMCR_TS_Pos)                /*!< 0x00200000 */

#define TIM_SMCR_MSM_Pos          (7U)
#define TIM_SMCR_MSM_Msk          (0x1UL << TIM_SMCR_MSM_Pos)                  /*!< 0x00000080 */
#define TIM_SMCR_MSM              TIM_SMCR_MSM_Msk                             /*!<Master/slave mode */

#define TIM_SMCR_ETF_Pos          (8U)
#define TIM_SMCR_ETF_Msk          (0xFUL << TIM_SMCR_ETF_Pos)                  /*!< 0x00000F00 */
#define TIM_SMCR_ETF              TIM_SMCR_ETF_Msk                             /*!<ETF[3:0] bits (External trigger filter) */
#define TIM_SMCR_ETF_0            (0x1U << TIM_SMCR_ETF_Pos)                   /*!< 0x00000100 */
#define TIM_SMCR_ETF_1            (0x2U << TIM_SMCR_ETF_Pos)                   /*!< 0x00000200 */
#define TIM_SMCR_ETF_2            (0x4U << TIM_SMCR_ETF_Pos)                   /*!< 0x00000400 */
#define TIM_SMCR_ETF_3            (0x8U << TIM_SMCR_ETF_Pos)                   /*!< 0x00000800 */

#define TIM_SMCR_ETPS_Pos         (12U)
#define TIM_SMCR_ETPS_Msk         (0x3UL << TIM_SMCR_ETPS_Pos)                 /*!< 0x00003000 */
#define TIM_SMCR_ETPS             TIM_SMCR_ETPS_Msk                            /*!<ETPS[1:0] bits (External trigger prescaler) */
#define TIM_SMCR_ETPS_0           (0x1U << TIM_SMCR_ETPS_Pos)                  /*!< 0x00001000 */
#define TIM_SMCR_ETPS_1           (0x2U << TIM_SMCR_ETPS_Pos)                  /*!< 0x00002000 */

#define TIM_SMCR_ECE_Pos          (14U)
#define TIM_SMCR_ECE_Msk          (0x1UL << TIM_SMCR_ECE_Pos)                  /*!< 0x00004000 */
#define TIM_SMCR_ECE              TIM_SMCR_ECE_Msk                             /*!<External clock enable */
#define TIM_SMCR_ETP_Pos          (15U)
#define TIM_SMCR_ETP_Msk          (0x1UL << TIM_SMCR_ETP_Pos)                  /*!< 0x00008000 */
#define TIM_SMCR_ETP              TIM_SMCR_ETP_Msk                             /*!<External trigger polarity */

/*******************  Bit definition for TIM_DIER register  *******************/
#define TIM_DIER_UIE_Pos          (0U)
#define TIM_DIER_UIE_Msk          (0x1UL << TIM_DIER_UIE_Pos)                  /*!< 0x00000001 */
#define TIM_DIER_UIE              TIM_DIER_UIE_Msk                             /*!<Update interrupt enable */
#define TIM_DIER_CC1IE_Pos        (1U)
#define TIM_DIER_CC1IE_Msk        (0x1UL << TIM_DIER_CC1IE_Pos)                /*!< 0x00000002 */
#define TIM_DIER_CC1IE            TIM_DIER_CC1IE_Msk                           /*!<Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE_Pos        (2U)
#define TIM_DIER_CC2IE_Msk        (0x1UL << TIM_DIER_CC2IE_Pos)                /*!< 0x00000004 */
#define TIM_DIER_CC2IE            TIM_DIER_CC2IE_Msk                           /*!<Capture/Compare 2 interrupt enable */
#define TIM_DIER_CC3IE_Pos        (3U)
#define TIM_DIER_CC3IE_Msk        (0x1UL << TIM_DIER_CC3IE_Pos)                /*!< 0x00000008 */
#define TIM_DIER_CC3IE            TIM_DIER_CC3IE_Msk                           /*!<Capture/Compare 3 interrupt enable */
#define TIM_DIER_CC4IE_Pos        (4U)
#define TIM_DIER_CC4IE_Msk        (0x1UL << TIM_DIER_CC4IE_Pos)                /*!< 0x00000010 */
#define TIM_DIER_CC4IE            TIM_DIER_CC4IE_Msk                           /*!<Capture/Compare 4 interrupt enable */
#define TIM_DIER_COMIE_Pos        (5U)
#define TIM_DIER_COMIE_Msk        (0x1UL << TIM_DIER_COMIE_Pos)                /*!< 0x00000020 */
#define TIM_DIER_COMIE            TIM_DIER_COMIE_Msk                           /*!<COM interrupt enable */
#define TIM_DIER_TIE_Pos          (6U)
#define TIM_DIER_TIE_Msk          (0x1UL << TIM_DIER_TIE_Pos)                  /*!< 0x00000040 */
#define TIM_DIER_TIE              TIM_DIER_TIE_Msk                             /*!<Trigger interrupt enable */
#define TIM_DIER_BIE_Pos          (7U)
#define TIM_DIER_BIE_Msk          (0x1UL << TIM_DIER_BIE_Pos)                  /*!< 0x00000080 */
#define TIM_DIER_BIE              TIM_DIER_BIE_Msk                             /*!<Break interrupt enable */
#define TIM_DIER_UDE_Pos          (8U)
#define TIM_DIER_UDE_Msk          (0x1UL << TIM_DIER_UDE_Pos)                  /*!< 0x00000100 */
#define TIM_DIER_UDE              TIM_DIER_UDE_Msk                             /*!<Update DMA request enable */
#define TIM_DIER_CC1DE_Pos        (9U)
#define TIM_DIER_CC1DE_Msk        (0x1UL << TIM_DIER_CC1DE_Pos)                /*!< 0x00000200 */
#define TIM_DIER_CC1DE            TIM_DIER_CC1DE_Msk                           /*!<Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC2DE_Pos        (10U)
#define TIM_DIER_CC2DE_Msk        (0x1UL << TIM_DIER_CC2DE_Pos)                /*!< 0x00000400 */
#define TIM_DIER_CC2DE            TIM_DIER_CC2DE_Msk                           /*!<Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC3DE_Pos        (11U)
#define TIM_DIER_CC3DE_Msk        (0x1UL << TIM_DIER_CC3DE_Pos)                /*!< 0x00000800 */
#define TIM_DIER_CC3DE            TIM_DIER_CC3DE_Msk                           /*!<Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC4DE_Pos        (12U)
#define TIM_DIER_CC4DE_Msk        (0x1UL << TIM_DIER_CC4DE_Pos)                /*!< 0x00001000 */
#define TIM_DIER_CC4DE            TIM_DIER_CC4DE_Msk                           /*!<Capture/Compare 4 DMA request enable */
#define TIM_DIER_COMDE_Pos        (13U)
#define TIM_DIER_COMDE_Msk        (0x1UL << TIM_DIER_COMDE_Pos)                /*!< 0x00002000 */
#define TIM_DIER_COMDE            TIM_DIER_COMDE_Msk                           /*!<COM DMA request enable */
#define TIM_DIER_TDE_Pos          (14U)
#define TIM_DIER_TDE_Msk          (0x1UL << TIM_DIER_TDE_Pos)                  /*!< 0x00004000 */
#define TIM_DIER_TDE              TIM_DIER_TDE_Msk                             /*!<Trigger DMA request enable */

/********************  Bit definition for TIM_SR register  ********************/
#define TIM_SR_UIF_Pos            (0U)
#define TIM_SR_UIF_Msk            (0x1UL << TIM_SR_UIF_Pos)                    /*!< 0x00000001 */
#define TIM_SR_UIF                TIM_SR_UIF_Msk                               /*!<Update interrupt Flag */
#define TIM_SR_CC1IF_Pos          (1U)
#define TIM_SR_CC1IF_Msk          (0x1UL << TIM_SR_CC1IF_Pos)                  /*!< 0x00000002 */
#define TIM_SR_CC1IF              TIM_SR_CC1IF_Msk                             /*!<Capture/Compare 1 interrupt Flag */
#define TIM_SR_CC2IF_Pos          (2U)
#define TIM_SR_CC2IF_Msk          (0x1UL << TIM_SR_CC2IF_Pos)                  /*!< 0x00000004 */
#define TIM_SR_CC2IF              TIM_SR_CC2IF_Msk                             /*!<Capture/Compare 2 interrupt Flag */
#define TIM_SR_CC3IF_Pos          (3U)
#define TIM_SR_CC3IF_Msk          (0x1UL << TIM_SR_CC3IF_Pos)                  /*!< 0x00000008 */
#define TIM_SR_CC3IF              TIM_SR_CC3IF_Msk                             /*!<Capture/Compare 3 interrupt Flag */
#define TIM_SR_CC4IF_Pos          (4U)
#define TIM_SR_CC4IF_Msk          (0x1UL << TIM_SR_CC4IF_Pos)                  /*!< 0x00000010 */
#define TIM_SR_CC4IF              TIM_SR_CC4IF_Msk                             /*!<Capture/Compare 4 interrupt Flag */
#define TIM_SR_COMIF_Pos          (5U)
#define TIM_SR_COMIF_Msk          (0x1UL << TIM_SR_COMIF_Pos)                  /*!< 0x00000020 */
#define TIM_SR_COMIF              TIM_SR_COMIF_Msk                             /*!<COM interrupt Flag */
#define TIM_SR_TIF_Pos            (6U)
#define TIM_SR_TIF_Msk            (0x1UL << TIM_SR_TIF_Pos)                    /*!< 0x00000040 */
#define TIM_SR_TIF                TIM_SR_TIF_Msk                               /*!<Trigger interrupt Flag */
#define TIM_SR_BIF_Pos            (7U)
#define TIM_SR_BIF_Msk            (0x1UL << TIM_SR_BIF_Pos)                    /*!< 0x00000080 */
#define TIM_SR_BIF                TIM_SR_BIF_Msk                               /*!<Break interrupt Flag */
#define TIM_SR_B2IF_Pos           (8U)
#define TIM_SR_B2IF_Msk           (0x1UL << TIM_SR_B2IF_Pos)                   /*!< 0x00000100 */
#define TIM_SR_B2IF               TIM_SR_B2IF_Msk                              /*!<Break 2 interrupt Flag */
#define TIM_SR_CC1OF_Pos          (9U)
#define TIM_SR_CC1OF_Msk          (0x1UL << TIM_SR_CC1OF_Pos)                  /*!< 0x00000200 */
#define TIM_SR_CC1OF              TIM_SR_CC1OF_Msk                             /*!<Capture/Compare 1 Overcapture Flag */
#define TIM_SR_CC2OF_Pos          (10U)
#define TIM_SR_CC2OF_Msk          (0x1UL << TIM_SR_CC2OF_Pos)                  /*!< 0x00000400 */
#define TIM_SR_CC2OF              TIM_SR_CC2OF_Msk                             /*!<Capture/Compare 2 Overcapture Flag */
#define TIM_SR_CC3OF_Pos          (11U)
#define TIM_SR_CC3OF_Msk          (0x1UL << TIM_SR_CC3OF_Pos)                  /*!< 0x00000800 */
#define TIM_SR_CC3OF              TIM_SR_CC3OF_Msk                             /*!<Capture/Compare 3 Overcapture Flag */
#define TIM_SR_CC4OF_Pos          (12U)
#define TIM_SR_CC4OF_Msk          (0x1UL << TIM_SR_CC4OF_Pos)                  /*!< 0x00001000 */
#define TIM_SR_CC4OF              TIM_SR_CC4OF_Msk                             /*!<Capture/Compare 4 Overcapture Flag */
#define TIM_SR_SBIF_Pos           (13U)
#define TIM_SR_SBIF_Msk           (0x1UL << TIM_SR_SBIF_Pos)                   /*!< 0x00002000 */
#define TIM_SR_SBIF               TIM_SR_SBIF_Msk                              /*!<System Break interrupt Flag */
#define TIM_SR_CC5IF_Pos          (16U)
#define TIM_SR_CC5IF_Msk          (0x1UL << TIM_SR_CC5IF_Pos)                  /*!< 0x00010000 */
#define TIM_SR_CC5IF              TIM_SR_CC5IF_Msk                             /*!<Capture/Compare 5 interrupt Flag */
#define TIM_SR_CC6IF_Pos          (17U)
#define TIM_SR_CC6IF_Msk          (0x1UL << TIM_SR_CC6IF_Pos)                  /*!< 0x00020000 */
#define TIM_SR_CC6IF              TIM_SR_CC6IF_Msk                             /*!<Capture/Compare 6 interrupt Flag */


/*******************  Bit definition for TIM_EGR register  ********************/
#define TIM_EGR_UG_Pos            (0U)
#define TIM_EGR_UG_Msk            (0x1UL << TIM_EGR_UG_Pos)                    /*!< 0x00000001 */
#define TIM_EGR_UG                TIM_EGR_UG_Msk                               /*!<Update Generation */
#define TIM_EGR_CC1G_Pos          (1U)
#define TIM_EGR_CC1G_Msk          (0x1UL << TIM_EGR_CC1G_Pos)                  /*!< 0x00000002 */
#define TIM_EGR_CC1G              TIM_EGR_CC1G_Msk                             /*!<Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos          (2U)
#define TIM_EGR_CC2G_Msk          (0x1UL << TIM_EGR_CC2G_Pos)                  /*!< 0x00000004 */
#define TIM_EGR_CC2G              TIM_EGR_CC2G_Msk                             /*!<Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos          (3U)
#define TIM_EGR_CC3G_Msk          (0x1UL << TIM_EGR_CC3G_Pos)                  /*!< 0x00000008 */
#define TIM_EGR_CC3G              TIM_EGR_CC3G_Msk                             /*!<Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos          (4U)
#define TIM_EGR_CC4G_Msk          (0x1UL << TIM_EGR_CC4G_Pos)                  /*!< 0x00000010 */
#define TIM_EGR_CC4G              TIM_EGR_CC4G_Msk                             /*!<Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos          (5U)
#define TIM_EGR_COMG_Msk          (0x1UL << TIM_EGR_COMG_Pos)                  /*!< 0x00000020 */
#define TIM_EGR_COMG              TIM_EGR_COMG_Msk                             /*!<Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos            (6U)
#define TIM_EGR_TG_Msk            (0x1UL << TIM_EGR_TG_Pos)                    /*!< 0x00000040 */
#define TIM_EGR_TG                TIM_EGR_TG_Msk                               /*!<Trigger Generation */
#define TIM_EGR_BG_Pos            (7U)
#define TIM_EGR_BG_Msk            (0x1UL << TIM_EGR_BG_Pos)                    /*!< 0x00000080 */
#define TIM_EGR_BG                TIM_EGR_BG_Msk                               /*!<Break Generation */
#define TIM_EGR_B2G_Pos           (8U)
#define TIM_EGR_B2G_Msk           (0x1UL << TIM_EGR_B2G_Pos)                   /*!< 0x00000100 */
#define TIM_EGR_B2G               TIM_EGR_B2G_Msk                              /*!<Break 2 Generation */


/******************  Bit definition for TIM_CCMR1 register  *******************/
#define TIM_CCMR1_CC1S_Pos        (0U)
#define TIM_CCMR1_CC1S_Msk        (0x3UL << TIM_CCMR1_CC1S_Pos)                /*!< 0x00000003 */
#define TIM_CCMR1_CC1S            TIM_CCMR1_CC1S_Msk                           /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_CC1S_0          (0x1U << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000001 */
#define TIM_CCMR1_CC1S_1          (0x2U << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000002 */

#define TIM_CCMR1_OC1FE_Pos       (2U)
#define TIM_CCMR1_OC1FE_Msk       (0x1UL << TIM_CCMR1_OC1FE_Pos)               /*!< 0x00000004 */
#define TIM_CCMR1_OC1FE           TIM_CCMR1_OC1FE_Msk                          /*!<Output Compare 1 Fast enable */
#define TIM_CCMR1_OC1PE_Pos       (3U)
#define TIM_CCMR1_OC1PE_Msk       (0x1UL << TIM_CCMR1_OC1PE_Pos)               /*!< 0x00000008 */
#define TIM_CCMR1_OC1PE           TIM_CCMR1_OC1PE_Msk                          /*!<Output Compare 1 Preload enable */

#define TIM_CCMR1_OC1M_Pos        (4U)
#define TIM_CCMR1_OC1M_Msk        (0x1007UL << TIM_CCMR1_OC1M_Pos)             /*!< 0x00010070 */
#define TIM_CCMR1_OC1M            TIM_CCMR1_OC1M_Msk                           /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define TIM_CCMR1_OC1M_0          (0x0001U << TIM_CCMR1_OC1M_Pos)              /*!< 0x00000010 */
#define TIM_CCMR1_OC1M_1          (0x0002U << TIM_CCMR1_OC1M_Pos)              /*!< 0x00000020 */
#define TIM_CCMR1_OC1M_2          (0x0004U << TIM_CCMR1_OC1M_Pos)              /*!< 0x00000040 */
#define TIM_CCMR1_OC1M_3          (0x1000U << TIM_CCMR1_OC1M_Pos)              /*!< 0x00010000 */

#define TIM_CCMR1_OC1CE_Pos       (7U)
#define TIM_CCMR1_OC1CE_Msk       (0x1UL << TIM_CCMR1_OC1CE_Pos)               /*!< 0x00000080 */
#define TIM_CCMR1_OC1CE           TIM_CCMR1_OC1CE_Msk                          /*!<Output Compare 1 Clear Enable */

#define TIM_CCMR1_CC2S_Pos        (8U)
#define TIM_CCMR1_CC2S_Msk        (0x3UL << TIM_CCMR1_CC2S_Pos)                /*!< 0x00000300 */
#define TIM_CCMR1_CC2S            TIM_CCMR1_CC2S_Msk                           /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_CC2S_0          (0x1U << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000100 */
#define TIM_CCMR1_CC2S_1          (0x2U << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000200 */

#define TIM_CCMR1_OC2FE_Pos       (10U)
#define TIM_CCMR1_OC2FE_Msk       (0x1UL << TIM_CCMR1_OC2FE_Pos)               /*!< 0x00000400 */
#define TIM_CCMR1_OC2FE           TIM_CCMR1_OC2FE_Msk                          /*!<Output Compare 2 Fast enable */
#define TIM_CCMR1_OC2PE_Pos       (11U)
#define TIM_CCMR1_OC2PE_Msk       (0x1UL << TIM_CCMR1_OC2PE_Pos)               /*!< 0x00000800 */
#define TIM_CCMR1_OC2PE           TIM_CCMR1_OC2PE_Msk                          /*!<Output Compare 2 Preload enable */

#define TIM_CCMR1_OC2M_Pos        (12U)
#define TIM_CCMR1_OC2M_Msk        (0x1007UL << TIM_CCMR1_OC2M_Pos)             /*!< 0x01007000 */
#define TIM_CCMR1_OC2M            TIM_CCMR1_OC2M_Msk                           /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define TIM_CCMR1_OC2M_0          (0x0001U << TIM_CCMR1_OC2M_Pos)              /*!< 0x00001000 */
#define TIM_CCMR1_OC2M_1          (0x0002U << TIM_CCMR1_OC2M_Pos)              /*!< 0x00002000 */
#define TIM_CCMR1_OC2M_2          (0x0004U << TIM_CCMR1_OC2M_Pos)              /*!< 0x00004000 */
#define TIM_CCMR1_OC2M_3          (0x1000U << TIM_CCMR1_OC2M_Pos)              /*!< 0x01000000 */

#define TIM_CCMR1_OC2CE_Pos       (15U)
#define TIM_CCMR1_OC2CE_Msk       (0x1UL << TIM_CCMR1_OC2CE_Pos)               /*!< 0x00008000 */
#define TIM_CCMR1_OC2CE           TIM_CCMR1_OC2CE_Msk                          /*!<Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/
#define TIM_CCMR1_IC1PSC_Pos      (2U)
#define TIM_CCMR1_IC1PSC_Msk      (0x3UL << TIM_CCMR1_IC1PSC_Pos)              /*!< 0x0000000C */
#define TIM_CCMR1_IC1PSC          TIM_CCMR1_IC1PSC_Msk                         /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMR1_IC1PSC_0        (0x1U << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x00000004 */
#define TIM_CCMR1_IC1PSC_1        (0x2U << TIM_CCMR1_IC1PSC_Pos)               /*!< 0x00000008 */

#define TIM_CCMR1_IC1F_Pos        (4U)
#define TIM_CCMR1_IC1F_Msk        (0xFUL << TIM_CCMR1_IC1F_Pos)                /*!< 0x000000F0 */
#define TIM_CCMR1_IC1F            TIM_CCMR1_IC1F_Msk                           /*!<IC1F[3:0] bits (Input Capture 1 Filter) */
#define TIM_CCMR1_IC1F_0          (0x1U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR1_IC1F_1          (0x2U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR1_IC1F_2          (0x4U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR1_IC1F_3          (0x8U << TIM_CCMR1_IC1F_Pos)                 /*!< 0x00000080 */

#define TIM_CCMR1_IC2PSC_Pos      (10U)
#define TIM_CCMR1_IC2PSC_Msk      (0x3UL << TIM_CCMR1_IC2PSC_Pos)              /*!< 0x00000C00 */
#define TIM_CCMR1_IC2PSC          TIM_CCMR1_IC2PSC_Msk                         /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TIM_CCMR1_IC2PSC_0        (0x1U << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000400 */
#define TIM_CCMR1_IC2PSC_1        (0x2U << TIM_CCMR1_IC2PSC_Pos)               /*!< 0x00000800 */

#define TIM_CCMR1_IC2F_Pos        (12U)
#define TIM_CCMR1_IC2F_Msk        (0xFUL << TIM_CCMR1_IC2F_Pos)                /*!< 0x0000F000 */
#define TIM_CCMR1_IC2F            TIM_CCMR1_IC2F_Msk                           /*!<IC2F[3:0] bits (Input Capture 2 Filter) */
#define TIM_CCMR1_IC2F_0          (0x1U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR1_IC2F_1          (0x2U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR1_IC2F_2          (0x4U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR1_IC2F_3          (0x8U << TIM_CCMR1_IC2F_Pos)                 /*!< 0x00008000 */

/******************  Bit definition for TIM_CCMR2 register  *******************/
#define TIM_CCMR2_CC3S_Pos        (0U)
#define TIM_CCMR2_CC3S_Msk        (0x3UL << TIM_CCMR2_CC3S_Pos)                /*!< 0x00000003 */
#define TIM_CCMR2_CC3S            TIM_CCMR2_CC3S_Msk                           /*!<CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TIM_CCMR2_CC3S_0          (0x1U << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000001 */
#define TIM_CCMR2_CC3S_1          (0x2U << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000002 */

#define TIM_CCMR2_OC3FE_Pos       (2U)
#define TIM_CCMR2_OC3FE_Msk       (0x1UL << TIM_CCMR2_OC3FE_Pos)               /*!< 0x00000004 */
#define TIM_CCMR2_OC3FE           TIM_CCMR2_OC3FE_Msk                          /*!<Output Compare 3 Fast enable */
#define TIM_CCMR2_OC3PE_Pos       (3U)
#define TIM_CCMR2_OC3PE_Msk       (0x1UL << TIM_CCMR2_OC3PE_Pos)               /*!< 0x00000008 */
#define TIM_CCMR2_OC3PE           TIM_CCMR2_OC3PE_Msk                          /*!<Output Compare 3 Preload enable */

#define TIM_CCMR2_OC3M_Pos        (4U)
#define TIM_CCMR2_OC3M_Msk        (0x1007UL << TIM_CCMR2_OC3M_Pos)             /*!< 0x00010070 */
#define TIM_CCMR2_OC3M            TIM_CCMR2_OC3M_Msk                           /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define TIM_CCMR2_OC3M_0          (0x0001U << TIM_CCMR2_OC3M_Pos)              /*!< 0x00000010 */
#define TIM_CCMR2_OC3M_1          (0x0002U << TIM_CCMR2_OC3M_Pos)              /*!< 0x00000020 */
#define TIM_CCMR2_OC3M_2          (0x0004U << TIM_CCMR2_OC3M_Pos)              /*!< 0x00000040 */
#define TIM_CCMR2_OC3M_3          (0x1000U << TIM_CCMR2_OC3M_Pos)              /*!< 0x00010000 */

#define TIM_CCMR2_OC3CE_Pos       (7U)
#define TIM_CCMR2_OC3CE_Msk       (0x1UL << TIM_CCMR2_OC3CE_Pos)               /*!< 0x00000080 */
#define TIM_CCMR2_OC3CE           TIM_CCMR2_OC3CE_Msk                          /*!<Output Compare 3 Clear Enable */

#define TIM_CCMR2_CC4S_Pos        (8U)
#define TIM_CCMR2_CC4S_Msk        (0x3UL << TIM_CCMR2_CC4S_Pos)                /*!< 0x00000300 */
#define TIM_CCMR2_CC4S            TIM_CCMR2_CC4S_Msk                           /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMR2_CC4S_0          (0x1U << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000100 */
#define TIM_CCMR2_CC4S_1          (0x2U << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000200 */

#define TIM_CCMR2_OC4FE_Pos       (10U)
#define TIM_CCMR2_OC4FE_Msk       (0x1UL << TIM_CCMR2_OC4FE_Pos)               /*!< 0x00000400 */
#define TIM_CCMR2_OC4FE           TIM_CCMR2_OC4FE_Msk                          /*!<Output Compare 4 Fast enable */
#define TIM_CCMR2_OC4PE_Pos       (11U)
#define TIM_CCMR2_OC4PE_Msk       (0x1UL << TIM_CCMR2_OC4PE_Pos)               /*!< 0x00000800 */
#define TIM_CCMR2_OC4PE           TIM_CCMR2_OC4PE_Msk                          /*!<Output Compare 4 Preload enable */

#define TIM_CCMR2_OC4M_Pos        (12U)
#define TIM_CCMR2_OC4M_Msk        (0x1007UL << TIM_CCMR2_OC4M_Pos)             /*!< 0x01007000 */
#define TIM_CCMR2_OC4M            TIM_CCMR2_OC4M_Msk                           /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR2_OC4M_0          (0x0001U << TIM_CCMR2_OC4M_Pos)              /*!< 0x00001000 */
#define TIM_CCMR2_OC4M_1          (0x0002U << TIM_CCMR2_OC4M_Pos)              /*!< 0x00002000 */
#define TIM_CCMR2_OC4M_2          (0x0004U << TIM_CCMR2_OC4M_Pos)              /*!< 0x00004000 */
#define TIM_CCMR2_OC4M_3          (0x1000U << TIM_CCMR2_OC4M_Pos)              /*!< 0x01000000 */

#define TIM_CCMR2_OC4CE_Pos       (15U)
#define TIM_CCMR2_OC4CE_Msk       (0x1UL << TIM_CCMR2_OC4CE_Pos)               /*!< 0x00008000 */
#define TIM_CCMR2_OC4CE           TIM_CCMR2_OC4CE_Msk                          /*!<Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/
#define TIM_CCMR2_IC3PSC_Pos      (2U)
#define TIM_CCMR2_IC3PSC_Msk      (0x3UL << TIM_CCMR2_IC3PSC_Pos)              /*!< 0x0000000C */
#define TIM_CCMR2_IC3PSC          TIM_CCMR2_IC3PSC_Msk                         /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3PSC_0        (0x1U << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x00000004 */
#define TIM_CCMR2_IC3PSC_1        (0x2U << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x00000008 */

#define TIM_CCMR2_IC3F_Pos        (4U)
#define TIM_CCMR2_IC3F_Msk        (0xFUL << TIM_CCMR2_IC3F_Pos)                /*!< 0x000000F0 */
#define TIM_CCMR2_IC3F            TIM_CCMR2_IC3F_Msk                           /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC3F_0          (0x1U << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR2_IC3F_1          (0x2U << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR2_IC3F_2          (0x4U << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR2_IC3F_3          (0x8U << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000080 */

#define TIM_CCMR2_IC4PSC_Pos      (10U)
#define TIM_CCMR2_IC4PSC_Msk      (0x3UL << TIM_CCMR2_IC4PSC_Pos)              /*!< 0x00000C00 */
#define TIM_CCMR2_IC4PSC          TIM_CCMR2_IC4PSC_Msk                         /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4PSC_0        (0x1U << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000400 */
#define TIM_CCMR2_IC4PSC_1        (0x2U << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000800 */

#define TIM_CCMR2_IC4F_Pos        (12U)
#define TIM_CCMR2_IC4F_Msk        (0xFUL << TIM_CCMR2_IC4F_Pos)                /*!< 0x0000F000 */
#define TIM_CCMR2_IC4F            TIM_CCMR2_IC4F_Msk                           /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMR2_IC4F_0          (0x1U << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR2_IC4F_1          (0x2U << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR2_IC4F_2          (0x4U << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR2_IC4F_3          (0x8U << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00008000 */

/******************  Bit definition for TIM_CCMR3 register  *******************/
#define TIM_CCMR3_OC5FE_Pos       (2U)
#define TIM_CCMR3_OC5FE_Msk       (0x1UL << TIM_CCMR3_OC5FE_Pos)               /*!< 0x00000004 */
#define TIM_CCMR3_OC5FE           TIM_CCMR3_OC5FE_Msk                          /*!<Output Compare 5 Fast enable */
#define TIM_CCMR3_OC5PE_Pos       (3U)
#define TIM_CCMR3_OC5PE_Msk       (0x1UL << TIM_CCMR3_OC5PE_Pos)               /*!< 0x00000008 */
#define TIM_CCMR3_OC5PE           TIM_CCMR3_OC5PE_Msk                          /*!<Output Compare 5 Preload enable */

#define TIM_CCMR3_OC5M_Pos        (4U)
#define TIM_CCMR3_OC5M_Msk        (0x1007UL << TIM_CCMR3_OC5M_Pos)             /*!< 0x00010070 */
#define TIM_CCMR3_OC5M            TIM_CCMR3_OC5M_Msk                           /*!<OC5M[3:0] bits (Output Compare 5 Mode) */
#define TIM_CCMR3_OC5M_0          (0x0001U << TIM_CCMR3_OC5M_Pos)              /*!< 0x00000010 */
#define TIM_CCMR3_OC5M_1          (0x0002U << TIM_CCMR3_OC5M_Pos)              /*!< 0x00000020 */
#define TIM_CCMR3_OC5M_2          (0x0004U << TIM_CCMR3_OC5M_Pos)              /*!< 0x00000040 */
#define TIM_CCMR3_OC5M_3          (0x1000U << TIM_CCMR3_OC5M_Pos)              /*!< 0x00010000 */

#define TIM_CCMR3_OC5CE_Pos       (7U)
#define TIM_CCMR3_OC5CE_Msk       (0x1UL << TIM_CCMR3_OC5CE_Pos)               /*!< 0x00000080 */
#define TIM_CCMR3_OC5CE           TIM_CCMR3_OC5CE_Msk                          /*!<Output Compare 5 Clear Enable */

#define TIM_CCMR3_OC6FE_Pos       (10U)
#define TIM_CCMR3_OC6FE_Msk       (0x1UL << TIM_CCMR3_OC6FE_Pos)               /*!< 0x00000400 */
#define TIM_CCMR3_OC6FE           TIM_CCMR3_OC6FE_Msk                          /*!<Output Compare 6 Fast enable */
#define TIM_CCMR3_OC6PE_Pos       (11U)
#define TIM_CCMR3_OC6PE_Msk       (0x1UL << TIM_CCMR3_OC6PE_Pos)               /*!< 0x00000800 */
#define TIM_CCMR3_OC6PE           TIM_CCMR3_OC6PE_Msk                          /*!<Output Compare 6 Preload enable */

#define TIM_CCMR3_OC6M_Pos        (12U)
#define TIM_CCMR3_OC6M_Msk        (0x1007UL << TIM_CCMR3_OC6M_Pos)             /*!< 0x01007000 */
#define TIM_CCMR3_OC6M            TIM_CCMR3_OC6M_Msk                           /*!<OC6M[3:0] bits (Output Compare 6 Mode) */
#define TIM_CCMR3_OC6M_0          (0x0001U << TIM_CCMR3_OC6M_Pos)              /*!< 0x00001000 */
#define TIM_CCMR3_OC6M_1          (0x0002U << TIM_CCMR3_OC6M_Pos)              /*!< 0x00002000 */
#define TIM_CCMR3_OC6M_2          (0x0004U << TIM_CCMR3_OC6M_Pos)              /*!< 0x00004000 */
#define TIM_CCMR3_OC6M_3          (0x1000U << TIM_CCMR3_OC6M_Pos)              /*!< 0x01000000 */

#define TIM_CCMR3_OC6CE_Pos       (15U)
#define TIM_CCMR3_OC6CE_Msk       (0x1UL << TIM_CCMR3_OC6CE_Pos)               /*!< 0x00008000 */
#define TIM_CCMR3_OC6CE           TIM_CCMR3_OC6CE_Msk                          /*!<Output Compare 6 Clear Enable */

/*******************  Bit definition for TIM_CCER register  *******************/
#define TIM_CCER_CC1E_Pos         (0U)
#define TIM_CCER_CC1E_Msk         (0x1UL << TIM_CCER_CC1E_Pos)                 /*!< 0x00000001 */
#define TIM_CCER_CC1E             TIM_CCER_CC1E_Msk                            /*!<Capture/Compare 1 output enable */
#define TIM_CCER_CC1P_Pos         (1U)
#define TIM_CCER_CC1P_Msk         (0x1UL << TIM_CCER_CC1P_Pos)                 /*!< 0x00000002 */
#define TIM_CCER_CC1P             TIM_CCER_CC1P_Msk                            /*!<Capture/Compare 1 output Polarity */
#define TIM_CCER_CC1NE_Pos        (2U)
#define TIM_CCER_CC1NE_Msk        (0x1UL << TIM_CCER_CC1NE_Pos)                /*!< 0x00000004 */
#define TIM_CCER_CC1NE            TIM_CCER_CC1NE_Msk                           /*!<Capture/Compare 1 Complementary output enable */
#define TIM_CCER_CC1NP_Pos        (3U)
#define TIM_CCER_CC1NP_Msk        (0x1UL << TIM_CCER_CC1NP_Pos)                /*!< 0x00000008 */
#define TIM_CCER_CC1NP            TIM_CCER_CC1NP_Msk                           /*!<Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos         (4U)
#define TIM_CCER_CC2E_Msk         (0x1UL << TIM_CCER_CC2E_Pos)                 /*!< 0x00000010 */
#define TIM_CCER_CC2E             TIM_CCER_CC2E_Msk                            /*!<Capture/Compare 2 output enable */
#define TIM_CCER_CC2P_Pos         (5U)
#define TIM_CCER_CC2P_Msk         (0x1UL << TIM_CCER_CC2P_Pos)                 /*!< 0x00000020 */
#define TIM_CCER_CC2P             TIM_CCER_CC2P_Msk                            /*!<Capture/Compare 2 output Polarity */
#define TIM_CCER_CC2NE_Pos        (6U)
#define TIM_CCER_CC2NE_Msk        (0x1UL << TIM_CCER_CC2NE_Pos)                /*!< 0x00000040 */
#define TIM_CCER_CC2NE            TIM_CCER_CC2NE_Msk                           /*!<Capture/Compare 2 Complementary output enable */
#define TIM_CCER_CC2NP_Pos        (7U)
#define TIM_CCER_CC2NP_Msk        (0x1UL << TIM_CCER_CC2NP_Pos)                /*!< 0x00000080 */
#define TIM_CCER_CC2NP            TIM_CCER_CC2NP_Msk                           /*!<Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos         (8U)
#define TIM_CCER_CC3E_Msk         (0x1UL << TIM_CCER_CC3E_Pos)                 /*!< 0x00000100 */
#define TIM_CCER_CC3E             TIM_CCER_CC3E_Msk                            /*!<Capture/Compare 3 output enable */
#define TIM_CCER_CC3P_Pos         (9U)
#define TIM_CCER_CC3P_Msk         (0x1UL << TIM_CCER_CC3P_Pos)                 /*!< 0x00000200 */
#define TIM_CCER_CC3P             TIM_CCER_CC3P_Msk                            /*!<Capture/Compare 3 output Polarity */
#define TIM_CCER_CC3NE_Pos        (10U)
#define TIM_CCER_CC3NE_Msk        (0x1UL << TIM_CCER_CC3NE_Pos)                /*!< 0x00000400 */
#define TIM_CCER_CC3NE            TIM_CCER_CC3NE_Msk                           /*!<Capture/Compare 3 Complementary output enable */
#define TIM_CCER_CC3NP_Pos        (11U)
#define TIM_CCER_CC3NP_Msk        (0x1UL << TIM_CCER_CC3NP_Pos)                /*!< 0x00000800 */
#define TIM_CCER_CC3NP            TIM_CCER_CC3NP_Msk                           /*!<Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos         (12U)
#define TIM_CCER_CC4E_Msk         (0x1UL << TIM_CCER_CC4E_Pos)                 /*!< 0x00001000 */
#define TIM_CCER_CC4E             TIM_CCER_CC4E_Msk                            /*!<Capture/Compare 4 output enable */
#define TIM_CCER_CC4P_Pos         (13U)
#define TIM_CCER_CC4P_Msk         (0x1UL << TIM_CCER_CC4P_Pos)                 /*!< 0x00002000 */
#define TIM_CCER_CC4P             TIM_CCER_CC4P_Msk                            /*!<Capture/Compare 4 output Polarity */
#define TIM_CCER_CC4NP_Pos        (15U)
#define TIM_CCER_CC4NP_Msk        (0x1UL << TIM_CCER_CC4NP_Pos)                /*!< 0x00008000 */
#define TIM_CCER_CC4NP            TIM_CCER_CC4NP_Msk                           /*!<Capture/Compare 4 Complementary output Polarity */
#define TIM_CCER_CC5E_Pos         (16U)
#define TIM_CCER_CC5E_Msk         (0x1UL << TIM_CCER_CC5E_Pos)                 /*!< 0x00010000 */
#define TIM_CCER_CC5E             TIM_CCER_CC5E_Msk                            /*!<Capture/Compare 5 output enable */
#define TIM_CCER_CC5P_Pos         (17U)
#define TIM_CCER_CC5P_Msk         (0x1UL << TIM_CCER_CC5P_Pos)                 /*!< 0x00020000 */
#define TIM_CCER_CC5P             TIM_CCER_CC5P_Msk                            /*!<Capture/Compare 5 output Polarity */
#define TIM_CCER_CC6E_Pos         (20U)
#define TIM_CCER_CC6E_Msk         (0x1UL << TIM_CCER_CC6E_Pos)                 /*!< 0x00100000 */
#define TIM_CCER_CC6E             TIM_CCER_CC6E_Msk                            /*!<Capture/Compare 6 output enable */
#define TIM_CCER_CC6P_Pos         (21U)
#define TIM_CCER_CC6P_Msk         (0x1UL << TIM_CCER_CC6P_Pos)                 /*!< 0x00200000 */
#define TIM_CCER_CC6P             TIM_CCER_CC6P_Msk                            /*!<Capture/Compare 6 output Polarity */

/*******************  Bit definition for TIM_CNT register  ********************/
#define TIM_CNT_CNT_Pos           (0U)
#define TIM_CNT_CNT_Msk           (0xFFFFFFFFUL << TIM_CNT_CNT_Pos)            /*!< 0xFFFFFFFF */
#define TIM_CNT_CNT               TIM_CNT_CNT_Msk                              /*!<Counter Value */
#define TIM_CNT_UIFCPY_Pos        (31U)
#define TIM_CNT_UIFCPY_Msk        (0x1UL << TIM_CNT_UIFCPY_Pos)                /*!< 0x80000000 */
#define TIM_CNT_UIFCPY            TIM_CNT_UIFCPY_Msk                           /*!<Update interrupt flag copy (if UIFREMAP=1) */

/*******************  Bit definition for TIM_PSC register  ********************/
#define TIM_PSC_PSC_Pos           (0U)
#define TIM_PSC_PSC_Msk           (0xFFFFUL << TIM_PSC_PSC_Pos)                /*!< 0x0000FFFF */
#define TIM_PSC_PSC               TIM_PSC_PSC_Msk                              /*!<Prescaler Value */

/*******************  Bit definition for TIM_ARR register  ********************/
#define TIM_ARR_ARR_Pos           (0U)
#define TIM_ARR_ARR_Msk           (0xFFFFFFFFUL << TIM_ARR_ARR_Pos)            /*!< 0xFFFFFFFF */
#define TIM_ARR_ARR               TIM_ARR_ARR_Msk                              /*!<Actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  ********************/
#define TIM_RCR_REP_Pos           (0U)
#define TIM_RCR_REP_Msk           (0xFFFFUL << TIM_RCR_REP_Pos)                /*!< 0x0000FFFF */
#define TIM_RCR_REP               TIM_RCR_REP_Msk                              /*!<Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  *******************/
#define TIM_CCR1_CCR1_Pos         (0U)
#define TIM_CCR1_CCR1_Msk         (0xFFFFUL << TIM_CCR1_CCR1_Pos)              /*!< 0x0000FFFF */
#define TIM_CCR1_CCR1             TIM_CCR1_CCR1_Msk                            /*!<Capture/Compare 1 Value */

/*******************  Bit definition for TIM_CCR2 register  *******************/
#define TIM_CCR2_CCR2_Pos         (0U)
#define TIM_CCR2_CCR2_Msk         (0xFFFFUL << TIM_CCR2_CCR2_Pos)              /*!< 0x0000FFFF */
#define TIM_CCR2_CCR2             TIM_CCR2_CCR2_Msk                            /*!<Capture/Compare 2 Value */

/*******************  Bit definition for TIM_CCR3 register  *******************/
#define TIM_CCR3_CCR3_Pos         (0U)
#define TIM_CCR3_CCR3_Msk         (0xFFFFUL << TIM_CCR3_CCR3_Pos)              /*!< 0x0000FFFF */
#define TIM_CCR3_CCR3             TIM_CCR3_CCR3_Msk                            /*!<Capture/Compare 3 Value */

/*******************  Bit definition for TIM_CCR4 register  *******************/
#define TIM_CCR4_CCR4_Pos         (0U)
#define TIM_CCR4_CCR4_Msk         (0xFFFFUL << TIM_CCR4_CCR4_Pos)              /*!< 0x0000FFFF */
#define TIM_CCR4_CCR4             TIM_CCR4_CCR4_Msk                            /*!<Capture/Compare 4 Value */

/*******************  Bit definition for TIM_CCR5 register  *******************/
#define TIM_CCR5_CCR5_Pos         (0U)
#define TIM_CCR5_CCR5_Msk         (0xFFFFUL << TIM_CCR5_CCR5_Pos)          /*!< 0xFFFF */
#define TIM_CCR5_CCR5             TIM_CCR5_CCR5_Msk                            /*!<Capture/Compare 5 Value */
#define TIM_CCR5_GC5C1_Pos        (29U)
#define TIM_CCR5_GC5C1_Msk        (0x1UL << TIM_CCR5_GC5C1_Pos)                /*!< 0x20000000 */
#define TIM_CCR5_GC5C1            TIM_CCR5_GC5C1_Msk                           /*!<Group Channel 5 and Channel 1 */
#define TIM_CCR5_GC5C2_Pos        (30U)
#define TIM_CCR5_GC5C2_Msk        (0x1UL << TIM_CCR5_GC5C2_Pos)                /*!< 0x40000000 */
#define TIM_CCR5_GC5C2            TIM_CCR5_GC5C2_Msk                           /*!<Group Channel 5 and Channel 2 */
#define TIM_CCR5_GC5C3_Pos        (31U)
#define TIM_CCR5_GC5C3_Msk        (0x1UL << TIM_CCR5_GC5C3_Pos)                /*!< 0x80000000 */
#define TIM_CCR5_GC5C3            TIM_CCR5_GC5C3_Msk                           /*!<Group Channel 5 and Channel 3 */

/*******************  Bit definition for TIM_CCR6 register  *******************/
#define TIM_CCR6_CCR6_Pos         (0U)
#define TIM_CCR6_CCR6_Msk         (0xFFFFUL << TIM_CCR6_CCR6_Pos)              /*!< 0x0000FFFF */
#define TIM_CCR6_CCR6             TIM_CCR6_CCR6_Msk                            /*!<Capture/Compare 6 Value */

/*******************  Bit definition for TIM_BDTR register  *******************/
#define TIM_BDTR_DTG_Pos          (0U)
#define TIM_BDTR_DTG_Msk          (0xFFUL << TIM_BDTR_DTG_Pos)                 /*!< 0x000000FF */
#define TIM_BDTR_DTG              TIM_BDTR_DTG_Msk                             /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define TIM_BDTR_DTG_0            (0x01U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000001 */
#define TIM_BDTR_DTG_1            (0x02U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000002 */
#define TIM_BDTR_DTG_2            (0x04U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000004 */
#define TIM_BDTR_DTG_3            (0x08U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000008 */
#define TIM_BDTR_DTG_4            (0x10U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000010 */
#define TIM_BDTR_DTG_5            (0x20U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000020 */
#define TIM_BDTR_DTG_6            (0x40U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000040 */
#define TIM_BDTR_DTG_7            (0x80U << TIM_BDTR_DTG_Pos)                  /*!< 0x00000080 */

#define TIM_BDTR_LOCK_Pos         (8U)
#define TIM_BDTR_LOCK_Msk         (0x3UL << TIM_BDTR_LOCK_Pos)                 /*!< 0x00000300 */
#define TIM_BDTR_LOCK             TIM_BDTR_LOCK_Msk                            /*!<LOCK[1:0] bits (Lock Configuration) */
#define TIM_BDTR_LOCK_0           (0x1U << TIM_BDTR_LOCK_Pos)                  /*!< 0x00000100 */
#define TIM_BDTR_LOCK_1           (0x2U << TIM_BDTR_LOCK_Pos)                  /*!< 0x00000200 */

#define TIM_BDTR_OSSI_Pos         (10U)
#define TIM_BDTR_OSSI_Msk         (0x1UL << TIM_BDTR_OSSI_Pos)                 /*!< 0x00000400 */
#define TIM_BDTR_OSSI             TIM_BDTR_OSSI_Msk                            /*!<Off-State Selection for Idle mode */
#define TIM_BDTR_OSSR_Pos         (11U)
#define TIM_BDTR_OSSR_Msk         (0x1UL << TIM_BDTR_OSSR_Pos)                 /*!< 0x00000800 */
#define TIM_BDTR_OSSR             TIM_BDTR_OSSR_Msk                            /*!<Off-State Selection for Run mode */
#define TIM_BDTR_BKE_Pos          (12U)
#define TIM_BDTR_BKE_Msk          (0x1UL << TIM_BDTR_BKE_Pos)                  /*!< 0x00001000 */
#define TIM_BDTR_BKE              TIM_BDTR_BKE_Msk                             /*!<Break enable for Break 1 */
#define TIM_BDTR_BKP_Pos          (13U)
#define TIM_BDTR_BKP_Msk          (0x1UL << TIM_BDTR_BKP_Pos)                  /*!< 0x00002000 */
#define TIM_BDTR_BKP              TIM_BDTR_BKP_Msk                             /*!<Break Polarity for Break 1 */
#define TIM_BDTR_AOE_Pos          (14U)
#define TIM_BDTR_AOE_Msk          (0x1UL << TIM_BDTR_AOE_Pos)                  /*!< 0x00004000 */
#define TIM_BDTR_AOE              TIM_BDTR_AOE_Msk                             /*!<Automatic Output enable */
#define TIM_BDTR_MOE_Pos          (15U)
#define TIM_BDTR_MOE_Msk          (0x1UL << TIM_BDTR_MOE_Pos)                  /*!< 0x00008000 */
#define TIM_BDTR_MOE              TIM_BDTR_MOE_Msk                             /*!<Main Output enable */

#define TIM_BDTR_BKF_Pos          (16U)
#define TIM_BDTR_BKF_Msk          (0xFUL << TIM_BDTR_BKF_Pos)                  /*!< 0x000F0000 */
#define TIM_BDTR_BKF              TIM_BDTR_BKF_Msk                             /*!<Break Filter for Break 1 */
#define TIM_BDTR_BK2F_Pos         (20U)
#define TIM_BDTR_BK2F_Msk         (0xFUL << TIM_BDTR_BK2F_Pos)                 /*!< 0x00F00000 */
#define TIM_BDTR_BK2F             TIM_BDTR_BK2F_Msk                            /*!<Break Filter for Break 2 */

#define TIM_BDTR_BK2E_Pos         (24U)
#define TIM_BDTR_BK2E_Msk         (0x1UL << TIM_BDTR_BK2E_Pos)                 /*!< 0x01000000 */
#define TIM_BDTR_BK2E             TIM_BDTR_BK2E_Msk                            /*!<Break enable for Break 2 */
#define TIM_BDTR_BK2P_Pos         (25U)
#define TIM_BDTR_BK2P_Msk         (0x1UL << TIM_BDTR_BK2P_Pos)                 /*!< 0x02000000 */
#define TIM_BDTR_BK2P             TIM_BDTR_BK2P_Msk                            /*!<Break Polarity for Break 2 */

#define TIM_BDTR_BKDSRM_Pos       (26U)
#define TIM_BDTR_BKDSRM_Msk       (0x1UL << TIM_BDTR_BKDSRM_Pos)               /*!< 0x04000000 */
#define TIM_BDTR_BKDSRM           TIM_BDTR_BKDSRM_Msk                          /*!<Break disarming/re-arming */
#define TIM_BDTR_BK2DSRM_Pos      (27U)
#define TIM_BDTR_BK2DSRM_Msk      (0x1UL << TIM_BDTR_BK2DSRM_Pos)              /*!< 0x08000000 */
#define TIM_BDTR_BK2DSRM          TIM_BDTR_BK2DSRM_Msk                         /*!<Break2 disarming/re-arming */

#define TIM_BDTR_BKBID_Pos        (28U)
#define TIM_BDTR_BKBID_Msk        (0x1UL << TIM_BDTR_BKBID_Pos)                /*!< 0x10000000 */
#define TIM_BDTR_BKBID            TIM_BDTR_BKBID_Msk                           /*!<Break BIDirectional */
#define TIM_BDTR_BK2BID_Pos       (29U)
#define TIM_BDTR_BK2BID_Msk       (0x1UL << TIM_BDTR_BK2BID_Pos)               /*!< 0x20000000 */
#define TIM_BDTR_BK2BID           TIM_BDTR_BK2BID_Msk                          /*!<Break2 BIDirectional */

/*******************  Bit definition for TIM_DCR register  ********************/
#define TIM_DCR_DBA_Pos           (0U)
#define TIM_DCR_DBA_Msk           (0x1FUL << TIM_DCR_DBA_Pos)                  /*!< 0x0000001F */
#define TIM_DCR_DBA               TIM_DCR_DBA_Msk                              /*!<DBA[4:0] bits (DMA Base Address) */
#define TIM_DCR_DBA_0             (0x01U << TIM_DCR_DBA_Pos)                   /*!< 0x00000001 */
#define TIM_DCR_DBA_1             (0x02U << TIM_DCR_DBA_Pos)                   /*!< 0x00000002 */
#define TIM_DCR_DBA_2             (0x04U << TIM_DCR_DBA_Pos)                   /*!< 0x00000004 */
#define TIM_DCR_DBA_3             (0x08U << TIM_DCR_DBA_Pos)                   /*!< 0x00000008 */
#define TIM_DCR_DBA_4             (0x10U << TIM_DCR_DBA_Pos)                   /*!< 0x00000010 */

#define TIM_DCR_DBL_Pos           (8U)
#define TIM_DCR_DBL_Msk           (0x1FUL << TIM_DCR_DBL_Pos)                  /*!< 0x00001F00 */
#define TIM_DCR_DBL               TIM_DCR_DBL_Msk                              /*!<DBL[4:0] bits (DMA Burst Length) */
#define TIM_DCR_DBL_0             (0x01U << TIM_DCR_DBL_Pos)                   /*!< 0x00000100 */
#define TIM_DCR_DBL_1             (0x02U << TIM_DCR_DBL_Pos)                   /*!< 0x00000200 */
#define TIM_DCR_DBL_2             (0x04U << TIM_DCR_DBL_Pos)                   /*!< 0x00000400 */
#define TIM_DCR_DBL_3             (0x08U << TIM_DCR_DBL_Pos)                   /*!< 0x00000800 */
#define TIM_DCR_DBL_4             (0x10U << TIM_DCR_DBL_Pos)                   /*!< 0x00001000 */

/*******************  Bit definition for TIM_DMAR register  *******************/
#define TIM_DMAR_DMAB_Pos         (0U)
#define TIM_DMAR_DMAB_Msk         (0xFFFFUL << TIM_DMAR_DMAB_Pos)              /*!< 0x0000FFFF */
#define TIM_DMAR_DMAB             TIM_DMAR_DMAB_Msk                            /*!<DMA register for burst accesses */

/*******************  Bit definition for TIM1_OR register  *******************/
#define TIM1_OR_ETR_ADC1_RMP_Pos      (0U)
#define TIM1_OR_ETR_ADC1_RMP_Msk      (0x3UL << TIM1_OR_ETR_ADC1_RMP_Pos)    /*!< 0x00000003 */
#define TIM1_OR_ETR_ADC1_RMP          TIM1_OR_ETR_ADC1_RMP_Msk               /*!< TIM1_ETR_ADC1 remapping capability*/
#define TIM1_OR_ETR_ADC1_RMP_0        (0x1U << TIM1_OR_ETR_ADC1_RMP_Pos)     /*!< 0x00000001 */
#define TIM1_OR_ETR_ADC1_RMP_1        (0x2U << TIM1_OR_ETR_ADC1_RMP_Pos)     /*!< 0x00000002 */
#define TIM1_OR_TI1_RMP_Pos            (4U)
#define TIM1_OR_TI1_RMP_Msk            (0x1UL << TIM1_OR_TI1_RMP_Pos)          /*!< 0x00000010 */
#define TIM1_OR_TI1_RMP                TIM1_OR_TI1_RMP_Msk                     /*!< Input Capture 1 remap*/

/*******************  Bit definition for TIM2_OR register  *******************/
#define TIM2_OR_TI4_RMP_Pos      (2U)
#define TIM2_OR_TI4_RMP_Msk      (0x3UL << TIM2_OR_TI4_RMP_Pos)              /*!< 0x0000000C */
#define TIM2_OR_TI4_RMP          TIM2_OR_TI4_RMP_Msk                         /*!< TI4 Input capture 4 remap*/
#define TIM2_OR_TI4_RMP_0        (0x1U << TIM2_OR_TI4_RMP_Pos)               /*!< 0x00000004 */
#define TIM2_OR_ETR_RMP_Pos      (1U)
#define TIM2_OR_ETR_RMP_Msk      (0x1UL << TIM2_OR_ETR_RMP_Pos)              /*!< 0x00000002 */
#define TIM2_OR_ETR_RMP          TIM2_OR_ETR_RMP_Msk                         /*!< External trigger remap*/

/*******************  Bit definition for TIM1_AF1 register  *******************/
#define TIM1_AF1_BKINE_Pos             (0U)
#define TIM1_AF1_BKINE_Msk             (0x1UL << TIM1_AF1_BKINE_Pos)           /*!< 0x00000001 */
#define TIM1_AF1_BKINE                 TIM1_AF1_BKINE_Msk                      /*!<BRK BKIN input enable */
#define TIM1_AF1_BKCMP1E_Pos           (1U)
#define TIM1_AF1_BKCMP1E_Msk           (0x1UL << TIM1_AF1_BKCMP1E_Pos)         /*!< 0x00000002 */
#define TIM1_AF1_BKCMP1E               TIM1_AF1_BKCMP1E_Msk                    /*!<BRK COMP1 enable */
#define TIM1_AF1_BKINP_Pos             (9U)
#define TIM1_AF1_BKINP_Msk             (0x1UL << TIM1_AF1_BKINP_Pos)           /*!< 0x00000200 */
#define TIM1_AF1_BKINP                 TIM1_AF1_BKINP_Msk                      /*!<BRK BKIN input polarity */
#define TIM1_AF1_BKCMP1P_Pos           (10U)
#define TIM1_AF1_BKCMP1P_Msk           (0x1UL << TIM1_AF1_BKCMP1P_Pos)         /*!< 0x00000400 */
#define TIM1_AF1_BKCMP1P               TIM1_AF1_BKCMP1P_Msk                    /*!<BRK COMP1 input polarity */
#define TIM1_AF1_ETRSEL_Pos            (14U)
#define TIM1_AF1_ETRSEL_Msk            (0x7UL << TIM1_AF1_ETRSEL_Pos)          /*!< 0x0001C000 */
#define TIM1_AF1_ETRSEL                TIM1_AF1_ETRSEL_Msk                     /*!<ETRSEL[2:0] bits (TIM1 ETR source selection) */
#define TIM1_AF1_ETRSEL_0              (0x1U << TIM1_AF1_ETRSEL_Pos)           /*!< 0x00004000 */
#define TIM1_AF1_ETRSEL_1              (0x2U << TIM1_AF1_ETRSEL_Pos)           /*!< 0x00008000 */
#define TIM1_AF1_ETRSEL_2              (0x4U << TIM1_AF1_ETRSEL_Pos)           /*!< 0x00010000 */

/*******************  Bit definition for TIM2_AF1 register  *******************/
#define TIM2_AF1_ETRSEL_Pos       (14U)
#define TIM2_AF1_ETRSEL_Msk       (0x7UL << TIM2_AF1_ETRSEL_Pos)               /*!< 0x0001C000 */
#define TIM2_AF1_ETRSEL           (0x00001C000)                                /*!< External trigger source selection */
#define TIM2_AF1_ETRSEL_0         (0x000004000)                                /*!< Bit_0 */
#define TIM2_AF1_ETRSEL_1         (0x000008000)                                /*!< Bit_1 */
#define TIM2_AF1_ETRSEL_2         (0x000010000)                                /*!< Bit_2 */

/*******************  Bit definition for TIM17_AF1 register  *******************/
#define TIM17_AF1_BKINE_Pos             (0U)
#define TIM17_AF1_BKINE_Msk             (0x1UL << TIM17_AF1_BKINE_Pos)           /*!< 0x00000001 */
#define TIM17_AF1_BKINE                 TIM17_AF1_BKINE_Msk                      /*!<BRK BKIN input enable */
#define TIM17_AF1_BKINP_Pos            (9U)
#define TIM17_AF1_BKINP_Msk            (0x1UL << TIM17_AF1_BKINP_Pos)          /*!< 0x00000200 */
#define TIM17_AF1_BKINP                TIM17_AF1_BKINP_Msk                     /*!<BRK BKIN2 input polarity */

/*******************  Bit definition for TIM1_AF2 register  *******************/
#define TIM1_AF2_BK2INE_Pos            (0U)
#define TIM1_AF2_BK2INE_Msk            (0x1UL << TIM1_AF2_BK2INE_Pos)          /*!< 0x00000001 */
#define TIM1_AF2_BK2INE                TIM1_AF2_BK2INE_Msk                     /*!<BRK2 BKIN2 input enable */
#define TIM1_AF2_BK2CMP1E_Pos          (1U)
#define TIM1_AF2_BK2CMP1E_Msk          (0x1UL << TIM1_AF2_BK2CMP1E_Pos)        /*!< 0x00000002 */
#define TIM1_AF2_BK2CMP1E              TIM1_AF2_BK2CMP1E_Msk                   /*!<BRK2 COMP1 enable */
#define TIM1_AF2_BK2INP_Pos            (9U)
#define TIM1_AF2_BK2INP_Msk            (0x1UL << TIM1_AF2_BK2INP_Pos)          /*!< 0x00000200 */
#define TIM1_AF2_BK2INP                TIM1_AF2_BK2INP_Msk                     /*!<BRK2 BKIN2 input polarity */
#define TIM1_AF2_BK2CMP1P_Pos          (10U)
#define TIM1_AF2_BK2CMP1P_Msk          (0x1UL << TIM1_AF2_BK2CMP1P_Pos)        /*!< 0x00000400 */
#define TIM1_AF2_BK2CMP1P              TIM1_AF2_BK2CMP1P_Msk                   /*!<BRK2 COMP1 input polarity */

/******************************************************************************/
/*                                                                            */
/*                         Low Power Timer (LPTIM)                            */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for LPTIM_ISR register  *******************/
#define LPTIM_ISR_CMPM_Pos          (0U)
#define LPTIM_ISR_CMPM_Msk          (0x1UL << LPTIM_ISR_CMPM_Pos)              /*!< 0x00000001 */
#define LPTIM_ISR_CMPM              LPTIM_ISR_CMPM_Msk                         /*!< Compare match */
#define LPTIM_ISR_ARRM_Pos          (1U)
#define LPTIM_ISR_ARRM_Msk          (0x1UL << LPTIM_ISR_ARRM_Pos)              /*!< 0x00000002 */
#define LPTIM_ISR_ARRM              LPTIM_ISR_ARRM_Msk                         /*!< Autoreload match */
#define LPTIM_ISR_EXTTRIG_Pos       (2U)
#define LPTIM_ISR_EXTTRIG_Msk       (0x1UL << LPTIM_ISR_EXTTRIG_Pos)           /*!< 0x00000004 */
#define LPTIM_ISR_EXTTRIG           LPTIM_ISR_EXTTRIG_Msk                      /*!< External trigger edge event */
#define LPTIM_ISR_CMPOK_Pos         (3U)
#define LPTIM_ISR_CMPOK_Msk         (0x1UL << LPTIM_ISR_CMPOK_Pos)             /*!< 0x00000008 */
#define LPTIM_ISR_CMPOK             LPTIM_ISR_CMPOK_Msk                        /*!< Compare register update OK */
#define LPTIM_ISR_ARROK_Pos         (4U)
#define LPTIM_ISR_ARROK_Msk         (0x1UL << LPTIM_ISR_ARROK_Pos)             /*!< 0x00000010 */
#define LPTIM_ISR_ARROK             LPTIM_ISR_ARROK_Msk                        /*!< Autoreload register update OK */
#define LPTIM_ISR_UP_Pos            (5U)
#define LPTIM_ISR_UP_Msk            (0x1UL << LPTIM_ISR_UP_Pos)                /*!< 0x00000020 */
#define LPTIM_ISR_UP                LPTIM_ISR_UP_Msk                           /*!< Counter direction change down to up */
#define LPTIM_ISR_DOWN_Pos          (6U)
#define LPTIM_ISR_DOWN_Msk          (0x1UL << LPTIM_ISR_DOWN_Pos)              /*!< 0x00000040 */
#define LPTIM_ISR_DOWN              LPTIM_ISR_DOWN_Msk                         /*!< Counter direction change up to down */

/******************  Bit definition for LPTIM_ICR register  *******************/
#define LPTIM_ICR_CMPMCF_Pos        (0U)
#define LPTIM_ICR_CMPMCF_Msk        (0x1UL << LPTIM_ICR_CMPMCF_Pos)            /*!< 0x00000001 */
#define LPTIM_ICR_CMPMCF            LPTIM_ICR_CMPMCF_Msk                       /*!< Compare match Clear Flag */
#define LPTIM_ICR_ARRMCF_Pos        (1U)
#define LPTIM_ICR_ARRMCF_Msk        (0x1UL << LPTIM_ICR_ARRMCF_Pos)            /*!< 0x00000002 */
#define LPTIM_ICR_ARRMCF            LPTIM_ICR_ARRMCF_Msk                       /*!< Autoreload match Clear Flag */
#define LPTIM_ICR_EXTTRIGCF_Pos     (2U)
#define LPTIM_ICR_EXTTRIGCF_Msk     (0x1UL << LPTIM_ICR_EXTTRIGCF_Pos)         /*!< 0x00000004 */
#define LPTIM_ICR_EXTTRIGCF         LPTIM_ICR_EXTTRIGCF_Msk                    /*!< External trigger edge event Clear Flag */
#define LPTIM_ICR_CMPOKCF_Pos       (3U)
#define LPTIM_ICR_CMPOKCF_Msk       (0x1UL << LPTIM_ICR_CMPOKCF_Pos)           /*!< 0x00000008 */
#define LPTIM_ICR_CMPOKCF           LPTIM_ICR_CMPOKCF_Msk                      /*!< Compare register update OK Clear Flag */
#define LPTIM_ICR_ARROKCF_Pos       (4U)
#define LPTIM_ICR_ARROKCF_Msk       (0x1UL << LPTIM_ICR_ARROKCF_Pos)           /*!< 0x00000010 */
#define LPTIM_ICR_ARROKCF           LPTIM_ICR_ARROKCF_Msk                      /*!< Autoreload register update OK Clear Flag */
#define LPTIM_ICR_UPCF_Pos          (5U)
#define LPTIM_ICR_UPCF_Msk          (0x1UL << LPTIM_ICR_UPCF_Pos)              /*!< 0x00000020 */
#define LPTIM_ICR_UPCF              LPTIM_ICR_UPCF_Msk                         /*!< Counter direction change down to up Clear Flag */
#define LPTIM_ICR_DOWNCF_Pos        (6U)
#define LPTIM_ICR_DOWNCF_Msk        (0x1UL << LPTIM_ICR_DOWNCF_Pos)            /*!< 0x00000040 */
#define LPTIM_ICR_DOWNCF            LPTIM_ICR_DOWNCF_Msk                       /*!< Counter direction change up to down Clear Flag */

/******************  Bit definition for LPTIM_IER register ********************/
#define LPTIM_IER_CMPMIE_Pos        (0U)
#define LPTIM_IER_CMPMIE_Msk        (0x1UL << LPTIM_IER_CMPMIE_Pos)            /*!< 0x00000001 */
#define LPTIM_IER_CMPMIE            LPTIM_IER_CMPMIE_Msk                       /*!< Compare match Interrupt Enable */
#define LPTIM_IER_ARRMIE_Pos        (1U)
#define LPTIM_IER_ARRMIE_Msk        (0x1UL << LPTIM_IER_ARRMIE_Pos)            /*!< 0x00000002 */
#define LPTIM_IER_ARRMIE            LPTIM_IER_ARRMIE_Msk                       /*!< Autoreload match Interrupt Enable */
#define LPTIM_IER_EXTTRIGIE_Pos     (2U)
#define LPTIM_IER_EXTTRIGIE_Msk     (0x1UL << LPTIM_IER_EXTTRIGIE_Pos)         /*!< 0x00000004 */
#define LPTIM_IER_EXTTRIGIE         LPTIM_IER_EXTTRIGIE_Msk                    /*!< External trigger edge event Interrupt Enable */
#define LPTIM_IER_CMPOKIE_Pos       (3U)
#define LPTIM_IER_CMPOKIE_Msk       (0x1UL << LPTIM_IER_CMPOKIE_Pos)           /*!< 0x00000008 */
#define LPTIM_IER_CMPOKIE           LPTIM_IER_CMPOKIE_Msk                      /*!< Compare register update OK Interrupt Enable */
#define LPTIM_IER_ARROKIE_Pos       (4U)
#define LPTIM_IER_ARROKIE_Msk       (0x1UL << LPTIM_IER_ARROKIE_Pos)           /*!< 0x00000010 */
#define LPTIM_IER_ARROKIE           LPTIM_IER_ARROKIE_Msk                      /*!< Autoreload register update OK Interrupt Enable */
#define LPTIM_IER_UPIE_Pos          (5U)
#define LPTIM_IER_UPIE_Msk          (0x1UL << LPTIM_IER_UPIE_Pos)              /*!< 0x00000020 */
#define LPTIM_IER_UPIE              LPTIM_IER_UPIE_Msk                         /*!< Counter direction change down to up Interrupt Enable */
#define LPTIM_IER_DOWNIE_Pos        (6U)
#define LPTIM_IER_DOWNIE_Msk        (0x1UL << LPTIM_IER_DOWNIE_Pos)            /*!< 0x00000040 */
#define LPTIM_IER_DOWNIE            LPTIM_IER_DOWNIE_Msk                       /*!< Counter direction change up to down Interrupt Enable */

/******************  Bit definition for LPTIM_CFGR register *******************/
#define LPTIM_CFGR_CKSEL_Pos        (0U)
#define LPTIM_CFGR_CKSEL_Msk        (0x1UL << LPTIM_CFGR_CKSEL_Pos)            /*!< 0x00000001 */
#define LPTIM_CFGR_CKSEL            LPTIM_CFGR_CKSEL_Msk                       /*!< Clock selector */

#define LPTIM_CFGR_CKPOL_Pos        (1U)
#define LPTIM_CFGR_CKPOL_Msk        (0x3UL << LPTIM_CFGR_CKPOL_Pos)            /*!< 0x00000006 */
#define LPTIM_CFGR_CKPOL            LPTIM_CFGR_CKPOL_Msk                       /*!< CKPOL[1:0] bits (Clock polarity) */
#define LPTIM_CFGR_CKPOL_0          (0x1U << LPTIM_CFGR_CKPOL_Pos)             /*!< 0x00000002 */
#define LPTIM_CFGR_CKPOL_1          (0x2U << LPTIM_CFGR_CKPOL_Pos)             /*!< 0x00000004 */

#define LPTIM_CFGR_CKFLT_Pos        (3U)
#define LPTIM_CFGR_CKFLT_Msk        (0x3UL << LPTIM_CFGR_CKFLT_Pos)            /*!< 0x00000018 */
#define LPTIM_CFGR_CKFLT            LPTIM_CFGR_CKFLT_Msk                       /*!< CKFLT[1:0] bits (Configurable digital filter for external clock) */
#define LPTIM_CFGR_CKFLT_0          (0x1U << LPTIM_CFGR_CKFLT_Pos)             /*!< 0x00000008 */
#define LPTIM_CFGR_CKFLT_1          (0x2U << LPTIM_CFGR_CKFLT_Pos)             /*!< 0x00000010 */

#define LPTIM_CFGR_TRGFLT_Pos       (6U)
#define LPTIM_CFGR_TRGFLT_Msk       (0x3UL << LPTIM_CFGR_TRGFLT_Pos)           /*!< 0x000000C0 */
#define LPTIM_CFGR_TRGFLT           LPTIM_CFGR_TRGFLT_Msk                      /*!< TRGFLT[1:0] bits (Configurable digital filter for trigger) */
#define LPTIM_CFGR_TRGFLT_0         (0x1U << LPTIM_CFGR_TRGFLT_Pos)            /*!< 0x00000040 */
#define LPTIM_CFGR_TRGFLT_1         (0x2U << LPTIM_CFGR_TRGFLT_Pos)            /*!< 0x00000080 */

#define LPTIM_CFGR_PRESC_Pos        (9U)
#define LPTIM_CFGR_PRESC_Msk        (0x7UL << LPTIM_CFGR_PRESC_Pos)            /*!< 0x00000E00 */
#define LPTIM_CFGR_PRESC            LPTIM_CFGR_PRESC_Msk                       /*!< PRESC[2:0] bits (Clock prescaler) */
#define LPTIM_CFGR_PRESC_0          (0x1U << LPTIM_CFGR_PRESC_Pos)             /*!< 0x00000200 */
#define LPTIM_CFGR_PRESC_1          (0x2U << LPTIM_CFGR_PRESC_Pos)             /*!< 0x00000400 */
#define LPTIM_CFGR_PRESC_2          (0x4U << LPTIM_CFGR_PRESC_Pos)             /*!< 0x00000800 */

#define LPTIM_CFGR_TRIGSEL_Pos      (13U)
#define LPTIM_CFGR_TRIGSEL_Msk      (0x7UL << LPTIM_CFGR_TRIGSEL_Pos)          /*!< 0x0000E000 */
#define LPTIM_CFGR_TRIGSEL          LPTIM_CFGR_TRIGSEL_Msk                     /*!< TRIGSEL[2:0]] bits (Trigger selector) */
#define LPTIM_CFGR_TRIGSEL_0        (0x1U << LPTIM_CFGR_TRIGSEL_Pos)           /*!< 0x00002000 */
#define LPTIM_CFGR_TRIGSEL_1        (0x2U << LPTIM_CFGR_TRIGSEL_Pos)           /*!< 0x00004000 */
#define LPTIM_CFGR_TRIGSEL_2        (0x4U << LPTIM_CFGR_TRIGSEL_Pos)           /*!< 0x00008000 */

#define LPTIM_CFGR_TRIGEN_Pos       (17U)
#define LPTIM_CFGR_TRIGEN_Msk       (0x3UL << LPTIM_CFGR_TRIGEN_Pos)           /*!< 0x00060000 */
#define LPTIM_CFGR_TRIGEN           LPTIM_CFGR_TRIGEN_Msk                      /*!< TRIGEN[1:0] bits (Trigger enable and polarity) */
#define LPTIM_CFGR_TRIGEN_0         (0x1U << LPTIM_CFGR_TRIGEN_Pos)            /*!< 0x00020000 */
#define LPTIM_CFGR_TRIGEN_1         (0x2U << LPTIM_CFGR_TRIGEN_Pos)            /*!< 0x00040000 */

#define LPTIM_CFGR_TIMOUT_Pos       (19U)
#define LPTIM_CFGR_TIMOUT_Msk       (0x1UL << LPTIM_CFGR_TIMOUT_Pos)           /*!< 0x00080000 */
#define LPTIM_CFGR_TIMOUT           LPTIM_CFGR_TIMOUT_Msk                      /*!< Timeout enable */
#define LPTIM_CFGR_WAVE_Pos         (20U)
#define LPTIM_CFGR_WAVE_Msk         (0x1UL << LPTIM_CFGR_WAVE_Pos)             /*!< 0x00100000 */
#define LPTIM_CFGR_WAVE             LPTIM_CFGR_WAVE_Msk                        /*!< Waveform shape */
#define LPTIM_CFGR_WAVPOL_Pos       (21U)
#define LPTIM_CFGR_WAVPOL_Msk       (0x1UL << LPTIM_CFGR_WAVPOL_Pos)           /*!< 0x00200000 */
#define LPTIM_CFGR_WAVPOL           LPTIM_CFGR_WAVPOL_Msk                      /*!< Waveform shape polarity */
#define LPTIM_CFGR_PRELOAD_Pos      (22U)
#define LPTIM_CFGR_PRELOAD_Msk      (0x1UL << LPTIM_CFGR_PRELOAD_Pos)          /*!< 0x00400000 */
#define LPTIM_CFGR_PRELOAD          LPTIM_CFGR_PRELOAD_Msk                     /*!< Reg update mode */
#define LPTIM_CFGR_COUNTMODE_Pos    (23U)
#define LPTIM_CFGR_COUNTMODE_Msk    (0x1UL << LPTIM_CFGR_COUNTMODE_Pos)        /*!< 0x00800000 */
#define LPTIM_CFGR_COUNTMODE        LPTIM_CFGR_COUNTMODE_Msk                   /*!< Counter mode enable */
#define LPTIM_CFGR_ENC_Pos          (24U)
#define LPTIM_CFGR_ENC_Msk          (0x1UL << LPTIM_CFGR_ENC_Pos)              /*!< 0x01000000 */
#define LPTIM_CFGR_ENC              LPTIM_CFGR_ENC_Msk                         /*!< Encoder mode enable */

/******************  Bit definition for LPTIM_CR register  ********************/
#define LPTIM_CR_ENABLE_Pos         (0U)
#define LPTIM_CR_ENABLE_Msk         (0x1UL << LPTIM_CR_ENABLE_Pos)             /*!< 0x00000001 */
#define LPTIM_CR_ENABLE             LPTIM_CR_ENABLE_Msk                        /*!< LPTIMer enable */
#define LPTIM_CR_SNGSTRT_Pos        (1U)
#define LPTIM_CR_SNGSTRT_Msk        (0x1UL << LPTIM_CR_SNGSTRT_Pos)            /*!< 0x00000002 */
#define LPTIM_CR_SNGSTRT            LPTIM_CR_SNGSTRT_Msk                       /*!< Timer start in single mode */
#define LPTIM_CR_CNTSTRT_Pos        (2U)
#define LPTIM_CR_CNTSTRT_Msk        (0x1UL << LPTIM_CR_CNTSTRT_Pos)            /*!< 0x00000004 */
#define LPTIM_CR_CNTSTRT            LPTIM_CR_CNTSTRT_Msk                       /*!< Timer start in continuous mode */
#define LPTIM_CR_COUNTRST_Pos       (3U)
#define LPTIM_CR_COUNTRST_Msk       (0x1UL << LPTIM_CR_COUNTRST_Pos)           /*!< 0x00000008 */
#define LPTIM_CR_COUNTRST           LPTIM_CR_COUNTRST_Msk                      /*!< Counter reset */
#define LPTIM_CR_RSTARE_Pos         (4U)
#define LPTIM_CR_RSTARE_Msk         (0x1UL << LPTIM_CR_RSTARE_Pos)             /*!< 0x00000010 */
#define LPTIM_CR_RSTARE             LPTIM_CR_RSTARE_Msk                        /*!< Reset after read enable */

/******************  Bit definition for LPTIM_CMP register  *******************/
#define LPTIM_CMP_CMP_Pos           (0U)
#define LPTIM_CMP_CMP_Msk           (0xFFFFUL << LPTIM_CMP_CMP_Pos)            /*!< 0x0000FFFF */
#define LPTIM_CMP_CMP               LPTIM_CMP_CMP_Msk                          /*!< Compare register */

/******************  Bit definition for LPTIM_ARR register  *******************/
#define LPTIM_ARR_ARR_Pos           (0U)
#define LPTIM_ARR_ARR_Msk           (0xFFFFUL << LPTIM_ARR_ARR_Pos)            /*!< 0x0000FFFF */
#define LPTIM_ARR_ARR               LPTIM_ARR_ARR_Msk                          /*!< Auto reload register */

/******************  Bit definition for LPTIM_CNT register  *******************/
#define LPTIM_CNT_CNT_Pos           (0U)
#define LPTIM_CNT_CNT_Msk           (0xFFFFUL << LPTIM_CNT_CNT_Pos)            /*!< 0x0000FFFF */
#define LPTIM_CNT_CNT               LPTIM_CNT_CNT_Msk                          /*!< Counter register */

/******************  Bit definition for LPTIM_OR register  *******************/
#define LPTIM_OR_OR_Pos             (0U)
#define LPTIM_OR_OR_Msk             (0x1UL << LPTIM_OR_OR_Pos)                 /*!< 0x00000001 */
#define LPTIM_OR_OR                 LPTIM_OR_OR_Msk                            /*!< OR[1:0] bits (Remap selection) */
#define LPTIM_OR_OR_0               (0x1U << LPTIM_OR_OR_Pos)                  /*!< 0x00000001 */

/******************************************************************************/
/*                                                                            */
/*         Inter-Processor Communication Controller (IPCC)                    */
/*                                                                            */
/******************************************************************************/

/**********************  Bit definition for IPCC_C1CR register  ***************/
#define IPCC_C1CR_RXOIE_Pos      (0U)
#define IPCC_C1CR_RXOIE_Msk      (0x1UL << IPCC_C1CR_RXOIE_Pos)                /*!< 0x00000001 */
#define IPCC_C1CR_RXOIE          IPCC_C1CR_RXOIE_Msk                           /*!< Processor M4 Receive channel occupied interrupt enable */
#define IPCC_C1CR_TXFIE_Pos      (16U)
#define IPCC_C1CR_TXFIE_Msk      (0x1UL << IPCC_C1CR_TXFIE_Pos)                /*!< 0x00010000 */
#define IPCC_C1CR_TXFIE          IPCC_C1CR_TXFIE_Msk                           /*!< Processor M4 Transmit channel free interrupt enable */

/**********************  Bit definition for IPCC_C1MR register  **************/
#define IPCC_C1MR_CH1OM_Pos      (0U)
#define IPCC_C1MR_CH1OM_Msk      (0x1UL << IPCC_C1MR_CH1OM_Pos)                /*!< 0x00000001 */
#define IPCC_C1MR_CH1OM          IPCC_C1MR_CH1OM_Msk                           /*!< M4 Channel1 occupied interrupt mask */
#define IPCC_C1MR_CH2OM_Pos      (1U)
#define IPCC_C1MR_CH2OM_Msk      (0x1UL << IPCC_C1MR_CH2OM_Pos)                /*!< 0x00000002 */
#define IPCC_C1MR_CH2OM          IPCC_C1MR_CH2OM_Msk                           /*!< M4 Channel2 occupied interrupt mask */
#define IPCC_C1MR_CH3OM_Pos      (2U)
#define IPCC_C1MR_CH3OM_Msk      (0x1UL << IPCC_C1MR_CH3OM_Pos)                /*!< 0x00000004 */
#define IPCC_C1MR_CH3OM          IPCC_C1MR_CH3OM_Msk                           /*!< M4 Channel3 occupied interrupt mask */
#define IPCC_C1MR_CH4OM_Pos      (3U)
#define IPCC_C1MR_CH4OM_Msk      (0x1UL << IPCC_C1MR_CH4OM_Pos)                /*!< 0x00000008 */
#define IPCC_C1MR_CH4OM          IPCC_C1MR_CH4OM_Msk                           /*!< M4 Channel4 occupied interrupt mask */
#define IPCC_C1MR_CH5OM_Pos      (4U)
#define IPCC_C1MR_CH5OM_Msk      (0x1UL << IPCC_C1MR_CH5OM_Pos)                /*!< 0x00000010 */
#define IPCC_C1MR_CH5OM          IPCC_C1MR_CH5OM_Msk                           /*!< M4 Channel5 occupied interrupt mask */
#define IPCC_C1MR_CH6OM_Pos      (5U)
#define IPCC_C1MR_CH6OM_Msk      (0x1UL << IPCC_C1MR_CH6OM_Pos)                /*!< 0x00000020 */
#define IPCC_C1MR_CH6OM          IPCC_C1MR_CH6OM_Msk                           /*!< M4 Channel6 occupied interrupt mask */

#define IPCC_C1MR_CH1FM_Pos      (16U)
#define IPCC_C1MR_CH1FM_Msk      (0x1UL << IPCC_C1MR_CH1FM_Pos)                /*!< 0x00010000 */
#define IPCC_C1MR_CH1FM          IPCC_C1MR_CH1FM_Msk                           /*!< M4 Transmit Channel1 free interrupt mask */
#define IPCC_C1MR_CH2FM_Pos      (17U)
#define IPCC_C1MR_CH2FM_Msk      (0x1UL << IPCC_C1MR_CH2FM_Pos)                /*!< 0x00020000 */
#define IPCC_C1MR_CH2FM          IPCC_C1MR_CH2FM_Msk                           /*!< M4 Transmit Channel2 free interrupt mask */
#define IPCC_C1MR_CH3FM_Pos      (18U)
#define IPCC_C1MR_CH3FM_Msk      (0x1UL << IPCC_C1MR_CH3FM_Pos)                /*!< 0x00040000 */
#define IPCC_C1MR_CH3FM          IPCC_C1MR_CH3FM_Msk                           /*!< M4 Transmit Channel3 free interrupt mask */
#define IPCC_C1MR_CH4FM_Pos      (19U)
#define IPCC_C1MR_CH4FM_Msk      (0x1UL << IPCC_C1MR_CH4FM_Pos)                /*!< 0x00080000 */
#define IPCC_C1MR_CH4FM          IPCC_C1MR_CH4FM_Msk                           /*!< M4 Transmit Channel4 free interrupt mask */
#define IPCC_C1MR_CH5FM_Pos      (20U)
#define IPCC_C1MR_CH5FM_Msk      (0x1UL << IPCC_C1MR_CH5FM_Pos)                /*!< 0x00100000 */
#define IPCC_C1MR_CH5FM          IPCC_C1MR_CH5FM_Msk                           /*!< M4 Transmit Channel5 free interrupt mask */
#define IPCC_C1MR_CH6FM_Pos      (21U)
#define IPCC_C1MR_CH6FM_Msk      (0x1UL << IPCC_C1MR_CH6FM_Pos)                /*!< 0x00200000 */
#define IPCC_C1MR_CH6FM          IPCC_C1MR_CH6FM_Msk                           /*!< M4 Transmit Channel6 free interrupt mask */

/**********************  Bit definition for IPCC_C1SCR register  ***************/
#define IPCC_C1SCR_CH1C_Pos      (0U)
#define IPCC_C1SCR_CH1C_Msk      (0x1UL << IPCC_C1SCR_CH1C_Pos)                /*!< 0x00000001 */
#define IPCC_C1SCR_CH1C          IPCC_C1SCR_CH1C_Msk                           /*!< M4 receive Channel1 status clear */
#define IPCC_C1SCR_CH2C_Pos      (1U)
#define IPCC_C1SCR_CH2C_Msk      (0x1UL << IPCC_C1SCR_CH2C_Pos)                /*!< 0x00000002 */
#define IPCC_C1SCR_CH2C          IPCC_C1SCR_CH2C_Msk                           /*!< M4 receive Channel2 status clear */
#define IPCC_C1SCR_CH3C_Pos      (2U)
#define IPCC_C1SCR_CH3C_Msk      (0x1UL << IPCC_C1SCR_CH3C_Pos)                /*!< 0x00000004 */
#define IPCC_C1SCR_CH3C          IPCC_C1SCR_CH3C_Msk                           /*!< M4 receive Channel3 status clear */
#define IPCC_C1SCR_CH4C_Pos      (3U)
#define IPCC_C1SCR_CH4C_Msk      (0x1UL << IPCC_C1SCR_CH4C_Pos)                /*!< 0x00000008 */
#define IPCC_C1SCR_CH4C          IPCC_C1SCR_CH4C_Msk                           /*!< M4 receive Channel4 status clear */
#define IPCC_C1SCR_CH5C_Pos      (4U)
#define IPCC_C1SCR_CH5C_Msk      (0x1UL << IPCC_C1SCR_CH5C_Pos)                /*!< 0x00000010 */
#define IPCC_C1SCR_CH5C          IPCC_C1SCR_CH5C_Msk                           /*!< M4 receive Channel5 status clear */
#define IPCC_C1SCR_CH6C_Pos      (5U)
#define IPCC_C1SCR_CH6C_Msk      (0x1UL << IPCC_C1SCR_CH6C_Pos)                /*!< 0x00000020 */
#define IPCC_C1SCR_CH6C          IPCC_C1SCR_CH6C_Msk                           /*!< M4 receive Channel6 status clear */

#define IPCC_C1SCR_CH1S_Pos      (16U)
#define IPCC_C1SCR_CH1S_Msk      (0x1UL << IPCC_C1SCR_CH1S_Pos)                /*!< 0x00010000 */
#define IPCC_C1SCR_CH1S          IPCC_C1SCR_CH1S_Msk                           /*!< M4 transmit Channel1 status set */
#define IPCC_C1SCR_CH2S_Pos      (17U)
#define IPCC_C1SCR_CH2S_Msk      (0x1UL << IPCC_C1SCR_CH2S_Pos)                /*!< 0x00020000 */
#define IPCC_C1SCR_CH2S          IPCC_C1SCR_CH2S_Msk                           /*!< M4 transmit Channel2 status set  */
#define IPCC_C1SCR_CH3S_Pos      (18U)
#define IPCC_C1SCR_CH3S_Msk      (0x1UL << IPCC_C1SCR_CH3S_Pos)                /*!< 0x00040000 */
#define IPCC_C1SCR_CH3S          IPCC_C1SCR_CH3S_Msk                           /*!< M4 transmit Channel3 status set  */
#define IPCC_C1SCR_CH4S_Pos      (19U)
#define IPCC_C1SCR_CH4S_Msk      (0x1UL << IPCC_C1SCR_CH4S_Pos)                /*!< 0x00080000 */
#define IPCC_C1SCR_CH4S          IPCC_C1SCR_CH4S_Msk                           /*!< M4 transmit Channel4 status set  */
#define IPCC_C1SCR_CH5S_Pos      (20U)
#define IPCC_C1SCR_CH5S_Msk      (0x1UL << IPCC_C1SCR_CH5S_Pos)                /*!< 0x00100000 */
#define IPCC_C1SCR_CH5S          IPCC_C1SCR_CH5S_Msk                           /*!< M4 transmit Channel5 status set  */
#define IPCC_C1SCR_CH6S_Pos      (21U)
#define IPCC_C1SCR_CH6S_Msk      (0x1UL << IPCC_C1SCR_CH6S_Pos)                /*!< 0x00200000 */
#define IPCC_C1SCR_CH6S          IPCC_C1SCR_CH6S_Msk                           /*!< M4 transmit Channel6 status set  */

/**********************  Bit definition for IPCC_C1TOC2SR register  ***************/
#define IPCC_C1TOC2SR_CH1F_Pos    (0U)
#define IPCC_C1TOC2SR_CH1F_Msk    (0x1UL << IPCC_C1TOC2SR_CH1F_Pos)            /*!< 0x00000001 */
#define IPCC_C1TOC2SR_CH1F        IPCC_C1TOC2SR_CH1F_Msk                       /*!< M4 transmit to M4 receive Channel1 status flag before masking */
#define IPCC_C1TOC2SR_CH2F_Pos    (1U)
#define IPCC_C1TOC2SR_CH2F_Msk    (0x1UL << IPCC_C1TOC2SR_CH2F_Pos)            /*!< 0x00000002 */
#define IPCC_C1TOC2SR_CH2F        IPCC_C1TOC2SR_CH2F_Msk                       /*!< M4 transmit to M4 receive Channel2 status flag before masking */
#define IPCC_C1TOC2SR_CH3F_Pos    (2U)
#define IPCC_C1TOC2SR_CH3F_Msk    (0x1UL << IPCC_C1TOC2SR_CH3F_Pos)            /*!< 0x00000004 */
#define IPCC_C1TOC2SR_CH3F        IPCC_C1TOC2SR_CH3F_Msk                       /*!< M4 transmit to M4 receive Channel3 status flag before masking */
#define IPCC_C1TOC2SR_CH4F_Pos    (3U)
#define IPCC_C1TOC2SR_CH4F_Msk    (0x1UL << IPCC_C1TOC2SR_CH4F_Pos)            /*!< 0x00000008 */
#define IPCC_C1TOC2SR_CH4F        IPCC_C1TOC2SR_CH4F_Msk                       /*!< M4 transmit to M4 receive Channel4 status flag before masking */
#define IPCC_C1TOC2SR_CH5F_Pos    (4U)
#define IPCC_C1TOC2SR_CH5F_Msk    (0x1UL << IPCC_C1TOC2SR_CH5F_Pos)            /*!< 0x00000010 */
#define IPCC_C1TOC2SR_CH5F        IPCC_C1TOC2SR_CH5F_Msk                       /*!< M4 transmit to M4 receive Channel5 status flag before masking */
#define IPCC_C1TOC2SR_CH6F_Pos    (5U)
#define IPCC_C1TOC2SR_CH6F_Msk    (0x1UL << IPCC_C1TOC2SR_CH6F_Pos)            /*!< 0x00000020 */
#define IPCC_C1TOC2SR_CH6F        IPCC_C1TOC2SR_CH6F_Msk                       /*!< M4 transmit to M4 receive Channel6 status flag before masking */

/**********************  Bit definition for IPCC_C2CR register  ***************/
#define IPCC_C2CR_RXOIE_Pos      (0U)
#define IPCC_C2CR_RXOIE_Msk      (0x1UL << IPCC_C2CR_RXOIE_Pos)                /*!< 0x00000001 */
#define IPCC_C2CR_RXOIE          IPCC_C2CR_RXOIE_Msk                           /*!< Processor M0+ Receive channel occupied interrupt enable */
#define IPCC_C2CR_TXFIE_Pos      (16U)
#define IPCC_C2CR_TXFIE_Msk      (0x1UL << IPCC_C2CR_TXFIE_Pos)                /*!< 0x00010000 */
#define IPCC_C2CR_TXFIE          IPCC_C2CR_TXFIE_Msk                           /*!< Processor M0+ Transmit channel free interrupt enable */

/**********************  Bit definition for IPCC_C2MR register  ***************/
#define IPCC_C2MR_CH1OM_Pos      (0U)
#define IPCC_C2MR_CH1OM_Msk      (0x1UL << IPCC_C2MR_CH1OM_Pos)                /*!< 0x00000001 */
#define IPCC_C2MR_CH1OM          IPCC_C2MR_CH1OM_Msk                           /*!< M0+ Channel1 occupied interrupt mask */
#define IPCC_C2MR_CH2OM_Pos      (1U)
#define IPCC_C2MR_CH2OM_Msk      (0x1UL << IPCC_C2MR_CH2OM_Pos)                /*!< 0x00000002 */
#define IPCC_C2MR_CH2OM          IPCC_C2MR_CH2OM_Msk                           /*!< M0+ Channel2 occupied interrupt mask */
#define IPCC_C2MR_CH3OM_Pos      (2U)
#define IPCC_C2MR_CH3OM_Msk      (0x1UL << IPCC_C2MR_CH3OM_Pos)                /*!< 0x00000004 */
#define IPCC_C2MR_CH3OM          IPCC_C2MR_CH3OM_Msk                           /*!< M0+ Channel3 occupied interrupt mask */
#define IPCC_C2MR_CH4OM_Pos      (3U)
#define IPCC_C2MR_CH4OM_Msk      (0x1UL << IPCC_C2MR_CH4OM_Pos)                /*!< 0x00000008 */
#define IPCC_C2MR_CH4OM          IPCC_C2MR_CH4OM_Msk                           /*!< M0+ Channel4 occupied interrupt mask */
#define IPCC_C2MR_CH5OM_Pos      (4U)
#define IPCC_C2MR_CH5OM_Msk      (0x1UL << IPCC_C2MR_CH5OM_Pos)                /*!< 0x00000010 */
#define IPCC_C2MR_CH5OM          IPCC_C2MR_CH5OM_Msk                           /*!< M0+ Channel5 occupied interrupt mask */
#define IPCC_C2MR_CH6OM_Pos      (5U)
#define IPCC_C2MR_CH6OM_Msk      (0x1UL << IPCC_C2MR_CH6OM_Pos)                /*!< 0x00000020 */
#define IPCC_C2MR_CH6OM          IPCC_C2MR_CH6OM_Msk                           /*!< M0+ Channel6 occupied interrupt mask */

#define IPCC_C2MR_CH1FM_Pos      (16U)
#define IPCC_C2MR_CH1FM_Msk      (0x1UL << IPCC_C2MR_CH1FM_Pos)                /*!< 0x00010000 */
#define IPCC_C2MR_CH1FM          IPCC_C2MR_CH1FM_Msk                           /*!< M0+ Transmit Channel1 free interrupt mask */
#define IPCC_C2MR_CH2FM_Pos      (17U)
#define IPCC_C2MR_CH2FM_Msk      (0x1UL << IPCC_C2MR_CH2FM_Pos)                /*!< 0x00020000 */
#define IPCC_C2MR_CH2FM          IPCC_C2MR_CH2FM_Msk                           /*!< M0+ Transmit Channel2 free interrupt mask */
#define IPCC_C2MR_CH3FM_Pos      (18U)
#define IPCC_C2MR_CH3FM_Msk      (0x1UL << IPCC_C2MR_CH3FM_Pos)                /*!< 0x00040000 */
#define IPCC_C2MR_CH3FM          IPCC_C2MR_CH3FM_Msk                           /*!< M0+ Transmit Channel3 free interrupt mask */
#define IPCC_C2MR_CH4FM_Pos      (19U)
#define IPCC_C2MR_CH4FM_Msk      (0x1UL << IPCC_C2MR_CH4FM_Pos)                /*!< 0x00080000 */
#define IPCC_C2MR_CH4FM          IPCC_C2MR_CH4FM_Msk                           /*!< M0+ Transmit Channel4 free interrupt mask */
#define IPCC_C2MR_CH5FM_Pos      (20U)
#define IPCC_C2MR_CH5FM_Msk      (0x1UL << IPCC_C2MR_CH5FM_Pos)                /*!< 0x00100000 */
#define IPCC_C2MR_CH5FM          IPCC_C2MR_CH5FM_Msk                           /*!< M0+ Transmit Channel5 free interrupt mask */
#define IPCC_C2MR_CH6FM_Pos      (21U)
#define IPCC_C2MR_CH6FM_Msk      (0x1UL << IPCC_C2MR_CH6FM_Pos)                /*!< 0x00200000 */
#define IPCC_C2MR_CH6FM          IPCC_C2MR_CH6FM_Msk                           /*!< M0+ Transmit Channel6 free interrupt mask */

/**********************  Bit definition for IPCC_C2SCR register  ***************/
#define IPCC_C2SCR_CH1C_Pos      (0U)
#define IPCC_C2SCR_CH1C_Msk      (0x1UL << IPCC_C2SCR_CH1C_Pos)                /*!< 0x00000001 */
#define IPCC_C2SCR_CH1C          IPCC_C2SCR_CH1C_Msk                           /*!< M0+ receive Channel1 status clear */
#define IPCC_C2SCR_CH2C_Pos      (1U)
#define IPCC_C2SCR_CH2C_Msk      (0x1UL << IPCC_C2SCR_CH2C_Pos)                /*!< 0x00000002 */
#define IPCC_C2SCR_CH2C          IPCC_C2SCR_CH2C_Msk                           /*!< M0+ receive Channel2 status clear */
#define IPCC_C2SCR_CH3C_Pos      (2U)
#define IPCC_C2SCR_CH3C_Msk      (0x1UL << IPCC_C2SCR_CH3C_Pos)                /*!< 0x00000004 */
#define IPCC_C2SCR_CH3C          IPCC_C2SCR_CH3C_Msk                           /*!< M0+ receive Channel3 status clear */
#define IPCC_C2SCR_CH4C_Pos      (3U)
#define IPCC_C2SCR_CH4C_Msk      (0x1UL << IPCC_C2SCR_CH4C_Pos)                /*!< 0x00000008 */
#define IPCC_C2SCR_CH4C          IPCC_C2SCR_CH4C_Msk                           /*!< M0+ receive Channel4 status clear */
#define IPCC_C2SCR_CH5C_Pos      (4U)
#define IPCC_C2SCR_CH5C_Msk      (0x1UL << IPCC_C2SCR_CH5C_Pos)                /*!< 0x00000010 */
#define IPCC_C2SCR_CH5C          IPCC_C2SCR_CH5C_Msk                           /*!< M0+ receive Channel5 status clear */
#define IPCC_C2SCR_CH6C_Pos      (5U)
#define IPCC_C2SCR_CH6C_Msk      (0x1UL << IPCC_C2SCR_CH6C_Pos)                /*!< 0x00000020 */
#define IPCC_C2SCR_CH6C          IPCC_C2SCR_CH6C_Msk                           /*!< M0+ receive Channel6 status clear */

#define IPCC_C2SCR_CH1S_Pos      (16U)
#define IPCC_C2SCR_CH1S_Msk      (0x1UL << IPCC_C2SCR_CH1S_Pos)                /*!< 0x00010000 */
#define IPCC_C2SCR_CH1S          IPCC_C2SCR_CH1S_Msk                           /*!< M0+ transmit Channel1 status set  */
#define IPCC_C2SCR_CH2S_Pos      (17U)
#define IPCC_C2SCR_CH2S_Msk      (0x1UL << IPCC_C2SCR_CH2S_Pos)                /*!< 0x00020000 */
#define IPCC_C2SCR_CH2S          IPCC_C2SCR_CH2S_Msk                           /*!< M0+ transmit Channel2 status set  */
#define IPCC_C2SCR_CH3S_Pos      (18U)
#define IPCC_C2SCR_CH3S_Msk      (0x1UL << IPCC_C2SCR_CH3S_Pos)                /*!< 0x00040000 */
#define IPCC_C2SCR_CH3S          IPCC_C2SCR_CH3S_Msk                           /*!< M0+ transmit Channel3 status set  */
#define IPCC_C2SCR_CH4S_Pos      (19U)
#define IPCC_C2SCR_CH4S_Msk      (0x1UL << IPCC_C2SCR_CH4S_Pos)                /*!< 0x00080000 */
#define IPCC_C2SCR_CH4S          IPCC_C2SCR_CH4S_Msk                           /*!< M0+ transmit Channel4 status set  */
#define IPCC_C2SCR_CH5S_Pos      (20U)
#define IPCC_C2SCR_CH5S_Msk      (0x1UL << IPCC_C2SCR_CH5S_Pos)                /*!< 0x00100000 */
#define IPCC_C2SCR_CH5S          IPCC_C2SCR_CH5S_Msk                           /*!< M0+ transmit Channel5 status set  */
#define IPCC_C2SCR_CH6S_Pos      (21U)
#define IPCC_C2SCR_CH6S_Msk      (0x1UL << IPCC_C2SCR_CH6S_Pos)                /*!< 0x00200000 */
#define IPCC_C2SCR_CH6S          IPCC_C2SCR_CH6S_Msk                           /*!< M0+ transmit Channel6 status set  */

/**********************  Bit definition for IPCC_C2TOC1SR register  ***************/
#define IPCC_C2TOC1SR_CH1F_Pos    (0U)
#define IPCC_C2TOC1SR_CH1F_Msk    (0x1UL << IPCC_C2TOC1SR_CH1F_Pos)            /*!< 0x00000001 */
#define IPCC_C2TOC1SR_CH1F        IPCC_C2TOC1SR_CH1F_Msk                       /*!< M0+ transmit to M0 receive Channel1 status flag before masking */
#define IPCC_C2TOC1SR_CH2F_Pos    (1U)
#define IPCC_C2TOC1SR_CH2F_Msk    (0x1UL << IPCC_C2TOC1SR_CH2F_Pos)            /*!< 0x00000002 */
#define IPCC_C2TOC1SR_CH2F        IPCC_C2TOC1SR_CH2F_Msk                       /*!< M0+ transmit to M0 receive Channel2 status flag before masking */
#define IPCC_C2TOC1SR_CH3F_Pos    (2U)
#define IPCC_C2TOC1SR_CH3F_Msk    (0x1UL << IPCC_C2TOC1SR_CH3F_Pos)            /*!< 0x00000004 */
#define IPCC_C2TOC1SR_CH3F        IPCC_C2TOC1SR_CH3F_Msk                       /*!< M0+ transmit to M0 receive Channel3 status flag before masking */
#define IPCC_C2TOC1SR_CH4F_Pos    (3U)
#define IPCC_C2TOC1SR_CH4F_Msk    (0x1UL << IPCC_C2TOC1SR_CH4F_Pos)            /*!< 0x00000008 */
#define IPCC_C2TOC1SR_CH4F        IPCC_C2TOC1SR_CH4F_Msk                       /*!< M0+ transmit to M0 receive Channel4 status flag before masking */
#define IPCC_C2TOC1SR_CH5F_Pos    (4U)
#define IPCC_C2TOC1SR_CH5F_Msk    (0x1UL << IPCC_C2TOC1SR_CH5F_Pos)            /*!< 0x00000010 */
#define IPCC_C2TOC1SR_CH5F        IPCC_C2TOC1SR_CH5F_Msk                       /*!< M0+ transmit to M0 receive Channel5 status flag before masking */
#define IPCC_C2TOC1SR_CH6F_Pos    (5U)
#define IPCC_C2TOC1SR_CH6F_Msk    (0x1UL << IPCC_C2TOC1SR_CH6F_Pos)            /*!< 0x00000020 */
#define IPCC_C2TOC1SR_CH6F        IPCC_C2TOC1SR_CH6F_Msk                       /*!< M0+ transmit to M0 receive Channel6 status flag before masking */

/**********************  Bit definition for IPCC_C1CR register  ***************/
#define IPCC_CR_RXOIE_Pos         IPCC_C1CR_RXOIE_Pos
#define IPCC_CR_RXOIE_Msk         IPCC_C1CR_RXOIE_Msk
#define IPCC_CR_RXOIE             IPCC_C1CR_RXOIE
#define IPCC_CR_TXFIE_Pos         IPCC_C1CR_TXFIE_Pos
#define IPCC_CR_TXFIE_Msk         IPCC_C1CR_TXFIE_Msk
#define IPCC_CR_TXFIE             IPCC_C1CR_TXFIE

/**********************  Bit definition for IPCC_C1MR register  **************/
#define IPCC_MR_CH1OM_Pos         IPCC_C1MR_CH1OM_Pos
#define IPCC_MR_CH1OM_Msk         IPCC_C1MR_CH1OM_Msk
#define IPCC_MR_CH1OM             IPCC_C1MR_CH1OM
#define IPCC_MR_CH2OM_Pos         IPCC_C1MR_CH2OM_Pos
#define IPCC_MR_CH2OM_Msk         IPCC_C1MR_CH2OM_Msk
#define IPCC_MR_CH2OM             IPCC_C1MR_CH2OM
#define IPCC_MR_CH3OM_Pos         IPCC_C1MR_CH3OM_Pos
#define IPCC_MR_CH3OM_Msk         IPCC_C1MR_CH3OM_Msk
#define IPCC_MR_CH3OM             IPCC_C1MR_CH3OM
#define IPCC_MR_CH4OM_Pos         IPCC_C1MR_CH4OM_Pos
#define IPCC_MR_CH4OM_Msk         IPCC_C1MR_CH4OM_Msk
#define IPCC_MR_CH4OM             IPCC_C1MR_CH4OM
#define IPCC_MR_CH5OM_Pos         IPCC_C1MR_CH5OM_Pos
#define IPCC_MR_CH5OM_Msk         IPCC_C1MR_CH5OM_Msk
#define IPCC_MR_CH5OM             IPCC_C1MR_CH5OM
#define IPCC_MR_CH6OM_Pos         IPCC_C1MR_CH6OM_Pos
#define IPCC_MR_CH6OM_Msk         IPCC_C1MR_CH6OM_Msk
#define IPCC_MR_CH6OM             IPCC_C1MR_CH6OM

#define IPCC_MR_CH1FM_Pos         IPCC_C1MR_CH1FM_Pos
#define IPCC_MR_CH1FM_Msk         IPCC_C1MR_CH1FM_Msk
#define IPCC_MR_CH1FM             IPCC_C1MR_CH1FM
#define IPCC_MR_CH2FM_Pos         IPCC_C1MR_CH2FM_Pos
#define IPCC_MR_CH2FM_Msk         IPCC_C1MR_CH2FM_Msk
#define IPCC_MR_CH2FM             IPCC_C1MR_CH2FM
#define IPCC_MR_CH3FM_Pos         IPCC_C1MR_CH3FM_Pos
#define IPCC_MR_CH3FM_Msk         IPCC_C1MR_CH3FM_Msk
#define IPCC_MR_CH3FM             IPCC_C1MR_CH3FM
#define IPCC_MR_CH4FM_Pos         IPCC_C1MR_CH4FM_Pos
#define IPCC_MR_CH4FM_Msk         IPCC_C1MR_CH4FM_Msk
#define IPCC_MR_CH4FM             IPCC_C1MR_CH4FM
#define IPCC_MR_CH5FM_Pos         IPCC_C1MR_CH5FM_Pos
#define IPCC_MR_CH5FM_Msk         IPCC_C1MR_CH5FM_Msk
#define IPCC_MR_CH5FM             IPCC_C1MR_CH5FM
#define IPCC_MR_CH6FM_Pos         IPCC_C1MR_CH6FM_Pos
#define IPCC_MR_CH6FM_Msk         IPCC_C1MR_CH6FM_Msk
#define IPCC_MR_CH6FM             IPCC_C1MR_CH6FM

/**********************  Bit definition for IPCC_C1SCR register  ***************/
#define IPCC_SCR_CH1C_Pos         IPCC_C1SCR_CH1C_Pos
#define IPCC_SCR_CH1C_Msk         IPCC_C1SCR_CH1C_Msk
#define IPCC_SCR_CH1C             IPCC_C1SCR_CH1C
#define IPCC_SCR_CH2C_Pos         IPCC_C1SCR_CH2C_Pos
#define IPCC_SCR_CH2C_Msk         IPCC_C1SCR_CH2C_Msk
#define IPCC_SCR_CH2C             IPCC_C1SCR_CH2C
#define IPCC_SCR_CH3C_Pos         IPCC_C1SCR_CH3C_Pos
#define IPCC_SCR_CH3C_Msk         IPCC_C1SCR_CH3C_Msk
#define IPCC_SCR_CH3C             IPCC_C1SCR_CH3C
#define IPCC_SCR_CH4C_Pos         IPCC_C1SCR_CH4C_Pos
#define IPCC_SCR_CH4C_Msk         IPCC_C1SCR_CH4C_Msk
#define IPCC_SCR_CH4C             IPCC_C1SCR_CH4C
#define IPCC_SCR_CH5C_Pos         IPCC_C1SCR_CH5C_Pos
#define IPCC_SCR_CH5C_Msk         IPCC_C1SCR_CH5C_Msk
#define IPCC_SCR_CH5C             IPCC_C1SCR_CH5C
#define IPCC_SCR_CH6C_Pos         IPCC_C1SCR_CH6C_Pos
#define IPCC_SCR_CH6C_Msk         IPCC_C1SCR_CH6C_Msk
#define IPCC_SCR_CH6C             IPCC_C1SCR_CH6C

#define IPCC_SCR_CH1S_Pos         IPCC_C1SCR_CH1S_Pos
#define IPCC_SCR_CH1S_Msk         IPCC_C1SCR_CH1S_Msk
#define IPCC_SCR_CH1S             IPCC_C1SCR_CH1S
#define IPCC_SCR_CH2S_Pos         IPCC_C1SCR_CH2S_Pos
#define IPCC_SCR_CH2S_Msk         IPCC_C1SCR_CH2S_Msk
#define IPCC_SCR_CH2S             IPCC_C1SCR_CH2S
#define IPCC_SCR_CH3S_Pos         IPCC_C1SCR_CH3S_Pos
#define IPCC_SCR_CH3S_Msk         IPCC_C1SCR_CH3S_Msk
#define IPCC_SCR_CH3S             IPCC_C1SCR_CH3S
#define IPCC_SCR_CH4S_Pos         IPCC_C1SCR_CH4S_Pos
#define IPCC_SCR_CH4S_Msk         IPCC_C1SCR_CH4S_Msk
#define IPCC_SCR_CH4S             IPCC_C1SCR_CH4S
#define IPCC_SCR_CH5S_Pos         IPCC_C1SCR_CH5S_Pos
#define IPCC_SCR_CH5S_Msk         IPCC_C1SCR_CH5S_Msk
#define IPCC_SCR_CH5S             IPCC_C1SCR_CH5S
#define IPCC_SCR_CH6S_Pos         IPCC_C1SCR_CH6S_Pos
#define IPCC_SCR_CH6S_Msk         IPCC_C1SCR_CH6S_Msk
#define IPCC_SCR_CH6S             IPCC_C1SCR_CH6S

/**********************  Bit definition for IPCC_C1TOC2SR register  ***************/
#define IPCC_SR_CH1F_Pos          IPCC_C1TOC2SR_CH1F_Pos
#define IPCC_SR_CH1F_Msk          IPCC_C1TOC2SR_CH1F_Msk
#define IPCC_SR_CH1F              IPCC_C1TOC2SR_CH1F
#define IPCC_SR_CH2F_Pos          IPCC_C1TOC2SR_CH2F_Pos
#define IPCC_SR_CH2F_Msk          IPCC_C1TOC2SR_CH2F_Msk
#define IPCC_SR_CH2F              IPCC_C1TOC2SR_CH2F
#define IPCC_SR_CH3F_Pos          IPCC_C1TOC2SR_CH3F_Pos
#define IPCC_SR_CH3F_Msk          IPCC_C1TOC2SR_CH3F_Msk
#define IPCC_SR_CH3F              IPCC_C1TOC2SR_CH3F
#define IPCC_SR_CH4F_Pos          IPCC_C1TOC2SR_CH4F_Pos
#define IPCC_SR_CH4F_Msk          IPCC_C1TOC2SR_CH4F_Msk
#define IPCC_SR_CH4F              IPCC_C1TOC2SR_CH4F
#define IPCC_SR_CH5F_Pos          IPCC_C1TOC2SR_CH5F_Pos
#define IPCC_SR_CH5F_Msk          IPCC_C1TOC2SR_CH5F_Msk
#define IPCC_SR_CH5F              IPCC_C1TOC2SR_CH5F
#define IPCC_SR_CH6F_Pos          IPCC_C1TOC2SR_CH6F_Pos
#define IPCC_SR_CH6F_Msk          IPCC_C1TOC2SR_CH6F_Msk
#define IPCC_SR_CH6F              IPCC_C1TOC2SR_CH6F

/******************** Number of IPCC channels ******************************/
#define IPCC_CHANNEL_NUMBER       6U

/******************************************************************************/
/*                                                                            */
/*      Universal Synchronous Asynchronous Receiver Transmitter (USART)       */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for USART_CR1 register  *******************/
#define USART_CR1_UE_Pos                (0U)
#define USART_CR1_UE_Msk                (0x1UL << USART_CR1_UE_Pos)            /*!< 0x00000001 */
#define USART_CR1_UE                    USART_CR1_UE_Msk                        /*!< USART Enable */
#define USART_CR1_UESM_Pos              (1U)
#define USART_CR1_UESM_Msk              (0x1UL << USART_CR1_UESM_Pos)           /*!< 0x00000002 */
#define USART_CR1_UESM                  USART_CR1_UESM_Msk                      /*!< USART Enable in STOP Mode */
#define USART_CR1_RE_Pos                (2U)
#define USART_CR1_RE_Msk                (0x1UL << USART_CR1_RE_Pos)             /*!< 0x00000004 */
#define USART_CR1_RE                    USART_CR1_RE_Msk                        /*!< Receiver Enable */
#define USART_CR1_TE_Pos                (3U)
#define USART_CR1_TE_Msk                (0x1UL << USART_CR1_TE_Pos)             /*!< 0x00000008 */
#define USART_CR1_TE                    USART_CR1_TE_Msk                        /*!< Transmitter Enable */
#define USART_CR1_IDLEIE_Pos            (4U)
#define USART_CR1_IDLEIE_Msk            (0x1UL << USART_CR1_IDLEIE_Pos)         /*!< 0x00000010 */
#define USART_CR1_IDLEIE                USART_CR1_IDLEIE_Msk                    /*!< IDLE Interrupt Enable */
#define USART_CR1_RXNEIE_Pos            (5U)
#define USART_CR1_RXNEIE_Msk            (0x1UL << USART_CR1_RXNEIE_Pos)         /*!< 0x00000020 */
#define USART_CR1_RXNEIE                USART_CR1_RXNEIE_Msk                    /*!< RXNE Interrupt Enable */
#define USART_CR1_RXNEIE_RXFNEIE_Pos    USART_CR1_RXNEIE_Pos
#define USART_CR1_RXNEIE_RXFNEIE_Msk    USART_CR1_RXNEIE_Msk                    /*!< 0x00000020 */
#define USART_CR1_RXNEIE_RXFNEIE        USART_CR1_RXNEIE_Msk                    /*!< RXNE and RX FIFO Not Empty Interrupt Enable */
#define USART_CR1_TCIE_Pos              (6U)
#define USART_CR1_TCIE_Msk              (0x1UL << USART_CR1_TCIE_Pos)           /*!< 0x00000040 */
#define USART_CR1_TCIE                  USART_CR1_TCIE_Msk                      /*!< Transmission Complete Interrupt Enable */
#define USART_CR1_TXEIE_Pos             (7U)
#define USART_CR1_TXEIE_Msk             (0x1UL << USART_CR1_TXEIE_Pos)          /*!< 0x00000080 */
#define USART_CR1_TXEIE                 USART_CR1_TXEIE_Msk                     /*!< TXE Interrupt Enable */
#define USART_CR1_TXEIE_TXFNFIE_Pos     (7U)
#define USART_CR1_TXEIE_TXFNFIE_Msk     (0x1UL << USART_CR1_TXEIE_Pos)          /*!< 0x00000080 */
#define USART_CR1_TXEIE_TXFNFIE         USART_CR1_TXEIE                         /*!< TXE and TX FIFO Not Full Interrupt Enable */
#define USART_CR1_PEIE_Pos              (8U)
#define USART_CR1_PEIE_Msk              (0x1UL << USART_CR1_PEIE_Pos)           /*!< 0x00000100 */
#define USART_CR1_PEIE                  USART_CR1_PEIE_Msk                      /*!< PE Interrupt Enable */
#define USART_CR1_PS_Pos                (9U)
#define USART_CR1_PS_Msk                (0x1UL << USART_CR1_PS_Pos)             /*!< 0x00000200 */
#define USART_CR1_PS                    USART_CR1_PS_Msk                        /*!< Parity Selection */
#define USART_CR1_PCE_Pos               (10U)
#define USART_CR1_PCE_Msk               (0x1UL << USART_CR1_PCE_Pos)            /*!< 0x00000400 */
#define USART_CR1_PCE                   USART_CR1_PCE_Msk                       /*!< Parity Control Enable */
#define USART_CR1_WAKE_Pos              (11U)
#define USART_CR1_WAKE_Msk              (0x1UL << USART_CR1_WAKE_Pos)           /*!< 0x00000800 */
#define USART_CR1_WAKE                  USART_CR1_WAKE_Msk                      /*!< Receiver Wakeup method */
#define USART_CR1_M0_Pos                (12U)
#define USART_CR1_M0_Msk                (0x1UL << USART_CR1_M0_Pos)             /*!< 0x00001000 */
#define USART_CR1_M0                    USART_CR1_M0_Msk                        /*!< Word length - Bit 0 */
#define USART_CR1_MME_Pos               (13U)
#define USART_CR1_MME_Msk               (0x1UL << USART_CR1_MME_Pos)            /*!< 0x00002000 */
#define USART_CR1_MME                   USART_CR1_MME_Msk                       /*!< Mute Mode Enable */
#define USART_CR1_CMIE_Pos              (14U)
#define USART_CR1_CMIE_Msk              (0x1UL << USART_CR1_CMIE_Pos)           /*!< 0x00004000 */
#define USART_CR1_CMIE                  USART_CR1_CMIE_Msk                      /*!< Character match interrupt enable */
#define USART_CR1_OVER8_Pos             (15U)
#define USART_CR1_OVER8_Msk             (0x1UL << USART_CR1_OVER8_Pos)          /*!< 0x00008000 */
#define USART_CR1_OVER8                 USART_CR1_OVER8_Msk                     /*!< Oversampling by 8-bit or 16-bit mode */
#define USART_CR1_DEDT_Pos              (16U)
#define USART_CR1_DEDT_Msk              (0x1FUL << USART_CR1_DEDT_Pos)          /*!< 0x001F0000 */
#define USART_CR1_DEDT                  USART_CR1_DEDT_Msk                      /*!< DEDT[4:0] bits (Driver Enable Deassertion Time) */
#define USART_CR1_DEDT_0                (0x01U << USART_CR1_DEDT_Pos)           /*!< 0x00010000 */
#define USART_CR1_DEDT_1                (0x02U << USART_CR1_DEDT_Pos)           /*!< 0x00020000 */
#define USART_CR1_DEDT_2                (0x04U << USART_CR1_DEDT_Pos)           /*!< 0x00040000 */
#define USART_CR1_DEDT_3                (0x08U << USART_CR1_DEDT_Pos)           /*!< 0x00080000 */
#define USART_CR1_DEDT_4                (0x10U << USART_CR1_DEDT_Pos)           /*!< 0x00100000 */
#define USART_CR1_DEAT_Pos              (21U)
#define USART_CR1_DEAT_Msk              (0x1FUL << USART_CR1_DEAT_Pos)          /*!< 0x03E00000 */
#define USART_CR1_DEAT                  USART_CR1_DEAT_Msk                      /*!< DEAT[4:0] bits (Driver Enable Assertion Time) */
#define USART_CR1_DEAT_0                (0x01U << USART_CR1_DEAT_Pos)           /*!< 0x00200000 */
#define USART_CR1_DEAT_1                (0x02U << USART_CR1_DEAT_Pos)           /*!< 0x00400000 */
#define USART_CR1_DEAT_2                (0x04U << USART_CR1_DEAT_Pos)           /*!< 0x00800000 */
#define USART_CR1_DEAT_3                (0x08U << USART_CR1_DEAT_Pos)           /*!< 0x01000000 */
#define USART_CR1_DEAT_4                (0x10U << USART_CR1_DEAT_Pos)           /*!< 0x02000000 */
#define USART_CR1_RTOIE_Pos             (26U)
#define USART_CR1_RTOIE_Msk             (0x1UL << USART_CR1_RTOIE_Pos)          /*!< 0x04000000 */
#define USART_CR1_RTOIE                 USART_CR1_RTOIE_Msk                     /*!< Receive Time Out Interrupt Enable */
#define USART_CR1_EOBIE_Pos             (27U)
#define USART_CR1_EOBIE_Msk             (0x1UL << USART_CR1_EOBIE_Pos)          /*!< 0x08000000 */
#define USART_CR1_EOBIE                 USART_CR1_EOBIE_Msk                     /*!< End of Block Interrupt Enable */
#define USART_CR1_M1_Pos                (28U)
#define USART_CR1_M1_Msk                (0x1UL << USART_CR1_M1_Pos)             /*!< 0x10000000 */
#define USART_CR1_M1                    USART_CR1_M1_Msk                        /*!< Word length - Bit 1 */
#define USART_CR1_M                     (uint32_t)(USART_CR1_M1 | USART_CR1_M0) /*!< Word length */
#define USART_CR1_FIFOEN_Pos            (29U)
#define USART_CR1_FIFOEN_Msk            (0x1UL << USART_CR1_FIFOEN_Pos)         /*!< 0x20000000 */
#define USART_CR1_FIFOEN                USART_CR1_FIFOEN_Msk                    /*!< FIFO mode enable */
#define USART_CR1_TXFEIE_Pos            (30U)
#define USART_CR1_TXFEIE_Msk            (0x1UL << USART_CR1_TXFEIE_Pos)         /*!< 0x40000000 */
#define USART_CR1_TXFEIE                USART_CR1_TXFEIE_Msk                    /*!< TX FIFO Empty Interrupt Enable */
#define USART_CR1_RXFFIE_Pos            (31U)
#define USART_CR1_RXFFIE_Msk            (0x1UL << USART_CR1_RXFFIE_Pos)         /*!< 0x80000000 */
#define USART_CR1_RXFFIE                USART_CR1_RXFFIE_Msk                    /*!< RX FIFO Full Interrupt Enable */

/******************  Bit definition for USART_CR2 register  *******************/
#define USART_CR2_SLVEN_Pos             (0U)
#define USART_CR2_SLVEN_Msk             (0x1UL << USART_CR2_SLVEN_Pos)          /*!< 0x00000001 */
#define USART_CR2_SLVEN                 USART_CR2_SLVEN_Msk                     /*!< Synchronous Slave mode enable */
#define USART_CR2_DIS_NSS_Pos           (3U)
#define USART_CR2_DIS_NSS_Msk           (0x1UL << USART_CR2_DIS_NSS_Pos)        /*!< 0x00000008 */
#define USART_CR2_DIS_NSS               USART_CR2_DIS_NSS_Msk                   /*!< Slave Select (NSS) pin management */
#define USART_CR2_ADDM7_Pos             (4U)
#define USART_CR2_ADDM7_Msk             (0x1UL << USART_CR2_ADDM7_Pos)          /*!< 0x00000010 */
#define USART_CR2_ADDM7                 USART_CR2_ADDM7_Msk                     /*!< 7-bit or 4-bit Address Detection */
#define USART_CR2_LBDL_Pos              (5U)
#define USART_CR2_LBDL_Msk              (0x1UL << USART_CR2_LBDL_Pos)           /*!< 0x00000020 */
#define USART_CR2_LBDL                  USART_CR2_LBDL_Msk                      /*!< LIN Break Detection Length */
#define USART_CR2_LBDIE_Pos             (6U)
#define USART_CR2_LBDIE_Msk             (0x1UL << USART_CR2_LBDIE_Pos)          /*!< 0x00000040 */
#define USART_CR2_LBDIE                 USART_CR2_LBDIE_Msk                     /*!< LIN Break Detection Interrupt Enable */
#define USART_CR2_LBCL_Pos              (8U)
#define USART_CR2_LBCL_Msk              (0x1UL << USART_CR2_LBCL_Pos)           /*!< 0x00000100 */
#define USART_CR2_LBCL                  USART_CR2_LBCL_Msk                      /*!< Last Bit Clock pulse */
#define USART_CR2_CPHA_Pos              (9U)
#define USART_CR2_CPHA_Msk              (0x1UL << USART_CR2_CPHA_Pos)           /*!< 0x00000200 */
#define USART_CR2_CPHA                  USART_CR2_CPHA_Msk                      /*!< Clock Phase */
#define USART_CR2_CPOL_Pos              (10U)
#define USART_CR2_CPOL_Msk              (0x1UL << USART_CR2_CPOL_Pos)           /*!< 0x00000400 */
#define USART_CR2_CPOL                  USART_CR2_CPOL_Msk                      /*!< Clock Polarity */
#define USART_CR2_CLKEN_Pos             (11U)
#define USART_CR2_CLKEN_Msk             (0x1UL << USART_CR2_CLKEN_Pos)          /*!< 0x00000800 */
#define USART_CR2_CLKEN                 USART_CR2_CLKEN_Msk                     /*!< Clock Enable */
#define USART_CR2_STOP_Pos              (12U)
#define USART_CR2_STOP_Msk              (0x3UL << USART_CR2_STOP_Pos)           /*!< 0x00003000 */
#define USART_CR2_STOP                  USART_CR2_STOP_Msk                      /*!< STOP[1:0] bits (STOP bits) */
#define USART_CR2_STOP_0                (0x1U << USART_CR2_STOP_Pos)            /*!< 0x00001000 */
#define USART_CR2_STOP_1                (0x2U << USART_CR2_STOP_Pos)            /*!< 0x00002000 */
#define USART_CR2_LINEN_Pos             (14U)
#define USART_CR2_LINEN_Msk             (0x1UL << USART_CR2_LINEN_Pos)          /*!< 0x00004000 */
#define USART_CR2_LINEN                 USART_CR2_LINEN_Msk                     /*!< LIN mode enable */
#define USART_CR2_SWAP_Pos              (15U)
#define USART_CR2_SWAP_Msk              (0x1UL << USART_CR2_SWAP_Pos)           /*!< 0x00008000 */
#define USART_CR2_SWAP                  USART_CR2_SWAP_Msk                      /*!< SWAP TX/RX pins */
#define USART_CR2_RXINV_Pos             (16U)
#define USART_CR2_RXINV_Msk             (0x1UL << USART_CR2_RXINV_Pos)          /*!< 0x00010000 */
#define USART_CR2_RXINV                 USART_CR2_RXINV_Msk                     /*!< RX pin active level inversion */
#define USART_CR2_TXINV_Pos             (17U)
#define USART_CR2_TXINV_Msk             (0x1UL << USART_CR2_TXINV_Pos)          /*!< 0x00020000 */
#define USART_CR2_TXINV                 USART_CR2_TXINV_Msk                     /*!< TX pin active level inversion */
#define USART_CR2_DATAINV_Pos           (18U)
#define USART_CR2_DATAINV_Msk           (0x1UL << USART_CR2_DATAINV_Pos)        /*!< 0x00040000 */
#define USART_CR2_DATAINV               USART_CR2_DATAINV_Msk                   /*!< Binary data inversion */
#define USART_CR2_MSBFIRST_Pos          (19U)
#define USART_CR2_MSBFIRST_Msk          (0x1UL << USART_CR2_MSBFIRST_Pos)       /*!< 0x00080000 */
#define USART_CR2_MSBFIRST              USART_CR2_MSBFIRST_Msk                  /*!< Most Significant Bit First */
#define USART_CR2_ABREN_Pos             (20U)
#define USART_CR2_ABREN_Msk             (0x1UL << USART_CR2_ABREN_Pos)          /*!< 0x00100000 */
#define USART_CR2_ABREN                 USART_CR2_ABREN_Msk                     /*!< Auto Baud-Rate Enable*/
#define USART_CR2_ABRMODE_Pos           (21U)
#define USART_CR2_ABRMODE_Msk           (0x3UL << USART_CR2_ABRMODE_Pos)        /*!< 0x00600000 */
#define USART_CR2_ABRMODE               USART_CR2_ABRMODE_Msk                   /*!< ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
#define USART_CR2_ABRMODE_0             (0x1U << USART_CR2_ABRMODE_Pos)         /*!< 0x00200000 */
#define USART_CR2_ABRMODE_1             (0x2U << USART_CR2_ABRMODE_Pos)         /*!< 0x00400000 */
#define USART_CR2_RTOEN_Pos             (23U)
#define USART_CR2_RTOEN_Msk             (0x1UL << USART_CR2_RTOEN_Pos)          /*!< 0x00800000 */
#define USART_CR2_RTOEN                 USART_CR2_RTOEN_Msk                     /*!< Receiver Time-Out enable */
#define USART_CR2_ADD_Pos               (24U)
#define USART_CR2_ADD_Msk               (0xFFUL << USART_CR2_ADD_Pos)           /*!< 0xFF000000 */
#define USART_CR2_ADD                   USART_CR2_ADD_Msk                       /*!< Address of the USART node */

/******************  Bit definition for USART_CR3 register  *******************/
#define USART_CR3_EIE_Pos               (0U)
#define USART_CR3_EIE_Msk               (0x1UL << USART_CR3_EIE_Pos)            /*!< 0x00000001 */
#define USART_CR3_EIE                   USART_CR3_EIE_Msk                       /*!< Error Interrupt Enable */
#define USART_CR3_IREN_Pos              (1U)
#define USART_CR3_IREN_Msk              (0x1UL << USART_CR3_IREN_Pos)           /*!< 0x00000002 */
#define USART_CR3_IREN                  USART_CR3_IREN_Msk                      /*!< IrDA mode Enable */
#define USART_CR3_IRLP_Pos              (2U)
#define USART_CR3_IRLP_Msk              (0x1UL << USART_CR3_IRLP_Pos)           /*!< 0x00000004 */
#define USART_CR3_IRLP                  USART_CR3_IRLP_Msk                      /*!< IrDA Low-Power */
#define USART_CR3_HDSEL_Pos             (3U)
#define USART_CR3_HDSEL_Msk             (0x1UL << USART_CR3_HDSEL_Pos)          /*!< 0x00000008 */
#define USART_CR3_HDSEL                 USART_CR3_HDSEL_Msk                     /*!< Half-Duplex Selection */
#define USART_CR3_NACK_Pos              (4U)
#define USART_CR3_NACK_Msk              (0x1UL << USART_CR3_NACK_Pos)           /*!< 0x00000010 */
#define USART_CR3_NACK                  USART_CR3_NACK_Msk                      /*!< SmartCard NACK enable */
#define USART_CR3_SCEN_Pos              (5U)
#define USART_CR3_SCEN_Msk              (0x1UL << USART_CR3_SCEN_Pos)           /*!< 0x00000020 */
#define USART_CR3_SCEN                  USART_CR3_SCEN_Msk                      /*!< SmartCard mode enable */
#define USART_CR3_DMAR_Pos              (6U)
#define USART_CR3_DMAR_Msk              (0x1UL << USART_CR3_DMAR_Pos)           /*!< 0x00000040 */
#define USART_CR3_DMAR                  USART_CR3_DMAR_Msk                      /*!< DMA Enable Receiver */
#define USART_CR3_DMAT_Pos              (7U)
#define USART_CR3_DMAT_Msk              (0x1UL << USART_CR3_DMAT_Pos)           /*!< 0x00000080 */
#define USART_CR3_DMAT                  USART_CR3_DMAT_Msk                      /*!< DMA Enable Transmitter */
#define USART_CR3_RTSE_Pos              (8U)
#define USART_CR3_RTSE_Msk              (0x1UL << USART_CR3_RTSE_Pos)           /*!< 0x00000100 */
#define USART_CR3_RTSE                  USART_CR3_RTSE_Msk                      /*!< RTS Enable */
#define USART_CR3_CTSE_Pos              (9U)
#define USART_CR3_CTSE_Msk              (0x1UL << USART_CR3_CTSE_Pos)           /*!< 0x00000200 */
#define USART_CR3_CTSE                  USART_CR3_CTSE_Msk
#define USART_CR3_CTSIE_Pos             (10U)
#define USART_CR3_CTSIE_Msk             (0x1UL << USART_CR3_CTSIE_Pos)          /*!< 0x00000400 */
#define USART_CR3_CTSIE                 USART_CR3_CTSIE_Msk                     /*!< CTS Interrupt Enable */
#define USART_CR3_ONEBIT_Pos            (11U)
#define USART_CR3_ONEBIT_Msk            (0x1UL << USART_CR3_ONEBIT_Pos)         /*!< 0x00000800 */
#define USART_CR3_ONEBIT                USART_CR3_ONEBIT_Msk                    /*!< One sample bit method enable */
#define USART_CR3_OVRDIS_Pos            (12U)
#define USART_CR3_OVRDIS_Msk            (0x1UL << USART_CR3_OVRDIS_Pos)         /*!< 0x00001000 */
#define USART_CR3_OVRDIS                USART_CR3_OVRDIS_Msk                    /*!< Overrun Disable */
#define USART_CR3_DDRE_Pos              (13U)
#define USART_CR3_DDRE_Msk              (0x1UL << USART_CR3_DDRE_Pos)           /*!< 0x00002000 */
#define USART_CR3_DDRE                  USART_CR3_DDRE_Msk                      /*!< DMA Disable on Reception Error */
#define USART_CR3_DEM_Pos               (14U)
#define USART_CR3_DEM_Msk               (0x1UL << USART_CR3_DEM_Pos)            /*!< 0x00004000 */
#define USART_CR3_DEM                   USART_CR3_DEM_Msk                       /*!< Driver Enable Mode */
#define USART_CR3_DEP_Pos               (15U)
#define USART_CR3_DEP_Msk               (0x1UL << USART_CR3_DEP_Pos)            /*!< 0x00008000 */
#define USART_CR3_DEP                   USART_CR3_DEP_Msk                       /*!< Driver Enable Polarity Selection */
#define USART_CR3_SCARCNT_Pos           (17U)
#define USART_CR3_SCARCNT_Msk           (0x7UL << USART_CR3_SCARCNT_Pos)        /*!< 0x000E0000 */
#define USART_CR3_SCARCNT               USART_CR3_SCARCNT_Msk                   /*!< SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
#define USART_CR3_SCARCNT_0             (0x1U << USART_CR3_SCARCNT_Pos)         /*!< 0x00020000 */
#define USART_CR3_SCARCNT_1             (0x2U << USART_CR3_SCARCNT_Pos)         /*!< 0x00040000 */
#define USART_CR3_SCARCNT_2             (0x4U << USART_CR3_SCARCNT_Pos)         /*!< 0x00080000 */
#define USART_CR3_WUS_Pos               (20U)
#define USART_CR3_WUS_Msk               (0x3UL << USART_CR3_WUS_Pos)            /*!< 0x00300000 */
#define USART_CR3_WUS                   USART_CR3_WUS_Msk                       /*!< WUS[1:0] bits (Wake UP Interrupt Flag Selection) */
#define USART_CR3_WUS_0                 (0x1U << USART_CR3_WUS_Pos)             /*!< 0x00100000 */
#define USART_CR3_WUS_1                 (0x2U << USART_CR3_WUS_Pos)             /*!< 0x00200000 */
#define USART_CR3_WUFIE_Pos             (22U)
#define USART_CR3_WUFIE_Msk             (0x1UL << USART_CR3_WUFIE_Pos)          /*!< 0x00400000 */
#define USART_CR3_WUFIE                 USART_CR3_WUFIE_Msk                     /*!< Wake Up Interrupt Enable */
#define USART_CR3_TXFTIE_Pos            (23U)
#define USART_CR3_TXFTIE_Msk            (0x1UL << USART_CR3_TXFTIE_Pos)         /*!< 0x00800000 */
#define USART_CR3_TXFTIE                USART_CR3_TXFTIE_Msk                    /*!< TX FIFO Threshold Interrupt Enable */
#define USART_CR3_TCBGTIE_Pos           (24U)
#define USART_CR3_TCBGTIE_Msk           (0x1UL << USART_CR3_TCBGTIE_Pos)        /*!< 0x01000000 */
#define USART_CR3_TCBGTIE               USART_CR3_TCBGTIE_Msk                   /*!< Transmission Complete Before Guard Time Interrupt Enable */
#define USART_CR3_RXFTCFG_Pos           (25U)
#define USART_CR3_RXFTCFG_Msk           (0x7UL << USART_CR3_RXFTCFG_Pos)        /*!< 0x0E000000 */
#define USART_CR3_RXFTCFG               USART_CR3_RXFTCFG_Msk                   /*!< RX FIFO Threshold Configuration */
#define USART_CR3_RXFTCFG_0             (0x1U << USART_CR3_RXFTCFG_Pos)         /*!< 0x02000000 */
#define USART_CR3_RXFTCFG_1             (0x2U << USART_CR3_RXFTCFG_Pos)         /*!< 0x04000000 */
#define USART_CR3_RXFTCFG_2             (0x4U << USART_CR3_RXFTCFG_Pos)         /*!< 0x08000000 */
#define USART_CR3_RXFTIE_Pos            (28U)
#define USART_CR3_RXFTIE_Msk            (0x1UL << USART_CR3_RXFTIE_Pos)         /*!< 0x10000000 */
#define USART_CR3_RXFTIE                USART_CR3_RXFTIE_Msk                    /*!< RX FIFO Threshold Interrupt Enable */
#define USART_CR3_TXFTCFG_Pos           (29U)
#define USART_CR3_TXFTCFG_Msk           (0x7UL << USART_CR3_TXFTCFG_Pos)        /*!< 0xE0000000 */
#define USART_CR3_TXFTCFG               USART_CR3_TXFTCFG_Msk                   /*!< TX FIFO Threshold configuration */
#define USART_CR3_TXFTCFG_0             (0x1U << USART_CR3_TXFTCFG_Pos)         /*!< 0x20000000 */
#define USART_CR3_TXFTCFG_1             (0x2U << USART_CR3_TXFTCFG_Pos)         /*!< 0x40000000 */
#define USART_CR3_TXFTCFG_2             (0x4U << USART_CR3_TXFTCFG_Pos)         /*!< 0x80000000 */

/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_BRR                   ((uint16_t)0xFFFF)                      /*!< USART  Baud rate register [15:0] */

/******************  Bit definition for USART_GTPR register  ******************/
#define USART_GTPR_PSC_Pos              (0U)
#define USART_GTPR_PSC_Msk              (0xFFUL << USART_GTPR_PSC_Pos)          /*!< 0x000000FF */
#define USART_GTPR_PSC                  USART_GTPR_PSC_Msk                      /*!< PSC[7:0] bits (Prescaler value) */
#define USART_GTPR_GT_Pos               (8U)
#define USART_GTPR_GT_Msk               (0xFFUL << USART_GTPR_GT_Pos)           /*!< 0x0000FF00 */
#define USART_GTPR_GT                   USART_GTPR_GT_Msk                       /*!< GT[7:0] bits (Guard time value) */

/*******************  Bit definition for USART_RTOR register  *****************/
#define USART_RTOR_RTO_Pos              (0U)
#define USART_RTOR_RTO_Msk              (0xFFFFFFUL << USART_RTOR_RTO_Pos)      /*!< 0x00FFFFFF */
#define USART_RTOR_RTO                  USART_RTOR_RTO_Msk                      /*!< Receiver Timeout Value */
#define USART_RTOR_BLEN_Pos             (24U)
#define USART_RTOR_BLEN_Msk             (0xFFUL << USART_RTOR_BLEN_Pos)         /*!< 0xFF000000 */
#define USART_RTOR_BLEN                 USART_RTOR_BLEN_Msk                     /*!< Block Length */

/*******************  Bit definition for USART_RQR register  ******************/
#define USART_RQR_ABRRQ_Pos             (0U)
#define USART_RQR_ABRRQ_Msk             (0x1UL << USART_RQR_ABRRQ_Pos)          /*!< 0x00000001 */
#define USART_RQR_ABRRQ                 USART_RQR_ABRRQ_Msk                     /*!< Auto-Baud Rate Request */
#define USART_RQR_SBKRQ_Pos             (1U)
#define USART_RQR_SBKRQ_Msk             (0x1UL << USART_RQR_SBKRQ_Pos)          /*!< 0x00000002 */
#define USART_RQR_SBKRQ                 USART_RQR_SBKRQ_Msk                     /*!< Send Break Request */
#define USART_RQR_MMRQ_Pos              (2U)
#define USART_RQR_MMRQ_Msk              (0x1UL << USART_RQR_MMRQ_Pos)           /*!< 0x00000004 */
#define USART_RQR_MMRQ                  USART_RQR_MMRQ_Msk                      /*!< Mute Mode Request */
#define USART_RQR_RXFRQ_Pos             (3U)
#define USART_RQR_RXFRQ_Msk             (0x1UL << USART_RQR_RXFRQ_Pos)          /*!< 0x00000008 */
#define USART_RQR_RXFRQ                 USART_RQR_RXFRQ_Msk                     /*!< Receive Data flush Request */
#define USART_RQR_TXFRQ_Pos             (4U)
#define USART_RQR_TXFRQ_Msk             (0x1UL << USART_RQR_TXFRQ_Pos)          /*!< 0x00000010 */
#define USART_RQR_TXFRQ                 USART_RQR_TXFRQ_Msk                     /*!< Transmit Data flush Request */

/*******************  Bit definition for USART_ISR register  ******************/
#define USART_ISR_PE_Pos                (0U)
#define USART_ISR_PE_Msk                (0x1UL << USART_ISR_PE_Pos)             /*!< 0x00000001 */
#define USART_ISR_PE                    USART_ISR_PE_Msk                        /*!< Parity Error */
#define USART_ISR_FE_Pos                (1U)
#define USART_ISR_FE_Msk                (0x1UL << USART_ISR_FE_Pos)             /*!< 0x00000002 */
#define USART_ISR_FE                    USART_ISR_FE_Msk                        /*!< Framing Error */
#define USART_ISR_NE_Pos                (2U)
#define USART_ISR_NE_Msk                (0x1UL << USART_ISR_NE_Pos)             /*!< 0x00000004 */
#define USART_ISR_NE                    USART_ISR_NE_Msk                        /*!< START bit Noise Error detection Flag */
#define USART_ISR_ORE_Pos               (3U)
#define USART_ISR_ORE_Msk               (0x1UL << USART_ISR_ORE_Pos)            /*!< 0x00000008 */
#define USART_ISR_ORE                   USART_ISR_ORE_Msk                       /*!< OverRun Error */
#define USART_ISR_IDLE_Pos              (4U)
#define USART_ISR_IDLE_Msk              (0x1UL << USART_ISR_IDLE_Pos)           /*!< 0x00000010 */
#define USART_ISR_IDLE                  USART_ISR_IDLE_Msk                      /*!< IDLE line detected */
#define USART_ISR_RXNE_Pos              (5U)
#define USART_ISR_RXNE_Msk              (0x1UL << USART_ISR_RXNE_Pos)           /*!< 0x00000020 */
#define USART_ISR_RXNE                  USART_ISR_RXNE_Msk                      /*!< Read Data Register Not Empty */
#define USART_ISR_RXNE_RXFNE_Pos        USART_ISR_RXNE_Pos
#define USART_ISR_RXNE_RXFNE_Msk        USART_ISR_RXNE_Msk                      /*!< 0x00000020 */
#define USART_ISR_RXNE_RXFNE            USART_ISR_RXNE_Msk                      /*!< Read Data Register or RX FIFO Not Empty */
#define USART_ISR_TC_Pos                (6U)
#define USART_ISR_TC_Msk                (0x1UL << USART_ISR_TC_Pos)             /*!< 0x00000040 */
#define USART_ISR_TC                    USART_ISR_TC_Msk                        /*!< Transmission Complete */
#define USART_ISR_TXE_Pos               (7U)
#define USART_ISR_TXE_Msk               (0x1UL << USART_ISR_TXE_Pos)            /*!< 0x00000080 */
#define USART_ISR_TXE                   USART_ISR_TXE_Msk                       /*!< Transmit Data Register Empty */
#define USART_ISR_TXE_TXFNF_Pos         USART_ISR_TXE_Pos
#define USART_ISR_TXE_TXFNF_Msk         USART_ISR_TXE_Msk                       /*!< 0x00000080 */
#define USART_ISR_TXE_TXFNF             USART_ISR_TXE_Msk                       /*!< Transmit Data Register Empty or TX FIFO Not Full Flag */
#define USART_ISR_LBDF_Pos              (8U)
#define USART_ISR_LBDF_Msk              (0x1UL << USART_ISR_LBDF_Pos)           /*!< 0x00000100 */
#define USART_ISR_LBDF                  USART_ISR_LBDF_Msk                      /*!< LIN Break Detection Flag */
#define USART_ISR_CTSIF_Pos             (9U)
#define USART_ISR_CTSIF_Msk             (0x1UL << USART_ISR_CTSIF_Pos)          /*!< 0x00000200 */
#define USART_ISR_CTSIF                 USART_ISR_CTSIF_Msk                     /*!< CTS interrupt Flag */
#define USART_ISR_CTS_Pos               (10U)
#define USART_ISR_CTS_Msk               (0x1UL << USART_ISR_CTS_Pos)            /*!< 0x00000400 */
#define USART_ISR_CTS                   USART_ISR_CTS_Msk                       /*!< CTS Flag */
#define USART_ISR_RTOF_Pos              (11U)
#define USART_ISR_RTOF_Msk              (0x1UL << USART_ISR_RTOF_Pos)           /*!< 0x00000800 */
#define USART_ISR_RTOF                  USART_ISR_RTOF_Msk                      /*!< Receiver Timeout */
#define USART_ISR_EOBF_Pos              (12U)
#define USART_ISR_EOBF_Msk              (0x1UL << USART_ISR_EOBF_Pos)           /*!< 0x00001000 */
#define USART_ISR_EOBF                  USART_ISR_EOBF_Msk                      /*!< End Of Block Flag */
#define USART_ISR_UDR_Pos               (13U)
#define USART_ISR_UDR_Msk               (0x1UL << USART_ISR_UDR_Pos)            /*!< 0x00002000 */
#define USART_ISR_UDR                   USART_ISR_UDR_Msk                       /*!< SPI Slave Underrun error Flag */
#define USART_ISR_ABRE_Pos              (14U)
#define USART_ISR_ABRE_Msk              (0x1UL << USART_ISR_ABRE_Pos)           /*!< 0x00004000 */
#define USART_ISR_ABRE                  USART_ISR_ABRE_Msk                      /*!< Auto-Baud Rate Error */
#define USART_ISR_ABRF_Pos              (15U)
#define USART_ISR_ABRF_Msk              (0x1UL << USART_ISR_ABRF_Pos)           /*!< 0x00008000 */
#define USART_ISR_ABRF                  USART_ISR_ABRF_Msk                      /*!< Auto-Baud Rate Flag */
#define USART_ISR_BUSY_Pos              (16U)
#define USART_ISR_BUSY_Msk              (0x1UL << USART_ISR_BUSY_Pos)           /*!< 0x00010000 */
#define USART_ISR_BUSY                  USART_ISR_BUSY_Msk                      /*!< Busy Flag */
#define USART_ISR_CMF_Pos               (17U)
#define USART_ISR_CMF_Msk               (0x1UL << USART_ISR_CMF_Pos)            /*!< 0x00020000 */
#define USART_ISR_CMF                   USART_ISR_CMF_Msk                       /*!< Character Match Flag */
#define USART_ISR_SBKF_Pos              (18U)
#define USART_ISR_SBKF_Msk              (0x1UL << USART_ISR_SBKF_Pos)           /*!< 0x00040000 */
#define USART_ISR_SBKF                  USART_ISR_SBKF_Msk                      /*!< Send Break Flag */
#define USART_ISR_RWU_Pos               (19U)
#define USART_ISR_RWU_Msk               (0x1UL << USART_ISR_RWU_Pos)            /*!< 0x00080000 */
#define USART_ISR_RWU                   USART_ISR_RWU_Msk                       /*!< Receive Wake Up from mute mode Flag */
#define USART_ISR_WUF_Pos               (20U)
#define USART_ISR_WUF_Msk               (0x1UL << USART_ISR_WUF_Pos)            /*!< 0x00100000 */
#define USART_ISR_WUF                   USART_ISR_WUF_Msk                       /*!< Wake Up from stop mode Flag */
#define USART_ISR_TEACK_Pos             (21U)
#define USART_ISR_TEACK_Msk             (0x1UL << USART_ISR_TEACK_Pos)          /*!< 0x00200000 */
#define USART_ISR_TEACK                 USART_ISR_TEACK_Msk                     /*!< Transmit Enable Acknowledge Flag */
#define USART_ISR_REACK_Pos             (22U)
#define USART_ISR_REACK_Msk             (0x1UL << USART_ISR_REACK_Pos)          /*!< 0x00400000 */
#define USART_ISR_REACK                 USART_ISR_REACK_Msk                     /*!< Receive Enable Acknowledge Flag */
#define USART_ISR_TXFE_Pos              (23U)
#define USART_ISR_TXFE_Msk              (0x1UL << USART_ISR_TXFE_Pos)           /*!< 0x00800000 */
#define USART_ISR_TXFE                  USART_ISR_TXFE_Msk                      /*!< TX FIFO Empty Flag */
#define USART_ISR_RXFF_Pos              (24U)
#define USART_ISR_RXFF_Msk              (0x1UL << USART_ISR_RXFF_Pos)           /*!< 0x01000000 */
#define USART_ISR_RXFF                  USART_ISR_RXFF_Msk                      /*!< RX FIFO Full Flag */
#define USART_ISR_TCBGT_Pos             (25U)
#define USART_ISR_TCBGT_Msk             (0x1UL << USART_ISR_TCBGT_Pos)          /*!< 0x02000000 */
#define USART_ISR_TCBGT                 USART_ISR_TCBGT_Msk                     /*!< Transmission Complete Before Guard Time completion */
#define USART_ISR_RXFT_Pos              (26U)
#define USART_ISR_RXFT_Msk              (0x1UL << USART_ISR_RXFT_Pos)           /*!< 0x04000000 */
#define USART_ISR_RXFT                  USART_ISR_RXFT_Msk                      /*!< RX FIFO Threshold Flag */
#define USART_ISR_TXFT_Pos              (27U)
#define USART_ISR_TXFT_Msk              (0x1UL << USART_ISR_TXFT_Pos)           /*!< 0x08000000 */
#define USART_ISR_TXFT                  USART_ISR_TXFT_Msk                      /*!< TX FIFO Threshold Flag */

/*******************  Bit definition for USART_ICR register  ******************/
#define USART_ICR_PECF_Pos              (0U)
#define USART_ICR_PECF_Msk              (0x1UL << USART_ICR_PECF_Pos)           /*!< 0x00000001 */
#define USART_ICR_PECF                  USART_ICR_PECF_Msk                      /*!< Parity Error Clear Flag */
#define USART_ICR_FECF_Pos              (1U)
#define USART_ICR_FECF_Msk              (0x1UL << USART_ICR_FECF_Pos)           /*!< 0x00000002 */
#define USART_ICR_FECF                  USART_ICR_FECF_Msk                      /*!< Framing Error Clear Flag */
#define USART_ICR_NECF_Pos              (2U)
#define USART_ICR_NECF_Msk              (0x1UL << USART_ICR_NECF_Pos)           /*!< 0x00000004 */
#define USART_ICR_NECF                  USART_ICR_NECF_Msk                      /*!< Noise Error detected Clear Flag */
#define USART_ICR_ORECF_Pos             (3U)
#define USART_ICR_ORECF_Msk             (0x1UL << USART_ICR_ORECF_Pos)          /*!< 0x00000008 */
#define USART_ICR_ORECF                 USART_ICR_ORECF_Msk                     /*!< OverRun Error Clear Flag */
#define USART_ICR_IDLECF_Pos            (4U)
#define USART_ICR_IDLECF_Msk            (0x1UL << USART_ICR_IDLECF_Pos)         /*!< 0x00000010 */
#define USART_ICR_IDLECF                USART_ICR_IDLECF_Msk                    /*!< IDLE line detected Clear Flag */
#define USART_ICR_TXFECF_Pos            (5U)
#define USART_ICR_TXFECF_Msk            (0x1UL << USART_ICR_TXFECF_Pos)         /*!< 0x00000020 */
#define USART_ICR_TXFECF                USART_ICR_TXFECF_Msk                    /*!< TX FIFO Empty Clear Flag */
#define USART_ICR_TCCF_Pos              (6U)
#define USART_ICR_TCCF_Msk              (0x1UL << USART_ICR_TCCF_Pos)           /*!< 0x00000040 */
#define USART_ICR_TCCF                  USART_ICR_TCCF_Msk                      /*!< Transmission Complete Clear Flag */
#define USART_ICR_TCBGTCF_Pos           (7U)
#define USART_ICR_TCBGTCF_Msk           (0x1UL << USART_ICR_TCBGTCF_Pos)        /*!< 0x00000080 */
#define USART_ICR_TCBGTCF               USART_ICR_TCBGTCF_Msk                   /*!< Transmission Complete Before Guard Time Clear Flag */
#define USART_ICR_LBDCF_Pos             (8U)
#define USART_ICR_LBDCF_Msk             (0x1UL << USART_ICR_LBDCF_Pos)          /*!< 0x00000100 */
#define USART_ICR_LBDCF                 USART_ICR_LBDCF_Msk                     /*!< LIN Break Detection Clear Flag */
#define USART_ICR_CTSCF_Pos             (9U)
#define USART_ICR_CTSCF_Msk             (0x1UL << USART_ICR_CTSCF_Pos)          /*!< 0x00000200 */
#define USART_ICR_CTSCF                 USART_ICR_CTSCF_Msk                     /*!< CTS Interrupt Clear Flag */
#define USART_ICR_RTOCF_Pos             (11U)
#define USART_ICR_RTOCF_Msk             (0x1UL << USART_ICR_RTOCF_Pos)          /*!< 0x00000800 */
#define USART_ICR_RTOCF                 USART_ICR_RTOCF_Msk                     /*!< Receiver Time Out Clear Flag */
#define USART_ICR_EOBCF_Pos             (12U)
#define USART_ICR_EOBCF_Msk             (0x1UL << USART_ICR_EOBCF_Pos)          /*!< 0x00001000 */
#define USART_ICR_EOBCF                 USART_ICR_EOBCF_Msk                     /*!< End Of Block Clear Flag */
#define USART_ICR_UDRCF_Pos             (13U)
#define USART_ICR_UDRCF_Msk             (0x1UL << USART_ICR_UDRCF_Pos)          /*!< 0x00002000 */
#define USART_ICR_UDRCF                 USART_ICR_UDRCF_Msk                     /*!< SPI Slave Underrun Clear Flag */
#define USART_ICR_CMCF_Pos              (17U)
#define USART_ICR_CMCF_Msk              (0x1UL << USART_ICR_CMCF_Pos)           /*!< 0x00020000 */
#define USART_ICR_CMCF                  USART_ICR_CMCF_Msk                      /*!< Character Match Clear Flag */
#define USART_ICR_WUCF_Pos              (20U)
#define USART_ICR_WUCF_Msk              (0x1UL << USART_ICR_WUCF_Pos)           /*!< 0x00100000 */
#define USART_ICR_WUCF                  USART_ICR_WUCF_Msk                      /*!< Wake Up from stop mode Clear Flag */

/*******************  Bit definition for USART_RDR register  ******************/
#define USART_RDR_RDR_Pos               (0U)
#define USART_RDR_RDR_Msk               (0x01FFUL << USART_RDR_RDR_Pos)         /*!< 0x000001FF */
#define USART_RDR_RDR                   USART_RDR_RDR_Msk                       /*!< RDR[8:0] bits (Receive Data value) */

/*******************  Bit definition for USART_TDR register  ******************/
#define USART_TDR_TDR_Pos               (0U)
#define USART_TDR_TDR_Msk               (0x01FFUL << USART_TDR_TDR_Pos)         /*!< 0x000001FF */
#define USART_TDR_TDR                   USART_TDR_TDR_Msk                       /*!< TDR[8:0] bits (Transmit Data value) */

/*******************  Bit definition for USART_PRESC register  ******************/
#define USART_PRESC_PRESCALER_Pos       (0U)
#define USART_PRESC_PRESCALER_Msk       (0xFUL << USART_PRESC_PRESCALER_Pos)    /*!< 0x0000000F */
#define USART_PRESC_PRESCALER           USART_PRESC_PRESCALER_Msk               /*!< PRESCALER[3:0] bits (Clock prescaler) */
#define USART_PRESC_PRESCALER_0         (0x1U << USART_PRESC_PRESCALER_Pos)     /*!< 0x00000001 */
#define USART_PRESC_PRESCALER_1         (0x2U << USART_PRESC_PRESCALER_Pos)     /*!< 0x00000002 */
#define USART_PRESC_PRESCALER_2         (0x4U << USART_PRESC_PRESCALER_Pos)     /*!< 0x00000004 */
#define USART_PRESC_PRESCALER_3         (0x8U << USART_PRESC_PRESCALER_Pos)     /*!< 0x00000008 */

/******************************************************************************/
/*                                                                            */
/*                            Window WATCHDOG                                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for WWDG_CR register  ********************/
#define WWDG_CR_T_Pos           (0U)
#define WWDG_CR_T_Msk           (0x7FUL << WWDG_CR_T_Pos)                      /*!< 0x0000007F */
#define WWDG_CR_T               WWDG_CR_T_Msk                                  /*!<T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define WWDG_CR_T_0             (0x01U << WWDG_CR_T_Pos)                       /*!< 0x00000001 */
#define WWDG_CR_T_1             (0x02U << WWDG_CR_T_Pos)                       /*!< 0x00000002 */
#define WWDG_CR_T_2             (0x04U << WWDG_CR_T_Pos)                       /*!< 0x00000004 */
#define WWDG_CR_T_3             (0x08U << WWDG_CR_T_Pos)                       /*!< 0x00000008 */
#define WWDG_CR_T_4             (0x10U << WWDG_CR_T_Pos)                       /*!< 0x00000010 */
#define WWDG_CR_T_5             (0x20U << WWDG_CR_T_Pos)                       /*!< 0x00000020 */
#define WWDG_CR_T_6             (0x40U << WWDG_CR_T_Pos)                       /*!< 0x00000040 */

#define WWDG_CR_WDGA_Pos        (7U)
#define WWDG_CR_WDGA_Msk        (0x1UL << WWDG_CR_WDGA_Pos)                    /*!< 0x00000080 */
#define WWDG_CR_WDGA            WWDG_CR_WDGA_Msk                               /*!<Activation bit */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define WWDG_CFR_W_Pos          (0U)
#define WWDG_CFR_W_Msk          (0x7FUL << WWDG_CFR_W_Pos)                     /*!< 0x0000007F */
#define WWDG_CFR_W              WWDG_CFR_W_Msk                                 /*!<W[6:0] bits (7-bit window value) */
#define WWDG_CFR_W_0            (0x01U << WWDG_CFR_W_Pos)                      /*!< 0x00000001 */
#define WWDG_CFR_W_1            (0x02U << WWDG_CFR_W_Pos)                      /*!< 0x00000002 */
#define WWDG_CFR_W_2            (0x04U << WWDG_CFR_W_Pos)                      /*!< 0x00000004 */
#define WWDG_CFR_W_3            (0x08U << WWDG_CFR_W_Pos)                      /*!< 0x00000008 */
#define WWDG_CFR_W_4            (0x10U << WWDG_CFR_W_Pos)                      /*!< 0x00000010 */
#define WWDG_CFR_W_5            (0x20U << WWDG_CFR_W_Pos)                      /*!< 0x00000020 */
#define WWDG_CFR_W_6            (0x40U << WWDG_CFR_W_Pos)                      /*!< 0x00000040 */

#define WWDG_CFR_WDGTB_Pos      (11U)
#define WWDG_CFR_WDGTB_Msk      (0x7UL << WWDG_CFR_WDGTB_Pos)                  /*!< 0x00003800 */
#define WWDG_CFR_WDGTB          WWDG_CFR_WDGTB_Msk                             /*!<WDGTB[2:0] bits (Timer Base) */
#define WWDG_CFR_WDGTB_0        (0x1U << WWDG_CFR_WDGTB_Pos)                   /*!< 0x00000800 */
#define WWDG_CFR_WDGTB_1        (0x2U << WWDG_CFR_WDGTB_Pos)                   /*!< 0x00001000 */
#define WWDG_CFR_WDGTB_2        (0x4U << WWDG_CFR_WDGTB_Pos)                   /*!< 0x00002000 */

#define WWDG_CFR_EWI_Pos        (9U)
#define WWDG_CFR_EWI_Msk        (0x1UL << WWDG_CFR_EWI_Pos)                    /*!< 0x00000200 */
#define WWDG_CFR_EWI            WWDG_CFR_EWI_Msk                               /*!<Early Wakeup Interrupt */

/*******************  Bit definition for WWDG_SR register  ********************/
#define WWDG_SR_EWIF_Pos        (0U)
#define WWDG_SR_EWIF_Msk        (0x1UL << WWDG_SR_EWIF_Pos)                    /*!< 0x00000001 */
#define WWDG_SR_EWIF            WWDG_SR_EWIF_Msk                               /*!<Early Wakeup Interrupt Flag */

/******************************************************************************/
/*                                                                            */
/*                                Debug MCU                                   */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DBGMCU_IDCODE register  *************/
#define DBGMCU_IDCODE_DEV_ID_Pos                          (0U)
#define DBGMCU_IDCODE_DEV_ID_Msk                          (0xFFFUL << DBGMCU_IDCODE_DEV_ID_Pos) /*!< 0x00000FFF */
#define DBGMCU_IDCODE_DEV_ID                              DBGMCU_IDCODE_DEV_ID_Msk
#define DBGMCU_IDCODE_REV_ID_Pos                          (16U)
#define DBGMCU_IDCODE_REV_ID_Msk                          (0xFFFFUL << DBGMCU_IDCODE_REV_ID_Pos) /*!< 0xFFFF0000 */
#define DBGMCU_IDCODE_REV_ID                              DBGMCU_IDCODE_REV_ID_Msk

/********************  Bit definition for DBGMCU_CR register  *****************/
#define DBGMCU_CR_DBG_SLEEP_Pos                           (0U)
#define DBGMCU_CR_DBG_SLEEP_Msk                           (0x1UL << DBGMCU_CR_DBG_SLEEP_Pos)  /*!< 0x00000001 */
#define DBGMCU_CR_DBG_SLEEP                               DBGMCU_CR_DBG_SLEEP_Msk
#define DBGMCU_CR_DBG_STOP_Pos                            (1U)
#define DBGMCU_CR_DBG_STOP_Msk                            (0x1UL << DBGMCU_CR_DBG_STOP_Pos)   /*!< 0x00000002 */
#define DBGMCU_CR_DBG_STOP                                DBGMCU_CR_DBG_STOP_Msk
#define DBGMCU_CR_DBG_STANDBY_Pos                         (2U)
#define DBGMCU_CR_DBG_STANDBY_Msk                         (0x1UL << DBGMCU_CR_DBG_STANDBY_Pos) /*!< 0x00000004 */
#define DBGMCU_CR_DBG_STANDBY                             DBGMCU_CR_DBG_STANDBY_Msk
#define DBGMCU_CR_TRACE_IOEN_Pos                          (5U)
#define DBGMCU_CR_TRACE_IOEN_Msk                          (0x1UL << DBGMCU_CR_TRACE_IOEN_Pos) /*!< 0x00000020 */
#define DBGMCU_CR_TRACE_IOEN                              DBGMCU_CR_TRACE_IOEN_Msk
#define DBGMCU_CR_TRGOEN_Pos                              (28U)
#define DBGMCU_CR_TRGOEN_Msk                              (0x1UL << DBGMCU_CR_TRGOEN_Pos)      /*!< 0x10000000 */
#define DBGMCU_CR_TRGOEN                                  DBGMCU_CR_TRGOEN_Msk

/********************  Bit definition for DBGMCU_APB1FZR1 register  ***********/
#define DBGMCU_APB1FZR1_DBG_TIM2_STOP_Pos                 (0U)
#define DBGMCU_APB1FZR1_DBG_TIM2_STOP_Msk                 (0x1UL << DBGMCU_APB1FZR1_DBG_TIM2_STOP_Pos)  /*!< 0x00000001 */
#define DBGMCU_APB1FZR1_DBG_TIM2_STOP                     DBGMCU_APB1FZR1_DBG_TIM2_STOP_Msk
#define DBGMCU_APB1FZR1_DBG_RTC_STOP_Pos                  (10U)
#define DBGMCU_APB1FZR1_DBG_RTC_STOP_Msk                  (0x1UL << DBGMCU_APB1FZR1_DBG_RTC_STOP_Pos)   /*!< 0x00000400 */
#define DBGMCU_APB1FZR1_DBG_RTC_STOP                      DBGMCU_APB1FZR1_DBG_RTC_STOP_Msk
#define DBGMCU_APB1FZR1_DBG_WWDG_STOP_Pos                 (11U)
#define DBGMCU_APB1FZR1_DBG_WWDG_STOP_Msk                 (0x1UL << DBGMCU_APB1FZR1_DBG_WWDG_STOP_Pos)  /*!< 0x00000800 */
#define DBGMCU_APB1FZR1_DBG_WWDG_STOP                     DBGMCU_APB1FZR1_DBG_WWDG_STOP_Msk
#define DBGMCU_APB1FZR1_DBG_IWDG_STOP_Pos                 (12U)
#define DBGMCU_APB1FZR1_DBG_IWDG_STOP_Msk                 (0x1UL << DBGMCU_APB1FZR1_DBG_IWDG_STOP_Pos)  /*!< 0x00001000 */
#define DBGMCU_APB1FZR1_DBG_IWDG_STOP                     DBGMCU_APB1FZR1_DBG_IWDG_STOP_Msk
#define DBGMCU_APB1FZR1_DBG_I2C1_STOP_Pos                 (21U)
#define DBGMCU_APB1FZR1_DBG_I2C1_STOP_Msk                 (0x1UL << DBGMCU_APB1FZR1_DBG_I2C1_STOP_Pos)  /*!< 0x00200000 */
#define DBGMCU_APB1FZR1_DBG_I2C1_STOP                     DBGMCU_APB1FZR1_DBG_I2C1_STOP_Msk
#define DBGMCU_APB1FZR1_DBG_LPTIM1_STOP_Pos               (31U)
#define DBGMCU_APB1FZR1_DBG_LPTIM1_STOP_Msk               (0x1UL << DBGMCU_APB1FZR1_DBG_LPTIM1_STOP_Pos) /*!< 0x80000000 */
#define DBGMCU_APB1FZR1_DBG_LPTIM1_STOP                   DBGMCU_APB1FZR1_DBG_LPTIM1_STOP_Msk

/********************  Bit definition for DBGMCU_C2APB1FZR1 register  ***********/
#define DBGMCU_C2APB1FZR1_DBG_TIM2_STOP_Pos               (0U)
#define DBGMCU_C2APB1FZR1_DBG_TIM2_STOP_Msk               (0x1UL << DBGMCU_C2APB1FZR1_DBG_TIM2_STOP_Pos)  /*!< 0x00000001 */
#define DBGMCU_C2APB1FZR1_DBG_TIM2_STOP                   DBGMCU_C2APB1FZR1_DBG_TIM2_STOP_Msk
#define DBGMCU_C2APB1FZR1_DBG_RTC_STOP_Pos                (10U)
#define DBGMCU_C2APB1FZR1_DBG_RTC_STOP_Msk                (0x1UL << DBGMCU_C2APB1FZR1_DBG_RTC_STOP_Pos)   /*!< 0x00000400 */
#define DBGMCU_C2APB1FZR1_DBG_RTC_STOP                    DBGMCU_C2APB1FZR1_DBG_RTC_STOP_Msk
#define DBGMCU_C2APB1FZR1_DBG_IWDG_STOP_Pos               (12U)
#define DBGMCU_C2APB1FZR1_DBG_IWDG_STOP_Msk               (0x1UL << DBGMCU_C2APB1FZR1_DBG_IWDG_STOP_Pos)  /*!< 0x00001000 */
#define DBGMCU_C2APB1FZR1_DBG_IWDG_STOP                   DBGMCU_C2APB1FZR1_DBG_IWDG_STOP_Msk
#define DBGMCU_C2APB1FZR1_DBG_I2C1_STOP_Pos               (21U)
#define DBGMCU_C2APB1FZR1_DBG_I2C1_STOP_Msk               (0x1UL << DBGMCU_C2APB1FZR1_DBG_I2C1_STOP_Pos)  /*!< 0x00200000 */
#define DBGMCU_C2APB1FZR1_DBG_I2C1_STOP                   DBGMCU_C2APB1FZR1_DBG_I2C1_STOP_Msk
#define DBGMCU_C2APB1FZR1_DBG_LPTIM1_STOP_Pos             (31U)
#define DBGMCU_C2APB1FZR1_DBG_LPTIM1_STOP_Msk             (0x1UL << DBGMCU_C2APB1FZR1_DBG_LPTIM1_STOP_Pos) /*!< 0x80000000 */
#define DBGMCU_C2APB1FZR1_DBG_LPTIM1_STOP                 DBGMCU_C2APB1FZR1_DBG_LPTIM1_STOP_Msk

/********************  Bit definition for DBGMCU_APB1FZR2 register  ***********/
#define DBGMCU_APB1FZR2_DBG_LPTIM2_STOP_Pos               (5U)
#define DBGMCU_APB1FZR2_DBG_LPTIM2_STOP_Msk               (0x1UL << DBGMCU_APB1FZR2_DBG_LPTIM2_STOP_Pos) /*!< 0x00000020 */
#define DBGMCU_APB1FZR2_DBG_LPTIM2_STOP                   DBGMCU_APB1FZR2_DBG_LPTIM2_STOP_Msk

/********************  Bit definition for DBGMCU_C2APB1FZR2 register  ***********/
#define DBGMCU_C2APB1FZR2_DBG_LPTIM2_STOP_Pos             (5U)
#define DBGMCU_C2APB1FZR2_DBG_LPTIM2_STOP_Msk             (0x1UL << DBGMCU_C2APB1FZR2_DBG_LPTIM2_STOP_Pos) /*!< 0x00000020 */
#define DBGMCU_C2APB1FZR2_DBG_LPTIM2_STOP                 DBGMCU_C2APB1FZR2_DBG_LPTIM2_STOP_Msk

/********************  Bit definition for DBGMCU_APB2FZR register  ************/
#define DBGMCU_APB2FZR_DBG_TIM1_STOP_Pos                  (11U)
#define DBGMCU_APB2FZR_DBG_TIM1_STOP_Msk                  (0x1UL << DBGMCU_APB2FZR_DBG_TIM1_STOP_Pos) /*!< 0x000000800 */
#define DBGMCU_APB2FZR_DBG_TIM1_STOP                      DBGMCU_APB2FZR_DBG_TIM1_STOP_Msk

/********************  Bit definition for DBGMCU_C2APB2FZR register  ************/
#define DBGMCU_C2APB2FZR_DBG_TIM1_STOP_Pos                (11U)
#define DBGMCU_C2APB2FZR_DBG_TIM1_STOP_Msk                (0x1UL << DBGMCU_C2APB2FZR_DBG_TIM1_STOP_Pos) /*!< 0x000000800 */
#define DBGMCU_C2APB2FZR_DBG_TIM1_STOP                    DBGMCU_C2APB2FZR_DBG_TIM1_STOP_Msk

/** @addtogroup Exported_macros
  * @{
  */


/*********************** UART Instances : Asynchronous mode *******************/
#define IS_UART_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/*********************** UART Instances : FIFO mode ***************************/
#define IS_UART_FIFO_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                         ((INSTANCE) == LPUART1))

/*********************** UART Instances : SPI Slave mode **********************/
#define IS_UART_SPI_SLAVE_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/*********************** USART Instances : Synchronous mode *******************/
#define IS_USART_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/*********************** USART Instances : Auto Baud Rate detection ***********/

#define IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/*********************** UART Instances : Half-Duplex mode ********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
                                                 ((INSTANCE) == LPUART1))

/*********************** UART Instances : LIN mode ****************************/
#define IS_UART_LIN_INSTANCE(INSTANCE)    ((INSTANCE) == USART1)

/*********************** UART Instances : Wake-up from Stop mode **************/
#define IS_UART_WAKEUP_FROMSTOP_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
                                                      ((INSTANCE) == LPUART1))

/*********************** UART Instances : Hardware Flow control ***************/
#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                           ((INSTANCE) == LPUART1))

/*********************** UART Instances : Smard card mode *********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/*********************** UART Instances : Driver Enable ***********************/
#define IS_UART_DRIVER_ENABLE_INSTANCE(INSTANCE) (((INSTANCE) == USART1)|| \
                                                  ((INSTANCE) == LPUART1))

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/******************** LPUART Instance *****************************************/
#define IS_LPUART_INSTANCE(INSTANCE)    ((INSTANCE) == LPUART1)

/******************************* ADC Instances ********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

#define IS_ADC_COMMON_INSTANCE(INSTANCE) ((INSTANCE) == ADC1_COMMON)

/******************************* AES Instances ********************************/
#define IS_AES_ALL_INSTANCE(INSTANCE) ((INSTANCE) == AES2)

/******************************** COMP Instances ******************************/
#define IS_COMP_ALL_INSTANCE(INSTANCE) (((INSTANCE) == COMP1))

#define IS_COMP_COMMON_INSTANCE(INSTANCE) (0U)

/******************** COMP Instances with window mode capability **************/
#define IS_COMP_WINDOWMODE_INSTANCE(INSTANCE) (0U)

/******************************* CRC Instances ********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/******************************** DMA Instances *******************************/
#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA1_Channel1) || \
                                       ((INSTANCE) == DMA1_Channel2) || \
                                       ((INSTANCE) == DMA1_Channel3) || \
                                       ((INSTANCE) == DMA1_Channel4) || \
                                       ((INSTANCE) == DMA1_Channel5) || \
                                       ((INSTANCE) == DMA1_Channel6) || \
                                       ((INSTANCE) == DMA1_Channel7))

/******************************** DMAMUX Instances ****************************/
#define IS_DMAMUX_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DMAMUX1)

#define IS_DMAMUX_REQUEST_GEN_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMAMUX1_RequestGenerator0) || \
                                                      ((INSTANCE) == DMAMUX1_RequestGenerator1) || \
                                                      ((INSTANCE) == DMAMUX1_RequestGenerator2) || \
                                                      ((INSTANCE) == DMAMUX1_RequestGenerator3))

/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB) || \
                                        ((INSTANCE) == GPIOC) || \
                                        ((INSTANCE) == GPIOE) || \
                                        ((INSTANCE) == GPIOH))

/******************************* GPIO AF Instances ****************************/
#define IS_GPIO_AF_INSTANCE(INSTANCE)   IS_GPIO_ALL_INSTANCE(INSTANCE)

/**************************** GPIO Lock Instances *****************************/
#define IS_GPIO_LOCK_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE) ((INSTANCE) == I2C1)

/****************** I2C Instances : wakeup capability from stop modes *********/
#define IS_I2C_WAKEUP_FROMSTOP_INSTANCE(INSTANCE) IS_I2C_ALL_INSTANCE(INSTANCE)

/******************************* SMBUS Instances ******************************/
#define IS_SMBUS_ALL_INSTANCE(INSTANCE) IS_I2C_ALL_INSTANCE(INSTANCE)

/******************************* IPCC Instances ********************************/
#define IS_IPCC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IPCC)

/******************************** HSEM Instances *******************************/
#define IS_HSEM_ALL_INSTANCE(INSTANCE) ((INSTANCE) == HSEM)

#define HSEM_CPU1_COREID        (0x00000004UL)/* Semaphore Core ID */
#define HSEM_CPU2_COREID        (0x00000008UL)/* Semaphore Core ID */

#define HSEM_SEMID_MIN     (0U)       /* HSEM ID Min*/
#define HSEM_SEMID_MAX     (31U)      /* HSEM ID Max */

#define HSEM_PROCESSID_MIN (0U)       /* HSEM Process ID Min */
#define HSEM_PROCESSID_MAX (255U)     /* HSEM Process ID Max */

#define HSEM_CLEAR_KEY_MIN (0U)       /* HSEM clear Key Min value */
#define HSEM_CLEAR_KEY_MAX (0xFFFFU)  /* HSEM clear Key Max value */

/******************************** PKA Instances *******************************/
#define IS_PKA_ALL_INSTANCE(INSTANCE) ((INSTANCE) == PKA)

/******************************* RNG Instances ********************************/
#define IS_RNG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RNG)

/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RTC)

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SPI1)

/****************** LPTIM Instances : All supported instances *****************/
#define IS_LPTIM_INSTANCE(INSTANCE)     (((INSTANCE) == LPTIM1) || \
                                         ((INSTANCE) == LPTIM2))

/****************** LPTIM Instances : Encoder mode ****************************/
#define IS_LPTIM_ENCODER_INTERFACE_INSTANCE(INSTANCE) ((INSTANCE) == LPTIM1)

/****************** TIM Instances : All supported instances *******************/
#define IS_TIM_INSTANCE(INSTANCE)       (((INSTANCE) == TIM1)   || \
                                         ((INSTANCE) == TIM2))

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG)

/****************************** WWDG Instances ********************************/
#define IS_WWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDG)

/****************** TIM Instances : supporting 32 bits counter ****************/
#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE) ((INSTANCE) == TIM2)

/****************** TIM Instances : supporting the break function *************/
#define IS_TIM_BREAK_INSTANCE(INSTANCE)  ((INSTANCE) == TIM1)

/************** TIM Instances : supporting Break source selection *************/
#define IS_TIM_BREAKSOURCE_INSTANCE(INSTANCE)  ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting 2 break inputs *****************/
#define IS_TIM_BKIN2_INSTANCE(INSTANCE)    ((INSTANCE) == TIM1)

/************* TIM Instances : at least 1 capture/compare channel *************/
#define IS_TIM_CC1_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)   || \
                                         ((INSTANCE) == TIM2))

/************ TIM Instances : at least 2 capture/compare channels *************/
#define IS_TIM_CC2_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)   || \
                                         ((INSTANCE) == TIM2))

/************ TIM Instances : at least 3 capture/compare channels *************/
#define IS_TIM_CC3_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)   || \
                                         ((INSTANCE) == TIM2))

/************ TIM Instances : at least 4 capture/compare channels *************/
#define IS_TIM_CC4_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)   || \
                                         ((INSTANCE) == TIM2))

/****************** TIM Instances : at least 5 capture/compare channels *******/
#define IS_TIM_CC5_INSTANCE(INSTANCE)      ((INSTANCE) == TIM1)

/****************** TIM Instances : at least 6 capture/compare channels *******/
#define IS_TIM_CC6_INSTANCE(INSTANCE)      ((INSTANCE) == TIM1)

/************ TIM Instances : DMA requests generation (TIMx_DIER.COMDE) *******/
#define IS_TIM_CCDMA_INSTANCE(INSTANCE)    ((INSTANCE) == TIM1)

/****************** TIM Instances : DMA requests generation (TIMx_DIER.UDE) ***/
#define IS_TIM_DMA_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1)   || \
                                            ((INSTANCE) == TIM2))

/************ TIM Instances : DMA requests generation (TIMx_DIER.CCxDE) *******/
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)   || \
                                            ((INSTANCE) == TIM2))

/******************** TIM Instances : DMA burst feature ***********************/
#define IS_TIM_DMABURST_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)   || \
                                            ((INSTANCE) == TIM2))

/******************* TIM Instances : Timer input selection ********************/
#define IS_TIM_TISEL_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)   || \
                                         ((INSTANCE) == TIM2))

/******************* TIM Instances : output(s) available **********************/
#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
  ((((INSTANCE) == TIM1) &&                  \
    (((CHANNEL) == TIM_CHANNEL_1) ||          \
     ((CHANNEL) == TIM_CHANNEL_2) ||          \
     ((CHANNEL) == TIM_CHANNEL_3) ||          \
     ((CHANNEL) == TIM_CHANNEL_4) ||          \
     ((CHANNEL) == TIM_CHANNEL_5) ||          \
     ((CHANNEL) == TIM_CHANNEL_6)))           \
   ||                                        \
   (((INSTANCE) == TIM2) &&                  \
    (((CHANNEL) == TIM_CHANNEL_1) ||          \
     ((CHANNEL) == TIM_CHANNEL_2) ||          \
     ((CHANNEL) == TIM_CHANNEL_3) ||          \
     ((CHANNEL) == TIM_CHANNEL_4))))

/****************** TIM Instances : supporting complementary output(s) ********/
#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
  (((INSTANCE) == TIM1) &&                    \
   (((CHANNEL) == TIM_CHANNEL_1) ||           \
    ((CHANNEL) == TIM_CHANNEL_2) ||           \
    ((CHANNEL) == TIM_CHANNEL_3)))

/****************** TIM Instances : supporting clock division *****************/
#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)    || \
                                                    ((INSTANCE) == TIM2))

/****** TIM Instances : supporting external clock mode 1 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2))

/****** TIM Instances : supporting external clock mode 2 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2))

/****************** TIM Instances : supporting external clock mode 1 for TIX inputs*/
#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2))

/****************** TIM Instances : supporting internal trigger inputs(ITRX) *******/
#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)     (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2))

/****************** TIM Instances : supporting combined 3-phase PWM mode ******/
#define IS_TIM_COMBINED3PHASEPWM_INSTANCE(INSTANCE) ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting commutation event generation ***/
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE) ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting counting mode selection ********/
#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIM2))

/****************** TIM Instances : supporting encoder interface **************/
#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1)  || \
                                                      ((INSTANCE) == TIM2))

/****************** TIM Instances : supporting Hall sensor interface **********/
#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)  || \
                                                         ((INSTANCE) == TIM2))

/**************** TIM Instances : external trigger input available ************/
#define IS_TIM_ETR_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1)  || \
                                            ((INSTANCE) == TIM2))

/************* TIM Instances : supporting ETR source selection ***************/
#define IS_TIM_ETRSEL_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1)  || \
                                             ((INSTANCE) == TIM2))

/****** TIM Instances : Master mode available (TIMx_CR2.MMS available )********/
#define IS_TIM_MASTER_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)  || \
                                            ((INSTANCE) == TIM2))

/*********** TIM Instances : Slave mode available (TIMx_SMCR available )*******/
#define IS_TIM_SLAVE_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1)  || \
                                            ((INSTANCE) == TIM2))

/****************** TIM Instances : supporting OCxREF clear *******************/
#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)        (((INSTANCE) == TIM1) || \
                                                       ((INSTANCE) == TIM2))

/****************** TIM Instances : remapping capability **********************/
#define IS_TIM_REMAP_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1)  || \
                                            ((INSTANCE) == TIM2))

/****************** TIM Instances : supporting repetition counter *************/
#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)  ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting ADC triggering through TRGO2 ***/
#define IS_TIM_TRGO2_INSTANCE(INSTANCE)    ((INSTANCE) == TIM1)

/******************* TIM Instances : Timer input XOR function *****************/
#define IS_TIM_XOR_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1)   || \
                                            ((INSTANCE) == TIM2))

/************ TIM Instances : Advanced timers  ********************************/
#define IS_TIM_ADVANCED_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1))

/****************************** TSC Instances *********************************/
#define IS_TSC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == TSC)

/**
  * @}
  */

/**
  * @}
 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32WB1Mxx_H */

/**
  * @}
  */

/**
  * @}
*/
