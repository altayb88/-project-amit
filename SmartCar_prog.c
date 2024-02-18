//**********************************************************************************************************************************************
//******************************************************************************************************************************************
//************** Auther:  altayb  ****************************************************************************************************
//************** File  : Program of SmartCar 		      *****************************************************************************************************
//************** Date  : 11/2/2024    				      *****************************************************************************************************
//************** Var   : V1        				          ******************************************************************************************************
//*********************************************************************************************************************************************
//**********************************************************************************************************************************************

#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "Bit-math.h"

#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "TIMER1_interface.h"
#include "GIE_interface.h"
#include "INT_interface.h"
#include "UART_interface.h"

#include "SRVMO_interface.h"
#include "ULTRASONIC_SENSOR_interface.h"

#include "SmartCar_cfg.h"
#include "SmartCar_interface.h"

/*********************************   Car Speed Function    **********************************/

void SmartCar_VidSetSpeed(u8 Copy_U8Speed)
{
	/* Cfg TIMER 0 To Generate Fast PWM */
	TIMER_0_VidGenerateFastPWM(Copy_U8Speed);
}


/******************************   Car Directions Functions    ******************************/

void SmartCar_VidStop(void)
{
	/* All Motors Stop */
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN1,LOW);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN2,LOW);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN3,LOW);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN4,LOW);
}

void SmartCar_VidMoveForward(void)
{
	/* All Motors Move Forward */
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN1,LOW);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN2,HIGH);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN3,LOW);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN4,HIGH);
}

void SmartCar_VidMoveBackward(void)
{
	/* All Motors Move Backward */
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN1,HIGH);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN2,LOW);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN3,HIGH);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN4,LOW);
}

void SmartCar_VidMoveLeft(void)
{
	/* Left Motors Move Backword And Right Motors Move Forword */
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN1,LOW);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN2,HIGH);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN3,HIGH);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN4,LOW);

}

void SmartCar_VidMoveRight(void)
{
	/* Right Motors Move Backword And Left Motors Move Forword */
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN1,HIGH);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN2,LOW);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN3,LOW);
	DIO_VidSetPinValue(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN4,HIGH);
}

/***************************************************/

void SmartCar_VidStepForward(void)
{
	/* Take Step Forward Then Stop */
	SmartCar_VidMoveForward();
	_delay_ms(300);
	SmartCar_VidStop();
}

void SmartCar_VidStepBackward(void)
{
	/* Take Step Backward Then Stop */
	SmartCar_VidMoveBackward();
	_delay_ms(100);
	SmartCar_VidStop();
}

void SmartCar_VidLeft90(void)
{
	/* Turn Left 90 degree then Stop */
	SmartCar_VidMoveLeft();
	_delay_ms(300);
	SmartCar_VidStop();
}

void SmartCar_VidLeft45(void)
{
	/* Turn Left 45 degree then Move Forward */
	SmartCar_VidMoveLeft();
	_delay_ms(125);
	SmartCar_VidMoveForward();
}

void SmartCar_VidBackwardLeft45(void)
{
	/* Turn Left 45 degree then Move Backword */
	SmartCar_VidMoveLeft();
	_delay_ms(125);
	SmartCar_VidMoveBackward();
}

void SmartCar_VidRight90(void)
{
	/* Turn Right 90 degree then Stop */
	SmartCar_VidMoveRight();
	_delay_ms(250);
	SmartCar_VidStop();
}

void SmartCar_VidRight45(void)
{
	/* Turn Right 45 degree then Move Forward */
	SmartCar_VidMoveRight();
	_delay_ms(125);
	SmartCar_VidMoveForward();
}

void SmartCar_VidBackwardRight45(void)
{
	/* Turn Right 90 degree then Move Backward */
	SmartCar_VidMoveRight();
	_delay_ms(125);
	SmartCar_VidMoveBackward();
}

void SmartCar_VidRevers(void)
{
	/* Turn 180 degree then Stop */
	SmartCar_VidMoveRight();
	_delay_ms(425);
	SmartCar_VidStop();
}

void SmartCar_VidSlowlyStop(void)
{
	SmartCar_VidSetSpeed(50);
	_delay_ms(20);
	SmartCar_VidSetSpeed(40);
	_delay_ms(20);
	SmartCar_VidSetSpeed(30);
	_delay_ms(20);
	SmartCar_VidSetSpeed(20);
	_delay_ms(20);
	SmartCar_VidSetSpeed(10);
	_delay_ms(20);
	SmartCar_VidStop();
}


