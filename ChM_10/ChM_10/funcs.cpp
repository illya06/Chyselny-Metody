#include "funcs.h"


double func(double x) {
	if (x <= 2 && x >= -2) {
		return log(1 + fabs(x))* log(1 + fabs(x));
	}
	return 0;
}

double step_len(double left, double right, int ammount) {
	return (fabs(left - right) / ammount);
}


void integrate() {
	double left, right, ammount;
	double sum_IPL = 0, sum_IPR = 0, sum_IPC = 0, sum_IT = 0, sum_IS = 0;
	int i = 0;

	cout << "\nEnter left border : ";
	cin >> left;

	cout << "\nEnter right border : ";
	cin >> right;

	cout << "\nEnter ammount of steps : ";
	cin >> ammount;

	double step = step_len(left, right, ammount);

	printf(" ( step = %f )\n\n", step);

	printf("  # | left  | right | centr | trape | Simps |\n");

	for (double x = left; x <= right; x += step)
	{
		i++;
		//left
		if(x != right)
			sum_IPL += IP(x)*step;

		//right
		if(x != left)
			sum_IPR += IP(x)*step;

		//central
		if (x != right)
			sum_IPC += IP(x+step/2)*step;
	
		//trapetions
		if(x != right)
			sum_IT += IT(x, step)*step;
	
		//Simpson
		if(i%2 == 0)
			sum_IS += IS(x, step)*step/3;


		printf(" %2d | %2.3f | %2.3f | %2.3f | %2.3f | %2.3f | (x = %+ .4f)\n",i, sum_IPL, sum_IPR, sum_IPC, sum_IT, sum_IS, x);
	}
	printf(" --------------------------------------------\n");
	printf("    | %2.3f | %2.3f | %2.3f | %2.3f | %2.3f |\n", sum_IPL, sum_IPR, sum_IPC, sum_IT, sum_IS);
}


double IP(double x) {
	return func(x);
}

double IT(double x, double step) {
	return (func(x) + func(x + step))/2;
}


double IS(double x, double step) {
	return func(x - step) + 4*func(x) + func(x + step);
}
