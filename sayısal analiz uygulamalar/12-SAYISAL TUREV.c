#include<stdio.h>
#include<math.h>
#define f(x) log(x)
// #define f(x) exp(x)

int main(){
	printf("\t\t#### SAYISAL TUREV ####\n");
	
	float sonuc,h,x,t,t1;

	printf("Turev alinacak noktayi(x) giriniz:");
	scanf("%f",&x);
	
	printf("iki x degeri arasindaki farki (h) giriniz:");
	scanf("%f",&h);
	
	// Geri Farklar Ýle Türev
	t=x-h;
	sonuc = (f(x)-(f(t)))/h;
	printf("Geri Farklar ile turevin sonucu:%f\n",sonuc);
	
	// Ýleri Farklar Ýle Türev	
	
	t=x+h;
	sonuc = (f(t)-(f(x)))/h;
	printf("Ileri Farklar ile turevin sonucu:%f\n",sonuc);
	
	// Merkezi Farklar Ýle Türev	
	
	t= x+h;
	t1 = x-h;
	sonuc = (f(t)-(f(t1)))/(2*h);
	printf("Merkezi Farklar ile turevin sonucu:%f\n",sonuc);
	
	
	
	
	return 0;
}
