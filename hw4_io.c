/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"
#include <stdio.h>

int read_polynomial3(double * a0, double * a1, double * a2, double * a3){/*this function gets coefficents from the user for degree3 polynomial*/
	printf("p(x) = a3x^3 + a2x^2 + a1x + a0\n");
	printf("Enter a3, a2, a1, a0:");
	scanf("%lf %lf %lf %lf",&*a3,&*a2,&*a1,&*a0);
	return 0;
}

int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4){/*this function gets coefficents from the user for degree4 polynomial*/
	printf("p(x) = a4x^4 + a3x^3 + a2x^2 + a1x + a0\n");
	printf("Enter a4, a3, a2, a1, a0:");
	scanf("%lf %lf %lf %lf %lf",&*a4,&*a3,&*a2,&*a1,&*a0);
	return 0;
}

void write_polynomial3(double a0, double a1, double a2, double a3){/*this function writes degree3 polynomial which we know coefficents*/ 
	int i;
	double a[4]={a0,a1,a2,a3};
	printf("P(x)=");	
	if(a1==0 && a2==0 && a3==0 && a0==0) printf("0\n");/*if all coefficents equal zero program writes just '0'*/
	else{
		for(i=3;i>-1;i--){
			if(i>=2){/*this comparing works only a3 and a2 coefficents*/
				if(a[i]>0){/*if coefficent is bigger than zero*/ 
					if(a[i]==1) printf("+x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("+%dx^%d",(int)a[i],i);		
						else printf("+%.1lfx^%d",a[i],i);
					}
				}
				if(a[i]<0){ /*if coefficent is less than 0*/
					if(a[i]==-1) printf("-x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("%dx^%d",(int)a[i],i);
						else printf("%.1lfx^%d",a[i],i);
					}
				}
			}
			else if(i==1){/*this is for a1*/
				if(a[i]>0){ /*if a1 bigger than 0*/
					if(a[i]==1) printf("+x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("+%dx",(int)a[i]);
						else printf("+%.1lfx",a[i]);
					}
				}
				if(a[i]<0){/*if a1 less than zero*/ 
					if(a[i]==-1) printf("-x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("%dx",(int)a[i]);
						else printf("%.1lfx",a[i]);
					}
				}
			}
			else if(i==0){/*this is for a0*/
				if(a[i]>0){ 
					if(a[i]==1) printf("+x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("+%d",(int)a[i]);
						else printf("+%.1lf",a[i]);
					}
				}
				if(a[i]<0){ 
					if(a[i]==-1) printf("-x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("%d",(int)a[i]);
						else printf("%.1lf",a[i]);
					}
				}
			}	
		}
	}
	printf("\n");		
}

void write_polynomial4(double a0, double a1, double a2, double a3, double a4){/*this function writes degree4 polynomial which we know coefficents*/ 
int i;
	double a[5]={a0,a1,a2,a3,a4};
	printf("P(x)=");	
	if(a1==0 && a2==0 && a3==0 && a0==0 && a4==0) printf("0\n");/*if all coeffcents equals zero, program writes only zero*/ 
	else{
		for(i=4;i>-1;i--){
			if(i>=2){/*this is works only a4,a3,a2 coefficents*/
				if(a[i]>0){ 
					if(a[i]==1) printf("+x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("+%dx^%d",(int)a[i],i);		
						else printf("+%.1lfx^%d",a[i],i);
					}
				}
				if(a[i]<0){ 
					if(a[i]==-1) printf("-x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("%dx^%d",(int)a[i],i);
						else printf("%.1lfx^%d",a[i],i);
					}
				}
			}
			else if(i==1){/*this is works for a1*/
				if(a[i]>0){ 
					if(a[i]==1) printf("+x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("+%dx",(int)a[i]);
						else printf("+%.1lfx",a[i]);
					}
				}
				if(a[i]<0){ 
					if(a[i]==-1) printf("-x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("%dx",(int)a[i]);
						else printf("%.1lfx",a[i]);
					}
				}
			}
			else if(i==0){/*this is working for a0*/
				if(a[i]>0){ 
					if(a[i]==1) printf("+x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("+%d",(int)a[i]);
						else printf("+%.1lf",a[i]);
					}
				}
				if(a[i]<0){ 
					if(a[i]==-1) printf("-x^%d",i);
					else{
						if(a[i]==(int)a[i]) printf("%d",(int)a[i]);
						else printf("%.1lf",a[i]);
					}
				}
			}	
		}
	}	
	printf("\n");		
}
