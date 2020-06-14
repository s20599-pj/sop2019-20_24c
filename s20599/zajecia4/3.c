#include <stdio.h>
#include <stdlib.h>

void przerwy(int wiersz, int wysokosc);
void rysuj(int wiersz);
int main(int argc, char *argv[]){
	if (argc == 0){
		return -1;
	}
	int wysokosc = atoi(argv[1]);
	//choinka
	
	for(int wiersz = 1; wiersz <= wysokosc; wiersz++){
		przerwy(wiersz, wysokosc);
		rysuj(wiersz);
		printf("\n");
	}
	for(int i=1;i<3;i++){
		przerwy(1, wysokosc);
		rysuj(1);
		printf("\n");
	}
	return wysokosc;
}
void przerwy(int wiersz, int wysokosc){
	for(int i = 0; i<wysokosc-wiersz;i++)
		printf(" ");
}
void rysuj(int wiersz){
	for(int i = 0; i<(wiersz*2)-1;i++){
		printf("*");
	}
}