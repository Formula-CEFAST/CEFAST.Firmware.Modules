/**
 * @file ReturnType.c
 * @author 
 * @brief
 * @version 0.1
 * @date 2022-02-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Modules/Inc/Models/ReturnType.h"

RETURN_TYPE PARSE_HAL_STATUS(HAL_StatusTypeDef status) {
    switch (status) {
        case HAL_OK:
            return OK;
            break;
        case HAL_BUSY:
            return BUSY_ERROR;
            break;
        case HAL_TIMEOUT:
            return TIMEOUT_ERROR;
            break;
        case HAL_ERROR:
            return HW_ERROR;
        default:
            return GENERAL_ERROR;
    }
}
