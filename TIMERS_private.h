//******************************************************************************************************************************************
//**************Auther: altayb     ****************************************************************************************************
//**************File  : Private of TIMER    *****************************************************************************************************
//**************Date  : 16/2/2024         *****************************************************************************************************
//**************Var   : V1                ******************************************************************************************************
//**************Desc  :                   ******************************************************************************************************
//*********************************************************************************************************************************************
//**********************************************************************************************************************************************

#ifndef TIMERS_PRAIVATE_H
#define TIMERS_PRAIVATE_H

/**************************************************************************************/
/*********************************** TIMER 0 ******************************************/
/**************************************************************************************/
#define TCCR0_REG   *((volatile u8*) 0x53 )
#define FOC0   7
#define WGM00  6
#define COM01  5
#define COM00  4
#define WGM01  3
#define CS02   2
#define CS01   1
#define CS00   0

#define TCNT0_REG   *((volatile u8*) 0x52 )

#define OCR0_REG    *((volatile u8*) 0x5C )

#define TIFR_REG    *((volatile u8*) 0x58 )
#define TOV0  0
#define OCF0  1

void __vector_11(void)       __attribute__((signal));
void __vector_10(void)       __attribute__((signal));

/* for Select Mood Timer 0  */
#define TIMER_0_NORMAL_MOOD            0
#define TIMER_0_CTC_MOOD               1
#define TIMER_0_PHASE_CORRECT_PWM_MOO  2
#define TIMER_0_FAST_PWM_MOOD          3

/* for Select prescaker clk Timer 0  */
#define TIMER_0_NO_CLOCK_SOUCE      0
#define TIMER_0_CLOCK_NO_PRESCALER  1
#define TIMER_0_CLK_8_PRESCALER     8
#define TIMER_0_CLK_64_PRESCALER    64
#define TIMER_0_CLK_256_PRESCALER   256
#define TIMER_0_CLK_1024_PRESCALER  1024
#define TIMER_0_EXCLK_T0PIN_FALLING  2
#define TIMER_0_EXCLK_T0PIN_RISING   3

/* for TIMER 0,2 */
#define TIMER_0_NORMAL_PORT        0
#define TIMER_0_NON_INVERTED_MOOD  1
#define TIMER_0_INVERTED_MOOD      2

#define TIMER_0_DISABLE  0
#define TIMER_0_ENABLE   1

/**************************************************************************************/
/*********************************** TIMER 2 ******************************************/
/**************************************************************************************/

#define TCCR2_REG     *((volatile u8*) 0x45 )
#define FOC2   7
#define WGM20  6
#define COM21  5
#define COM20  4
#define WGM21  3
#define CS22   2
#define CS21   1
#define CS20   0

#define TCNT2_REG   *((volatile u8*) 0x44 )
#define OCR2_REG    *((volatile u8*) 0x43 )

void __vector_5(void)       __attribute__((signal));
void __vector_4(void)       __attribute__((signal));

/* for Select Mood Timer 2  */
#define TIMER_2_NORMAL_MOOD   0
#define TIMER_2_CTC_MOOD      1
#define TIMER_2_PWM_MOOD      2
#define TIMER_2_FAST_PWM_MOOD 3

/* for Select prescaker clk Timer 2  */
#define TIMER_2_NO_CLOCK_SOUCE      0
#define TIMER_2_CLOCK_NO_PRESCALER  1
#define TIMER_2_CLK_8_PRESCALER     8
#define TIMER_2_CLK_32_PRESCALER    32
#define TIMER_2_CLK_64_PRESCALER    64
#define TIMER_2_CLK_128_PRESCALER   128
#define TIMER_2_CLK_256_PRESCALER   256
#define TIMER_2_CLK_1024_PRESCALER  1024

#define TIMER_2_NORMAL_PORT        0
#define TIMER_2_NON_INVERTED_MOOD  1
#define TIMER_2_INVERTED_MOOD      2

#define TIMER_2_DISABLE  0
#define TIMER_2_ENABLE   1

/*****************************************************************/
/* global REG */
#define TIMSK_REG   *((volatile u8*) 0x59 )
#define OCIE2  7
#define TOIE2  6

#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1  2

#define OCIE0  1
#define TOIE0  0

#endif
