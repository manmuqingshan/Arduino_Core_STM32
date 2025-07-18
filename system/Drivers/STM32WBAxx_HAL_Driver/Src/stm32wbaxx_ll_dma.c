/**
  ******************************************************************************
  * @file    stm32wbaxx_ll_dma.c
  * @author  MCD Application Team
  * @brief   DMA LL module driver.
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
                        ##### LL DMA driver acronyms #####
  ==============================================================================
  [..]  Acronyms table :
                   =========================================
                   || Acronym ||                          ||
                   =========================================
                   || SRC     ||  Source                  ||
                   || DEST    ||  Destination             ||
                   || ADDR    ||  Address                 ||
                   || ADDRS   ||  Addresses               ||
                   || INC     ||  Increment / Incremented ||
                   || DEC     ||  Decrement / Decremented ||
                   || BLK     ||  Block                   ||
                   || RPT     ||  Repeat / Repeated       ||
                   || TRIG    ||  Trigger                 ||
                   =========================================
 @endverbatim
  ******************************************************************************
  */

#if defined (USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "stm32wbaxx_ll_dma.h"
#include "stm32wbaxx_ll_bus.h"
#ifdef  USE_FULL_ASSERT
#include "stm32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup STM32WBAxx_LL_Driver
  * @{
  */

#if defined (GPDMA1) || defined (LPDMA1)

/** @addtogroup DMA_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup DMA_LL_Private_Macros
  * @{
  */
#if defined (GPDMA1)
#define IS_LL_DMA_ALL_CHANNEL_INSTANCE(INSTANCE, Channel) (((INSTANCE) == GPDMA1)                && \
                                                           (((Channel)  == LL_DMA_CHANNEL_0)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_1)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_2)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_3)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_4)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_5)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_6)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_7)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_ALL)))
#endif /* GPDMA1 */
#if defined (LPDMA1)
#define IS_LL_DMA_ALL_CHANNEL_INSTANCE(INSTANCE, Channel) (((INSTANCE) == LPDMA1)                && \
                                                           (((Channel)  == LL_DMA_CHANNEL_0)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_1)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_2)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_3)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_4)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_5)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_6)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_7)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_ALL)))
#endif /* LPDMA1 */

#if  defined(GPDMA1)
#define IS_LL_GPDMA_CHANNEL_INSTANCE(INSTANCE, Channel)   (((INSTANCE) == GPDMA1)                && \
                                                           (((Channel)  == LL_DMA_CHANNEL_0)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_1)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_2)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_3)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_4)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_5)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_6)     || \
                                                            ((Channel)  == LL_DMA_CHANNEL_7)))

#endif /* GPDMA1 */
#if defined(GPDMA1)
#define IS_LL_DMA_DIRECTION(__VALUE__)                    (((__VALUE__) == LL_DMA_DIRECTION_MEMORY_TO_MEMORY) || \
                                                           ((__VALUE__) == LL_DMA_DIRECTION_PERIPH_TO_MEMORY) || \
                                                           ((__VALUE__) == LL_DMA_DIRECTION_MEMORY_TO_PERIPH))

#define IS_LL_DMA_DATA_ALIGNMENT(__VALUE__)               (((__VALUE__) == LL_DMA_DATA_ALIGN_ZEROPADD)    || \
                                                           ((__VALUE__) == LL_DMA_DATA_ALIGN_SIGNEXTPADD) || \
                                                           ((__VALUE__) == LL_DMA_DATA_PACK_UNPACK))
#endif /* GPDMA1 */
#if defined(LPDMA1)
#define IS_LL_DMA_DIRECTION(__VALUE__)                    (((__VALUE__) == LL_DMA_DIRECTION_MEMORY_TO_MEMORY) || \
                                                           ((__VALUE__) == LL_DMA_DIRECTION_PERIPH_TO_MEMORY))

#define IS_LL_DMA_DATA_ALIGNMENT(__VALUE__)               (((__VALUE__) == LL_DMA_DATA_ALIGN_ZEROPADD)    || \
                                                           ((__VALUE__) == LL_DMA_DATA_ALIGN_SIGNEXTPADD))
#endif /* LPDMA1 */

#define IS_LL_DMA_BURST_LENGTH(__VALUE__)                 (((__VALUE__) > 0U) && ((__VALUE__) <= 64U))

#define IS_LL_DMA_SRC_DATA_WIDTH(__VALUE__)               (((__VALUE__) == LL_DMA_SRC_DATAWIDTH_BYTE)     || \
                                                           ((__VALUE__) == LL_DMA_SRC_DATAWIDTH_HALFWORD) || \
                                                           ((__VALUE__) == LL_DMA_SRC_DATAWIDTH_WORD))

#define IS_LL_DMA_DEST_DATA_WIDTH(__VALUE__)              (((__VALUE__) == LL_DMA_DEST_DATAWIDTH_BYTE)     || \
                                                           ((__VALUE__) == LL_DMA_DEST_DATAWIDTH_HALFWORD) || \
                                                           ((__VALUE__) == LL_DMA_DEST_DATAWIDTH_WORD))

#define IS_LL_DMA_SRC_INCREMENT_MODE(__VALUE__)           (((__VALUE__) == LL_DMA_SRC_FIXED) || \
                                                           ((__VALUE__) == LL_DMA_SRC_INCREMENT))

#define IS_LL_DMA_DEST_INCREMENT_MODE(__VALUE__)          (((__VALUE__) == LL_DMA_DEST_FIXED) || \
                                                           ((__VALUE__) == LL_DMA_DEST_INCREMENT))

#define IS_LL_DMA_PRIORITY(__VALUE__)                     (((__VALUE__) == LL_DMA_LOW_PRIORITY_LOW_WEIGHT)  || \
                                                           ((__VALUE__) == LL_DMA_LOW_PRIORITY_MID_WEIGHT)  || \
                                                           ((__VALUE__) == LL_DMA_LOW_PRIORITY_HIGH_WEIGHT) || \
                                                           ((__VALUE__) == LL_DMA_HIGH_PRIORITY))

#define IS_LL_DMA_BLK_DATALENGTH(__VALUE__)                ((__VALUE__) <= 0xFFFFU)

#define IS_LL_DMA_BLK_REPEATCOUNT(__VALUE__)               ((__VALUE__) <= 0x0EFFU)

#define IS_LL_DMA_TRIGGER_MODE(__VALUE__)                 (((__VALUE__) == LL_DMA_TRIGM_BLK_TRANSFER)      || \
                                                           ((__VALUE__) == LL_DMA_TRIGM_RPT_BLK_TRANSFER)  || \
                                                           ((__VALUE__) == LL_DMA_TRIGM_LLI_LINK_TRANSFER) || \
                                                           ((__VALUE__) == LL_DMA_TRIGM_SINGLBURST_TRANSFER ))

#define IS_LL_DMA_TRIGGER_POLARITY(__VALUE__)             (((__VALUE__) == LL_DMA_TRIG_POLARITY_MASKED) || \
                                                           ((__VALUE__) == LL_DMA_TRIG_POLARITY_RISING) || \
                                                           ((__VALUE__) == LL_DMA_TRIG_POLARITY_FALLING))

