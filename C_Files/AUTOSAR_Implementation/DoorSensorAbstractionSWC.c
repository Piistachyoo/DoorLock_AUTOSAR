/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : DoorLock_AUTOSAR_Project  	                         */
/* File          : DoorSensorAbstractionSWC.c 			                 */
/* Date          : Nov 6, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "Rte_DoorSensorAbstractionSWC.h"
#include "DIO.h"

#define LEDON	0
#define LEDOFF	1

/*****************************************************
 * Port: 		PP_CS_LEDSwitch
 * Interface:	IF_CS_LED
 * Operation:	LED_Switch
 *****************************************************/
Std_ReturnType Led_Switch_Runnable(myuint8 LedState){
	Std_ReturnType ret_val = E_NOT_OK;

	if(LedState == LEDON){
		Dio_WriteChannel(LED_ID,  LEDON);
		ret_val =  E_OK;
	}
	else if(LedState == LEDOFF){
		Dio_WriteChannel(LED_ID,  LEDOFF);
		ret_val =  E_NOT_OK;
	}
	return ret_val;
}

/*****************************************************
 * Runnable: 	ReadDoorSensor
 * Period:		0.01
 *****************************************************/
void ReadDoorSensor_Runnable(void){
	uint8 DoorState = 0;
	DoorState = Dio_ReadChannel(DOOR_ID);

	Rte_IWrite_DoorSensorAbstractionSWC_ReadDoorSensor_PP_SR_DoorState(DoorState);
}
