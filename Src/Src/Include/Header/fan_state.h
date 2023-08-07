/******************************************************************************
 *
 * Module: Fan state
 *
 * File Name: fan_state.h
 *
 * Description: header file for the Fan states
 *
 * Author: Menna Saeed
 *
 *******************************************************************************/

#ifndef FAN_STATE_H_
#define FAN_STATE_H_

/*******************************************************************************
 *                               Types Declaration                                 *
 *******************************************************************************/
typedef enum
{
	OFF,ON
}FAN_STATE;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*Description :
 * This function is responsible for updating the LCD display
 */
void LCD_displayUpdate(void);

/*Description:
 * This function is responsible for tracking the Fan State based on the Temperature value
 *  and rotates the DC motor accordingly
 */
void Fan_Process (void);


#endif /* FAN_STATE_H_ */
