/**
 * @file RingBufferService.c
 * @author 
 * @brief
 * @version 0.1
 * @date 2022-02-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Modules/Inc/Services/RingBufferService.h"

#include <string.h>

RETURN_TYPE RingBuffer_SRV_Init(RingBuffer_S *pRingBuffer,
                                void *pRingBufferData,
                                uint16_t maxLen,
                                uint16_t elementSize) {
    if (!pRingBuffer || !pRingBufferData || maxLen == 0 || elementSize == 0) {
        return INVALID_PARAM_ERROR;
    }

    pRingBuffer->pBuffer     = pRingBufferData;
    pRingBuffer->head        = 0;
    pRingBuffer->tail        = 0;
    pRingBuffer->read        = 0;
    pRingBuffer->maxLen      = maxLen;
    pRingBuffer->elementSize = elementSize;

    return OK;
}

RETURN_TYPE RingBuffer_SRV_Queue(RingBuffer_S *pRingBuffer, const void *pData) {
    if (!pRingBuffer || !pData) {
        return INVALID_PARAM_ERROR;
    }

    uint16_t next = pRingBuffer->head + 1;
    if (next >= pRingBuffer->maxLen) {
        next = 0;
    }
    if (next == pRingBuffer->tail) {
        return BUFFER_OVERFLOW;
    }

    void *pIndex =
        pRingBuffer->pBuffer + (pRingBuffer->head * pRingBuffer->elementSize);

    memcpy(pIndex, pData, pRingBuffer->elementSize);

    pRingBuffer->head = next;

    return OK;
}

RETURN_TYPE RingBuffer_SRV_Dequeue(RingBuffer_S *pRingBuffer, void *pData) {
    if (!pRingBuffer || !pData) {
        return INVALID_PARAM_ERROR;
    }

    uint16_t next;
    if (pRingBuffer->head == pRingBuffer->read) {
        return BUFFER_EMPTY;
    }

    next = pRingBuffer->read + 1;
    if (next >= pRingBuffer->maxLen) {
        next = 0;
    }

    void *pIndex =
        pRingBuffer->pBuffer + (pRingBuffer->read * pRingBuffer->elementSize);
    memcpy(pData, pIndex, pRingBuffer->elementSize);

    pRingBuffer->read = next;
    pRingBuffer->tail = next;

    return OK;
}

RETURN_TYPE RingBuffer_SRV_Peek(RingBuffer_S *pRingBuffer, void *pData) {
    if (!pRingBuffer || !pData) {
        return INVALID_PARAM_ERROR;
    }

    uint16_t next;
    if (pRingBuffer->head == pRingBuffer->read) {
        return BUFFER_EMPTY;
    }
    next = pRingBuffer->read + 1;
    if (next >= pRingBuffer->maxLen) {
        next = 0;
    }

    void *pIndex =
        pRingBuffer->pBuffer + (pRingBuffer->read * pRingBuffer->elementSize);
    memcpy(pData, pIndex, pRingBuffer->elementSize);

    pRingBuffer->read = next;
    return OK;
}

RETURN_TYPE RingBuffer_SRV_PopPeek(RingBuffer_S *pRingBuffer) {
    if (!pRingBuffer) {
        return INVALID_PARAM_ERROR;
    }

    pRingBuffer->tail = pRingBuffer->read;
    return OK;
}

RETURN_TYPE RingBuffer_SRV_ResetPeek(RingBuffer_S *pRingBuffer) {
    if (!pRingBuffer) {
        return INVALID_PARAM_ERROR;
    }

    pRingBuffer->read = pRingBuffer->tail;
    return OK;
}

RETURN_TYPE RingBuffer_SRV_GetIsEmpty(const RingBuffer_S *pRingBuffer,
                                      uint8_t *pIsEmpty) {
    if (!pRingBuffer || !pIsEmpty) {
        return INVALID_PARAM_ERROR;
    }

    *pIsEmpty = pRingBuffer->head == pRingBuffer->tail;
    return OK;
}

RETURN_TYPE RingBuffer_SRV_GetIsFull(const RingBuffer_S *pRingBuffer,
                                     uint8_t *pIsFull) {
    if (!pRingBuffer || !pIsFull) {
        return INVALID_PARAM_ERROR;
    }

    uint16_t nextHeadPos = pRingBuffer->head + 1;
    if (nextHeadPos == pRingBuffer->maxLen) {
        nextHeadPos = 0;
    }

    *pIsFull = nextHeadPos == pRingBuffer->tail;
    return OK;
}

RETURN_TYPE RingBuffer_SRV_GetItemNumber(const RingBuffer_S *pRingBuffer,
                                         uint16_t *pItemNumber) {
    if (!pRingBuffer || !pItemNumber) {
        return INVALID_PARAM_ERROR;
    }

    uint8_t tmp;
    if (RingBuffer_SRV_GetIsEmpty(pRingBuffer, &tmp) && tmp) {
        *pItemNumber = 0;
    } else if (RingBuffer_SRV_GetIsFull(pRingBuffer, &tmp) && tmp) {
        *pItemNumber = pRingBuffer->maxLen - 1;
    } else {
        if (pRingBuffer->head < pRingBuffer->tail) {
            *pItemNumber =
                (pRingBuffer->tail - pRingBuffer->head) - pRingBuffer->maxLen;
        } else {
            *pItemNumber = pRingBuffer->head - pRingBuffer->tail;
        }
    }

    return OK;
}