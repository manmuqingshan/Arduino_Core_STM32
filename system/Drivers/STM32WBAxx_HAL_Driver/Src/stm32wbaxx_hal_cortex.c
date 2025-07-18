/**
  ******************************************************************************
  * @file    stm32wbaxx_hal_cortex.c
  * @author  MCD Application Team
  * @brief   CORTEX HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the CORTEX:
  *           + Initialization and Configuration functions
  *           + Peripheral Control functions
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
  @verbatim
  ==============================================================================
                        ##### How to use this driver #####
  ==============================================================================

    [..]
    *** How to configure Interrupts using CORTEX HAL driver ***
    ===========================================================
    [..]
    This section provides functions allowing to configure the NVIC interrupts (IRQ).
    The Cortex-M33 exceptions are managed by CMSIS functions.

    (#) Configure the NVIC Priority Grouping using HAL_NVIC_SetPriorityGrouping() function.
    (#) Configure the priority of the selected IRQ Channels using HAL_NVIC_SetPriority().
    (#) Enable the selected IRQ Channels using HAL_NVIC_EnableIRQ().

     -@- When the NVIC_PRIORITYGROUP_0 is selected, IRQ pre-emption is no more possible.
         The pending IRQ priority will be managed only by the sub priority.

     -@- IRQ priority order (sorted by highest to lowest priority):
        (+@) Lowest pre-emption priority
        (+@) Lowest sub priority
        (+@) Lowest hardware priority (IRQ number)

    [..]
    *** How to configure SysTick using CORTEX HAL driver ***
    ========================================================
    [..]
    Setup SysTick Timer for time base.

    (+) The SysTick clock source shall be configured with HAL_SYSTICK_CLKSourceConfig().

    (+) The SysTick IRQ priority shall be configured with HAL_NVIC_SetPriority(SysTick_IRQn,...).
        The HAL_NVIC_SetPriority() calls the CMSIS NVIC_SetPriority() function.

    (+) The HAL_SYSTICK_Config() function:
        (++) Configures the SysTick Reload register with the value passed as function parameter.
        (++) Resets the SysTick Counter register.
        (++) Enables the SysTick Interrupt.
        (++) Starts the SysTick Counter.

    (+) To adjust the SysTick time base, use the following formula:

        Reload Value = SysTick Counter Clock (Hz) x  Desired Time base (s)
        (++) Reload Value is the parameter to be passed for HAL_SYSTICK_Config() function
        (++) Reload Value should not exceed 0xFFFFFF

    (+) In case the HAL time base is the SysTick Timer, the HAL time base configuration must be completed
        by calling the HAL_InitTick() function.

    [..]
    *** How to configure MPU regions using CORTEX HAL driver ***
    ============================================================
    [..]
    This section provides functions allowing to configure the Memory Protection Unit (MPU).

    (#) Disable the MPU using HAL_MPU_Disable().
    (#) Configure the necessary MPU memory attributes using HAL_MPU_ConfigMemoryAttributes().
    (#) Configure the necessary MPU regions using HAL_MPU_ConfigRegion() ennsuring that the MPU region configuration link to
        the right MPU attributes number.
    (#) Enable the MPU using HAL_MPU_Enable() function.

     -@- The memory management fault exception is enabled in HAL_MPU_Enable() function and the system will enter the memory
         management fault handler MemManage_Handler() when an illegal memory access is performed.
     -@- If the MPU has previously been programmed, disable the unused regions to prevent any previous region configuration
         from affecting the new MPU configuration.
     -@- MPU APIs ending with '_NS' allow to control the non-secure Memory Protection Unit (MPU_NS) from the secure context
         and the same sequence as above applies to configure the non-secure MPU.

  @endverbatim
  ******************************************************************************

  The table below gives the allowed values of the pre-emption priority and subpriority according
  to the Priority Grouping configuration performed by HAL_NVIC_SetPriorityGrouping() function.

    ==========================================================================================================================
      NVIC_PriorityGroup   | NVIC_IRQChannelPreemptionPriority | NVIC_IRQChannelSubPriority  |       Description
    ==========================================================================================================================
     NVIC_PRIORITYGROUP_0  |                0                  |            0-15             | 0 bit for pre-emption priority
                           |                                   |                             | 4 bits for subpriority
    --------------------------------------------------------------------------------------------------------------------------
     NVIC_PRIORITYGROUP_1  |                0-1                |            0-7              | 1 bit for pre-emption priority
                           |                                   |                             | 3 bits for subpriority
    --------------------------------------------------------------------------------------------------------------------------
     NVIC_PRIORITYGROUP_2  |                0-3                |            0-3              | 2 bits for pre-emption priority
                           |                                   |                             | 2 bits for subpriority
    --------------------------------------------------------------------------------------------------------------------------
     NVIC_PRIORITYGROUP_3  |                0-7                |            0-1              | 3 bits for pre-emption priority
                           |                                   |                             | 1 bit for subpriority
    --------------------------------------------------------------------------------------------------------------------------
     NVIC_PRIORITYGROUP_4  |                0-15               |            0                | 4 bits for pre-emption priority
                           |                                   |                             | 0 bit for subpriority
    ==========================================================================================================================

  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32wbaxx_hal.h"

/** @addtogroup STM32WBAxx_HAL_Driver
  * @{
  */

