#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc == 2){
		FILE *infile;
		if(strcmp(argv[1],"--print") == 0){
			FILE* binary;
			if((binary = fopen("binary.bin","rb"))== NULL){
				printf("Nie mozna otworzyc pliku\n");
				fclose(binary);
				return 1;
			}
			else{
				fseek(binary,0,SEEK_END);
				long fileSize = ftell(binary); //szuka konca pliku
				fseek(binary,0,SEEK_SET);
				char buffer[16];
				long int offset = 0L;
				while(offset < fileSize){
					size_t readLength = fread(buffer,sizeof(char),16,binary);
					if(readLength == 0){
						printf("Blad podczas wczywywania pliku na offsecie: %08X\r\n", offset);
						break;
					}
					printf("%08X ", offset);
					offset += readLength;
					for(int i = 0; i < readLength-1; i++){
						unsigned char ch = (unsigned char)buffer[i];
						unsigned int number = (unsigned int)ch;
						printf("%02X ", number);
					}
					for (int i = 16; i > readLength; i--)
							printf("   ");
					int limier = ' ';
					for(int i = 0; i < readLength; i++){
						unsigned char ch = (unsigned char)buffer[i];
						if(ch < limier){
							ch = '.';
						}
						printf("%c",ch);
					}
					printf("\r\n");
				}
			}
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
			}
			FILE* binary;
			if((binary = fopen("binary.bin","wb")) == NULL){
				printf("Nie mozna otworzyc pliku\n");
				fclose(binary);
				fclose(infile);
				return 1;
			}
			else{
				fwrite(liczby,sizeof(liczby),1,binary);
				printf("Zapisano do pliku binarnego\n");
			}
			fclose(binary);
			fclose(infile);
		}
	}
}
