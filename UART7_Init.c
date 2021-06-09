#include <stdint.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
void SystemInit(){}
void UART7_Init(void){
SYSCTL_RCGCUART_R |= 0x80;
SYSCTL_RCGCGPIO_R|= 0x10;
UART7_CTL_R &= ~(0x001);
UART7_IBRD_R = 104;
UART7_FBRD_R = 11;
UART7_CTL_R |= 0x301;
UART7_LCRH_R|= 0x70;
GPIO_PORTE_AFSEL_R |= 0x03;
GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & ~(0x000000FF) )| 0x00000011;
GPIO_PORTE_DEN_R |= 0x03;
GPIO_PORTE_AMSEL_R &= ~(0x03);
}
int main(){
    UART7_Init();
}
