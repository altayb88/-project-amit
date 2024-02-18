//**********************************************************************************************************************************************
//******************************************************************************************************************************************
//************** Auther: altayb  ****************************************************************************************************
//************** File  : Interface of SmartCar 		      *****************************************************************************************************
//************** Date  : 18/2/2024    				      *****************************************************************************************************
//************** Var   : V1        				          ******************************************************************************************************
//*********************************************************************************************************************************************
//**********************************************************************************************************************************************

#ifndef SMARTCAR_INTERFACE_H_
#define SMARTCAR_INTERFACE_H_

void SmartCar_VidSetSpeed(u8 Copy_U8Speed);

void SmartCar_VidStop(void);
void SmartCar_VidMoveForward(void);
void SmartCar_VidMoveBackward(void);
void SmartCar_VidMoveLeft(void);
void SmartCar_VidMoveRight(void);

void SmartCar_VidStepForward(void);
void SmartCar_VidStepBackward(void);
void SmartCar_VidLeft90(void);
void SmartCar_VidLeft45(void);
void SmartCar_VidBackwardLeft45(void);
void SmartCar_VidRight90(void);
void SmartCar_VidRight45(void);
void SmartCar_VidBackwardRight45(void);
void SmartCar_VidRevers(void);
void SmartCar_VidSlowlyStop(void);

u16 SmartCar_VidRightDistance(void);
u16 SmartCar_VidLeftDistance(void);
void SmartCar_VidObstacleAvoidingMode(void);

void SmartCar_VidControlMode(void);

void SmartCar_VidTrackingHumansMode(void);

void SmartCar_VidInit(void);
void SmartCar_VidProg(void);



#define SMARTCAR_MOTOR_DRIVER_L298N_PORT  PORTA
#define SMARTCAR_MOTOR_DRIVER_L298N_IN1   PIN0
#define SMARTCAR_MOTOR_DRIVER_L298N_IN2   PIN1
#define SMARTCAR_MOTOR_DRIVER_L298N_IN3   PIN2
#define SMARTCAR_MOTOR_DRIVER_L298N_IN4   PIN3

#define SMARTCAR_IR_SENSOR_1_PORT PORTA
#define SMARTCAR_IR_SENSOR_1_PIN  PIN6

#define SMARTCAR_IR_SENSOR_2_PORT PORTA
#define SMARTCAR_IR_SENSOR_2_PIN  PIN7

#define SMARTCAR_MAX_SPEED 100
#define SMARTCAR_MIN_SPEED 0

#define SMARTCAR_FORWARD_ANGLE 75
#define SMARTCAR_RIGHT_ANGLE   0
#define SMARTCAR_LEFT_ANGLE    180


#endif /* SMARTCAR_INTERFACE_H_ */