#define IS_LL_DMA_BLKHW_REQUEST(__VALUE__)                (((__VALUE__) == LL_DMA_HWREQUEST_SINGLEBURST) || \
                                                           ((__VALUE__) == LL_DMA_HWREQUEST_BLK))

#if defined (GPDMA1)
#if defined (TIM4)
#define IS_LL_DMA_TRIGGER_SELECTION(__VALUE__)             ((__VALUE__) <= LL_GPDMA1_TRIGGER_TIM4_TRGO)
#else
#if defined (TIM3)
#define IS_LL_DMA_TRIGGER_SELECTION(__VALUE__)             ((__VALUE__) <= LL_GPDMA1_TRIGGER_TIM3_TRGO)
#else
#define IS_LL_DMA_TRIGGER_SELECTION(__VALUE__)             ((__VALUE__) <= LL_GPDMA1_TRIGGER_ADC4_AWD1)
#endif /* TIM3 */
#endif /* TIM4 */
#endif /* GPDMA1 */
#if defined (LPDMA1)
#define IS_LL_DMA_TRIGGER_SELECTION(__VALUE__)             ((__VALUE__) <= LL_LPDMA1_TRIGGER_ADC4_AWD1)
#endif /* LPDMA1 */


#if defined (GPDMA1)
#if defined (USART3)
#define IS_LL_DMA_REQUEST_SELECTION(__VALUE__)             ((__VALUE__) <= LL_GPDMA1_REQUEST_USART3_TX)
#else
#if defined (LPTIM2)
#define IS_LL_DMA_REQUEST_SELECTION(__VALUE__)             ((__VALUE__) <= LL_GPDMA1_REQUEST_LPTIM2_UE)
#else
#define IS_LL_DMA_REQUEST_SELECTION(__VALUE__)             ((__VALUE__) <= LL_GPDMA1_REQUEST_LPTIM1_UE)
#endif /* LPTIM2 */
#endif /* USART3 */
#endif /* GPDMA1 */
#if defined (LPDMA1)
#define IS_LL_DMA_REQUEST_SELECTION(__VALUE__)             ((__VALUE__) <= LL_LPDMA1_REQUEST_XSPI1)
#endif /* LPDMA1 */


#define IS_LL_DMA_TRANSFER_EVENT_MODE(__VALUE__)          (((__VALUE__) == LL_DMA_TCEM_BLK_TRANSFER)         || \
                                                           ((__VALUE__) == LL_DMA_TCEM_RPT_BLK_TRANSFER)     || \
                                                           ((__VALUE__) == LL_DMA_TCEM_EACH_LLITEM_TRANSFER) || \
                                                           ((__VALUE__) == LL_DMA_TCEM_LAST_LLITEM_TRANSFER))

#define IS_LL_DMA_DEST_HALFWORD_EXCHANGE(__VALUE__)       (((__VALUE__) == LL_DMA_DEST_HALFWORD_PRESERVE) || \
                                                           ((__VALUE__) == LL_DMA_DEST_HALFWORD_EXCHANGE))

#define IS_LL_DMA_DEST_BYTE_EXCHANGE(__VALUE__)           (((__VALUE__) == LL_DMA_DEST_BYTE_PRESERVE) || \
                                                           ((__VALUE__) == LL_DMA_DEST_BYTE_EXCHANGE))

#define IS_LL_DMA_SRC_BYTE_EXCHANGE(__VALUE__)            (((__VALUE__) == LL_DMA_SRC_BYTE_PRESERVE) || \
                                                           ((__VALUE__) == LL_DMA_SRC_BYTE_EXCHANGE))

#define IS_LL_DMA_LINK_ALLOCATED_PORT(__VALUE__)          (((__VALUE__) == LL_DMA_LINK_ALLOCATED_PORT0) || \
                                                           ((__VALUE__) == LL_DMA_LINK_ALLOCATED_PORT1))

#define IS_LL_DMA_SRC_ALLOCATED_PORT(__VALUE__)           (((__VALUE__) == LL_DMA_SRC_ALLOCATED_PORT0) || \
                                                           ((__VALUE__) == LL_DMA_SRC_ALLOCATED_PORT1))

#define IS_LL_DMA_DEST_ALLOCATED_PORT(__VALUE__)          (((__VALUE__) == LL_DMA_DEST_ALLOCATED_PORT0) || \
                                                           ((__VALUE__) == LL_DMA_DEST_ALLOCATED_PORT1))

#define IS_LL_DMA_LINK_STEP_MODE(__VALUE__)               (((__VALUE__) == LL_DMA_LSM_FULL_EXECUTION) || \
                                                           ((__VALUE__) == LL_DMA_LSM_1LINK_EXECUTION))

#define IS_LL_DMA_BURST_SRC_ADDR_UPDATE(__VALUE__)        (((__VALUE__) == LL_DMA_BURST_SRC_ADDR_INCREMENT) || \
                                                           ((__VALUE__) == LL_DMA_BURST_SRC_ADDR_DECREMENT))

#define IS_LL_DMA_BURST_DEST_ADDR_UPDATE(__VALUE__)       (((__VALUE__) == LL_DMA_BURST_DEST_ADDR_INCREMENT) || \
                                                           ((__VALUE__) == LL_DMA_BURST_DEST_ADDR_DECREMENT))

#define IS_LL_DMA_BURST_ADDR_UPDATE_VALUE(__VALUE__)       ((__VALUE__) <= 0x1FFFU)

#define IS_LL_DMA_BLKRPT_SRC_ADDR_UPDATE(__VALUE__)       (((__VALUE__) == LL_DMA_BLKRPT_SRC_ADDR_INCREMENT) || \
                                                           ((__VALUE__) == LL_DMA_BLKRPT_SRC_ADDR_DECREMENT))

#define IS_LL_DMA_BLKRPT_DEST_ADDR_UPDATE(__VALUE__)      (((__VALUE__) == LL_DMA_BLKRPT_DEST_ADDR_INCREMENT) || \
                                                           ((__VALUE__) == LL_DMA_BLKRPT_DEST_ADDR_DECREMENT))

#define IS_LL_DMA_BLKRPT_ADDR_UPDATE_VALUE(__VALUE__)      ((__VALUE__) <= 0xFFFFU)

#define IS_LL_DMA_LINK_BASEADDR(__VALUE__)                (((__VALUE__) & 0xFFFFU) == 0U)

#define IS_LL_DMA_LINK_ADDR_OFFSET(__VALUE__)             (((__VALUE__) & 0x03U) == 0U)

#define IS_LL_DMA_LINK_UPDATE_REGISTERS(__VALUE__)       ((((__VALUE__) & 0x01FE0000U) == 0U) && ((__VALUE__) != 0U))

#if defined (GPDMA1)
#define IS_LL_DMA_LINK_NODETYPE(TYPE)          \
  ((TYPE) == LL_DMA_GPDMA_LINEAR_NODE)
