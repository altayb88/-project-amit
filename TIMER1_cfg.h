//******************************************************************************************************************************************
//**************Auther: altayb     ****************************************************************************************************
//**************File  : Confg of TIMER      *****************************************************************************************************
//**************Date  : 15/2/2024         *****************************************************************************************************
//**************Var   : V1                ******************************************************************************************************
//**************Desc  :                   ******************************************************************************************************
//*********************************************************************************************************************************************
//**********************************************************************************************************************************************


#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_

/* Select Timer 1 State "0" to "TIMER_1_DISABLE"
				    	"1" to "TIMER_1_ENABLE" */
#define TIMER_1_STATE  TIMER_1_ENABLE

/************************************************************ *******/

/* cfg for Timer 1 */
/* Select Timer0 Mood "0"  to "TIMER_1_NORMAL_MOOD"
					  "1"  to "TIMER_1_PWM_PHASE_CORRECT_8_BIT_MOOD"
					  "2"  to "TIMER_1_PWM_PHASE_CORRECT_9_BIT_MOOD"
					  "3"  to "TIMER_1_PWM_PHASE_CORRECT_10_BIT_MOOD"
 	 	 	 	 	  "4"  to "TIMER_1_CTC_OCR1A_MOOD"
 	 	 	 	 	  "5"  to "TIMER_1_FAST_PWM_8_BIT_MOOD"
                      "6"  to "TIMER_1_FAST_PWM_9_BIT_MOOD"
                      "7"  to "TIMER_1_FAST_PWM_10_BIT_MOOD"
					  "12" to "TIMER_1_CTC_ICR1_MOOD"
                      "14" to "TIMER_1_FAST_PWM_ICR1_MOOD"
					  "15" to "TIMER_1_FAST_PWM_OCR1A_MOOD" */
#define TIMER_1_MOOD_SELECTION   TIMER_1_FAST_PWM_ICR1_MOOD

/********************************************************************/
/* Select Timer Mood for FAST_PWM_MOOD & PWM_PHASE_CORRECT_MOOD
						"0" to "TIMER_1_NORMAL_PORT"
						"1" to "TIMER_1_TOGGLE_ON_CM_MOOD_15"
						"2" to "TIMER_1_CLR_ON_CM_MOOD"
						"3" to "TIMER_1_SET_ON_CM_MOOD" */
#define TIMER_1_COMPARE_MODE_SELECTION  TIMER_1_CLR_ON_CM_MOOD

/********************************************************************/
/* Select Timer1 CLK prescaler  "0"    to  "TIMER_1_NO_CLOCK_SOUCE"
                         	 	"1"    to  "TIMER_1_CLOCK_NO_PRESCALER"
                         	 	"8"    to  "TIMER_1_CLK_8_PRESCALER"
                         	 	"64"   to  "TIMER_1_CLK_64_PRESCALER"
                         	 	"256"  to  "TIMER_1_CLK_256_PRESCALER"
						 	 	"1024" to  "TIMER_1_CLK_1024_PRESCALER"  */
#define TIMER_1_CLK_PRESCALER_SELECTION   TIMER_1_CLK_8_PRESCALER
#define Prescalar_Timer1_Type             TIMER_1_CLK_8_PRESCALER

/********************************************************************/
/* Select Time of Top on CTC Mood (compare match value)*/
#define ICR1_Value  19999   //Value Top
#define OCR1A_Value 999    //Value Compare Match


#endif
