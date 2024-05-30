#include "Calculation.h"

int main() {
	double time = T / 13.6;
	double perigee_time = 0;
	double apogee_time = T / 2.0;
	calculation(perigee_time);
	calculation(time);
	calculation(apogee_time);
	return 0;
}