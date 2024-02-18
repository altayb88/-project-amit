//******************************************************************************************************************************************
//**************Auther: altayb     ****************************************************************************************************
//**************File  : Program of Timer    *****************************************************************************************************
//**************Date  : 15/2/2024         *****************************************************************************************************
//**************Var   : V1                ******************************************************************************************************
//**************Desc  :                   ******************************************************************************************************
//*********************************************************************************************************************************************
//**********************************************************************************************************************************************
#include "STD_TYPES.h"
#include "Bit-math.h"

#include "TIMER1_cfg.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"

#define F_CPU 8000000UL

static void(*PFunTimer1)(void);    //for call back function Timer 1

u32 over_dec1;
f32 Count_ov1;              //count_ov+1
u8 Perload_value1;
u32 Count_CTC1;

u8 TIMER1_u8MODEPWM;

/***********************************************************************************/
void TIMER_1_VidInit(void){

#if TIMER_1_STATE == TIMER_1_ENABLE
/* Select Waveform Generation Mode */
	#if   TIMER_1_MOOD_SELECTION == TIMER_1_NORMAL_MOOD
		CLR_BIT(TCCR1B_REG,WGM13);
		CLR_BIT(TCCR1B_REG,WGM12);
		CLR_BIT(TCCR1A_REG,WGM11);
		CLR_BIT(TCCR1A_REG,WGM10);
		/* Overflow Interrupt Enable */
		SET_BIT(TIMSK_REG,TOIE1);
		/* Set Preload Value*/
		TCNT1_REG = Perload_value1 ;            //256-(0,0703*256) = 238

	/***************************************************************/
	#elif  TIMER_1_MOOD_SELECTION == TIMER_1_PWM_PHASE_CORRECT_8_BIT_MOOD
	   SET_BIT(TCCR1A_REG,WGM10);
	   CLR_BIT(TCCR1A_REG,WGM11);
	   CLR_BIT(TCCR1B_REG,WGM12);
	   CLR_BIT(TCCR1B_REG,WGM13);
	   TIMER1_u8MODEPWM = TIMER_1_PWM_PHASE_CORRECT_8_BIT_MOOD;
	/***************************************************************/
	#elif  TIMER_1_MOOD_SELECTION == TIMER_1_PWM_PHASE_CORRECT_9_BIT_MOOD
	   CLR_BIT(TCCR1A_REG,WGM10);
	   SET_BIT(TCCR1A_REG,WGM11);
	   CLR_BIT(TCCR1B_REG,WGM12);
	   CLR_BIT(TCCR1B_REG,WGM13);
	   TIMER1_u8MODEPWM = TIMER_1_PWM_PHASE_CORRECT_9_BIT_MOOD;
	/***************************************************************/
	#elif  TIMER_1_MOOD_SELECTION == TIMER_1_PWM_PHASE_CORRECT_10_BIT_MOOD
	   SET_BIT(TCCR1A_REG,WGM10);
	   SET_BIT(TCCR1A_REG,WGM11);
	   CLR_BIT(TCCR1B_REG,WGM12);
	   CLR_BIT(TCCR1B_REG,WGM13);
	   TIMER1_u8MODEPWM = TIMER_1_PWM_PHASE_CORRECT_10_BIT_MOOD;

	/***************************************************************/
	#elif   TIMER_1_MOOD_SELECTION == TIMER_1_CTC_OCR1A_MOOD
		CLR_BIT(TCCR1B_REG,WGM13);
		SET_BIT(TCCR1B_REG,WGM12);
		CLR_BIT(TCCR1A_REG,WGM11);
		CLR_BIT(TCCR1A_REG,WGM10);
		/* CTC Interrupt Enable */
		SET_BIT(TIMSK_REG,OCIE1A);
		/* Set OCR1 Value (top) */
		OCR1A_REG = OCR1A_Value;

	/***************************************************************/
	#elif  TIMER_1_MOOD_SELECTION == TIMER_1_FAST_PWM_8_BIT_MOOD
		CLR_BIT(TCCR1B_REG,WGM13);
		SET_BIT(TCCR1B_REG,WGM12);
		CLR_BIT(TCCR1A_REG,WGM11);
		SET_BIT(TCCR1A_REG,WGM10);
	    TIMER1_u8MODEPWM = TIMER_1_FAST_PWM_8_BIT_MOOD;
	/***************************************************************/
	#elif  TIMER_1_MOOD_SELECTION == TIMER_1_FAST_PWM_9_BIT_MOOD
		CLR_BIT(TCCR1B_REG,WGM13);
		SET_BIT(TCCR1B_REG,WGM12);
		SET_BIT(TCCR1A_REG,WGM11);
		CLR_BIT(TCCR1A_REG,WGM10);
	    TIMER1_u8MODEPWM = TIMER_1_FAST_PWM_9_BIT_MOOD;
	/***************************************************************/
	#elif  TIMER_1_MOOD_SELECTION == TIMER_1_FAST_PWM_10_BIT_MOOD
		CLR_BIT(TCCR1B_REG,WGM13);
		SET_BIT(TCCR1B_REG,WGM12);
		SET_BIT(TCCR1A_REG,WGM11);
		SET_BIT(TCCR1A_REG,WGM10);
		TIMER1_u8MODEPWM = TIMER_1_FAST_PWM_10_BIT_MOOD;

	/***************************************************************/
	#elif   TIMER_1_MOOD_SELECTION == TIMER_1_CTC_ICR1_MOOD
		SET_BIT(TCCR1B_REG,WGM13);
		SET_BIT(TCCR1B_REG,WGM12);
		CLR_BIT(TCCR1A_REG,WGM11);
		CLR_BIT(TCCR1A_REG,WGM10);

		SET_BIT(TIMSK_REG,OCIE1A);
		SET_BIT(TIMSK_REG,OCIE1A);

		ICR1_REG = ICR1_Value;

	/***************************************************************/
	#elif  TIMER_1_MOOD_SELECTION == TIMER_1_FAST_PWM_ICR1_MOOD
		SET_BIT(TCCR1B_REG,WGM13);
		SET_BIT(TCCR1B_REG,WGM12);
		SET_BIT(TCCR1A_REG,WGM11);
		CLR_BIT(TCCR1A_REG,WGM10);
		/* Set Top Value in ICR1 */
		ICR1_REG = 20000;
		/* Set Compare Match Value In OCR1A */
		OCR1A_REG = 750;

		/* OC1A_PWM_SET_AT_TOP_CLR_ON_COMPER */
		CLR_BIT(TCCR1A_REG,COM1A0);
		SET_BIT(TCCR1A_REG,COM1A1);
		/* OC1B_PWM_SET_AT_TOP_CLR_ON_COMPER */
		CLR_BIT(TCCR1A_REG,COM1B0);
		SET_BIT(TCCR1A_REG,COM1B1);

	/***************************************************************/
	#elif  TIMER_1_MOOD_SELECTION == TIMER_1_FAST_PWM_OCR1A_MOOD
		SET_BIT(TCCR1B_REG,WGM13);
		SET_BIT(TCCR1B_REG,WGM12);
		SET_BIT(TCCR1A_REG,WGM11);
		SET_BIT(TCCR1A_REG,WGM10);

#endif

	/***************************************************************/
	/* Select Non-inverted or inverted  */
	#if	   TIMER_1_COMPARE_MODE_SELECTION == TIMER_1_NORMAL_PORT
		CLR_BIT(TCCR1A_REG,COM1A1);
		CLR_BIT(TCCR1A_REG,COM1B1);
		CLR_BIT(TCCR1A_REG,COM1A0);
		CLR_BIT(TCCR1A_REG,COM1B0);
	#elif  TIMER_1_COMPARE_MODE_SELECTION == TIMER_1_TOGGLE_ON_CM_MOOD_15
		CLR_BIT(TCCR1A_REG,COM1A1);
		CLR_BIT(TCCR1A_REG,COM1B1);
		SET_BIT(TCCR1A_REG,COM1A0);
		SET_BIT(TCCR1A_REG,COM1B0);
	#elif  TIMER_1_COMPARE_MODE_SELECTION == TIMER_1_CLR_ON_CM_MOOD
		SET_BIT(TCCR1A_REG,COM1A1);
		SET_BIT(TCCR1A_REG,COM1B1);
		CLR_BIT(TCCR1A_REG,COM1A0);
		CLR_BIT(TCCR1A_REG,COM1B0);
	#elif  TIMER_1_COMPARE_MODE_SELECTION == TIMER_1_SET_ON_CM_MOOD
		SET_BIT(TCCR1A_REG,COM1A1);
		SET_BIT(TCCR1A_REG,COM1B1);
		SET_BIT(TCCR1A_REG,COM1A0);
		SET_BIT(TCCR1A_REG,COM1B0);
	#endif

	/***************************************************************/
		/* Select CLK prescaler  */
		#if   TIMER_1_CLK_PRESCALER_SELECTION == TIMER_1_NO_CLOCK_SOUCE
			CLR_BIT(TCCR1B_REG,CS12);
			CLR_BIT(TCCR1B_REG,CS11);
			CLR_BIT(TCCR1B_REG,CS10);
		#elif TIMER_1_CLK_PRESCALER_SELECTION == TIMER_1_CLOCK_NO_PRESCALER
			CLR_BIT(TCCR1B_REG,CS12);
			CLR_BIT(TCCR1B_REG,CS11);
			SET_BIT(TCCR1B_REG,CS10);
		#elif TIMER_1_CLK_PRESCALER_SELECTION == TIMER_1_CLK_8_PRESCALER
			CLR_BIT(TCCR1B_REG,CS12);
			SET_BIT(TCCR1B_REG,CS11);
			CLR_BIT(TCCR1B_REG,CS10);
		#elif TIMER_1_CLK_PRESCALER_SELECTION == TIMER_1_CLK_64_PRESCALER
			CLR_BIT(TCCR1B_REG,CS12);
			SET_BIT(TCCR1B_REG,CS11);
			SET_BIT(TCCR1B_REG,CS10);
		#elif TIMER_1_CLK_PRESCALER_SELECTION == TIMER_1_CLK_256_PRESCALER
			SET_BIT(TCCR1B_REG,CS12);
			CLR_BIT(TCCR1B_REG,CS11);
			CLR_BIT(TCCR1B_REG,CS10);
		#elif TIMER_1_CLK_PRESCALER_SELECTION == TIMER_1_CLK_1024_PRESCALER
			SET_BIT(TCCR1B_REG,CS12);
			CLR_BIT(TCCR1B_REG,CS11);
			SET_BIT(TCCR1B_REG,CS10);
		#endif

#endif

}
/***********************************************************************************/
void TIMER_voidTimer1GeneratePWMOCR1A(u8 Copy_u8Intensity)
{
	u16 Copy_u16OCR1AValue;
	switch(TIMER1_u8MODEPWM)
	{
	   case TIMER_1_PWM_PHASE_CORRECT_8_BIT_MOOD :
	        Copy_u16OCR1AValue = ((u16)510*Copy_u8Intensity/100);
	        OCR1A_REG = Copy_u16OCR1AValue;
	        break;

	   case TIMER_1_PWM_PHASE_CORRECT_9_BIT_MOOD :
	        Copy_u16OCR1AValue = ((u16)1022*Copy_u8Intensity/100);
	        OCR1A_REG = Copy_u16OCR1AValue;
	        break;

	   case TIMER_1_PWM_PHASE_CORRECT_10_BIT_MOOD :
	        Copy_u16OCR1AValue = ((u16)2046*Copy_u8Intensity/100);
	        OCR1A_REG = Copy_u16OCR1AValue;
	        break;

	   case TIMER_1_FAST_PWM_8_BIT_MOOD :
	        Copy_u16OCR1AValue = (256*Copy_u8Intensity/100);
	        OCR1A_REG = Copy_u16OCR1AValue;
	        break;

	   case TIMER_1_FAST_PWM_9_BIT_MOOD :
	        Copy_u16OCR1AValue = (512*Copy_u8Intensity/100);
	        OCR1A_REG = Copy_u16OCR1AValue;
	        break;

	   case TIMER_1_FAST_PWM_10_BIT_MOOD :
	        Copy_u16OCR1AValue = ((u16)1023*Copy_u8Intensity/100);
	        OCR1A_REG = Copy_u16OCR1AValue;
	        break;
	}
}
/****************************************/
void TIMER_voidTimer1GeneratePWMOCR1B(u8 Copy_u8Intensity)
{
	u16 Copy_u16OCR1BValue;
	switch(TIMER1_u8MODEPWM)
	{
	   case TIMER_1_PWM_PHASE_CORRECT_8_BIT_MOOD :
	        Copy_u16OCR1BValue = ((u16)510*Copy_u8Intensity/100);
	        OCR1B_REG = Copy_u16OCR1BValue;
	        break;

	   case TIMER_1_PWM_PHASE_CORRECT_9_BIT_MOOD :
	        Copy_u16OCR1BValue = ((u16)1022*Copy_u8Intensity/100);
	        OCR1B_REG = Copy_u16OCR1BValue;
	        break;

	   case TIMER_1_PWM_PHASE_CORRECT_10_BIT_MOOD :
	        Copy_u16OCR1BValue = ((u16)2046*Copy_u8Intensity/100);
	        OCR1B_REG = Copy_u16OCR1BValue;
	        break;

	   case TIMER_1_FAST_PWM_8_BIT_MOOD :
	        Copy_u16OCR1BValue = (256*Copy_u8Intensity/100);
	        OCR1B_REG = Copy_u16OCR1BValue;
	        break;

	   case TIMER_1_FAST_PWM_9_BIT_MOOD :
	        Copy_u16OCR1BValue = (512*Copy_u8Intensity/100);
	        OCR1B_REG = Copy_u16OCR1BValue;
	        break;

	   case TIMER_1_FAST_PWM_10_BIT_MOOD :
	        Copy_u16OCR1BValue = ((u16)1023*Copy_u8Intensity/100);
	        OCR1B_REG = Copy_u16OCR1BValue;
	        break;
	}
}