/***************************     Obstacle Avoiding Mode     ***********************************/

u16 SmartCar_VidRightDistance(void)
{
	/* Turn Servo to Right Angle (0) */
	SRVMO_VidSetAngle(SMARTCAR_RIGHT_ANGLE);
	_delay_ms(300);
	/* Read Right Distance */
	u16 Local_RDistance = ULTRASONIC_SENSOR_GetDistance();
	_delay_ms(300);
	/* Turn Servo to Forward Angle (75) */
	SRVMO_VidSetAngle(SMARTCAR_FORWARD_ANGLE);
	/* Return Right Distance */
	return Local_RDistance;
}

u16 SmartCar_VidLeftDistance(void)
{
	/* Turn Servo to Left Angle (180) */
	SRVMO_VidSetAngle(SMARTCAR_LEFT_ANGLE);
	_delay_ms(300);
	/* Read Left Distance */
	u16 Local_LDistance = ULTRASONIC_SENSOR_GetDistance();
	_delay_ms(300);
	/* Turn Servo to Forward Angle (75) */
	SRVMO_VidSetAngle(SMARTCAR_FORWARD_ANGLE);
	/* Return Left Distance */
	return Local_LDistance;
}

void SmartCar_VidObstacleAvoidingMode(void)
{
	/* Send String To User (UART Func) */
	UART_VidSendString("*************************************\n ");
	UART_VidSendString("Obstacle Avoiding Mode \n ");
	UART_VidSendString("Enter E => To Eixt Mode \n ");
	UART_VidSendString("*************************************\n ");

	/* Set Obstacle Avoiding Mode Speed */
	SmartCar_VidSetSpeed(SMARTCAR_OBSTACLE_MODE_SPEED);

	u16 Local_U16LeftDistance   = 0 ;
	u16 Local_U16RightDistance  = 0 ;
	u16 Local_U16ObjectDistance = 0 ;

	u8 Local_U8Data = 0;

	/* Set Servo in Forward Angle (75) */
	SRVMO_VidSetAngle(SMARTCAR_FORWARD_ANGLE);
	_delay_ms(1000);
	SmartCar_VidMoveForward();

	while(1)
	{
		/* Read Char From User (UART Func) */
		Local_U8Data = UART_U8ReadData();
        /* To Exit this Mode Enter 'E' */
		if(Local_U8Data == 'E')
		{
			SmartCar_VidStop();
			_delay_ms(50);
			break ;
		}

		/* Set Servo in Forward Angle (75) */
		SRVMO_VidSetAngle(SMARTCAR_FORWARD_ANGLE);

		/* Read Object Distance */
		Local_U16ObjectDistance = ULTRASONIC_SENSOR_GetDistance();
		Local_U16ObjectDistance = ULTRASONIC_SENSOR_GetDistance();
		_delay_ms(20);

		/*
		 * if no Object Move Forward
		 *
		 * if Find Object Stop
		 * Read left and right Distance
		 * Move to Empty Road
		 *
		 * */
		if(Local_U16ObjectDistance <= 25)
		{
			SmartCar_VidStop();
			_delay_ms(50);
			SmartCar_VidStepBackward();

			/* Read Left Distance */
			Local_U16LeftDistance = SmartCar_VidLeftDistance();
			_delay_ms(200);

			/* Read Right Distance */
			Local_U16RightDistance = SmartCar_VidRightDistance();
			_delay_ms(200);

			/* Set Servo in Forward Angle (75) */
			SRVMO_VidSetAngle(SMARTCAR_FORWARD_ANGLE);
			_delay_ms(100);

			/* Compare The Left Distance And Right Distance */
			if(Local_U16LeftDistance >= Local_U16RightDistance)
			{
				SmartCar_VidLeft45();
			}
			else if(Local_U16LeftDistance < Local_U16RightDistance)
			{
				SmartCar_VidRight45();
			}
			else if( Local_U16LeftDistance < 15 && Local_U16RightDistance < 15 )
			{
				SmartCar_VidRevers();
			}
		}
		else
		{
			/* Move Forward if No Object */
			SmartCar_VidMoveForward();
		}
	}
}

