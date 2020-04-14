#include<stdio.h>
#define f(x) 3*x*x*x + 2*x*x + 5
//#define f(x) 1/(1+x*x)
//#define f(x) (10*x*x + 5)/(10*x*x*x)
int main(){
	
	int i;
	float n,islem=0,h,result,a,b,t;
	
	printf("\t\t#### SAYISAL INTEGRAL TRAPEZ YONTEMI ####\n");
	printf("Alt siniri giriniz:");
	scanf("%f",&a);
	printf("Ust siniri giriniz:");
	scanf("%f",&b);
	
	printf("Aralik sayisini (n) giriniz:");
	scanf("%f",&n);
	
	h = (b-a)/n; //genislik
	printf("h===> %.2f\n",h);

	
	
	for(i=1;i<=n-1;i++){ // 3 tane aralýk için 2 iþlem yapýlýyor o yüzzden n-1 dahil 
		t=a+i*h;
		islem+=f(t);
	}
	
	result = h*(f(a)+f(b))/2;
	result+= h*islem;
	printf("Sonuc===> %f\n",result);
	
	
	
	return 0;
}
