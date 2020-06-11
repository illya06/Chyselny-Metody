#include "neuton.h"

double f_1(double x, double y) {
	return x + sin(y) + 0,4;
};

double f_2(double x, double y) {
	return 2*y - cos(x+1);
};

double yakobian(double x, double y) {
	return -(sin(x + 1) * cos(y)) / 2;
};
  
double delX(double x, double y) {
	return (1 / yakobian(0, 0)) * (f_2(x,y)*cos(y));
};

double delY(double x, double y) {
	return (1 / yakobian(0, 0)) * (f_1(x, y)*(sin(x+1)/2));
};

void iterate_n() {
	printf("\n\nNeuton iteration proccess started");
	double x_p = 10, y_p = 10;
	double x_n = 0, y_n = 0;

	int i = 1;

	while (((fabs(x_p - x_n) + fabs(y_p - y_n)) > 0.01) && i != 10) {
		i++;
		x_p = x_n;
		y_p = y_n;

		x_n = x_p + delX(x_p, y_p);
		y_n = y_p + delY(x_p, y_p);
		printf("\n(%02d) Current (x: % .4f; y: % .4f), Previouse (x: % .4f; y: % .4f)", i, x_n, y_n, x_p, y_p);
	}
};