/*******************************      Control Mode      *********************************/

void SmartCar_VidControlMode(void)
{
	/* Send String To User (UART Func) */
	UART_VidSendString("*************************************\n ");
	UART_VidSendString("Control Mode \n ");
	UART_VidSendString("Enter E => To Eixt Mode \n ");
	UART_VidSendString("*************************************\n ");

	/* Set Control Mode Speed */
	SmartCar_VidSetSpeed(SMARTCAR_CONTROL_MODE_SPEED);

	u8  Local_U8Data =0 ;

	while(1)
	{
		/* Read Char From User (UART Func) */
		Local_U8Data = UART_U8ReadData();
		_delay_ms(20);
		Local_U8Data = UART_U8ReadData() ;

        /* To Exit this Mode Enter 'E' */
	    if  (Local_U8Data == 'E')
	    {
	    	SmartCar_VidStop();
			_delay_ms(50);
	    	break;
	    }

		/* Set Servo in Forward Angle (75) */
	    SRVMO_VidSetAngle(SMARTCAR_FORWARD_ANGLE);

		switch (Local_U8Data)
		{
			case 'F':
				SmartCar_VidMoveForward();
				break;

			case 'B':
				SmartCar_VidMoveBackward();
				break;

			case 'L':
				SmartCar_VidMoveLeft();
				break;

			case 'R':
				SmartCar_VidMoveRight();
				break;

			case 'S':
				SmartCar_VidStop();
				break;

			case'G':
				SmartCar_VidLeft45();
				break;

			case'I':
				SmartCar_VidRight45();
				break;

			case'H':
				SmartCar_VidBackwardLeft45();
				break;

			case'J':
				SmartCar_VidBackwardRight45();
				break;



			case '1' :
				SmartCar_VidSetSpeed(10);
				break;

			case '2' :
				SmartCar_VidSetSpeed(20);
				break;

			case '3' :
				SmartCar_VidSetSpeed(30);
				break;

			case '4' :
				SmartCar_VidSetSpeed(40);
				break;

			case '5' :
				SmartCar_VidSetSpeed(50);
				break;

			case '6' :
				SmartCar_VidSetSpeed(60);
				break;

			case '7' :
				SmartCar_VidSetSpeed(70);
				break;

			case '8' :
				SmartCar_VidSetSpeed(80);
				break;

			case '9' :
				SmartCar_VidSetSpeed(90);
				break;

			case 'q' :
				SmartCar_VidSetSpeed(100);
				break;
		}
	}
}

/******************************     Humans Tracking Mode     *********************************/

void SmartCar_VidTrackingHumansMode(void)
{
	/* Send String To User (UART Func) */
	UART_VidSendString("*************************************\n ");
	UART_VidSendString("Tracking Mode \n ");
	UART_VidSendString("Enter E => To Eixt Mode \n ");
	UART_VidSendString("*************************************\n ");

	/* Set Tracking Mode Speed */
	SmartCar_VidSetSpeed(SMARTCAR_TRACKING_MODE_SPEED);

	u8 Local_U8Data = 0;

	u8 Local_U8_IR_1_Pin = 0;        //Right
	u8 Local_U8_IR_2_Pin = 0;        //Left
	u16 Local_U16HumanDistance = 0;

	while(1)
	{
		/* Read Char From User (UART Func) */
		Local_U8Data = UART_U8ReadData();
        /* To Exit this Mode Enter 'E' */
		if(Local_U8Data=='E')
		{
			SmartCar_VidStop();
			_delay_ms(50);
			break ;
		}

		/* Set Servo in Forward Angle (75) */
		SRVMO_VidSetAngle(SMARTCAR_FORWARD_ANGLE);

		/* Read Human Distance */
		Local_U16HumanDistance = ULTRASONIC_SENSOR_GetDistance();
		Local_U16HumanDistance = ULTRASONIC_SENSOR_GetDistance();
		_delay_ms(10);

		/* Get IR SENSORS Value */
		Local_U8_IR_1_Pin = DIO_U8GetPinValue(SMARTCAR_IR_SENSOR_1_PORT,SMARTCAR_IR_SENSOR_1_PIN);
		Local_U8_IR_2_Pin = DIO_U8GetPinValue(SMARTCAR_IR_SENSOR_2_PORT,SMARTCAR_IR_SENSOR_2_PIN);
		_delay_ms(10);

		/* if Human Distance Read (0..6) => Move Backward */
		if ( Local_U16HumanDistance >= 0  &&  Local_U16HumanDistance <= 6 )
		{
			SmartCar_VidMoveBackward();
		}
		/* if Human Distance Read (7..25) => Move Forward */
		else if ( Local_U16HumanDistance >= 7  &&  Local_U16HumanDistance <= 25 )
		{
			SmartCar_VidMoveForward();
		}
		/* if Human Distance Read more than 26 => Stop */
		else if ( Local_U16HumanDistance >= 26 )
		{
			SmartCar_VidStop();
		}

        /* if IR_1_Pin read 0 and IR_2_Pin read 1 => Turn Right  */
		if (Local_U8_IR_1_Pin == 0 && Local_U8_IR_2_Pin == 1 )
		{
			SmartCar_VidMoveRight();
		}
        /* if IR_1_Pin read 1 and IR_2_Pin read 0 => Turn Left  */
		else if (Local_U8_IR_1_Pin==1 && Local_U8_IR_2_Pin==0)
		{
			SmartCar_VidMoveLeft();
		}

	}
}

