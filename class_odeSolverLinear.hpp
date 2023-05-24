

#ifndef class_odeSolverLinear_hpp
#define class_odeSolverLinear_hpp

#include <stdio.h>
#include "class_odeSolver.hpp"

class odeSolverLinear:odeSolver{
private:
    double alpha;
    double (*src)(double);
    float integral(double a, double b, double (*function)(double),double factor,size_t N =100)const;
public:
    // Default constructor
    odeSolverLinear();
    
    
    odeSolverLinear(double t0, double x0, double T,double (*function)(double,double),double Alpha,double(*SRC)(double));

    double *solve_linear(size_t N)const;
};

#endif /* class_odeSolverLinear_hpp */
