#include<stdio.h>
#include<math.h>

//#define f(x) x*x*x - 4*x*x - 4*x +15
//#define g(x) 3*x*x - 8*x - 4

//#define f(x) x*x - 4*x - 7
//#define g(x) 2*x - 4

//#define f(x) exp(-x) - x
//#define g(x) -(exp(-x)) -1

int main(){
	
	float x0,x1,epsilon,f0,g0,f1;
	
	printf("x(x0):");
	scanf("%f",&x0);
	printf("Hassasiyet (epsilon) degerini giriniz:");
	scanf("%f",&epsilon);
	
	do{
		g0 = g(x0);
		f0 = f(x0);
		if(g0 == 0.0)
		{
			printf("HATA!!!!");
			return 0;
		}
	
		x1 = x0 - (f0/g0);
		x0 = x1;
		f1 = f(x1);
	
	 }while(fabs(f1)>epsilon);
	 
	printf("~KOK ====>: %f", x1);

	
	return 0;
}