/***********************************************************************************/
/* Set Compare Match Value In OCR1A */
void TIMER_1_VidSetCompareMatchValueOn_OCR1A(u16 Copy_U16CompareMatchValue){
	OCR1A_REG = Copy_U16CompareMatchValue;
}

/* Set Compare Match Value In OCR1B */
void TIMER_1_VidSetCompareMatchValueOn_OCR1B(u16 Copy_U16CompareMatchValue){
	OCR1B_REG = Copy_U16CompareMatchValue;
}


/* Set Top Value in ICR1 */
void TIMER_1_VidSetCompareMatchValueOn_ICR1(u16 Copy_U16CompareMatchValue){
	ICR1_REG = Copy_U16CompareMatchValue;
}

/* Set Preload Value For Normal Mode */
void TIMER_1_VidSetTimerValueOnNormalMode(u16 Copy_U16TimerValue){
	TCNT1_REG = Copy_U16TimerValue;
}
/* Read Timer Value From Normal Mode */
u16 TIMER_1_VidReadTimerValueNormalMode(void){
	return TCNT1_REG;
}

/***********************************************************************************/

void TIMER_1_VidSetCallback(void(*ptr)(void) , u32 Copy_U8TimeIn_mSec){
	PFunTimer1 = ptr;

	/* clac For Normal Mode */
	f32 Floating_value;
	f32 Time_ov;
	Time_ov =  (f32) 256 * 1000 * ( (f32) Prescalar_Timer1_Type / (f32) F_CPU );
	Count_ov1 = (f32) ( Copy_U8TimeIn_mSec ) / Time_ov ;     //count_ov+1
	over_dec1 = Count_ov1;
	Floating_value  = Count_ov1 - over_dec1 ;
	Perload_value1 = 256 - ( Floating_value * 256 );

	/* clac For CTC Mode */
	f32 Time_Tik;
	Time_Tik = (f32) Prescalar_Timer1_Type / (f32) F_CPU;
	Count_CTC1 = (Copy_U8TimeIn_mSec/1000) / (OCR1A_Value * Time_Tik);

}

