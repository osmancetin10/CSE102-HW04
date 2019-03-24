/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include <stdio.h>
#include <math.h>


double integral(double f(double x), double xs, double xe, double delta){/*this function calculates integral with using basic integration method*/
	double temp=delta,integral=0;/*delta is accrual*/
	printf("Enter the ranges[xs,xe]:");
	scanf("%lf %lf",&xs,&xe);
	for(delta=xs+temp;delta<=xe;delta=delta+temp){
		integral=(temp*f(delta))+integral;
	}
	printf("\nIntegral of f(x) between [%lf,%lf] = %lf\n",xs,xe,integral);
	
	return 0;
} 

double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta){/*this function calculates double-deck integral with using basic integration method*/
	double integral=0,delta_x=delta,delta_y=delta;
	printf("Enter the ranges[xs,xe]:");
	scanf("%lf %lf",&xs,&xe);
	printf("Enter the ranges[ys,ye]:");
	scanf("%lf %lf",&ys,&ye);
	for(delta_x=xs+delta;delta_x<=xe;delta_x=delta_x+delta){
		for(delta_y=ys+delta;delta_y<=ye;delta_y=delta_y+delta){
			integral=(delta*delta*f(delta_x,delta_y))+integral;
		}
	}
	
	printf("\nIntegral of f(x) between [%lf,%lf] and [%lf,%lf] = %lf\n",xs,xe,ys,ye,integral);
	return 0;
}

int derivatives(double f(double a), double x, double eps, double * d1, double * d2){/*this function finds first and second derivatives of given function by using formulas given in homework pdf*/	
	double denominator1,denominator2;
	denominator1=eps*2;
	denominator2=eps*eps;
	*d1=(f(x+eps)-f(x-eps))/denominator1;/*this is the first derivative*/
	printf("\nfirst derivate when x is %lf = %lf\n",x,*d1);
	*d2=(f(x+eps)+f(x-eps)-2*f(x))/denominator2;/*this is the second derivative*/
	printf("\nsecond derivate when x is %lf = %lf\n",x,*d2);
	return 0;
} 



int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){/*this function compares users derivates and found derivatives. and than this function finds absolute difference*/ 
	double der1,der2;
	derivatives(f, x, eps, &der1, &der2);
	*e1=der1-d1(x);
	*e2=der2-d2(x);
	*e1=fabs(*e1)/*fabs function helps to find absolute value*/;
	*e2=fabs(*e2);
}	
		
int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4){/*this function finds roots of given function with trying every value between -10000 and +10000.*/
	*x1=10001; *x2=10001; *x3=10001; *x4=10001; 
	double delta;
	for(delta=-10000;delta<=10000;delta+=0.01){
		if(f(delta)>=-0.00001 && f(delta)<=0.00001){
			if(*x1==10001) *x1=delta;
			else if(*x2==10001) *x2=delta;
			else if(*x3==10001) *x3=delta;
			else if(*x4==10001) *x4=delta;

		}
	}
	if(*x1==10001) *x1=0;
	if(*x2==10001) *x2=0;
	if(*x3==10001) *x3=0;
	if(*x4==10001) *x4=0;
	
	printf("x1:%lf x2:%lf x3:%lf x4:%lf\n",*x1,*x2,*x3,*x4);
	return 0;
}