/***********************************     Initialization     ***********************************/
void SmartCar_VidInit(void)
{
	/* initilization */
	GIE_VidEnable();
	UART_VidInit();
	ULTRASONIC_VoidInit();
	SRVMO_VidInit();

	TIMER_0_VidInit();                           // For Robot Speed
	DIO_VidSetPinDirectoin(PORTB,PIN3,OUTPUT);   // PB3 (OC0) Set As Output

	/* For ROBOT_MOTOR_DRIVER_L298N_PINS */
	DIO_VidSetPinDirectoin(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN1,OUTPUT);  /* IN1 */
	DIO_VidSetPinDirectoin(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN2,OUTPUT);  /* IN2 */
	DIO_VidSetPinDirectoin(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN3,OUTPUT);  /* IN3 */
	DIO_VidSetPinDirectoin(SMARTCAR_MOTOR_DRIVER_L298N_PORT,SMARTCAR_MOTOR_DRIVER_L298N_IN4,OUTPUT);  /* IN4 */

	/* For ROBOT_IR_SENSORS_PINS */
	DIO_VidSetPinDirectoin(SMARTCAR_IR_SENSOR_1_PORT,SMARTCAR_IR_SENSOR_1_PIN,INPUT);  /* IR1 */
	DIO_VidSetPinValue(SMARTCAR_IR_SENSOR_1_PORT,SMARTCAR_IR_SENSOR_1_PIN,HIGH);
	DIO_VidSetPinDirectoin(SMARTCAR_IR_SENSOR_2_PORT,SMARTCAR_IR_SENSOR_2_PIN,INPUT);  /* IR2 */
	DIO_VidSetPinValue(SMARTCAR_IR_SENSOR_2_PORT,SMARTCAR_IR_SENSOR_2_PIN,HIGH);

}

/***********************************     Program     ***********************************/

void SmartCar_VidProg(void)
{
	u8 Local_U8ModeSelctoin = 0;

	UART_VidSendString("******************************************\n ");
	UART_VidSendString("Select Car Mode \n ");
	UART_VidSendString("Enter 1 => Avoiding Obstacle Mode \n ");
	UART_VidSendString("Enter 2 => Control Mode \n ");
	UART_VidSendString("Enter 3 => Tracking Mode \n ");
	UART_VidSendString("******************************************\n ");

	SmartCar_VidSetSpeed(SMARTCAR_MAX_SPEED);
	SRVMO_VidSetAngle(SMARTCAR_FORWARD_ANGLE);

	_delay_ms(2000);

	Local_U8ModeSelctoin = UART_U8ReadData();
	_delay_ms(100);
	Local_U8ModeSelctoin = UART_U8ReadData();


	switch(Local_U8ModeSelctoin)
	{
	case '1' :
		_delay_ms(2000);
		SmartCar_VidObstacleAvoidingMode();
		break ;
	case '2':
		_delay_ms(2000);
		SmartCar_VidControlMode();
		break ;
	case '3':
		_delay_ms(2000);
		SmartCar_VidTrackingHumansMode();
		break ;
	}
}