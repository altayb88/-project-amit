//******************************************************************************************************************************************
//**************Auther: altayb     ****************************************************************************************************
//**************File  : Private of TIMER    *****************************************************************************************************
//**************Date  : 15/2/2024         *****************************************************************************************************
//**************Var   : V1                ******************************************************************************************************
//**************Desc  :                   ******************************************************************************************************
//*********************************************************************************************************************************************
//**********************************************************************************************************************************************

#ifndef TIMER_PRAIVATE_H
#define TIMER_PRAIVATE_H
/*****************************************************************/

#define TIMER_1_DISABLE  0
#define TIMER_1_ENABLE   1

/* global REG*/
#define TIMSK_REG   *((volatile u8*) 0x59 )
#define OCIE2  7
#define TOIE2  6

#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1  2

#define OCIE0  1
#define TOIE0  0
/*****************************************************************/
/* TIMER1 */
#define  TCCR1A_REG   *((volatile u8*) 0x4F )
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

#define  TCCR1B_REG   *((volatile u8*) 0x4E )
#define ICNC1  7
#define ICES1  6
#define WGM13  4
#define WGM12  3
#define CS12   2
#define CS11   1
#define CS10   0

#define TIFR_REG   *((volatile u16*) 0x58 )
#define ICF1   5

#define TCNT1_REG   *((volatile u16*) 0x4C )
#define OCR1A_REG   *((volatile u16*) 0x4A )
#define OCR1B_REG   *((volatile u16*) 0x48 )
#define ICR1_REG    *((volatile u16*) 0x46 )

/* for Select Mood Timer 1  */
#define TIMER_1_NORMAL_MOOD                     0
#define TIMER_1_PWM_PHASE_CORRECT_8_BIT_MOOD    1
#define TIMER_1_PWM_PHASE_CORRECT_9_BIT_MOOD    2
#define TIMER_1_PWM_PHASE_CORRECT_10_BIT_MOOD   3
#define TIMER_1_CTC_OCR1A_MOOD                  4
#define TIMER_1_FAST_PWM_8_BIT_MOOD             5
#define TIMER_1_FAST_PWM_9_BIT_MOOD             6
#define TIMER_1_FAST_PWM_10_BIT_MOOD            7
#define TIMER_1_CTC_ICR1_MOOD                  12
#define TIMER_1_FAST_PWM_ICR1_MOOD             14
#define TIMER_1_FAST_PWM_OCR1A_MOOD            15

/* for Select Compare Output Mode, Fast PWM */
#define  TIMER_1_NORMAL_PORT            0
#define  TIMER_1_TOGGLE_ON_CM_MOOD_15   1
#define  TIMER_1_CLR_ON_CM_MOOD         2
#define  TIMER_1_SET_ON_CM_MOOD         3

/* for Select prescaker clk Timer 1  */
#define TIMER_1_NO_CLOCK_SOUCE      0
#define TIMER_1_CLOCK_NO_PRESCALER  1
#define TIMER_1_CLK_8_PRESCALER     8
#define TIMER_1_CLK_64_PRESCALER    64
#define TIMER_1_CLK_256_PRESCALER   256
#define TIMER_1_CLK_1024_PRESCALER  1024

/*********************************************************************/
void __vector_9 (void) __attribute__((signal));
void __vector_8 (void) __attribute__((signal));
void __vector_7 (void) __attribute__((signal));
void __vector_6 (void) __attribute__((signal));

#endif
