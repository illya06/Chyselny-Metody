#include "solve.h"
#include <cstdio>

void print_(double** arr) {
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

void print_(double* arr) {
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		printf(" %02.3f \n", arr[i]);
	}
}

void go_forward(double** X, double* Y, int size) {
	double sub = 0;
	double koef = 0;

	for (int i = 0; i < size + 1; i++)
	{
		koef = X[i][i];
		Y[i] = Y[i] / koef;
		for (int j = 0; j < size + 1; j++)
		{
				X[i][j] = X[i][j] / koef;
				
		}
		for (int k = i+1; k < size+1; k++)
		{
			sub = X[k][i];
			for (int f = i; f < size + 1; f++)
			{
				X[k][f] = X[k][f] - X[i][f] * sub;
			}
			Y[k] = Y[k] - sub * Y[i];
		}
	}

	print_(X);
	print_(Y);

	go_backwards(X, Y, size);
};

void go_backwards(double** X, double* Y, int size) {
	double sum = 0;
	double* A = new double[size+1];
	for (int i = 0; i < size + 1; i++) {
		A[i] = 0;
	}

	A[size] = Y[size] / X[size][size];
	for (int i = size-1; i > -1; i--)
	{
		for (int j = size; j > -1; j--)
		{
			sum += A[j] * X[i][j];
		}
		A[i] = Y[i] / sum;
	}
	print_(A);
};