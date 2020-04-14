#include<stdio.h>
#include<math.h>

#define f(x) x*x*x - 20*x + 16
//#define f(x) cos(x) + 2*sin(x) + x*x
//#define f(x) exp(-x)*cos(x)
int main(){
	
	float x0,x1,x2,epsilon,f0,g0,f1,f2;
	
	printf("x(x0):");
	scanf("%f",&x0);
	printf("x(x1):");
	scanf("%f",&x1);
	
	printf("Hassaslik (epsilon) degerini giriniz:");
	scanf("%f",&epsilon);
	
	
	do{
		f0 = f(x0);
		f1 = f(x1);
		x2 = x1 - (x1 - x0) * f1/(f1-f0);  //siradaki x deðerini buluyoruz 
		f2 = f(x2);
		
		x0 = x1;
		f0 = f1;
		x1 = x2;
		f1 = f2;  
		 
	 }while(fabs(f2)>epsilon);  
	
	 printf("\nKOK ====> %f", x2);	
	
	return 0;
}