/** @addtogroup CORTEX
  * @{
  */

#ifdef HAL_CORTEX_MODULE_ENABLED

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static void MPU_ConfigRegion(MPU_Type *MPUx, MPU_Region_InitTypeDef *MPU_RegionInit);
static void MPU_ConfigMemoryAttributes(MPU_Type *MPUx, MPU_Attributes_InitTypeDef *MPU_AttributesInit);
/* Exported functions --------------------------------------------------------*/

/** @addtogroup CORTEX_Exported_Functions
  * @{
  */


/** @addtogroup CORTEX_Exported_Functions_Group1
  *  @brief    Initialization and Configuration functions
  *
@verbatim
  ==============================================================================
              ##### Initialization and Configuration functions #####
  ==============================================================================
    [..]
      This section provides the CORTEX HAL driver functions allowing to configure Interrupts
      SysTick functionalities

@endverbatim
  * @{
  */


/**
  * @brief  Set the priority grouping field (pre-emption priority and subpriority)
  *         using the required unlock sequence.
  * @param  PriorityGroup: The priority grouping bits length.
  *         This parameter can be one of the following values:
  *         @arg NVIC_PRIORITYGROUP_0: 0 bit  for pre-emption priority,
  *                                    4 bits for subpriority
  *         @arg NVIC_PRIORITYGROUP_1: 1 bit  for pre-emption priority,
  *                                    3 bits for subpriority
  *         @arg NVIC_PRIORITYGROUP_2: 2 bits for pre-emption priority,
  *                                    2 bits for subpriority
  *         @arg NVIC_PRIORITYGROUP_3: 3 bits for pre-emption priority,
  *                                    1 bit  for subpriority
  *         @arg NVIC_PRIORITYGROUP_4: 4 bits for pre-emption priority,
  *                                    0 bit  for subpriority
  * @note   When the NVIC_PriorityGroup_0 is selected, IRQ pre-emption is no more possible.
  *         The pending IRQ priority will be managed only by the subpriority.
  * @retval None
  */
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  /* Check the parameters */
  assert_param(IS_NVIC_PRIORITY_GROUP(PriorityGroup));

  /* Set the PRIGROUP[10:8] bits according to the PriorityGroup parameter value */
  NVIC_SetPriorityGrouping(PriorityGroup);
}

/**
  * @brief  Set the priority of an interrupt.
  * @param  IRQn: External interrupt number.
  *         This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32wbaxxxx.h))
  * @param  PreemptPriority: The pre-emption priority for the IRQn channel.
  *         This parameter can be a value between 0 and 15
  *         A lower priority value indicates a higher priority
  * @param  SubPriority: the subpriority level for the IRQ channel.
  *         This parameter can be a value between 0 and 15
  *         A lower priority value indicates a higher priority.
  * @retval None
  */
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t prioritygroup;

  prioritygroup = (NVIC_GetPriorityGrouping() & 0x7U);

  /* Check the parameters */
  assert_param(IS_NVIC_SUB_PRIORITY(SubPriority, prioritygroup));
  assert_param(IS_NVIC_PREEMPTION_PRIORITY(PreemptPriority, prioritygroup));

  NVIC_SetPriority(IRQn, NVIC_EncodePriority(prioritygroup, PreemptPriority, SubPriority));
}

