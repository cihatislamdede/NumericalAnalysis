// Matrisin inversinin bulunmasi (TESTED)
#include<stdio.h>
#define SIZE 4

int main (){
	
	printf("\t\t### GAUSS-JORDAN YONTEMIYLE MATRISIN TERSININ BULUNMASI ###\n");
	
	int i,j,k,z;
	float bolunecek_sayi,bolunecek_sayi_2;
	static float I[SIZE][SIZE];
	/*
	float A[SIZE][SIZE] = {
							{3,9,5},
							{2,5,2},
							{1,4,5}
							};
	*/
	float A[SIZE][SIZE] = {
							{1,5,3,2},
							{1,2,6,3},
							{2,3,1,5},
							{6,3,5,1}
							};
	
	if(A[0][0] == 0){
		printf("HATA!!!!!!"); // A[0][0] bir sayinin 0'a bölümü tanýmsýz olduðundan bölünemiyor. bu yüzden bunu kontrol ettik
		return 0;
	}
	
						
	for(i=0;i<SIZE;i++){ // SIZE x SIZE boyutunda birim matris oluþturuyoruz
		for(j=0;j<SIZE;j++){
			if(i==j){
				I[i][j]=1;
			}
		}
	}
							
	printf("[A]= \t");
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%.2f ",A[i][j]);
		}
		if(i!=SIZE-1 && j!=SIZE-1)
			printf("\n\n\t");	
	}
	printf("\n\n[I]= \t");
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%.2f ",I[i][j]);
		}
		printf("\n\n\t");
	}
	
	// ÝÞLEMLER BURADA BAÞLIYOR
	for(i=0;i<SIZE;i++){
		bolunecek_sayi=A[i][i];
		for(j=0;j<SIZE;j++){
			A[i][j]=A[i][j]/bolunecek_sayi;
			I[i][j]=I[i][j]/bolunecek_sayi;
		}
		for(k=0;k<SIZE;k++){
			if(k!=i){
				bolunecek_sayi_2=A[k][i];
				for(z=0;z<SIZE;z++){
					A[k][z]=A[k][z]-(A[i][z]*bolunecek_sayi_2);
					I[k][z]=I[k][z]-(I[i][z]*bolunecek_sayi_2);
				}
			}
		}
	}
	
	printf("\n\n[A]^-1= ");
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%.3f ",I[i][j]);
		}
		if(i!=SIZE-1 && j!=SIZE-1)
			printf("\n\n\t");	
	}
	
	return 0;
}
