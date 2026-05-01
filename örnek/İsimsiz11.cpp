#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i, fakt = 1;
	for(i=1;i<=20;i++){
		fakt *= i;
		printf("%d\n",fakt);
	}
	printf("%d! = %d",i-1, fakt);
	return 0;
}
