//******************************************************************************************************************************************
//**************Auther: altayb     ****************************************************************************************************
//**************File  : Program of Timer    *****************************************************************************************************
//**************Date  : 1/10/2022         *****************************************************************************************************
//**************Var   : V1                ******************************************************************************************************
//**************Desc  :                   ******************************************************************************************************
//*********************************************************************************************************************************************

#include "STD_TYPES.h"
#include "Bit-math.h"

#include "TIMERS_cfg.h"
#include "TIMERS_interface.h"
#include "TIMERS_private.h"

#define F_CPU 8000000UL


static void(*PFunTimer0)(void);    //for call back function Timer 0
static void(*PFunTimer2)(void);    //for call back function Timer 2


u32 CTC_counter=0   ;

u32 over_dec_0 , over_dec_2;
f32 Count_ov_0 , Count_ov_2 ;              //count_ov+1
u8 Perload_value_0 , Perload_value_2;
u32 Count_CTC_0 , Count_CTC_2;

/**************************************************************************************/
/*********************************** TIMER 0 ******************************************/
/**************************************************************************************/

void TIMER_0_VidInit(void){

#if TIMER_0_STATE == TIMER_0_ENABLE

	/* Select Waveform Generation Mode */
	#if   TIMER_0_MOOD_SELECTION == TIMER_0_NORMAL_MOOD
		CLR_BIT(TCCR0_REG,WGM00);
		CLR_BIT(TCCR0_REG,WGM01);
		/* Overflow Interrupt Enable */
		SET_BIT(TIMSK_REG,TOIE0);
		/* Set Preload Value*/
		TCNT0_REG = Perload_value_0 ;            //256-(0,0703*256) = 238

	/***************************************************************/
	#elif  TIMER_0_MOOD_SELECTION == TIMER_0_PHASE_CORRECT_PWM_MOOD
		SET_BIT(TCCR0_REG,WGM00);
		CLR_BIT(TCCR0_REG,WGM01);
		/* Select Non-inverted or inverted  */
		#if	   TIMER_0_COMPARE_MODE_SELECTION == TIMER_0_NORMAL_PORT
			CLR_BIT(TCCR0_REG,COM01);
			CLR_BIT(TCCR0_REG,COM00);
		#elif  TIMER_0_COMPARE_MODE_SELECTION == TIMER_0_NON_INVERTED_MOOD
			SET_BIT(TCCR0_REG,COM01);
			CLR_BIT(TCCR0_REG,COM00);
		#elif  TIMER_0_COMPARE_MODE_SELECTION == TIMER_0_INVERTED_MOOD
			SET_BIT(TCCR0_REG,COM01);
			SET_BIT(TCCR0_REG,COM00);
		#endif

	/***************************************************************/
	#elif  TIMER_0_MOOD_SELECTION == TIMER_0_CTC_MOOD
		CLR_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);
		/* CTC Interrupt Enable */
		SET_BIT(TIMSK_REG,OCIE0);
		/* Set OCR0 Value (top) */
		OCR0_REG = OCR0_Value;

	/***************************************************************/
	#elif  TIMER_0_MOOD_SELECTION == TIMER_0_FAST_PWM_MOOD
		SET_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);
		/* Select Non-inverted or inverted  */
		#if	   TIMER_0_COMPARE_MODE_SELECTION == TIMER_0_NORMAL_PORT
			CLR_BIT(TCCR0_REG,COM01);
			CLR_BIT(TCCR0_REG,COM00);
		#elif  TIMER_0_COMPARE_MODE_SELECTION == TIMER_0_NON_INVERTED_MOOD
			SET_BIT(TCCR0_REG,COM01);
			CLR_BIT(TCCR0_REG,COM00);
		#elif  TIMER_0_COMPARE_MODE_SELECTION == TIMER_0_INVERTED_MOOD
			SET_BIT(TCCR0_REG,COM01);
			SET_BIT(TCCR0_REG,COM00);
		#endif
	#endif

	/*************************************************************************/
	/* Select CLK prescaler Timer0 */
	#if   TIMER_0_CLK_PRESCALER_SELECTION == TIMER_0_NO_CLOCK_SOUCE
		CLR_BIT(TCCR0_REG,CS02);
		CLR_BIT(TCCR0_REG,CS01);
		CLR_BIT(TCCR0_REG,CS00);
	#elif TIMER_0_CLK_PRESCALER_SELECTION == TIMER_0_CLOCK_NO_PRESCALER
		CLR_BIT(TCCR0_REG,CS02);
		CLR_BIT(TCCR0_REG,CS01);
		SET_BIT(TCCR0_REG,CS00);
	#elif TIMER_0_CLK_PRESCALER_SELECTION == TIMER_0_CLK_8_PRESCALER
		CLR_BIT(TCCR0_REG,CS02);
		SET_BIT(TCCR0_REG,CS01);
		CLR_BIT(TCCR0_REG,CS00);
	#elif TIMER_0_CLK_PRESCALER_SELECTION == TIMER_0_CLK_64_PRESCALER
		CLR_BIT(TCCR0_REG,CS02);
		SET_BIT(TCCR0_REG,CS01);
		SET_BIT(TCCR0_REG,CS00);
	#elif TIMER_0_CLK_PRESCALER_SELECTION == TIMER_0_CLK_256_PRESCALER
		SET_BIT(TCCR0_REG,CS02);
		CLR_BIT(TCCR0_REG,CS01);
		CLR_BIT(TCCR0_REG,CS00);
	#elif TIMER_0_CLK_PRESCALER_SELECTION == TIMER_0_CLK_1024_PRESCALER
		SET_BIT(TCCR0_REG,CS02);
		CLR_BIT(TCCR0_REG,CS01);
		SET_BIT(TCCR0_REG,CS00);
	#elif TIMER_0_CLK_PRESCALER_SELECTION == TIMER_0_EXCLK_T0PIN_FALLING
		SET_BIT(TCCR0_REG,CS02);
		SET_BIT(TCCR0_REG,CS01);
		CLR_BIT(TCCR0_REG,CS00);
	#elif TIMER_0_CLK_PRESCALER_SELECTION == TIMER_0_EXCLK_T0PIN_RISING
		SET_BIT(TCCR0_REG,CS02);
		SET_BIT(TCCR0_REG,CS01);
		SET_BIT(TCCR0_REG,CS00);
	#endif
