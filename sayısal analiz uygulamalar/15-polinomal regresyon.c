#include<stdio.h>
// F(x) = Ax^2+Bx+C
// 3 BÝLÝNMEYENLÝ DENKLEM ÝÇÝN 
float fonk_hesap(float A,float B,float C,float deger){
	return (A*deger*deger)+(B*deger)+C;
}

int main(){
	
	int n,i,secim;
	float x[20],y[20];
	static float xi,yi,xi2,xi3,xi4,xiyi,xi2yi,A,B,C,delta,deger;
		
	printf("Verilen olcum degeri sayisini giriniz:");
	scanf("%d",&n);	
	
	printf("Verilen bilgileri giriniz:\n");
	for(i=0;i<n;i++){
		printf("x[%d]=",i);
		scanf("%f", &x[i]);
		printf("y[%d]=",i);
		scanf("%f", &y[i]);
	}
	
	for(i=0;i<n;i++){
		xi+=x[i];
		yi+=y[i];
		xiyi+=x[i]*y[i];
		xi2+=x[i]*x[i];
		xi3+=x[i]*x[i]*x[i];
		xi4+=x[i]*x[i]*x[i]*x[i];
		xi2yi+=x[i]*x[i]*y[i];		
	}
	
	delta = (n*((xi2*xi4)-(xi3*xi3)))-(xi*((xi*xi4)-(xi2*xi3)))+(xi2*((xi*xi3)-(xi2*xi2)));
		
	printf("\txi=%.3f\tyi=%.3f\txy=%.3f\txi^2=%.3f\txi^3=%.3f\txi^4=%.3f\txi^2yi=%.3f\tdelta=%.2f\n",xi,yi,xiyi,xi2,xi3,xi4,xi2yi,delta);
	
	
	A = ((n*((xi2*xi2yi)-(xiyi*xi3)))-(xi*((xi*xi2yi)-(xi2*xiyi)))+(yi*((xi*xi3)-(xi2*xi2))))/delta;
	B = ((n*((xiyi*xi4)-(xi2yi*xi3)))-(yi*((xi*xi4)-(xi2*xi3)))+(xi2*((xi*xi2yi)-(xiyi*xi2))))/delta;
	C = ((yi*((xi2*xi4)-(xi3*xi3)))-(xi*((xiyi*xi4)-(xi2yi*xi3)))+(xi2*((xiyi*xi3)-(xi2yi*xi2))))/delta;
	
	printf("A=%.3f\tB=%.3f\tC=%.3f\n",A,B,C);
	
	printf("F(x)=%.2fx^2+%.3fx+%.3f\n",A,B,C);
	
	printf("Girdiginiz x degeri icin sonu hesaplamak ister misiniz?\n 1)ISTERIM\t2)CIKIS\n");
	scanf("%d",&secim);
	if(secim==1){
		printf("Sayiyi giriniz:");
		scanf("%f",&deger);
	}
	else{
		return 0;
	}
		
	printf("\nx=%f icin F(x)=%.3f",deger,fonk_hesap(A,B,C,deger));
	
	
	return 0;
}



