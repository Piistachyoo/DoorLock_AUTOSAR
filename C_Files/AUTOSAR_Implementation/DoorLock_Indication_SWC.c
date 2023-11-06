/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : DoorLock_AUTOSAR_Project  	                         */
/* File          : DoorLock_Indication_SWC.c 			                 */
/* Date          : Nov 6, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "Rte_DoorLock_Indication_SWC.h"

#define LEDON	0
#define LEDOFF	1

void DoorLock_indication_runnable(void){
	unsigned char DoorState = 0;

	/* Read DoorState from RTE SR Interface */
	DoorState = Rte_IRead_DoorLock_Indication_SWC_DoorLock_indication_RP_SR_DoorState_DoorState();

	if(DoorState){
		/* Door is opened */
		Rte_Call_DoorLock_Indication_SWC_RP_CS_Led_Switch_LED_Switch(LEDON);
	}
	else{
		/* Door is closed */
		Rte_Call_DoorLock_Indication_SWC_RP_CS_Led_Switch_LED_Switch(LEDOFF);
	}
}
