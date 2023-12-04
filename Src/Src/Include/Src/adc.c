 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType *config_ptr)
{

	/* ADMUX Register Bits Description:
	 * REFS1:0 = to choose to connect internal reference voltage by input this voltage 2.56V (bits 6&7)
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */

	//ADMUX =((ADMUX&0X3F)| (((config_ptr->voltage)&0X03) << REFS0));
	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = Configurable --> ADC must operate in range 50-200Khz
	 */
	//ADCSRA = (1<<ADEN) | ((ADCSRA&0XF8)|((config_ptr->prescaler)&0X07));
	ADMUX=((config_ptr->voltage)<<6); // 0000 0110 Khong hieu lam
	ADCSRA=(1<<ADEN) |(config_ptr->prescaler); // Cho bit ADEN = 1
}

// Ham dung de doc gia tri cam bien nhiet do va chuyen tu tuong tu sang so
uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* 0000 0111 Input channel number must be from 0 --> 7 */ // dung de khoi tao
	ADMUX &= 0xE0; /* 1110 0000 Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