/**
  * @brief  Enable a device specific interrupt in the NVIC interrupt controller.
  * @note   To configure interrupts priority correctly, the NVIC_PriorityGroupConfig()
  *         function should be called before.
  * @param  IRQn External interrupt number.
  *         This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32wbaxxxx.h))
  * @retval None
  */
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn)
{
  /* Check the parameters */
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));

  /* Enable interrupt */
  NVIC_EnableIRQ(IRQn);
}

/**
  * @brief  Disable a device specific interrupt in the NVIC interrupt controller.
  * @param  IRQn External interrupt number.
  *         This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32wbaxxxx.h))
  * @retval None
  */
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn)
{
  /* Check the parameters */
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));

  /* Disable interrupt */
  NVIC_DisableIRQ(IRQn);
}

/**
  * @brief  Initiate a system reset request to reset the MCU.
  * @retval None
  */
void HAL_NVIC_SystemReset(void)
{
  /* System Reset */
  NVIC_SystemReset();
}

/**
  * @brief  Initialize the System Timer with interrupt enabled and start the System Tick Timer (SysTick):
  *         Counter is in free running mode to generate periodic interrupts.
  * @param  TicksNumb: Specifies the ticks Number of ticks between two interrupts.
  * @retval status:  - 0  Function succeeded.
  *                  - 1  Function failed.
  */
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb)
{
  if ((TicksNumb - 1UL) > SysTick_LOAD_RELOAD_Msk)
  {
    /* Reload value impossible */
    return (1UL);
  }

  /* Set reload register */
  WRITE_REG(SysTick->LOAD, (uint32_t)(TicksNumb - 1UL));

  /* Load the SysTick Counter Value */
  WRITE_REG(SysTick->VAL, 0UL);

  /* Enable SysTick IRQ and SysTick Timer */
  SET_BIT(SysTick->CTRL, (SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk));

  /* Function successful */
  return (0UL);
}
/**
  * @}
  */

/** @addtogroup CORTEX_Exported_Functions_Group2
  *  @brief   Cortex control functions
  *
@verbatim
  ==============================================================================
                      ##### Peripheral Control functions #####
  ==============================================================================
    [..]
      This subsection provides a set of functions allowing to control the CORTEX
      (NVIC, SYSTICK, MPU) functionalities.


@endverbatim
  * @{
  */

/**
  * @brief  Get the priority grouping field from the NVIC Interrupt Controller.
  * @retval Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field)
  */
uint32_t HAL_NVIC_GetPriorityGrouping(void)
{
  /* Get the PRIGROUP[10:8] field value */
  return NVIC_GetPriorityGrouping();
}

/**
  * @brief  Get the priority of an interrupt.
  * @param  IRQn: External interrupt number.
  *         This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32wbaxxxx.h))
  * @param   PriorityGroup: the priority grouping bits length.
  *         This parameter can be one of the following values:
  *           @arg NVIC_PRIORITYGROUP_0: 0 bit for pre-emption priority,
  *                                      4 bits for subpriority
  *           @arg NVIC_PRIORITYGROUP_1: 1 bit for pre-emption priority,
  *                                      3 bits for subpriority
  *           @arg NVIC_PRIORITYGROUP_2: 2 bits for pre-emption priority,
  *                                      2 bits for subpriority
  *           @arg NVIC_PRIORITYGROUP_3: 3 bits for pre-emption priority,
  *                                      1 bit for subpriority
  *           @arg NVIC_PRIORITYGROUP_4: 4 bits for pre-emption priority,
  *                                      0 bit for subpriority
  * @param  pPreemptPriority: Pointer on the Preemptive priority value (starting from 0).
  * @param  pSubPriority: Pointer on the Subpriority value (starting from 0).
  * @retval None
  */
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t *pPreemptPriority, uint32_t *pSubPriority)
{
  /* Check the parameters */
  assert_param(IS_NVIC_PRIORITY_GROUP(PriorityGroup));
  /* Get priority for Cortex-M system or device specific interrupts */
  NVIC_DecodePriority(NVIC_GetPriority(IRQn), PriorityGroup, pPreemptPriority, pSubPriority);
}

/**
  * @brief  Set Pending bit of an external interrupt.
  * @param  IRQn External interrupt number
  *         This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32wbaxxxx.h))
  * @retval None
  */
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  /* Set interrupt pending */
  NVIC_SetPendingIRQ(IRQn);
}