/***********************************************************************************/

/* ISR For TIMER_1_NORMAL_MOOD */
void __vector_9(void){
	static u32 Local_U8_OV_Count = 0;
	Local_U8_OV_Count++;

	if( Local_U8_OV_Count == (u32)Count_ov1 + 1  ){
		TCNT1_REG = Perload_value1 ;     //256-(0,0703*256) = 238

		PFunTimer1();

		Local_U8_OV_Count = 0;
	}
}
/************************************************************/
/* ISR For TIMER_1_CTC_OCR1A_MOOD */
void __vector_7(void){

	static u32 Local_U8_CTC_Count = 0;
	Local_U8_CTC_Count++;

	if(Local_U8_CTC_Count == Count_CTC1 ){  // to 2sec -> 256clk/8*10^6=32us -> 2sec/100tik*32us=625

		PFunTimer1();
		Local_U8_CTC_Count = 0;

	}
}

/*********************************************************************************************/
/*******************************  ServoMotor  ********************************************** */
/*********************************************************************************************/
void TIMER_1_VidInitForServoMotorOCR1A(void)
{
	/* TIMER_1_FAST_PWM_ICR1_MOOD */
	SET_BIT(TCCR1B_REG,WGM13);
	SET_BIT(TCCR1B_REG,WGM12);
	SET_BIT(TCCR1A_REG,WGM11);
	CLR_BIT(TCCR1A_REG,WGM10);
	/* Select Non-inverted or inverted  */
	SET_BIT(TCCR1A_REG,COM1A1);
	SET_BIT(TCCR1A_REG,COM1B1);
	CLR_BIT(TCCR1A_REG,COM1A0);
	CLR_BIT(TCCR1A_REG,COM1B0);
	/* Set Top Value in ICR1 */
	ICR1_REG = ICR1_Value;
	/* Set Compare Match Value In OCR1A => Angle Of Servo */
	OCR1A_REG = OCR1A_Value;
	/* Select CLK 8 prescaler */
	CLR_BIT(TCCR1B_REG,CS12);
	SET_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS10);
}

