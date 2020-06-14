#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <arpa/inet.h>

int sockfd, newsockfd, portnumber, n;

void error(char *message, int socket, int newsocket){
    perror(message);
    close(socket);
    close(newsocket);
    exit(1);
}

void closeHandler(int sig){
    signal (sig, SIG_IGN);
    close(sockfd);
    close(newsockfd);
    printf("Zamknieto bezpiecznie gniazda\n");
    exit(0);
}

int main(int argc, char *argv[]){
    
    socklen_t clilength;
    char buffer[256];
    int file_name_length;
    int file_size;
    char* file_name;
    char* file_buffer;
    struct sockaddr_in serv_addr, cli_addr; //deklaracja zmiennych zawierajacych adres internetowy

    signal (SIGINT, closeHandler);

    if(argc < 2){
        fprintf(stderr,"Nie podano portu\n");
        return(1);
    }
    //pierwszy argument to adres domeny, drugi to jak beda wczytywane dane, trzeci to wybor protokolu(zazwyczaj 0)
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //zapytanie do systemu w celu otwarcia portu
    if (sockfd < 0){
        error("Blad otwierania socketu", sockfd, newsockfd);
    }
    //ustawia wartosci w buferze na zero
    bzero((char *) &serv_addr, sizeof(serv_addr));
    //ustawia port na podstawie argumentu aplikacji
    portnumber = atoi(argv[1]);
    
    serv_addr.sin_family = AF_INET;
    //ustawienie portu do pola struktury; htons zmienia kolejnosc bitow do 
    serv_addr.sin_port = htons(portnumber);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("Blad laczenia socketu z adresem", sockfd, newsockfd);
    }
    //nasluchiwanie polaczenia
    listen(sockfd, 5);
    clilength = sizeof(cli_addr);
    //przyjmowanie polaczenia
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilength);

    if(newsockfd < 0){
        error("Blad podczas przyjmowania polaczenia", sockfd, newsockfd);
    }
    bzero(buffer, 256);
    //zapis dlugosci nazwy pliku
    read(newsockfd, &file_name_length, sizeof(file_name_length));
    //rezerwacja pamieci dla zmiennej
    file_name = (char *)malloc(file_name_length);
    //wczytanie nazwy pliku
    read(newsockfd, file_name, file_name_length);

    printf("Plik do wyslania: %s\n", file_name);
    //wczytywanie oraz wysylanie pliku
    FILE* file = fopen(file_name, "r");
    if(file == NULL){
        printf("Blad podczas otwierania pliku\n");
        file_name_length = -1;
        write(newsockfd, &file_name_length,sizeof(file_name_length));
        exit(0);
    }
    else{
        fseek(file, 0, SEEK_END);
        file_size = ftell(file);
        fseek(file, 0, SEEK_SET);
        file_buffer = (char *)malloc(file_size+1);
        fread(file_buffer, file_size, 1, file);
        fclose(file);
    }
    //wysylanie rozmiaru pliku
    write(newsockfd, &file_size, sizeof(file_size));
    //wysylanie pliku
    write(newsockfd, file_buffer, file_size);
    printf("Wyslano plik\n");
    close(sockfd);
    close(newsockfd);
    FILE* log = fopen("log.txt", "w");
    if(log == NULL){
        printf("Blad podczas tworzenia logow\n");
        exit(0);
    }
    else{
        fprintf(log, "IP: %s, port: %d, Plik: %s\n", inet_ntoa(cli_addr.sin_addr), portnumber, file_name);
        fclose(log);
    }
    return 0;
}