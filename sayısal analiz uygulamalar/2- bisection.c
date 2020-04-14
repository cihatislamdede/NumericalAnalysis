#include<stdio.h>
#include <stdlib.h>
#include<math.h>

// !!!!! ÇALIÞMASI ÝÇÝN BAÞLANGIÇ DEÐERLERÝNÝN DÜZGÜN VERÝLMESÝ LAZIM !!!!!

int main(){
	
	int i,derece;
	float a,b,c,epsilon,sonuc1=0,sonuc2=0,sonuc3=0,fark;
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
    
   	c=(a+b)/2;
   	
	for(i=0;i<=derece;i++){
   			sonuc3=sonuc3 + katsayilar[i]*pow(c,i);
  	}
	printf("x=%.3f icin f(x)=%.5f\n",c,sonuc3);
	
	fark=sonuc2 - sonuc1;
	
	if(fark<0){
		fark=fark*-1;
	}
	
	while(fark>= epsilon){
		
        if(sonuc3==0){
            printf("KOK===> %f\n",c);
            break;
        }
        else if(sonuc3*sonuc1<0){
            b=c;
        }
        else if(sonuc3*sonuc2<0){
            a=c;
        }
        
        c=(a+b)/2;
        sonuc1=0,sonuc2=0,sonuc3=0;
        for(i=0;i<=derece;i++){
	   		sonuc1=sonuc1 + katsayilar[i]*pow(a,i);
	  	}	
		printf("x=%.5f icin f(x)=%f\n",a,sonuc1);
		
		for(i=0;i<=derece;i++){
	   		sonuc2=sonuc2 + katsayilar[i]*pow(b,i);
	  	}	
		printf("x=%.5f icin f(x)=%f\n",b,sonuc2);
      
		for(i=0;i<=derece;i++){
   			sonuc3=sonuc3 + katsayilar[i]*pow(c,i);
  		}
		printf("x=%.5f icin f(x)=%f\n",c,sonuc3);
        fark = sonuc2 - sonuc1;
        if(fark<0){
			fark=fark*-1;
		}
	}
	
	return 0;
}
