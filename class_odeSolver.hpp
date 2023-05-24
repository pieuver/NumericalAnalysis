
#ifndef class_odeSolver_hpp
#define class_odeSolver_hpp

#include <stdio.h>
#include "func_euler.hpp"

class odeSolver{
protected:
    double t_ini; // initial time
    double i_sol; // initial solution
    double t_end; // end time
    double (*sfn)(double t, double x); //source function
public:
    odeSolver(double t0, double x0, double T,double (*function)(double,double));
    double *solve_with_euler(size_t N) const;
    double *solve_with_rk2(size_t N)const;
    odeSolver();
};
#endif /* class_odeSolver_hpp */
