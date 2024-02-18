//******************************************************************************************************************************************
//**************Auther: altayb ***********************************************************************************
//**************File  : Program of DIO   				    ***********************************************************************************
//**************Date  : 7/2/2024     				        ***********************************************************************************
//**************Var   : V1         					        ***********************************************************************************
//**************Desc  :          					        ***********************************************************************************
//********************************************************************************************************************************************

#include "STD_TYPES.h"
#include "Bit-math.h"

#include "DIO_private.h"
#include "DIO_interface.h"


 //                           port 0---3       pin 0---7      dir 0--1
 
void DIO_VidSetPinDirectoin(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Dir){
	if (OUTPUT == Copy_U8Dir){
		switch(Copy_U8Port){
			case PORTA: SET_BIT(DDRA_REG,Copy_U8Pin);   break;
			case PORTB: SET_BIT(DDRB_REG,Copy_U8Pin);   break;
			case PORTC: SET_BIT(DDRC_REG,Copy_U8Pin);   break;
			case PORTD: SET_BIT(DDRD_REG,Copy_U8Pin);   break;
		}
	}
	else if (INPUT == Copy_U8Dir){
		switch(Copy_U8Port){
			case PORTA: CLR_BIT(DDRA_REG,Copy_U8Pin);   break;
			case PORTB: CLR_BIT(DDRB_REG,Copy_U8Pin);   break;
			case PORTC: CLR_BIT(DDRC_REG,Copy_U8Pin);   break;
			case PORTD: CLR_BIT(DDRD_REG,Copy_U8Pin);   break;
		}
	}
}

void DIO_VidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value){
	if (HIGH == Copy_U8Value){
		switch(Copy_U8Port){
			case PORTA: SET_BIT(PORTA_REG,Copy_U8Pin);   break;
			case PORTB: SET_BIT(PORTB_REG,Copy_U8Pin);   break;
			case PORTC: SET_BIT(PORTC_REG,Copy_U8Pin);   break;
			case PORTD: SET_BIT(PORTD_REG,Copy_U8Pin);   break;
		}
	}
	else if (LOW == Copy_U8Value){
		switch(Copy_U8Port){
			case PORTA: CLR_BIT(PORTA_REG,Copy_U8Pin);   break;
			case PORTB: CLR_BIT(PORTB_REG,Copy_U8Pin);   break;
			case PORTC: CLR_BIT(PORTC_REG,Copy_U8Pin);   break;
			case PORTD: CLR_BIT(PORTD_REG,Copy_U8Pin);   break;
		}
	}
}

u8 DIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin){
	u8 Local_ReturnValue;
	switch(Copy_U8Port){
		case PORTA: Local_ReturnValue = GET_BIT(PINA_REG,Copy_U8Pin);   break;
		case PORTB: Local_ReturnValue = GET_BIT(PINB_REG,Copy_U8Pin);   break;
		case PORTC: Local_ReturnValue = GET_BIT(PINC_REG,Copy_U8Pin);   break;
		case PORTD: Local_ReturnValue = GET_BIT(PIND_REG,Copy_U8Pin);   break;
	}
	return Local_ReturnValue;
}

void DIO_VidTogglePinValue(u8 Copy_U8Port,u8 Copy_U8Pin){
	switch(Copy_U8Port){
		case PORTA: TOGGLE_BIT(PORTA_REG,Copy_U8Pin);   break;
		case PORTB: TOGGLE_BIT(PORTB_REG,Copy_U8Pin);   break;
		case PORTC: TOGGLE_BIT(PORTC_REG,Copy_U8Pin);   break;
		case PORTD: TOGGLE_BIT(PORTD_REG,Copy_U8Pin);   break;
	}
}

void DIO_VidSetPortValue(u8 Copy_U8Port,u8 Copy_U8Value){
	switch(Copy_U8Port){
		case PORTA: PORTA_REG = Copy_U8Value;   break;
		case PORTB: PORTB_REG = Copy_U8Value;   break;
		case PORTC: PORTC_REG = Copy_U8Value;   break;
		case PORTD: PORTD_REG = Copy_U8Value;   break;
	}
}

void DIO_VidSetPortDirectoin(u8 Copy_U8Port,u8 Copy_U8Dir){
	switch(Copy_U8Port){
		case PORTA: DDRA_REG = Copy_U8Dir;  break;
		case PORTB: DDRB_REG = Copy_U8Dir;  break;
		case PORTC: DDRC_REG = Copy_U8Dir;  break;
		case PORTD: DDRD_REG = Copy_U8Dir;  break;
	}

}
