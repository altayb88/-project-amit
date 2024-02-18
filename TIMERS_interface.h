//******************************************************************************************************************************************
//**************Auther: altayb     ****************************************************************************************************
//**************File  : Interface of TIMER*****************************************************************************************************
//**************Date  : 16/2/2024         *****************************************************************************************************
//**************Var   : V1                ******************************************************************************************************
//**************Desc  :                   ******************************************************************************************************
//*********************************************************************************************************************************************
//**********************************************************************************************************************************************


#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

void TIMER_0_VidInit(void);
void TIMER_0_VidSetCompareMatchValue(u8 Copy_U8CompareMatchValue);
void TIMER_0_VidGenerateFastPWM(u8 Copy_U8Intensity);
void TIMER_0_VidSetCallback( void(*ptr)(void) , u32 Copy_U8TimeIn_mSec);
void __vector_11(void);
void __vector_10(void);


void TIMER_2_VidInit(void);
void TIMER_2_VidSetCompareMatchValue(u8 Copy_U8CompareMatchValue);
void TIMER_2_VidSetPreloadValueTCNT2REG(u8 Copy_u8PreloadValue);
u8 TIMER_2_U8ReadTCNT2REG(void);
void TIMER_2_VidGenerateFastPWM(u8 Copy_U8Intensity);
void TIMER_2_VidSetCallback( void(*ptr)(void) , u32 Copy_U8TimeIn_mSec);
void __vector_5(void);
void __vector_4(void);



#endif
