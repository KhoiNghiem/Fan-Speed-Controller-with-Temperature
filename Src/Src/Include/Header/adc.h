 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL
}ADC_ReferanceVoltage;

typedef enum
{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferanceVoltage voltage;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *config_ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
