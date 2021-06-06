#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h.h"
#include "C:/Keil/ARM/INC/TI/TM4C123/TM4C123GH6PM.h"
void SystemInit () {}
	//uint32_t delay();
	void LCD_Data (char data)
	{
		GPIO_PORTA_DATA_R = 0x20;
		GPIO_PORTB_DATA_R = data;
		GPIO_PORTA_DATA_R |=0x80;
		//delay (230);
	GPIO_PORTA_DATA_R = 0 ;
				
	}
	
void LCD_Command (char com)
	{
		GPIO_PORTA_DATA_R = 0;
		GPIO_PORTB_DATA_R = com;
		GPIO_PORTA_DATA_R |=0x80;
	//	delay (230);
	GPIO_PORTA_DATA_R = 0 ;
				
	}
	void init (void)
	{
		//uint32_t  delay;
		SYSCTL_RCGCGPIO_R |=0x03;
		//while ((SYSCTL_PRGPIO_R & 0x03)==0){};
		GPIO_PORTB_LOCK_R = 0x4C4F434B ;
		GPIO_PORTA_LOCK_R = 0x4C4F434B ;
		GPIO_PORTB_CR_R = 0xFF ;
		GPIO_PORTA_CR_R = 0xE0 ;
		GPIO_PORTB_DIR_R = 0xFF ;
		GPIO_PORTB_DEN_R = 0xFF ;
		GPIO_PORTA_DIR_R = 0xE0 ;
		GPIO_PORTA_DEN_R = 0xE0 ;
		GPIO_PORTB_AMSEL_R = 0 ; 
		GPIO_PORTB_AFSEL_R = 0 ;
		GPIO_PORTB_PCTL_R = 0 ; 
		GPIO_PORTA_AMSEL_R = 0 ; 
		GPIO_PORTA_AFSEL_R = 0 ;
		GPIO_PORTA_PCTL_R = 0 ; 
		
		
		
		
					
		}
	
	int main()
		{
	init();
			
			while (1)
			{
				LCD_Command(0x01);       //clear screen
				//delay (230);
				LCD_Command(0x80);       //curser begin from first line 
				//delay (230);
				LCD_Command(0x30);      //wakeup
				//delay (230);
				LCD_Command(0x38);       //8-bits
				//delay (230);
				LCD_Command (0x06);      //increment curser 
				//delay (230);
				LCD_Command (0x0F);      //display on 
				//delay (230);
				LCD_Data ('A');
				//delay (230);
				LCD_Data ('B');
				
				
			}
}