//========================================================================
// Реализация программных таймеров.
// Примечание. Важно!!!!!!!!!!!!!!!
// При смене состояния конечного автомата нужно сбросить
// все таймеры, которые используются в этом состоянии. Иначе может быть
// следующая ситуация: если таймер уже использовался в
// текущем состоянии и флаг EN установлен, то по окончании времени
// выполнится соответствующий код.
//--------------------- Пример использования -----------------------------
// set_soft_timer (ST_LED_2_BLINK, 50, 50); // Установка таймера.
// if (handle_soft_timer (ST_LED_2_BLINK))  // Проверка таймера.
//========================================================================

//========================================================================
#include "soft_timers.h"
//========================================================================

//========================================================================
static u08 sys_tick;
//========================================================================

//========================================================================
#ifdef __ST_INTERRUPT__
#pragma vector = TIMER2_COMP_vect
__interrupt void SysTimerComp (void)
{
   ST_OCR += SYS_TICK;
   sys_tick++;
}
#endif
//========================================================================

//========================================================================
void init_soft_timers (void)
{
   sys_tick = 0;
   ST_TCNT = 0;
   ST_OCR = SYS_TICK;
   ST_TCCR = ((1<<ST_CS1) | (1<<ST_CS0));

#ifdef __ST_INTERRUPT__
   set_bit (ST_TIMSK, ST_OCIE);
#endif
}
//------------------------------------------------------------------------
#ifdef __ST_PERIOD__
void _set_soft_timer (soft_timer *ptr_timer, u16 time, u16 period)
#else
void _set_soft_timer (soft_timer *ptr_timer, u16 time)
#endif
{
   ptr_timer -> status = true;

   if (time == 0)
      ptr_timer -> sys_tick_prev = ~sys_tick;
   else
      ptr_timer -> sys_tick_prev = sys_tick;

   ptr_timer -> cnt = time;

#ifdef __ST_PERIOD__
   ptr_timer -> period = period;
#endif
}
//------------------------------------------------------------------------
bool _handle_soft_timer (soft_timer *ptr_timer)
{
   if (ptr_timer -> status)
   {
      if (ptr_timer -> sys_tick_prev != sys_tick)
      {
         ptr_timer -> sys_tick_prev = sys_tick;

         if (ptr_timer -> cnt == 0)
         {
            #ifdef __ST_PERIOD__
            if (ptr_timer -> period != 0)
               ptr_timer -> cnt = ptr_timer -> period;
            #endif

            return true;
         }
         else
         {
            ptr_timer -> cnt--;

            if (ptr_timer -> cnt == 0)
            {
               #ifdef __ST_PERIOD__
               if (ptr_timer -> period == 0)
                  ptr_timer -> status = false;
               else
                  ptr_timer -> cnt = ptr_timer -> period;
               #else
               ptr_timer -> status = false;
               #endif

               return true;
            }
         }
      }
   }

   return false;
}
//------------------------------------------------------------------------
void _reset_soft_timer (soft_timer *ptr_timer)
{
   ptr_timer -> status = false;
   ptr_timer -> sys_tick_prev = 0;
   ptr_timer -> cnt = 0;

#ifdef __ST_PERIOD__
   ptr_timer -> period = 0;
#endif
}
//------------------------------------------------------------------------
#ifdef __ST_NO_INTERRUPT__
void proc_sys_tick (void)
{
   static u08 _proc_sys_tick;

   switch (_proc_sys_tick)
   {
      case 0:
         init_soft_timers ();
         _proc_sys_tick = 1;
         break;

      case 1:
         if (ST_TIFR & (1<<ST_OCF))
         {
            ST_TIFR = (1<<ST_OCF);
            ST_OCR += SYS_TICK;
            sys_tick++;
         }
         break;
   }
}
#endif
//========================================================================