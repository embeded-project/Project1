#include <stdint.h>
#include <stdlib.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "stdlib.h"
#include <stdbool.h>
#include <string.h>
void UART5_init(void){
    //portE UART5
SYSCTL_RCGCUART_R |=0x20;
SYSCTL_RCGCGPIO_R |=0x10;
UART5_CTL_R &=~(0x01);
UART5_IBRD_R =104;
UART5_FBRD_R =11;
UART5_LCRH_R |=0x70;
UART5_CTL_R |=0x301;
GPIO_PORTE_DEN_R |=0x0030;
GPIO_PORTE_AMSEL_R &=~0x0030;
GPIO_PORTE_AFSEL_R |=0x0030;
GPIO_PORTE_PCTL_R =(GPIO_PORTE_PCTL_R&0xFF00FFFF)+0x00110000;
}

char UART_read(void){
    while((UART5_FR_R&0x0010) !=0);
    return (char)(UART5_DR_R&0xFF);
}
void Get_gpsdata(char * Command, int len){
    char c ;
    int i;
    for (i=0; i< len; i++){
        c=UART_read();
         Command[i]=c;
       }
}
void GPS(void){
      char* lat = NULL;
      char* Buffer = NULL;
      char* buffpoint;
      char* buffpoint2;
      const char s[2] = ",";
      const char s2[2] = "$";
      char* lon;
      char BufferAll[300];
      Get_gpsdata(BufferAll, 300);
      buffpoint = strtok(BufferAll, s2);
      for (int i = 0; i < 5; i++){
          if (buffpoint[3] == 'G'){ Buffer = buffpoint;}
          buffpoint = strtok(NULL, s2);
      }
       buffpoint2 = strtok(Buffer, s);
      if (buffpoint2 != NULL) {
          for (int i = 0; i < 14; i++) {
              if (i == 2) { lat = buffpoint2; }
              if (i == 4) { lon = buffpoint2; }
              buffpoint2 = strtok(NULL, s);
          }
      }
}
int main()
{
UART5_init();
GPS();
}