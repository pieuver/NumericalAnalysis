
#include "class_odeSolverLinear.hpp"

odeSolverLinear::odeSolverLinear(){
    alpha=0;
    src=NULL;
}


odeSolverLinear::odeSolverLinear(double t0, double x0, double T,double (*function)(double,double),double Alpha,double(*SRC)(double)):odeSolver(t0,x0,T,function){
    alpha=Alpha;
    src=SRC;
    
}




double * odeSolverLinear::solve_linear(size_t N)const{
    double *x= new double[N+1];
    double  h=(t_end-t_ini)/N;
    
    double x0 =i_sol;
    for(int k = 0; k<=N;k++){
        float tk = t_ini+h*k;
        
        double integral =0.0;
        for(int j = 1; j<=k;j++){
            
            double tj= t_ini+h*j;
            double dt = (tk-tj)/N;
            integral+=exp(tk-tj)*src(tj)*dt;
        }
        x[k] = x[0]*exp(alpha*tk)+integral;
    }
    return x;
}
