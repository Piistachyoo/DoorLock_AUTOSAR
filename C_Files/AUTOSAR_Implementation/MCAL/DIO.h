/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : DoorLock_AUTOSAR_Project  	                         */
/* File          : DIO.h 			                            		 */
/* Date          : Nov 6, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "gpio_driver.h"

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------
#define DOOR_ID	GPIO_PIN_3
#define LED_ID	GPIO_PIN_7

#define GPIO_PORT_USED	GPIOA

/*
 * =============================================
 * APIs Supported by "DIO"
 * =============================================
 */
uint8 Dio_ReadChannel(uint8 ID);
void  Dio_WriteChannel(uint8 ID, uint8 Level);

/**=============================================
 * @Fn			- 
 * @brief 		- 
 * @param [in] 	- 
 * @retval 		- 
 * Note			- 
 */


#endif /* MCAL_DIO_H_ */
