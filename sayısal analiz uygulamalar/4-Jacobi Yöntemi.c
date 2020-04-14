#include<stdio.h>
#include<math.h>

int main(){	

	double x0,epsilon,dif,gx,hx,a;
	
	printf("f(x)=x^2-2x-3\t\tg(x)=x\t\th(x)=(2x+3)^1/2\n");  // fonksiyonun -x li hali => f(x)   g(x)=x      h(x) => f(x)in x yalnýz kalmýþ hali
	printf("g'(x)=1\t\th'(x)=1/sqrt(2x+3)\n"); // g(x) ve h(x) in türevleri 
	printf("NOT: x=%lf icin g'(x) > h'(x) olmali \n",x0);
		
	printf("x(x0):");
	scanf("%lf",&x0);
	
	printf("Hassasiyet (epsilon) degerini giriniz:");
	scanf("%lf",&epsilon);
	
	gx=x0;
	hx=sqrt(2*x0+3);
	
	printf("g(%lf)=%lf\th(%lf)=%lf\t\t",x0,gx,x0,hx);
	
	dif=fabs(gx-hx);
	printf("|y1-y0| = %lf\n",dif);
	
	
	if(dif<=epsilon){
		printf("KOK ===> %lf",hx);
	}
	
	while(dif>epsilon){
		
		x0=hx;
		gx=x0;
		hx=sqrt(2*x0+3);
		
		printf("g(%lf)=%lf\th(%lf)=%lf\t\t|y1-y0| = %lf\n",x0,gx,x0,hx,dif);
		
		dif=fabs(gx-hx);
		if(dif<=epsilon){
			printf("KOK ===> %lf",hx);
			return 0;
		}
			
	}
		
	return 0;
}
