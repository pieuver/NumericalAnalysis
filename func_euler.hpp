
#ifndef func_euler_hpp
#define func_euler_hpp

#include <stdio.h>
#include <cmath>
//Exercise 1, the Euler function

double * euler_function(double t_ini, double i_sol, double t_end, double (*sfn)(double t,double x), size_t N);
#endif /* func_euler_hpp */

