/**
  ******************************************************************************
  * @file    system_stm32wbaxx_s.c
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M33 Device Peripheral Access Layer System Source File
  *          to be used in secure application when the system implements
  *          the TrustZone-M security.
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  *   This file provides two functions and one global variable to be called from
  *   user application:
  *      - SystemInit(): This function is called at secure startup just after reset
  *                      and before branch to secure main program.
  *                      This call is made inside the "startup_stm32wbaxx.s" file.
  *
  *      - SystemCoreClock variable: Contains the core clock (HCLK), it can be used
  *                                  by the user application to setup the SysTick
  *                                  timer or configure other parameters.
  *
  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  *                                 be called whenever the core clock is changed
  *                                 during program execution.
  *
  *      - SECURE_SystemCoreClockUpdate(): Non-secure callable function to update
  *                                        the variable SystemCoreClock and return
  *                                        its value to the non-secure calling
  *                                        application. It must be called whenever
  *                                        the core clock is changed during program
  *                                        execution.
  *
  *   After each device reset the HSI (16 MHz) is used as system clock source.
  *   Then SystemInit() function is called, in "startup_stm32wbaxx.s" file, to
  *   configure the system clock before to branch to main program.
  *
  *   This file configures the system clock as follows:
  *=============================================================================
  *-----------------------------------------------------------------------------
  *        System Clock source                     | HSI
  *-----------------------------------------------------------------------------
  *        SYSCLK(Hz)                              | 16000000
  *-----------------------------------------------------------------------------
  *        HCLK(Hz)                                | 16000000
  *-----------------------------------------------------------------------------
  *        AHB Prescaler                           | 1
  *-----------------------------------------------------------------------------
  *        APB1 Prescaler                          | 1
  *-----------------------------------------------------------------------------
  *        APB2 Prescaler                          | 1
  *-----------------------------------------------------------------------------
  *        PLL1_SRC                                | No clock
  *-----------------------------------------------------------------------------
  *        PLL1_M                                  | 1
  *-----------------------------------------------------------------------------
  *        PLL1_N                                  | 128
  *-----------------------------------------------------------------------------
  *        PLL1_P                                  | 1
  *-----------------------------------------------------------------------------
  *        PLL1_Q                                  | 1
  *-----------------------------------------------------------------------------
  *        PLL1_R                                  | 1
  *-----------------------------------------------------------------------------
  *        Require 48MHz for                       | Disabled
  *        SDIO and RNG clock                      |
  *-----------------------------------------------------------------------------
  *=============================================================================
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup STM32WBAxx_system
  * @{
  */

/** @addtogroup STM32WBAxx_System_Private_Includes
  * @{
  */

#include "stm32wbaxx.h"
#include "partition_stm32wbaxx.h"  /* Trustzone-M core secure attributes */
#include <math.h>

/**
  * @}
  */

/** @addtogroup STM32WBAxx_System_Private_TypesDefinitions
  * @{
  */
#if defined ( __ICCARM__ )
#  define CMSE_NS_ENTRY __cmse_nonsecure_entry
#else
#  define CMSE_NS_ENTRY __attribute((cmse_nonsecure_entry))
#endif
/**
  * @}
  */

/** @addtogroup STM32WBAxx_System_Private_Defines
  * @{
  */
#if !defined (HSE_VALUE)
#define HSE_VALUE     (32000000U) /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined (HSI_VALUE)
#define HSI_VALUE     (16000000U) /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

/*!< The VTOR location information is based on information from the linker with a dependency
     on the IDE, the cortex register is updated using the INTVECT_START.
*/
#if defined(__ICCARM__)
extern uint32_t __vector_table;
#define INTVECT_START ((uint32_t)& __vector_table)
#elif defined(__CC_ARM) || defined(__ARMCC_VERSION)
extern void * __Vectors;
#define INTVECT_START ((uint32_t) & __Vectors)
#elif defined(__GNUC__)
extern void * g_pfnVectors;
#define INTVECT_START ((uint32_t)& g_pfnVectors)
#endif /* __ICCARM__*/

/******************************************************************************/

/**
  * @}
  */

/** @addtogroup STM32WBAxx_System_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32WBAxx_System_Private_Variables
  * @{
  */
  /* The SystemCoreClock variable is updated in three ways:
      1) by calling CMSIS function SystemCoreClockUpdate()
      2) by calling HAL API function HAL_RCC_GetHCLKFreq()
      3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency
         Note: If you use this function to configure the system clock; then there
               is no need to call the 2 first functions listed above, since SystemCoreClock
               variable is updated automatically.
  */
  uint32_t SystemCoreClock = 16000000U; /* The HSI16 is used as system clock source after startup from reset, configured at 16 MHz. */

  const uint8_t AHBPrescTable[8] = {0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};
  const uint8_t APBPrescTable[8] = {0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};
  const uint8_t AHB5PrescTable[8] = {1U, 1U, 1U, 1U, 2U, 3U, 4U, 6U};
