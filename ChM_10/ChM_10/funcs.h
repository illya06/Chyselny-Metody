#pragma once
#include <math.h>
#include <iostream>

using namespace std;

//function of ln^2(1+|x|)
double func(double);

//returns step's length
double step_len(double, double, int);

//integrating cycle
void integrate();

//integral of left or right or central pryamokytnyks
double IP(double);

//integral of trapetions
double IT(double, double);

//integral of Simpson
double IS(double, double);

