#include<stdio.h>
#include<math.h>

int main(){
	
	int n,i,j;
	float x[20],y[20],p,ist_deg,sonuc=0;	
	printf("Kullanilacak x(xi) sayisini giriniz:"); // Kaç tane bilgi verildiðini kullanicidan istedik
	scanf("%d",&n);
	
	printf("NOT: Verilecek degerleri 1/2.75 yerine 0.3636 gibi giriniz!\n");
	// Soruda verilen bilgileri aldýk.
	for(i=0;i<n;i++){
		printf("x[%d]=",i);
		scanf("%f",&x[i]);
		printf("y[%d]=",i);
		scanf("%f",&y[i]);
	}
	
	// istenilen degeri ilk basta aldik
	printf("Fonksiyonda bulmak istediginiz degeri giriniz:");
	scanf("%f",&ist_deg);
	
	// burada islemleri yaptýk
	for(i=0;i<n;i++)
	 {
		  p=1;  // 1 ile carpim sonucu degistirmeyecigi icin ve rastgele bir deger gelmemesi için atama yaptýk
		  for(j=0;j<n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (ist_deg - x[j])/(x[i] - x[j]);
			   }
		  }
		  sonuc = sonuc + p * y[i]; // her adimda yapýlan islemi sonuca ekledik. tanimlerken sonuc=0 demistik!
	 }
	 
	printf("x= %.4f ==> y= %.4f.", ist_deg,sonuc);

	
	return 0;
}
