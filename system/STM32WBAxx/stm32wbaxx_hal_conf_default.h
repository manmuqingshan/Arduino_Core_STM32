/**
  ******************************************************************************
  * @file    stm32wbaxx_hal_conf_template.h
  * @brief   HAL default configuration template file.
  *          This file should be copied to the application folder and renamed
  *          to stm32wbaxx_hal_conf.h.
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
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32WBAxx_HAL_CONF_DEFAULT_H
#define STM32WBAxx_HAL_CONF_DEFAULT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* ########################## Module Selection ############################## */
/**
  * @brief Include the default list of modules to be used in the HAL driver
  *        and manage module deactivation
  */
#include "stm32yyxx_hal_conf.h"
#if 0
/**
  * @brief This is the list of modules to be used in the HAL driver
  */
#define HAL_MODULE_ENABLED
#define HAL_ADC_MODULE_ENABLED
#define HAL_COMP_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED
#define HAL_CRC_MODULE_ENABLED
#define HAL_CRYP_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_EXTI_MODULE_ENABLED
#define HAL_FLASH_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_GTZC_MODULE_ENABLED
#define HAL_HASH_MODULE_ENABLED
#define HAL_HCD_MODULE_ENABLED
#define HAL_HSEM_MODULE_ENABLED
#define HAL_I2C_MODULE_ENABLED
#define HAL_ICACHE_MODULE_ENABLED
#define HAL_IRDA_MODULE_ENABLED
#define HAL_IWDG_MODULE_ENABLED
#define HAL_LPTIM_MODULE_ENABLED
#define HAL_PCD_MODULE_ENABLED
#define HAL_PKA_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_RAMCFG_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_RNG_MODULE_ENABLED
#define HAL_RTC_MODULE_ENABLED
#define HAL_SAI_MODULE_ENABLED
#define HAL_SMARTCARD_MODULE_ENABLED
#define HAL_SMBUS_MODULE_ENABLED
#define HAL_SPI_MODULE_ENABLED
#define HAL_TIM_MODULE_ENABLED
#define HAL_TSC_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HAL_USART_MODULE_ENABLED
#define HAL_WWDG_MODULE_ENABLED
#define HAL_XSPI_MODULE_ENABLED
#endif

/* ########################## Oscillator Values adaptation ####################*/
/**
  * @brief Adjust the value of External High Speed oscillator (HSE) used in your application.
  *        This value is used by the RCC HAL module to compute the system frequency
  *        (when HSE is used as system clock source, directly or through the PLL).
  */
#if !defined (HSE_VALUE)
#define HSE_VALUE              32000000UL /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined (HSE_STARTUP_TIMEOUT)
#define HSE_STARTUP_TIMEOUT    100UL   /*!< Time out for HSE start up, in ms */
#endif /* HSE_STARTUP_TIMEOUT */

/**
  * @brief Internal High Speed oscillator (HSI) value.
  *        This value is used by the RCC HAL module to compute the system frequency
  *        (when HSI is used as system clock source, directly or through the PLL).
  */
#if !defined (HSI_VALUE)
#define HSI_VALUE              16000000UL /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

/**
  * @brief Internal Low Speed oscillator (LSI) value.
  */
#if !defined (LSI_VALUE)
#define LSI_VALUE               32000UL    /*!< LSI Typical Value in Hz*/
#endif /* LSI_VALUE */                     /*!< Value of the Internal Low Speed oscillator in Hz
                                                The real value may vary depending on the variations in voltage
                                                and temperature.*/

#if defined (RCC_LSI2_SUPPORT)
#if !defined (LSI2_VALUE)
#define LSI2_VALUE              32000UL    /*!< LSI2 Typical Value in Hz*/
#endif /* LSI2_VALUE */
#endif

/**
  * @brief External Low Speed oscillator (LSE) value.
  *        This value is used by the UART, RTC HAL module to compute the system frequency
  */
#if !defined (LSE_VALUE)
#define LSE_VALUE              32768UL   /*!< Value of the External oscillator in Hz*/
#endif /* LSE_VALUE */

