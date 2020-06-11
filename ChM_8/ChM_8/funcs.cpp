#include "funcs.h"
int factorial(int x) {
	int factorial = 1;
	for (int i = 1; i <= x; ++i)
	{
		factorial *= i;
	}
	return factorial;
}



double LangrangeSum(double* X, double* Y, double x) {
	
	cout << "\n\nSTART OF LAGRANGE METHOD!\n\n";

	double P_n_add_1 = 1;

	for (int i = 0; i < 10; i++)
	{
		P_n_add_1 *= (x - X[i]);
	}
	double temp = 1;
	double divider_sum = 0;
	printf("|    \t\t\t\t\t\t___P n+1 (x)___\t\t\t\t\t   || D(i) || Y(i)  |");
	printf("\n---------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < 10; i++)
	{
		temp = 1;
		for (int j = 0; j < 10; j++)
		{
			if (i == j) {
				temp = temp * (x - X[i]);
				printf("| %+1.3f |", x - X[i]);
			}
			else {
				temp = temp * (X[i] - X[j]);
				printf("| %+1.3f |", X[i] - X[j]);
			}
			
		}
		printf("| D(%d) || %1.3f |\n", i, Y[i]);
		
		divider_sum += Y[i]/(temp);
	}

	return P_n_add_1*divider_sum;
}

double delF(double* Y, int level, int searched_x_pos, int print) {
	int n = level;
	double sum = Y[searched_x_pos + 1] - Y[searched_x_pos];
	for (int i = 0; i < 10 - searched_x_pos; i++)
	{
		sum += pow(-1, i) * factorial(n) * (Y[searched_x_pos + i]) / (factorial(n - i) * factorial(i));
	}
	if(print == 1)printf("|%+2.3f |", sum);
	return sum;
}

double NeutonSum(double* X, double* Y, double x) {

	cout << "\n\nSTART OF NEUTONS METHOD!\n";

	double h = fabs(X[0] - X[1]);
	double q = (x - X[0]) / h;
	double solution = Y[0];
	
	printf("\n| # || x_at_i || y_at_i || d1x_i || d2x_i || d3x_i || d4x_i || d5x_i || d6x_i || d7x_i || d8x_i  || d9x_i  |");
	printf("\n------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < 10; i++)
	{
		printf("| %d || %2.4f || %2.4f |", i, X[i], Y[i]);
		for (int j = 0; j < 10 - i - 1; j++)
		{
			delF(Y, j, i, 1);
		}
		printf("\n");
	}
	printf("------------------------------------------------------------------------------------------------------------\n");
	
	printf("\nsolution = ");
	printf("%2.3f ", solution);

	for (int i = 1; i < 10; i++)
	{
		double multipl = 1;
		for (int j = 1; j < i; j++) {
			multipl *= (q + j);
		}
		solution += multipl * delF(Y, i, 0, 0) /factorial(i);
		printf("+ (%2.3f)*(%2.3f)/(%d) ", multipl, delF(Y, i, 0, 0), factorial(i));
	}
	printf("= ", solution);
	
	return solution;
}

