/**
 * @file TimerService.h
 * @author
 * @brief
 * @version 0.1
 * @date 2020-10-06
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef TIMER_SERVICE_H_
#define TIMER_SERVICE_H_


#include "Modules/Inc/Models/ReturnType.h"


#include <stdint.h>

typedef uint32_t timer_t;

/**
 * @brief Reseta o timer.
 *
 * @param pTimer Ponteiro para timer que será reiniciado.
 * @return RETURN_TYPE
 */
RETURN_TYPE Timer_SRV_ResetTimer(timer_t *pTimer);

/**
 * @brief Checa o tempo decorrido desde quando o timer foi reiniciado.
 *
 * @param timer Timer a ser checado.
 * @return uint32_t Tempo decorrido.
 */
uint32_t Timer_SRV_GetElapsedTime(timer_t timer);

/**
 * @brief Indica quando o tempo esperado expirou em milisegundos.
 *
 * @param timer Timer a ser checado.
 * @param timeMs Valor de tempo em milissegundos.
 * @return uint8_t 0 caso tempo  expirado, 1 caso tempo expirado.
 */
uint8_t Timer_SRV_WaitTimeMSec(timer_t timer, uint32_t timeMs);

/**
 * @brief Indica quando o tempo esperado expirou em segundos.
 *
 * @param timer Timer a ser checado.
 * @param timeSec Valor de tempo em segundos.
 * @return uint8_t 0 caso tempo  expirado, 1 caso tempo expirado.
 */
uint8_t Timer_SRV_WaitTimeSec(timer_t timer, uint16_t timeSec);

#endif  // TIMER_SERVICE_H_
