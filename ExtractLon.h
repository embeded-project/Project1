#pragma once
double ExtractLon(char* lon) {
	double dlon = atof(lon);
	double dlon2 = dlon / 100;
	int dint = (int)dlon2;
	double dpoint = (dlon2 - dint) * 100;
	return dint + (dpoint / 60);
}