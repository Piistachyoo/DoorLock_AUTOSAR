/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : DoorLock_AUTOSAR_Project  	                         */
/* File          : main.c 			                           			 */
/* Date          : Nov 5, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "gpio_driver.h"
#include "RCC_driver.h"

#define GPIO_DOOR_SENSOR_PIN	GPIO_PIN_3
#define GPIO_DOOR_LED_PIN		GPIO_PIN_7
#define LED_ON					GPIO_PIN_RESET
#define LED_OFF					GPIO_PIN_SET

void MCU_Init(void);

void StartOS(void);

int main(){
	MCU_Init();
	StartOS();
	while(1){

	}
	return 0;
}

void MCU_Init(void){
	/* GPIO Init */
	MCAL_RCC_Enable_Peripheral(RCC_GPIOA);

	GPIO_PinConfig_t PinCfg_Door_Sensor;

	/* PA3 ---> Door Sensor */
	PinCfg_Door_Sensor.GPIO_PinNumber = GPIO_DOOR_SENSOR_PIN;
	PinCfg_Door_Sensor.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCfg_Door_Sensor);

	/* PA7 ---> Led On/OFF */
	PinCfg_Door_Sensor.GPIO_PinNumber = GPIO_DOOR_LED_PIN;
	PinCfg_Door_Sensor.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg_Door_Sensor.GPIO_OUTPUT_SPEED = GPIO_SPEED_2M;
	MCAL_GPIO_Init(GPIOA, &PinCfg_Door_Sensor);
}

#define CYCLES_PER_LOOP 3
void wait_cycles( uint32 n ) {
	uint32 l = n/CYCLES_PER_LOOP;
	asm volatile( "0:" "SUBS %[count], 1;" "BNE 0b;" :[count]"+r"(l) );
}

void StartOS(void){
	uint8 i = 0;
	while(1){
		if(i==10){
			ReadDoorSensor_Runnable();
			i++;
		}
		else if(i==12){
			DoorLock_indication_runnable();
			i=0;
		}
		else{
			i++;
		}
		wait_cycles(10);
	}
}
