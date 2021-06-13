#include "Initializations.h"
#include "tm4c123gh6pm.h"
#include <Math.h>
#define PI 3.14159265359
#include <string.h>
#include <stdlib.h>
#include "LCD.h"





float calculate(float ExLatitude,float ExLongitude,float NLatitude,float NLongitude){

	float dy = (NLatitude-ExLatitude)* PI/180.0;
	float dx = (NLatitude-ExLongitude)* PI/180.0;
	

	ExLatitude = (ExLatitude)* PI/180.0;
	NLatitude = (NLatitude)* PI/180.0;
	

	float a = pow(sin(dy / 2), 2) + pow(sin(dx / 2), 2) * cos(ExLatitude) * cos(NLatitude);
	float r = 6371, dist = 2 * asin(sqrt(a));
	return r * dist * 1000;
}

float total (float ExLatitude, float ExLongitude, float NLatitude, float NLongitude)
{ 
	float Total=0;
	if(ExLongitude!=0 && ExLatitude !=0){ 
		Total = calculate(ExLatitude,ExLongitude,NLatitude,NLongitude);
	}
	return Total;
}

void delay(int north)
{
	int i;
	int j;
	for(i=0 ; i<north ; i++)
	{
		for(j=0; j<3180; j++)
		{
			
		}
	}
}