#endif
}

/***********************************************************************************/
void TIMER_0_VidSetCompareMatchValue(u8 Copy_U8CompareMatchValue){
	OCR0_REG = Copy_U8CompareMatchValue;
}

/***************************************/
void TIMER_0_VidGenerateFastPWM(u8 Copy_U8Intensity)
{
	/* Copy_U8Intensity 0...100 */
	u8 Local_OCR0_Value = (255 * Copy_U8Intensity / 100);
	TIMER_0_VidSetCompareMatchValue(Local_OCR0_Value);
}

/***********************************************************************************/

void TIMER_0_VidSetCallback( void(*ptr)(void) , u32 Copy_U8TimeIn_mSec)
{
	PFunTimer0 = ptr;

	/* clac For Normal Mode */
	f32 Floating_value;
	f32 Time_ov;
	Time_ov =  (f32) 256 * 1000 * ( (f32) Prescalar_Timer0_Type / (f32) F_CPU );
	Count_ov_0 = (f32) ( Copy_U8TimeIn_mSec ) / Time_ov ;     //count_ov+1
	over_dec_0 = Count_ov_0;
	Floating_value  = Count_ov_0 - over_dec_0 ;
	Perload_value_0 = 256 - ( Floating_value * 256 );

	/* clac For CTC Mode */
	f32 Time_Tik;
	Time_Tik = (f32) Prescalar_Timer0_Type / (f32) F_CPU;
	Count_CTC_0 = (Copy_U8TimeIn_mSec/1000) / (OCR0_Value * Time_Tik);

}
/***********************************************************************************/

/* ISR For TIMER_0_NORMAL_MOOD */
void __vector_11(void){

	static u32 Local_U8_OV_Count = 0;
	Local_U8_OV_Count++;

	if( Local_U8_OV_Count == (u32)Count_ov_0 + 1 ){
		TCNT0_REG = Perload_value_0 ;     //256-(0,0703*256) = 238

		PFunTimer0();

		Local_U8_OV_Count = 0;
	}

}

/*******************************************/

