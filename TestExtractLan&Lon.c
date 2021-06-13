/*
 * TestExtractLan&Lon.c
 *
 *  Created on: Jun 13, 2021
 *      Author: DELL
 */


#include "ExtractLat.h"
#include "ExtractLon.h"
int main() {
    char* lat = NULL;
    char* buffpoint;
    char* lon = NULL;
    char Buffer[] = { "$GPGGA,184241.000,1829.9639,N,07347.6174,E,1,05,2.1,607.1,M,-64.7,M,,0000*7C" };
       double lat = ExtractLat(Buffer);
         buffpoint = strtok(Buffer, s);
          if (buffpoint != NULL) {
          for (int i = 0; i < 14; i++) {
              // printf("%s\n", buffpoint);
              if (i == 2) { lat = buffpoint; }
              if (i == 4) { lon = buffpoint; }
              //printf("%s\n", lan);
              buffpoint = strtok(NULL, s);
          }
          double  ActualLat=  ExtractLan(lat);
          double ActualLon = Extractlon(lon);
          //will be sent to function distance
}