/**
  * @brief  Get Pending Interrupt (read the pending register in the NVIC
  *         and return the pending bit for the specified interrupt).
  * @param  IRQn External interrupt number.
  *          This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32wbaxxxx.h))
  * @retval status: - 0  Interrupt status is not pending.
  *                 - 1  Interrupt status is pending.
  */
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  /* Return 1 if pending else 0 */
  return NVIC_GetPendingIRQ(IRQn);
}

/**
  * @brief  Clear the pending bit of an external interrupt.
  * @param  IRQn External interrupt number.
  *         This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32wbaxxxx.h))
  * @retval None
  */
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  /* Clear pending interrupt */
  NVIC_ClearPendingIRQ(IRQn);
}

/**
  * @brief Get active interrupt (read the active register in NVIC and return the active bit).
  * @param IRQn External interrupt number
  *         This parameter can be an enumerator of IRQn_Type enumeration
  *         (For the complete STM32 Devices IRQ Channels list, please refer to the appropriate CMSIS device file (stm32wbaxxxx.h))
  * @retval status: - 0  Interrupt status is not pending.
  *                 - 1  Interrupt status is pending.
  */
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn)
{
  /* Return 1 if active else 0 */
  return NVIC_GetActive(IRQn);
}

/**
  * @brief  Configure the SysTick clock source.
  * @param  CLKSource: specifies the SysTick clock source.
  *          This parameter can be one of the following values:
  *             @arg SYSTICK_CLKSOURCE_LSI: LSI clock selected as SysTick clock source.
  *             @arg SYSTICK_CLKSOURCE_LSE: LSE clock selected as SysTick clock source.
  *             @arg SYSTICK_CLKSOURCE_HCLK: AHB clock selected as SysTick clock source.
  *             @arg SYSTICK_CLKSOURCE_HCLK_DIV8: AHB clock divided by 8 selected as SysTick clock source.
  *             @arg SYSTICK_CLKSOURCE_HSI_DIV4: HSI clock divided by 4 selected as SysTick clock source. (*)
  *
  *             (*) value not defined in all devices.
  * @retval None
  */
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource)
{
  /* Check the parameters */
  assert_param(IS_SYSTICK_CLK_SOURCE(CLKSource));
  switch (CLKSource)
  {
    /* Select HCLK as Systick clock source */
    case SYSTICK_CLKSOURCE_HCLK:
      SET_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk);
      break;
    /* Select HCLK_DIV8 as Systick clock source */
    case SYSTICK_CLKSOURCE_HCLK_DIV8:
      CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk);
      MODIFY_REG(RCC->CCIPR1, RCC_CCIPR1_SYSTICKSEL, (0x00000000U));
      break;
    /* Select LSI as Systick clock source */
    case SYSTICK_CLKSOURCE_LSI:
      CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk);
      MODIFY_REG(RCC->CCIPR1, RCC_CCIPR1_SYSTICKSEL, RCC_CCIPR1_SYSTICKSEL_0);
      break;
    /* Select LSE as Systick clock source */
    case SYSTICK_CLKSOURCE_LSE:
      CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk);
      MODIFY_REG(RCC->CCIPR1, RCC_CCIPR1_SYSTICKSEL, RCC_CCIPR1_SYSTICKSEL_1);
      break;
#if !defined (STM32WBA50xx) && !defined (STM32WBA52xx) && !defined (STM32WBA54xx) && !defined (STM32WBA55xx) && !defined (STM32WBA5Mxx)
    /* Select HSI_DIV4 as Systick clock source */
    case SYSTICK_CLKSOURCE_HSI_DIV4:
      CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk);
      MODIFY_REG(RCC->CCIPR1, RCC_CCIPR1_SYSTICKSEL, (RCC_CCIPR1_SYSTICKSEL_1 | RCC_CCIPR1_SYSTICKSEL_0));
      break;
#endif
    default:
      /* Nothing to do */
      break;
  }
}

