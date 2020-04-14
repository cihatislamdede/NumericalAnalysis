#include<stdio.h>
#include<math.h>
int main(){
	printf("\t\t### GRAFIK YONTEMIYLE KOK BULMA ###\n");

    int i,j,derece,exit=0;
    float x0,hassasiyet,deltaX,islem_sonuc=1,sonuc1,sonuc2;
    float katsayilar[50];

    printf("Denklemin kacinci dereceden oldugunu giriniz:"); //denklemi elle almak için
    scanf("%d",&derece);
	
    for(i=0;i<=derece;i++){
        printf("%d. dereceden elemanin katsayisini giriniz:",i);
        scanf("%f",&katsayilar[i]);
    }
    
    printf("Baslangic x degerini(x0) giriniz:");
    scanf("%f",&x0);
    printf("Hassasiyeti(epsilonu) giriniz:"); // durma hassasiyeti
    scanf("%f",&hassasiyet);
    printf("Degisim miktarini (deltaX) giriniz:"); // x'in artýþ miktarýný burada aldýk
    scanf("%f",&deltaX);
    
    // girilen x0 icin fonksiyonun sonucunu alýyoruz
    for(i=derece;i>=0;i--){
		for(j=i;j>0;j--){
			islem_sonuc=islem_sonuc*x0;
		}
		sonuc1=sonuc1 + islem_sonuc*katsayilar[i];
		islem_sonuc=1;
	}		
	
	printf("x=%f icin f(x)=%f\n",x0,sonuc1);
    x0=x0+deltaX;
	sonuc2=sonuc1;
	sonuc1=0;
	
	while(exit== 0 && deltaX>=hassasiyet){
		
		for(i=derece;i>=0;i--){
		    for(j=i;j>0;j--){
		    	islem_sonuc=islem_sonuc*x0;
		    }
		    sonuc1=sonuc1 + islem_sonuc*katsayilar[i];
		    islem_sonuc=1;
		}
		printf("x=%f icin f(x)=%.10f\n",x0,sonuc1);
		
		if(sonuc2*sonuc1 <0) {
			x0=x0-deltaX;
			deltaX=deltaX/2;
			sonuc1=0;
		}
		else if(sonuc1==0){
			exit=1;
		}	
		else {
			x0=x0+deltaX;
			sonuc2=sonuc1;
			sonuc1=0;
		}			
	}
		
	printf("Koku %f ve %f arasindadir.",x0,x0+deltaX);
	return 0;
}