/**
  * @}
  */

/** @addtogroup STM32WBAxx_System_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32WBAxx_System_Private_Functions
  * @{
  */

/**
  * @brief  Setup the microcontroller system.
  * @param  None
  * @retval None
  */

void SystemInit(void)
{
#if defined(STM32WBAXX_SI_CUT1_0)
  __IO uint32_t timeout_cpu_cycles;
#endif
#if defined(STM32WBAXX_SI_CUT1_0) || defined (VREFBUF)
  __IO uint32_t tmpreg;
#endif

  /* SAU/IDAU, FPU and Interrupts secure/non-secure allocation settings */
  TZ_SAU_Setup();

  /* FPU settings ------------------------------------------------------------*/
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
  SCB->CPACR |= ((3UL << 20U)|(3UL << 22U));  /* set CP10 and CP11 Full Access */
#endif

  /* Configure the Vector Table location -------------------------------------*/
  SCB->VTOR = INTVECT_START;

#if defined(STM32WBAXX_SI_CUT1_0)
  /* Work-around for ADC peripheral issue possibly impacting system
     power consumption.
     Refer to STM32WBA errata sheet item "HSI16 clock cannot be stopped when
     used as kernel clock by ADC".
     Actions: Perform a ADC activation sequence in order to update state
               of internal signals.
  */
  /* Enable ADC kernel clock */
  SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_ADC4EN);
  /* Delay after an RCC peripheral clock enabling */
  tmpreg = READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_ADC4EN);
  (void)tmpreg;

  /* Enable ADC */
  SET_BIT(ADC4->CR, ADC_CR_ADEN);

  /* Poll for ADC ready */
  /* Set timeout 2 ADC clock cycles */
  /* Note: Approximative computation and timeout execution not taking into
           account processing CPU cycles */
  timeout_cpu_cycles = 2;
  while (READ_BIT(ADC4->ISR, ADC_ISR_ADRDY) == 0U)
  {
    timeout_cpu_cycles--;
    if(timeout_cpu_cycles == 0U)
    {
      break;
    }
  }

  /* Disable ADC */
  SET_BIT(ADC4->CR, ADC_CR_ADDIS);

  /* Poll for ADC disable is effective */
  /* Set timeout 6 ADC clock cycles */
  /* Note: Approximative computation and timeout execution not taking into
           account processing CPU cycles */
  timeout_cpu_cycles = 6;
  while (READ_BIT(ADC4->CR, ADC_CR_ADEN) != 0U)
  {
    timeout_cpu_cycles--;
    if(timeout_cpu_cycles == 0U)
    {
      break;
    }
  }

  /* Disable ADC internal voltage regulator */
  CLEAR_BIT(ADC4->CR, ADC_CR_ADVREGEN);

  /* Disable ADC kernel clock */
  CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_ADC4EN);
#endif

#if defined (VREFBUF)
  /* Work-around for VREFBUF peripheral issue.
     Refer to STM32WBA errata sheet item "VREF BUFF cannot be trimmed by EngiBit".
     Actions: Our SW copies the TRIM V11 (R1) in VREFBUF CCR (to guarantee the correct start
               trim instead the current bad value 111111).
  */
  /* Enable VREFBUF kernel clock */
  SET_BIT(RCC->APB7ENR, RCC_APB7ENR_VREFEN);
  /* Delay after an RCC peripheral clock enabling */
  tmpreg = READ_BIT(RCC->APB7ENR, RCC_APB7ENR_VREFEN);
  (void)tmpreg;

  /* Set TRIM V11 (R1) value */
  MODIFY_REG(VREFBUF->CCR, VREFBUF_CCR_TRIM, ((*(uint32_t *)(FLASH_ENGY_BASE + 0x2ABUL)) & 0x3FUL));

  /* Disable VREFBUF kernel clock */
  CLEAR_BIT(RCC->APB7ENR, RCC_APB7ENR_VREFEN);
#endif /* VREFBUF */
}

