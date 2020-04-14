#include<stdio.h>
#include<math.h>

// !!!!! ÇALIÞMASI ÝÇÝN BAÞLANGIÇ DEÐERLERÝNÝN DÜZGÜN VERÝLMESÝ LAZIM !!!!!


int main(){
	
	int i,derece;
	float a,b,c,c1,sonuc1=0,sonuc2=0,sonuc3=0,negatif,pozitif,epsilon,fark;
    float katsayilar[10];

    printf("Denklemin kacinci dereceden oldugunu giriniz:");
    scanf("%d",&derece);

    for(i=0;i<=derece;i++){
        printf("%d. dereceden elemanin katsayisini giriniz:",i);
        scanf("%f",&katsayilar[i]);
    }
	
	printf("Hassasiyeti (epsilonu) giriniz:");
	scanf("%f",&epsilon);
	
	printf("Koku icine alan a ve b degerlerini giriniz:(a<b olacak sekilde)\n");
	printf("a:");
	scanf("%f",&a);
	printf("b:");
	scanf("%f",&b);
		
	for(i=0;i<=derece;i++){
   		sonuc1=sonuc1 + katsayilar[i]*pow(a,i);
  	}	
	printf("x=%.3f icin f(x)=%.5f\n",a,sonuc1);
	
	for(i=0;i<=derece;i++){
   		sonuc2=sonuc2 + katsayilar[i]*pow(b,i);
  	}	
	printf("x=%.3f icin f(x)=%.5f\n",b,sonuc2);
		
	if(sonuc1*sonuc2>0){
        	printf("Yanlis aralik girdiniz. Tekrar deneyiniz!");
        	return 0;
    }
    
    fark=fabs(c-c1);
    
	while(sonuc1*sonuc2 < 0){
		c1=c;
		c=((b*sonuc1)-(a*sonuc2))/(sonuc1-sonuc2);
   	
		for(i=0;i<=derece;i++){
	   			sonuc3=sonuc3 + katsayilar[i]*pow(c,i);
	  	}
		printf("x=%.3f icin f(x)=%.5f\n",c,sonuc3);
		
		if(sonuc3==0){
			printf("KOK===>%f",c);
			return 0;
		}
		
		if(sonuc1<0){
			negatif=a;
			pozitif=b;
		}
		else if (sonuc2<0){
			negatif=b;
			pozitif=a;
		}
		
		if(sonuc3<0){
			negatif=c;
		}
		else if(sonuc3>0){
			pozitif=c;
		}
		
		fark=fabs(c-c1);

        if(fark<=epsilon){
        	printf("~KOK===> %f",c);
        	return 0;
		}
	}
	
	return 0;
}
