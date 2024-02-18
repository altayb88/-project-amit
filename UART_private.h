//********************************************************************************************************************************************
//**************Auther: altayb **********************************************************************************
//**************File  : Private of UART     		       ***********************************************************************************
//**************Date  : 17/2/2024       			       *******************************************************************************
//**************Var   : V1               	               *******************************************************************************
//**************Desc  :                  		           *******************************************************************************
//********************************************************************************************************************************************

#ifndef UART_PRAIVATE_H
#define UART_PRAIVATE_H

#define UDR_REG     *((volatile u8*) 0x2C )

#define UCSRA_REG   *((volatile u8*) 0x2B )
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

#define UCSRB_REG   *((volatile u8*) 0x2A )
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

#define UCSRC_REG   *((volatile u8*) 0x40 )
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0

#define UBRRH_REG   *((volatile u8*) 0x40 )

#define UBRRL_REG   *((volatile u8*) 0x29 )


#define UART_NORMAL_SPEED    0
#define UART_DOUBLE_SPEED    1

#define UART_SINGLE_CYCLE_PRICESSOR    0
#define UART_MULTI_PRICESSOR           1

#define UART_ASYNCHRONOUS_OPERATION    0
#define UART_SYNCHRONOUS_OPERATION     1

#define UART_DISABLE_PARITY        0
#define UART_ENABLE_EVEN_PARITY    1
#define UART_ENABLE_ODD_PARITY     2

#define UART_1_BIT_STOP_SELECT   0
#define UART_2_BIT_STOP_SELECT   1

#define UART_5_BIT_CHARACTER_SIZE  0
#define UART_6_BIT_CHARACTER_SIZE  1
#define UART_7_BIT_CHARACTER_SIZE  2
#define UART_8_BIT_CHARACTER_SIZE  3
#define UART_9_BIT_CHARACTER_SIZE  4

#endif