/* ISR For TIMER_0_CTC_MOOD */
void __vector_10(void){

	static u32 Local_U8_CTC_Count = 0;
	Local_U8_CTC_Count++;

	if(Local_U8_CTC_Count == Count_CTC_0){  // to 2sec -> 256clk/8*10^6=32us -> 2sec/100tik*32us=625

		PFunTimer0();
		Local_U8_CTC_Count = 0;

	}
}

/**************************************************************************************/
/*********************************** TIMER 2 ******************************************/
/**************************************************************************************/
void TIMER_2_VidInit(void){

#if TIMER_2_STATE == TIMER_2_ENABLE

	/* Select Waveform Generation Mode */
	#if   TIMER_2_MOOD_SELECTION == TIMER_2_NORMAL_MOOD
		CLR_BIT(TCCR2_REG,WGM21);
		CLR_BIT(TCCR2_REG,WGM20);
		/* Overflow Interrupt Enable */
		SET_BIT(TIMSK_REG,TOIE2);
		/* Set Preload Value*/
		TCNT2_REG = TIMER_2_PRELOAD_VALUE ;            //256-(0,0703*256) = 238

	/***************************************************************/
	#elif   TIMER_2_MOOD_SELECTION == TIMER_2_PWM_MOOD
		CLR_BIT(TCCR2_REG,WGM21);
		SET_BIT(TCCR2_REG,WGM20);
		/* Select Non-inverted or inverted  */
		#if	   TIMER_2_COMPARE_MODE_SELECTION == TIMER_2_NORMAL_PORT
			CLR_BIT(TCCR2_REG,COM21);
			CLR_BIT(TCCR2_REG,COM20);
		#elif  TIMER_2_COMPARE_MODE_SELECTION == TIMER_2_NON_INVERTED_MOOD
			SET_BIT(TCCR2_REG,COM21);
			CLR_BIT(TCCR2_REG,COM20);
		#elif  TIMER_2_COMPARE_MODE_SELECTION == TIMER_2_INVERTED_MOOD
			SET_BIT(TCCR2_REG,COM21);
			SET_BIT(TCCR2_REG,COM20);
		#endif

	/***************************************************************/
	#elif   TIMER_2_MOOD_SELECTION == TIMER_2_CTC_MOOD
		SET_BIT(TCCR2_REG,WGM21);
		CLR_BIT(TCCR2_REG,WGM20);
		/* CTC Interrupt Enable */
		SET_BIT(TIMSK_REG,OCIE2);
		/* Set OCR0 Value (top) */
		//OCR2_REG = OCR2_Value;

		CLR_BIT(TCCR0_REG,COM20);
		CLR_BIT(TCCR0_REG,COM21);

	/***************************************************************/
	#elif   TIMER_2_MOOD_SELECTION == TIMER_2_FAST_PWM_MOOD
		SET_BIT(TCCR2_REG,WGM21);
		SET_BIT(TCCR2_REG,WGM20);
		/* Select Non-inverted or inverted  */
		#if	   TIMER_2_COMPARE_MODE_SELECTION == TIMER_2_NORMAL_PORT
			CLR_BIT(TCCR2_REG,COM21);
			CLR_BIT(TCCR2_REG,COM20);
		#elif  TIMER_2_COMPARE_MODE_SELECTION == TIMER_2_NON_INVERTED_MOOD
			SET_BIT(TCCR2_REG,COM21);
			CLR_BIT(TCCR2_REG,COM20);
		#elif  TIMER_2_COMPARE_MODE_SELECTION == TIMER_2_INVERTED_MOOD
			SET_BIT(TCCR2_REG,COM21);
			SET_BIT(TCCR2_REG,COM20);
		#endif
	#endif

	/*************************************************************************/
	/* Select CLK prescaler  */
	#if   TIMER_2_CLK_PRESCALER_SELECTION == TIMER_2_NO_CLOCK_SOUCE
		CLR_BIT(TCCR2_REG,CS22);
		CLR_BIT(TCCR2_REG,CS21);
		CLR_BIT(TCCR2_REG,CS20);
	#elif TIMER_2_CLK_PRESCALER_SELECTION == TIMER_2_CLOCK_NO_PRESCALER
		CLR_BIT(TCCR2_REG,CS22);
		CLR_BIT(TCCR2_REG,CS21);
		SET_BIT(TCCR2_REG,CS20);
	#elif TIMER_2_CLK_PRESCALER_SELECTION == TIMER_2_CLK_8_PRESCALER
		CLR_BIT(TCCR2_REG,CS22);
		SET_BIT(TCCR2_REG,CS21);
		CLR_BIT(TCCR2_REG,CS20);
	#elif TIMER_2_CLK_PRESCALER_SELECTION == TIMER_2_CLK_32_PRESCALER
		CLR_BIT(TCCR2_REG,CS22);
		SET_BIT(TCCR2_REG,CS21);
		SET_BIT(TCCR2_REG,CS20);
	#elif TIMER_2_CLK_PRESCALER_SELECTION == TIMER_2_CLK_64_PRESCALER
		SET_BIT(TCCR2_REG,CS22);
		CLR_BIT(TCCR2_REG,CS21);
		CLR_BIT(TCCR2_REG,CS20);
	#elif TIMER_2_CLK_PRESCALER_SELECTION == TIMER_2_CLK_128_PRESCALER
		SET_BIT(TCCR2_REG,CS22);
		CLR_BIT(TCCR2_REG,CS21);
		SET_BIT(TCCR2_REG,CS20);
	#elif TIMER_2_CLK_PRESCALER_SELECTION == TIMER_2_CLK_256_PRESCALER
		SET_BIT(TCCR2_REG,CS22);
		SET_BIT(TCCR2_REG,CS21);
		CLR_BIT(TCCR2_REG,CS20);
	#elif TIMER_2_CLK_PRESCALER_SELECTION == TIMER_2_CLK_1024_PRESCALER
		SET_BIT(TCCR2_REG,CS22);
		SET_BIT(TCCR2_REG,CS21);
		SET_BIT(TCCR2_REG,CS20);
	#endif

#endif
}

