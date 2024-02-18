//*********************************************************************************************************************************************
//**************Auther: altayb **********************************************************************************
//**************File  : Program of Servo     		       ***********************************************************************************
//**************Date  : 11/2/2024         			       *******************************************************************************
//**************Var   : V1                	               *******************************************************************************
//**************Desc  :                   		           *******************************************************************************
//*********************************************************************************************************************************************
//*********************************************************************************************************************************************
#include "STD_TYPES.h"
#include "Bit-math.h"

#include "DIO_interface.h"
#include "TIMER1_interface.h"

#include "SRVMO_cfg.h"
#include "SRVMO_private.h"
#include "SRVMO_interface.h"



/*
 * My Servo
 *  ****
 * Angle 0 => OCR1A = 51
 * Angle 180 => OCR1A = 319
 *
 *****************************
 * Stander Servo
 *   *****
 * Angle 0 => OCR1A = 999
 * Angle 180 => OCR1A = 1999
 *
 * */
/***********************************/
void SRVMO_VidInit(void)
{
	#if SRVMO_REG_MODE == SRVMO_REG_OCR1A
		/* Func To Cfg TIMER1 On Fast PWM Mood 14 With 8 Clk Prescaler for OCR1A */
		TIMER_1_VidInitForServoMotorOCR1A();
		/* Cfg PD5 Of OC1A AS OUTPUT */
		DIO_VidSetPinDirectoin(PORTD,PIN5,OUTPUT);

	#elif SRVMO_REG_MODE == SRVMO_REG_OCR1B
		/* Func To Cfg TIMER1 On Fast PWM Mood 14 With 8 Clk Prescaler for OCR1B */
		TIMER_1_VidInitForServoMotorOCR1B();
		/* Cfg PD4 Of OC1B AS OUTPUT */
		DIO_VidSetPinDirectoin(PORTD,PIN4,OUTPUT);
	#endif
}

void SRVMO_VidSetAngle(u8 Copy_U8Angle)
{
	#if SRVMO_REG_MODE == SRVMO_REG_OCR1A

		/* Set Top Of Timer1 To Overflow To Make Freq = 20Hz */
		TIMER_1_VidSetCompareMatchValueOn_ICR1(SRVMO_Freq_20Hz);

		/* Calc Compare Match Value Based On Angle */
		u16 OCR1A_CM_Value;

		/* Select Servo */
		#if SRVMO_SELECT == SRVMO_S_STANDERSERVO
			OCR1A_CM_Value = ((Copy_U8Angle * SRVMO_S_DIFFERENCE)/SRVMO_ANGLE_180) + SRVMO_S_ANGLE_0 ;
		#elif SRVMO_SELECT == SRVMO_M_MySERVO
			OCR1A_CM_Value = ((Copy_U8Angle * SRVMO_M_DIFFERENCE)/SRVMO_ANGLE_180) + SRVMO_M_ANGLE_0 ;
		#endif

		/* Set Compare Match Value In OCR1A */
		TIMER_1_VidSetCompareMatchValueOn_OCR1A(OCR1A_CM_Value);


	#elif SRVMO_REG_MODE == SRVMO_REG_OCR1B

		/* Set Top Of Timer1 To Overflow To Make Freq = 20Hz */
		TIMER_1_VidSetCompareMatchValueOn_OCR1A(SRVMO_Freq_20Hz);

		/* Calc Compare Match Value Based On Angle */
		u16 OCR1B_CM_Value;

		/* Select Servo */
		#if SRVMO_SELECT == SRVMO_S_STANDERSERVO
			OCR1B_CM_Value = ((Copy_U8Angle * SRVMO_S_DIFFERENCE)/SRVMO_ANGLE_180) + SRVMO_S_ANGLE_0 ;
		#elif SRVMO_SELECT == SRVMO_M_MySERVO
			OCR1B_CM_Value = ((Copy_U8Angle * SRVMO_M_DIFFERENCE)/SRVMO_ANGLE_180) + SRVMO_M_ANGLE_0 ;
		#endif

		/* Set Compare Match Value In OCR1A */
		TIMER_1_VidSetCompareMatchValueOn_OCR1B(OCR1B_CM_Value);
	#endif

}

