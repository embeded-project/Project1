#pragma once
double ExtractLat(char* lat) {
	double dlat = atof(lat);
	double dlat2 = dlat / 100;
	int dint = (int)dlat2;
	double dpoint = (dlat2 - dint) * 100;
	return dint + (dpoint / 60);
}