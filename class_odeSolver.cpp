
#include "class_odeSolver.hpp"

odeSolver::odeSolver(){
    t_ini=0.0;
    t_end = 0.0;
    t_end = 0.0;
    sfn = NULL;
}
odeSolver::odeSolver(double t0, double x0, double T,double (*function)(double,double)){
    t_ini = t0;
    i_sol = x0;
    t_end = T;
    sfn = function;
}

double* odeSolver::solve_with_euler(size_t N) const{
    return euler_function(t_ini, i_sol, t_end, sfn, N);
}

double * odeSolver::solve_with_rk2(size_t N)const{
    double h = (t_end -t_ini)/N;
    double x0 = i_sol;
    
    double *s = new double[N+1];
    s[0] = x0;
    for(int k = 0; k < N;k++){
        double tk = h*k;
        double tk_plus = h*(k+1);
        double F1  =sfn(tk,s[k]);
        double F2 = sfn(tk_plus,s[k]+h*F1);
        s[k+1]=s[k]+h*(F1+F2)/2.0;
    }
    return s;
}