/**
  * @brief  Update SystemCoreClock variable according to Clock Register Values.
  *         The SystemCoreClock variable contains the core clock (HCLK), it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.
  *
  * @note   Depending on secure or non-secure compilation, the adequate RCC peripheral
  *         memory are is accessed thanks to RCC alias defined in stm32wbxxxx.h device file
  *         so either from RCC_S peripheral register mapped memory in secure or from
  *         RCC_NS peripheral register mapped memory in non-secure.
  *
  * @note   Each time the core clock (HCLK) changes, this function must be called
  *         to update SystemCoreClock variable value. Otherwise, any configuration
  *         based on this variable will be incorrect.
  *
  * @note   - The system frequency computed by this function is not the real
  *           frequency in the chip. It is calculated based on the predefined
  *           constant and the selected clock source:
  *
  *           - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(**)
  *
  *           - If SYSCLK source is HSE, SystemCoreClock will contain the HSE_VALUE(***)
  *
  *           - If SYSCLK source is PLL1, SystemCoreClock will contain the HSE_VALUE(***)
  *             or HSI_VALUE(*)  multiplied/divided by the PLL1 factors.
  *
  *         (**) HSI_VALUE is a constant defined in STM32WBAxx_hal.h file (default value
  *              16 MHz) but the real value may vary depending on the variations
  *              in voltage and temperature.
  *
  *         (***) HSE_VALUE is a constant defined in STM32WBAxx_hal.h file (default value
  *              32 MHz), user has to ensure that HSE_VALUE is same as the real
  *              frequency of the crystal used. Otherwise, this function may
  *              have wrong result.
  *
  *         - The result of this function could be not correct when using fractional
  *           value for HSE crystal.
  *
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate(void)
{
  uint32_t tmp1;
  uint32_t tmp2;
  uint32_t pllsource;
  uint32_t pllr;
  uint32_t pllm;
  uint32_t plln;
  float_t fracn;
  float_t pllvco;

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (RCC->CFGR1 & RCC_CFGR1_SWS)
  {
    case RCC_CFGR1_SWS_1:  /* HSE used as system clock source */
      SystemCoreClock = (HSE_VALUE >> ((RCC->CR & RCC_CR_HSEPRE) >> RCC_CR_HSEPRE_Pos));
      break;

    case (RCC_CFGR1_SWS_0 | RCC_CFGR1_SWS_1):  /* PLL1 used as system clock source */
      /* PLL_VCO = (PLLsource / PLLM) * PLLN * FractionnalPart
          SYSCLK = PLL_VCO / PLLR */
      /* Get PLL1 CFGR and DIVR register values */
      tmp1 = RCC->PLL1CFGR;
      tmp2 = RCC->PLL1DIVR;

      /* Retrieve PLL1 multiplication factor and divider */
      pllm = ((tmp1 & RCC_PLL1CFGR_PLL1M) >> RCC_PLL1CFGR_PLL1M_Pos) + 1U;
      plln = (tmp2 & RCC_PLL1DIVR_PLL1N) + 1U;
      pllr = ((tmp2 & RCC_PLL1DIVR_PLL1R) >> RCC_PLL1DIVR_PLL1R_Pos) + 1U;

      /* Check if fractional part is enable */
      if ((tmp1 & RCC_PLL1CFGR_PLL1FRACEN) != 0x00u)
      {
        fracn = (float_t)((uint32_t)((RCC->PLL1FRACR & RCC_PLL1FRACR_PLL1FRACN) >> RCC_PLL1FRACR_PLL1FRACN_Pos));
      }
      else
      {
        fracn = (float_t)0U;
      }

      /* determine PLL source */
      pllsource = (tmp1 & RCC_PLL1CFGR_PLL1SRC);
      switch (pllsource)
      {
        /* HSI used as PLL1 clock source */
        case RCC_PLL1CFGR_PLL1SRC_1:
          tmp1 = HSI_VALUE;
          break;

        /* HSE used as PLL1 clock source */
        case (RCC_PLL1CFGR_PLL1SRC_0 | RCC_PLL1CFGR_PLL1SRC_1):
          tmp1 = (HSE_VALUE >> ((RCC->CR & RCC_CR_HSEPRE) >> RCC_CR_HSEPRE_Pos));
          break;

        default:
          tmp1 = 0U;
          break;
      }

      /* Compute VCO output frequency */
      pllvco = ((float_t) tmp1 / (float_t)pllm) * (((float_t)plln + (float_t)(fracn / (float_t)0x2000U)));
      SystemCoreClock = (uint32_t)((float_t)(pllvco / (float_t)pllr));
      break;

    case 0x00u:  /* HSI used as system clock source */
    default:
      SystemCoreClock = HSI_VALUE;
      break;
  }

  /* Compute HCLK clock frequency --------------------------------------------*/
  /* Get HCLK prescaler */
  tmp1 = AHBPrescTable[(RCC->CFGR2 & RCC_CFGR2_HPRE)];

  /* HCLK clock frequency */
  SystemCoreClock >>= tmp1;
}

/**
  * @brief  Secure Non-Secure-Callable function to return the current
  *         SystemCoreClock value after SystemCoreClock update.
  *         The SystemCoreClock variable contains the core clock (HCLK), it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.
  * @retval SystemCoreClock value (HCLK)
  */
CMSE_NS_ENTRY uint32_t SECURE_SystemCoreClockUpdate(void)
{
  SystemCoreClockUpdate();

  return SystemCoreClock;
}


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
