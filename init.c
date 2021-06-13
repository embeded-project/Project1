#ifndef GPIO_INIT_H_
#define GPIO_INIT_H_

void initials(void);
unsigned char UART5_in(void);
void parsing(float data_arr[]);
void hundredm (unsigned short int dist);
float total(float old_latitude, float old_longitude, float new_latitude, float new_longitude);
float calculate(float old_latitude,float old_longitude,float new_latitude,float new_longitude);
void delay(int n);

#endif