#endif /* GPDMA1 */
#if defined (LPDMA1)
#define IS_LL_DMA_LINK_NODETYPE(TYPE)          \
  ((TYPE) == LL_DMA_LPDMA_LINEAR_NODE)
#endif /* LPDMA1 */

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define IS_LL_DMA_CHANNEL_SRC_SEC(__VALUE__)              (((__VALUE__) == LL_DMA_CHANNEL_SRC_NSEC) || \
                                                           ((__VALUE__) == LL_DMA_CHANNEL_SRC_SEC))

#define IS_LL_DMA_CHANNEL_DEST_SEC(__VALUE__)             (((__VALUE__) == LL_DMA_CHANNEL_DEST_NSEC) || \
                                                           ((__VALUE__) == LL_DMA_CHANNEL_DEST_SEC))

#endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup DMA_LL_Exported_Functions
  * @{
  */

/** @addtogroup DMA_LL_EF_Init
  * @{
  */

/**
  * @brief De-initialize the DMA registers to their default reset values.
  * @note  This API is used for all available DMA channels.
  * @note  To convert DMAx_Channely Instance to DMAx Instance and Channely, use
  *        helper macros :
  *        @arg @ref LL_DMA_GET_INSTANCE
  *        @arg @ref LL_DMA_GET_CHANNEL
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_0
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS : DMA registers are de-initialized.
  *          - ERROR   : DMA registers are not de-initialized.
  */
uint32_t LL_DMA_DeInit(DMA_TypeDef *DMAx, uint32_t Channel)
{
  DMA_Channel_TypeDef *tmp;
  ErrorStatus status = SUCCESS;

  /* Check the DMA Instance DMAx and Channel parameters */
  assert_param(IS_LL_DMA_ALL_CHANNEL_INSTANCE(DMAx, Channel));

  if (Channel == LL_DMA_CHANNEL_ALL)
  {
#if defined(GPDMA1)
    /* Force reset of DMA clock */
    LL_AHB2_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_GPDMA1);

    /* Release reset of DMA clock */
    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_GPDMA1);
#endif /* GPDMA1 */
#if defined(LPDMA1)

    /* Force reset of DMA clock */
    LL_AHB2_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_LPDMA1);

    /* Release reset of DMA clock */
    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_LPDMA1);
#endif /* LPDMA1 */
  }
  else
  {
    /* Get the DMA Channel Instance */
    tmp = (DMA_Channel_TypeDef *)(LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel));

    /* Suspend DMA channel */
    LL_DMA_SuspendChannel(DMAx, Channel);

    /* Disable the selected Channel */
    LL_DMA_ResetChannel(DMAx, Channel);

    /* Reset DMAx_Channely control register */
    LL_DMA_WriteReg(tmp, CLBAR, 0U);

    /* Reset DMAx_Channely control register */
    LL_DMA_WriteReg(tmp, CCR, 0U);

    /* Reset DMAx_Channely Configuration register */
    LL_DMA_WriteReg(tmp, CTR1, 0U);

    /* Reset DMAx_Channely transfer register 2 */
    LL_DMA_WriteReg(tmp, CTR2, 0U);

    /* Reset DMAx_Channely block number of data register */
    LL_DMA_WriteReg(tmp, CBR1, 0U);

    /* Reset DMAx_Channely source address register */
    LL_DMA_WriteReg(tmp, CSAR, 0U);

    /* Reset DMAx_Channely destination address register */
    LL_DMA_WriteReg(tmp, CDAR, 0U);


    /* Reset DMAx_Channely Linked list address register */
    LL_DMA_WriteReg(tmp, CLLR, 0U);

    /* Reset DMAx_Channely pending flags */
    LL_DMA_WriteReg(tmp, CFCR, 0x00003F00U);
#if defined (DMA_PRIVCFGR_PRIV0)
    /* Reset DMAx_Channely attribute */
    LL_DMA_DisableChannelPrivilege(DMAx, Channel);
#endif /* DMA_PRIVCFGR_PRIV0 */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    LL_DMA_DisableChannelSecure(DMAx, Channel);
#endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
  }

  return (uint32_t)status;
}

/**
  * @brief Initialize the DMA registers according to the specified parameters
  *        in DMA_InitStruct.
  * @note  This API is used for all available DMA channels.
  * @note  A software request transfer can be done once programming the direction
  *        field in memory to memory value.
  * @note  To convert DMAx_Channely Instance to DMAx Instance and Channely, use
  *        helper macros :
  *        @arg @ref LL_DMA_GET_INSTANCE
  *        @arg @ref LL_DMA_GET_CHANNEL
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_0
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  DMA_InitStruct pointer to a @ref LL_DMA_InitTypeDef structure.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS : DMA registers are initialized.
  *          - ERROR   : Not applicable.
  */
