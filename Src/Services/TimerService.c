/**
 * @file TimerService.c
 * @author 
 * @brief 
 * @version 0.1
 * @date 2022-02-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Modules/Inc/Services/TimerService.h"

#define MAX_TIME ((timer_t)-1)

#define relactiveTime(init_t, final_t)                         \
    (init_t > final_t) ? (((MAX_TIME - init_t) + final_t) + 1) \
                       : (final_t - init_t)

RETURN_TYPE Timer_SRV_ResetTimer(timer_t *pTimer) {
    *pTimer = HAL_GetTick();

    return OK;
}

uint32_t Timer_SRV_GetElapsedTime(timer_t timer) {
    const timer_t ft = HAL_GetTick();
    return (uint32_t)relactiveTime(timer, ft);
}

uint8_t Timer_SRV_WaitTimeMSec(timer_t timer, uint32_t timeMs) {
    const timer_t ft = HAL_GetTick();
    return !(relactiveTime(timer, ft) < timeMs);
}

uint8_t Timer_SRV_WaitTimeSec(timer_t timer, uint16_t timeSec) {
    const timer_t ft = HAL_GetTick();
    return !(relactiveTime(timer, ft) < ((timer_t)timeSec * 1000));
}
