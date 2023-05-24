
#ifndef class_odeSolver_Ex4_hpp
#define class_odeSolver_Ex4_hpp

#include <stdio.h>
template <typename T>
class odeSolverTemplate{
protected:
    double t_ini; // initial time
    double i_sol; // initial solution
    double t_end; // end time
    T sfn;
public:
    odeSolver(double t0, double x0, double T,double, T SFN);
    double *solve_with_euler(size_t N) const;
    double *solve_with_rk2(size_t N)const;
    
    odeSolver();
};

#endif /* class_odeSolver_Ex4_hpp */
