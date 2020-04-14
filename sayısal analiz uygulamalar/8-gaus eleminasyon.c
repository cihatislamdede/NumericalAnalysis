#include <stdio.h>
int main() {
	int i,j,u,n,p;
	float k,cikar;
	static float cozum[10];
	float matris[10][10];
	printf("Kare matrisin satir sayisini giriniz(sutun sayisi):");
	scanf("%d",&n);
	
	for(i=0;i<n;i++) { // denklemlerin katsayilarini aliyoruz
		for(j=0;j<n;j++) {
			printf("A[%d][%d] = ",i+1,j+1);
			scanf("%f",&matris[i][j]);
		}
	}
	
	for(i=0;i<n;i++) {  // esitligin sað tarafýný alýyoruz
		printf("C[%d][%d] = ",i+1,n);
		scanf("%f",&matris[i][n]);
	}
	
	for(i=1;i<n;i++) {      // üst üçgen matrisi sýfýr yapacak þekilde iþlemleri yapýyoruz  (paint ile gösterildi)
		for(u=0;u<i;u++) {
			k=matris[i][u]/matris[u][u];
			for(j=0;j<n+1;j++) {
				matris[i][j]=matris[i][j]-k*matris[u][j];
			}
		}
	}
	
	for(i=0;i<n;i++){
		k=matris[i][i];
		for(j=0;j<n;j++){
			matris[i][j]/=k;	
		}	
		matris[i][n]/=k;				
	}
	
	printf("\n\n[A]=  ");
	for(i=0;i<n;i++) {
		for(j=0;j<=n;j++){
			printf("%.1f  ",matris[i][j]);
		}
		printf("\n       ");
	}

	for(i=n-1;i>=0;i--) {
		cikar= 0;
		for(j=i;j<n;j++) {
			cikar=cikar+cozum[j]*matris[i][j];
		}
		cozum[i]=(matris[i][n]-cikar)/matris[i][i];
	}
	
	for(i=0;i<n;i++) {
		printf("\n\n X%d = %f",i+1,cozum[i]);
	}
	return 0;
}