/**
  * @brief  Get the SysTick clock source configuration.
  * @retval  SysTick clock source that can be one of the following values:
  *             @arg SYSTICK_CLKSOURCE_LSI: LSI clock selected as SysTick clock source.
  *             @arg SYSTICK_CLKSOURCE_LSE: LSE clock selected as SysTick clock source.
  *             @arg SYSTICK_CLKSOURCE_HCLK: AHB clock selected as SysTick clock source.
  *             @arg SYSTICK_CLKSOURCE_HCLK_DIV8: AHB clock divided by 8 selected as SysTick clock source.
  *             @arg SYSTICK_CLKSOURCE_HSI_DIV4: HSI clock divided by 4 selected as SysTick clock source. (*)
  *
  *             (*) value not defined in all devices.
  */
uint32_t HAL_SYSTICK_GetCLKSourceConfig(void)
{
  uint32_t systick_source;

  /* Read SysTick->CTRL register for internal or external clock source */
  if(READ_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk) != 0U)
  {
    /* Internal clock source */
    systick_source = SYSTICK_CLKSOURCE_HCLK;
  }
  else
  {
    /* External clock source, check the selected one in RCC */
    switch (__HAL_RCC_GET_SYSTICK_SOURCE())
    {
      case RCC_SYSTICKCLKSOURCE_LSI:
        systick_source = SYSTICK_CLKSOURCE_LSI;
        break;

      case RCC_SYSTICKCLKSOURCE_LSE:
        systick_source = SYSTICK_CLKSOURCE_LSE;
        break;

#if !defined (STM32WBA50xx) && !defined (STM32WBA52xx) && !defined (STM32WBA54xx) && !defined (STM32WBA55xx) && !defined (STM32WBA5Mxx)
      case RCC_SYSTICKCLKSOURCE_HSI_DIV4:
        systick_source = SYSTICK_CLKSOURCE_HSI_DIV4;
        break;
#endif

      default: /* RCC_SYSTICKCLKSOURCE_HCLK_DIV8 */
        systick_source = SYSTICK_CLKSOURCE_HCLK_DIV8;
        break;
    }
  }
  return systick_source;
}

/**
  * @brief  Handle SYSTICK interrupt request.
  * @retval None
  */
void HAL_SYSTICK_IRQHandler(void)
{
  HAL_SYSTICK_Callback();
}

/**
  * @brief  SYSTICK callback.
  * @retval None
  */
__weak void HAL_SYSTICK_Callback(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SYSTICK_Callback could be implemented in the user file
   */
}

/**
  * @brief  Enable the MPU.
  * @param  MPU_Control: Specifies the control mode of the MPU during hard fault,
  *          NMI, FAULTMASK and privileged accessto the default memory
  *          This parameter can be one of the following values:
  *            @arg MPU_HFNMI_PRIVDEF_NONE
  *            @arg MPU_HARDFAULT_NMI
  *            @arg MPU_PRIVILEGED_DEFAULT
  *            @arg MPU_HFNMI_PRIVDEF
  * @retval None
  */
void HAL_MPU_Enable(uint32_t MPU_Control)
{
  __DMB(); /* Data Memory Barrier operation to force any outstanding writes to memory before enabling the MPU */

  /* Enable the MPU */
  MPU->CTRL   = MPU_Control | MPU_CTRL_ENABLE_Msk;

  /* Enable fault exceptions */
  SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;

  /* Follow ARM recommendation with */
  /* Data Synchronization and Instruction Synchronization Barriers to ensure MPU configuration */
  __DSB(); /* Ensure that the subsequent instruction is executed only after the write to memory */
  __ISB(); /* Flush and refill pipeline with updated MPU configuration settings */
}

/**
  * @brief  Enable the MPU Region.
  * @retval None
  */
void HAL_MPU_EnableRegion(uint32_t RegionNumber)
{
  /* Check the parameters */
  assert_param(IS_MPU_REGION_NUMBER(RegionNumber));

  /* Set the Region number */
  MPU->RNR = RegionNumber;

  /* Enable the Region */
  SET_BIT(MPU->RLAR, MPU_RLAR_EN_Msk);
}

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  * @brief  Enable the non-secure MPU.
  * @param  MPU_Control: Specifies the control mode of the MPU during hard fault,
  *          NMI, FAULTMASK and privileged accessto the default memory
  *          This parameter can be one of the following values:
  *            @arg MPU_HFNMI_PRIVDEF_NONE
  *            @arg MPU_HARDFAULT_NMI
  *            @arg MPU_PRIVILEGED_DEFAULT
  *            @arg MPU_HFNMI_PRIVDEF
  * @retval None
  */
