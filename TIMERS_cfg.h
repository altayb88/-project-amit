//******************************************************************************************************************************************
//**************Auther: altayb     ****************************************************************************************************
//**************File  : Confg of TIMER      *****************************************************************************************************
//**************Date  : 16/2/2024         *****************************************************************************************************
//**************Var   : V1                ******************************************************************************************************
//**************Desc  :                   ******************************************************************************************************
//*********************************************************************************************************************************************
//**********************************************************************************************************************************************


#ifndef TIMERS_CFG_H_
#define TIMERS_CFG_H_


/**************************************************************************************/
/*********************************** TIMER 0 ******************************************/
/**************************************************************************************/
/* for Select The Timer */
/* Select Timer 0 State "0" to "TIMER_0_DISABLE"
				    	"1" to "TIMER_0_ENABLE" */
#define TIMER_0_STATE  TIMER_0_ENABLE


/********************************************************************************************/
/* cfg for Timer 0 */
/* Select Timer0 Mood "0" to "TIMER_0_NORMAL_MOOD"
                      "1" to "TIMER_0_CTC_MOOD"
                      "2" to "TIMER_0_PHASE_CORRECT_PWM_MOOD"
                      "3" to "TIMER_0_FAST_PWM_MOOD" */
#define TIMER_0_MOOD_SELECTION   TIMER_0_FAST_PWM_MOOD

/********************************************************************/

/* Select Timer0 CLK prescaler  "0"    to  "TIMER_0_NO_CLOCK_SOUCE"
								"1"    to  "TIMER_0_CLOCK_NO_PRESCALER"
								"2"    to  "TIMER_0_EXCLK_T0PIN_FALLING"
								"3"    to  "TIMER_0_EXCLK_T0PIN_RISING"
								"8"    to  "TIMER_0_CLK_8_PRESCALER"
								"64"   to  "TIMER_0_CLK_64_PRESCALER"
								"256"  to  "TIMER_0_CLK_256_PRESCALER"
								"1024" to  "TIMER_0_CLK_1024_PRESCALER"  */
#define TIMER_0_CLK_PRESCALER_SELECTION   TIMER_0_CLK_8_PRESCALER
#define Prescalar_Timer0_Type             TIMER_0_CLK_8_PRESCALER

/********************************************************************/
/* Select Timer Mood for TIMER_FAST_PWM_MOOD and TIMER_PWM_MOOD "0" to "TIMER_0_NORMAL_PORT"
										         	 	 	 	"1" to "TIMER_0_NON_INVERTED_MOOD"
								   	           					"2" to "TIMER_0_INVERTED_MOOD" */
#define TIMER_0_COMPARE_MODE_SELECTION  TIMER_0_NON_INVERTED_MOOD

/********************************************************************/
/* Select Time of Top on CTC Mood (compare match value)*/
#define OCR0_Value 99



/**************************************************************************************/
/*********************************** TIMER 2 ******************************************/
/**************************************************************************************/

/* for Select The Timer */
/* Select Timer 2 State "0" to "TIMER_2_DISABLE"
				    	"1" to "TIMER_2_ENABLE" */
#define TIMER_2_STATE  TIMER_2_ENABLE


/*******************************************************/
/* cfg for Timer 0 */
/* Select Timer0 Mood "0" to "TIMER_2_NORMAL_MOOD"
                      "1" to "TIMER_2_CTC_MOOD"
                      "2" to "TIMER_2_PHASE_CORRECT_PWM_MOOD"
                      "3" to "TIMER_2_FAST_PWM_MOOD" */
#define TIMER_2_MOOD_SELECTION   TIMER_2_CTC_MOOD

/********************************************************************/

/* Select Timer0 CLK prescaler  "0"    to  "TIMER_2_NO_CLOCK_SOUCE"
								"1"    to  "TIMER_2_CLOCK_NO_PRESCALER"
								"8"    to  "TIMER_2_CLK_8_PRESCALER"
								"32"   to  "TIMER_2_CLK_32_PRESCALER"
								"64"   to  "TIMER_2_CLK_64_PRESCALER"
								"128"  to  "TIMER_2_CLK_128_PRESCALER"
								"256"  to  "TIMER_2_CLK_256_PRESCALER"
								"1024" to  "TIMER_2_CLK_1024_PRESCALER"  */
#define TIMER_2_CLK_PRESCALER_SELECTION   TIMER_2_CLK_8_PRESCALER
#define Prescalar_Timer2_Type             TIMER_2_CLK_8_PRESCALER

/********************************************************************/
/* for TIMER 2 */
/* Select Timer Mood for TIMER_FAST_PWM_MOOD and TIMER_PWM_MOOD "0" to "TIMER_2_NORMAL_PORT"
										         	 	 	 	"1" to "TIMER_2_NON_INVERTED_MOOD"
								   	           					"2" to "TIMER_2_INVERTED_MOOD" */
#define TIMER_2_COMPARE_MODE_SELECTION  TIMER_2_NON_INVERTED_MOOD

/********************************************************************/
/* Select Time of Top on CTC Mood (compare match value)*/
#define OCR2_Value 99

/********************************************************************/

#endif