#if !defined (LSE_STARTUP_TIMEOUT)
#define LSE_STARTUP_TIMEOUT    5000UL     /*!< Time out for LSE start up, in ms */
#endif /* HSE_STARTUP_TIMEOUT */

/**
  * @brief External clock source for SAI1 peripheral
  *        This value is used by the RCC HAL module to compute the SAI1 & SAI2 clock source
  *        frequency.
  */
#if !defined (EXTERNAL_SAI1_CLOCK_VALUE)
#define EXTERNAL_SAI1_CLOCK_VALUE  48000UL /*!< Value of the SAI1 External clock source in Hz*/
#endif /* EXTERNAL_SAI1_CLOCK_VALUE */

/* Tip: To avoid modifying this file each time you need to use different HSE,
   ===  you can define the HSE value in your toolchain compiler preprocessor. */

/* ########################### System Configuration ######################### */
/**
  * @brief This is the HAL system configuration section
  */
#if !defined (VDD_VALUE)
#define  VDD_VALUE                    3300UL /*!< Value of VDD in mv */
#endif
#if !defined (TICK_INT_PRIORITY)
#define  TICK_INT_PRIORITY            ((1UL<<__NVIC_PRIO_BITS) - 1UL)  /*!< tick interrupt priority (lowest by default) */
#endif
#if !defined (USE_RTOS)
#define  USE_RTOS                     0U
#endif
#if !defined (PREFETCH_ENABLE)
#define  PREFETCH_ENABLE              1U               /*!< Enable prefetch */
#endif

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* ################## Register callback feature configuration ############### */
/**
  * @brief Set below the peripheral configuration  to "1U" to add the support
  *        of HAL callback registration/unregistration feature for the HAL
  *        driver(s). This allows user application to provide specific callback
  *        functions thanks to HAL_PPP_RegisterCallback() rather than overwriting
  *        the default weak callback functions (see each stm32wbaxx_hal_ppp.h file
  *        for possible callback identifiers defined in HAL_PPP_CallbackIDTypeDef
  *        for each PPP peripheral).
  */
#define  USE_HAL_ADC_REGISTER_CALLBACKS        0U /* ADC register callback disabled       */
#define  USE_HAL_COMP_REGISTER_CALLBACKS       0U /* COMP register callback disabled      */
#define  USE_HAL_CRYP_REGISTER_CALLBACKS       0U /* CRYP register callback disabled      */
#define  USE_HAL_HASH_REGISTER_CALLBACKS       0U /* HASH register callback disabled      */
#define  USE_HAL_HCD_REGISTER_CALLBACKS        0U /* HCD register callback disabled       */
#define  USE_HAL_I2C_REGISTER_CALLBACKS        0U /* I2C register callback disabled       */
#define  USE_HAL_IRDA_REGISTER_CALLBACKS       0U /* IRDA register callback disabled      */
#define  USE_HAL_IWDG_REGISTER_CALLBACKS       0U /* IWDG register callback disabled      */
#define  USE_HAL_LPTIM_REGISTER_CALLBACKS      0U /* LPTIM register callback disabled     */
#define  USE_HAL_PCD_REGISTER_CALLBACKS        0U /* PCD register callback disabled       */
#define  USE_HAL_PKA_REGISTER_CALLBACKS        0U /* PKA register callback disabled       */
#define  USE_HAL_RAMCFG_REGISTER_CALLBACKS     0U /* RAMCFG register callback disabled    */
#define  USE_HAL_RNG_REGISTER_CALLBACKS        0U /* RNG register callback disabled       */
#define  USE_HAL_RTC_REGISTER_CALLBACKS        0U /* RTC register callback disabled       */
#define  USE_HAL_SAI_REGISTER_CALLBACKS        0U /* SAI register callback disabled       */
#define  USE_HAL_SMARTCARD_REGISTER_CALLBACKS  0U /* SMARTCARD register callback disabled */
#define  USE_HAL_SMBUS_REGISTER_CALLBACKS      0U /* SMBUS register callback disabled     */
#define  USE_HAL_SPI_REGISTER_CALLBACKS        0U /* SPI register callback disabled       */
#define  USE_HAL_TIM_REGISTER_CALLBACKS        0U /* TIM register callback disabled       */
#define  USE_HAL_TSC_REGISTER_CALLBACKS        0U /* TSC register callback disabled       */
#define  USE_HAL_UART_REGISTER_CALLBACKS       0U /* UART register callback disabled      */
#define  USE_HAL_USART_REGISTER_CALLBACKS      0U /* USART register callback disabled     */
#define  USE_HAL_WWDG_REGISTER_CALLBACKS       0U /* WWDG register callback disabled      */
#define  USE_HAL_XSPI_REGISTER_CALLBACKS       0U /* XSPI register callback disabled      */

