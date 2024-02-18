//*******************************************************************************************************************************************
//**************Auther: altayb **********************************************************************************
//**************File  : Program of INT     			   	  ***********************************************************************************
//**************Date  : 9/2/2024       			      *******************************************************************************
//**************Var   : V1              	              *******************************************************************************
//**************Desc  :                 		          *******************************************************************************
//*******************************************************************************************************************************************
//*******************************************************************************************************************************************

#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "Bit-math.h"

#include "DIO_interface.h"

#include "TIMER1_interface.h"
#include "TIMERS_interface.h"

#include "ULTRASONIC_SENSOR_privet.h"

#include "INT_interface.h"
#include "INT_privet.h"
#include "INT_config.h"


extern u32 CTC_counter;
u16 Distance_in_cm =5000 ;
u32 Time_in_Microsec=0 ;
static void(*INT0PFUN)(void);
static void(*INT1PFUN)(void);
static void(*INT2PFUN)(void);


void INT_VoidInit(void){



#if   INT0 == 1                     // 1 =enable   0 = Disable this interuppt
	                       //INT0 ENABLE     PIE
						   
	SET_BIT( GICR,GICR_INT0	);

#if     INT0_SENSE_CONTROL_TYPE == LOW_LEVEL       // interupt sense control =LOW_LEVEL
	
	CLR_BIT(MCUCR, MCUCR_ISC00 );
	CLR_BIT(MCUCR, MCUCR_ISC01 );

#elif            INT0_SENSE_CONTROL_TYPE==ON_CHANGE
    SET_BIT(MCUCR, MCUCR_ISC00 );
	CLR_BIT(MCUCR, MCUCR_ISC01 );


#elif           INT0_SENSE_CONTROL_TYPE==FALLING_EDGE                 	// interupt sense control = falling edge

	CLR_BIT(MCUCR, MCUCR_ISC00 );
	SET_BIT(MCUCR, MCUCR_ISC01 );
#elif   INT0_SENSE_CONTROL_TYPE==RISING_EDGE
	   SET_BIT(MCUCR, MCUCR_ISC00 );
		SET_BIT(MCUCR, MCUCR_ISC01 );
#elif                  INT0_SENSE_CONTROL_TYPE== NO_SENSE_CONTROL
#endif

#endif

#if   INT1 == 1                     // 1 =enable   0 = Disable this interuppt
	  //INT1 ENABLE     PIE
	SET_BIT( GICR,GICR_INT1	);

#if     INT1_SENSE_CONTROL_TYPE==LOW_LEVEL       // interupt sense control =LOW_LEVEL

	CLR_BIT(MCUCR, MCUCR_ISC10 );
	CLR_BIT(MCUCR, MCUCR_ISC11 );

#elif            INT1_SENSE_CONTROL_TYPE==ON_CHANGE
    SET_BIT(MCUCR, MCUCR_ISC10 );
	CLR_BIT(MCUCR, MCUCR_ISC11 );


#elif           INT1_SENSE_CONTROL_TYPE==FALLING_EDGE                 	// interupt sense control = falling edge

	CLR_BIT(MCUCR, MCUCR_ISC10 );
	SET_BIT(MCUCR, MCUCR_ISC11 );
#elif   INT1_SENSE_CONTROL_TYPE==RISING_EDGE
	   SET_BIT(MCUCR, MCUCR_ISC10 );
		SET_BIT(MCUCR, MCUCR_ISC11 );
#elif                  INT1_SENSE_CONTROL_TYPE== NO_SENSE_CONTROL
#endif

# endif

#if   INT2 == 1                           // 1 =enable   0 = Disable this interuppt

	//INT2 ENABLE     PIE

	SET_BIT( GICR,GICR_INT2	);
#if           INT2_SENSE_CONTROL_TYPE==FALLING_EDGE
	         CLR_BIT(MCUCSR,MCUCSR_ISC2);
#elif          INT2_SENSE_CONTROL_TYPE==RISING_EDGE
	         SET_BIT(MCUCSR,MCUCSR_ISC2);
#elif                  INT2_SENSE_CONTROL_TYPE== NO_SENSE_CONTROL


#endif

#endif


 }