void TIMER_1_VidInitForServoMotorOCR1B(void)
{
	/* TIMER_1_FAST_PWM_OCR1A_MOOD */
	SET_BIT(TCCR1B_REG,WGM13);
	SET_BIT(TCCR1B_REG,WGM12);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1A_REG,WGM10);
	/* Select Non-inverted or inverted  */
	CLR_BIT(TCCR1A_REG,COM1A1);
	SET_BIT(TCCR1A_REG,COM1B1);
	CLR_BIT(TCCR1A_REG,COM1A0);
	CLR_BIT(TCCR1A_REG,COM1B0);
	/* Select CLK 8 prescaler */
	CLR_BIT(TCCR1B_REG,CS12);
	SET_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS10);

}


/*********************************************************************************************/
/*******************************  ICU Timer 1  ***********************************************/
/*********************************************************************************************/
static void(*Timer_1_pICUSetCallBack)(void);

void TIMER_1_VidICUInit(void)
{
	/* Input Capture Edge Select rising (positive) edge */
	SET_BIT(TCCR1B_REG,ICES1);
	/*  Input Capture Interrupt Enable */
	SET_BIT(TIMSK_REG,TICIE1);

	/* TIMER_1_CLK_8_PRESCALER */
	CLR_BIT(TCCR1B_REG,CS12);
	SET_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS10);
}

void TIMER_1_VidICUSetTriggerEdge(u8 Copy_U8ICUEdgeType)
{
   if(Copy_U8ICUEdgeType == TIMER_1_ICU_RISING_EDGY_TYPE_MODE)
   {
	  SET_BIT(TCCR1B_REG,ICES1);
   }
   else if(Copy_U8ICUEdgeType == TIMER_1_ICU_FALLING_EDGY_TYPE_MODE)
   {
	  CLR_BIT(TCCR1B_REG,ICES1);
   }
}

u16 TIMER_1_VidICUGetInputCaptureValue(void)
{
	 return ICR1_REG;
}

void TIMER_1_VidICUSetCallBack(void (*Copy_pFun) (void))
{
	Timer_1_pICUSetCallBack = Copy_pFun;
}

void TIMER_1_VidClearTimer1Value(void)
{
	TCNT1_REG = 0;
}


void __vector_6(void)
{

}
