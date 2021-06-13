#include "Initializations.h"
#include "tm4c123gh6pm.h"
#include "Lcd.h"

int main(void)
{
  initials();
	lcd_init();
	unsigned short int buff[10];
	float total=0;
	float lat_old=0; 
	float lon_old=0;
	float data_arr[2];
	
	command(lcd_Clear);
			