void INT0_SeneseControlMode(u8 mood){

#if  mood==LOW_LEVEL
	   CLR_BIT(MCUCR, MCUCR_ISC00 );
		CLR_BIT(MCUCR, MCUCR_ISC01 );
#elif      mood==ON_CHANGE
		  SET_BIT(MCUCR, MCUCR_ISC00 );
			CLR_BIT(MCUCR, MCUCR_ISC01 );
#elif      mood==FALLING_EDGE
		  CLR_BIT(MCUCR, MCUCR_ISC00 );
			SET_BIT(MCUCR, MCUCR_ISC01 );
#elif      mood==RISING_EDGE
		  SET_BIT(MCUCR, MCUCR_ISC00 );
			SET_BIT(MCUCR, MCUCR_ISC01 );
#else
#error  "wrong input "

			#endif

}
void INT1_SeneseControlMode(u8 mood){

#if  mood==LOW_LEVEL
	   CLR_BIT(MCUCR, MCUCR_ISC10 );
		CLR_BIT(MCUCR, MCUCR_ISC11 );
#elif      mood==ON_CHANGE
		  SET_BIT(MCUCR, MCUCR_ISC10 );
			CLR_BIT(MCUCR, MCUCR_ISC11 );
#elif      mood==FALLING_EDGE
		  CLR_BIT(MCUCR, MCUCR_ISC10 );
			SET_BIT(MCUCR, MCUCR_ISC11 );
#elif      mood==RISING_EDGE
		  SET_BIT(MCUCR, MCUCR_ISC10 );
			SET_BIT(MCUCR, MCUCR_ISC11 );
#else
#error  "wrong input "

			#endif

}
void INT2_SeneseControlMode(u8 mood){

#if  mood==FALLING_EDGE
	   CLR_BIT(MCUCSR,MCUCSR_ISC2);
#elif      mood==RISING_EDGE
	  SET_BIT(MCUCSR,MCUCSR_ISC2);



		#endif

}
// MAsking Functions Int0
void INT0_VoidDisable_int0PIE(void){
	CLR_BIT( GICR,GICR_INT0	);

}
void INT0_VoidEnable_int0PIE(void){
	SET_BIT( GICR,GICR_INT0	);

}
// MAsking Functions Int1
void INT1_VoidDisable_int0PIE(void){
	CLR_BIT( GICR,GICR_INT1	);

}

void INT1_VoidEnable_int0PIE(void){

	SET_BIT( GICR,GICR_INT1	);
}
// MAsking Functions Int2
void INT2_VoidDisable_int0PIE(void){
	CLR_BIT( GICR,GICR_INT2	);

}
void INT2_VoidEnable_int0PIE(void){
	SET_BIT( GICR,GICR_INT2	);

}




void __vector_1(void)
{
	static u8 Low =0 , High=0  ;
	if((Low==0)&&(High==0))
	{
		High=1 ;
	}
	else if  ((Low==0)&&(High==1))
	{
		CTC_counter =0 ;
		TIMER_2_VidSetPreloadValueTCNT2REG(0);
		High=0 ;
		Low=1 ;
	}
	else if  ((Low==1)&&(High==0))
	{

		Time_in_Microsec=((u32)(CTC_counter*250)+TIMER_2_U8ReadTCNT2REG() );  // time u got in microsecond
	    Distance_in_cm= (u16)(((u32)Time_in_Microsec)/Cm_Factor) ;              // Obstacle Distance in cm

	   /*stop ultrasonic to get another signals*/
	   Low=0 ;
	   High=0;
	   /*make ultasonic work again*/

	}
}

void __vector_2(void){

	          INT1PFUN();
}

void __vector_3(void){
                  INT2PFUN();

}
void INT0_Set_CallBack(void(*INT0PTR)(void)){

	INT0PFUN    = INT0PTR        ;

}
void INT1_Set_CallBack(void(*INT1PTR)(void)){

	INT1PFUN    =INT1PTR        ;
}
void INT2_Set_CallBack(void(*INT2PTR)(void)){

	INT2PFUN    =INT2PTR        ;

}
