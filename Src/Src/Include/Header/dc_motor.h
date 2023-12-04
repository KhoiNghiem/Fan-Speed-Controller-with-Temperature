/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the DC motor driver
 *
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_PORT					PORTB_ID
#define MOTOR_INPUT1_PIN_ID			PIN0_ID
#define MOTOR_INPUT2_PIN_ID			PIN1_ID
#define MOTOR_ENABLE_PIN_ID 		PIN3_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	STOP,CW,ACW
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */

void DcMotor_init(void);

/*
 * Description:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DC_MOTOR_H_ */
