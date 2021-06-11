#include <stdint.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
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
    //portB//
    SYSCTL_RCGC2_R |= 0X00000002;//port B clock enabled
    delay = SYSCTL_RCGC2_R; //give time for clock start
    GPIO_PORTB_AFSEL_R &= ~0xFF; //UART deactivation 
    GPIO_PORTB_AMSEL_R &= ~0XFF; //analog disabled
    GPIO_PORTB_PCTL_R &= ~0XFF; //used as i/o port
    GPIO_PORTB_DIR_R  |= 0XFF; //portB pins used as input 
    GPIO_PORTB_DEN_R  |= 0XFF; //Port B is digital enbled 

      //portA//
    SYSCTL_RCGC2_R |= 0X00000001; //Port A clock enabled
    delay = SYSCTL_RCGC2_R; //give time for clock start
    GPIO_PORTA_AFSEL_R &= ~0xE0; //UART deactivated,PA 6,7,8
    GPIO_PORTA_AMSEL_R &= ~0XE0; //analog disabled, PA6,PA7,PA8
    GPIO_PORTA_PCTL_R &= ~0XE0;// PA6,PA7,PA8 used as I/O
    GPIO_PORTA_DIR_R |= 0XE0; //pA6,PA7,PA8 used as input  
    GPIO_PORTA_DEN_R |= 0XE0; //pA6,PA7,PA8 is digital enabled
}
void LCD_command (unsigned char cmd) {
  LCD_RS = 0x00;
  LCD_RW = 0x00;
  GPIO_PORTB_DATA_R = cmd;
   LCD_EN = 0x40;
   mdelay(10);
   LCD_EN = 0x00;
}
void LCD_Data (unsigned char data) {
    LCD_RS = 0x80;
    LCD_RW = 0x00;
    GPIO_PORTB_DATA_R = data;
    LCD_EN = 0x40;
    mdelay(10);
    LCD_EN = 0x00;
}
void initialize_portF(void){
//uint32_t delay;
SYSCTL_RCGCGPIO_R|= 0x20;
//delay = 1; //dummy var
//while((SYSCTL_PRGPIO_R & 0x20) == 0);
GPIO_PORTF_LOCK_R = 0x4C4F434B; //key to unlock Port F
GPIO_PORTF_CR_R =0x1F; // unlock PF0,PF1,PF2,PF3,PF4
GPIO_PORTF_PCTL_R =0;//set as I/O port
GPIO_PORTF_AFSEL_R = 0;//alternate functions disabled
GPIO_PORTF_AMSEL_R = 0 ;//analog input disabled
GPIO_PORTF_DEN_R = 0x1F;//PF0,PF1,PF2,PF3,PF4 digital enabled
GPIO_PORTF_DIR_R = 0x0E;//PF1,PF2,PF3 used as input registers
GPIO_PORTF_PUR_R = 0x11;//PF0,PF4 internal pull up resistor activation
}
void Display_num(void){
    LCD_command(0X30);
    udelay(40);
      LCD_command(0X38);
      udelay(40);
      LCD_command(0X01);
       mdelay(10);
       udelay(40);
       LCD_command(0X0F);
       udelay(40);
      LCD_command(0X80);
    LCD_Data ('1');
    mdelay(500);
    LCD_Data('0');
    mdelay(500);
    LCD_Data('0');
    mdelay(500);
}
void Turn_On_LED(void){
    GPIO_PORTF_DATA_R = 0x02;
}
int main(void)
{
     LCD_init();
    initialize_portF();
      Display_num();
      Turn_On_LED();
}