uint32_t LL_DMA_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitTypeDef *DMA_InitStruct)
{
  /* Check the DMA Instance DMAx and Channel parameters*/
  assert_param(IS_LL_DMA_ALL_CHANNEL_INSTANCE(DMAx, Channel));

  /* Check the DMA parameters from DMA_InitStruct */
  assert_param(IS_LL_DMA_DIRECTION(DMA_InitStruct->Direction));

  /* Check direction */
  if (DMA_InitStruct->Direction != LL_DMA_DIRECTION_MEMORY_TO_MEMORY)
  {
    assert_param(IS_LL_DMA_REQUEST_SELECTION(DMA_InitStruct->Request));
  }

  assert_param(IS_LL_DMA_DATA_ALIGNMENT(DMA_InitStruct->DataAlignment));
  assert_param(IS_LL_DMA_SRC_DATA_WIDTH(DMA_InitStruct->SrcDataWidth));
  assert_param(IS_LL_DMA_DEST_DATA_WIDTH(DMA_InitStruct->DestDataWidth));
  assert_param(IS_LL_DMA_SRC_INCREMENT_MODE(DMA_InitStruct->SrcIncMode));
  assert_param(IS_LL_DMA_DEST_INCREMENT_MODE(DMA_InitStruct->DestIncMode));
  assert_param(IS_LL_DMA_PRIORITY(DMA_InitStruct->Priority));
  assert_param(IS_LL_DMA_BLK_DATALENGTH(DMA_InitStruct->BlkDataLength));
  assert_param(IS_LL_DMA_TRIGGER_POLARITY(DMA_InitStruct->TriggerPolarity));
  assert_param(IS_LL_DMA_BLKHW_REQUEST(DMA_InitStruct->BlkHWRequest));
  assert_param(IS_LL_DMA_TRANSFER_EVENT_MODE(DMA_InitStruct->TransferEventMode));
  assert_param(IS_LL_DMA_LINK_STEP_MODE(DMA_InitStruct->LinkStepMode));
  assert_param(IS_LL_DMA_LINK_BASEADDR(DMA_InitStruct->LinkedListBaseAddr));
  assert_param(IS_LL_DMA_LINK_ADDR_OFFSET(DMA_InitStruct->LinkedListAddrOffset));

  /* Check DMA instance */
#if defined(GPDMA1)
  if (IS_LL_GPDMA_CHANNEL_INSTANCE(DMAx, Channel) != 0U)
  {
    assert_param(IS_LL_DMA_BURST_LENGTH(DMA_InitStruct->SrcBurstLength));
    assert_param(IS_LL_DMA_BURST_LENGTH(DMA_InitStruct->DestBurstLength));
    assert_param(IS_LL_DMA_DEST_HALFWORD_EXCHANGE(DMA_InitStruct->DestHWordExchange));
    assert_param(IS_LL_DMA_DEST_BYTE_EXCHANGE(DMA_InitStruct->DestByteExchange));
    assert_param(IS_LL_DMA_SRC_BYTE_EXCHANGE(DMA_InitStruct->SrcByteExchange));
    assert_param(IS_LL_DMA_LINK_ALLOCATED_PORT(DMA_InitStruct->LinkAllocatedPort));
    assert_param(IS_LL_DMA_SRC_ALLOCATED_PORT(DMA_InitStruct->SrcAllocatedPort));
    assert_param(IS_LL_DMA_DEST_ALLOCATED_PORT(DMA_InitStruct->DestAllocatedPort));
  }
#endif /* GPDMA1 */

  /* Check trigger polarity */
  if (DMA_InitStruct->TriggerPolarity != LL_DMA_TRIG_POLARITY_MASKED)
  {
    assert_param(IS_LL_DMA_TRIGGER_MODE(DMA_InitStruct->TriggerMode));
    assert_param(IS_LL_DMA_TRIGGER_SELECTION(DMA_InitStruct->TriggerSelection));
  }


  /*-------------------------- DMAx CLBAR Configuration ------------------------
   * Configure the Transfer linked list address with parameter :
   * - LinkedListBaseAdd:                              DMA_CLBAR_LBA[31:16] bits
   */
  LL_DMA_SetLinkedListBaseAddr(DMAx, Channel, DMA_InitStruct->LinkedListBaseAddr);

  /*-------------------------- DMAx CCR Configuration --------------------------
   * Configure the control parameter :
   * - LinkAllocatedPort:                              DMA_CCR_LAP bit
   *   LinkAllocatedPort field is not supported by LPDMA channels.
   * - LinkStepMode:                                   DMA_CCR_LSM bit
   * - Priority:                                       DMA_CCR_PRIO [23:22] bits
   */
#if defined(GPDMA1)
  LL_DMA_ConfigControl(DMAx, Channel, DMA_InitStruct->Priority | \
                       DMA_InitStruct->LinkAllocatedPort       | \
                       DMA_InitStruct->LinkStepMode);
#endif /* GPDMA1 */
#if defined(LPDMA1)
  LL_DMA_ConfigControl(DMAx, Channel, DMA_InitStruct->Priority | \
                       DMA_InitStruct->LinkStepMode);
#endif /* LPDMA1 */

  /*-------------------------- DMAx CTR1 Configuration -------------------------
   * Configure the Data transfer  parameter :
   * - DestAllocatedPort:                         DMA_CTR1_DAP bit
   * - DestHWordExchange:                         DMA_CTR1_DHX bit
   * - DestByteExchange:                          DMA_CTR1_DBX bit
   * - DestIncMode:                               DMA_CTR1_DINC bit
   * - DestDataWidth:                             DMA_CTR1_DDW_LOG2 [17:16] bits
   * - SrcAllocatedPort:                          DMA_CTR1_SAP bit
   * - SrcByteExchange:                           DMA_CTR1_SBX bit
   * - DataAlignment:                             DMA_CTR1_PAM [12:11] bits
   * - SrcIncMode:                                DMA_CTR1_SINC bit
   * - SrcDataWidth:                              DMA_CTR1_SDW_LOG2 [1:0] bits
   * - SrcBurstLength:                            DMA_CTR1_SBL_1 [9:4] bits
   * - DestBurstLength:                           DMA_CTR1_DBL_1 [25:20] bits
   */
#if  defined(GPDMA1)
  LL_DMA_ConfigTransfer(DMAx, Channel, DMA_InitStruct->DestAllocatedPort | \
                        DMA_InitStruct->DestHWordExchange                | \
                        DMA_InitStruct->DestByteExchange                 | \
                        DMA_InitStruct->DestIncMode                      | \
                        DMA_InitStruct->DestDataWidth                    | \
                        DMA_InitStruct->SrcAllocatedPort                 | \
                        DMA_InitStruct->SrcByteExchange                  | \
                        DMA_InitStruct->DataAlignment                    | \
                        DMA_InitStruct->SrcIncMode                       | \
                        DMA_InitStruct->SrcDataWidth);
#endif /* GPDMA1 */
#if defined(LPDMA1)
  LL_DMA_ConfigTransfer(DMAx, Channel, DMA_InitStruct->DestIncMode       | \
                        DMA_InitStruct->DestDataWidth                    | \
                        DMA_InitStruct->DataAlignment                    | \
                        DMA_InitStruct->SrcIncMode                       | \
                        DMA_InitStruct->SrcDataWidth);
#endif /* LPDMA1 */
  /* Check DMA instance */
#if defined(GPDMA1)
  if (IS_LL_GPDMA_CHANNEL_INSTANCE(DMAx, Channel) != 0U)
#endif /* GPDMA1 */
#if defined(GPDMA1)
  {
    LL_DMA_ConfigBurstLength(DMAx, Channel,  DMA_InitStruct->SrcBurstLength,
                             DMA_InitStruct->DestBurstLength);
  }
#endif /* GPDMA1 */
  /*-------------------------- DMAx CTR2 Configuration -------------------------
   * Configure the channel transfer parameter :
   * - TransferEventMode:                          DMA_CTR2_TCEM [31:30] bits
   * - TriggerPolarity:                            DMA_CTR2_TRIGPOL [25:24] bits
   * - TriggerMode:                                DMA_CTR2_TRIGM  [15:14] bits
   * - BlkHWRequest:                               DMA_CTR2_BREQ bit
   * - Direction:                                  DMA_CTR2_DREQ bit
   * - Direction:                                  DMA_CTR2_SWREQ bit
   *   Direction field is reduced to one bit for LPDMA channels (SWREQ).
   * - TriggerSelection:                           DMA_CTR2_TRIGSEL [21:16] bits
   *   TriggerSelection field is reduced to 5 bits for LPDMA channels.
   * - Request:                                    DMA_CTR2_REQSEL [6:0] bits
   *   Request field is reduced to 5 bits for LPDMA channels.
   */
  LL_DMA_ConfigChannelTransfer(DMAx, Channel, DMA_InitStruct->TransferEventMode | \
                               DMA_InitStruct->TriggerPolarity                  | \
                               DMA_InitStruct->BlkHWRequest                     | \
                               DMA_InitStruct->Direction);

  /* Check direction */
  if (DMA_InitStruct->Direction != LL_DMA_DIRECTION_MEMORY_TO_MEMORY)
  {
    LL_DMA_SetPeriphRequest(DMAx, Channel, DMA_InitStruct->Request);
  }

  /* Check trigger polarity */
  if (DMA_InitStruct->TriggerPolarity != LL_DMA_TRIG_POLARITY_MASKED)
  {
    LL_DMA_SetHWTrigger(DMAx, Channel, DMA_InitStruct->TriggerSelection);
    LL_DMA_SetTriggerMode(DMAx, Channel, DMA_InitStruct->TriggerMode);
  }

  /*-------------------------- DMAx CBR1 Configuration -------------------------
   * Configure the Transfer Block counters and update mode with parameter :
   * - BlkDataLength:                                   DMA_CBR1_BNDT[15:0] bits
   */
  LL_DMA_SetBlkDataLength(DMAx, Channel, DMA_InitStruct->BlkDataLength);

  /*-------------------------- DMAx CSAR and CDAR Configuration ----------------
   * Configure the Transfer source address with parameter :
   * - SrcAddress:                                        DMA_CSAR_SA[31:0] bits
   * - DestAddress:                                       DMA_CDAR_DA[31:0] bits
   */
  LL_DMA_ConfigAddresses(DMAx, Channel, DMA_InitStruct->SrcAddress, DMA_InitStruct->DestAddress);

  /*-------------------------- DMAx CLLR Configuration -------------------------
   * Configure the Transfer linked list address with parameter :
   * - DestAddrOffset:                                    DMA_CLLR_LA[15:2] bits
   */
  LL_DMA_SetLinkedListAddrOffset(DMAx, Channel, DMA_InitStruct->LinkedListAddrOffset);

  return (uint32_t)SUCCESS;
}

