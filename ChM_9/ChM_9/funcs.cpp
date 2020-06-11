#include "funcs.h"
#include "solve.h"

void print_arr(double** arr) {
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf(" %02.3f ", arr[i][j]);
		}
		printf("\n");
	}
}

void print_arr(double* arr) {
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		printf(" %02.3f \n", arr[i]);
	}
}

double sq_sum(double* X, double* Y, int step) {
	double sum = 0;
	for (int i = 0; i < 6; i++)
	{
		sum += pow(X[i], step)*Y[i];
		//printf("\nstepin(%d) cur_Y = %f  sum = %f\n", step, pow(X[i], step), sum);
	}
	return sum;
}

double sq_sum(double* X, int step) {
	double sum = 0;
	for (int i = 0; i < 6; i++)
	{
		sum = sum + pow(X[i], step);
		//printf("\nstepin(%d) cur_X = %f  sum = %f\n", step, X[i], sum);
	}
	return sum;
}



double poly_linear(double* X, double* Y, int size) {
	int n = size + 1;
	//creates array
	double** M = new double* [n];
	for (int i = 0; i < n; i++) {
		M[i] = new double[n];
	}

	double* Y_M = new double [n];

	for (int i = 0; i < n; i++)
	{
		Y_M[i] = sq_sum(X, Y, i);
		int k = i;
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0) {
				M[i][j] = (n + 1);
			}else{
				M[i][j] = sq_sum(X, k);
			}
			k++;
		}
	}

	printf("\nA matrix of square sum of X-s\n");
	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < n; j++)
		{
			printf(" % .4f ", M[i][j]);
		}
	}

	printf("\n\n\nA matrix of square sum of Y-s\n");
	for (int i = 0; i < n; i++) {
		printf("\n % .4f ", Y_M[i]);
	}


	printf("\n\nLinear polynom fo size (%d) is called\n", size);
	go_forward(M,Y_M,3);
	printf("\nLinear polynom fo size (%d) is called\n", size - 1);
	go_forward(M, Y_M, 2);
	printf("\nLinear polynom fo size (%d) is called\n", size - 2);
	go_forward(M, Y_M, 1);
	return 0;
}

//double poly_square(double* X, double* Y) {
//	return 0;
//}

//double poly_qube(double* X, double* Y) {
//	return 0;
//}