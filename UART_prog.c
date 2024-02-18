//********************************************************************************************************************************************
//**************Auther: altayb **********************************************************************************
//**************File  : Program of UART     		       ***********************************************************************************
//**************Date  : 17/2/2024       			       *******************************************************************************
//**************Var   : V1               	               *******************************************************************************
//**************Desc  :                  		           *******************************************************************************
//********************************************************************************************************************************************
//********************************************************************************************************************************************

#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "Bit-math.h"

#include "DIO_interface.h"

#include "UART_private.h"
#include "UART_cfg.h"
#include "UART_interface.h"




void UART_VidInit(void){

	/* Configer Pins Diraction */
	DIO_VidSetPinDirectoin(PORTD,PIN0,INPUT);     //RXD
	DIO_VidSetPinValue(PORTD,PIN0,HIGH);          //pull up
	DIO_VidSetPinDirectoin(PORTD,PIN1,OUTPUT);    //TXD

	/* Normal Speed */
	#if    UART_SPEED == UART_NORMAL_SPEED
		   CLR_BIT(UCSRA_REG,U2X);
	#elif  UART_SPEED == UART_DOUBLE_SPEED
		   SET_BIT(UCSRA_REG,U2X);
	#endif

	/* Disable  Multi-processor Communication */
	#if    UART_PROCESSOR_COMMUNICATION == UART_SINGLE_CYCLE_PRICESSOR
		   CLR_BIT(UCSRA_REG,MPCM);
	#elif  UART_PROCESSOR_COMMUNICATION == UART_MULTI_PRICESSOR
		   SET_BIT(UCSRA_REG,MPCM);
	#endif

	/* Enable Receive Complete and Transmit Complete */
	SET_BIT(UCSRB_REG,TXEN);
	SET_BIT(UCSRB_REG,RXEN);

	/* cfg UCSRC_REG */
	u8 Local_U8UCSR_REGHelp = 0b10000000;

	/* Select Asynchronous Operation */
	#if    UART_MODE_SELECT == UART_ASYNCHRONOUS_OPERATION
		   CLR_BIT(Local_U8UCSR_REGHelp,UMSEL);
	#elif  UART_MODE_SELECT == UART_SYNCHRONOUS_OPERATION
	       SET_BIT(Local_U8UCSR_REGHelp,UMSEL);
	#endif

	/* Disable Parity */
	#if    UART_PARITY_MODE == UART_DISABLE_PARITY
	       CLR_BIT(Local_U8UCSR_REGHelp,UPM0);
	       CLR_BIT(Local_U8UCSR_REGHelp,UPM1);
	#elif  UART_PARITY_MODE == UART_ENABLE_EVEN_PARITY
	       CLR_BIT(Local_U8UCSR_REGHelp,UPM0);
	       SET_BIT(Local_U8UCSR_REGHelp,UPM1);
    #elif  UART_PARITY_MODE == UART_ENABLE_ODD_PARITY
	       SET_BIT(Local_U8UCSR_REGHelp,UPM0);
	       SET_BIT(Local_U8UCSR_REGHelp,UPM1);
    #endif

	/* Select Stop bits */
	#if    UART_STOP_BIT_SELECT == UART_1_BIT_STOP_SELECT
	       CLR_BIT(Local_U8UCSR_REGHelp,USBS);
	#elif  UART_STOP_BIT_SELECT == UART_2_BIT_STOP_SELECT
		   SET_BIT(Local_U8UCSR_REGHelp,USBS);
	#endif

	/* Select The Data bits */
	#if    UART_CHARACTER_SIZE == UART_5_BIT_CHARACTER_SIZE
			CLR_BIT(UCSRB_REG,UCSZ2);
			CLR_BIT(Local_U8UCSR_REGHelp,UCSZ1);
			CLR_BIT(Local_U8UCSR_REGHelp,UCSZ0);
	#elif  UART_CHARACTER_SIZE == UART_6_BIT_CHARACTER_SIZE
			CLR_BIT(UCSRB_REG,UCSZ2);
			CLR_BIT(Local_U8UCSR_REGHelp,UCSZ1);
			SET_BIT(Local_U8UCSR_REGHelp,UCSZ0);
	#elif  UART_CHARACTER_SIZE == UART_7_BIT_CHARACTER_SIZE
			CLR_BIT(UCSRB_REG,UCSZ2);
			SET_BIT(Local_U8UCSR_REGHelp,UCSZ1);
			CLR_BIT(Local_U8UCSR_REGHelp,UCSZ0);
	#elif  UART_CHARACTER_SIZE == UART_8_BIT_CHARACTER_SIZE
			CLR_BIT(UCSRB_REG,UCSZ2);
			SET_BIT(Local_U8UCSR_REGHelp,UCSZ1);
			SET_BIT(Local_U8UCSR_REGHelp,UCSZ0);
	#elif  UART_CHARACTER_SIZE == UART_9_BIT_CHARACTER_SIZE
			SET_BIT(UCSRB_REG,UCSZ2);
			SET_BIT(Local_U8UCSR_REGHelp,UCSZ1);
			SET_BIT(Local_U8UCSR_REGHelp,UCSZ0);
	#endif

	/* Set all UCSRC_REG_Help in UCSRC_REG in one cycle */
	UCSRC_REG = Local_U8UCSR_REGHelp;

	/* Baud Rate = 9600 */
	u16 Local_U16UBRRValue ;
	Local_U16UBRRValue = UART_BAUD_RATE_UBRR;
	UBRRL_REG = (u8)Local_U16UBRRValue;
	UBRRH_REG = (u8)(Local_U16UBRRValue>>8);
}

/********************************************************************************/

void UART_VidSendData(u8 Copy_U8DataSend){
	while( GET_BIT(UCSRA_REG, UDRE) == 0 ) ;
    UDR_REG  = Copy_U8DataSend ;
}


u8 UART_U8ReadData(void){
	while( GET_BIT(UCSRA_REG , RXC) == 0 ) ;
	return   UDR_REG   ;
}

/********************************************************************************/

void UART_VidSendString(u8 *Copy_U8DataSend){
	u8 Local_U8Index = 0;
	while( Copy_U8DataSend[Local_U8Index] != '\0' )
	{
		UART_VidSendData(Copy_U8DataSend[Local_U8Index]);
		_delay_ms(1);
		Local_U8Index++;
	}
}

void UART_U8ReadString(u8 *Copy_U8ArrData){
	u8 Local_U8Count = 0 , Local_U8GetData;
	Local_U8GetData = UART_U8ReadData();
	while(Local_U8GetData != ' ')
	{
		Copy_U8ArrData[Local_U8Count] = Local_U8GetData;
		Local_U8Count++;
		Local_U8GetData = UART_U8ReadData();
	}
	Copy_U8ArrData[Local_U8Count] = '\0';
}

/*******************************************************************************/

void UART_VidNewLine(void){
	u8 Local_U8Arr[] = "\n";
	UART_VidSendString(Local_U8Arr);
}

u8 UART_U8CompareTwoString( u8 *String1 , u8 *String2){
	u8 Local_U8Flag = 0;
	while( *String1 != '\0' && *String2 != '\0' )
	{
		if( *String1 != *String2 )
		{
			Local_U8Flag = 1;
		}
		String1++;
		String2++;
	}
	if(*String1 != '\0' || *String2 != '\0')
		return 1;
	if( Local_U8Flag == 0)
		return 0;     //Two String is Equal
	else
		return 1;     //Two String is Not Equal
}








