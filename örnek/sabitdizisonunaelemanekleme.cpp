#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int dizi[20];
	int i, sonuncu=-1;
	for(i=0;i<10;i++){
		dizi[i] = rand()%100;
		printf("dizi indeksi: %d, degeri: %d \n", i, dizi[i]);
		sonuncu++;
	}
	printf("\ndizinin son dolu elemaninin indeksi: %d, degeri: %d\n", sonuncu, dizi[sonuncu]);
	dizi[++sonuncu]=66;		//sonuncu deðiþkenini 1 artýrdýktan sonra diziye deðer atadýk.
	printf("yeni son dolu elemaninin indeksi: %d, degeri: %d",sonuncu, dizi[sonuncu]);
	return 0;
}
