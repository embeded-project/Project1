#include "Initializations.h"
#include "tm4c123gh6pm.h"
#include "Lcd.h"

void lcd_init (void)                     
{
	command(lcd_FunctionSet8bit);
	delay(1);

	command(lcd_EntryMode);
	delay(1);
	
	command(lcd_DisplayOn);
	delay(1);
	
	command(lcd_Clear);
	delay(2);
	
	command(lcd_Home);
	delay(2);
	
	return;
}