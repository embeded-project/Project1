#include <math.h>
#include <stdint.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <stdbool.h>
#define LCD_RS  (*((volatile unsigned long *)0x40004200))
#define LCD_EN  (*((volatile unsigned long *)0x40004100))
#define LCD_RW  (*((volatile unsigned long *)0x40004080))
#define PI 3.14159265358979323846
void SystemInit(){}
void initialize_portF(void){
//uint32_t delay;
SYSCTL_RCGCGPIO_R|= 0x20;
//delay = 1; //dummy var
//while((SYSCTL_PRGPIO_R & 0x20) == 0);
GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R =0x1F;
GPIO_PORTF_PCTL_R =0;
GPIO_PORTF_AFSEL_R = 0;
GPIO_PORTF_AMSEL_R = 0 ;
GPIO_PORTF_DEN_R = 0x1F;
GPIO_PORTF_DIR_R = 0x0E;
GPIO_PORTF_PUR_R = 0x11;
}
void Turn_On_LED(void){
    GPIO_PORTF_DATA_R = 0x02;
}
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
double ToRadian(double deg){
return (deg*(PI/180));
}
double distance_small(double lat1 , double lon1 ,double lat2 , double lon2 ){
double RadiusEarth = 6371;
double difflat = ((ToRadian(lat2))-(ToRadian(lat1))) ;
double difflan = ((ToRadian(lon2))-(ToRadian(lon1)));
double a = sin(difflat/2) * sin(difflat/2) + cos(ToRadian(lat1))*cos(ToRadian(lat1))*sin(difflan /2) * sin(difflan/2);
double c = 2*atan2(sqrt(a),sqrt(1-a));
double d = RadiusEarth *c;
return d;
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
int main(void) {
  double total=0;
  //double latt[100];
  //double lonn[100];
   int i=0;
  //the location path has 3 turning point from start to end
  //start location latitude and longitude
  double lat0 =30.069966;
  double lon0 =31.282305;
  //First turning point
  double lat1 = 30.070900;
  double lon1 = 31.279999;
   //Second Turning point
   double lat2 = 30.070492;
   double lon2 = 31.279419;
   //Third Turning point
   double lat3 = 30.070733;
   double lon3 = 31.279055;
   //End point
   double latF =30.067039;
   double lonF = 31.27663;
 double d1= distance_small(lat0,lon0,lat1,lon1);
 double d2 = distance_small(lat1,lon1,lat2,lon2);
 double d3 = distance_small(lat2 , lon2 , lat3  , lon3);
double d4 = distance_small(lat3 , lon3 , latF  , lonF);
total = d1 +d2+ d3 + d4; //distance in km
if (total>0.1){
       LCD_init();
       initialize_portF();
       Display_num();
       Turn_On_LED();

}
}