void HAL_MPU_Enable_NS(uint32_t MPU_Control)
{
  __DMB(); /* Data Memory Barrier operation to force any outstanding writes to memory before enabling the MPU */

  /* Enable the MPU */
  MPU_NS->CTRL   = MPU_Control | MPU_CTRL_ENABLE_Msk;

  /* Enable fault exceptions */
  SCB_NS->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;

  /* Follow ARM recommendation with */
  /* Data Synchronization and Instruction Synchronization Barriers to ensure MPU configuration */
  __DSB(); /* Ensure that the subsequent instruction is executed only after the write to memory */
  __ISB(); /* Flush and refill pipeline with updated MPU configuration settings */
}

/**
  * @brief  Enable the non-secure MPU Region.
  * @retval None
  */
void HAL_MPU_EnableRegion_NS(uint32_t RegionNumber)
{
  assert_param(IS_MPU_REGION_NUMBER(RegionNumber));

  /* Set the Region number */
  MPU_NS->RNR = RegionNumber;

  /* Enable the Region */
  SET_BIT(MPU_NS->RLAR, MPU_RLAR_EN_Msk);
}
#endif /* __ARM_FEATURE_CMSE */

/**
  * @brief  Disable the MPU.
  * @retval None
  */
void HAL_MPU_Disable(void)
{
  __DMB(); /* Force any outstanding transfers to complete before disabling MPU */

  /* Disable fault exceptions */
  SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;

  /* Disable the MPU */
  MPU->CTRL  &= ~MPU_CTRL_ENABLE_Msk;

  /* Follow ARM recommendation with */
  /* Data Synchronization and Instruction Synchronization Barriers to ensure MPU configuration */
  __DSB(); /* Ensure that the subsequent instruction is executed only after the write to memory */
  __ISB(); /* Flush and refill pipeline with updated MPU configuration settings */
}

/**
  * @brief  Disable the MPU Region.
  * @retval None
  */
void HAL_MPU_DisableRegion(uint32_t RegionNumber)
{
  /* Check the parameters */
  assert_param(IS_MPU_REGION_NUMBER(RegionNumber));

  /* Set the Region number */
  MPU->RNR = RegionNumber;

  /* Disable the Region */
  CLEAR_BIT(MPU->RLAR, MPU_RLAR_EN_Msk);
}

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
void HAL_MPU_Disable_NS(void)
{
  __DMB(); /* Force any outstanding transfers to complete before disabling MPU */

  /* Disable fault exceptions */
  SCB_NS->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;

  /* Disable the MPU */
  MPU_NS->CTRL  &= ~MPU_CTRL_ENABLE_Msk;

  /* Follow ARM recommendation with */
  /* Data Synchronization and Instruction Synchronization Barriers to ensure MPU configuration */
  __DSB(); /* Ensure that the subsequent instruction is executed only after the write to memory */
  __ISB(); /* Flush and refill pipeline with updated MPU configuration settings */
}

/**
  * @brief  Disable the non-secure MPU Region.
  * @retval None
  */
void HAL_MPU_DisableRegion_NS(uint32_t RegionNumber)
{
  /* Check the parameters */
  assert_param(IS_MPU_REGION_NUMBER(RegionNumber));

  /* Set the Region number */
  MPU_NS->RNR = RegionNumber;

  /* Disable the Region */
  CLEAR_BIT(MPU_NS->RLAR, MPU_RLAR_EN_Msk);
}
#endif /* __ARM_FEATURE_CMSE */

/**
  * @brief  Initialize and configure the Region and the memory to be protected.
  * @param  MPU_RegionInit: Pointer to a MPU_Region_InitTypeDef structure that contains
  *                the initialization and configuration information.
  * @retval None
  */
void HAL_MPU_ConfigRegion(MPU_Region_InitTypeDef *MPU_RegionInit)
{
  MPU_ConfigRegion(MPU, MPU_RegionInit);
}

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  * @brief  Initialize and configure the Region and the memory to be protected for non-secure MPU.
  * @param  MPU_RegionInit: Pointer to a MPU_Region_InitTypeDef structure that contains
  *                the initialization and configuration information.
  * @retval None
  */
void HAL_MPU_ConfigRegion_NS(MPU_Region_InitTypeDef *MPU_RegionInit)
{
  MPU_ConfigRegion(MPU_NS, MPU_RegionInit);
}
#endif /* __ARM_FEATURE_CMSE */

