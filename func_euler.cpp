
#include "func_euler.hpp"


double * euler_function(double t_ini, double i_sol, double t_end, double (*sfn)(double t,double x), size_t N){
    // We don't want to have issues with indexing
    // So we create N+1 values to respect :
    // result[k] = x_k for each k
    double * result = new double[N+1];
    double h = (t_end-t_ini)/N;
    
    result[0] = i_sol;
    for(int k = 0; k<N;k++){
        double tk = t_ini+h*k;
        result[k+1]=result[k]+h*sfn(tk,result[k]);
    }
    return result;
}


