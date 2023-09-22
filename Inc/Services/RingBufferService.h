/**
 * @file RingBufferService.h
 * @author
 * @brief
 * @version 0.1
 * @date 2022-02-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef RING_BUFF_SRV_H_
#define RING_BUFF_SRV_H_

#include <stdint.h>

#include "Models/ReturnType.h"

typedef struct RingBuffer_S {
    void *pBuffer;
    uint16_t head;
    uint16_t tail;
    uint16_t read;
    uint16_t maxLen;
    uint16_t elementSize;
} RingBuffer_S;

RETURN_TYPE RingBuffer_SRV_Init(RingBuffer_S *pRingBuffer,
                                void *pRingBufferData,
                                uint16_t maxLen,
                                uint16_t elementSize);

RETURN_TYPE RingBuffer_SRV_Queue(RingBuffer_S *pRingBuffer, const void *pData);

RETURN_TYPE RingBuffer_SRV_Dequeue(RingBuffer_S *pRingBuffer, void *pData);

RETURN_TYPE RingBuffer_SRV_Peek(RingBuffer_S *pRingBuffer, void *pData);

RETURN_TYPE RingBuffer_SRV_PopPeek(RingBuffer_S *pRingBuffer);

RETURN_TYPE RingBuffer_SRV_ResetPeek(RingBuffer_S *pRingBuffer);

RETURN_TYPE RingBuffer_SRV_GetIsEmpty(const RingBuffer_S *pRingBuffer,
                                      uint8_t *pIsEmpty);

RETURN_TYPE RingBuffer_SRV_GetIsFull(const RingBuffer_S *pRingBuffer,
                                     uint8_t *pIsFull);

RETURN_TYPE RingBuffer_SRV_GetItemNumber(const RingBuffer_S *pRingBuffer,
                                         uint16_t *pItemNumber);

#endif /* RING_BUFF_SRV_H_ */