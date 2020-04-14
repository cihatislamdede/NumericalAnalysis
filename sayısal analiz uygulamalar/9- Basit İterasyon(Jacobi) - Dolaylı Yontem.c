#include <stdio.h>
#include <math.h>

#define DENEME 1000

int main() {
	int i,j,k,n,u,temp,p,c,d;
	int carpim=1,escarpim=1;
	int a[10][10],b[10][10];
	float eps;
	static float anlik[10];
	static float esanlik[10];
	
	printf("Epsilon degerini gir:");
	scanf("%f",&eps);
	printf("Satir (ya da sutun) sayisi:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("A[%d][%d]= ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<n;i++) {
		printf("C[%d]= ",i);
		scanf("%d",&a[i][n]);
	}
	
	for(k=0;k<n;k++) {   // burada diyagonaldeki sayilarin mutlak deðerinin max. çarpýmýný tek tek deneyerek buluyoruz (n!)
		for(i=n-1;i>0;i--) {
			carpim=1;
			for(j=0;j<n+1;j++) {
				temp = a[i][j];
				a[i][j] = a[i-1][j];
				a[i-1][j] = temp;
			}
			for(c=0;c<n;c++) {
				carpim = fabs(a[c][c])*carpim;
			}
			if(carpim>escarpim) { // escarpim=1 olarak tanimlamistik
				escarpim=carpim;
				for(u=0;u<n;u++) {
					for(p=0;p<n+1;p++) {
						b[u][p]=a[u][p]; // ilk girilen matrisi yeni matrise aktariyoruz
					}
				}
			}
		}
	}
	
	printf("Diyagonel carpiminin max. olmus hali:\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n+1;j++) {
			printf("%d\t",b[i][j]);  // b[] yeni matris
		}
		printf("\n");
	}
	
	for(u=0;u<DENEME;u++) { // DENEME hassasiyete göre deðiþtirilebilir. Fonksiyon sonucunda çýktý vermezse DENEME arttýrýlýr
		for(i=0;i<n;i++) {
			for(j=n-1;j>=0;j--) {
				if(i!=j) {
					anlik[i]=anlik[i]-esanlik[j]*b[i][j];  //anlik ve esanlik arrayinin tüm elemanlarý baslangýcta 0 - anlik baþta verdiðimiz deðer. esanlik onceki deðeri tutmak için
				}
			}
			anlik[i]=(anlik[i]+b[i][n])/b[i][i];
		}
		for(d=0;d<n;d++) {
			if(fabs(esanlik[d]-anlik[d])<=eps) {  
				for(p=0;p<n;p++) {
					printf("x[%d]=%.2f\n",p,anlik[p]);
				}
				printf("\n%d. adim sonucunda bulunmustur.",u);
				return 0;
			}
		}
		
		for(k=0;k<n;k++) {     // adim sonucunda epsilondan küçük olmuyorsa sonraki adýma önceki deðerler aktarýlýr ve ilk deðer yine 0lanýr
			esanlik[k]=anlik[k];
			anlik[k]=0;
		}
	}
	return 0;
}
