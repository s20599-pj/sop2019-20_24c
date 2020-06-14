#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc == 2){
		FILE *infile;
		if((infile=fopen(argv[1],"r"))==NULL){
			printf("Nie mozna otworzyc pliku\n");
			fclose(infile);
			return 1;
		}
		else{
			printf("Plik otwarty\n");
			int liczby[11];
			for(int i = 0; i < 11; i++){
				fscanf(infile,"%d",&liczby[i]);
			}
			for(int i = 11; i > 0; i--){
				printf("%d\n",liczby[i]);
			}
			fclose(infile);
		}
	}
	else{
		FILE *infile;
		if((infile=fopen("liczby2.txt","r"))==NULL){
			printf("Nie mozna otworzyc pliku\n");
			fclose(infile);
			return 1;
		}
		else{
			printf("Plik otwarty\n");
			int liczby[11];
			for(int i = 0; i < 11; i++){
				fscanf(infile,"%d",&liczby[i]);
				if()
			}
			for(int i = 11; i > 0; i--){
				printf("%d\n",liczby[i]);
			}
			fclose(infile);
		}
	}
}
