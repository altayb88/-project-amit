//*****************************************************************************************************************************************************
//************** Auther: altayb *****************************************************************************************
//************** File  : Program of Ultrasonic   		   ****************************************************************************************
//************** Date  : 18/2/2024    				       ********************************************************************************************
//************** Var   : V1        			               ********************************************************************************************
//*****************************************************************************************************************************************************
//*****************************************************************************************************************************************************


#include "STD_TYPES.h"
#include "Bit-math.h"

#include "DIO_interface.h"

#include "INT_interface.h"
#include "INT_privet.h"

#include "TIMER1_interface.h"
#include "TIMERS_interface.h"

#include "ULTRASONIC_SENSOR_interface.h"
#include "ULTRASONIC_SENSOR_privet.h"

extern u16 Distance_in_cm ;

void ULTRASONIC_VoidInit(void)
{

	INT_VoidInit();

	TIMER_1_VidInit();       // timer 1 used with servo motor
	TIMER_2_VidInit();       // timer 2 used with ultrasonic with help of external INT0

	// the settings of Ultra sonic

	// echo pin as an input
	DIO_VidSetPinDirectoin(PORTD,PIN2,INPUT);
	DIO_VidSetPinValue(PORTD,PIN2,HIGH);

	//Triger pin out
	DIO_VidSetPinDirectoin(PORTD,4,OUTPUT);
	DIO_VidSetPinValue(PORTD,4,LOW);

	TIMER_2_VidSetCompareMatchValue(250);
	TIMER_1_VidSetCompareMatchValueOn_OCR1B(10);
	TIMER_1_VidSetCompareMatchValueOn_ICR1(24);
}

u16 ULTRASONIC_SENSOR_GetDistance(void)
{
	return	Distance_in_cm ;
}
