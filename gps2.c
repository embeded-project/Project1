#include "C:\Keil\EE319Kware\inc\tm4c123gh6pm.h"
#include "string.h"
#include "stdint.h"


void UART0_INIT(){
	SYSCTL_RCGCUART_R |=SYSCTL_RCGCUART_R0;
	SYSCTL_RCGCGPIO_R |=SYSCTL_RCGCGPIO_R0;
	
	UART0_CTL_R &=~ UART_CTL_UARTEN;
	UART0_IBRD_R = 104;
	UART0_FBRD_R = 11;
	UART0_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	UART0_CTL_R = (UART_CTL_RXE | UART_CTL_TXE |UART_CTL_UARTEN);
	
	GPIO_PORTA_AFSEL_R |= 0x03;
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R &= ~0xFF)|(GPIO_PCTL_PA1_U0TX|GPIO_PCTL_PA0_U0RX);
	GPIO_PORTA_DEN_R |= 0x03;
	GPIO_PORTA_AMSEL_R &= ~0x03;
	
	
	
	
	
	
	
}
void UART_OutChar(char data)  {
	while ((UART0_FR_R & 0x0080)==0);   //wait if the transmitter FIFO is fuul
	UART0_DR_R = data ;
}
char UART_InChar(void){
	while ((UART0_FR_R & 0x0080)==0);    //wait if the receiver FIFO is empty
	return (char)(UART0_DR_R & 0xFF );   //return the data 
	
	
}

void receive_command(char* command , int length) {
	char character;
	int i;
	for (i=0; i<length; i++){
		character=UART_InChar();
		
		
	}
	
	
}
void LCD_OutPut(char data) {
	
	
}



int main() {
	UART0_INIT();
	int i=0 ;
	char command [i];
	
	
	while (1) {
		
		
	}
	
	
	
	
	return 0 ;
	
	
}