/**
  * @brief  Set each @ref LL_DMA_InitTypeDef field to default value.
  * @param  DMA_InitStruct Pointer to a @ref LL_DMA_InitTypeDef structure.
  * @retval None.
  */
void LL_DMA_StructInit(LL_DMA_InitTypeDef *DMA_InitStruct)
{
  /* Set DMA_InitStruct fields to default values */
  DMA_InitStruct->SrcAddress               = 0x00000000U;
  DMA_InitStruct->DestAddress              = 0x00000000U;
  DMA_InitStruct->Direction                = LL_DMA_DIRECTION_MEMORY_TO_MEMORY;
  DMA_InitStruct->BlkHWRequest             = LL_DMA_HWREQUEST_SINGLEBURST;
  DMA_InitStruct->DataAlignment            = LL_DMA_DATA_ALIGN_ZEROPADD;
  DMA_InitStruct->SrcBurstLength           = 1U;
  DMA_InitStruct->DestBurstLength          = 1U;
  DMA_InitStruct->SrcDataWidth             = LL_DMA_SRC_DATAWIDTH_BYTE;
  DMA_InitStruct->DestDataWidth            = LL_DMA_DEST_DATAWIDTH_BYTE;
  DMA_InitStruct->SrcIncMode               = LL_DMA_SRC_FIXED;
  DMA_InitStruct->DestIncMode              = LL_DMA_DEST_FIXED;
  DMA_InitStruct->Priority                 = LL_DMA_LOW_PRIORITY_LOW_WEIGHT;
  DMA_InitStruct->BlkDataLength            = 0x00000000U;
  DMA_InitStruct->TriggerMode              = LL_DMA_TRIGM_BLK_TRANSFER;
  DMA_InitStruct->TriggerPolarity          = LL_DMA_TRIG_POLARITY_MASKED;
  DMA_InitStruct->TriggerSelection         = 0x00000000U;
  DMA_InitStruct->Request                  = 0x00000000U;
  DMA_InitStruct->TransferEventMode        = LL_DMA_TCEM_BLK_TRANSFER;
#if defined(GPDMA1)
  DMA_InitStruct->DestHWordExchange        = LL_DMA_DEST_HALFWORD_PRESERVE;
  DMA_InitStruct->DestByteExchange         = LL_DMA_DEST_BYTE_PRESERVE;
  DMA_InitStruct->SrcByteExchange          = LL_DMA_SRC_BYTE_PRESERVE;
  DMA_InitStruct->SrcAllocatedPort         = LL_DMA_SRC_ALLOCATED_PORT0;
  DMA_InitStruct->DestAllocatedPort        = LL_DMA_DEST_ALLOCATED_PORT0;
  DMA_InitStruct->LinkAllocatedPort        = LL_DMA_LINK_ALLOCATED_PORT0;
#endif /* GPDMA1 */
  DMA_InitStruct->LinkStepMode             = LL_DMA_LSM_FULL_EXECUTION;
  DMA_InitStruct->LinkedListBaseAddr       = 0x00000000U;
  DMA_InitStruct->LinkedListAddrOffset     = 0x00000000U;
}

/**
  * @brief  Set each @ref LL_DMA_InitLinkedListTypeDef field to default value.
  * @param  DMA_InitLinkedListStruct Pointer to
  *         a @ref LL_DMA_InitLinkedListTypeDef structure.
  * @retval None.
  */
void LL_DMA_ListStructInit(LL_DMA_InitLinkedListTypeDef *DMA_InitLinkedListStruct)
{
  /* Set LL_DMA_InitLinkedListTypeDef fields to default values */
  DMA_InitLinkedListStruct->Priority          = LL_DMA_LOW_PRIORITY_LOW_WEIGHT;
  DMA_InitLinkedListStruct->LinkStepMode      = LL_DMA_LSM_FULL_EXECUTION;
  DMA_InitLinkedListStruct->TransferEventMode = LL_DMA_TCEM_LAST_LLITEM_TRANSFER;
#if defined(GPDMA1)
  DMA_InitLinkedListStruct->LinkAllocatedPort = LL_DMA_LINK_ALLOCATED_PORT0;
#endif /* GPDMA1 */
}

/**
  * @brief De-initialize the DMA linked list.
  * @note  This API is used for all available DMA channels.
  * @note  To convert DMAx_Channely Instance to DMAx Instance and Channely, use
  *        helper macros :
  *        @arg @ref LL_DMA_GET_INSTANCE
  *        @arg @ref LL_DMA_GET_CHANNEL
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_0
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS : DMA registers are de-initialized.
  *          - ERROR   : DMA registers are not de-initialized.
  */
uint32_t LL_DMA_List_DeInit(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return LL_DMA_DeInit(DMAx, Channel);
}

/**
  * @brief Initialize the DMA linked list according to the specified parameters
  *        in LL_DMA_InitLinkedListTypeDef.
  * @note  This API is used for all available DMA channels.
  * @note  To convert DMAx_Channely Instance to DMAx Instance and Channely, use
  *        helper macros :
  *        @arg @ref LL_DMA_GET_INSTANCE
  *        @arg @ref LL_DMA_GET_CHANNEL
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_0
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  DMA_InitLinkedListStruct pointer to
  *         a @ref LL_DMA_InitLinkedListTypeDef structure.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS : DMA registers are initialized.
  *          - ERROR   : Not applicable.
  */
