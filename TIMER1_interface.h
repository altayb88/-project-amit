//******************************************************************************************************************************************
//**************Auther: altayb     ****************************************************************************************************
//**************File  : Interface of TIMER*****************************************************************************************************
//**************Date  : 15/2/2024         *****************************************************************************************************
//**************Var   : V1                ******************************************************************************************************
//**************Desc  :                   ******************************************************************************************************
//*********************************************************************************************************************************************
//**********************************************************************************************************************************************


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER_1_VidInit(void);

void TIMER_1_VidSetCompareMatchValueOn_OCR1A(u16 Copy_U16CompareMatchValue);
void TIMER_1_VidSetCompareMatchValueOn_OCR1B(u16 Copy_U16CompareMatchValue);
void TIMER_1_VidSetCompareMatchValueOn_ICR1(u16 Copy_U16CompareMatchValue);

void TIMER_1_VidSetTimerValueOnNormalMode(u16 Copy_U16TimerValue);
u16 TIMER_1_VidReadTimerValueNormalMode(void);

void TIMER_1_VidSetCallback(void(*ptr)(void) , u32 Copy_U8TimeIn_mSec);

void TIMER_1_VidInitForServoMotorOCR1A(void);
void TIMER_1_VidInitForServoMotorOCR1B(void);


void TIMER_1_VidDelay(u32 Copy_U8TimeIn_mSec);

void TIMER_1_VidICUInit(void);
void TIMER_1_VidICUSetTriggerEdge(u8 Copy_U8ICUEdgeType);
u16 TIMER_1_VidICUGetInputCaptureValue(void);
void TIMER_1_VidICUSetCallBack(void (*Copy_pFun) (void));
void TIMER_1_VidClearTimer1Value(void);

void TIMER_voidTimer1GeneratePWMOCR1A(u8 Copy_u8Intensity);
void TIMER_voidTimer1GeneratePWMOCR1B(u8 Copy_u8Intensity);

/* This MACRO Used in Func -> TIMER_1_VidICUSetTriggerEdge
 *                            To Select Trigger Eadge
 *                            Option : "0" to "TIMER_1_ICU_RISING_EDGY_TYPE_MODE"
 *                            		   "1" to "TIMER_1_ICU_FALLING_EDGY_TYPE_MODE"
 *                            		   */
#define TIMER_1_ICU_RISING_EDGY_TYPE_MODE   0
#define TIMER_1_ICU_FALLING_EDGY_TYPE_MODE  1


#endif
