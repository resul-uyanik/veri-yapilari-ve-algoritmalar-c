#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int dizi[] = {34,6,79,21,60};
	int i, j, k = 2;
	//dizinin k'nýncý elemanýný silme 
	for(i=k;i<4;i++){
		dizi[i]=dizi[i+1];
//		for(j=0;j<5;j++){
//		printf("%d\t", dizi[j]);
//		}
//		printf("---\n");
	}
	//dizinin k'nýncý indeksine(arasýna) eleman ekleme
	for(i=4;i>k;i--){
		dizi[i]=dizi[i-1];
		for(j=0;j<5;j++){
		printf("%d\t", dizi[j]);
		}
		printf("---\n");
	}
	dizi[i]=79;
	
	for(i=0;i<5;i++){
		printf("%d. index: %d\n",i,dizi[i]);
	}
	return 0;
}
