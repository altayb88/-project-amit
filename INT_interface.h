//********************************************************************************************************************************************
//**************Auther: altayb **********************************************************************************
//**************File  : Interface of INT    		       ***********************************************************************************
//**************Date  : 9/2/2024        			       *******************************************************************************
//**************Var   : V1               	               *******************************************************************************
//**************Desc  :                  		           *******************************************************************************
//********************************************************************************************************************************************


#ifndef INT_INTERFACE_H
#define  INT_INTERFACE_H




void INT_VoidInit(void);
void INT0_SeneseControlMode(u8 mood);
void INT1_SeneseControlMode(u8 mood);
void INT2_SeneseControlMode(u8 mood);
void INT0_Set_CallBack(void(*INT0PTR)(void));
void INT1_Set_CallBack(void(*INT1PTR)(void));
void INT2_Set_CallBack(void(*INT2PTR)(void));
void INT0_VoidDisable_int0PIE(void);
void INT0_VoidEnable_int0PIE(void);
void INT1_VoidDisable_int0PIE(void);
void INT1_VoidEnable_int0PIE(void);
void INT2_VoidDisable_int0PIE(void);
void INT2_VoidEnable_int0PIE(void);





#endif


