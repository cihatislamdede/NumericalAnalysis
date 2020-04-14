#include<stdio.h>
#define f(x) ((x*x)-1)*(x+2)
//#define f(x) (10*x*x + 5)/(10*x*x*x)

int main(){
	
	printf("\t\t#### SIMPSON YONTEMI ####\n");
	
	int i;
	float n,islem=0,islem1=0,islem2=0,h,result,a,b,T;
	
	printf("Alt siniri giriniz:");
	scanf("%f",&a);
	printf("Ust siniri giriniz:");
	scanf("%f",&b);
	
	printf("Aralik sayisini (n) giriniz:");
	scanf("%f",&n);
	
	h = (b-a)/n;
	printf("h===> %.2f\n",h);
	
	islem = f(a)+f(b);
	// Formülde kullanmak için öncesinde yapýyoruz
	for(i=1;i<n;i=i+2){
		T=a+i*h;
		islem1+=f(T);
	}
	
	for(i=2;i<n;i=i+2){
		T=a+i*h;
		islem2+=f(T);
	}
	
	result = (h/3)*(islem+4*islem1+2*islem2);
	printf("Sonuc===> %f\n",result);
	
	
	
	
	return 0;
}
