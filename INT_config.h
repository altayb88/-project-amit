//********************************************************************************************************************************************
//**************Auther:  altayb **********************************************************************************
//**************File  : Cfg of INT    		       		   ***********************************************************************************
//**************Date  : 9/2/2024        			       *******************************************************************************
//**************Var   : V1               	               *******************************************************************************
//**************Desc  :                  		           *******************************************************************************
//********************************************************************************************************************************************




#ifndef INT_CONFIG_H
#define  INT_CONFIG_H



#define            INT0            1                          // Enable=1 & Disable = 0
#define             INT1          0
#define             INT2          0

#define  INT0_SENSE_CONTROL_TYPE     ON_CHANGE   /* valid selection (LOW_LEVEL=0 ,ON_CHANGE=1,
                                                                                                                     FALLING_EDGE=2, RISING_EDGE=3, NO_SENSE_CONTROL=4)*/

#define  INT1_SENSE_CONTROL_TYPE     LOW_LEVEL
#define  INT2_SENSE_CONTROL_TYPE    FALLING_EDGE                     // has only  two options falling edge=2 & rising Edge   =3

   // INT2  has  just two options in senseing control (falling and rising edge )


#endif
