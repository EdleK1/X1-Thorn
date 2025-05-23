/*
 * Dshot.h
 *
 *  Created on: May 15, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_LIB_DSHOTPROTOCOL_DSHOT_H_
#define SRC_USER_LIB_DSHOTPROTOCOL_DSHOT_H_

#include <stdint.h>
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_dma.h"
#include "dma.h"

#define POLES 6
#define ESC_BIT_0 300
#define ESC_BIT_1 600


uint8_t DShot_Init(void);
uint8_t DShot_SendFrame(uint16_t throttle1, uint16_t throttle2, uint32_t *last_erpm1, uint32_t *last_erpm2);
void DShot_MakeFrame(uint16_t throttle, uint16_t *dshotBits);
uint8_t DShot_DecodeTelemetry(uint32_t rawtelem, uint32_t *mRPM);
void TIM_PeriodElapsedCallback_TIM3(void);
void HAL_DMA_XferCpltCallback(DMA_HandleTypeDef *hdma);




#endif /* SRC_USER_LIB_DSHOTPROTOCOL_DSHOT_H_ */