uint32_t LL_DMA_List_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitLinkedListTypeDef *DMA_InitLinkedListStruct)
{
  /* Check the DMA Instance DMAx and Channel parameters*/
  assert_param(IS_LL_DMA_ALL_CHANNEL_INSTANCE(DMAx, Channel));

  /* Check the DMA parameters from DMA_InitLinkedListStruct */
  assert_param(IS_LL_DMA_PRIORITY(DMA_InitLinkedListStruct->Priority));
  assert_param(IS_LL_DMA_LINK_STEP_MODE(DMA_InitLinkedListStruct->LinkStepMode));
  assert_param(IS_LL_DMA_TRANSFER_EVENT_MODE(DMA_InitLinkedListStruct->TransferEventMode));
  /* Check DMA instance */
#if defined(GPDMA1)
  if (IS_LL_GPDMA_CHANNEL_INSTANCE(DMAx, Channel) != 0U)
  {
    assert_param(IS_LL_DMA_LINK_ALLOCATED_PORT(DMA_InitLinkedListStruct->LinkAllocatedPort));
  }
#endif /* GPDMA1 */

  /*-------------------------- DMAx CCR Configuration --------------------------
   * Configure the control parameter :
   * - LinkAllocatedPort:                              DMA_CCR_LAP bit
   *   LinkAllocatedPort field is supported only by GPDMA channels.
   * - LinkStepMode:                                   DMA_CCR_LSM bit
   * - Priority:                                       DMA_CCR_PRIO [23:22] bits
   */
#if defined(GPDMA1)
  LL_DMA_ConfigControl(DMAx, Channel, DMA_InitLinkedListStruct->Priority | \
                       DMA_InitLinkedListStruct->LinkAllocatedPort       | \
                       DMA_InitLinkedListStruct->LinkStepMode);
#endif /* GPDMA1 */
#if defined(LPDMA1)
  LL_DMA_ConfigControl(DMAx, Channel, DMA_InitLinkedListStruct->Priority | \
                       DMA_InitLinkedListStruct->LinkStepMode);
#endif /* LPDMA1 */
  /*-------------------------- DMAx CTR2 Configuration -------------------------
   * Configure the channel transfer parameter :
   * - TransferEventMode:                          DMA_CTR2_TCEM [31:30] bits
   */
  LL_DMA_SetTransferEventMode(DMAx, Channel, DMA_InitLinkedListStruct->TransferEventMode);

  return (uint32_t)SUCCESS;
}

/**
  * @brief  Set each @ref LL_DMA_InitNodeTypeDef field to default value.
  * @param  DMA_InitNodeStruct Pointer to a @ref LL_DMA_InitNodeTypeDef
  *         structure.
  * @retval None.
  */
void LL_DMA_NodeStructInit(LL_DMA_InitNodeTypeDef *DMA_InitNodeStruct)
{
  /* Set DMA_InitNodeStruct fields to default values */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  DMA_InitNodeStruct->DestSecure               = LL_DMA_CHANNEL_DEST_NSEC;
#endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
#if defined(GPDMA1)
  DMA_InitNodeStruct->DestAllocatedPort        = LL_DMA_DEST_ALLOCATED_PORT0;
#endif /* GPDMA1 */
  DMA_InitNodeStruct->DestHWordExchange        = LL_DMA_DEST_HALFWORD_PRESERVE;
  DMA_InitNodeStruct->DestByteExchange         = LL_DMA_DEST_BYTE_PRESERVE;
  DMA_InitNodeStruct->DestBurstLength          = 1U;
  DMA_InitNodeStruct->DestIncMode              = LL_DMA_DEST_FIXED;
  DMA_InitNodeStruct->DestDataWidth            = LL_DMA_DEST_DATAWIDTH_BYTE;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  DMA_InitNodeStruct->SrcSecure                = LL_DMA_CHANNEL_SRC_NSEC;
#endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
#if defined(GPDMA1)
  DMA_InitNodeStruct->SrcAllocatedPort         = LL_DMA_SRC_ALLOCATED_PORT0;
#endif /* GPDMA1 */
  DMA_InitNodeStruct->SrcByteExchange          = LL_DMA_SRC_BYTE_PRESERVE;
  DMA_InitNodeStruct->DataAlignment            = LL_DMA_DATA_ALIGN_ZEROPADD;
  DMA_InitNodeStruct->SrcBurstLength           = 1U;
  DMA_InitNodeStruct->SrcIncMode               = LL_DMA_SRC_FIXED;
  DMA_InitNodeStruct->SrcDataWidth             = LL_DMA_SRC_DATAWIDTH_BYTE;
  DMA_InitNodeStruct->TransferEventMode        = LL_DMA_TCEM_BLK_TRANSFER;
  DMA_InitNodeStruct->TriggerPolarity          = LL_DMA_TRIG_POLARITY_MASKED;
  DMA_InitNodeStruct->TriggerSelection         = 0x00000000U;
  DMA_InitNodeStruct->TriggerMode              = LL_DMA_TRIGM_BLK_TRANSFER;
  DMA_InitNodeStruct->BlkHWRequest             = LL_DMA_HWREQUEST_SINGLEBURST;
  DMA_InitNodeStruct->Direction                = LL_DMA_DIRECTION_MEMORY_TO_MEMORY;
  DMA_InitNodeStruct->Request                  = 0x00000000U;
  DMA_InitNodeStruct->BlkDataLength            = 0x00000000U;
  DMA_InitNodeStruct->SrcAddress               = 0x00000000U;
  DMA_InitNodeStruct->DestAddress              = 0x00000000U;
  DMA_InitNodeStruct->UpdateRegisters          = (LL_DMA_UPDATE_CTR1 | LL_DMA_UPDATE_CTR2 | \
                                                  LL_DMA_UPDATE_CBR1 | LL_DMA_UPDATE_CSAR | \
                                                  LL_DMA_UPDATE_CDAR | LL_DMA_UPDATE_CLLR);
#if defined(GPDMA1)
  DMA_InitNodeStruct->NodeType                 = LL_DMA_GPDMA_LINEAR_NODE;
#endif /* GPDMA1 */
#if defined(LPDMA1)
  DMA_InitNodeStruct->NodeType                 = LL_DMA_LPDMA_LINEAR_NODE;
#endif /* LPDMA1 */
}

/**
  * @brief  Initializes DMA linked list node according to the specified
  *         parameters in the DMA_InitNodeStruct.
  * @param  DMA_InitNodeStruct Pointer to a LL_DMA_InitNodeTypeDef structure
  *         that contains linked list node
  *         registers configurations.
  * @param  pNode Pointer to linked list node to fill according to
  *         LL_DMA_LinkNodeTypeDef parameters.
  * @retval None
  */
