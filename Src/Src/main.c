#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "pwm.h"
#include "fan_state.h"
#include "adc.h"

extern uint8 temp;

int main()
{
	/*Initialization*/
	DcMotor_init();
	//PWM_Timer0_init();

	LCD_init();
	LCD_displayStringRowColumn(0, 2, "Fan is    ");
	LCD_displayStringRowColumn(1, 2, "Temp =  C");

	ADC_ConfigType adc_requirement ={INTERNAL,F_CPU_8};
	ADC_init(&adc_requirement);


	while(1)
	{
		//PWM_Timer0_Start (30);
		temp=LM35_getTemperature(); 
		Fan_Process();
		LCD_displayUpdate();
	}
	return 0;
}
