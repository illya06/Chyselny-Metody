#include "funcs.h"

using namespace std;


//
//X : 0.62 0.69 0.8 1.01 1.1  1.15
//Y : 2.80 2.94 3.2 3.38 3.53 3.75
//
int main()
{
	double X[6] = { 0.62, 0.69, 0.8, 1.01, 1.1,  1.15 };
	double Y[6] = { 2.80, 2.94, 3.2, 3.38, 3.53, 3.75 };

	poly_linear(X, Y, 3);
}