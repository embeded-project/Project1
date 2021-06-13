/*
 * Recieve.h
 *
 *  Created on: Jun 12, 2021
 *      Author: DELL
 */

#ifndef RECIEVE_H_
#define RECIEVE_H_
#include <stdint.h>
#include "String.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include"UART7_Init.h"

char UART_InputChar(void){
while((UART7_FR_R & 0x10) != 0);                // wait if the receive FIFO is empty
return (char)(UART7_DR_R & 0xFF);           //return the first 8 bits (Data)
}
void UART_OutputChar(char data){
while((UART7_FR_R & 0x0080) == 0);
UART0_DR_R = data;
}



#endif /* RECIEVE_H_ */