/* ################## SPI peripheral configuration ########################## */

/* CRC FEATURE: Use to activate CRC feature inside HAL SPI Driver
 * Activated: CRC code is present inside driver
 * Deactivated: CRC code cleaned from driver
 */
#define USE_SPI_CRC                   1U

/* ################## CRYP peripheral configuration ########################## */

#define USE_HAL_CRYP_SUSPEND_RESUME   0U

/* ################## HASH peripheral configuration ########################## */

#define USE_HAL_HASH_SUSPEND_RESUME   0U

/* Includes ------------------------------------------------------------------*/
/**
  * @brief Include module's header file
  */
#ifdef HAL_DMA_MODULE_ENABLED
#include "stm32wbaxx_hal_dma.h"
#endif /* HAL_DMA_MODULE_ENABLED */

#ifdef HAL_RCC_MODULE_ENABLED
#include "stm32wbaxx_hal_rcc.h"
#endif /* HAL_RCC_MODULE_ENABLED */

#ifdef HAL_ADC_MODULE_ENABLED
#include "stm32wbaxx_hal_adc.h"
#endif /* HAL_ADC_MODULE_ENABLED */

#ifdef HAL_COMP_MODULE_ENABLED
#include "stm32wbaxx_hal_comp.h"
#endif /* HAL_COMP_MODULE_ENABLED */

#ifdef HAL_CORTEX_MODULE_ENABLED
#include "stm32wbaxx_hal_cortex.h"
#endif /* HAL_CORTEX_MODULE_ENABLED */

#ifdef HAL_CRC_MODULE_ENABLED
#include "stm32wbaxx_hal_crc.h"
#endif /* HAL_CRC_MODULE_ENABLED */

#ifdef HAL_CRYP_MODULE_ENABLED
#include "stm32wbaxx_hal_cryp.h"
#endif /* HAL_CRYP_MODULE_ENABLED */

#ifdef HAL_EXTI_MODULE_ENABLED
#include "stm32wbaxx_hal_exti.h"
#endif /* HAL_EXTI_MODULE_ENABLED */

#ifdef HAL_FLASH_MODULE_ENABLED
#include "stm32wbaxx_hal_flash.h"
#endif /* HAL_FLASH_MODULE_ENABLED */

#ifdef HAL_GPIO_MODULE_ENABLED
#include "stm32wbaxx_hal_gpio.h"
#endif /* HAL_GPIO_MODULE_ENABLED */

#ifdef HAL_GTZC_MODULE_ENABLED
#include "stm32wbaxx_hal_gtzc.h"
#endif /* HAL_GTZC_MODULE_ENABLED */

#ifdef HAL_HASH_MODULE_ENABLED
#include "stm32wbaxx_hal_hash.h"
#endif /* HAL_HASH_MODULE_ENABLED */

#ifdef HAL_HCD_MODULE_ENABLED
#include "stm32wbaxx_hal_hcd.h"
#endif /* HAL_HCD_MODULE_ENABLED */

#ifdef HAL_HSEM_MODULE_ENABLED
#include "stm32wbaxx_hal_hsem.h"
#endif /* HAL_HSEM_MODULE_ENABLED */

