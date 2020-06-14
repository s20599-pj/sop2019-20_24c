#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

typedef int (*funkcja)(int, int);

int max(int, int);
int min(int, int);
int suma(int, int);
void przetwarzanieElementow(list<int> &elementy, funkcja *funkcja, int idFunkcja);

int main(int argc, char* argv[]){
    int z;
    int liczbaelementow;
    funkcja funkcja[] {max, min, suma};
    printf("Podaj ktora funkcja ma byc uzyta(0-max.1-min,2-suma)\r\n");
    scanf("%d",&z);
    printf("Podaj ilosc elementow ciagu: ");
    scanf("%d",&liczbaelementow);
    list<int> elementy;
    for (int i = 0; i < liczbaelementow; i++){
        int element = 0;
        scanf("%d",&element);
        elementy.push_back(element);
    }
    przetwarzanieElementow(elementy,funkcja,z);
}

int max(int a, int b){
    return (a < b ? b : a);
}
int min(int a, int b){
    return (a > b ? b : a);
}

int suma(int a, int b){
    return a+b;
}
void przetwarzanieElementow(list<int> &elementy, funkcja *funkcja, int idFunkcja){
 list<int>::iterator iterator = elementy.begin();
 int v = *iterator;
 iterator++;
 for(;iterator != elementy.end();iterator++){
     v = funkcja[idFunkcja](v, *iterator);
 }
 printf("%d\r\n",v);
}