#include<stdio.h>

// F(x) = Ax+B

// girilen x deðeri için f(x) in deðerini hesaplamak için fonksiyon
float fonk_hesap(float A,float B,float deger){
		return A*deger + B;
}

int main(){
	int i,n,secim;
	float x[20],y[20],A,B,deger;
	static float xi,xi2,yi,xy,delta;
	
	printf("Verilen olcum degeri sayisini giriniz:");
	scanf("%d",&n);	
	
	// verilen tabloyu giriyoruz
	for(i=0;i<n;i++){
		printf("x[%d]=",i);
		scanf("%f", &x[i]);
		printf("y[%d]=",i);
		scanf("%f", &y[i]);
	}
	//formulde kullanacaðýmýz deðerleri hesaplýyoruz
	for(i=0;i<n;i++){
		xi+=x[i];
		yi+=y[i];
		xy+=x[i]*y[i];
		xi2+=x[i]*x[i];
	}
	
	delta = (n*xi2)-(xi*xi);
	
	printf("\txi=%.3f\tyi=%.3f\txy=%.3f\txi^2=%.3f\tdelta=%.2f\n",xi,yi,xy,xi2,delta);
	
	A =(float)((n*xy)-(yi*xi))/(float)delta;
	B=(float)((yi*xi2)-(xy*xi))/(float)delta;

	
	
	printf("F(x)=%.2fx+%.3f\n",A,B);
	
	printf("Girdiginiz x degeri icin sonu hesaplamak ister misiniz?\n 1)ISTERIM\t2)CIKIS\n");
	scanf("%d",&secim);
	if(secim==1){
		printf("Sayiyi giriniz:");
		scanf("%f",&deger);
	}
	else{
		return 0;
	}
		
	printf("\nx=%f icin F(x)=%f",deger,fonk_hesap(A,B,deger));
	
	
	
	
}