#ifdef HAL_I2C_MODULE_ENABLED
#include "stm32wbaxx_hal_i2c.h"
#endif /* HAL_I2C_MODULE_ENABLED */

#ifdef HAL_ICACHE_MODULE_ENABLED
#include "stm32wbaxx_hal_icache.h"
#endif /* HAL_ICACHE_MODULE_ENABLED */

#ifdef HAL_IRDA_MODULE_ENABLED
#include "stm32wbaxx_hal_irda.h"
#endif /* HAL_IRDA_MODULE_ENABLED */

#ifdef HAL_IWDG_MODULE_ENABLED
#include "stm32wbaxx_hal_iwdg.h"
#endif /* HAL_IWDG_MODULE_ENABLED */

#ifdef HAL_LPTIM_MODULE_ENABLED
#include "stm32wbaxx_hal_lptim.h"
#endif /* HAL_LPTIM_MODULE_ENABLED */

#ifdef HAL_PCD_MODULE_ENABLED
#include "stm32wbaxx_hal_pcd.h"
#endif /* HAL_PCD_MODULE_ENABLED */

#ifdef HAL_PKA_MODULE_ENABLED
#include "stm32wbaxx_hal_pka.h"
#endif /* HAL_PKA_MODULE_ENABLED */

#ifdef HAL_PWR_MODULE_ENABLED
#include "stm32wbaxx_hal_pwr.h"
#endif /* HAL_PWR_MODULE_ENABLED */

#ifdef HAL_RAMCFG_MODULE_ENABLED
#include "stm32wbaxx_hal_ramcfg.h"
#endif /* HAL_RAMCFG_MODULE_ENABLED */

#ifdef HAL_RNG_MODULE_ENABLED
#include "stm32wbaxx_hal_rng.h"
#endif /* HAL_RNG_MODULE_ENABLED */

#ifdef HAL_RTC_MODULE_ENABLED
#include "stm32wbaxx_hal_rtc.h"
#endif /* HAL_RTC_MODULE_ENABLED */

#ifdef HAL_SAI_MODULE_ENABLED
#include "stm32wbaxx_hal_sai.h"
#endif /* HAL_SAI_MODULE_ENABLED */

#ifdef HAL_SMARTCARD_MODULE_ENABLED
#include "stm32wbaxx_hal_smartcard.h"
#endif /* HAL_SMARTCARD_MODULE_ENABLED */

#ifdef HAL_SMBUS_MODULE_ENABLED
#include "stm32wbaxx_hal_smbus.h"
#endif /* HAL_SMBUS_MODULE_ENABLED */

#ifdef HAL_SPI_MODULE_ENABLED
#include "stm32wbaxx_hal_spi.h"
#endif /* HAL_SPI_MODULE_ENABLED */

#ifdef HAL_TIM_MODULE_ENABLED
#include "stm32wbaxx_hal_tim.h"
#endif /* HAL_TIM_MODULE_ENABLED */

#ifdef HAL_TSC_MODULE_ENABLED
#include "stm32wbaxx_hal_tsc.h"
#endif /* HAL_TSC_MODULE_ENABLED */

#ifdef HAL_UART_MODULE_ENABLED
#include "stm32wbaxx_hal_uart.h"
#endif /* HAL_UART_MODULE_ENABLED */

#ifdef HAL_USART_MODULE_ENABLED
#include "stm32wbaxx_hal_usart.h"
#endif /* HAL_USART_MODULE_ENABLED */

#ifdef HAL_WWDG_MODULE_ENABLED
#include "stm32wbaxx_hal_wwdg.h"
#endif /* HAL_WWDG_MODULE_ENABLED */

#ifdef HAL_XSPI_MODULE_ENABLED
#include "stm32wbaxx_hal_xspi.h"
#endif /* HAL_XSPI_MODULE_ENABLED */

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *         which reports the name of the source file and the source
  *         line number of the call that failed.
  *         If expr is true, it returns no value.
  * @retval None
  */
#define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t *file, uint32_t line);
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
}
#endif

#endif /* STM32WBAxx_HAL_CONF_DEFAULT_H */
