/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : DoorLock_AUTOSAR_Project  	                         */
/* File          : DIO.c 			                            		 */
/* Date          : Nov 6, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "DIO.h"

uint8 Dio_ReadChannel(uint8 ID){
	return (MCAL_GPIO_ReadPin(GPIO_PORT_USED, ID));
}

void  Dio_WriteChannel(uint8 ID, uint8 Level){
	MCAL_GPIO_WritePin(GPIO_PORT_USED, ID, Level);
}