/***********************************************************************************/
void TIMER_2_VidSetCompareMatchValue(u8 Copy_U8CompareMatchValue){
	OCR2_REG = Copy_U8CompareMatchValue;
}

void TIMER_2_VidSetPreloadValueTCNT2REG(u8 Copy_u8PreloadValue)
{
	/*Set Compare Match Value To The OCR0 Register*/
	TCNT2_REG = Copy_u8PreloadValue;
}
u8 TIMER_2_U8ReadTCNT2REG(void)
{
	/*READ TCNT2_REG_ Value To */
	return  TCNT2_REG ;
}

/***************************************/
void TIMER_2_VidGenerateFastPWM(u8 Copy_U8Intensity)
{
	/* Copy_U8Intensity 0...100 */
	u8 Local_OCR2_Value = (255 * Copy_U8Intensity / 100);
	TIMER_2_VidSetCompareMatchValue(Local_OCR2_Value);
}

/***********************************************************************************/

void TIMER_2_VidSetCallback( void(*ptr)(void) , u32 Copy_U8TimeIn_mSec)
{
	PFunTimer2 = ptr;

	/* clac For Normal Mode */
	f32 Floating_value;
	f32 Time_ov;
	Time_ov =  (f32) 256 * 1000 * ( (f32) Prescalar_Timer2_Type / (f32) F_CPU );
	Count_ov_2 = (f32) ( Copy_U8TimeIn_mSec ) / Time_ov ;     //count_ov+1
	over_dec_2 = Count_ov_2;
	Floating_value  = Count_ov_2 - over_dec_2 ;
	Perload_value_2 = 256 - ( Floating_value * 256 );

	/* clac For CTC Mode */
	f32 Time_Tik;
	Time_Tik = (f32) Prescalar_Timer2_Type / (f32) F_CPU;
	Count_CTC_2 = (Copy_U8TimeIn_mSec/1000) / (OCR2_Value * Time_Tik);

}
/***********************************************************************************/

/* ISR For TIMER_2_NORMAL_MOOD */
void __vector_5(void){

	static u32 Local_U8_OV_Count = 0;
	Local_U8_OV_Count++;

	if( Local_U8_OV_Count == (u32)Count_ov_2 + 1 ){
		TCNT2_REG = Perload_value_2 ;     //256-(0,0703*256) = 238

		PFunTimer2();

		Local_U8_OV_Count = 0;
	}

}
/*******************************************/

/* ISR For TIMER_2_CTC_MOOD */
void __vector_4(void)
{
	CTC_counter++;
}

/***********************************************************************************/

