//*******************************************************************************************************************************************
//**************Auther:  altayb **********************************************************************************
//**************File  : Praivate of INT    			   	  ***********************************************************************************
//**************Date  : 9/2/2024       			      *******************************************************************************
//**************Var   : V1              	              *******************************************************************************
//**************Desc  :                 		          *******************************************************************************
//*******************************************************************************************************************************************


#ifndef INT_PRIVET_H
#define  INT_PRIVET_H


//   sense contrrol selection _REGISTER (INT0,INT1 )
#define MCUCR     *((volatile u8*)0x55)

#define   MCUCR_ISC00   0
#define   MCUCR_ISC01   1
#define   MCUCR_ISC10   2
#define   MCUCR_ISC11   3
//
//   sense contrrol selection _REGISTER (INT2 )
#define  MCUCSR   *((volatile u8*)0x54)
#define  MCUCSR_ISC2       6
 //INT _ENABLE _REGESTER
#define  GICR   *((volatile u8*)0x5B)
#define   GICR_INT2          5
#define   GICR_INT0          6
#define   GICR_INT1          7


// sense control _selection
#define    LOW_LEVEL    0
#define    ON_CHANGE    1
#define     FALLING_EDGE   2
#define      RISING_EDGE   3
#define    NO_SENSE_CONTROL 4

// enable &disable
#define Enable    1
#define Disable    0



void __vector_1(void)      __attribute__((signal)) ;
void __vector_2(void)      __attribute__((signal)) ;
void __vector_3(void)      __attribute__((signal)) ;



#endif