uint32_t LL_DMA_CreateLinkNode(const LL_DMA_InitNodeTypeDef *DMA_InitNodeStruct, LL_DMA_LinkNodeTypeDef *pNode)
{
  uint32_t reg_counter = 0U;

  /* Check the DMA Node type */
  assert_param(IS_LL_DMA_LINK_NODETYPE(DMA_InitNodeStruct->NodeType));

  /* Check the DMA parameters from DMA_InitNodeStruct */
  assert_param(IS_LL_DMA_DIRECTION(DMA_InitNodeStruct->Direction));

  /* Check direction */
  if (DMA_InitNodeStruct->Direction != LL_DMA_DIRECTION_MEMORY_TO_MEMORY)
  {
    assert_param(IS_LL_DMA_REQUEST_SELECTION(DMA_InitNodeStruct->Request));
  }

  assert_param(IS_LL_DMA_DATA_ALIGNMENT(DMA_InitNodeStruct->DataAlignment));
  assert_param(IS_LL_DMA_SRC_DATA_WIDTH(DMA_InitNodeStruct->SrcDataWidth));
  assert_param(IS_LL_DMA_DEST_DATA_WIDTH(DMA_InitNodeStruct->DestDataWidth));
  assert_param(IS_LL_DMA_SRC_INCREMENT_MODE(DMA_InitNodeStruct->SrcIncMode));
  assert_param(IS_LL_DMA_DEST_INCREMENT_MODE(DMA_InitNodeStruct->DestIncMode));
  assert_param(IS_LL_DMA_BLK_DATALENGTH(DMA_InitNodeStruct->BlkDataLength));
  assert_param(IS_LL_DMA_TRIGGER_POLARITY(DMA_InitNodeStruct->TriggerPolarity));
  assert_param(IS_LL_DMA_BLKHW_REQUEST(DMA_InitNodeStruct->BlkHWRequest));
  assert_param(IS_LL_DMA_TRANSFER_EVENT_MODE(DMA_InitNodeStruct->TransferEventMode));
  assert_param(IS_LL_DMA_LINK_UPDATE_REGISTERS(DMA_InitNodeStruct->UpdateRegisters));

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  assert_param(IS_LL_DMA_CHANNEL_SRC_SEC(DMA_InitNodeStruct->SrcSecure));
  assert_param(IS_LL_DMA_CHANNEL_DEST_SEC(DMA_InitNodeStruct->DestSecure));
#endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

  /* Check trigger polarity */
  if (DMA_InitNodeStruct->TriggerPolarity != LL_DMA_TRIG_POLARITY_MASKED)
  {
    assert_param(IS_LL_DMA_TRIGGER_MODE(DMA_InitNodeStruct->TriggerMode));
    assert_param(IS_LL_DMA_TRIGGER_SELECTION(DMA_InitNodeStruct->TriggerSelection));
  }

  /* Check node type */
#if defined(GPDMA1)
  if (DMA_InitNodeStruct->NodeType == LL_DMA_GPDMA_LINEAR_NODE)
#endif /* GPDMA1 */
  {
#if defined(GPDMA1)
    assert_param(IS_LL_DMA_DEST_HALFWORD_EXCHANGE(DMA_InitNodeStruct->DestHWordExchange));
    assert_param(IS_LL_DMA_DEST_BYTE_EXCHANGE(DMA_InitNodeStruct->DestByteExchange));
    assert_param(IS_LL_DMA_SRC_BYTE_EXCHANGE(DMA_InitNodeStruct->SrcByteExchange));
    assert_param(IS_LL_DMA_SRC_ALLOCATED_PORT(DMA_InitNodeStruct->SrcAllocatedPort));
    assert_param(IS_LL_DMA_DEST_ALLOCATED_PORT(DMA_InitNodeStruct->DestAllocatedPort));
#endif /* GPDMA1 */
  }


  /* Check if CTR1 register update is enabled */
  if ((DMA_InitNodeStruct->UpdateRegisters & LL_DMA_UPDATE_CTR1) == LL_DMA_UPDATE_CTR1)
  {
    /*-------------------------- DMAx CTR1 Configuration -----------------------
    * Configure the Data transfer  parameter :
    * - DestAllocatedPort:                        DMA_CTR1_DAP bit
    *   DestAllocatedPort field is not supported by LPDMA channels.
    * - DestHWordExchange:                        DMA_CTR1_DHX bit
    *   DestHWordExchange field is not supported by LPDMA channels.
    * - DestByteExchange:                         DMA_CTR1_DBX bit
    *   DestByteExchange field is not supported by LPDMA channels.
    * - DestIncMode:                              DMA_CTR1_DINC bit
    * - DestDataWidth:                            DMA_CTR1_DDW_LOG2 [17:16] bits
    * - SrcAllocatedPort:                         DMA_CTR1_SAP bit
    *   SrcAllocatedPort field is not supported by LPDMA channels.
    * - SrcByteExchange:                          DMA_CTR1_SBX bit
    *   SrcByteExchange field is not supported by LPDMA channels.
    * - DataAlignment:                            DMA_CTR1_PAM [12:11] bits
    *   DataAlignment field is reduced to one bit for LPDMA channels.
    * - SrcIncMode:                               DMA_CTR1_SINC bit
    * - SrcDataWidth:                             DMA_CTR1_SDW_LOG2 [1:0] bits
    * - SrcBurstLength:                           DMA_CTR1_SBL_1 [9:4] bits
    *   SrcBurstLength field is not supported by LPDMA channels.
    * - DestBurstLength:                          DMA_CTR1_DBL_1 [25:20] bits
    *   DestBurstLength field is not supported by LPDMA channels.
    */

    pNode->LinkRegisters[reg_counter] = (DMA_InitNodeStruct->DestIncMode   | \
                                         DMA_InitNodeStruct->DestDataWidth | \
                                         DMA_InitNodeStruct->DataAlignment | \
                                         DMA_InitNodeStruct->SrcIncMode    | \
                                         DMA_InitNodeStruct->SrcDataWidth);

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    pNode->LinkRegisters[reg_counter] |= (DMA_InitNodeStruct->DestSecure | \
                                          DMA_InitNodeStruct->SrcSecure);
#endif /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */


#if defined(GPDMA1)
    /* Update CTR1 register fields */
    pNode->LinkRegisters[reg_counter] |= (DMA_InitNodeStruct->DestAllocatedPort                              | \
                                          DMA_InitNodeStruct->DestHWordExchange                              | \
                                          DMA_InitNodeStruct->DestByteExchange                               | \
                                          ((DMA_InitNodeStruct->DestBurstLength - 1U) << DMA_CTR1_DBL_1_Pos) | \
                                          DMA_InitNodeStruct->SrcAllocatedPort                               | \
                                          DMA_InitNodeStruct->SrcByteExchange                                | \
                                          ((DMA_InitNodeStruct->SrcBurstLength - 1U) << DMA_CTR1_SBL_1_Pos));
#endif /* GPDMA1 */

    /* Increment counter for the next register */
    reg_counter++;
  }


  /* Check if CTR2 register update is enabled */
  if ((DMA_InitNodeStruct->UpdateRegisters & LL_DMA_UPDATE_CTR2) == LL_DMA_UPDATE_CTR2)
  {
    /*-------------------------- DMAx CTR2 Configuration -----------------------
     * Configure the channel transfer parameter :
     * - TransferEventMode:                        DMA_CTR2_TCEM [31:30] bits
     * - TriggerPolarity:                          DMA_CTR2_TRIGPOL [25:24] bits
     * - TriggerMode:                              DMA_CTR2_TRIGM  [15:14] bits
     * - BlkHWRequest:                             DMA_CTR2_BREQ bit
     * - Direction:                                DMA_CTR2_DREQ bit
     * - Direction:                                DMA_CTR2_SWREQ bit
     *   Direction field is reduced to one bit for LPDMA channels (SWREQ).
     * - TriggerSelection:                         DMA_CTR2_TRIGSEL [21:16] bits
     *   DataAlignment field is reduced to 5 bits for LPDMA channels.
     * - Request:                                  DMA_CTR2_REQSEL [6:0] bits
     *   DataAlignment field is reduced to 5 bits for LPDMA channels.
     */
    pNode->LinkRegisters[reg_counter] = (DMA_InitNodeStruct->TransferEventMode | \
                                         DMA_InitNodeStruct->TriggerPolarity   | \
                                         DMA_InitNodeStruct->BlkHWRequest      | \
                                         DMA_InitNodeStruct->Direction);

    /* Check direction */
    if (DMA_InitNodeStruct->Direction != LL_DMA_DIRECTION_MEMORY_TO_MEMORY)
    {
      pNode->LinkRegisters[reg_counter] |= DMA_InitNodeStruct->Request & DMA_CTR2_REQSEL;
    }

    /* Check trigger polarity */
    if (DMA_InitNodeStruct->TriggerPolarity != LL_DMA_TRIG_POLARITY_MASKED)
    {
      pNode->LinkRegisters[reg_counter] |= (((DMA_InitNodeStruct->TriggerSelection << DMA_CTR2_TRIGSEL_Pos) & \
                                             DMA_CTR2_TRIGSEL) | DMA_InitNodeStruct->TriggerMode);
    }

#if defined(LPDMA1)
    /* Update CTR2 register fields for LPDMA */
    if (DMA_InitNodeStruct->NodeType == LL_DMA_LPDMA_LINEAR_NODE)
    {
      pNode->LinkRegisters[reg_counter] &= (~(1UL << 21U) & ~(3UL << 5U));
    }
#endif /* LPDMA1 */

    /* Increment counter for the next register */
    reg_counter++;
  }
  /* Check if CBR1 register update is enabled */
  if ((DMA_InitNodeStruct->UpdateRegisters & LL_DMA_UPDATE_CBR1) == LL_DMA_UPDATE_CBR1)
  {
    /*-------------------------- DMAx CBR1 Configuration -----------------------
     * Configure the Transfer Block counters and update mode with parameter :
     * - BlkDataLength:                                 DMA_CBR1_BNDT[15:0] bits
     */
    pNode->LinkRegisters[reg_counter] = DMA_InitNodeStruct->BlkDataLength;

    /* Increment counter for the next register */
    reg_counter++;
  }
  /* Check if CSAR register update is enabled */
  if ((DMA_InitNodeStruct->UpdateRegisters & LL_DMA_UPDATE_CSAR) == LL_DMA_UPDATE_CSAR)
  {
    /*-------------------------- DMAx CSAR Configuration -----------------------
     * Configure the Transfer Block counters and update mode with parameter :
     * - SrcAddress:                                         DMA_CSAR_SA[31:0] bits
     */
    pNode->LinkRegisters[reg_counter] = DMA_InitNodeStruct->SrcAddress;

    /* Increment counter for the next register */
    reg_counter++;
  }


  /* Check if CDAR register update is enabled */
  if ((DMA_InitNodeStruct->UpdateRegisters & LL_DMA_UPDATE_CDAR) == LL_DMA_UPDATE_CDAR)
  {
    /*-------------------------- DMAx CDAR Configuration -----------------------
     * Configure the Transfer Block counters and update mode with parameter :
     * - DestAddress:                                        DMA_CDAR_DA[31:0] bits
     */
    pNode->LinkRegisters[reg_counter] = DMA_InitNodeStruct->DestAddress;

    /* Increment counter for the next register */
    reg_counter++;
  }

  /* Check if CLLR register update is enabled */
  if ((DMA_InitNodeStruct->UpdateRegisters & LL_DMA_UPDATE_CLLR) == LL_DMA_UPDATE_CLLR)
  {
    /*-------------------------- DMAx CLLR Configuration -----------------------
    * Configure the Transfer Block counters and update mode with parameter :
    * - UpdateRegisters                                         DMA_CLLR_UT1 bit
    * - UpdateRegisters                                         DMA_CLLR_UT2 bit
    * - UpdateRegisters                                         DMA_CLLR_UB1 bit
    * - UpdateRegisters                                         DMA_CLLR_USA bit
    * - UpdateRegisters                                         DMA_CLLR_UDA bit
    * - UpdateRegisters                                         DMA_CLLR_ULL bit
    */
    pNode->LinkRegisters[reg_counter] = ((DMA_InitNodeStruct->UpdateRegisters & (DMA_CLLR_UT1 | DMA_CLLR_UT2 | \
                                                                                 DMA_CLLR_UB1 | DMA_CLLR_USA | \
                                                                                 DMA_CLLR_UDA | DMA_CLLR_ULL)));

  }
  else
  {
    /* Reset of the CLLR of the node being created */
    pNode->LinkRegisters[reg_counter] = 0U;
  }

  return (uint32_t)SUCCESS;
}

