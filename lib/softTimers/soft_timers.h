//========================================================================
#ifndef SOFT_TIMERS_H

#define SOFT_TIMERS_H

#include "soft_timers.h"

#include "main_def_func.h"
//========================================================================

//========================================================================
// Выбор: с прерыванием или с опросом флага OCFx.
#define __ST_NO_INTERRUPT__ // __ST_NO_INTERRUPT__ // __ST_INTERRUPT__

// Состав структуры: bool status, u08 sys_tick_prev, u16 cnt, u16 period.
// Итого 6 байтов на один программный таймер. Если убрать элемент period,
// то теперь будет 4 байта на таймер.
#define __ST_NO_PERIOD__ // __ST_PERIOD__ // __ST_NO_PERIOD__
//========================================================================

//========================================================================
#define ST_TCNT         TCNT0
#define ST_TIMSK        TIMSK0
#define ST_OCIE         OCIE0A
#define ST_OCR          OCR0A
#define ST_TCCR         TCCR0B
#define ST_CS0          CS00
#define ST_CS1          CS01
#define ST_CS2          CS02

#define ST_TIFR         TIFR0
#define ST_OCF          OCF0A
//========================================================================

//========================================================================
#define SYS_TICK        (F_CPU/64/1000)
//========================================================================

//========================================================================
typedef struct soft_timer
{
   bool status;
   u08 sys_tick_prev;
   u16 cnt;       // Counter.

#ifdef __ST_PERIOD__
   u16 period;    // Period.
#endif
} soft_timer;
//========================================================================

//========================================================================
void init_soft_timers (void);

#define handle_soft_timer(a) _handle_soft_timer(&a)
bool _handle_soft_timer(soft_timer *ptr_timer);

#ifdef __ST_PERIOD__
#define set_soft_timer(a,b,c) _set_soft_timer (&a, b, c)
void _set_soft_timer (soft_timer *ptr_timer, u16 time, u16 period);
#endif

#ifdef __ST_NO_PERIOD__
#define set_soft_timer(a,b) _set_soft_timer (&a, b)
void _set_soft_timer (soft_timer *ptr_timer, u16 time);
#endif

#define reset_soft_timer(a) _reset_soft_timer (&a)
void _reset_soft_timer (soft_timer *ptr_timer);

void proc_sys_tick (void);
//========================================================================

#endif