static void MPU_ConfigRegion(MPU_Type *MPUx, MPU_Region_InitTypeDef *MPU_RegionInit)
{
  /* Check the parameters */
  assert_param(IS_MPU_REGION_NUMBER(MPU_RegionInit->Number));
  assert_param(IS_MPU_REGION_ENABLE(MPU_RegionInit->Enable));
  assert_param(IS_MPU_INSTRUCTION_ACCESS(MPU_RegionInit->DisableExec));
  assert_param(IS_MPU_REGION_PERMISSION_ATTRIBUTE(MPU_RegionInit->AccessPermission));
  assert_param(IS_MPU_ACCESS_SHAREABLE(MPU_RegionInit->IsShareable));
  assert_param(IS_MPU_ATTRIBUTES_NUMBER(MPU_RegionInit->AttributesIndex));

  /* Follow ARM recommendation with Data Memory Barrier prior to MPU configuration */
  __DMB();

  /* Set the Region number */
  MPUx->RNR = MPU_RegionInit->Number;

   /* Disable the Region */
  CLEAR_BIT(MPUx->RLAR, MPU_RLAR_EN_Msk);

  MPUx->RBAR = (((uint32_t)MPU_RegionInit->BaseAddress & 0xFFFFFFE0U)  |
                ((uint32_t)MPU_RegionInit->IsShareable      << MPU_RBAR_SH_Pos)  |
                ((uint32_t)MPU_RegionInit->AccessPermission << MPU_RBAR_AP_Pos)  |
                ((uint32_t)MPU_RegionInit->DisableExec      << MPU_RBAR_XN_Pos));

  MPUx->RLAR = (((uint32_t)MPU_RegionInit->LimitAddress & 0xFFFFFFE0U) |
                ((uint32_t)MPU_RegionInit->AttributesIndex << MPU_RLAR_AttrIndx_Pos) |
                ((uint32_t)MPU_RegionInit->Enable          << MPU_RLAR_EN_Pos));
}
/**
  * @brief  Initialize and configure the memory attributes.
  * @param  MPU_AttributesInit: Pointer to a MPU_Attributes_InitTypeDef structure that contains
  *                the initialization and configuration information.
  * @retval None
  */
void HAL_MPU_ConfigMemoryAttributes(MPU_Attributes_InitTypeDef *MPU_AttributesInit)
{
  MPU_ConfigMemoryAttributes(MPU, MPU_AttributesInit);
}

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  * @brief  Initialize and configure the memory attributes for non-secure MPU.
  * @param  MPU_AttributesInit: Pointer to a MPU_Attributes_InitTypeDef structure that contains
  *                the initialization and configuration information.
  * @retval None
  */
void HAL_MPU_ConfigMemoryAttributes_NS(MPU_Attributes_InitTypeDef *MPU_AttributesInit)
{
  MPU_ConfigMemoryAttributes(MPU_NS, MPU_AttributesInit);
}
#endif /* __ARM_FEATURE_CMSE */

static void MPU_ConfigMemoryAttributes(MPU_Type *MPUx, MPU_Attributes_InitTypeDef *MPU_AttributesInit)
{
  __IO uint32_t *mair;
  uint32_t      attr_values;
  uint32_t      attr_number;

  /* Check the parameters */
  assert_param(IS_MPU_ATTRIBUTES_NUMBER(MPU_AttributesInit->Number));
  /* No need to check Attributes value as all 0x0..0xFF possible */

  /* Follow ARM recommendation with Data Memory Barrier prior to MPUx configuration */
  __DMB();

  if (MPU_AttributesInit->Number < MPU_ATTRIBUTES_NUMBER4)
  {
    /* Program MPU_MAIR0 */
    mair = &(MPUx->MAIR0);
    attr_number = MPU_AttributesInit->Number;
  }
  else
  {
    /* Program MPU_MAIR1 */
    mair = &(MPUx->MAIR1);
    attr_number = (uint32_t)MPU_AttributesInit->Number - 4U;
  }

  attr_values = *(mair);
  attr_values &=  ~(0xFFU << (attr_number * 8U));
  *(mair) = attr_values | ((uint32_t)MPU_AttributesInit->Attributes << (attr_number * 8U));
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_CORTEX_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */
