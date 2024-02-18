//********************************************************************************************************************************************
//**************Auther: altayb  ***********************************************************************************
//**************File  : Interface of DIO   				   ***********************************************************************************
//**************Date  : 7/2/2024        			       ***********************************************************************************
//**************Var   : V1              			       ***********************************************************************************
//**************Desc  :                 			       ***********************************************************************************
//**********************************************************************************************************************************************


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

#define OUTPUT 1
#define INPUT  0

#define HIGH   1
#define LOW    0

void DIO_VidSetPinDirectoin(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Dir);

void DIO_VidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value);

u8 DIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin);

void DIO_VidTogglePinValue(u8 Copy_U8Port,u8 Copy_U8Pin);

void DIO_VidSetPortValue(u8 Copy_U8Port,u8 Copy_U8Value);

void DIO_VidSetPortDirectoin(u8 Copy_U8Port,u8 Copy_U8Dir);




#endif
