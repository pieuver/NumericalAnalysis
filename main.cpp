
#include <iostream>
#include "func_euler.hpp"
#include <math.h>
#include "class_odeSolver.hpp"
#include "class_odeSolverLinear.hpp"
using namespace std;

double f(double t,double x){
    return (1-exp(t))*x/(1+exp(t));
    }

double x(double t){
    return 12*exp(t)/pow((1+exp(t)),2);
}

double numerical_error(double (*x)(double), double *s, size_t N,double t0,double T){
    double result = 0.0;
    double h = (T-t0)/(float)N;
    for(int k = 1; k <= N;k++){
        double tk= t0+h*k;
        result+=abs(x(tk)-s[k]);
    }
    return result;
}
double g(double t){
    return cos(sqrt(t));
}

int main(int argc, const char * argv[]) {
    
    /*
     Exercise 1 : the procedural mode
     */
    size_t N = 100;
    double T = 2;
    double x0 = 3;
    double t0=0.0;
    double *s = euler_function(t0, x0, T, &f, N);
    double error = numerical_error(&x, s, N, t0, T);
    cout<<"Numerical Error = "<<error<<endl;
    delete [] s;
    /*
     Exercise 2
     */
    s = new double [N];
    odeSolver solver(t0, x0, T, &f);
    s = solver.solve_with_euler(N);
    error = numerical_error(&x, s, N, t0, T);
    cout<<"Numerical Error = "<<error<<endl;
    
    for(N = 1; N < 100;N+=2){
        /*
         We can see to a certain point that when h is halved,
         the error is reduced by a factor of 2
         
         */
        s = solver.solve_with_euler(N);
        double *s2 = solver.solve_with_rk2(N);
        error = numerical_error(&x, s, N, t0, T);
        double error_rk2 = numerical_error(&x, s2, N, t0, T);

        cout<<"Numerical Error (Euler loop) = "<<error<<endl;
        cout<<"Numerical Error (RK2 loop) = "<<error_rk2<<endl;

        delete []s;
    }
    /*
     We conclude that the Runge-Kutta 2 Method has a much faster error factor decrease compared to Euler
     */
    
    //Exercise 3
    double alpha = 2.0;
    odeSolverLinear solver_linear(t0, x0, T, &f, alpha, &g);
    double *sol_linear = solver_linear.solve_linear(N);
    
    
    for(int k = 0; k<=N;k++){
        cout<<"x["<<k<<"] = "<<sol_linear[k]<<endl;
    }
    delete[] sol_linear;
    
    //Exercise 4 possible validation
    /*
     odeSolverTemplate<double *> solver
     double *solver = solver.solve_with_rk2(N);

     */
     
     
    return 0;
}
