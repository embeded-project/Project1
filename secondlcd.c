#include <stdint.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h.h"
#include <math.h>
#include <stdbool.h>
#define LCD_RS  (*((volatile unsigned long *)0x40004200))
#define LCD_EN  (*((volatile unsigned long *)0x40004100))
#define LCD_RW  (*((volatile unsigned long *)0x40004080))
void SystemInit(){}
void mdelay(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {}
}
void udelay(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {}

}
void LCD_init(void) {
    volatile unsigned long delay;
    //portB
    SYSCTL_RCGC2_R |= 0X00000002;
    delay = SYSCTL_RCGC2_R;
    GPIO_PORTB_AFSEL_R &= ~0xFF;
    GPIO_PORTB_AMSEL_R &= ~0XFF;
    GPIO_PORTB_PCTL_R &= ~0XFF;
    GPIO_PORTB_DIR_R  |= 0XFF;
    GPIO_PORTB_DEN_R  |= 0XFF;
     //portA
    SYSCTL_RCGC2_R |= 0X00000001;
    delay = SYSCTL_RCGC2_R;
    GPIO_PORTA_AFSEL_R &= ~0xE0;
    GPIO_PORTA_AMSEL_R &= ~0XE0;
    GPIO_PORTA_PCTL_R &= ~0XE0;
    GPIO_PORTA_DIR_R |= 0XE0;
    GPIO_PORTA_DEN_R |= 0XE0;
}