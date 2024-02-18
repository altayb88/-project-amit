//*******************************************************************************************************************************************
//**************Auther: altayb **********************************************************************************
//**************File  : Confg of UART      		          ***********************************************************************************
//**************Date  : 17/2/2024      			      *******************************************************************************
//**************Var   : V1              	              *******************************************************************************
//**************Desc  :                 		          *******************************************************************************
//*******************************************************************************************************************************************
//*******************************************************************************************************************************************

#ifndef UART_CFG_H_
#define UART_CFG_H_

/* Select UART_SPEED   "0" to "UART_NORMAL_SPEED"
                       "1" to "UART_DOUBLE_SPEED"  */
#define UART_SPEED   UART_NORMAL_SPEED

/* Select UART_PROCESSOR_COMMUNICATION   "0" to "UART_SINGLE_CYCLE_PRICESSOR"
                                         "1" to "UART_MULTI_PRICESSOR"     */
#define UART_PROCESSOR_COMMUNICATION   UART_SINGLE_CYCLE_PRICESSOR

/* Select UART_MODE_SELECT   "0" to "UART_ASYNCHRONOUS_OPERATION"
                             "1" to "UART_SYNCHRONOUS_OPERATION" */
#define UART_MODE_SELEC   UART_ASYNCHRONOUS_OPERATION

/* Select UART_PARITY_MODE   "0" to "UART_DISABLE_PARITY"
                             "1" to "UART_ENABLE_EVEN_PARITY"
							 "2" to "UART_ENABLE_ODD_PARITY" */
#define UART_PARITY_MODE   UART_DISABLE_PARITY

/* Select UART_STOP_BIT_SELECT   "0" to "UART_1_BIT_STOP_SELECT"
                                 "1" to "UART_2_BIT_STOP_SELECT"  */
#define UART_STOP_BIT_SELECT   UART_1_BIT_STOP_SELECT

/* Select UART_CHARACTER_SIZE  "0" to "UART_5_BIT_CHARACTER_SIZE"
                               "1" to "UART_6_BIT_CHARACTER_SIZE"
							   "2" to "UART_7_BIT_CHARACTER_SIZE"
							   "3" to "UART_8_BIT_CHARACTER_SIZE"
							   "4" to "UART_9_BIT_CHARACTER_SIZE" */
#define UART_CHARACTER_SIZE   UART_8_BIT_CHARACTER_SIZE

/* Baud Rate = 9600  ->  UBRR = ((F_CPU/(16*9600))-1)
                         UBRR = (((8*10^6)/(16*9600))-1) = 51 */
#define UART_BAUD_RATE_UBRR    51






#endif
