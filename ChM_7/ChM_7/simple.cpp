#include "simple.h"


double phi_1(double y) {
	//return acos(2 * y) - 1;
	return -0.4 - sin(y);
};

double phi_2(double x) {
	//return asin(x + 0.4) - 1;
	return cos(x + 1) / 2;
};

void iterate() {
	printf("\nSimple iteration proccess started");
	double x_p = 0, y_p = 0;
	double x_n, y_n;

	x_n = phi_1(y_p);
	y_n = phi_2(x_p);
	printf("\n(01) Current (x: % .4f; y: % .4f), Previouse (x: % .4f; y: % .4f)", x_n, y_n, x_p, y_p);
	int i = 1;

	while ((fabs(x_p - x_n) + fabs(y_p - y_n)) > 0.01) {

		
		i++;
		x_p = x_n;
		y_p = y_n;

		x_n = phi_1(y_p);
		y_n = phi_2(x_p);
		printf("\n(%02d) Current (x: % .4f; y: % .4f), Previouse (x: % .4f; y: % .4f)", i, x_n, y_n, x_p, y_p);
	}

};