/**
  * @brief  Connect Linked list Nodes.
  * @param  pPrevLinkNode Pointer to previous linked list node to be connected to new Linked list node.
  * @param  PrevNodeCLLRIdx Offset of Previous Node CLLR register.
  *         This parameter can be a value of @ref DMA_LL_EC_CLLR_OFFSET.
  * @param  pNewLinkNode Pointer to new Linked list.
  * @param  NewNodeCLLRIdx Offset of New Node CLLR register.
  *         This parameter can be a value of @ref DMA_LL_EC_CLLR_OFFSET.
  * @retval None
  */
void LL_DMA_ConnectLinkNode(LL_DMA_LinkNodeTypeDef *pPrevLinkNode, uint32_t PrevNodeCLLRIdx,
                            LL_DMA_LinkNodeTypeDef *pNewLinkNode, uint32_t NewNodeCLLRIdx)
{
  pPrevLinkNode->LinkRegisters[PrevNodeCLLRIdx] = (((uint32_t)pNewLinkNode & DMA_CLLR_LA)                        | \
                                                   (pNewLinkNode->LinkRegisters[NewNodeCLLRIdx] & (DMA_CLLR_UT1  | \
                                                       DMA_CLLR_UT2 | DMA_CLLR_UB1 | DMA_CLLR_USA | DMA_CLLR_UDA | \
                                                       DMA_CLLR_ULL)));
}

/**
  * @brief  Disconnect the next linked list node.
  * @param  pLinkNode Pointer to linked list node to be disconnected from the next one.
  * @param  LinkNodeCLLRIdx Offset of Link Node CLLR register.
  * @retval None.
  */
void LL_DMA_DisconnectNextLinkNode(LL_DMA_LinkNodeTypeDef *pLinkNode, uint32_t LinkNodeCLLRIdx)
{
  pLinkNode->LinkRegisters[LinkNodeCLLRIdx] = 0;
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

#endif /* GPDMA1 || LPDMA1 */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */
