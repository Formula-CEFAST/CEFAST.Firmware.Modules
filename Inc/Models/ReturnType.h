/**
 * @file ReturnType.h
 * @author 
 * @brief
 * @version 0.1
 * @date 2022-02-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef RETURN_TYPE_H_
#define RETURN_TYPE_H_

#include <main.h>

typedef enum RETURN_TYPE
{
    CHECKSUM_ERROR        = -16,
    INVALID_PARAM_ERROR   = -15,
    NOT_INITIALIZED_ERROR = -14,
    SD_WRITE_ERROR        = -13,
    BUFFER_OVERFLOW       = -12,
    BUFFER_EMPTY          = -11,
    CRC_ERROR             = -10,
    HW_ERROR              = -9,
    STAGE_ONE_ERROR       = -8,
    BUSY_ERROR            = -7,
    TIMEOUT_ERROR         = -6,
    FAILED                = -5,
    GENERAL_ERROR         = -4,
    IS_BUSY               = -3,
    ABORTED               = -2,
    DETECTED              = -1,
    OK                    = 0,
} RETURN_TYPE;

/**
 * @brief Converte o retorno do HAL para RETURN_STATUS
 *
 * @param status status fornecido pelo HAL
 * @return RETURN_STATUS
 */
RETURN_TYPE PARSE_HAL_STATUS(HAL_StatusTypeDef status);

#endif /* RETURN_TYPE_H_ */